#pragma once
class Game;
class Player;
class Player2;
class Enemy;
class HP: public IGameObject
{
public:
	HP();
	~HP();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//〇側状態
	enum enSideState
	{
		enSideState_Left, //左側
		enSideState_Right, //右側
		enSideState_Num, //〇側数
	};

	SpriteRender m_playerName; //プレイヤー(名前)
	SpriteRender m_enemyName; //敵(名前)
	SpriteRender m_player2Name; //プレイヤー2(名前)
	SpriteRender m_playerHPBer; //プレイヤー(体力バー)
	SpriteRender m_player2HPBer; //プレイヤー2(体力バー)
	//SpriteRender m_playerHPBer[2];
	SpriteRender m_enemyHPBer; //敵(体力バー)
	SpriteRender m_playerHPGauge; //プレイヤー(体力ゲージ)
	SpriteRender m_player2HPGauge; //プレイヤー2(体力ゲージ)
	//SpriteRender m_playerHPGauge[2];
	SpriteRender m_enemyHPGauge; //敵(体力ゲージ)

	//左側
	Vector3 m_sideLeftNamePosition = { -625.0f,375.0f,0.0f };
	Vector3 m_sideLeftHPBerPosition = { -500.0f,450.0f,0.0f };
	Vector3 m_sideLeftHPGaugePosition = { -246.0f,450.0f,0.0f };
	Vector2 m_sideLeftPivot = { 1.0f, 0.5f };

	//右側
	Vector3 m_sideRightNamePosition = { 625.0f,375.0f,0.0f };
	Vector3 m_sideRightHPBerPosition = { 500.0f,450.0f,0.0f };
	Vector3 m_sideRightHPGaugePosition = { 247.0f,450.0f,0.0f };
	Vector2 m_sideRightPivot = { 0.0f, 0.5f };

	//敵用左側
	Vector3 m_sideLeftEnemyNamePosition = { -675.0f,375.0f,0.0f };

	//敵用右側
	Vector3 m_sideRightEnemyNamePosition = { 675.0f,375.0f,0.0f };

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Player2* m_player2 = nullptr;
	Enemy* m_enemy = nullptr;
};

