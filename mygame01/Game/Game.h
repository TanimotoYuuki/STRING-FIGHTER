#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class Enemy;
class Player2;
class Frame;
class HP;
class Debug;
class GameTimer;
class Round;
class Result;
class Fade;
class GameCamera;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	
	//�����o�֐�
	////�������I����Ă��邩�H
	//bool IsFinish();

	//�Đ킷��Ƃ��ϐ��̒l�����Z�b�g����
	void Reset()
	{
		//���U���g�pBGM���Đ����Ă��Ȃ����H
		if (m_resultBGMFlag != false)
		{
			DeleteGO(m_resultbgm);
			//�ΐ�pBGM
			m_battlebgm = NewGO<SoundSource>(0);
			m_battlebgm->Init(7);
			m_battlebgm->Play(true);
			m_battlebgm->SetVolume(0.3f);
			m_resultBGMFlag = false;
		}
		m_selectNum = 0;
		m_intTime = 0;
		m_selectTime = 1.0f;
		m_selectFlag = false;
		m_selectFadeFlag = false;
		m_retryFlag = false;
	}

	//�����o�ϐ�
	//�I�����
	enum enSelectState
	{
		enSelectState_Left, //��
		enSelectState_Right, //�E
		enSelectState_Num //�I����Ԑ�
	};


	SpriteRender m_select[2]; //�I��
	SpriteRender m_text[2]; //�e�L�X�g
	SpriteRender m_aButton; //A�{�^��

	FontRender m_retry; //�e�L�X�g


	int m_flag = 0; //�f�o�b�O�p
	int m_count = 0; //�f�o�b�O�p	
	int m_selectNum = 0; //�I�����
	int m_intTime = 0; //�����ϊ�	
	float m_selectTime = 1.0f; //�I������
	//float m_fadeTime = 1.0f;
	//bool m_isWaitFadeout = false;
	//bool m_titleFlag = false; //�^�C�g���֖߂�p�t���O
	int m_1pSide = 0; //�v���C���[:�Z��
	int m_2pSide = 0; //�v���C���[2:�Z��
	int m_cpuSide = 0; //CPU:�Z��
	bool m_roadFlag = false; //���[�h�t���O
	bool m_2playerFlag = false; //2�l�ΐ�p�t���O
	bool m_resultBGMFlag = false; //���U���g�pBGM�Đ��t���O
	bool m_selectFlag = false; //�I���t���O
	bool m_selectFadeFlag = false; //�I��p�����t���O
	bool m_retryFlag = false; //�Đ�p�t���O

	Debug* m_debug = nullptr;
	Player* m_player = nullptr;
	BackGround* m_backGround = nullptr;
	Enemy* m_enemy = nullptr;
	Player2* m_player2 = nullptr;
	Frame* m_frame = nullptr;
	HP* m_hp = nullptr;
	GameTimer* m_gametimer = nullptr;	
	Round* m_round = nullptr;
	Result* m_result = nullptr;
	Fade* m_fade = nullptr;
	GameCamera* m_gameCamera = nullptr;
	SoundSource* m_battlebgm = nullptr;
	SoundSource* m_resultbgm = nullptr;
};

