#include "stdafx.h"
#include "Title.h"
#include "Fade.h"
#include "Game.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Title::Title()
{

}

Title::~Title()
{
	DeleteGO(m_fade);
}

bool Title::Start()
{
	//タイトルの背景
	m_titleBackGround.Init("Assets/screen/titlebackground.dds", 1920.0f, 1080.0f);
	m_titleBackGround.SetPosition({ 0.0f,0.0f,0.0f });
	m_titleBackGround.SetScale({ 1.0f,1.0f,1.0f });
	m_titleBackGround.Update();

	//拳
	m_fist.Init("Assets/screen/fist.dds", 1600.0f, 1200.0f);
	m_fist.SetPosition({ 0.0f,0.0f,0.0f });
	m_fist.SetScale({ 0.0f,0.0f,0.0f });
	m_fist.Update();

	//タイトル名
	m_titleName.Init("Assets/screen/titlename1.dds", 910.0f, 128.0f);
	m_titleName.SetPosition({ -1700.0f,350.0f,0.0f });
	m_titleName.SetScale({ 1.5f,1.5f,1.0f });
	m_titleName.Update();

	//プレスボタン
	m_pressButton.Init("Assets/screen/pressbutton1.dds", 910.0f, 128.0f);
	m_pressButton.SetPosition({ 0.0f,-350.0f,0.0f });
	m_pressButton.SetScale({ 1.5f,1.5f,1.0f });
	m_pressButton.Update();

	//1P VS CPU
	m_vs[0].Init("Assets/screen/1pvscpu1.dds", 486.0f, 128.0f);
	m_vs[0].SetPosition({0.0f,50.0f,0.0f});
	m_vs[0].SetScale({1.5f,1.5f,1.0f});
	m_vs[0].Update();

	//1P VS 2P
	m_vs[1].Init("Assets/screen/1pvs2p1.dds", 420.0f, 128.0f);
	m_vs[1].SetPosition({ 0.0f,-250.0f,0.0f });
	m_vs[1].SetScale({ 1.5f,1.5f,1.0f });
	m_vs[1].Update();

	//モード
	m_mode.Init("Assets/screen/mode.dds", 250.0f, 128.0f);
	m_mode.SetPosition({ 0.0f,350.0f,0.0f });
	m_mode.SetScale({ 1.5f,1.5f,1.0f });
	m_mode.Update();

	//1P
	m_1p.Init("Assets/screen/1p.dds", 256.0f, 128.0f);
	m_1p.SetPosition({ 0.0f,-125.0f,0.0f });
	m_1p.SetScale({ 1.0f,1.0f,1.0f });
	m_1p.Update();
	m_1pSideSelectInitPosition = m_1p.GetPosition();

	//2P
	m_2p.Init("Assets/screen/2p.dds", 256.0f, 128.0f);
	m_2p.SetPosition({ 0.0f,-325.0f,0.0f });
	m_2p.SetScale({ 1.0f,1.0f,1.0f });
	m_2p.Update();
	m_2pSideSelectInitPosition = m_2p.GetPosition();

	//CPU:左側側
	m_cpu[enSideState_Left].Init("Assets/screen/cpu.dds", 256.0f, 128.0f);
	m_cpu[enSideState_Left].SetPosition({425.0f,-225.0f,0.0f});
	m_cpu[enSideState_Left].SetScale({1.0f,1.0f,1.0f});
	m_cpu[enSideState_Left].Update();	

	//CPU:右側側
	m_cpu[enSideState_Right].Init("Assets/screen/cpu.dds", 256.0f, 128.0f);
	m_cpu[enSideState_Right].SetPosition({-475.0f,-225.0f,0.0f});
	m_cpu[enSideState_Right].SetScale({1.0f,1.0f,1.0f});
	m_cpu[enSideState_Right].Update();

	//プレイ中のプレイヤーの初期位置:左側
	m_playerSide[enSideState_Left].Init("Assets/screen/left.dds", 220.0f, 128.0f);
	m_playerSide[enSideState_Left].SetPosition({ -450.0f,100.0f,0.0f });
	m_playerSide[enSideState_Left].SetScale({ 1.5f,1.5f,1.0f });
	m_playerSide[enSideState_Left].Update();

	//プレイ中のプレイヤーの初期位置:右側
	m_playerSide[enSideState_Right].Init("Assets/screen/right.dds", 284.0f, 128.0f);
	m_playerSide[enSideState_Right].SetPosition({ 450.0f,100.0f,0.0f });
	m_playerSide[enSideState_Right].SetScale({ 1.5f,1.5f,1.0f });
	m_playerSide[enSideState_Right].Update();

	//〇側の選択を促すテキスト
	m_sideSelectText.Init("Assets/screen/sideselecttext.dds", 981.0f, 128.0f);
	m_sideSelectText.SetPosition({ 0.0f,350.0f,0.0f });
	m_sideSelectText.SetScale({ 1.5f,1.5f,1.0f });
	m_sideSelectText.Update();

	//選択
	m_select[enSelectState_Up].Init("Assets/screen/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Up].SetPosition({-500.0f,75.0f,0.0f});
	m_select[enSelectState_Up].SetScale({1.0f,1.0f,1.0f});
	m_select[enSelectState_Up].Update();

	m_select[enSelectState_Down].Init("Assets/screen/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Down].SetPosition({-500.0f,-225.0f,0.0f});
	m_select[enSelectState_Down].SetScale({1.0f,1.0f,1.0f});
	m_select[enSelectState_Down].Update();

	//Aボタン
	m_button[enButtonState_A].Init("Assets/UI/button/controller/A.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_A].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_A].SetPosition({ 500.0f,-475.0f,0.0f });
	m_button[enButtonState_A].Update();

	//Bボタン
	m_button[enButtonState_B].Init("Assets/UI/button/controller/B.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_B].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_B].SetPosition({ 700.0f,-475.0f,0.0f });
	m_button[enButtonState_B].Update();

	//Xボタン
	m_button[enButtonState_X].Init("Assets/UI/button/controller/X.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_X].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_X].Update();

	//Yボタン
	m_button[enButtonState_Y].Init("Assets/UI/button/controller/Y.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_Y].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_Y].Update();

	//決定
	m_text[0].SetText(L"決定");
	m_text[0].SetPosition(Vector3(525.0f, -455.0f, 0.0f));
	m_text[0].SetScale(1.0f);
	m_text[0].SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	//戻る
	m_text[1].SetText(L"戻る");
	m_text[1].SetPosition(Vector3(725.0f, -455.0f, 0.0f));
	m_text[1].SetScale(1.0f);
	m_text[1].SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	//BGM
	g_soundEngine->ResistWaveFileBank(0, "Assets/BGM/title_bgm.wav");
	//効果音
	g_soundEngine->ResistWaveFileBank(1, "Assets/SE/title_back.wav");
	g_soundEngine->ResistWaveFileBank(2, "Assets/SE/title_button1.wav");
	g_soundEngine->ResistWaveFileBank(3, "Assets/SE/title_button2.wav");
	g_soundEngine->ResistWaveFileBank(4, "Assets/SE/title_select.wav");

	//BGM
	m_bgm = NewGO<SoundSource>(0);
	m_bgm->Init(0);
	m_bgm->Play(true);
	m_bgm->SetVolume(0.3f);

	//インスタンス
	NewGO<Fade>(0, "fade");
	m_fade = FindGO<Fade>("fade");

	return true;
}

void Title::Update()
{
	//以下の条件になっていたときイージング処理をする
	if (m_moveFlag != true && //モード・スタート操作
		m_sideMoveFlag != true //〇側操作
		)
	{
		//拳のイージング設定が終わっていなかったら
		if (m_fistSetEasingFlag != true)
		{
			FistSetEasing(); //拳のイージング設定
		}
		//拳のイージング設定が終わったら
		else if (m_fistSetEasingFlag == true)
		{
			FistEasing(); //拳のイージング
		}

		//タイトルのイージング設定が終わったら
		if (m_titleNameSetEasingFlag == true)
		{
			TitleNameEasing(); //タイトル名のイージング
		}
	}
	//全てのイージングが終わったらスタートボタンが押せるようになる
	else if (m_moveFlag == true)
	{
		Move();
	}
	//モードが選択ができたら〇側選択ができるようになる
	else if (m_sideMoveFlag == true)
	{
		PlayerSide();
	}

	//プレスボタンの乗算カラー
	m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));

	//更新
	m_pressButton.Update();
}

//拳のイージング設定
void Title::FistSetEasing()
{
	m_fistScaleA = m_fist.GetScale();
	m_fistScaleB = { 1.0f,1.0f,1.0f };
	m_fistT = 0.0f;

	m_fistSetEasingFlag = true;
}

//拳のイージング
void Title::FistEasing()
{
	m_fistT += g_gameTime->GetFrameDeltaTime();

	//拳(イージング時間)が1.0秒になったら
	if (m_fistT > 1.0f)
	{
		m_fistT = 1.0f;
		//タイトルのイージング設定が終わっていなかったら
		if (m_titleNameSetEasingFlag != true)
		{
			//タイトル名のイージング設定
			TitleNameSetEasing();
		}
	}

	m_fistScale.Lerp(m_fistT, m_fistScaleA, m_fistScaleB);
	m_fist.SetScale(m_fistScale);
	m_fist.Update();
}

//タイトル名のイージング設定
void Title::TitleNameSetEasing()
{
	m_titleNamePositionA = m_titleName.GetPosition();
	m_titleNamePositionB = { 0.0f,350.0f,0.0f };
	m_titleNameT = 0.0f;

	m_titleNameSetEasingFlag = true;
}

//タイトル名のイージング
void Title::TitleNameEasing()
{
	m_titleNameT += g_gameTime->GetFrameDeltaTime();

	//タイトル名(イージング時間)が1.0秒になったら
	if (m_titleNameT > 1.0f)
	{
		m_titleNameT = 1.0f;
		m_moveFlag = true;
	}

	m_titleNamePosition.Lerp(m_titleNameT, m_titleNamePositionA, m_titleNamePositionB);
	m_titleName.SetPosition(m_titleNamePosition);
	m_titleName.Update();
}

//1P:〇側選択の移動イージング設定
void Title::Player1SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition)
{
	m_1psideSelectPositionA = target.GetPosition();
	switch (mode)
	{
	case enSideSelectState_Center: //中央
		m_1psideSelectPositionB = initPosition;
		break;
	case enSideSelectState_Left: //左側
		m_1psideSelectPositionB = { -475.0f,-225.0f,0.0f };
		break;
	case enSideSelectState_Right: //右側
		m_1psideSelectPositionB = { 425.0f,-225.0f,0.0f };
		break;
	default:
		break;
	}
	m_1psideSelectT = 0.0f;

	m_1psideSelectSetEasingFlag = true;
}

//2P:〇側選択の移動イージング設定
void Title::Player2SideMoveSetEasing(int mode, SpriteRender& target, Vector3 initPosition)
{
	m_2psideSelectPositionA = target.GetPosition();
	switch (mode)
	{
	case enSideSelectState_Center: //中央
		m_2psideSelectPositionB = initPosition;
		break;
	case enSideSelectState_Left: //左側
		m_2psideSelectPositionB = { -475.0f,-225.0f,0.0f };
		break;
	case enSideSelectState_Right: //右側
		m_2psideSelectPositionB = { 425.0f,-225.0f,0.0f };
		break;
	default:
		break;
	}
	m_2psideSelectT = 0.0f;

	m_2psideSelectSetEasingFlag = true;
}

//1P:〇側選択の移動イージング
void Title::Player1SideMoveEasing(SpriteRender& target)
{
	m_1psideSelectT += 4.5f * g_gameTime->GetFrameDeltaTime();

	//〇側選択時間(イージング時間)が1.0秒になったら
	if (m_1psideSelectT > 1.0f)
	{
		m_1psideSelectT = 1.0f;
		m_onePlayerSideMoveSelectFlag = false;
		m_twoPlayerSideMoveSelectFlag[0] = false;
		m_1psideSelectSetEasingFlag = false;
	}

	m_1psideSelectPosition.Lerp(m_1psideSelectT, m_1psideSelectPositionA, m_1psideSelectPositionB);
	target.SetPosition(m_1psideSelectPosition);
	target.Update();
}

//2P:〇側選択の移動イージング
void Title::Player2SideMoveEasing(SpriteRender& target)
{
	m_2psideSelectT += 4.5f * g_gameTime->GetFrameDeltaTime();

	//〇側選択時間(イージング時間)が1.0秒になったら
	if (m_2psideSelectT > 1.0f)
	{
		m_2psideSelectT = 1.0f;
		m_twoPlayerSideMoveSelectFlag[1] = false;
		m_2psideSelectSetEasingFlag = false;
	}

	m_2psideSelectPosition.Lerp(m_2psideSelectT, m_2psideSelectPositionA, m_2psideSelectPositionB);
	target.SetPosition(m_2psideSelectPosition);
	target.Update();
}

//選択・移動
void Title::Move()
{
	//スタート用
	//選択用のフェードかつ選択用のフェードを元に戻すフラグがtrueになっていないとき
	if (m_halfFadeFlag != true && m_brightenFlag != true)
	{
		//Aボタン押されていないとき
		if (m_flashingFlag != true)
		{
			//Aボタン
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				m_alpha = 1.0f; //不透明にする
				m_flashingFlag = true; //点滅する
				//効果音
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(2);
				se->Play(false);
				se->SetVolume(0.6f);
				//m_halfFadeFlag = true;
			}
		}

		//Aボタン押されていたら
		if (m_flashingFlag == true)
		{
			m_pressButtonTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
			m_intTime = m_pressButtonTime * 10;

			//プレスボタン時間が0.0秒になったら
			if (m_pressButtonTime <= 0.0f)
			{
				m_pressButtonfadeFlag = true; //透明にする

				//拳とタイトル名を透明にする
				ObjectFade();
			}
			//0秒になっていなかったら
			else
			{
				if (m_intTime % 2 == 0)
				{
					m_pressButtonfadeFlag = true; //透明にする
				}
				else
				{
					m_pressButtonfadeFlag = false; //透明にしない
				}
			}
		}
		else
		{
			//Press A ButtonのUIを透明にしたり元に戻したりする
			m_alpha += 1.2f * g_gameTime->GetFrameDeltaTime();
		}
	}

	//選択用
	//Press A ButtonのUIの点滅が終わったら
	if (m_halfFadeFlag == true)
	{
		////タイトルの背景を半透明にする
		//m_halfFade -= 0.5f * g_gameTime->GetFrameDeltaTime();

		////半透明になったら
		//if (m_halfFade <= 0.5f)
		//{
		//	m_halfFade = 0.5f; //半透明のままにする
		//	m_halfFadeFinishFlag = true; //半透明になった

		//	//Bボタン押されていないとき
		//	if (m_brightenFlag != true)
		//	{
		//		//Aボタン押されていないとき
		//		if (m_selectFlag != true)
		//		{
		//			//上ボタン
		//			if (g_pad[0]->IsTrigger(enButtonUp))
		//			{
		//				//選択状態が上のとき
		//				if (m_selectNum == enSelectState_Up)
		//				{
		//					m_selectNum = enSelectState_Down;
		//				}
		//				else
		//				{
		//					m_selectNum = enSelectState_Up;
		//				}
		//				//効果音
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(4);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//			}
		//			//下ボタン
		//			else if (g_pad[0]->IsTrigger(enButtonDown))
		//			{
		//				//選択状態が下のとき
		//				if (m_selectNum == enSelectState_Down)
		//				{
		//					m_selectNum = enSelectState_Up;
		//				}
		//				else
		//				{
		//					m_selectNum = enSelectState_Down;
		//				}
		//				//効果音
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(4);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//			}

		//			//Aボタン
		//			if (g_pad[0]->IsTrigger(enButtonA))
		//			{
		//				m_selectFlag = true;
		//				//効果音
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(2);
		//				//se->Init(3);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//				////BGMを流さない
		//				//DeleteGO(m_bgm);
		//			}
		//			//Bボタン
		//			if (g_pad[0]->IsTrigger(enButtonB))
		//			{
		//				m_halfFadeFlag = false; //半透明ではない
		//				m_brightenFlag = true; //不透明にする
		//				//効果音
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(1);
		//				se->Play(false);
		//				se->SetVolume(1.5f);
		//			}
		//		}

		//		//Aボタン押されていたら
		//		if (m_selectFlag == true)
		//		{
		//			m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
		//			m_intTime = m_selectTime * 10;

		//			//選択時間が0.0秒になったら
		//			if (m_selectTime <= 0.0f)
		//			{
		//				m_moveFlag = false; //モード操作ができなくなる
		//				m_sideMoveFlag = true; //〇側操作ができるようになる
		//				m_selectFlag = false; //モード画面に戻ったらモード操作ができるようにする
		//				m_selectFadeFlag = false; //不透明にする
		//				m_selectTime = 1.0f; //選択時間

		//				////ロードしていないとき
		//				//if (m_roadFlag != true)
		//				//{
		//				//	m_fade->StartFadeOut();
		//				//	m_roadFlag = true;
		//				//}
		//				////フェードアウトが終わったら
		//				//if (!m_fade->IsFade())
		//				//{
		//				//	NewGO<Game>(0, "game");
		//				//	m_game = FindGO<Game>("game");
		//				//	//選択状態が下のとき
		//				//	if (m_selectNum == enSelectState_Down)
		//				//	{
		//				//		m_1pVS2pSelectFlag = true;
		//				//		m_game->m_2playerFlag = m_1pVS2pSelectFlag;
		//				//	}
		//				//	DeleteGO(this);
		//				//}
		//			}
		//			//0秒になっていなかったら
		//			else
		//			{
		//				if (m_intTime % 2 == 0)
		//				{
		//					m_selectFadeFlag = true; //透明にする
		//				}
		//				else
		//				{
		//					m_selectFadeFlag = false; //透明にしない
		//				}
		//			}
		//		}
		//	}
		//}
		// 

		//m_halfFade = 0.5f; //半透明のままにする
		m_halfFadeFinishFlag = true; //半透明になった

		//Bボタン押されていないとき
		if (m_brightenFlag != true)
		{
			//Aボタン押されていないとき
			if (m_selectFlag != true)
			{
				//上ボタン
				if (g_pad[0]->IsTrigger(enButtonUp))
				{
					//選択状態が上のとき
					if (m_selectNum == enSelectState_Up)
					{
						m_selectNum = enSelectState_Down;
					}
					else
					{
						m_selectNum = enSelectState_Up;
					}
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				//下ボタン
				else if (g_pad[0]->IsTrigger(enButtonDown))
				{
					//選択状態が下のとき
					if (m_selectNum == enSelectState_Down)
					{
						m_selectNum = enSelectState_Up;
					}
					else
					{
						m_selectNum = enSelectState_Down;
					}
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}

				//Aボタン
				if (g_pad[0]->IsTrigger(enButtonA))
				{
					m_selectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(2);
					//se->Init(3);
					se->Play(false);
					se->SetVolume(0.6f);
					////BGMを流さない
					//DeleteGO(m_bgm);
				}
				//Bボタン
				if (g_pad[0]->IsTrigger(enButtonB))
				{
					m_halfFadeFlag = false; //半透明ではない
					m_brightenFlag = true; //不透明にする
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(1);
					se->Play(false);
					se->SetVolume(1.5f);
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
					m_moveFlag = false; //モード操作ができなくなる
					m_sideMoveFlag = true; //〇側操作ができるようになる
					m_selectFlag = false; //モード画面に戻ったらモード操作ができるようにする
					m_selectFadeFlag = false; //不透明にする
					m_selectTime = 1.0f; //選択時間

					////ロードしていないとき
					//if (m_roadFlag != true)
					//{
					//	m_fade->StartFadeOut();
					//	m_roadFlag = true;
					//}
					////フェードアウトが終わったら
					//if (!m_fade->IsFade())
					//{
					//	NewGO<Game>(0, "game");
					//	m_game = FindGO<Game>("game");
					//	//選択状態が下のとき
					//	if (m_selectNum == enSelectState_Down)
					//	{
					//		m_1pVS2pSelectFlag = true;
					//		m_game->m_2playerFlag = m_1pVS2pSelectFlag;
					//	}
					//	DeleteGO(this);
					//}
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
		}
		//タイトルの背景の乗算カラー
		//m_titleBackGround.SetMulColor({ 1.0f, 1.0f, 1.0f, m_halfFade });
	}
	//Bボタンが押されていたら
	else if (m_brightenFlag == true)
	{
		////タイトルの背景を不透明にする
		//m_halfFade += 0.5f * g_gameTime->GetFrameDeltaTime();

		////不透明になったら
		//if (m_halfFade >= 1.0f)
		//{
		//	m_halfFade = 1.0f; //値をリセットする

		//	//透明率を不透明にする
		//	m_allfade = 1.0f;
		//	m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
		//	m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });

		//	//イージング用に座標を元の位置に戻す
		//	m_titleName.SetPosition({ -1700.0f, 350.0f, 0.0f });
		//	m_fist.SetScale({ 0.0f,0.0f,0.0f });

		//	//更新
		//	m_titleName.Update();
		//	m_fist.Update();

		//	//スタートボタン
		//	m_alpha = 0.0f;
		//	m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));
		//	m_pressButton.Update();
		//	m_pressButtonfadeFlag = false; //透明にしない

		//	m_fistSetEasingFlag = false; //拳のイージングフラグ
		//	m_titleNameSetEasingFlag = false; //タイトル名のイージングフラグ
		//	m_moveFlag = false; //選択・移動可能フラグ

		//	m_halfFadeFinishFlag = false; //半透明完了フラグ
		//	m_brightenFlag = false; //不透明にするフラグ

		//	m_selectNum = enSelectState_Up;
		//}
		//タイトルの背景の乗算カラー
		//m_titleBackGround.SetMulColor({ 1.0f, 1.0f, 1.0f, m_halfFade });

		//m_halfFade = 1.0f; //値をリセットする

		//透明率を不透明にする
		m_allfade = 1.0f;
		m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
		m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });

		//イージング用に座標を元の位置に戻す
		m_titleName.SetPosition({ -1700.0f, 350.0f, 0.0f });
		m_fist.SetScale({ 0.0f,0.0f,0.0f });

		//更新
		m_titleName.Update();
		m_fist.Update();

		//スタートボタン
		m_alpha = 0.0f;
		m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));
		m_pressButton.Update();
		m_pressButtonfadeFlag = false; //透明にしない

		m_fistSetEasingFlag = false; //拳のイージングフラグ
		m_titleNameSetEasingFlag = false; //タイトル名のイージングフラグ
		m_moveFlag = false; //選択・移動可能フラグ

		m_halfFadeFinishFlag = false; //半透明完了フラグ
		m_brightenFlag = false; //不透明にするフラグ

		m_selectNum = enSelectState_Up;
	}
}

//プレイヤー〇側選択
void Title::PlayerSide()
{
	//モード選択画面で何を選択したか
	switch (m_selectNum)
	{
	case enSelectState_Up: //1P VS CPU
		m_1pVScpuSelectFlag = true;
		OnePlayerSideMove();
		break;
	case enSelectState_Down: //1P VS 2P
		m_1pVS2pSelectFlag = true;
		TwoPlayerSideMove();
		break;
	default:
		break;
	}
}

//プレイヤー〇側選択・移動
void Title::OnePlayerSideMove()
{
	//〇側選択で操作していないとき
	if (m_onePlayerSideMoveSelectFlag != true)
	{
		//Aボタン押されていないとき
		if (m_selectFlag != true)
		{
			//〇側選択で何を選択しているか
			switch (m_onePlayerSideSelectNum)
			{
			case enSideSelectState_Center: //中央
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Left;
					m_onePlayerSideMoveSelectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				else if (g_pad[0]->IsTrigger(enButtonRight))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Right;
					m_onePlayerSideMoveSelectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			case enSideSelectState_Left: //左側
				if (g_pad[0]->IsTrigger(enButtonRight))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Center;
					m_onePlayerSideMoveSelectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			case enSideSelectState_Right: //右側
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Center;
					m_onePlayerSideMoveSelectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			default:
				break;
			}

			//選択が中央以外のとき
			if (m_onePlayerSideSelectNum != enSideSelectState_Center)
			{
				if (g_pad[0]->IsTrigger(enButtonA))
				{
					m_selectFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(3);
					se->Play(false);
					se->SetVolume(0.6f);
					//BGMを流さない
					DeleteGO(m_bgm);
				}
			}
			if (g_pad[0]->IsTrigger(enButtonB))
			{
				m_sideMoveFlag = false;
				m_moveFlag = true;
				m_1pVScpuSelectFlag = false;
				m_onePlayerSideSelectNum = enSideSelectState_Center;
				m_1p.SetPosition(m_1pSideSelectInitPosition);
				m_1p.Update();
				//効果音
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(1);
				se->Play(false);
				se->SetVolume(1.5f);
			}
		}
		//Aボタンが押されていたら
		else if (m_selectFlag == true)
		{
			m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
			if (m_selectTime <= 0.0f)
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
					if (m_inGameFlag != true)
					{
						NewGO<Game>(0, "game");
						m_game = FindGO<Game>("game");
						m_inGameFlag = true;
					}
					//以下の選択になっているとき
					if (m_onePlayerSideSelectNum == enSideSelectState_Left) //1P:左側
					{
						m_game->m_1pSide = enSideSelectState_Left;
						m_game->m_cpuSide = enSideSelectState_Right;
					}
					else if (m_onePlayerSideSelectNum == enSideSelectState_Right) //1P:右側
					{
						m_game->m_1pSide = enSideSelectState_Right;
						m_game->m_cpuSide = enSideSelectState_Left;
					}
					DeleteGO(this);
				}
			}
		}
	}
	//〇側選択で操作したとき
	else if (m_onePlayerSideMoveSelectFlag == true)
	{
		//選択のイージング設定が終わっていないとき
		if (m_1psideSelectSetEasingFlag != true)
		{
			Player1SideMoveSetEasing(m_onePlayerSideSelectNum, m_1p, m_1pSideSelectInitPosition);
		}
		//選択のイージング設定が終わったとき
		else if (m_1psideSelectSetEasingFlag == true)
		{
			Player1SideMoveEasing(m_1p);
		}
	}
}

