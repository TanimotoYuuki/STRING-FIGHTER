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
	//1P vs 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	//1P vs 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}

	//キャラクターの初期座標を設定する
	m_playerDefaultPosition = m_player->m_position;
	//1P vs 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		m_enemyDefaultPosition = m_enemy->m_position;
	}
	//1P vs 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		m_player2DefaultPosition = m_player2->m_position;
	}
	//画角の変更
	g_camera3D->SetViewAngle(0.85f);
	return true;
}

void GameCamera::Update()
{
	//キャラクターの座標を設定する
	m_playerPosition = m_player->m_position;
	// 1P VS 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		m_enemyPosition = m_enemy->m_position;
	}
	// 1P VS 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		m_player2Position = m_player2->m_position;
	}

	//画面端
	//m_movePosのX軸はプレイヤーと敵またはプレイヤー2の初期位置の値を絶対値にしてから足して、
	//プレイヤーと敵またはプレイヤー2の現在位置を引いて、
	//プレイヤーの位置が右側にいたら 初期位置+現在位置
	//プレイヤーの位置が左側にいたら 初期位置-現在位置
	//m_movePosの値が-100以下になったら画面端に行っている
	//画面端までいったらカメラ移動しない
	//1P vs 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//右
		if (m_playerPosition.x < m_enemyPosition.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_enemyDefaultPosition.x)) + (m_playerPosition.x - m_enemyPosition.x);
		}
		//左
		else if (m_playerPosition.x > m_enemyPosition.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_enemyDefaultPosition.x)) - (m_playerPosition.x - m_enemyPosition.x);
		}
	}
	//1P vs 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//右
		if (m_playerPosition.x < m_player2Position.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_player2DefaultPosition.x)) + (m_playerPosition.x - m_player2Position.x);
		}
		//左
		else if (m_playerPosition.x > m_player2Position.x)
		{
			m_movePos.x = (fabsf(m_playerDefaultPosition.x) + fabsf(m_player2DefaultPosition.x)) - (m_playerPosition.x - m_player2Position.x);
		}
	}
	//if (m_targetLeft.x >= -500.0f)
	//{
	//	//画面左端
	//	//m_targetLeft.x = (m_enemyPosition.x + m_playerDefaultPosition.x) - 200.0f;
	//}

	//if (m_targetRight.x <= 500.0f)
	//{
	//	//画面右端

	//	//m_targetRight.x = (m_playerPosition.x + m_enemyDefaultPosition.x) + 200.0;
	//}

	//注視点
	//m_targetのX軸とY軸はプレイヤーの現在位置と敵またはプレイヤー2の現在位置の中央値を求めて注視点を設定している
	//m_targetのZ軸は固定
	if ((m_targetLeft.x > -600.0f && m_targetRight.x < 600.0f))
	{
		// 1P VS 2P ではないとき
		if (m_game->m_2playerFlag != true)
		{
			//画面中央
			m_target.x = (m_playerPosition.x + m_enemyPosition.x) / 2;
		}
		// 1P VS 2P のとき
		else if (m_game->m_2playerFlag == true)
		{
			//画面中央
			m_target.x = (m_playerPosition.x + m_player2Position.x) / 2;
		}
	}
	else
	{
		//1P vs 2P ではないとき
		if (m_game->m_2playerFlag != true)
		{
			if (m_player->m_charaCon.IsOnGround() && m_enemy->m_charaCon.IsOnGround())
			{
				//右
				if (m_targetLeft.x<=-600.0f)
				{
					m_target.x = -400.0f;
				}
				//左
				else
				{
					m_target.x = 400.0f;
				}
			}
		}
		// 1P VS 2P のとき
		else if(m_game->m_2playerFlag==true)
		{
			if (m_player->m_charaCon.IsOnGround() && m_player2->m_charaCon.IsOnGround())
			{
				//右
				if (m_targetLeft.x <= -600.0f)
				{
					m_target.x = -400.0f;
				}
				//左
				else
				{
					m_target.x = 400.0f;
				}
			}
		}
	}

	//1P vs 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//左画面端
		m_targetLeft.x = -200.0f + ((m_playerPosition.x + m_enemyPosition.x) / 2);
		//右画面端
		m_targetRight.x = 200.0 + ((m_playerPosition.x + m_enemyPosition.x) / 2);

		m_target.y = ((m_playerPosition.y + m_enemyPosition.y) / 2) + 50.0f;
		m_target.z = 0.0f;
	}
	//1P vs 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//左画面端
		m_targetLeft.x = -200.0f + ((m_playerPosition.x + m_player2Position.x) / 2);
		//右画面端
		m_targetRight.x = 200.0 + ((m_playerPosition.x + m_player2Position.x) / 2);

		m_target.y = ((m_playerPosition.y + m_player2Position.y) / 2) + 50.0f;
		m_target.z = 0.0f;
	}

	//注視点
	g_camera3D->SetTarget(m_target);

	//視点
	m_cameraPos = m_target;
	m_cameraPos.z -= 200.0f;
	
	g_camera3D->SetPosition(m_cameraPos);
}