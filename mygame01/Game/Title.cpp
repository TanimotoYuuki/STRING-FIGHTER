#include "stdafx.h"
#include "Title.h"
#include "Fade.h"
#include "Game.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Title::Title()
{

}

Title::~Title()
{
	DeleteGO(m_fade);
}

bool Title::Start()
{
	//�^�C�g���̔w�i
	m_titleBackGround.Init("Assets/screen/titlebackground.dds", 1920.0f, 1080.0f);
	m_titleBackGround.SetPosition({ 0.0f,0.0f,0.0f });
	m_titleBackGround.SetScale({ 1.0f,1.0f,1.0f });
	m_titleBackGround.Update();

	//��
	m_fist.Init("Assets/screen/fist.dds", 1600.0f, 1200.0f);
	m_fist.SetPosition({ 0.0f,0.0f,0.0f });
	m_fist.SetScale({ 0.0f,0.0f,0.0f });
	m_fist.Update();

	//�^�C�g����
	m_titleName.Init("Assets/screen/titlename1.dds", 910.0f, 128.0f);
	m_titleName.SetPosition({ -1700.0f,350.0f,0.0f });
	m_titleName.SetScale({ 1.5f,1.5f,1.0f });
	m_titleName.Update();

	//�v���X�{�^��
	m_pressButton.Init("Assets/screen/pressbutton1.dds", 910.0f, 128.0f);
	m_pressButton.SetPosition({ 0.0f,-350.0f,0.0f });
	m_pressButton.SetScale({ 1.5f,1.5f,1.0f });
	m_pressButton.Update();

	//1P VS CPU
	m_vs[0].Init("Assets/screen/1pvscpu1.dds", 486.0f, 128.0f);
	m_vs[0].SetPosition({0.0f,50.0f,0.0f});
	m_vs[0].SetScale({1.5f,1.5f,1.0f});
	m_vs[0].Update();

	//1P VS 2P
	m_vs[1].Init("Assets/screen/1pvs2p1.dds", 420.0f, 128.0f);
	m_vs[1].SetPosition({ 0.0f,-250.0f,0.0f });
	m_vs[1].SetScale({ 1.5f,1.5f,1.0f });
	m_vs[1].Update();

	//���[�h
	m_mode.Init("Assets/screen/mode.dds", 250.0f, 128.0f);
	m_mode.SetPosition({ 0.0f,350.0f,0.0f });
	m_mode.SetScale({ 1.5f,1.5f,1.0f });
	m_mode.Update();

	//1P
	m_1p.Init("Assets/screen/1p.dds", 256.0f, 128.0f);
	m_1p.SetPosition({ 0.0f,-125.0f,0.0f });
	m_1p.SetScale({ 1.0f,1.0f,1.0f });
	m_1p.Update();
	m_1pSideSelectInitPosition = m_1p.GetPosition();

	//2P
	m_2p.Init("Assets/screen/2p.dds", 256.0f, 128.0f);
	m_2p.SetPosition({ 0.0f,-325.0f,0.0f });
	m_2p.SetScale({ 1.0f,1.0f,1.0f });
	m_2p.Update();
	m_2pSideSelectInitPosition = m_2p.GetPosition();

	//CPU:������
	m_cpu[enSideState_Left].Init("Assets/screen/cpu.dds", 256.0f, 128.0f);
	m_cpu[enSideState_Left].SetPosition({425.0f,-225.0f,0.0f});
	m_cpu[enSideState_Left].SetScale({1.0f,1.0f,1.0f});
	m_cpu[enSideState_Left].Update();	

	//CPU:�E����
	m_cpu[enSideState_Right].Init("Assets/screen/cpu.dds", 256.0f, 128.0f);
	m_cpu[enSideState_Right].SetPosition({-475.0f,-225.0f,0.0f});
	m_cpu[enSideState_Right].SetScale({1.0f,1.0f,1.0f});
	m_cpu[enSideState_Right].Update();

	//�v���C���̃v���C���[�̏����ʒu:����
	m_playerSide[enSideState_Left].Init("Assets/screen/left.dds", 220.0f, 128.0f);
	m_playerSide[enSideState_Left].SetPosition({ -450.0f,100.0f,0.0f });
	m_playerSide[enSideState_Left].SetScale({ 1.5f,1.5f,1.0f });
	m_playerSide[enSideState_Left].Update();

	//�v���C���̃v���C���[�̏����ʒu:�E��
	m_playerSide[enSideState_Right].Init("Assets/screen/right.dds", 284.0f, 128.0f);
	m_playerSide[enSideState_Right].SetPosition({ 450.0f,100.0f,0.0f });
	m_playerSide[enSideState_Right].SetScale({ 1.5f,1.5f,1.0f });
	m_playerSide[enSideState_Right].Update();

	//�Z���̑I���𑣂��e�L�X�g
	m_sideSelectText.Init("Assets/screen/sideselecttext.dds", 981.0f, 128.0f);
	m_sideSelectText.SetPosition({ 0.0f,350.0f,0.0f });
	m_sideSelectText.SetScale({ 1.5f,1.5f,1.0f });
	m_sideSelectText.Update();

	//�I��
	m_select[enSelectState_Up].Init("Assets/screen/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Up].SetPosition({-500.0f,75.0f,0.0f});
	m_select[enSelectState_Up].SetScale({1.0f,1.0f,1.0f});
	m_select[enSelectState_Up].Update();

	m_select[enSelectState_Down].Init("Assets/screen/select.dds", 210.0f, 128.0f);
	m_select[enSelectState_Down].SetPosition({-500.0f,-225.0f,0.0f});
	m_select[enSelectState_Down].SetScale({1.0f,1.0f,1.0f});
	m_select[enSelectState_Down].Update();

	//A�{�^��
	m_button[enButtonState_A].Init("Assets/UI/button/controller/A.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_A].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_A].SetPosition({ 500.0f,-475.0f,0.0f });
	m_button[enButtonState_A].Update();

	//B�{�^��
	m_button[enButtonState_B].Init("Assets/UI/button/controller/B.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_B].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_B].SetPosition({ 700.0f,-475.0f,0.0f });
	m_button[enButtonState_B].Update();

	//X�{�^��
	m_button[enButtonState_X].Init("Assets/UI/button/controller/X.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_X].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_X].Update();

	//Y�{�^��
	m_button[enButtonState_Y].Init("Assets/UI/button/controller/Y.dds", 1024.0f, 1024.0f);
	m_button[enButtonState_Y].SetScale({ 0.1f,0.1f,0.1f });
	m_button[enButtonState_Y].Update();

	//����
	m_text[0].SetText(L"����");
	m_text[0].SetPosition(Vector3(525.0f, -455.0f, 0.0f));
	m_text[0].SetScale(1.0f);
	m_text[0].SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	//�߂�
	m_text[1].SetText(L"�߂�");
	m_text[1].SetPosition(Vector3(725.0f, -455.0f, 0.0f));
	m_text[1].SetScale(1.0f);
	m_text[1].SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	//BGM
	g_soundEngine->ResistWaveFileBank(0, "Assets/BGM/title_bgm.wav");
	//���ʉ�
	g_soundEngine->ResistWaveFileBank(1, "Assets/SE/title_back.wav");
	g_soundEngine->ResistWaveFileBank(2, "Assets/SE/title_button1.wav");
	g_soundEngine->ResistWaveFileBank(3, "Assets/SE/title_button2.wav");
	g_soundEngine->ResistWaveFileBank(4, "Assets/SE/title_select.wav");

	//BGM
	m_bgm = NewGO<SoundSource>(0);
	m_bgm->Init(0);
	m_bgm->Play(true);
	m_bgm->SetVolume(0.3f);

	//�C���X�^���X
	NewGO<Fade>(0, "fade");
	m_fade = FindGO<Fade>("fade");

	return true;
}

void Title::Update()
{
	//�ȉ��̏����ɂȂ��Ă����Ƃ��C�[�W���O����������
	if (m_moveFlag != true && //���[�h�E�X�^�[�g����
		m_sideMoveFlag != true //�Z������
		)
	{
		//���̃C�[�W���O�ݒ肪�I����Ă��Ȃ�������
		if (m_fistSetEasingFlag != true)
		{
			FistSetEasing(); //���̃C�[�W���O�ݒ�
		}
		//���̃C�[�W���O�ݒ肪�I�������
		else if (m_fistSetEasingFlag == true)
		{
			FistEasing(); //���̃C�[�W���O
		}

		//�^�C�g���̃C�[�W���O�ݒ肪�I�������
		if (m_titleNameSetEasingFlag == true)
		{
			TitleNameEasing(); //�^�C�g�����̃C�[�W���O
		}
	}
	//�S�ẴC�[�W���O���I�������X�^�[�g�{�^����������悤�ɂȂ�
	else if (m_moveFlag == true)
	{
		Move();
	}
	//���[�h���I�����ł�����Z���I�����ł���悤�ɂȂ�
	else if (m_sideMoveFlag == true)
	{
		PlayerSide();
	}

	//�v���X�{�^���̏�Z�J���[
	m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));

	//�X�V
	m_pressButton.Update();
}

//���̃C�[�W���O�ݒ�
void Title::FistSetEasing()
{
	m_fistScaleA = m_fist.GetScale();
	m_fistScaleB = { 1.0f,1.0f,1.0f };
	m_fistT = 0.0f;

	m_fistSetEasingFlag = true;
}

//���̃C�[�W���O
void Title::FistEasing()
{
	m_fistT += g_gameTime->GetFrameDeltaTime();

	//��(�C�[�W���O����)��1.0�b�ɂȂ�����
	if (m_fistT > 1.0f)
	{
		m_fistT = 1.0f;
		//�^�C�g���̃C�[�W���O�ݒ肪�I����Ă��Ȃ�������
		if (m_titleNameSetEasingFlag != true)
		{
			//�^�C�g�����̃C�[�W���O�ݒ�
			TitleNameSetEasing();
		}
	}

	m_fistScale.Lerp(m_fistT, m_fistScaleA, m_fistScaleB);
	m_fist.SetScale(m_fistScale);
	m_fist.Update();
}

//�^�C�g�����̃C�[�W���O�ݒ�
void Title::TitleNameSetEasing()
{
	m_titleNamePositionA = m_titleName.GetPosition();
	m_titleNamePositionB = { 0.0f,350.0f,0.0f };
	m_titleNameT = 0.0f;

	m_titleNameSetEasingFlag = true;
}

//�^�C�g�����̃C�[�W���O
void Title::TitleNameEasing()
{
	m_titleNameT += g_gameTime->GetFrameDeltaTime();

	//�^�C�g����(�C�[�W���O����)��1.0�b�ɂȂ�����
	if (m_titleNameT > 1.0f)
	{
		m_titleNameT = 1.0f;
		m_moveFlag = true;
	}

	m_titleNamePosition.Lerp(m_titleNameT, m_titleNamePositionA, m_titleNamePositionB);
	m_titleName.SetPosition(m_titleNamePosition);
	m_titleName.Update();
}

//1P:�Z���I���̈ړ��C�[�W���O�ݒ�
void Title::Player1SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition)
{
	m_1psideSelectPositionA = target.GetPosition();
	switch (mode)
	{
	case enSideSelectState_Center: //����
		m_1psideSelectPositionB = initPosition;
		break;
	case enSideSelectState_Left: //����
		m_1psideSelectPositionB = { -475.0f,-225.0f,0.0f };
		break;
	case enSideSelectState_Right: //�E��
		m_1psideSelectPositionB = { 425.0f,-225.0f,0.0f };
		break;
	default:
		break;
	}
	m_1psideSelectT = 0.0f;

	m_1psideSelectSetEasingFlag = true;
}

//2P:�Z���I���̈ړ��C�[�W���O�ݒ�
void Title::Player2SideMoveSetEasing(int mode, SpriteRender& target, Vector3 initPosition)
{
	m_2psideSelectPositionA = target.GetPosition();
	switch (mode)
	{
	case enSideSelectState_Center: //����
		m_2psideSelectPositionB = initPosition;
		break;
	case enSideSelectState_Left: //����
		m_2psideSelectPositionB = { -475.0f,-225.0f,0.0f };
		break;
	case enSideSelectState_Right: //�E��
		m_2psideSelectPositionB = { 425.0f,-225.0f,0.0f };
		break;
	default:
		break;
	}
	m_2psideSelectT = 0.0f;

	m_2psideSelectSetEasingFlag = true;
}

//1P:�Z���I���̈ړ��C�[�W���O
void Title::Player1SideMoveEasing(SpriteRender& target)
{
	m_1psideSelectT += 4.5f * g_gameTime->GetFrameDeltaTime();

	//�Z���I������(�C�[�W���O����)��1.0�b�ɂȂ�����
	if (m_1psideSelectT > 1.0f)
	{
		m_1psideSelectT = 1.0f;
		m_onePlayerSideMoveSelectFlag = false;
		m_twoPlayerSideMoveSelectFlag[0] = false;
		m_1psideSelectSetEasingFlag = false;
	}

	m_1psideSelectPosition.Lerp(m_1psideSelectT, m_1psideSelectPositionA, m_1psideSelectPositionB);
	target.SetPosition(m_1psideSelectPosition);
	target.Update();
}

//2P:�Z���I���̈ړ��C�[�W���O
void Title::Player2SideMoveEasing(SpriteRender& target)
{
	m_2psideSelectT += 4.5f * g_gameTime->GetFrameDeltaTime();

	//�Z���I������(�C�[�W���O����)��1.0�b�ɂȂ�����
	if (m_2psideSelectT > 1.0f)
	{
		m_2psideSelectT = 1.0f;
		m_twoPlayerSideMoveSelectFlag[1] = false;
		m_2psideSelectSetEasingFlag = false;
	}

	m_2psideSelectPosition.Lerp(m_2psideSelectT, m_2psideSelectPositionA, m_2psideSelectPositionB);
	target.SetPosition(m_2psideSelectPosition);
	target.Update();
}

//�I���E�ړ�
void Title::Move()
{
	//�X�^�[�g�p
	//�I��p�̃t�F�[�h���I��p�̃t�F�[�h�����ɖ߂��t���O��true�ɂȂ��Ă��Ȃ��Ƃ�
	if (m_halfFadeFlag != true && m_brightenFlag != true)
	{
		//A�{�^��������Ă��Ȃ��Ƃ�
		if (m_flashingFlag != true)
		{
			//A�{�^��
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				m_alpha = 1.0f; //�s�����ɂ���
				m_flashingFlag = true; //�_�ł���
				//���ʉ�
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(2);
				se->Play(false);
				se->SetVolume(0.6f);
				//m_halfFadeFlag = true;
			}
		}

		//A�{�^��������Ă�����
		if (m_flashingFlag == true)
		{
			m_pressButtonTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
			m_intTime = m_pressButtonTime * 10;

			//�v���X�{�^�����Ԃ�0.0�b�ɂȂ�����
			if (m_pressButtonTime <= 0.0f)
			{
				m_pressButtonfadeFlag = true; //�����ɂ���

				//���ƃ^�C�g�����𓧖��ɂ���
				ObjectFade();
			}
			//0�b�ɂȂ��Ă��Ȃ�������
			else
			{
				if (m_intTime % 2 == 0)
				{
					m_pressButtonfadeFlag = true; //�����ɂ���
				}
				else
				{
					m_pressButtonfadeFlag = false; //�����ɂ��Ȃ�
				}
			}
		}
		else
		{
			//Press A Button��UI�𓧖��ɂ����茳�ɖ߂����肷��
			m_alpha += 1.2f * g_gameTime->GetFrameDeltaTime();
		}
	}

	//�I��p
	//Press A Button��UI�̓_�ł��I�������
	if (m_halfFadeFlag == true)
	{
		////�^�C�g���̔w�i�𔼓����ɂ���
		//m_halfFade -= 0.5f * g_gameTime->GetFrameDeltaTime();

		////�������ɂȂ�����
		//if (m_halfFade <= 0.5f)
		//{
		//	m_halfFade = 0.5f; //�������̂܂܂ɂ���
		//	m_halfFadeFinishFlag = true; //�������ɂȂ���

		//	//B�{�^��������Ă��Ȃ��Ƃ�
		//	if (m_brightenFlag != true)
		//	{
		//		//A�{�^��������Ă��Ȃ��Ƃ�
		//		if (m_selectFlag != true)
		//		{
		//			//��{�^��
		//			if (g_pad[0]->IsTrigger(enButtonUp))
		//			{
		//				//�I����Ԃ���̂Ƃ�
		//				if (m_selectNum == enSelectState_Up)
		//				{
		//					m_selectNum = enSelectState_Down;
		//				}
		//				else
		//				{
		//					m_selectNum = enSelectState_Up;
		//				}
		//				//���ʉ�
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(4);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//			}
		//			//���{�^��
		//			else if (g_pad[0]->IsTrigger(enButtonDown))
		//			{
		//				//�I����Ԃ����̂Ƃ�
		//				if (m_selectNum == enSelectState_Down)
		//				{
		//					m_selectNum = enSelectState_Up;
		//				}
		//				else
		//				{
		//					m_selectNum = enSelectState_Down;
		//				}
		//				//���ʉ�
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(4);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//			}

		//			//A�{�^��
		//			if (g_pad[0]->IsTrigger(enButtonA))
		//			{
		//				m_selectFlag = true;
		//				//���ʉ�
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(2);
		//				//se->Init(3);
		//				se->Play(false);
		//				se->SetVolume(0.6f);
		//				////BGM�𗬂��Ȃ�
		//				//DeleteGO(m_bgm);
		//			}
		//			//B�{�^��
		//			if (g_pad[0]->IsTrigger(enButtonB))
		//			{
		//				m_halfFadeFlag = false; //�������ł͂Ȃ�
		//				m_brightenFlag = true; //�s�����ɂ���
		//				//���ʉ�
		//				SoundSource* se = NewGO<SoundSource>(0);
		//				se->Init(1);
		//				se->Play(false);
		//				se->SetVolume(1.5f);
		//			}
		//		}

		//		//A�{�^��������Ă�����
		//		if (m_selectFlag == true)
		//		{
		//			m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
		//			m_intTime = m_selectTime * 10;

		//			//�I�����Ԃ�0.0�b�ɂȂ�����
		//			if (m_selectTime <= 0.0f)
		//			{
		//				m_moveFlag = false; //���[�h���삪�ł��Ȃ��Ȃ�
		//				m_sideMoveFlag = true; //�Z�����삪�ł���悤�ɂȂ�
		//				m_selectFlag = false; //���[�h��ʂɖ߂����烂�[�h���삪�ł���悤�ɂ���
		//				m_selectFadeFlag = false; //�s�����ɂ���
		//				m_selectTime = 1.0f; //�I������

		//				////���[�h���Ă��Ȃ��Ƃ�
		//				//if (m_roadFlag != true)
		//				//{
		//				//	m_fade->StartFadeOut();
		//				//	m_roadFlag = true;
		//				//}
		//				////�t�F�[�h�A�E�g���I�������
		//				//if (!m_fade->IsFade())
		//				//{
		//				//	NewGO<Game>(0, "game");
		//				//	m_game = FindGO<Game>("game");
		//				//	//�I����Ԃ����̂Ƃ�
		//				//	if (m_selectNum == enSelectState_Down)
		//				//	{
		//				//		m_1pVS2pSelectFlag = true;
		//				//		m_game->m_2playerFlag = m_1pVS2pSelectFlag;
		//				//	}
		//				//	DeleteGO(this);
		//				//}
		//			}
		//			//0�b�ɂȂ��Ă��Ȃ�������
		//			else
		//			{
		//				if (m_intTime % 2 == 0)
		//				{
		//					m_selectFadeFlag = true; //�����ɂ���
		//				}
		//				else
		//				{
		//					m_selectFadeFlag = false; //�����ɂ��Ȃ�
		//				}
		//			}
		//		}
		//	}
		//}
		// 

		//m_halfFade = 0.5f; //�������̂܂܂ɂ���
		m_halfFadeFinishFlag = true; //�������ɂȂ���

		//B�{�^��������Ă��Ȃ��Ƃ�
		if (m_brightenFlag != true)
		{
			//A�{�^��������Ă��Ȃ��Ƃ�
			if (m_selectFlag != true)
			{
				//��{�^��
				if (g_pad[0]->IsTrigger(enButtonUp))
				{
					//�I����Ԃ���̂Ƃ�
					if (m_selectNum == enSelectState_Up)
					{
						m_selectNum = enSelectState_Down;
					}
					else
					{
						m_selectNum = enSelectState_Up;
					}
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				//���{�^��
				else if (g_pad[0]->IsTrigger(enButtonDown))
				{
					//�I����Ԃ����̂Ƃ�
					if (m_selectNum == enSelectState_Down)
					{
						m_selectNum = enSelectState_Up;
					}
					else
					{
						m_selectNum = enSelectState_Down;
					}
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}

				//A�{�^��
				if (g_pad[0]->IsTrigger(enButtonA))
				{
					m_selectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(2);
					//se->Init(3);
					se->Play(false);
					se->SetVolume(0.6f);
					////BGM�𗬂��Ȃ�
					//DeleteGO(m_bgm);
				}
				//B�{�^��
				if (g_pad[0]->IsTrigger(enButtonB))
				{
					m_halfFadeFlag = false; //�������ł͂Ȃ�
					m_brightenFlag = true; //�s�����ɂ���
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(1);
					se->Play(false);
					se->SetVolume(1.5f);
				}
			}

			//A�{�^��������Ă�����
			if (m_selectFlag == true)
			{
				m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
				m_intTime = m_selectTime * 10;

				//�I�����Ԃ�0.0�b�ɂȂ�����
				if (m_selectTime <= 0.0f)
				{
					m_moveFlag = false; //���[�h���삪�ł��Ȃ��Ȃ�
					m_sideMoveFlag = true; //�Z�����삪�ł���悤�ɂȂ�
					m_selectFlag = false; //���[�h��ʂɖ߂����烂�[�h���삪�ł���悤�ɂ���
					m_selectFadeFlag = false; //�s�����ɂ���
					m_selectTime = 1.0f; //�I������

					////���[�h���Ă��Ȃ��Ƃ�
					//if (m_roadFlag != true)
					//{
					//	m_fade->StartFadeOut();
					//	m_roadFlag = true;
					//}
					////�t�F�[�h�A�E�g���I�������
					//if (!m_fade->IsFade())
					//{
					//	NewGO<Game>(0, "game");
					//	m_game = FindGO<Game>("game");
					//	//�I����Ԃ����̂Ƃ�
					//	if (m_selectNum == enSelectState_Down)
					//	{
					//		m_1pVS2pSelectFlag = true;
					//		m_game->m_2playerFlag = m_1pVS2pSelectFlag;
					//	}
					//	DeleteGO(this);
					//}
				}
				//0�b�ɂȂ��Ă��Ȃ�������
				else
				{
					if (m_intTime % 2 == 0)
					{
						m_selectFadeFlag = true; //�����ɂ���
					}
					else
					{
						m_selectFadeFlag = false; //�����ɂ��Ȃ�
					}
				}
			}
		}
		//�^�C�g���̔w�i�̏�Z�J���[
		//m_titleBackGround.SetMulColor({ 1.0f, 1.0f, 1.0f, m_halfFade });
	}
	//B�{�^����������Ă�����
	else if (m_brightenFlag == true)
	{
		////�^�C�g���̔w�i��s�����ɂ���
		//m_halfFade += 0.5f * g_gameTime->GetFrameDeltaTime();

		////�s�����ɂȂ�����
		//if (m_halfFade >= 1.0f)
		//{
		//	m_halfFade = 1.0f; //�l�����Z�b�g����

		//	//��������s�����ɂ���
		//	m_allfade = 1.0f;
		//	m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
		//	m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });

		//	//�C�[�W���O�p�ɍ��W�����̈ʒu�ɖ߂�
		//	m_titleName.SetPosition({ -1700.0f, 350.0f, 0.0f });
		//	m_fist.SetScale({ 0.0f,0.0f,0.0f });

		//	//�X�V
		//	m_titleName.Update();
		//	m_fist.Update();

		//	//�X�^�[�g�{�^��
		//	m_alpha = 0.0f;
		//	m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));
		//	m_pressButton.Update();
		//	m_pressButtonfadeFlag = false; //�����ɂ��Ȃ�

		//	m_fistSetEasingFlag = false; //���̃C�[�W���O�t���O
		//	m_titleNameSetEasingFlag = false; //�^�C�g�����̃C�[�W���O�t���O
		//	m_moveFlag = false; //�I���E�ړ��\�t���O

		//	m_halfFadeFinishFlag = false; //�����������t���O
		//	m_brightenFlag = false; //�s�����ɂ���t���O

		//	m_selectNum = enSelectState_Up;
		//}
		//�^�C�g���̔w�i�̏�Z�J���[
		//m_titleBackGround.SetMulColor({ 1.0f, 1.0f, 1.0f, m_halfFade });

		//m_halfFade = 1.0f; //�l�����Z�b�g����

		//��������s�����ɂ���
		m_allfade = 1.0f;
		m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
		m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });

		//�C�[�W���O�p�ɍ��W�����̈ʒu�ɖ߂�
		m_titleName.SetPosition({ -1700.0f, 350.0f, 0.0f });
		m_fist.SetScale({ 0.0f,0.0f,0.0f });

		//�X�V
		m_titleName.Update();
		m_fist.Update();

		//�X�^�[�g�{�^��
		m_alpha = 0.0f;
		m_pressButton.SetMulColor(Vector4(1.0f, 1.0f, 1.0f, fabsf(sinf(m_alpha))));
		m_pressButton.Update();
		m_pressButtonfadeFlag = false; //�����ɂ��Ȃ�

		m_fistSetEasingFlag = false; //���̃C�[�W���O�t���O
		m_titleNameSetEasingFlag = false; //�^�C�g�����̃C�[�W���O�t���O
		m_moveFlag = false; //�I���E�ړ��\�t���O

		m_halfFadeFinishFlag = false; //�����������t���O
		m_brightenFlag = false; //�s�����ɂ���t���O

		m_selectNum = enSelectState_Up;
	}
}

