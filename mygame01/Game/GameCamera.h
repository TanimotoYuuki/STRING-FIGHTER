#pragma once
class Game;
class Player;
class Enemy;
class Player2;
class GameCamera: public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	//�����o�ϐ�

	Vector3 m_target; //�����_(����)
	Vector3 m_targetLeft; //�����_(��)
	Vector3 m_targetRight; //�����_(�E)
	Vector3 m_cameraPos; //���_
	Vector3 m_playerDefaultPosition; //�v���C���[�����ʒu
	Vector3 m_playerPosition; //�v���C���[���݈ʒu
	Vector3 m_player2DefaultPosition; //�v���C���[2�����ʒu
	Vector3 m_player2Position; //�v���C���[2���݈ʒu
	Vector3 m_enemyDefaultPosition; //�G�����ʒu
	Vector3 m_enemyPosition; //�G���݈ʒu
	Vector3 m_movePos; //��ʒ[����p
	Vector3 m_playerMovePos; 
	Vector3 m_enemyMovePos;

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
};

