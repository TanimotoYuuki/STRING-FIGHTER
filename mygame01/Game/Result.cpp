#include "stdafx.h"
#include "Result.h"
#include "Round.h"

Result::Result()
{

}

Result::~Result()
{

}

bool Result::Start()
{
	//1P勝利
	m_1pWin[0].Init("Assets/UI/result/1P_black.dds", 1028.0f, 256.0f);
	m_1pWin[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_1pWin[0].SetScale({ 0.5f,0.5f,1.0f });
	m_1pWin[0].Update();

	m_1pWin[1].Init("Assets/UI/result/win.dds", 1028.0f, 256.0f);
	m_1pWin[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_1pWin[1].SetScale({ 0.5f,0.5f,1.0f });
	m_1pWin[1].Update();

	//2P勝利
	m_2pWin[0].Init("Assets/UI/result/2P_black.dds", 1028.0f, 256.0f);
	m_2pWin[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_2pWin[0].SetScale({ 0.5f,0.5f,1.0f });
	m_2pWin[0].Update();

	m_2pWin[1].Init("Assets/UI/result/win.dds", 1028.0f, 256.0f);
	m_2pWin[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_2pWin[1].SetScale({ 0.5f,0.5f,1.0f });
	m_2pWin[1].Update();

	//CPU勝利
	m_enemyWin[0].Init("Assets/UI/result/CPU_black.dds", 1028.0f, 256.0f);
	m_enemyWin[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_enemyWin[0].SetScale({ 0.5f,0.5f,1.0f });
	m_enemyWin[0].Update();

	m_enemyWin[1].Init("Assets/UI/result/win.dds", 1028.0f, 256.0f);
	m_enemyWin[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_enemyWin[1].SetScale({ 0.5f,0.5f,1.0f });
	m_enemyWin[1].Update();

	//引き分け
	m_draw.Init("Assets/UI/result/draw.dds", 1028.0f, 256.0f);
	m_draw.SetPosition({ 0.0f,0.0f,0.0f });
	m_draw.SetScale({ 0.65f,0.8f,1.0f });
	m_draw.Update();

	//インスタンス
	m_round = FindGO<Round>("round");
	return true;
}

void Result::Update()
{

}

void Result::Render(RenderContext& rc)
{
	//1Pが勝利したとき
	if (m_round->m_1pWinFlag == true)
	{
		for (int i = 0; i < 2; i++)
		{
			//1P勝利描画
			m_1pWin[i].Draw(rc);
		}
	}
	//2Pが勝利したとき
	else if (m_round->m_2pWinFlag == true)
	{
		for (int i = 0; i < 2; i++)
		{
			//2P勝利描画
			m_2pWin[i].Draw(rc);
		}
	}
	//CPUが勝利したとき
	else if (m_round->m_enemyWinFlag == true)
	{
		for (int i = 0; i < 2; i++)
		{
			//敵勝利描画
			m_enemyWin[i].Draw(rc);
		}
	}
	//引き分けのとき
	else if (m_round->m_drawFlag == true)
	{
		//引き分け描画
		m_draw.Draw(rc);
	}
}