void Title::TwoPlayerSideMove()
{
	for (int i = 0; i < m_gamepad; i++)
	{
		//〇側選択で操作していないとき
		if (m_twoPlayerSideMoveSelectFlag[i] != true)
		{
			//Aボタンが押されていないとき
			if (m_selectFlag != true)
			{
				//〇側選択で何を選択しているか
				switch (m_twoPlayerSideSelectNum[i])
				{
				case enSideSelectState_Center: //中央
					if (g_pad[i]->IsTrigger(enButtonLeft))
					{
						//以下の条件になっていたとき移動しない
						if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Left && //左側
							m_twoPlayerSideSelectNum[1] != enSideSelectState_Left //左側
							)
						{
							m_twoPlayerSideSelectNum[i] = enSideSelectState_Left;
							m_twoPlayerSideMoveSelectFlag[i] = true;
							//効果音
							SoundSource* se = NewGO<SoundSource>(0);
							se->Init(4);
							se->Play(false);
							se->SetVolume(0.6f);
						}
					}
					else if (g_pad[i]->IsTrigger(enButtonRight))
					{
						//以下の条件になっていたとき移動しない
						if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Right && //右側
							m_twoPlayerSideSelectNum[1] != enSideSelectState_Right //右側
							)
						{
							m_twoPlayerSideSelectNum[i] = enSideSelectState_Right;
							m_twoPlayerSideMoveSelectFlag[i] = true;
							//効果音
							SoundSource* se = NewGO<SoundSource>(0);
							se->Init(4);
							se->Play(false);
							se->SetVolume(0.6f);
						}
					}
					break;
				case enSideSelectState_Left: //左側
					if (g_pad[i]->IsTrigger(enButtonRight))
					{
						m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
						m_twoPlayerSideMoveSelectFlag[i] = true;
						//効果音
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(4);
						se->Play(false);
						se->SetVolume(0.6f);
					}
					break;
				case enSideSelectState_Right: //右側
					if (g_pad[i]->IsTrigger(enButtonLeft))
					{
						m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
						m_twoPlayerSideMoveSelectFlag[i] = true;
						//効果音
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(4);
						se->Play(false);
						se->SetVolume(0.6f);
					}
					break;
				default:
					break;
				}

				//以下の条件になっていたときAボタン押しても反応しない
				if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Center && //中央
					m_twoPlayerSideSelectNum[1] != enSideSelectState_Center //中央
					)
				{
					if (g_pad[i]->IsTrigger(enButtonA))
					{
						m_selectFlag = true;
						//効果音
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(3);
						se->Play(false);
						se->SetVolume(0.6f);
						//BGMを流さない
						DeleteGO(m_bgm);
					}
				}
				if (g_pad[i]->IsTrigger(enButtonB))
				{
					m_sideMoveFlag = false;
					m_moveFlag = true;
					m_1pVS2pSelectFlag = false;
					m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
					m_1p.SetPosition(m_1pSideSelectInitPosition);
					m_1p.Update();
					m_2p.SetPosition(m_2pSideSelectInitPosition);
					m_2p.Update();
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(1);
					se->Play(false);
					se->SetVolume(1.5f);
				}
			}
			//Aボタンが押されていたら
			else if (m_selectFlag == true)
			{
				m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
				if (m_selectTime <= 0.0f)
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
						if (m_inGameFlag != true)
						{
							NewGO<Game>(0, "game");
							m_game = FindGO<Game>("game");
							m_inGameFlag = true;
						}
						//以下の選択になっているとき
						if (m_twoPlayerSideSelectNum[0] == enSideSelectState_Left && //1P:左側
							m_twoPlayerSideSelectNum[1] == enSideSelectState_Right //2P:右側
							)
						{
							m_game->m_2playerFlag = m_1pVS2pSelectFlag;
							m_game->m_1pSide = enSideSelectState_Left;
							m_game->m_2pSide = enSideSelectState_Right;
						}
						else if (m_twoPlayerSideSelectNum[0] == enSideSelectState_Right && //1P:右側
								 m_twoPlayerSideSelectNum[1] == enSideSelectState_Left //2P:左側
							    )
						{
							m_game->m_2playerFlag = m_1pVS2pSelectFlag;
							m_game->m_1pSide = enSideSelectState_Right;
							m_game->m_2pSide = enSideSelectState_Left;
						}
						DeleteGO(this);
					}
				}
			}
		}
		//〇側選択で操作したとき
		else if (m_twoPlayerSideMoveSelectFlag[i] == true)
		{
			//選択のイージング設定が終わっていないとき
			if (m_1psideSelectSetEasingFlag != true)
			{
				Player1SideMoveSetEasing(m_twoPlayerSideSelectNum[0], m_1p, m_1pSideSelectInitPosition);
			}
			//選択のイージング設定が終わったとき
			else if (m_1psideSelectSetEasingFlag == true)
			{
				Player1SideMoveEasing(m_1p);
			}

			//選択のイージング設定が終わっていないとき
			if (m_2psideSelectSetEasingFlag != true)
			{
				Player2SideMoveSetEasing(m_twoPlayerSideSelectNum[1], m_2p, m_2pSideSelectInitPosition);
			}
			//選択のイージング設定が終わったとき
			else if (m_2psideSelectSetEasingFlag == true)
			{
				Player2SideMoveEasing(m_2p);
			}
		}
	}
}

