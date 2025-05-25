#include "stdafx.h"
#include "Round.h"
#include "Game.h"
#include "Fade.h"
#include "Player.h"
#include "Enemy.h"
#include "Player2.h"
#include "GameTimer.h"
#include "Frame.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Round::Round()
{

}

Round::~Round()
{

}

bool Round::Start()
{
	//ラウンド1
	m_round[0].Init("Assets/UI/round/round1.dds", 1028.0f, 256.0f);
	m_round[0].SetPosition({-25.0f,0.0f,0.0f});
	m_round[0].SetScale({0.65f,0.8f,1.0f});
	m_round[0].Update();

	//ラウンド2
	m_round[1].Init("Assets/UI/round/round2.dds", 1028.0f, 256.0f);
	m_round[1].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[1].SetScale({ 0.65f,0.8f,1.0f });
	m_round[1].Update();

	//ラウンド3
	m_round[2].Init("Assets/UI/round/round3.dds", 1028.0f, 256.0f);
	m_round[2].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[2].SetScale({ 0.65f,0.8f,1.0f });
	m_round[2].Update();

	//ラウンド4
	m_round[3].Init("Assets/UI/round/round4.dds", 1028.0f, 256.0f);
	m_round[3].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[3].SetScale({ 0.65f,0.8f,1.0f });
	m_round[3].Update();

	//ラウンド5
	m_round[4].Init("Assets/UI/round/round5.dds", 1028.0f, 256.0f);
	m_round[4].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[4].SetScale({ 0.65f,0.8f,1.0f });
	m_round[4].Update();

	//ラウンド6
	m_round[5].Init("Assets/UI/round/round6.dds", 1028.0f, 256.0f);
	m_round[5].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[5].SetScale({ 0.65f,0.8f,1.0f });
	m_round[5].Update();

	//ラウンド7
	m_round[6].Init("Assets/UI/round/round7.dds", 1028.0f, 256.0f);
	m_round[6].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[6].SetScale({ 0.65f,0.8f,1.0f });
	m_round[6].Update();

	//ラウンド8
	m_round[7].Init("Assets/UI/round/round8.dds", 1028.0f, 256.0f);
	m_round[7].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[7].SetScale({ 0.65f,0.8f,1.0f });
	m_round[7].Update();

	//ラウンド9
	m_round[8].Init("Assets/UI/round/round9.dds", 1028.0f, 256.0f);
	m_round[8].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[8].SetScale({ 0.65f,0.8f,1.0f });
	m_round[8].Update();

	//ラウンド10～
	m_overround.Init("Assets/UI/round/round.dds", 1028.0f, 256.0f);
	m_overround.SetPosition({ 0.0f,0.0f,0.0f });
	m_overround.SetScale({ 0.5f,0.5f,1.0f });
	m_overround.Update();

	//ファイト
	m_fight.Init("Assets/UI/round/fight.dds", 1028.0f, 256.0f);
	m_fight.SetPosition({ 0.0f,0.0f,0.0f });
	m_fight.SetScale({ 0.65f,0.8f,1.0f });
	m_fight.Update();

	//KO
	m_ko.Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_ko.SetPosition({ 0.0f,0.0f,0.0f });
	m_ko.SetScale({ 0.65f,0.8f,1.0f });
	m_ko.Update();

	//ダブルKO
	m_doubleKO[0].Init("Assets/UI/round/double.dds", 1028.0f, 256.0f);
	m_doubleKO[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_doubleKO[0].SetScale({ 0.5f,0.5f,1.0f });
	m_doubleKO[0].Update();

	m_doubleKO[1].Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_doubleKO[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_doubleKO[1].SetScale({ 0.5f,0.5f,1.0f });
	m_doubleKO[1].Update();

	//パーフェクトKO
	m_perfectKO[0].Init("Assets/UI/round/perfect.dds", 1028.0f, 256.0f);
	m_perfectKO[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_perfectKO[0].SetScale({ 0.5f,0.5f,1.0f });
	m_perfectKO[0].Update();

	m_perfectKO[1].Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_perfectKO[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_perfectKO[1].SetScale({ 0.5f,0.5f,1.0f });
	m_perfectKO[1].Update();

	//タイムアップ
	m_timeUp.Init("Assets/UI/round/timeup.dds", 1028.0f, 256.0f);
	m_timeUp.SetPosition({ 0.0f,0.0f,0.0f });
	m_timeUp.SetScale({ 0.65f,0.8f,1.0f });
	m_timeUp.Update();

	//ファイナルラウンド
	m_finalRound[0].Init("Assets/UI/round/final.dds", 1028.0f, 256.0f);
	m_finalRound[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_finalRound[0].SetScale({ 0.5f,0.5f,1.0f });
	m_finalRound[0].Update();

	m_finalRound[1].Init("Assets/UI/round/round.dds", 1028.0f, 256.0f);
	m_finalRound[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_finalRound[1].SetScale({ 0.5f,0.5f,1.0f });
	m_finalRound[1].Update();

	//インスタンス
	m_game = FindGO<Game>("game");

	//プレイヤーデフォルトラウンドアイコン
	m_playerRoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_playerRoundIconD[0].SetPosition({ -275.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_playerRoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconD[0].Update();	

	m_playerRoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_playerRoundIconD[1].SetPosition({ -335.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_playerRoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconD[1].Update();	

	//プレイヤー2デフォルトラウンドアイコン
	m_player2RoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_player2RoundIconD[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_player2RoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconD[0].Update();

	m_player2RoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_player2RoundIconD[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_player2RoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconD[1].Update();

	//敵デフォルトラウンドアイコン
	m_enemyRoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_enemyRoundIconD[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_enemyRoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconD[0].Update();	

	m_enemyRoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_enemyRoundIconD[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_enemyRoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconD[1].Update();

	//プレイヤー勝利ラウンドアイコン
	m_playerRoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_playerRoundIconW[0].SetPosition({ -275.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_playerRoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconW[0].Update();	

	m_playerRoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_playerRoundIconW[1].SetPosition({ -335.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_playerRoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconW[1].Update();	

	//プレイヤー2勝利ラウンドアイコン
	m_player2RoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_player2RoundIconW[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_player2RoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconW[0].Update();

	m_player2RoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_player2RoundIconW[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_player2RoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconW[1].Update();

	//敵勝利ラウンドアイコン
	m_enemyRoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_enemyRoundIconW[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_enemyRoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconW[0].Update();	

	m_enemyRoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_enemyRoundIconW[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_enemyRoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconW[1].Update();

	//効果音
	g_soundEngine->ResistWaveFileBank(9, "Assets/SE/voice/round1.wav");
	g_soundEngine->ResistWaveFileBank(10, "Assets/SE/voice/round2.wav");
	g_soundEngine->ResistWaveFileBank(11, "Assets/SE/voice/finalround.wav");
	g_soundEngine->ResistWaveFileBank(12, "Assets/SE/voice/fight.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/SE/voice/ko.wav");
	g_soundEngine->ResistWaveFileBank(14, "Assets/SE/voice/doubleko.wav");
	g_soundEngine->ResistWaveFileBank(15, "Assets/SE/voice/perfect.wav");
	g_soundEngine->ResistWaveFileBank(16, "Assets/SE/timeup.wav");

	//インスタンス
	m_fade = FindGO<Fade>("fade");
	m_player = FindGO<Player>("player");
	// 1P vs 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	// 1P vs 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}
	m_gametimer = FindGO<GameTimer>("gametimer");
	m_frame = FindGO<Frame>("frame");

	//フェードイン
	m_fade->StartFadeIn();

	return true;
}

void Round::Update()
{
	//ラウンドが終わっているか？
	IsNoFighting();

	//以下の状態以外のとき
	if (m_roundState!=State_Fighting && //対戦中
		m_roundState!= State_Idle && //待機
		m_roundState!=State_Round && //ラウンド
		m_roundState!=State_Fight && //ファイト
		m_roundState!=State_KO && //KO
		m_roundState!=State_TimeUp //タイムアップ
	   )
	{
		//誰が勝ったか？
		if (m_1pWinFlag != true || //プレイヤー勝利
			m_2pWinFlag!=true || //プレイヤー2勝利
			m_enemyWinFlag != true //CPU勝利
		   )
		{
			//プレイヤーが勝ったとき
			if (m_1pGetWinFlag == true)
			{
				m_playerGetWin++;
				m_playerNoGetWin--;
				m_roundNo++;
				m_1pGetWinFlag = false;
			}
			//プレイヤー2が勝ったとき
			else if (m_2pGetWinFlag == true)
			{
				m_player2GetWin++;
				m_player2NoGetWin--;
				m_roundNo++;
				m_2pGetWinFlag = false;
			}
			//敵が勝ったとき
			else if (m_enemyGetWinFlag == true)
			{
				m_enemyGetWin++;
				m_enemyNoGetWin--;
				m_roundNo++;
				m_enemyGetWinFlag = false;
			}
			//引き分けのとき
			else if (m_getDrawFlag == true)
			{
				m_playerGetWin++;
				m_playerNoGetWin--;
				// 1P VS 2P ではないとき
				if (m_game->m_2playerFlag != true)
				{
					m_enemyGetWin++;
					m_enemyNoGetWin--;
				}
				// 1P VS 2P のとき
				else if (m_game->m_2playerFlag == true)
				{
					m_player2GetWin++;
					m_player2NoGetWin--;
				}
				m_roundNo = 11;
				m_getDrawFlag = false;
			}
		}

		//ラウンドが終わったときの処理
		// 1P vs 2P ではないとき
		if (m_game->m_2playerFlag != true)
		{
			//ラウンドが終わったときにするアニメーションが終わったとき
			if (m_player->m_player.IsPlayingAnimation() == false && m_enemy->m_enemy.IsPlayingAnimation() == false)
			{
				//プレイヤーかつ敵のラウンド無取得数が0のとき
				if (m_playerNoGetWin == 0 && m_enemyNoGetWin == 0)
				{
					m_drawFlag = true;
				}
				//プレイヤーのラウンド無取得数が0のとき
				else if (m_playerNoGetWin == 0)
				{
					m_1pWinFlag = true;
				}
				//敵のラウンド無取得数が0のとき
				else if (m_enemyNoGetWin == 0)
				{
					m_enemyWinFlag = true;
				}

				//決着がついたとき処理しない
				if ((m_1pWinFlag == true || //プレイヤー勝利
					m_enemyWinFlag == true || //CPU勝利
					m_drawFlag == true) && //引き分け
					m_game->m_retryFlag != true //再戦
					)
				{
					return;
				}

				//フェードアウトしていないとき
				if (m_isWaitFadeout == false)
				{
					m_fadeTime -= g_gameTime->GetFrameDeltaTime();
					//フェード時間が0.0秒になったら
					if (m_fadeTime < 0.0f)
					{
						//フェードアウト
						m_fade->StartFadeOut();
						m_fadeTime = 1.0f;
						m_isWaitFadeout = true;
					}
				}
				//フェードアウトしたとき
				else if (m_isWaitFadeout == true)
				{
					//フェードアウトが終わったら初期値に戻す
					if (!m_fade->IsFade())
					{
						if (m_game->m_retryFlag == true)
						{
							m_game->Reset();
							Reset();
						}
						m_player->Reset();
						m_enemy->Reset();
						//if (m_game->m_2playerFlag != true)
						//{
						//	m_enemy->Reset();
						//}
						//else if (m_game->m_2playerFlag == true)
						//{
						//	m_player2->Reset();
						//}
						m_gametimer->Reset();
						m_frame->Reset();
						//フェードイン
						m_fade->StartFadeIn();
						for (int i = 0; i < State_Num; i++)
						{
							m_seFlag[i] = false;
						}
						m_roundState = State_Idle;
					}
				}
			}
		}
		// 1P vs 2P のとき
		else if (m_game->m_2playerFlag == true)
		{
			//ラウンドが終わったときにするアニメーションが終わったとき
			if (m_player->m_player.IsPlayingAnimation() == false && m_player2->m_player2.IsPlayingAnimation() == false)
			{
				//プレイヤーかつプレイヤー2のラウンド無取得数が0のとき
				if (m_playerNoGetWin == 0 && m_player2NoGetWin == 0)
				{
					m_drawFlag = true;
				}
				//プレイヤーのラウンド無取得数が0のとき
				else if (m_playerNoGetWin == 0)
				{
					m_1pWinFlag = true;
				}
				//プレイヤー2のラウンド無取得数が0のとき
				else if (m_player2NoGetWin == 0)
				{
					m_2pWinFlag = true;
				}

				//決着がついたとき処理しない
				if ((m_1pWinFlag == true || //プレイヤー勝利
					m_2pWinFlag == true || //プレイヤー2勝利
					m_drawFlag == true) && //引き分け
					m_game->m_retryFlag != true //再戦
					)
				{
					return;
				}

				//フェードアウトしていないとき
				if (m_isWaitFadeout == false)
				{
					m_fadeTime -= g_gameTime->GetFrameDeltaTime();
					//フェード時間が0.0秒になったら
					if (m_fadeTime < 0.0f)
					{
						//フェードアウト
						m_fade->StartFadeOut();
						m_fadeTime = 1.0f;
						m_isWaitFadeout = true;
					}
				}
				//フェードアウトしたとき
				else if (m_isWaitFadeout == true)
				{
					//フェードアウトが終わったら初期値に戻す
					if (!m_fade->IsFade())
					{
						if (m_game->m_retryFlag == true)
						{
							m_game->Reset();
							Reset();
						}
						m_player->Reset();
						m_player2->Reset();
						//if (m_game->m_2playerFlag != true)
						//{
						//	m_enemy->Reset();
						//}
						//else if (m_game->m_2playerFlag == true)
						//{
						//	m_player2->Reset();
						//}
						m_gametimer->Reset();
						m_frame->Reset();
						//フェードイン
						m_fade->StartFadeIn();
						for (int i = 0; i < State_Num; i++)
						{
							m_seFlag[i] = false;
						}
						m_roundState = State_Idle;
					}
				}
			}
		}
	}
	//ラウンド状態が待機のとき
	else if (m_roundState == State_Idle)
	{
		//フェードイン中
		if (m_fade->IsFade())
		{
			m_isWaitFadeout = false;
			m_battleFinishFlag = false;
			m_roundState = State_Round;
		}
		//m_isWaitFadeout = false;
	}
	//ラウンド状態がラウンドのとき
	else if (m_roundState == State_Round)
	{
		//フェードインが終わったら
		if (!m_fade->IsFade())
		{
			m_roundFlag = true;
			//効果音が再生しているか？
			if (m_seFlag[State_Round] != true)
			{
				//効果音
				m_roundSE = NewGO<SoundSource>(0);
				m_roundSE->Init(m_roundNo);
				m_roundSE->Play(false);
				m_roundSE->SetVolume(0.6f);
				m_seFlag[State_Round] = true;
			}
			//m_roundState = State_Fight;
		}

		//ラウンドが表示したら
		if (m_roundFlag == true)
		{
			m_roundTime -= 0.5*g_gameTime->GetFrameDeltaTime();
			//ラウンド表示時間が0.0秒になったら
			if (m_roundTime < 0.0f)
			{
				m_roundTime = 1.0f;
				m_roundFlag = false;
				m_fightFlag = true;
				m_roundState = State_Fight;
			}
		}
	}
	//ラウンド状態がファイトのとき
	else if (m_roundState == State_Fight)
	{
		m_fightTime -= g_gameTime->GetFrameDeltaTime();
		//効果音が再生しているか？
		if (m_seFlag[State_Fight] != true)
		{
			//効果音
			m_fightSE = NewGO<SoundSource>(0);
			m_fightSE->Init(12);
			m_fightSE->Play(false);
			m_fightSE->SetVolume(0.6f);
			m_seFlag[State_Fight] = true;
		}
		//ファイト表示時間が0.0秒になったら
		if (m_fightTime < 0.0f)
		{
			m_fightTime = 1.0f;
			m_roundCount++;
			m_fightFlag = false;
			m_roundState = State_Fighting;
		}
	}
	//ラウンド状態がKOのとき
	else if (m_roundState == State_KO)
	{
		m_koTime -= 1.5f * g_gameTime->GetFrameDeltaTime();
		//ダブルKOが表示したら
		if (m_doubleKOFlag == true)
		{
			//効果音が再生しているか？
			if (m_seFlag[State_KO] != true)
			{
				//効果音
				m_doubleKOSE = NewGO<SoundSource>(0);
				m_doubleKOSE->Init(14);
				m_doubleKOSE->Play(false);
				m_doubleKOSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		//パーフェクトKOが表示したら
		else if (m_perfectKOFlag == true)
		{
			//効果音が再生しているか？
			if (m_seFlag[State_KO] != true)
			{
				//効果音
				m_koSE = NewGO<SoundSource>(0);
				m_koSE->Init(15);
				m_koSE->Play(false);
				m_koSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		else
		{
			//効果音が再生しているか？
			if (m_seFlag[State_KO] != true)
			{
				//効果音
				m_koSE = NewGO<SoundSource>(0);
				m_koSE->Init(13);
				m_koSE->Play(false);
				m_koSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		//KO表示時間が0.0秒になったら
		if (m_koTime < 0.0f)
		{
			m_koTime = 1.0f;
			m_koFlag = false;
			//ダブルKOが表示したら
			if (m_doubleKOFlag == true)
			{
				m_doubleKOFlag = false;
			}
			//パーフェクトKOが表示したら
			else if(m_perfectKOFlag==true)
			{
				m_perfectKOFlag = false;
			}
			// 1P VS 2P ではないとき
			if (m_game->m_2playerFlag != true)
			{
				//ラウンドが終わったときにするアニメーションが終わったとき
				if ((((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //パンチ
					m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //キック
					(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) || //地上攻撃または空中攻撃
					((m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Panch || //パンチ
						m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Kick) && //キック
						(m_enemy->m_charaCon.IsOnGround() == true || m_enemy->m_charaCon.IsOnGround() != false))) && //地上攻撃または空中攻撃
					((m_player->m_animationState == Player::EnAnimationState::enAnimationState_Lose &&
						m_player->m_player.IsPlayingAnimation() == false) || //負け 
						(m_enemy->m_animationState == Enemy::EnAnimationState::enAnimationState_Lose &&
							m_enemy->m_enemy.IsPlayingAnimation() == false)) //負け
					)
				{
					m_roundState = State_Next;
				}
			}
			// 1P VS 2P のとき
			else if (m_game->m_2playerFlag == true)
			{
				//ラウンドが終わったときにするアニメーションが終わったとき
				if ((((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //パンチ
					m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //キック
					(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) || //地上攻撃または空中攻撃
					((m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Panch || //パンチ
						m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Kick) && //キック
						(m_player2->m_charaCon.IsOnGround() == true || m_player2->m_charaCon.IsOnGround() != false))) &&//地上攻撃または空中攻撃
					((m_player->m_animationState == Player::EnAnimationState::enAnimationState_Lose &&
						m_player->m_player.IsPlayingAnimation() == false) || //負け
						(m_player2->m_animationState == Player2::EnAnimationState::enAnimationState_Lose &&
							m_player2->m_player2.IsPlayingAnimation() == false)) //負け
					)
				{
					m_roundState = State_Next;
				}
			}
		}
	}	
	//ラウンド状態がタイムアップのとき
	else if (m_roundState == State_TimeUp)
	{
		m_timeUpTime -= 1.5f * g_gameTime->GetFrameDeltaTime();
		//効果音が再生しているか？
		if (m_seFlag[State_TimeUp] != true)
		{
			//効果音
			m_koSE = NewGO<SoundSource>(0);
			m_koSE->Init(16);
			m_koSE->Play(false);
			m_koSE->SetVolume(0.6f);
			m_seFlag[State_TimeUp] = true;
		}
		//タイムアップ表示時間が0.0秒になったら
		if (m_timeUpTime < 0.0f)
		{
			m_timeUpTime = 1.0f;
			m_timeUpFlag = false;
			// 1P VS 2P ではないとき
			if (m_game->m_2playerFlag != true)
			{
				//以下の行動していないとき
				if (m_player->m_animationState != Player::EnAnimationState::enAnimationState_Jump && //ジャンプ
					m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Jump && //ジャンプ
					((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //パンチ
						m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //キック
						m_player->m_charaCon.IsOnGround() != false) && //地上攻撃または空中攻撃
					((m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Panch || //パンチ
						m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Kick) && //キック
						(m_enemy->m_charaCon.IsOnGround() == true || m_enemy->m_charaCon.IsOnGround() != false)) //地上攻撃または空中攻撃
					)
				{
					m_roundState = State_Next;
				}
			}
			// 1P VS 2P のとき
			else if (m_game->m_2playerFlag == true)
			{
				//以下の行動していないとき
				if (m_player->m_animationState != Player::EnAnimationState::enAnimationState_Jump && //ジャンプ
					m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Jump &&//ジャンプ
					((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //パンチ
						m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //キック
						(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) && //地上攻撃または空中攻撃
					((m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Panch || //パンチ
						m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Kick) && //キック
						(m_player2->m_charaCon.IsOnGround() == true || m_player2->m_charaCon.IsOnGround() != false)) //地上攻撃または空中攻撃
					)
				{
					m_roundState = State_Next;
				}
			}
			//m_roundState = State_Next;
		}
	}
}

bool Round::IsNoFighting()
{
	if (m_isWaitFadeout != true && m_battleFinishFlag != true)
	{
		//1P vs 2P ではないとき
		if (m_game->m_2playerFlag != true)
		{
			//時間切れ
			if (m_gametimer->m_time < 0.0f)
			{
				//プレイヤーのHPの方が多いとき
				if (m_player->m_playerHP > m_enemy->m_enemyHP)
				{
					//m_playerGetWin++;
					//m_playerNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_PlayerGetWIn;
					m_battleFinishFlag = true;
					m_1pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//敵のHPの方が多いとき
				else if (m_player->m_playerHP < m_enemy->m_enemyHP)
				{
					//m_enemyGetWin++;
					//m_enemyNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_EnemyGetWIn;
					m_battleFinishFlag = true;
					m_enemyGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//引き分け
				else if (m_player->m_playerHP == m_enemy->m_enemyHP)
				{
					m_roundState = State_TimeUp;
					//m_roundState = State_Draw;
					m_battleFinishFlag = true;
					m_getDrawFlag = true;
					m_timeUpFlag = true;
				}
				//return false;
				//タイムアップが表示したら
				if (m_timeUpFlag == true)
				{
					return true;
				}
			}
			//プレイヤーが勝ったとき
			else if (m_enemy->m_enemyHP <= 0 && m_player->m_playerHP > 0)
			{
				//m_playerGetWin++;
				//m_playerNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_PlayerGetWIn;
				m_battleFinishFlag = true;
				m_1pGetWinFlag = true;
				m_koFlag = true;
				//プレイヤーの体力が減っていないとき
				if (m_player->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//敵が勝ったとき
			else if (m_player->m_playerHP <= 0 && m_enemy->m_enemyHP > 0)
			{
				//m_enemyGetWin++;
				//m_enemyNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_EnemyGetWIn;
				m_battleFinishFlag = true;
				m_enemyGetWinFlag = true;
				m_koFlag = true;
				//敵の体力が減っていないとき
				if (m_enemy->m_enemyHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//引き分け
			else if (m_player->m_playerHP <= 0 && m_enemy->m_enemyHP <= 0)
			{
				m_roundState = State_KO;
				//m_roundState = State_Draw;
				m_battleFinishFlag = true;
				m_getDrawFlag = true;
				m_koFlag = true;
				m_doubleKOFlag = true;
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//ラウンド状態がラウンドまたはファイトのとき
			else if (m_roundState == State_Round || m_roundState == State_Fight)
			{
				//return false;
				return true;
			}
			else
			{
				m_roundState = State_Fighting;
				//return true;
				return false;
			}
		}
		//1P vs 2P のとき
		else if (m_game->m_2playerFlag == true)
		{
			//時間切れ
			if (m_gametimer->m_time < 0.0f)
			{
				//プレイヤーのHPの方が多いとき
				if (m_player->m_playerHP > m_player2->m_playerHP)
				{
					//m_playerGetWin++;
					//m_playerNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_PlayerGetWIn;
					m_battleFinishFlag = true;
					m_1pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//敵のHPの方が多いとき
				else if (m_player->m_playerHP < m_player2->m_playerHP)
				{
					//m_enemyGetWin++;
					//m_enemyNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_EnemyGetWIn;
					m_battleFinishFlag = true;
					m_2pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//引き分け
				else if (m_player->m_playerHP == m_player2->m_playerHP)
				{
					m_roundState = State_TimeUp;
					//m_roundState = State_Draw;
					m_battleFinishFlag = true;
					m_getDrawFlag = true;
					m_timeUpFlag = true;
				}
				//return false;
				//タイムアップが表示したら
				if (m_timeUpFlag == true)
				{
					return true;
				}
			}
			//プレイヤーが勝ったとき
			else if (m_player2->m_playerHP <= 0 && m_player->m_playerHP > 0)
			{
				//m_playerGetWin++;
				//m_playerNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_PlayerGetWIn;
				m_battleFinishFlag = true;
				m_1pGetWinFlag = true;
				m_koFlag = true;
				//プレイヤーの体力が減っていないとき
				if (m_player->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//プレイヤー2が勝ったとき
			else if (m_player->m_playerHP <= 0 && m_player2->m_playerHP > 0)
			{
				//m_enemyGetWin++;
				//m_enemyNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_EnemyGetWIn;
				m_battleFinishFlag = true;
				m_2pGetWinFlag = true;
				m_koFlag = true;
				//プレイヤー2の体力が減っていないとき
				if (m_player2->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//引き分け
			else if (m_player->m_playerHP <= 0 && m_player2->m_playerHP <= 0)
			{
				m_roundState = State_KO;
				//m_roundState = State_Draw;
				m_battleFinishFlag = true;
				m_getDrawFlag = true;
				m_koFlag = true;
				m_doubleKOFlag = true;
				//return false;
				//KOが表示したら
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//ラウンド状態がラウンドまたはファイトのとき
			else if (m_roundState == State_Round || m_roundState == State_Fight)
			{
				//return false;
				return true;
			}
			else
			{
				m_roundState = State_Fighting;
				//return true;
				return false;
			}
		}
	}
}

void Round::Render(RenderContext& rc)
{
	////m_playerRoundIconD[0].Draw(rc);
	//m_playerRoundIconD[1].Draw(rc);
	////m_enemyRoundIconD[0].Draw(rc);
	//m_enemyRoundIconD[1].Draw(rc);	

	//m_playerRoundIconW[0].Draw(rc);
	////m_playerRoundIconW[1].Draw(rc);
	//m_enemyRoundIconW[0].Draw(rc);
	////m_enemyRoundIconW[1].Draw(rc);

	//for (int i = 0; i < 2; i++)
	//{
	//	//m_doubleKO[i].Draw(rc);
	//	//m_perfectKO[i].Draw(rc);
	//}

	//ラウンド描画
	if (m_roundFlag == true)
	{
		//プレイヤーまたは敵またはプレイヤー2のラウンド取得数が0のとき
		if (m_playerGetWin==0&&(m_enemyGetWin==0||m_player2GetWin==0))
		{
			for (int i = 0; i < 2; i++)
			{
				//ファイナルラウンド描画
				m_finalRound[i].Draw(rc);
			}
		}
		//ラウンドカウントが9未満のとき
		else if(m_roundCount<9)
		{
			//ラウンド1～9描画
			m_round[m_roundCount].Draw(rc);
		}
		//ラウンドカウントが8より大きいとき
		else if (m_roundCount>8)
		{
			//ラウンド10～描画
			m_overround.Draw(rc);
		}
	}
	//ファイト描画
	else if (m_fightFlag == true)
	{
		m_fight.Draw(rc);
	}
	//KO描画
	else if (m_koFlag == true)
	{
		//ダブルKOが表示したら
		if (m_doubleKOFlag==true)
		{
			for (int i = 0; i < 2; i++)
			{
				m_doubleKO[i].Draw(rc);
			}
		}
		//パーフェクトKOが表示したら
		else if(m_perfectKOFlag == true)
		{
			for (int i = 0; i < 2; i++)
			{
				m_perfectKO[i].Draw(rc);
			}
		}
		else
		{
			m_ko.Draw(rc);
		}
	}
	//タイムアップ描画
	else if (m_timeUpFlag == true)
	{
		m_timeUp.Draw(rc);
	}

	//プレイヤーデフォルトラウンドアイコン描画
	if (m_playerNoGetWin != 0)
	{
		for (int i = m_playerNoGetWin; i > 0; i--)
		{
			m_playerRoundIconD[i + m_playerGetWin].Draw(rc);
		}
	}
	// 1P VS 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//敵デフォルトラウンドアイコン描画
		if (m_enemyNoGetWin != 0)
		{
			for (int i = m_enemyNoGetWin; i > 0; i--)
			{
				m_enemyRoundIconD[i + m_enemyGetWin].Draw(rc);
			}
		}
	}
	// 1P VS 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//プレイヤー2デフォルトラウンドアイコン描画
		if (m_player2NoGetWin != 0)
		{
			for (int i = m_player2NoGetWin; i > 0; i--)
			{
				m_player2RoundIconD[i + m_player2GetWin].Draw(rc);
			}
		}
	}

	//プレイヤー勝利ラウンドアイコン描画
	if (m_playerGetWin != -1)
	{
		for (int i = 0; i <= m_playerGetWin; i++)
		{
			m_playerRoundIconW[i].Draw(rc);
		}
	}
	// 1P VS 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//敵勝利ラウンドアイコン描画
		if (m_enemyGetWin != -1)
		{
			for (int i = 0; i <= m_enemyGetWin; i++)
			{
				m_enemyRoundIconW[i].Draw(rc);
			}
		}
	}
	// 1P VS 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//プレイヤー2勝利ラウンドアイコン描画
		if (m_player2GetWin != -1)
		{
			for (int i = 0; i <= m_player2GetWin; i++)
			{
				m_player2RoundIconW[i].Draw(rc);
			}
		}
	}
}