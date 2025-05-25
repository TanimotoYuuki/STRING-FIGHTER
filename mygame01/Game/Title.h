#pragma once
class Fade;
class Game;
class Title: public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//�����o�֐�
	//���̃C�[�W���O�ݒ�
	void FistSetEasing();

	//���̃C�[�W���O
	void FistEasing();

	//�^�C�g�����̃C�[�W���O�ݒ�
	void TitleNameSetEasing();

	//�^�C�g�����̃C�[�W���O
	void TitleNameEasing();

	//1P:�Z���I���̈ړ��C�[�W���O�ݒ�
	void Player1SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition);	

	//2P:�Z���I���̈ړ��C�[�W���O�ݒ�
	void Player2SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition);

	//1P:�Z���I���̈ړ��C�[�W���O
	void Player1SideMoveEasing(SpriteRender& target);	

	//2P:�Z���I���̈ړ��C�[�W���O
	void Player2SideMoveEasing(SpriteRender& target);
	
	//�t�F�[�h
	void ObjectFade();

	//�I���E�ړ�
	void Move();

	//�v���C���[�Z���I��
	void PlayerSide();

	//1P VS CPU �p�Z���I���E�ړ�
	void OnePlayerSideMove();

	//1P VS 2P �p�Z���I���E�ړ�
	void TwoPlayerSideMove();

	//�����o�ϐ�
	//�I�����
	enum enSelectState
	{
		enSelectState_Up, //��
		enSelectState_Down, //��
		enSelectState_Num //�I����Ԑ�
	};

	//�{�^�����
	enum enButtonState
	{
		enButtonState_A, //A�{�^��
		enButtonState_B, //B�{�^��
		enButtonState_X, //X�{�^��
		enButtonState_Y, //Y�{�^��
		enButtonState_Num //�{�^����Ԑ�
	};

	//�Z�����
	enum enSideState
	{
		enSideState_Left, //����
		enSideState_Right, //�E��
		enSideState_Num, //�Z����
	};

	//�Z���I�����
	enum enSideSelectState
	{
		enSideSelectState_Left, //����
		enSideSelectState_Right, //�E��
		enSideSelectState_Center, //����
		enSideSelectState_Num, //�Z���I��
	};

	SpriteRender m_titleBackGround; //�^�C�g���w�i
	SpriteRender m_fist; //��
	SpriteRender m_titleName; //�^�C�g����
	SpriteRender m_pressButton; //�v���X�{�^��
	SpriteRender m_mode; //���[�h
	SpriteRender m_vs[2]; //�Z�Z VS �Z�Z
	SpriteRender m_1p; //1P
	SpriteRender m_2p; //2P
	SpriteRender m_cpu[enSideState_Num]; //cpu
	SpriteRender m_playerSide[enSideSelectState_Num]; //�v���C���̃v���C���[�̏����ʒu:�Z��
	SpriteRender m_sideSelectText; //�Z���̑I���𑣂��e�L�X�g
	SpriteRender m_select[enSelectState_Num]; //�I��
	SpriteRender m_button[enButtonState_Num]; //�{�^��

	FontRender m_text[50]; //�e�L�X�g

	Vector3 m_fistScale; //��(�傫��)
	Vector3 m_fistScaleA; //��(�傫��: �C�[�W���O�J�n)
	Vector3 m_fistScaleB; //��(�傫��: �C�[�W���O�I��)
	float m_fistT = 0.0f; //��(�C�[�W���O����)
	bool m_fistSetEasingFlag = false; //���C�[�W���O�ݒ�I���t���O

	Vector3 m_titleNamePosition; //�^�C�g����(�ʒu)
	Vector3 m_titleNamePositionA; //�^�C�g����(�ʒu: �C�[�W���O�J�n)
	Vector3 m_titleNamePositionB; //�^�C�g����(�ʒu: �C�[�W���O�I��)
	float m_titleNameT = 0.0f; //�^�C�g����(�C�[�W���O����)
	bool m_titleNameSetEasingFlag = false; //�^�C�g�����C�[�W���O�ݒ�I���t���O	

	Vector3 m_1pSideSelectInitPosition; //1P:�Z���I��p�����ʒu
	Vector3 m_1psideSelectPosition; //1P:�Z���I��(�ʒu)
	Vector3 m_1psideSelectPositionA; //1P:�Z���I��(�ʒu: �C�[�W���O�J�n)
	Vector3 m_1psideSelectPositionB; //1P:�Z���I��(�ʒu: �C�[�W���O�I��)
	float m_1psideSelectT = 0.0f; //1P:�Z���I��(�C�[�W���O����)
	bool m_1psideSelectSetEasingFlag = false; //1P:�Z���I���C�[�W���O�ݒ�I���t���O	

	Vector3 m_2pSideSelectInitPosition; //2P:�Z���I��p�����ʒu
	Vector3 m_2psideSelectPosition; //2P:�Z���I��(�ʒu)
	Vector3 m_2psideSelectPositionA; //2P:�Z���I��(�ʒu: �C�[�W���O�J�n)
	Vector3 m_2psideSelectPositionB; //2P:�Z���I��(�ʒu: �C�[�W���O�I��)
	float m_2psideSelectT = 0.0f; //2P:�Z���I��(�C�[�W���O����)
	bool m_2psideSelectSetEasingFlag = false; //2P:�Z���I���C�[�W���O�ݒ�I���t���O

	float m_alpha = 0.0f; //�����x
	float m_halfFade = 1.0f; //�t�F�[�h(������)
	float m_allfade = 1.0f; //�t�F�[�h(����)
	float m_pressButtonTime = 1.0f; //�v���X�{�^������
	float m_selectTime = 1.0f; //�I������
	float m_sideSelectTime = 1.0f; //�Z���I������
	int m_selectNum = enSelectState_Up; //�I�����
	int m_onePlayerSideSelectNum = enSideSelectState_Center; //�Z���I�����(1P VS CPU)
	int m_twoPlayerSideSelectNum[2] = { enSideSelectState_Center,enSideSelectState_Center }; //�Z���I�����(1P VS 2P)
	int m_intTime = 0; //�����ϊ�
	int m_gamepad = 2; //�ڑ��ł���R���g���[���̐�

	bool m_moveFlag = false; //�X�^�[�g�E���[�h����t���O
	bool m_sideMoveFlag = false; //�Z������t���O
	bool m_onePlayerSideMoveSelectFlag = false; //�Z���I�𑀍�t���O(1P VS CPU)
	bool m_twoPlayerSideMoveSelectFlag[2] = { false ,false }; //�Z���I�𑀍�t���O(1P VS 2P)
	bool m_pressButtonfadeFlag = false; //�������t���O
	bool m_selectFlag = false; //�I���t���O
	bool m_selectFadeFlag = false; //�I��p�����t���O
	bool m_flashingFlag = false; //�_�Ńt���O
	bool m_halfFadeFlag = false; //�������t���O
	bool m_halfFadeFinishFlag = false; //�������I���t���O
	bool m_brightenFlag = false; //�s�����t���O
	bool m_roadFlag = false; //���[�h�t���O
	bool m_1pVScpuSelectFlag = false; //1P VS 2P �I���t���O
	bool m_1pVS2pSelectFlag = false; //1P VS 2P �I���t���O
	bool m_inGameFlag = false; //�C���Q�[���t���O

	Fade* m_fade = nullptr;
	Game* m_game = nullptr;
	SoundSource* m_bgm = nullptr;
};

