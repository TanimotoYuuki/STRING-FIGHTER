#pragma once
class Game;
class Round;
class Frame: public IGameObject
{
public:
	Frame();
	~Frame();
	bool Start();
	void Update();

	//�����o�֐�
	//�����ɒl����͂����炻�̒l���t���[�����Z����
	float GetFrame(float frame)
	{
		m_getFrame = frame / 60;
		return m_getFrame;
	}

	void FrameState();

	//���E���h���I�������ϐ��̒l�����Z�b�g����
	void Reset()
	{
		m_playerMoveState = 0;
		m_player2MoveState = 0;
		m_playertenkey = 0;
		m_player2tenkey = 0;

		for (int i = 0; i < 9; i++)
		{
			m_playerframe[i] = 0.0f;
		}

		for (int i = 0; i < 9; i++)
		{
			m_player2frame[i] = 0.0f;
		}
		m_frameDash = 0.0f;
	}

	//�����o�ϐ�
	//�X�e�B�b�N�������
	enum EnDirectionState
	{
		enDirectionState_Idle, //����
		enDirectionState_Right, //�E
		enDirectionState_Right_Up, //�E��
		enDirectionState_Right_Down, //�E��
		enDirectionState_Left, //��
		enDirectionState_Left_Up, //����
		enDirectionState_Left_Down, //����
		enDirectionState_Up, //��
		enDirectionState_Down, //��
		enDirectionState_NUM //�X�e�B�b�N������Ԑ�
	};
	int m_playerMoveState = 0; //�v���C���[�p�X�e�B�b�N�������
	int m_player2MoveState = 0; //�v���C���[2�p�X�e�B�b�N�������
	int m_playertenkey = 0; //�v���C���[�p�e���L�[
	int m_player2tenkey = 0; //�v���C���[2�p�e���L�[
	//�z��̗v�f��
	//0:�ҋ@
	//1:�E
	//2:�΂߉E��
	//3:�΂߉E��
	//4:��
	//5:�΂ߍ���
	//6:�΂ߍ���
	//7:��
	//8:��
	float m_playerframe[9] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; //�v���C���[�p�t���[���Ǘ�
	float m_player2frame[9] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; //�v���C���[2�p�t���[���Ǘ�
	float m_getFrame = 0.0f; //�t���[���擾
	float m_frameDash = 0.0f; //�_�b�V���t���[��

	Game* m_game = nullptr;
	Round* m_round = nullptr;
};

