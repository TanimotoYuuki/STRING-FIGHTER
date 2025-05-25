#include "stdafx.h"
#include "GameCamera.h"
#include "Game.h"
#include "Player.h"
#include "Player2.h"
#include "Enemy.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	//1P vs 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	//1P vs 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}

	//�L�����N�^�[�̏������W��ݒ肷��
	m_playerDefaultPosition = m_player->m_position;
	//1P vs 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_enemyDefaultPosition = m_enemy->m_position;
	}
	//1P vs 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_player2DefaultPosition = m_player2->m_position;
	}
	//��p�̕ύX
	g_camera3D->SetViewAngle(0.85f);
	return true;
}

void GameCamera::Update()
{
	//�L�����N�^�[�̍��W��ݒ肷��
	m_playerPosition = m_player->m_position;
	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_enemyPosition = m_enemy->m_position;
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_player2Position = m_player2->m_position;
	}

	//��ʒ[
	//m_movePos��X���̓v���C���[�ƓG�܂��̓v���C���[2�̏����ʒu�̒l���Βl�ɂ��Ă��瑫���āA
	//�v���C���[�ƓG�܂��̓v���C���[2�̌��݈ʒu�������āA
	//�v���C���[�̈ʒu���E���ɂ����� �����ʒu+���݈ʒu
	//�v���C���[�̈ʒu�������ɂ����� �����ʒu-���݈ʒu
	//m_movePos�̒l��-100�ȉ��ɂȂ������ʒ[�ɍs���Ă���
	//��ʒ[�܂ł�������J�����ړ����Ȃ�
	//1P vs 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�E
		if (m_playerPosition.x < m_enemyPosition.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_enemyDefaultPosition.x)) + (m_playerPosition.x - m_enemyPosition.x);
		}
		//��
		else if (m_playerPosition.x > m_enemyPosition.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_enemyDefaultPosition.x)) - (m_playerPosition.x - m_enemyPosition.x);
		}
	}
	//1P vs 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�E
		if (m_playerPosition.x < m_player2Position.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_player2DefaultPosition.x)) + (m_playerPosition.x - m_player2Position.x);
		}
		//��
		else if (m_playerPosition.x > m_player2Position.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_player2DefaultPosition.x)) - (m_playerPosition.x - m_player2Position.x);
		}
	}
	//if (m_targetLeft.x >= -500.0f)
	//{
	//	//��ʍ��[
	//	//m_targetLeft.x = (m_enemyPosition.x + m_playerDefaultPosition.x) - 200.0f;
	//}

	//if (m_targetRight.x <= 500.0f)
	//{
	//	//��ʉE�[

	//	//m_targetRight.x = (m_playerPosition.x + m_enemyDefaultPosition.x) + 200.0;
	//}

	//�����_
	//m_target��X����Y���̓v���C���[�̌��݈ʒu�ƓG�܂��̓v���C���[2�̌��݈ʒu�̒����l�����߂Ē����_��ݒ肵�Ă���
	//m_target��Z���͌Œ�
	if ((m_targetLeft.x > -600.0f && m_targetRight.x < 600.0f))
	{
		// 1P VS 2P �ł͂Ȃ��Ƃ�
		if (m_game->m_2playerFlag != true)
		{
			//��ʒ���
			m_target.x = (m_playerPosition.x + m_enemyPosition.x) / 2;
		}
		// 1P VS 2P �̂Ƃ�
		else if (m_game->m_2playerFlag == true)
		{
			//��ʒ���
			m_target.x = (m_playerPosition.x + m_player2Position.x) / 2;
		}
	}
	else
	{
		//1P vs 2P �ł͂Ȃ��Ƃ�
		if (m_game->m_2playerFlag != true)
		{
			if (m_player->m_charaCon.IsOnGround() && m_enemy->m_charaCon.IsOnGround())
			{
				//�E
				if (m_targetLeft.x<=-600.0f)
				{
					m_target.x = -400.0f;
				}
				//��
				else
				{
					m_target.x = 400.0f;
				}
			}
		}
		// 1P VS 2P �̂Ƃ�
		else if(m_game->m_2playerFlag==true)
		{
			if (m_player->m_charaCon.IsOnGround() && m_player2->m_charaCon.IsOnGround())
			{
				//�E
				if (m_targetLeft.x <= -600.0f)
				{
					m_target.x = -400.0f;
				}
				//��
				else
				{
					m_target.x = 400.0f;
				}
			}
		}
	}

	//1P vs 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//����ʒ[
		m_targetLeft.x = -200.0f + ((m_playerPosition.x + m_enemyPosition.x) / 2);
		//�E��ʒ[
		m_targetRight.x = 200.0 + ((m_playerPosition.x + m_enemyPosition.x) / 2);

		m_target.y = ((m_playerPosition.y + m_enemyPosition.y) / 2) + 50.0f;
		m_target.z = 0.0f;
	}
	//1P vs 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//����ʒ[
		m_targetLeft.x = -200.0f + ((m_playerPosition.x + m_player2Position.x) / 2);
		//�E��ʒ[
		m_targetRight.x = 200.0 + ((m_playerPosition.x + m_player2Position.x) / 2);

		m_target.y = ((m_playerPosition.y + m_player2Position.y) / 2) + 50.0f;
		m_target.z = 0.0f;
	}

	//�����_
	g_camera3D->SetTarget(m_target);

	//���_
	m_cameraPos = m_target;
	m_cameraPos.z -= 200.0f;
	
	g_camera3D->SetPosition(m_cameraPos);
}