//�v���C���[�Z���I��
void Title::PlayerSide()
{
	//���[�h�I����ʂŉ���I��������
	switch (m_selectNum)
	{
	case enSelectState_Up: //1P VS CPU
		m_1pVScpuSelectFlag = true;
		OnePlayerSideMove();
		break;
	case enSelectState_Down: //1P VS 2P
		m_1pVS2pSelectFlag = true;
		TwoPlayerSideMove();
		break;
	default:
		break;
	}
}

//�v���C���[�Z���I���E�ړ�
void Title::OnePlayerSideMove()
{
	//�Z���I���ő��삵�Ă��Ȃ��Ƃ�
	if (m_onePlayerSideMoveSelectFlag != true)
	{
		//A�{�^��������Ă��Ȃ��Ƃ�
		if (m_selectFlag != true)
		{
			//�Z���I���ŉ���I�����Ă��邩
			switch (m_onePlayerSideSelectNum)
			{
			case enSideSelectState_Center: //����
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Left;
					m_onePlayerSideMoveSelectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				else if (g_pad[0]->IsTrigger(enButtonRight))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Right;
					m_onePlayerSideMoveSelectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			case enSideSelectState_Left: //����
				if (g_pad[0]->IsTrigger(enButtonRight))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Center;
					m_onePlayerSideMoveSelectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			case enSideSelectState_Right: //�E��
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					m_onePlayerSideSelectNum = enSideSelectState_Center;
					m_onePlayerSideMoveSelectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(4);
					se->Play(false);
					se->SetVolume(0.6f);
				}
				break;
			default:
				break;
			}

			//�I���������ȊO�̂Ƃ�
			if (m_onePlayerSideSelectNum != enSideSelectState_Center)
			{
				if (g_pad[0]->IsTrigger(enButtonA))
				{
					m_selectFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(3);
					se->Play(false);
					se->SetVolume(0.6f);
					//BGM�𗬂��Ȃ�
					DeleteGO(m_bgm);
				}
			}
			if (g_pad[0]->IsTrigger(enButtonB))
			{
				m_sideMoveFlag = false;
				m_moveFlag = true;
				m_1pVScpuSelectFlag = false;
				m_onePlayerSideSelectNum = enSideSelectState_Center;
				m_1p.SetPosition(m_1pSideSelectInitPosition);
				m_1p.Update();
				//���ʉ�
				SoundSource* se = NewGO<SoundSource>(0);
				se->Init(1);
				se->Play(false);
				se->SetVolume(1.5f);
			}
		}
		//A�{�^����������Ă�����
		else if (m_selectFlag == true)
		{
			m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
			if (m_selectTime <= 0.0f)
			{
				//���[�h���Ă��Ȃ��Ƃ�
				if (m_roadFlag != true)
				{
					m_fade->StartFadeOut();
					m_roadFlag = true;
				}
				//�t�F�[�h�A�E�g���I�������
				if (!m_fade->IsFade())
				{
					if (m_inGameFlag != true)
					{
						NewGO<Game>(0, "game");
						m_game = FindGO<Game>("game");
						m_inGameFlag = true;
					}
					//�ȉ��̑I���ɂȂ��Ă���Ƃ�
					if (m_onePlayerSideSelectNum == enSideSelectState_Left) //1P:����
					{
						m_game->m_1pSide = enSideSelectState_Left;
						m_game->m_cpuSide = enSideSelectState_Right;
					}
					else if (m_onePlayerSideSelectNum == enSideSelectState_Right) //1P:�E��
					{
						m_game->m_1pSide = enSideSelectState_Right;
						m_game->m_cpuSide = enSideSelectState_Left;
					}
					DeleteGO(this);
				}
			}
		}
	}
	//�Z���I���ő��삵���Ƃ�
	else if (m_onePlayerSideMoveSelectFlag == true)
	{
		//�I���̃C�[�W���O�ݒ肪�I����Ă��Ȃ��Ƃ�
		if (m_1psideSelectSetEasingFlag != true)
		{
			Player1SideMoveSetEasing(m_onePlayerSideSelectNum, m_1p, m_1pSideSelectInitPosition);
		}
		//�I���̃C�[�W���O�ݒ肪�I������Ƃ�
		else if (m_1psideSelectSetEasingFlag == true)
		{
			Player1SideMoveEasing(m_1p);
		}
	}
}

