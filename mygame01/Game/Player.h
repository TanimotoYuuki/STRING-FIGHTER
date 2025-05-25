#pragma once
class Game;
class Enemy;
class Player2;
class Frame;
class GameTimer;
class Round;
class GameCamera;
class Collision;
class Player: public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);	

	//�L�����N�^�[�ړ�
	void Move();

	//�L�����N�^�[��]
	void Rotation();

	//�t���[���Ǘ�
	void FrameManage();

	//�����蔻��
	void Collision();	
	
	//�U��
	void Attack();

	//�A�j���V�����Ǘ�
	void ManageState();

	//�A�j���[�V����
	void PlayAnimation();

	//�A�j���[�V�����C�x���g
	void OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName);

	//�p���`�U���p�R���W����
	void MakePanchAttackCollision();	

	//�󒆃p���`�U���p�R���W����
	void MakeFlyingPanchAttackCollision();

	//�L�b�N�U���p�R���W����
	void MakeKickAttackCollision();

	//�󒆃L�b�N�U���p�R���W����
	void MakeFlyingKickAttackCollision();

	//�����o�֐�
	//�U�������炤���̗̑͂����炷
	//����:�L�����N�^�[�̗̑�,�Z�̍U����
	int TargetAttack(int HP,int ATK)
	{
		HP -= ATK;
		m_damageCount += ATK;
		m_damageFlag = true;
		return HP;
	}
	//���E���h���I�������ϐ��̒l�����Z�b�g����
	void Reset()
	{
		if (m_initSide == enSideState_Left)
		{
			m_position = { -100.0f,0.0f,0.0f };
		}
		else if (m_initSide == enSideState_Right)
		{
			m_position = { 100.0f,0.0f,0.0f };
		}
		m_charaCon.SetPosition(m_position);
		m_player.SetPosition(m_position);
		m_player.Update();
		m_noMovePosition = Vector3::Zero;
		m_repulsion = Vector3::Zero;

		m_animationState = false;
		m_pushRightFlag = false;
		m_pushLeftFlag = false;
		m_stepFlagRight = 0;
		m_stepFlagLeft = 0;
		m_startFlag = false;
		m_playerHP = 100;
		m_playerMaxHP = 100;
		m_damageCount = 0;
		m_damageCountTime = 0.0f;
		m_moveDirectionState = 0;
		m_frameMemoryDefault = 0.0f;
		m_frameMemoryRight = 0.0f;
		m_frameMemoryLeft = 0.0f;
		m_collisionHitFlag = false;
		m_panchAttackCollision = false;
		m_flyingPanchAttackCollision = false;
		m_kickAttackCollision = false;
		m_flyingKickAttackCollision = false;
		m_noMove = false;
		m_moveFlag = false;
		m_moveJumpFlag = false;
		m_rotationRightFlag = false;
		m_rotationLeftFlag = false;
		m_rotationKeepFlag = false;
		m_targetAttackFlag = false;
		m_upGuardFlag = false;
		m_downGuardFlag = false;
		m_upDamageFlag = false;
		m_downDamageFlag = false;
		m_flyDamageFlag = false;
		m_panchAnimationFlag = false;
		m_flyingPanchAnimationFlag = false;
		m_kickAnimationFlag = false;
		m_flyingKickAnimationFlag = false;
		m_stepAnimationFlagRight = false;
		m_stepAnimationFlagLeft = false;
		m_damageFlag = false;
	}

	//�����o�ϐ�	
	//�Z�����
	enum enSideState
	{
		enSideState_Left, //����
		enSideState_Right, //�E��
		enSideState_Num, //�Z����
	};

	//�A�j���[�V�����N���b�v
	enum EnAnimationClip { 
		enAnimationClip_Idle, //�ҋ@
		enAnimationClip_Jump, //�W�����v
		enAnimationClip_Walk_Forward, //�O�ړ�
		enAnimationClip_Walk_Back, //���ړ�
		enAnimationClip_Step_Forward, //�O�X�e�b�v
		enAnimationClip_Step_Back, //���X�e�b�v
		enAnimationClip_Panch, //�p���`
		enAnimationClip_Panch_Jump, //�󒆃p���`
		enAnimationClip_Panch_Guard, //�p���`�K�[�h
		enAnimationClip_Panch_Damage, //�p���`�_���[�W
		enAnimationClip_Kick, //�L�b�N
		enAnimationClip_Kick_Jump, //�󒆃L�b�N
		enAnimationClip_Kick_Guard, //�L�b�N�K�[�h
		enAnimationClip_Kick_Damage, //�L�b�N�_���[�W
		enAnimationClip_Fly_Damage, //�󒆃_���[�W
		enAnimationClip_Win, //����
		enAnimationClip_Lose, //�s�k
		enAnimationClip_Lose_TimeUp, //�^�C���A�b�v�s�k
		enAnimationClip_Draw, //��������
		enAnimationClip_Num, //�A�j���[�V�����N���b�v��
	};	
	//�A�j���[�V�������
	enum EnAnimationState 
	{
		enAnimationState_Idle, //�ҋ@
		enAnimationState_Jump, //�W�����v
		enAnimationState_Walk, //�ړ�
		enAnimationState_Step, //�X�e�b�v
		enAnimationState_Panch, //�p���`
		enAnimationState_Kick, //�L�b�N
		enAnimationState_Guard, //�K�[�h
		enAnimationState_Damage, //�_���[�W
		enAnimationState_Win, //����
		enAnimationState_Lose, //�s�k
		enAnimationState_Lose_TimeUp, //�^�C���A�b�v�s�k
		enAnimationState_Draw, //��������
		enAnimationState_Num, //�A�j���[�V������Ԑ�
	}; 
	//�������
	enum EnMoveState
	{
		enMoveState_Idle, //����
		enMoveState_Right, //�E
		enMoveState_Right_Up, //�E��
		enMoveState_Right_Down, //�E��
		enMoveState_Left, //��
		enMoveState_Left_Up, //����
		enMoveState_Left_Down, //����
		enMoveState_Up, //��
		enMoveState_Down, //��
		enMoveState_Num //������Ԑ�
	};

	AnimationClip m_animationClips[enAnimationClip_Num]; //�A�j���[�V�����N���b�v
	CharacterController m_charaCon; //�L�����N�^�[�R���g���[��
	ModelRender m_player; //���f��
	Vector3 m_position; //�v���C���[�̈ʒu
	Vector3 m_noMovePosition; //��ʒ[�ɍs�����Ƃ��̈ʒu
	Vector3 m_repulsion; //����(��ʒ[�p)
	Vector3 m_moveSpeed; //�v���C���[�̑��x
	Vector3 m_stickL; //���X�e�B�b�N
	Vector3 m_distance; //����
	Vector3 m_side = Vector3::AxisX; //�����蔻��̕�
	Vector3 m_up = Vector3::AxisY; //�����蔻��̍���
	//Vector3 m_collision_position;
	Quaternion m_rotation; //�v���C���[�̕���
	int m_animationState = 0; //�A�j���[�V�������
	bool m_pushRightFlag = false; //���X�e�B�b�N���E�ɓ|���Ă���H
	bool m_pushLeftFlag = false; //���X�e�B�b�N�����ɓ|���Ă���H
	int m_stepFlagRight = 0; //�E�X�e�b�v�t���O
	int m_stepFlagLeft = 0; //���X�e�b�v�t���O
	int m_gamepadNo = 0; //�Q�[���p�b�h���ԖځH
	bool m_startFlag = false; //���߂Ĉړ��������H
	//int m_finishflag = 0;
	int m_playerHP = 100; //�v���C���[�̗̑�
	int m_playerMaxHP = 100; //�v���C���[�̍ő�̗�
	int m_damageCount = 0; //�_���[�W�J�E���g(�f�o�b�O�p)
	float m_damageCountTime = 0.0f; //�_���[�W�J�E���g����(�f�o�b�O�p)
	int m_moveDirectionState = 0; //�������
	int m_initSide = 0; //�����ʒu:�Z��
	//int m_player_hp[2] = {100,100};
	//int m_player_maxhp[2] = {100,100};
	float m_frameMemoryDefault = 0.0f; //�ҋ@�t���[���ۊ�
	float m_frameMemoryRight = 0.0f; //�E�t���[���ۊ�
	float m_frameMemoryLeft = 0.0f; //���t���[���ۊ�
	bool m_collisionHitFlag = false; //�����蔻�肪�����������H
	bool m_panchAttackCollision =false; //�p���`�p�����蔻�蔭���t���O
	bool m_flyingPanchAttackCollision =false; //�󒆃p���`�p�����蔻�蔭���t���O
	bool m_kickAttackCollision =false; //�L�b�N�p�����蔻�蔭���t���O
	bool m_flyingKickAttackCollision =false; //�󒆃L�b�N�p�����蔻�蔭���t���O
	bool m_noMove = false; //��ʒ[�t���O
	bool m_moveFlag = false; //�ړ��������H(��ʒ[�p)
	bool m_moveJumpFlag = false; //�W�����v�������H(��ʒ[�p)
	bool m_rotationRightFlag = false; //�E�����Ă��邩�H
	bool m_rotationLeftFlag = false; //�������Ă��邩�H
	bool m_rotationKeepFlag = false; //�������Œ�
	bool m_targetAttackFlag = false; //�^�[�Q�b�g���U���������H
	bool m_upGuardFlag = false; //��i�K�[�h�t���O
	bool m_downGuardFlag = false; //���i�K�[�h�t���O
	bool m_upDamageFlag = false; //��i�_���[�W�t���O
	bool m_downDamageFlag = false; //���i�_���[�W�t���O
	bool m_flyDamageFlag = false; //�󒆃_���[�W�t���O
	bool m_panchAnimationFlag = false; //�p���`�A�j���[�V�����t���O
	bool m_flyingPanchAnimationFlag = false; //�󒆃p���`�A�j���[�V�����t���O
	bool m_kickAnimationFlag = false; //�L�b�N�A�j���[�V�����t���O
	bool m_flyingKickAnimationFlag = false; //�󒆃L�b�N�A�j���[�V�����t���O
	bool m_stepAnimationFlagRight = false; //�E�X�e�b�v�A�j���[�V�����t���O
	bool m_stepAnimationFlagLeft = false; //���X�e�b�v�A�j���[�V�����t���O
	bool m_damageFlag = false; //�_���[�W�t���O(�f�o�b�O�p)
	//float frame = 0;

	Game* m_game = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
	Frame* m_frame = nullptr;
	GameTimer* m_gametimer = nullptr;
	Round* m_round = nullptr;
	GameCamera* m_gameCamera = nullptr;
};

