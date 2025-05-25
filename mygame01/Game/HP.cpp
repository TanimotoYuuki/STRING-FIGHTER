#include "stdafx.h"
#include "Game.h"
#include "HP.h"
#include "Player.h"
#include "Player2.h"
#include "Enemy.h"

HP::HP()
{

}

HP::~HP()
{

}

bool HP::Start()
{
	//インスタンス
	m_game = FindGO<Game>("game");

	//1P
	//名前
	m_playerName.Init("Assets/UI/hp/1P_white.dds", 1024.0f, 128.0f);
	//m_playerName.SetPosition({ -625.0f,375.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerName.SetPosition(m_sideLeftNamePosition);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerName.SetPosition(m_sideRightNamePosition);
	}
	m_playerName.SetScale({ 0.25f,0.5f,1.0f });
	m_playerName.Update();

	//バー
	m_playerHPBer.Init("Assets/UI/hp/frame.dds", 1024.0f, 128.0f);
	//m_playerHPBer.SetPosition({ -500.0f,450.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerHPBer.SetPosition(m_sideLeftHPBerPosition);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerHPBer.SetPosition(m_sideRightHPBerPosition);
	}
	m_playerHPBer.SetScale({ 0.5f,0.5f,1.0f });
	m_playerHPBer.Update();

	//ゲージ
	m_playerHPGauge.Init("Assets/UI/hp/1P.dds", 1024.0f, 128.0f);
	//m_playerHPGauge.SetPosition({ -246.0f,450.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerHPGauge.SetPosition(m_sideLeftHPGaugePosition);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerHPGauge.SetPosition(m_sideRightHPGaugePosition);
	}
	m_playerHPGauge.SetScale({ 0.4956f,0.45f,1.0f });
	//m_playerHPGauge.SetPivot(Vector2(1.0f, 0.5f));
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerHPGauge.SetPivot(m_sideLeftPivot);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerHPGauge.SetPivot(m_sideRightPivot);
	}
	m_playerHPGauge.Update();



	//2P
	//名前
	m_player2Name.Init("Assets/UI/hp/2P_white.dds", 1024.0f, 128.0f);
	//m_player2Name.SetPosition({ 625.0f,375.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2Name.SetPosition(m_sideLeftNamePosition);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2Name.SetPosition(m_sideRightNamePosition);
	}
	m_player2Name.SetScale({ 0.25f,0.5f,1.0f });
	m_player2Name.Update();

	//バー
	m_player2HPBer.Init("Assets/UI/hp/frame.dds", 1024.0f, 128.0f);
	//m_player2HPBer.SetPosition({ 500.0f,450.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2HPBer.SetPosition(m_sideLeftHPBerPosition);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2HPBer.SetPosition(m_sideRightHPBerPosition);
	}
	m_player2HPBer.SetScale({ 0.5f,0.5f,1.0f });
	m_player2HPBer.Update();

	//ゲージ
	m_player2HPGauge.Init("Assets/UI/hp/2P.dds", 1024.0f, 128.0f);
	//m_player2HPGauge.SetPosition({ 247.0f,450.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2HPGauge.SetPosition(m_sideLeftHPGaugePosition);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2HPGauge.SetPosition(m_sideRightHPGaugePosition);
	}
	m_player2HPGauge.SetScale({ 0.4956f,0.45f,1.0f });
	//m_player2HPGauge.SetPivot(Vector2(0.0f, 0.5f));
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2HPGauge.SetPivot(m_sideLeftPivot);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2HPGauge.SetPivot(m_sideRightPivot);
	}
	m_player2HPGauge.Update();



	//CPU
	//名前
	m_enemyName.Init("Assets/UI/hp/CPU_white.dds", 1024.0f, 128.0f);
	//m_enemyName.SetPosition({ 675.0f,375.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyName.SetPosition(m_sideLeftEnemyNamePosition);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyName.SetPosition(m_sideRightEnemyNamePosition);
	}
	m_enemyName.SetScale({ 0.15f,0.5f,1.0f });
	m_enemyName.Update();

	//バー
	m_enemyHPBer.Init("Assets/UI/hp/frame.dds", 1024.0f, 128.0f);
	//m_enemyHPBer.SetPosition({ 500.0f,450.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyHPBer.SetPosition(m_sideLeftHPBerPosition);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyHPBer.SetPosition(m_sideRightHPBerPosition);
	}
	m_enemyHPBer.SetScale({ 0.5f,0.5f,1.0f });
	m_enemyHPBer.Update();

	//ゲージ
	m_enemyHPGauge.Init("Assets/UI/hp/CPU.dds", 1024.0f, 128.0f);
	//m_enemyHPGauge.SetPosition({ 247.0f,450.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyHPGauge.SetPosition(m_sideLeftHPGaugePosition);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyHPGauge.SetPosition(m_sideRightHPGaugePosition);
	}
	m_enemyHPGauge.SetScale({ 0.4956f,0.45f,1.0f });
	//m_enemyHPGauge.SetPivot(Vector2(0.0f, 0.5f));
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyHPGauge.SetPivot(m_sideLeftPivot);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyHPGauge.SetPivot(m_sideRightPivot);
	}
	m_enemyHPGauge.Update();



	//インスタンス
	m_player = FindGO<Player>("player");
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}

	return true;
}