void Title::TwoPlayerSideMove()
{
	for (int i = 0; i < m_gamepad; i++)
	{
		//�Z���I���ő��삵�Ă��Ȃ��Ƃ�
		if (m_twoPlayerSideMoveSelectFlag[i] != true)
		{
			//A�{�^����������Ă��Ȃ��Ƃ�
			if (m_selectFlag != true)
			{
				//�Z���I���ŉ���I�����Ă��邩
				switch (m_twoPlayerSideSelectNum[i])
				{
				case enSideSelectState_Center: //����
					if (g_pad[i]->IsTrigger(enButtonLeft))
					{
						//�ȉ��̏����ɂȂ��Ă����Ƃ��ړ����Ȃ�
						if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Left && //����
							m_twoPlayerSideSelectNum[1] != enSideSelectState_Left //����
							)
						{
							m_twoPlayerSideSelectNum[i] = enSideSelectState_Left;
							m_twoPlayerSideMoveSelectFlag[i] = true;
							//���ʉ�
							SoundSource* se = NewGO<SoundSource>(0);
							se->Init(4);
							se->Play(false);
							se->SetVolume(0.6f);
						}
					}
					else if (g_pad[i]->IsTrigger(enButtonRight))
					{
						//�ȉ��̏����ɂȂ��Ă����Ƃ��ړ����Ȃ�
						if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Right && //�E��
							m_twoPlayerSideSelectNum[1] != enSideSelectState_Right //�E��
							)
						{
							m_twoPlayerSideSelectNum[i] = enSideSelectState_Right;
							m_twoPlayerSideMoveSelectFlag[i] = true;
							//���ʉ�
							SoundSource* se = NewGO<SoundSource>(0);
							se->Init(4);
							se->Play(false);
							se->SetVolume(0.6f);
						}
					}
					break;
				case enSideSelectState_Left: //����
					if (g_pad[i]->IsTrigger(enButtonRight))
					{
						m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
						m_twoPlayerSideMoveSelectFlag[i] = true;
						//���ʉ�
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(4);
						se->Play(false);
						se->SetVolume(0.6f);
					}
					break;
				case enSideSelectState_Right: //�E��
					if (g_pad[i]->IsTrigger(enButtonLeft))
					{
						m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
						m_twoPlayerSideMoveSelectFlag[i] = true;
						//���ʉ�
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(4);
						se->Play(false);
						se->SetVolume(0.6f);
					}
					break;
				default:
					break;
				}

				//�ȉ��̏����ɂȂ��Ă����Ƃ�A�{�^�������Ă��������Ȃ�
				if (m_twoPlayerSideSelectNum[0] != enSideSelectState_Center && //����
					m_twoPlayerSideSelectNum[1] != enSideSelectState_Center //����
					)
				{
					if (g_pad[i]->IsTrigger(enButtonA))
					{
						m_selectFlag = true;
						//���ʉ�
						SoundSource* se = NewGO<SoundSource>(0);
						se->Init(3);
						se->Play(false);
						se->SetVolume(0.6f);
						//BGM�𗬂��Ȃ�
						DeleteGO(m_bgm);
					}
				}
				if (g_pad[i]->IsTrigger(enButtonB))
				{
					m_sideMoveFlag = false;
					m_moveFlag = true;
					m_1pVS2pSelectFlag = false;
					m_twoPlayerSideSelectNum[i] = enSideSelectState_Center;
					m_1p.SetPosition(m_1pSideSelectInitPosition);
					m_1p.Update();
					m_2p.SetPosition(m_2pSideSelectInitPosition);
					m_2p.Update();
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(1);
					se->Play(false);
					se->SetVolume(1.5f);
				}
			}
			//A�{�^����������Ă�����
			else if (m_selectFlag == true)
			{
				m_selectTime -= 0.5f * g_gameTime->GetFrameDeltaTime();
				if (m_selectTime <= 0.0f)
				{
					//���[�h���Ă��Ȃ��Ƃ�
					if (m_roadFlag != true)
					{
						m_fade->StartFadeOut();
						m_roadFlag = true;
					}
					//�t�F�[�h�A�E�g���I�������
					if (!m_fade->IsFade())
					{
						if (m_inGameFlag != true)
						{
							NewGO<Game>(0, "game");
							m_game = FindGO<Game>("game");
							m_inGameFlag = true;
						}
						//�ȉ��̑I���ɂȂ��Ă���Ƃ�
						if (m_twoPlayerSideSelectNum[0] == enSideSelectState_Left && //1P:����
							m_twoPlayerSideSelectNum[1] == enSideSelectState_Right //2P:�E��
							)
						{
							m_game->m_2playerFlag = m_1pVS2pSelectFlag;
							m_game->m_1pSide = enSideSelectState_Left;
							m_game->m_2pSide = enSideSelectState_Right;
						}
						else if (m_twoPlayerSideSelectNum[0] == enSideSelectState_Right && //1P:�E��
								 m_twoPlayerSideSelectNum[1] == enSideSelectState_Left //2P:����
							    )
						{
							m_game->m_2playerFlag = m_1pVS2pSelectFlag;
							m_game->m_1pSide = enSideSelectState_Right;
							m_game->m_2pSide = enSideSelectState_Left;
						}
						DeleteGO(this);
					}
				}
			}
		}
		//�Z���I���ő��삵���Ƃ�
		else if (m_twoPlayerSideMoveSelectFlag[i] == true)
		{
			//�I���̃C�[�W���O�ݒ肪�I����Ă��Ȃ��Ƃ�
			if (m_1psideSelectSetEasingFlag != true)
			{
				Player1SideMoveSetEasing(m_twoPlayerSideSelectNum[0], m_1p, m_1pSideSelectInitPosition);
			}
			//�I���̃C�[�W���O�ݒ肪�I������Ƃ�
			else if (m_1psideSelectSetEasingFlag == true)
			{
				Player1SideMoveEasing(m_1p);
			}

			//�I���̃C�[�W���O�ݒ肪�I����Ă��Ȃ��Ƃ�
			if (m_2psideSelectSetEasingFlag != true)
			{
				Player2SideMoveSetEasing(m_twoPlayerSideSelectNum[1], m_2p, m_2pSideSelectInitPosition);
			}
			//�I���̃C�[�W���O�ݒ肪�I������Ƃ�
			else if (m_2psideSelectSetEasingFlag == true)
			{
				Player2SideMoveEasing(m_2p);
			}
		}
	}
}

