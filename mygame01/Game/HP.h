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

	//�Z�����
	enum enSideState
	{
		enSideState_Left, //����
		enSideState_Right, //�E��
		enSideState_Num, //�Z����
	};

	SpriteRender m_playerName; //�v���C���[(���O)
	SpriteRender m_enemyName; //�G(���O)
	SpriteRender m_player2Name; //�v���C���[2(���O)
	SpriteRender m_playerHPBer; //�v���C���[(�̗̓o�[)
	SpriteRender m_player2HPBer; //�v���C���[2(�̗̓o�[)
	//SpriteRender m_playerHPBer[2];
	SpriteRender m_enemyHPBer; //�G(�̗̓o�[)
	SpriteRender m_playerHPGauge; //�v���C���[(�̗̓Q�[�W)
	SpriteRender m_player2HPGauge; //�v���C���[2(�̗̓Q�[�W)
	//SpriteRender m_playerHPGauge[2];
	SpriteRender m_enemyHPGauge; //�G(�̗̓Q�[�W)

	//����
	Vector3 m_sideLeftNamePosition = { -625.0f,375.0f,0.0f };
	Vector3 m_sideLeftHPBerPosition = { -500.0f,450.0f,0.0f };
	Vector3 m_sideLeftHPGaugePosition = { -246.0f,450.0f,0.0f };
	Vector2 m_sideLeftPivot = { 1.0f, 0.5f };

	//�E��
	Vector3 m_sideRightNamePosition = { 625.0f,375.0f,0.0f };
	Vector3 m_sideRightHPBerPosition = { 500.0f,450.0f,0.0f };
	Vector3 m_sideRightHPGaugePosition = { 247.0f,450.0f,0.0f };
	Vector2 m_sideRightPivot = { 0.0f, 0.5f };

	//�G�p����
	Vector3 m_sideLeftEnemyNamePosition = { -675.0f,375.0f,0.0f };

	//�G�p�E��
	Vector3 m_sideRightEnemyNamePosition = { 675.0f,375.0f,0.0f };

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Player2* m_player2 = nullptr;
	Enemy* m_enemy = nullptr;
};

