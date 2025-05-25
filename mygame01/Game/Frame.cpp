#include "stdafx.h"
#include "Frame.h"
#include "Round.h"
#include "Game.h"

Frame::Frame()
{

}

Frame::~Frame()
{

}

bool Frame::Start()
{
	m_game = FindGO<Game>("game");
	m_round = FindGO<Round>("round");
	return true;
}

void Frame::Update()
{
	//���E���h���I����Ă��Ȃ��Ƃ�
	if (m_round->IsNoFighting() != true)
	{
		FrameState();
	}
}

void Frame::FrameState()
{
	for (int i = 0; i < 9; i++)
	{
		//�X�e�B�b�N�̓��삵�Ă��Ȃ��Ƃ���͒l��ς��Ȃ��悤�ɂ���
		if (i != m_playerMoveState)
		{
			m_playerframe[i] = 0.0f;
		}
	}

	switch (m_playerMoveState)
	{
	case enDirectionState_Idle: //�ҋ@
		m_playerframe[enDirectionState_Idle] += g_gameTime->GetFrameDeltaTime();
		//m_frame[0] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Right: //�E
		m_playerframe[enDirectionState_Right] += g_gameTime->GetFrameDeltaTime();
		//m_frame[1] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Right_Up: //�΂߉E��
		m_playerframe[enDirectionState_Right_Up] += g_gameTime->GetFrameDeltaTime();
		//m_frame[2] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Right_Down: //�΂߉E��
		m_playerframe[enDirectionState_Right_Down] += g_gameTime->GetFrameDeltaTime();
		//m_frame[3] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Left: //��
		m_playerframe[enDirectionState_Left] += g_gameTime->GetFrameDeltaTime();
		//m_frame[4] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Left_Up: //�΂ߍ���
		m_playerframe[enDirectionState_Left_Up] += g_gameTime->GetFrameDeltaTime();
		//m_frame[5] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Left_Down: //�΂ߍ���
		m_playerframe[enDirectionState_Left_Down] += g_gameTime->GetFrameDeltaTime();
		//m_frame[6] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Up: //��
		m_playerframe[enDirectionState_Up] += g_gameTime->GetFrameDeltaTime();
		//m_frame[7] += g_gameTime->GetFrameDeltaTime();
		break;

	case enDirectionState_Down: //��
		m_playerframe[enDirectionState_Down] += g_gameTime->GetFrameDeltaTime();
		//m_frame[8] += g_gameTime->GetFrameDeltaTime();
		break;

	default:
		break;
	}

	// 1P VS 2P �̂Ƃ�
	if (m_game->m_2playerFlag == true)
	{
		for (int i = 0; i < 9; i++)
		{
			//�X�e�B�b�N�̓��삵�Ă��Ȃ��Ƃ���͒l��ς��Ȃ��悤�ɂ���
			if (i != m_player2MoveState)
			{
				m_player2frame[i] = 0.0f;
			}
		}

		switch (m_player2MoveState)
		{
		case enDirectionState_Idle: //�ҋ@
			m_player2frame[enDirectionState_Idle] += g_gameTime->GetFrameDeltaTime();
			//m_frame[0] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Right: //�E
			m_player2frame[enDirectionState_Right] += g_gameTime->GetFrameDeltaTime();
			//m_frame[1] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Right_Up: //�΂߉E��
			m_player2frame[enDirectionState_Right_Up] += g_gameTime->GetFrameDeltaTime();
			//m_frame[2] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Right_Down: //�΂߉E��
			m_player2frame[enDirectionState_Right_Down] += g_gameTime->GetFrameDeltaTime();
			//m_frame[3] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Left: //��
			m_player2frame[enDirectionState_Left] += g_gameTime->GetFrameDeltaTime();
			//m_frame[4] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Left_Up: //�΂ߍ���
			m_player2frame[enDirectionState_Left_Up] += g_gameTime->GetFrameDeltaTime();
			//m_frame[5] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Left_Down: //�΂ߍ���
			m_player2frame[enDirectionState_Left_Down] += g_gameTime->GetFrameDeltaTime();
			//m_frame[6] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Up: //��
			m_player2frame[enDirectionState_Up] += g_gameTime->GetFrameDeltaTime();
			//m_frame[7] += g_gameTime->GetFrameDeltaTime();
			break;

		case enDirectionState_Down: //��
			m_player2frame[enDirectionState_Down] += g_gameTime->GetFrameDeltaTime();
			//m_frame[8] += g_gameTime->GetFrameDeltaTime();
			break;

		default:
			break;
		}
	}
}
