#pragma once
class Game;
class Fade;
class Player;
class Enemy;
class Player2;
class GameTimer;
class Frame;
class Round: public IGameObject
{
public:
	Round();
	~Round();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//メンバ関数
	//試合が終わっているか？
	bool IsNoFighting();

	//再戦するとき変数の値をリセットする
	void Reset()
	{
		m_roundCount = 0;
		m_playerNoGetWin = 2;
		m_playerGetWin = -1;
		m_player2NoGetWin = 2;
		m_player2GetWin = -1;
		m_enemyNoGetWin = 2;
		m_enemyGetWin = -1;
		m_roundNo = 9;
		m_1pWinFlag = false;
		m_2pWinFlag = false;
		m_enemyWinFlag = false;
		m_drawFlag = false;
	}

	//メンバ変数
	//〇側状態
	enum enSideState
	{
		enSideState_Left, //左側
		enSideState_Right, //右側
		enSideState_Num, //〇側数
	};

	//ラウンド状態
	enum EnRoundState
	{		
		State_Idle, //待機
		State_Round, //ラウンド
		State_Fight, //ファイト
		State_Fighting, //ファイティング
		State_KO, //KO
		State_TimeUp, //タイムアップ
		State_Next, //ネクスト
		State_Num //ラウンド状態数
		//State_PlayerGetWIn,
		//State_EnemyGetWIn,
		//State_PlayerWIn,		
		//State_EnemyWIn,
		//State_Draw,
	};

	SpriteRender m_round[9]; //ラウンド1～9
	SpriteRender m_overround; //ラウンド10～
	SpriteRender m_fight; //ファイト
	SpriteRender m_ko; //KO
	SpriteRender m_doubleKO[2]; //ダブルKO
	SpriteRender m_perfectKO[2]; //パーフェクトKO
	SpriteRender m_timeUp; //タイムアップ
	SpriteRender m_finalRound[2]; //ファイナルラウンド
	SpriteRender m_playerRoundIconD[2]; //プレイヤーラウンド無取得アイコン
	SpriteRender m_player2RoundIconD[2]; //プレイヤー2ラウンド無取得アイコン
	SpriteRender m_enemyRoundIconD[2]; //敵ラウンド無取得アイコン
	SpriteRender m_playerRoundIconW[2]; //プレイヤーラウンド取得アイコン
	SpriteRender m_player2RoundIconW[2]; //プレイヤー2ラウンド取得アイコン
	SpriteRender m_enemyRoundIconW[2]; //敵ラウンド取得
	Vector3 m_roundIconLeftD[2] = { {-275.0f,385.0f,0.0f},{-335.0f,385.0f,0.0f} }; //ラウンド無取得:左側
	Vector3 m_roundIconRightD[2] = { {275.0f,385.0f,0.0f},{335.0f,385.0f,0.0f} }; //ラウンド無取得:右側
	Vector3 m_roundIconLeftW[2] = { {-275.0f,385.0f,0.0f},{-338.0f,385.0f,0.0f} }; //ラウンド取得:左側
	Vector3 m_roundIconRightW[2] = { {275.0f,385.0f,0.0f},{335.0f,385.0f,0.0f} }; //ラウンド取得:右側
	float m_fadeTime = 1.0f; //フェード時間
	float m_roundTime = 1.0f; //ラウンド表示時間
	float m_fightTime = 1.0f; //ファイト表示時間
	float m_koTime = 1.0f; //KO表示時間
	float m_timeUpTime = 1.0f; //タイムアップ表示時間
	int m_roundCount = 0; //ラウンドカウント
	int m_playerNoGetWin = 2; //プレイヤーラウンド無取得
	int m_playerGetWin = -1; //プレイヤーラウンド取得
	int m_player2NoGetWin = 2; //プレイヤー2ラウンド無取得
	int m_player2GetWin = -1; //プレイヤー2ラウンド取得
	int m_enemyNoGetWin = 2; //敵ラウンド無取得
	int m_enemyGetWin = -1; //敵ラウンド取得
	int m_roundNo = 9; //SE用
	bool m_battleFinishFlag = false; //対戦終了フラグ
	bool m_roundFlag = false; //ラウンド表示フラグ
	bool m_fightFlag = false; //ファイト表示フラグ
	bool m_koFlag = false; //KO表示フラグ
	bool m_doubleKOFlag = false; //ダブルKO表示フラグ
	bool m_perfectKOFlag = false; //パーフェクトKO表示フラグ
	bool m_timeUpFlag = false; //タイムアップ表示フラグ
	bool m_1pGetWinFlag = false; //プレイヤーラウンド取得フラグ
	bool m_1pWinFlag = false; //プレイヤー勝利フラグ
	bool m_2pGetWinFlag = false; //プレイヤー2ラウンド取得フラグ
	bool m_2pWinFlag = false; //プレイヤー2勝利フラグ	
	bool m_enemyGetWinFlag = false; //敵ラウンド取得フラグ
	bool m_enemyWinFlag = false; //敵勝利フラグ
	bool m_getDrawFlag = false; //引き分け取得フラグ
	bool m_drawFlag = false; //引き分けフラグ

	bool m_isWaitFadeout = false; //フェードアウトフラグ
	bool m_seFlag[State_Num]; //効果音フラグ
	EnRoundState m_roundState = State_Round; //ラウンド状態

	Game* m_game = nullptr;
	Fade* m_fade = nullptr;
	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
	GameTimer* m_gametimer = nullptr;
	Frame* m_frame = nullptr;
	SoundSource* m_roundSE = nullptr;
	SoundSource* m_fightSE = nullptr;
	SoundSource* m_koSE = nullptr;
	SoundSource* m_doubleKOSE = nullptr;
	SoundSource* m_perfectKOSE = nullptr;
};

