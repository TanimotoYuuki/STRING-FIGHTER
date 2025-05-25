#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class Enemy;
class Player2;
class Frame;
class HP;
class Debug;
class GameTimer;
class Round;
class Result;
class Fade;
class GameCamera;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	
	//メンバ関数
	////試合が終わっているか？
	//bool IsFinish();

	//再戦するとき変数の値をリセットする
	void Reset()
	{
		//リザルト用BGMが再生していないか？
		if (m_resultBGMFlag != false)
		{
			DeleteGO(m_resultbgm);
			//対戦用BGM
			m_battlebgm = NewGO<SoundSource>(0);
			m_battlebgm->Init(7);
			m_battlebgm->Play(true);
			m_battlebgm->SetVolume(0.3f);
			m_resultBGMFlag = false;
		}
		m_selectNum = 0;
		m_intTime = 0;
		m_selectTime = 1.0f;
		m_selectFlag = false;
		m_selectFadeFlag = false;
		m_retryFlag = false;
	}

	//メンバ変数
	//選択状態
	enum enSelectState
	{
		enSelectState_Left, //左
		enSelectState_Right, //右
		enSelectState_Num //選択状態数
	};


	SpriteRender m_select[2]; //選択
	SpriteRender m_text[2]; //テキスト
	SpriteRender m_aButton; //Aボタン

	FontRender m_retry; //テキスト


	int m_flag = 0; //デバッグ用
	int m_count = 0; //デバッグ用	
	int m_selectNum = 0; //選択状態
	int m_intTime = 0; //整数変換	
	float m_selectTime = 1.0f; //選択時間
	//float m_fadeTime = 1.0f;
	//bool m_isWaitFadeout = false;
	//bool m_titleFlag = false; //タイトルへ戻る用フラグ
	int m_1pSide = 0; //プレイヤー:〇側
	int m_2pSide = 0; //プレイヤー2:〇側
	int m_cpuSide = 0; //CPU:〇側
	bool m_roadFlag = false; //ロードフラグ
	bool m_2playerFlag = false; //2人対戦用フラグ
	bool m_resultBGMFlag = false; //リザルト用BGM再生フラグ
	bool m_selectFlag = false; //選択フラグ
	bool m_selectFadeFlag = false; //選択用透明フラグ
	bool m_retryFlag = false; //再戦用フラグ

	Debug* m_debug = nullptr;
	Player* m_player = nullptr;
	BackGround* m_backGround = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
	Frame* m_frame = nullptr;
	HP* m_hp = nullptr;
	GameTimer* m_gametimer = nullptr;	
	Round* m_round = nullptr;
	Result* m_result = nullptr;
	Fade* m_fade = nullptr;
	GameCamera* m_gameCamera = nullptr;
	SoundSource* m_battlebgm = nullptr;
	SoundSource* m_resultbgm = nullptr;
};

