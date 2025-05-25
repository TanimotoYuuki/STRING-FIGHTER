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

	//メンバ変数

	Vector3 m_target; //注視点(中央)
	Vector3 m_targetLeft; //注視点(左)
	Vector3 m_targetRight; //注視点(右)
	Vector3 m_cameraPos; //視点
	Vector3 m_playerDefaultPosition; //プレイヤー初期位置
	Vector3 m_playerPosition; //プレイヤー現在位置
	Vector3 m_player2DefaultPosition; //プレイヤー2初期位置
	Vector3 m_player2Position; //プレイヤー2現在位置
	Vector3 m_enemyDefaultPosition; //敵初期位置
	Vector3 m_enemyPosition; //敵現在位置
	Vector3 m_movePos; //画面端判定用
	Vector3 m_playerMovePos; 
	Vector3 m_enemyMovePos;

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
};

