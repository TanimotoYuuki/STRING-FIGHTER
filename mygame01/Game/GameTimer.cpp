#include "stdafx.h"
#include "GameTimer.h"
#include "Game.h"
#include "Round.h"

GameTimer::GameTimer()
{

}

GameTimer::~GameTimer()
{

}

bool GameTimer::Start()
{
	//上位桁
	m_timeFirstNumber[0].Init("Assets/UI/number/0.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[0].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[0].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[0].Update();

	m_timeFirstNumber[1].Init("Assets/UI/number/1.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[1].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[1].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[1].Update();

	m_timeFirstNumber[2].Init("Assets/UI/number/2.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[2].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[2].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[2].Update();

	m_timeFirstNumber[3].Init("Assets/UI/number/3.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[3].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[3].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[3].Update();

	m_timeFirstNumber[4].Init("Assets/UI/number/4.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[4].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[4].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[4].Update();

	m_timeFirstNumber[5].Init("Assets/UI/number/5.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[5].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[5].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[5].Update();

	m_timeFirstNumber[6].Init("Assets/UI/number/6.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[6].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[6].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[6].Update();

	m_timeFirstNumber[7].Init("Assets/UI/number/7.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[7].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[7].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[7].Update();

	m_timeFirstNumber[8].Init("Assets/UI/number/8.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[8].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[8].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[8].Update();

	m_timeFirstNumber[9].Init("Assets/UI/number/9.dds", 1024.0f, 1024.0f);
	m_timeFirstNumber[9].SetPosition({ -30.0f,450.0f,0.0f });
	m_timeFirstNumber[9].SetScale({ 0.1f,0.1f,1.0f });
	m_timeFirstNumber[9].Update();

	//下位桁
	m_timeSecondNumber[0].Init("Assets/UI/number/0.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[0].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[0].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[0].Update();

	m_timeSecondNumber[1].Init("Assets/UI/number/1.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[1].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[1].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[1].Update();

	m_timeSecondNumber[2].Init("Assets/UI/number/2.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[2].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[2].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[2].Update();

	m_timeSecondNumber[3].Init("Assets/UI/number/3.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[3].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[3].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[3].Update();

	m_timeSecondNumber[4].Init("Assets/UI/number/4.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[4].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[4].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[4].Update();

	m_timeSecondNumber[5].Init("Assets/UI/number/5.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[5].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[5].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[5].Update();

	m_timeSecondNumber[6].Init("Assets/UI/number/6.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[6].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[6].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[6].Update();

	m_timeSecondNumber[7].Init("Assets/UI/number/7.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[7].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[7].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[7].Update();

	m_timeSecondNumber[8].Init("Assets/UI/number/8.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[8].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[8].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[8].Update();

	m_timeSecondNumber[9].Init("Assets/UI/number/9.dds", 1024.0f, 1024.0f);
	m_timeSecondNumber[9].SetPosition({ 30.0f,450.0f,0.0f });
	m_timeSecondNumber[9].SetScale({ 0.1f,0.1f,1.0f });
	m_timeSecondNumber[9].Update();

	//インスタンス
	m_game = FindGO<Game>("game");
	m_round = FindGO<Round>("round");

	return true;
}

void GameTimer::Update()
{
	//ラウンドが終わっていないとき
	if (m_round->IsNoFighting() != true)
	{
		m_time -= g_gameTime->GetFrameDeltaTime();
	}

	if (m_time < 0.0f)
	{
		m_timeFirstView = 0;
		m_timeSecondView = 0;
		return;
	}

	//残り時間を10で割ったら残り時間の2桁目が求まる
	m_timeFirstView = m_time/10;
	//残り時間を10で割って
	//割った値をさっき求めた残り時間の2桁目を引いて、
	//求めた値を10掛けたら残り時間の1桁目が求まる
	m_timeSecondView = ((m_time / 10) - m_timeFirstView) * 10;
}

void GameTimer::Render(RenderContext& rc)
{
	m_timeFirstNumber[m_timeFirstView].Draw(rc);
	m_timeSecondNumber[m_timeSecondView].Draw(rc);
}