//�t�F�[�h
void Title::ObjectFade()
{
	m_allfade -= g_gameTime->GetFrameDeltaTime();
	//�t�F�[�h(����)��0.0�b�ɂȂ�����
	if (m_allfade < 0.0f)
	{
		m_allfade = 0.0f; //����
		m_pressButtonTime = 1.0f;
		m_flashingFlag = false; //�_�ł��Ȃ�
		m_halfFadeFlag = true; //�������ɂ���
	}
	m_titleName.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
	m_fist.SetMulColor({ 1.0f, 1.0f, 1.0f, m_allfade });
}

void Title::Render(RenderContext& rc)
{
	//�`��
	m_titleBackGround.Draw(rc);
	m_fist.Draw(rc);
	m_titleName.Draw(rc);

	//m_1p.Draw(rc);
	//m_2p.Draw(rc);
	//m_cpu.Draw(rc);
	//m_playerSide[enSideState_Left].Draw(rc);
	//m_playerSide[enSideState_Right].Draw(rc);
	//m_sideSelectText.Draw(rc);

	//A�{�^����������Ă��Ȃ�������
	if (m_pressButtonfadeFlag != true)
	{
		//�v���X�{�^���`��
		m_pressButton.Draw(rc);
	}

	//�^�C�g���̔w�i���������ɂȂ�����
	if (m_halfFadeFinishFlag == true)
	{
		if (m_brightenFlag != true && m_sideMoveFlag != true)
		{
			if (m_selectFadeFlag != true)
			{
				//�I��`��
				m_select[m_selectNum].Draw(rc);
			}
			for (int i = 0; i < 2; i++)
			{
				//�Z�Z VS �Z�Z
				m_vs[i].Draw(rc);
			}
			//���[�h
			m_mode.Draw(rc);
		}
		else if (m_sideMoveFlag == true)
		{
			for (int i = 0; i < enSideState_Num; i++)
			{
				//�Z��
				m_playerSide[i].Draw(rc);
			}
			//�I��
			if (m_1pVS2pSelectFlag == true)
			{
				m_2p.Draw(rc);
			}
			else if (m_1pVScpuSelectFlag == true)
			{
				for (int i = 0; i < enSideState_Num; i++)
				{
					m_cpu[i].Draw(rc);
				}
			}
			m_1p.Draw(rc);
			//�I���𑣂��e�L�X�g
			m_sideSelectText.Draw(rc);
		}
		if (m_brightenFlag != true)
		{
			//�{�^��
			m_button[enButtonState_A].Draw(rc);
			m_button[enButtonState_B].Draw(rc);
			//�e�L�X�g
			m_text[0].Draw(rc);
			m_text[1].Draw(rc);
		}
	}
}