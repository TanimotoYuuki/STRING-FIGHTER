#pragma once
class Game;
class Player;
class Player2;
class Enemy;
class Frame;
class GameTimer;
class Round;
class GameCamera;
class Fade;
class Debug: public IGameObject
{
public:
	Debug();
	~Debug();
	bool Start();
	void Update();
	void Render(RenderContext& re);

	//メンバ変数

	FontRender m_playerPositionX; //プレイヤーのポジション(X軸)
	FontRender m_playerPositionY; //プレイヤーのポジション(Y軸)
	FontRender m_playerPositionZ; //プレイヤーのポジション(Z軸)
	FontRender m_enemyPositionX; //敵のポジション(X軸)
	FontRender m_enemyPositionY; //敵のポジション(Y軸)
	FontRender m_enemyPositionZ; //敵のポジション(Z軸)
	FontRender m_player2PositionX; //プレイヤー2のポジション(X軸)
	FontRender m_player2PositionY; //プレイヤー2のポジション(Y軸)
	FontRender m_player2PositionZ; //プレイヤー2のポジション(Z軸)
	FontRender m_lstickX; //左スティック(X軸)
	FontRender m_lstickY; //左スティック(Y軸)
	FontRender m_pushcountRight; //左スティックを右に倒している
	FontRender m_pushcountLeft; //左スティックを左に倒している
	FontRender m_framePlayer; //プレイヤーフレーム状態
	FontRender m_dashflagRight; //右ステップフラグ
	FontRender m_dashflagLeft; //左ステップフラグ
	FontRender m_frameDefault; //デフォルトフレーム
	FontRender m_frameRight; //右フレーム
	FontRender m_frameLeft; //左フレーム
	FontRender m_playerHP; //プレイヤー体力
	FontRender m_enemyHP; //敵体力
	FontRender m_player2HP; //プレイヤー2体力
	FontRender m_fadeTime; //フェード時間
	FontRender m_currentAlpha; //フェード
	FontRender m_movePosX; //視点(X軸)
	FontRender m_movePosY; //視点(Y軸)
	FontRender m_movePosZ; //視点(Z軸)
	FontRender m_targetLeft; //注視点(左)
	FontRender m_target; //注視点(中央)
	FontRender m_targetRight; //注視点(右)
	FontRender m_damageCountP; //ダメージカウント:プレイヤー
	FontRender m_damageCountE; //ダメージカウント:敵
	FontRender m_damageCountP2; //ダメージカウント:プレイヤー2

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Player2* m_player2 = nullptr;
	Enemy* m_enemy = nullptr;
	Frame* m_frame = nullptr;
	GameTimer* m_gametimer = nullptr;
	Round* m_round = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Fade* m_fade = nullptr;
};

