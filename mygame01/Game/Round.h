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

	//�����o�֐�
	//�������I����Ă��邩�H
	bool IsNoFighting();

	//�Đ킷��Ƃ��ϐ��̒l�����Z�b�g����
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

	//�����o�ϐ�
	//�Z�����
	enum enSideState
	{
		enSideState_Left, //����
		enSideState_Right, //�E��
		enSideState_Num, //�Z����
	};

	//���E���h���
	enum EnRoundState
	{		
		State_Idle, //�ҋ@
		State_Round, //���E���h
		State_Fight, //�t�@�C�g
		State_Fighting, //�t�@�C�e�B���O
		State_KO, //KO
		State_TimeUp, //�^�C���A�b�v
		State_Next, //�l�N�X�g
		State_Num //���E���h��Ԑ�
		//State_PlayerGetWIn,
		//State_EnemyGetWIn,
		//State_PlayerWIn,		
		//State_EnemyWIn,
		//State_Draw,
	};

	SpriteRender m_round[9]; //���E���h1�`9
	SpriteRender m_overround; //���E���h10�`
	SpriteRender m_fight; //�t�@�C�g
	SpriteRender m_ko; //KO
	SpriteRender m_doubleKO[2]; //�_�u��KO
	SpriteRender m_perfectKO[2]; //�p�[�t�F�N�gKO
	SpriteRender m_timeUp; //�^�C���A�b�v
	SpriteRender m_finalRound[2]; //�t�@�C�i�����E���h
	SpriteRender m_playerRoundIconD[2]; //�v���C���[���E���h���擾�A�C�R��
	SpriteRender m_player2RoundIconD[2]; //�v���C���[2���E���h���擾�A�C�R��
	SpriteRender m_enemyRoundIconD[2]; //�G���E���h���擾�A�C�R��
	SpriteRender m_playerRoundIconW[2]; //�v���C���[���E���h�擾�A�C�R��
	SpriteRender m_player2RoundIconW[2]; //�v���C���[2���E���h�擾�A�C�R��
	SpriteRender m_enemyRoundIconW[2]; //�G���E���h�擾
	Vector3 m_roundIconLeftD[2] = { {-275.0f,385.0f,0.0f},{-335.0f,385.0f,0.0f} }; //���E���h���擾:����
	Vector3 m_roundIconRightD[2] = { {275.0f,385.0f,0.0f},{335.0f,385.0f,0.0f} }; //���E���h���擾:�E��
	Vector3 m_roundIconLeftW[2] = { {-275.0f,385.0f,0.0f},{-338.0f,385.0f,0.0f} }; //���E���h�擾:����
	Vector3 m_roundIconRightW[2] = { {275.0f,385.0f,0.0f},{335.0f,385.0f,0.0f} }; //���E���h�擾:�E��
	float m_fadeTime = 1.0f; //�t�F�[�h����
	float m_roundTime = 1.0f; //���E���h�\������
	float m_fightTime = 1.0f; //�t�@�C�g�\������
	float m_koTime = 1.0f; //KO�\������
	float m_timeUpTime = 1.0f; //�^�C���A�b�v�\������
	int m_roundCount = 0; //���E���h�J�E���g
	int m_playerNoGetWin = 2; //�v���C���[���E���h���擾
	int m_playerGetWin = -1; //�v���C���[���E���h�擾
	int m_player2NoGetWin = 2; //�v���C���[2���E���h���擾
	int m_player2GetWin = -1; //�v���C���[2���E���h�擾
	int m_enemyNoGetWin = 2; //�G���E���h���擾
	int m_enemyGetWin = -1; //�G���E���h�擾
	int m_roundNo = 9; //SE�p
	bool m_battleFinishFlag = false; //�ΐ�I���t���O
	bool m_roundFlag = false; //���E���h�\���t���O
	bool m_fightFlag = false; //�t�@�C�g�\���t���O
	bool m_koFlag = false; //KO�\���t���O
	bool m_doubleKOFlag = false; //�_�u��KO�\���t���O
	bool m_perfectKOFlag = false; //�p�[�t�F�N�gKO�\���t���O
	bool m_timeUpFlag = false; //�^�C���A�b�v�\���t���O
	bool m_1pGetWinFlag = false; //�v���C���[���E���h�擾�t���O
	bool m_1pWinFlag = false; //�v���C���[�����t���O
	bool m_2pGetWinFlag = false; //�v���C���[2���E���h�擾�t���O
	bool m_2pWinFlag = false; //�v���C���[2�����t���O	
	bool m_enemyGetWinFlag = false; //�G���E���h�擾�t���O
	bool m_enemyWinFlag = false; //�G�����t���O
	bool m_getDrawFlag = false; //���������擾�t���O
	bool m_drawFlag = false; //���������t���O

	bool m_isWaitFadeout = false; //�t�F�[�h�A�E�g�t���O
	bool m_seFlag[State_Num]; //���ʉ��t���O
	EnRoundState m_roundState = State_Round; //���E���h���

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

