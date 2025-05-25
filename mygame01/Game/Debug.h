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

	//�����o�ϐ�

	FontRender m_playerPositionX; //�v���C���[�̃|�W�V����(X��)
	FontRender m_playerPositionY; //�v���C���[�̃|�W�V����(Y��)
	FontRender m_playerPositionZ; //�v���C���[�̃|�W�V����(Z��)
	FontRender m_enemyPositionX; //�G�̃|�W�V����(X��)
	FontRender m_enemyPositionY; //�G�̃|�W�V����(Y��)
	FontRender m_enemyPositionZ; //�G�̃|�W�V����(Z��)
	FontRender m_player2PositionX; //�v���C���[2�̃|�W�V����(X��)
	FontRender m_player2PositionY; //�v���C���[2�̃|�W�V����(Y��)
	FontRender m_player2PositionZ; //�v���C���[2�̃|�W�V����(Z��)
	FontRender m_lstickX; //���X�e�B�b�N(X��)
	FontRender m_lstickY; //���X�e�B�b�N(Y��)
	FontRender m_pushcountRight; //���X�e�B�b�N���E�ɓ|���Ă���
	FontRender m_pushcountLeft; //���X�e�B�b�N�����ɓ|���Ă���
	FontRender m_framePlayer; //�v���C���[�t���[�����
	FontRender m_dashflagRight; //�E�X�e�b�v�t���O
	FontRender m_dashflagLeft; //���X�e�b�v�t���O
	FontRender m_frameDefault; //�f�t�H���g�t���[��
	FontRender m_frameRight; //�E�t���[��
	FontRender m_frameLeft; //���t���[��
	FontRender m_playerHP; //�v���C���[�̗�
	FontRender m_enemyHP; //�G�̗�
	FontRender m_player2HP; //�v���C���[2�̗�
	FontRender m_fadeTime; //�t�F�[�h����
	FontRender m_currentAlpha; //�t�F�[�h
	FontRender m_movePosX; //���_(X��)
	FontRender m_movePosY; //���_(Y��)
	FontRender m_movePosZ; //���_(Z��)
	FontRender m_targetLeft; //�����_(��)
	FontRender m_target; //�����_(����)
	FontRender m_targetRight; //�����_(�E)
	FontRender m_damageCountP; //�_���[�W�J�E���g:�v���C���[
	FontRender m_damageCountE; //�_���[�W�J�E���g:�G
	FontRender m_damageCountP2; //�_���[�W�J�E���g:�v���C���[2

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

