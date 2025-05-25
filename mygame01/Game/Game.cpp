#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Player2.h"
#include "BackGround.h"
#include "Enemy.h"
#include "Debug.h"
#include "Frame.h"
#include "HP.h"
#include "GameTimer.h"
#include "Round.h"
#include "Result.h"
#include "Fade.h"
#include "GameCamera.h"
#include "Title.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Game::Game()
{

}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_backGround);
	// 1P VS 2P ではないとき
	if (m_2playerFlag != true)
	{
		DeleteGO(m_enemy);
	}
	// 1P VS 2P のとき
	else if (m_2playerFlag == true)
	{
		DeleteGO(m_player2);
	}
	DeleteGO(m_frame);
	DeleteGO(m_hp);
	DeleteGO(m_gametimer);
	DeleteGO(m_round);
	DeleteGO(m_result);
	DeleteGO(m_gameCamera);
	DeleteGO(m_fade);
	DeleteGO(m_resultbgm);
}

bool Game::Start()
{
	Player* player=NewGO<Player>(0, "player");
	player->m_initSide = m_1pSide;
	// 1P VS 2P ではないとき
	if (m_2playerFlag != true)
	{
		Enemy* enemy=NewGO<Enemy>(0, "enemy");
		enemy->m_initSide = m_cpuSide;
	}
	// 1P VS 2P のとき
	else if(m_2playerFlag==true)
	{
		Player2* player2=NewGO<Player2>(0, "player2");
		player2->m_initSide = m_2pSide;
	}
	NewGO<BackGround>(0, "background");
	NewGO<Frame>(0, "frame");
	NewGO<HP>(0, "hp");
	NewGO<GameTimer>(0, "gametimer");
	NewGO<Round>(0, "round");
	NewGO<Result>(0, "result");
	NewGO<GameCamera>(0, "gamecamera");
	NewGO<Fade>(0, "fade");

	//BGM
	g_soundEngine->ResistWaveFileBank(7, "Assets/BGM/battle.wav");
	g_soundEngine->ResistWaveFileBank(8, "Assets/BGM/result.wav");

	//対戦用BGM
	m_battlebgm = NewGO<SoundSource>(0);
	m_battlebgm->Init(7);
	m_battlebgm->Play(true);
	m_battlebgm->SetVolume(0.3f);

	//選択
	m_select[enSelectState_Left].Init("Assets/UI/result/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Left].SetPosition({ -550.0f,-475.0f,0.0f });
	m_select[enSelectState_Left].SetScale({ 0.5f,0.5f,0.5f });
	m_select[enSelectState_Left].Update();

	m_select[enSelectState_Right].Init("Assets/UI/result/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Right].SetPosition({ 135.0f,-475.0f,0.0f });
	m_select[enSelectState_Right].SetScale({ 0.5f,0.5f,0.5f });
	m_select[enSelectState_Right].Update();

	//テキスト
	m_text[0].Init("Assets/UI/result/retry.dds", 250.0f, 128.0f);
	m_text[0].SetPosition({ -400.0f,-475.0f,0.0f });
	m_text[0].SetScale({ 0.5f,0.5f,0.5f });
	m_text[0].Update();

	m_text[1].Init("Assets/UI/result/back_title.dds", 748.0f, 128.0f);
	m_text[1].SetPosition({ 400.0f,-475.0f,0.0f });
	m_text[1].SetScale({ 0.5f,0.5f,0.5f });
	m_text[1].Update();

	//Aボタン
	m_aButton.Init("Assets/UI/button/controller/A.dds", 1024.0f, 1024.0f);
	m_aButton.SetScale({ 0.1f,0.1f,0.1f });
	m_aButton.SetPosition({ 700.0f,-500.0f,0.0f });
	m_aButton.Update();

	//決定
	m_retry.SetText(L"決定");
	m_retry.SetPosition(Vector3(725.0f, -480.0f, 0.0f));
	m_retry.SetScale(1.0f);
	m_retry.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//インスタンス
	m_player=FindGO<Player>("player");
	m_backGround = FindGO<BackGround>("background");
	// 1P VS 2P ではないとき
	if (m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	// 1P VS 2P のとき
	else if (m_2playerFlag == true)
	{
		m_player2=FindGO<Player2>("player2");
	}
	m_frame = FindGO<Frame>("frame");
	m_hp = FindGO<HP>("hp");
	m_gametimer = FindGO<GameTimer>("gametimer");	
	m_round = FindGO<Round>("round");
	m_result = FindGO<Result>("result");
	m_gameCamera = FindGO<GameCamera>("gamecamera");
	m_fade = FindGO<Fade>("fade");
	return true;
}

void Game::Update()
{
	//以下のフラグが立っているとき
	if (m_round->m_1pWinFlag == true || //1P勝利
		m_round->m_2pWinFlag == true || //2P勝利
		m_round->m_enemyWinFlag == true || //CPU勝利
		m_round->m_drawFlag == true //引き分け
	   )
	{
		//リザルト用BGM再生しているか？
		if (m_resultBGMFlag != true)
		{
			DeleteGO(m_battlebgm);
			//リザルト用BGM
			m_resultbgm = NewGO<SoundSource>(0);
			m_resultbgm->Init(8);
			m_resultbgm->Play(true);
			m_resultbgm->SetVolume(0.3f);
			m_resultBGMFlag = true;
		}

		//左ボタン
		if (g_pad[0]->IsTrigger(enButtonLeft))
		{
			//選択状態が上のとき
			if (m_selectNum == enSelectState_Left)
			{
				m_selectNum = enSelectState_Right;
			}
			else
			{
				m_selectNum = enSelectState_Left;
			}
			//効果音
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(4);
			se->Play(false);
			se->SetVolume(0.6f);
		}
		//右ボタン
		else if (g_pad[0]->IsTrigger(enButtonRight))
		{
			//選択状態が下のとき
			if (m_selectNum == enSelectState_Right)
			{
				m_selectNum = enSelectState_Left;
			}
			else
			{
				m_selectNum = enSelectState_Right;
			}
			//効果音
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(4);
			se->Play(false);
			se->SetVolume(0.6f);
		}

		//Aボタン押されていないとき
		if (m_selectFlag != true)
		{
			//Aボタン
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				m_selectFlag = true;
				//効果音
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(3);
				se->Play(false);
				se->SetVolume(0.6f);
				////BGMを流さない
				//DeleteGO(m_bgm);
			}
		}

		//Aボタン押されていたら
		if (m_selectFlag == true)
		{
			m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
			m_intTime = m_selectTime * 10;

			//選択時間が0.0秒になったら
			if (m_selectTime <= 0.0f)
			{
				//再戦するを押したら
				if (m_selectNum == enSelectState_Left)
				{
					m_retryFlag = true;
				}
				//タイトルへ戻るを押したら
				else if (m_selectNum == enSelectState_Right)
				{
					//ロードしていないとき
					if (m_roadFlag != true)
					{
						m_fade->StartFadeOut();
						m_roadFlag = true;
					}
					//フェードアウトが終わったら
					if (!m_fade->IsFade())
					{
						NewGO<Title>(0, "title");
						DeleteGO(this);
					}
				}
			}
			//0秒になっていなかったら
			else
			{
				if (m_intTime % 2 == 0)
				{
					m_selectFadeFlag = true; //透明にする
				}
				else
				{
					m_selectFadeFlag = false; //透明にしない
				}
			}
		}

		////Aボタン
		//if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	m_titleFlag = true;
		//}

		////Aボタンを押したらフェードアウトしてタイトルに戻る
		//if (m_titleFlag == true)
		//{
		//	//ロードしていないとき
		//	if (m_roadFlag != true)
		//	{
		//		m_fade->StartFadeOut();
		//		m_roadFlag = true;
		//	}
		//	//フェードアウトが終わったら
		//	if (!m_fade->IsFade())
		//	{
		//		NewGO<Title>(0, "title");
		//		DeleteGO(this);
		//	}
		//}
	}

	////デバッグ用
	//if(g_pad[0]->IsTrigger(enButtonY))
	//{
	//	if (m_count == 0)
	//	{
	//		NewGO<Debug>(0, "debug");
	//		m_debug = FindGO<Debug>("debug");
	//	}
	//	m_count++;
	//	m_flag = 1;
	//}
	//if (m_count == 2)
	//{
	//	DeleteGO(m_debug);
	//	m_count = 0;
	//}

	//if (g_pad[0]->IsTrigger(enButtonY))
	//{
	//	NewGO<Title>(0, "title");
	//	DeleteGO(this);
	//	DeleteGO(m_battlebgm);
	//}

	//if (g_pad[0]->IsTrigger(enButtonB))
	//{
	//	m_player->Reset();
	//	m_enemy->Reset();
	//	m_time->Reset();
	//}

	//IsFinish();

	//if (IsFinish() == true)
	//{
	//	if (m_player->m_player.IsPlayingAnimation() == false && m_enemy->m_enemy.IsPlayingAnimation() == false)
	//	{
	//		m_fadeTime -= g_gameTime->GetFrameDeltaTime();

	//		if (m_fadeTime < 0.0f)
	//		{
	//			m_fade->StartFadeOut();
	//			m_isWaitFadeout = true;
	//		}

	//		//	m_player->Reset();
	//		//	m_enemy->Reset();
	//		//	m_time->Reset();
	//	}
	//}

	//if (m_isWaitFadeout == true)
	//{
	//	m_fade->StartFadeIn();
	//	m_isWaitFadeout = false;
	//}

	// g_renderingEngine->DisableRaytracing();
}

//bool Game::IsFinish()
//{
//	if (m_time->m_time < 0.0f)
//	{
//		if (m_player->m_playerHP <= 0)
//		{
//
//		}
//		else if (m_enemy->m_enemyHP <= 0)
//		{
//
//		}
//		return true;
//	}
//	else if (m_player->m_playerHP <= 0)
//	{
//		return true;
//	}
//	else if (m_enemy->m_enemyHP <= 0)
//	{
//		return true;
//	}
//	else 
//	{
//		return false;
//	}
//}

void Game::Render(RenderContext& rc)
{
	//描画
	//対戦が終わったとき
	if (m_round->m_1pWinFlag == true ||
		m_round->m_2pWinFlag == true ||
		m_round->m_enemyWinFlag == true ||
		m_round->m_drawFlag == true
		)
	{
		m_text[0].Draw(rc);
		m_text[1].Draw(rc);
		m_aButton.Draw(rc);
		m_retry.Draw(rc);
		if (m_selectFadeFlag != true)
		{
			m_select[m_selectNum].Draw(rc);
		}
	}
}