void HP::Update()
{
	//1P
	int playerMaxHP = m_player->m_playerMaxHP;
	int playerNowHP = m_player->m_playerHP;
	float playerRemnanth = (float)playerNowHP / (float)playerMaxHP;
	Vector3 playerScal = { 0.4956f,0.45f,1.0f };
	playerScal.x *= playerRemnanth;
	if (m_player->m_playerHP <= 0)
	{
		playerScal.x = 0.0f;
	}
	m_playerHPGauge.SetScale(playerScal);
	m_playerHPGauge.Update();

	// 1P VS 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//CPU
		int enemyMaxHP = m_enemy->m_enemyMaxHP;
		int enemyNowHP = m_enemy->m_enemyHP;
		float enemyRemnanth = (float)enemyNowHP / (float)enemyMaxHP;
		Vector3 enemyScal = { 0.4956f,0.45f,1.0f };
		enemyScal.x *= enemyRemnanth;
		if (m_enemy->m_enemyHP <= 0)
		{
			enemyScal.x = 0.0f;
		}
		m_enemyHPGauge.SetScale(enemyScal);
		m_enemyHPGauge.Update();
	}
	// 1P VS 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//2P
		int player2MaxHP = m_player2->m_playerMaxHP;
		int player2NowHP = m_player2->m_playerHP;
		float player2Remnanth = (float)player2NowHP / (float)player2MaxHP;
		Vector3 player2Scal = { 0.4956f,0.45f,1.0f };
		player2Scal.x *= player2Remnanth;
		if (m_player2->m_playerHP <= 0)
		{
			player2Scal.x = 0.0f;
		}
		m_player2HPGauge.SetScale(player2Scal);
		m_player2HPGauge.Update();
	}

}

void HP::Render(RenderContext& rc)
{
	//プレイヤー(名前)描画
	m_playerName.Draw(rc);
	//プレイヤー(体力バー)描画
	m_playerHPBer.Draw(rc);
	//プレイヤー(体力ゲージ)描画
	m_playerHPGauge.Draw(rc);

	// 1P VS 2P ではないとき
	if (m_game->m_2playerFlag != true)
	{
		//敵(名前)描画
		m_enemyName.Draw(rc);
		//敵(体力バー)描画
		m_enemyHPBer.Draw(rc);
		//敵(体力ゲージ)描画
		m_enemyHPGauge.Draw(rc);
	}
	// 1P VS 2P のとき
	else if (m_game->m_2playerFlag == true)
	{
		//プレイヤー2(名前)描画
		m_player2Name.Draw(rc);
		//プレイヤー2(体力バー)描画
		m_player2HPBer.Draw(rc);
		//プレイヤー2(体力ゲージ)描画
		m_player2HPGauge.Draw(rc);
	}
}