//フェード
void Title::ObjectFade()
{
	m_allfade -= g_gameTime->GetFrameDeltaTime();
	//フェード(透明)が0.0秒になったら
	if (m_allfade < 0.0f)
	{
		m_allfade = 0.0f; //透明
		m_pressButtonTime = 1.0f;
		m_flashingFlag = false; //点滅しない
		m_halfFadeFlag = true; //半透明にする
	}
	m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
	m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
}

void Title::Render(RenderContext& rc)
{
	//描画
	m_titleBackGround.Draw(rc);
	m_fist.Draw(rc);
	m_titleName.Draw(rc);

	//m_1p.Draw(rc);
	//m_2p.Draw(rc);
	//m_cpu.Draw(rc);
	//m_playerSide[enSideState_Left].Draw(rc);
	//m_playerSide[enSideState_Right].Draw(rc);
	//m_sideSelectText.Draw(rc);

	//Aボタンが押されていなかったら
	if (m_pressButtonfadeFlag != true)
	{
		//プレスボタン描画
		m_pressButton.Draw(rc);
	}

	//タイトルの背景が半透明になったら
	if (m_halfFadeFinishFlag == true)
	{
		if (m_brightenFlag != true && m_sideMoveFlag != true)
		{
			if (m_selectFadeFlag != true)
			{
				//選択描画
				m_select[m_selectNum].Draw(rc);
			}
			for (int i = 0; i < 2; i++)
			{
				//〇〇 VS 〇〇
				m_vs[i].Draw(rc);
			}
			//モード
			m_mode.Draw(rc);
		}
		else if (m_sideMoveFlag == true)
		{
			for (int i = 0; i < enSideState_Num; i++)
			{
				//〇側
				m_playerSide[i].Draw(rc);
			}
			//選択
			if (m_1pVS2pSelectFlag == true)
			{
				m_2p.Draw(rc);
			}
			else if (m_1pVScpuSelectFlag == true)
			{
				for (int i = 0; i < enSideState_Num; i++)
				{
					m_cpu[i].Draw(rc);
				}
			}
			m_1p.Draw(rc);
			//選択を促すテキスト
			m_sideSelectText.Draw(rc);
		}
		if (m_brightenFlag != true)
		{
			//ボタン
			m_button[enButtonState_A].Draw(rc);
			m_button[enButtonState_B].Draw(rc);
			//テキスト
			m_text[0].Draw(rc);
			m_text[1].Draw(rc);
		}
	}
}