#include "stdafx.h"
#include "Debug.h"
#include "Game.h"
#include "Player.h"
#include "Player2.h"
#include "Enemy.h"
#include "Frame.h"
#include "GameTimer.h"
#include "Round.h"
#include "GameCamera.h"
#include "Fade.h"

Debug::Debug()
{

}

Debug::~Debug()
{

}

bool Debug::Start()
{
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}
	m_frame = FindGO<Frame>("frame");
	m_gametimer = FindGO<GameTimer>("gametimer");
	m_round = FindGO<Round>("round");
	m_gameCamera = FindGO<GameCamera>("gamecamera");
	m_fade = FindGO<Fade>("fade");
	return true;
}

void Debug::Update()
{
	//�v���C���[�̍��W:X��
	wchar_t pp_x[256];
	swprintf_s(pp_x, 256, L"X:%d", int(m_player->m_position.x));

	m_playerPositionX.SetText(pp_x);
	m_playerPositionX.SetPosition(Vector3(361.0f, 500.0f, 0.0f));
	m_playerPositionX.SetScale(1.0f);
	m_playerPositionX.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̍��W:Y��
	wchar_t pp_y[256];
	swprintf_s(pp_y, 256, L"Y:%d", int(m_player->m_position.y));

	m_playerPositionY.SetText(pp_y);
	m_playerPositionY.SetPosition(Vector3(561.0f, 500.0f, 0.0f));
	m_playerPositionY.SetScale(1.0f);
	m_playerPositionY.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̍��W:Z��
	wchar_t pp_z[256];
	swprintf_s(pp_z, 256, L"Z:%d", int(m_player->m_position.z));

	m_playerPositionZ.SetText(pp_z);
	m_playerPositionZ.SetPosition(Vector3(761.0f, 500.0f, 0.0f));
	m_playerPositionZ.SetScale(1.0f);
	m_playerPositionZ.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�G�̍��W:X��
		wchar_t ep_x[256];
		swprintf_s(ep_x, 256, L"X:%d", int(m_enemy->m_position.x));

		m_enemyPositionX.SetText(ep_x);
		m_enemyPositionX.SetPosition(Vector3(361.0f, 450.0f, 0.0f));
		m_enemyPositionX.SetScale(1.0f);
		m_enemyPositionX.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

		//�G�̍��W:Y��
		wchar_t ep_y[256];
		swprintf_s(ep_y, 256, L"Y:%d", int(m_enemy->m_position.y));

		m_enemyPositionY.SetText(ep_y);
		m_enemyPositionY.SetPosition(Vector3(561.0f, 450.0f, 0.0f));
		m_enemyPositionY.SetScale(1.0f);
		m_enemyPositionY.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

		//�G�̍��W:Z��
		wchar_t ep_z[256];
		swprintf_s(ep_z, 256, L"Z:%d", int(m_enemy->m_position.z));

		m_enemyPositionZ.SetText(ep_z);
		m_enemyPositionZ.SetPosition(Vector3(761.0f, 450.0f, 0.0f));
		m_enemyPositionZ.SetScale(1.0f);
		m_enemyPositionZ.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�v���C���[2�̍��W:X��
		wchar_t p2p_x[256];
		swprintf_s(p2p_x, 256, L"X:%d", int(m_player2->m_position.x));

		m_player2PositionX.SetText(p2p_x);
		m_player2PositionX.SetPosition(Vector3(361.0f, 450.0f, 0.0f));
		m_player2PositionX.SetScale(1.0f);
		m_player2PositionX.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

		//�v���C���[2�̍��W:Y��
		wchar_t p2p_y[256];
		swprintf_s(p2p_y, 256, L"Y:%d", int(m_player2->m_position.y));

		m_player2PositionY.SetText(p2p_y);
		m_player2PositionY.SetPosition(Vector3(561.0f, 450.0f, 0.0f));
		m_player2PositionY.SetScale(1.0f);
		m_player2PositionY.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

		//�v���C���[2�̍��W:Z��
		wchar_t p2p_z[256];
		swprintf_s(p2p_z, 256, L"Z:%d", int(m_player2->m_position.z));

		m_player2PositionZ.SetText(p2p_z);
		m_player2PositionZ.SetPosition(Vector3(761.0f, 450.0f, 0.0f));
		m_player2PositionZ.SetScale(1.0f);
		m_player2PositionZ.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

	//Lstick:X��
	wchar_t l_x[256];
	swprintf_s(l_x, 256, L"X:%.1f", float(m_player->m_stickL.x));

	m_lstickX.SetText(l_x);
	m_lstickX.SetPosition(Vector3(361.0f, 400.0f, 0.0f));
	m_lstickX.SetScale(1.0f);
	m_lstickX.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//Lstick:Y��
	wchar_t l_y[256];
	swprintf_s(l_y, 256, L"Y:%.1f", float(m_player->m_stickL.y));

	m_lstickY.SetText(l_y);
	m_lstickY.SetPosition(Vector3(561.0f, 400.0f, 0.0f));
	m_lstickY.SetScale(1.0f);
	m_lstickY.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//pushcount_left
	wchar_t p_l[256];
	swprintf_s(p_l, 256, L"L:%d", int(m_player->m_pushLeftFlag));

	m_pushcountLeft.SetText(p_l);
	m_pushcountLeft.SetPosition(Vector3(361.0f, 350.0f, 0.0f));
	m_pushcountLeft.SetScale(1.0f);
	m_pushcountLeft.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//pushcount_right
	wchar_t p_r[256];
	swprintf_s(p_r, 256, L"R:%d", int(m_player->m_pushRightFlag));

	m_pushcountRight.SetText(p_r);
	m_pushcountRight.SetPosition(Vector3(561.0f, 350.0f, 0.0f));
	m_pushcountRight.SetScale(1.0f);
	m_pushcountRight.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�X�e�b�v�t���O(��)
	wchar_t df_l[256];
	swprintf_s(df_l, 256, L"L:%d", int(m_player->m_stepFlagLeft));

	m_dashflagLeft.SetText(df_l);
	m_dashflagLeft.SetPosition(Vector3(361.0f, 300.0f, 0.0f));
	m_dashflagLeft.SetScale(1.0f);
	m_dashflagLeft.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�X�e�b�v�t���O(�E)
	wchar_t df_r[256];
	swprintf_s(df_r, 256, L"R:%d", int(m_player->m_stepFlagRight));

	m_dashflagRight.SetText(df_r);
	m_dashflagRight.SetPosition(Vector3(561.0f, 300.0f, 0.0f));
	m_dashflagRight.SetScale(1.0f);
	m_dashflagRight.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�t���[��
	wchar_t f[256];
	swprintf_s(f, 256, L"%d:%.2f", int(m_frame->m_playertenkey), float(m_frame->m_playerframe[m_frame->m_playerMoveState]));

	m_framePlayer.SetText(f);
	m_framePlayer.SetPosition(Vector3(761.0f, 300.0f, 0.0f));
	m_framePlayer.SetScale(1.0f);
	m_framePlayer.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	
	//�t���[��(��)
	wchar_t f_l[256];
	swprintf_s(f_l, 256, L"L:%.2f", float(m_player->m_frameMemoryLeft));

	m_frameLeft.SetText(f_l);
	m_frameLeft.SetPosition(Vector3(361.0f, 250.0f, 0.0f));
	m_frameLeft.SetScale(1.0f);
	m_frameLeft.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�t���[��(�E)
	wchar_t f_r[256];
	swprintf_s(f_r, 256, L"R:%.2f", float(m_player->m_frameMemoryRight));

	m_frameRight.SetText(f_r);
	m_frameRight.SetPosition(Vector3(561.0f, 250.0f, 0.0f));
	m_frameRight.SetScale(1.0f);
	m_frameRight.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�t���[��(�f�t�H���g)
	wchar_t f_d[256];
	swprintf_s(f_d, 256, L"D:%.2f", float(m_player->m_frameMemoryDefault));

	m_frameDefault.SetText(f_d);
	m_frameDefault.SetPosition(Vector3(761.0f, 250.0f, 0.0f));
	m_frameDefault.SetScale(1.0f);
	m_frameDefault.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̗�
	wchar_t ph[256];
	swprintf_s(ph, 256, L"P:%d", int(m_player->m_playerHP));

	m_playerHP.SetText(ph);
	m_playerHP.SetPosition(Vector3(361.0f, 200.0f, 0.0f));
	m_playerHP.SetScale(1.0f);
	m_playerHP.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�G�̗�
		wchar_t eh[256];
		swprintf_s(eh, 256, L"E:%d", int(m_enemy->m_enemyHP));

		m_enemyHP.SetText(eh);
		m_enemyHP.SetPosition(Vector3(561.0f, 200.0f, 0.0f));
		m_enemyHP.SetScale(1.0f);
		m_enemyHP.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag==true)
	{
		//�v���C���[2�̗�
		wchar_t p2h[256];
		swprintf_s(p2h, 256, L"E:%d", int(m_player2->m_playerHP));

		m_player2HP.SetText(p2h);
		m_player2HP.SetPosition(Vector3(561.0f, 200.0f, 0.0f));
		m_player2HP.SetScale(1.0f);
		m_player2HP.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}
	//�t�F�[�h����
	wchar_t ft[256];
	swprintf_s(ft, 256, L"T:%.1f", float(m_round->m_fadeTime));

	m_fadeTime.SetText(ft);
	m_fadeTime.SetPosition(Vector3(761.0f, 200.0f, 0.0f));
	m_fadeTime.SetScale(1.0f);
	m_fadeTime.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�t�F�[�h
	wchar_t ca[256];
	swprintf_s(ca, 256, L"C:%.1f", float(m_fade->m_currentAlpha));

	m_currentAlpha.SetText(ca);
	m_currentAlpha.SetPosition(Vector3(361.0f, 150.0f, 0.0f));
	m_currentAlpha.SetScale(1.0f);
	m_currentAlpha.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̍��W:X��
	wchar_t mp_x[256];
	swprintf_s(mp_x, 256, L"X:%d", int(m_gameCamera->m_movePos.x));

	m_movePosX.SetText(mp_x);
	m_movePosX.SetPosition(Vector3(361.0f, 100.0f, 0.0f));
	m_movePosX.SetScale(1.0f);
	m_movePosX.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̍��W:Y��
	wchar_t mp_y[256];
	swprintf_s(mp_y, 256, L"X:%d", int(m_gameCamera->m_movePos.y));

	m_movePosY.SetText(mp_y);
	m_movePosY.SetPosition(Vector3(561.0f, 100.0f, 0.0f));
	m_movePosY.SetScale(1.0f);
	m_movePosY.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//�v���C���[�̍��W:Z��
	wchar_t mp_z[256];
	swprintf_s(mp_z, 256, L"X:%d", int(m_gameCamera->m_movePos.z));

	m_movePosZ.SetText(mp_z);
	m_movePosZ.SetPosition(Vector3(761.0f, 100.0f, 0.0f));
	m_movePosZ.SetScale(1.0f);
	m_movePosZ.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//��ʍ��[
	wchar_t t_l[256];
	swprintf_s(t_l, 256, L"L:%d", int(m_gameCamera->m_targetLeft.x));

	m_targetLeft.SetText(t_l);
	m_targetLeft.SetPosition(Vector3(361.0f, 50.0f, 0.0f));
	m_targetLeft.SetScale(1.0f);
	m_targetLeft.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//��ʍ��[
	wchar_t t[256];
	swprintf_s(t, 256, L"M:%d", int(m_gameCamera->m_target.x));

	m_target.SetText(t);
	m_target.SetPosition(Vector3(561.0f, 50.0f, 0.0f));
	m_target.SetScale(1.0f);
	m_target.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	//��ʉE�[
	wchar_t t_r[256];
	swprintf_s(t_r, 256, L"R:%d", int(m_gameCamera->m_targetRight.x));

	m_targetRight.SetText(t_r);
	m_targetRight.SetPosition(Vector3(761.0f, 50.0f, 0.0f));
	m_targetRight.SetScale(1.0f);
	m_targetRight.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });	

	//�_���[�W�J�E���g:�v���C���[
	wchar_t dc_p[256];
	swprintf_s(dc_p, 256, L"P:%d", int(m_player->m_damageCount));

	m_damageCountP.SetText(dc_p);
	m_damageCountP.SetPosition(Vector3(361.0f, 0.0f, 0.0f));
	m_damageCountP.SetScale(1.0f);
	m_damageCountP.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });

	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�_���[�W�J�E���g:�G
		wchar_t dc_e[256];
		swprintf_s(dc_e, 256, L"E:%d", int(m_enemy->m_damageCount));

		m_damageCountE.SetText(dc_e);
		m_damageCountE.SetPosition(Vector3(561.0f, 0.0f, 0.0f));
		m_damageCountE.SetScale(1.0f);
		m_damageCountE.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�_���[�W�J�E���g:�v���C���[2
		wchar_t dc_p2[256];
		swprintf_s(dc_p2, 256, L"P2:%d", int(m_player2->m_damageCount));

		m_damageCountP2.SetText(dc_p2);
		m_damageCountP2.SetPosition(Vector3(561.0f, 0.0f, 0.0f));
		m_damageCountP2.SetScale(1.0f);
		m_damageCountP2.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

}

void Debug::Render(RenderContext& rc)
{
	//�v���C���[�̍��W
	m_playerPositionX.Draw(rc);
	m_playerPositionY.Draw(rc);
	m_playerPositionZ.Draw(rc);

	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�G�̍��W
		m_enemyPositionX.Draw(rc);
		m_enemyPositionY.Draw(rc);
		m_enemyPositionZ.Draw(rc);
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�v���C���[2�̍��W
		m_player2PositionX.Draw(rc);
		m_player2PositionY.Draw(rc);
		m_player2PositionZ.Draw(rc);
	}

	//���X�e�B�b�N
	m_lstickX.Draw(rc);
	m_lstickY.Draw(rc);

	//���X�e�B�b�N��|��
	m_pushcountLeft.Draw(rc);
	m_pushcountRight.Draw(rc);

	//�t���[��
	m_framePlayer.Draw(rc);
	m_frameLeft.Draw(rc);
	m_frameRight.Draw(rc);
	m_frameDefault.Draw(rc);

	//�_�b�V���t���O
	m_dashflagLeft.Draw(rc);
	m_dashflagRight.Draw(rc);

	//�̗�
	m_playerHP.Draw(rc);
	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_enemyHP.Draw(rc);
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_player2HP.Draw(rc);
	}

	//�t�F�[�h����
	m_fadeTime.Draw(rc);

	//�t�F�[�h
	m_currentAlpha.Draw(rc);

	//���_
	m_movePosX.Draw(rc);
	m_movePosY.Draw(rc);
	m_movePosZ.Draw(rc);

	//�����_
	m_targetLeft.Draw(rc);
	m_target.Draw(rc);
	m_targetRight.Draw(rc);

	//���x
	m_damageCountP.Draw(rc);
	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_damageCountE.Draw(rc);
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_damageCountP2.Draw(rc);
	}
}