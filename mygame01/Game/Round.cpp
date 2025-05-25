#include "stdafx.h"
#include "Round.h"
#include "Game.h"
#include "Fade.h"
#include "Player.h"
#include "Enemy.h"
#include "Player2.h"
#include "GameTimer.h"
#include "Frame.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Round::Round()
{

}

Round::~Round()
{

}

bool Round::Start()
{
	//���E���h1
	m_round[0].Init("Assets/UI/round/round1.dds", 1028.0f, 256.0f);
	m_round[0].SetPosition({-25.0f,0.0f,0.0f});
	m_round[0].SetScale({0.65f,0.8f,1.0f});
	m_round[0].Update();

	//���E���h2
	m_round[1].Init("Assets/UI/round/round2.dds", 1028.0f, 256.0f);
	m_round[1].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[1].SetScale({ 0.65f,0.8f,1.0f });
	m_round[1].Update();

	//���E���h3
	m_round[2].Init("Assets/UI/round/round3.dds", 1028.0f, 256.0f);
	m_round[2].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[2].SetScale({ 0.65f,0.8f,1.0f });
	m_round[2].Update();

	//���E���h4
	m_round[3].Init("Assets/UI/round/round4.dds", 1028.0f, 256.0f);
	m_round[3].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[3].SetScale({ 0.65f,0.8f,1.0f });
	m_round[3].Update();

	//���E���h5
	m_round[4].Init("Assets/UI/round/round5.dds", 1028.0f, 256.0f);
	m_round[4].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[4].SetScale({ 0.65f,0.8f,1.0f });
	m_round[4].Update();

	//���E���h6
	m_round[5].Init("Assets/UI/round/round6.dds", 1028.0f, 256.0f);
	m_round[5].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[5].SetScale({ 0.65f,0.8f,1.0f });
	m_round[5].Update();

	//���E���h7
	m_round[6].Init("Assets/UI/round/round7.dds", 1028.0f, 256.0f);
	m_round[6].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[6].SetScale({ 0.65f,0.8f,1.0f });
	m_round[6].Update();

	//���E���h8
	m_round[7].Init("Assets/UI/round/round8.dds", 1028.0f, 256.0f);
	m_round[7].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[7].SetScale({ 0.65f,0.8f,1.0f });
	m_round[7].Update();

	//���E���h9
	m_round[8].Init("Assets/UI/round/round9.dds", 1028.0f, 256.0f);
	m_round[8].SetPosition({ -25.0f,0.0f,0.0f });
	m_round[8].SetScale({ 0.65f,0.8f,1.0f });
	m_round[8].Update();

	//���E���h10�`
	m_overround.Init("Assets/UI/round/round.dds", 1028.0f, 256.0f);
	m_overround.SetPosition({ 0.0f,0.0f,0.0f });
	m_overround.SetScale({ 0.5f,0.5f,1.0f });
	m_overround.Update();

	//�t�@�C�g
	m_fight.Init("Assets/UI/round/fight.dds", 1028.0f, 256.0f);
	m_fight.SetPosition({ 0.0f,0.0f,0.0f });
	m_fight.SetScale({ 0.65f,0.8f,1.0f });
	m_fight.Update();

	//KO
	m_ko.Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_ko.SetPosition({ 0.0f,0.0f,0.0f });
	m_ko.SetScale({ 0.65f,0.8f,1.0f });
	m_ko.Update();

	//�_�u��KO
	m_doubleKO[0].Init("Assets/UI/round/double.dds", 1028.0f, 256.0f);
	m_doubleKO[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_doubleKO[0].SetScale({ 0.5f,0.5f,1.0f });
	m_doubleKO[0].Update();

	m_doubleKO[1].Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_doubleKO[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_doubleKO[1].SetScale({ 0.5f,0.5f,1.0f });
	m_doubleKO[1].Update();

	//�p�[�t�F�N�gKO
	m_perfectKO[0].Init("Assets/UI/round/perfect.dds", 1028.0f, 256.0f);
	m_perfectKO[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_perfectKO[0].SetScale({ 0.5f,0.5f,1.0f });
	m_perfectKO[0].Update();

	m_perfectKO[1].Init("Assets/UI/round/ko.dds", 1028.0f, 256.0f);
	m_perfectKO[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_perfectKO[1].SetScale({ 0.5f,0.5f,1.0f });
	m_perfectKO[1].Update();

	//�^�C���A�b�v
	m_timeUp.Init("Assets/UI/round/timeup.dds", 1028.0f, 256.0f);
	m_timeUp.SetPosition({ 0.0f,0.0f,0.0f });
	m_timeUp.SetScale({ 0.65f,0.8f,1.0f });
	m_timeUp.Update();

	//�t�@�C�i�����E���h
	m_finalRound[0].Init("Assets/UI/round/final.dds", 1028.0f, 256.0f);
	m_finalRound[0].SetPosition({ 0.0f,100.0f,0.0f });
	m_finalRound[0].SetScale({ 0.5f,0.5f,1.0f });
	m_finalRound[0].Update();

	m_finalRound[1].Init("Assets/UI/round/round.dds", 1028.0f, 256.0f);
	m_finalRound[1].SetPosition({ 0.0f,0.0f,0.0f });
	m_finalRound[1].SetScale({ 0.5f,0.5f,1.0f });
	m_finalRound[1].Update();

	//�C���X�^���X
	m_game = FindGO<Game>("game");

	//�v���C���[�f�t�H���g���E���h�A�C�R��
	m_playerRoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_playerRoundIconD[0].SetPosition({ -275.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_playerRoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconD[0].Update();	

	m_playerRoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_playerRoundIconD[1].SetPosition({ -335.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_playerRoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconD[1].Update();	

	//�v���C���[2�f�t�H���g���E���h�A�C�R��
	m_player2RoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_player2RoundIconD[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_player2RoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconD[0].Update();

	m_player2RoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_player2RoundIconD[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_player2RoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconD[1].Update();

	//�G�f�t�H���g���E���h�A�C�R��
	m_enemyRoundIconD[0].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_enemyRoundIconD[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconD[0].SetPosition(m_roundIconLeftD[0]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconD[0].SetPosition(m_roundIconRightD[0]);
	}
	m_enemyRoundIconD[0].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconD[0].Update();	

	m_enemyRoundIconD[1].Init("Assets/UI/round/roundicon_default.dds", 512.0f, 512.0f);
	//m_enemyRoundIconD[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconD[1].SetPosition(m_roundIconLeftD[1]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconD[1].SetPosition(m_roundIconRightD[1]);
	}
	m_enemyRoundIconD[1].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconD[1].Update();

	//�v���C���[�������E���h�A�C�R��
	m_playerRoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_playerRoundIconW[0].SetPosition({ -275.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_playerRoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconW[0].Update();	

	m_playerRoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_playerRoundIconW[1].SetPosition({ -335.0f,385.0f,0.0f });
	if (m_game->m_1pSide == enSideState_Left)
	{
		m_playerRoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_1pSide == enSideState_Right)
	{
		m_playerRoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_playerRoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_playerRoundIconW[1].Update();	

	//�v���C���[2�������E���h�A�C�R��
	m_player2RoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_player2RoundIconW[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_player2RoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconW[0].Update();

	m_player2RoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_player2RoundIconW[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_2pSide == enSideState_Left)
	{
		m_player2RoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_2pSide == enSideState_Right)
	{
		m_player2RoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_player2RoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_player2RoundIconW[1].Update();

	//�G�������E���h�A�C�R��
	m_enemyRoundIconW[0].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_enemyRoundIconW[0].SetPosition({ 275.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconW[0].SetPosition(m_roundIconLeftW[0]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconW[0].SetPosition(m_roundIconRightW[0]);
	}
	m_enemyRoundIconW[0].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconW[0].Update();	

	m_enemyRoundIconW[1].Init("Assets/UI/round/roundicon_win.dds", 512.0f, 512.0f);
	//m_enemyRoundIconW[1].SetPosition({ 335.0f,385.0f,0.0f });
	if (m_game->m_cpuSide == enSideState_Left)
	{
		m_enemyRoundIconW[1].SetPosition(m_roundIconLeftW[1]);
	}
	else if (m_game->m_cpuSide == enSideState_Right)
	{
		m_enemyRoundIconW[1].SetPosition(m_roundIconRightW[1]);
	}
	m_enemyRoundIconW[1].SetScale({ 0.2f,0.2f,1.0f });
	m_enemyRoundIconW[1].Update();

	//���ʉ�
	g_soundEngine->ResistWaveFileBank(9, "Assets/SE/voice/round1.wav");
	g_soundEngine->ResistWaveFileBank(10, "Assets/SE/voice/round2.wav");
	g_soundEngine->ResistWaveFileBank(11, "Assets/SE/voice/finalround.wav");
	g_soundEngine->ResistWaveFileBank(12, "Assets/SE/voice/fight.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/SE/voice/ko.wav");
	g_soundEngine->ResistWaveFileBank(14, "Assets/SE/voice/doubleko.wav");
	g_soundEngine->ResistWaveFileBank(15, "Assets/SE/voice/perfect.wav");
	g_soundEngine->ResistWaveFileBank(16, "Assets/SE/timeup.wav");

	//�C���X�^���X
	m_fade = FindGO<Fade>("fade");
	m_player = FindGO<Player>("player");
	// 1P vs 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		m_enemy = FindGO<Enemy>("enemy");
	}
	// 1P vs 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		m_player2 = FindGO<Player2>("player2");
	}
	m_gametimer = FindGO<GameTimer>("gametimer");
	m_frame = FindGO<Frame>("frame");

	//�t�F�[�h�C��
	m_fade->StartFadeIn();

	return true;
}

void Round::Update()
{
	//���E���h���I����Ă��邩�H
	IsNoFighting();

	//�ȉ��̏�ԈȊO�̂Ƃ�
	if (m_roundState!=State_Fighting && //�ΐ풆
		m_roundState!= State_Idle && //�ҋ@
		m_roundState!=State_Round && //���E���h
		m_roundState!=State_Fight && //�t�@�C�g
		m_roundState!=State_KO && //KO
		m_roundState!=State_TimeUp //�^�C���A�b�v
	   )
	{
		//�N�����������H
		if (m_1pWinFlag != true || //�v���C���[����
			m_2pWinFlag!=true || //�v���C���[2����
			m_enemyWinFlag != true //CPU����
		   )
		{
			//�v���C���[���������Ƃ�
			if (m_1pGetWinFlag == true)
			{
				m_playerGetWin++;
				m_playerNoGetWin--;
				m_roundNo++;
				m_1pGetWinFlag = false;
			}
			//�v���C���[2���������Ƃ�
			else if (m_2pGetWinFlag == true)
			{
				m_player2GetWin++;
				m_player2NoGetWin--;
				m_roundNo++;
				m_2pGetWinFlag = false;
			}
			//�G���������Ƃ�
			else if (m_enemyGetWinFlag == true)
			{
				m_enemyGetWin++;
				m_enemyNoGetWin--;
				m_roundNo++;
				m_enemyGetWinFlag = false;
			}
			//���������̂Ƃ�
			else if (m_getDrawFlag == true)
			{
				m_playerGetWin++;
				m_playerNoGetWin--;
				// 1P VS 2P �ł͂Ȃ��Ƃ�
				if (m_game->m_2playerFlag != true)
				{
					m_enemyGetWin++;
					m_enemyNoGetWin--;
				}
				// 1P VS 2P �̂Ƃ�
				else if (m_game->m_2playerFlag == true)
				{
					m_player2GetWin++;
					m_player2NoGetWin--;
				}
				m_roundNo = 11;
				m_getDrawFlag = false;
			}
		}

		//���E���h���I������Ƃ��̏���
		// 1P vs 2P �ł͂Ȃ��Ƃ�
		if (m_game->m_2playerFlag != true)
		{
			//���E���h���I������Ƃ��ɂ���A�j���[�V�������I������Ƃ�
			if (m_player->m_player.IsPlayingAnimation() == false && m_enemy->m_enemy.IsPlayingAnimation() == false)
			{
				//�v���C���[���G�̃��E���h���擾����0�̂Ƃ�
				if (m_playerNoGetWin == 0 && m_enemyNoGetWin == 0)
				{
					m_drawFlag = true;
				}
				//�v���C���[�̃��E���h���擾����0�̂Ƃ�
				else if (m_playerNoGetWin == 0)
				{
					m_1pWinFlag = true;
				}
				//�G�̃��E���h���擾����0�̂Ƃ�
				else if (m_enemyNoGetWin == 0)
				{
					m_enemyWinFlag = true;
				}

				//�����������Ƃ��������Ȃ�
				if ((m_1pWinFlag == true || //�v���C���[����
					m_enemyWinFlag == true || //CPU����
					m_drawFlag == true) && //��������
					m_game->m_retryFlag != true //�Đ�
					)
				{
					return;
				}

				//�t�F�[�h�A�E�g���Ă��Ȃ��Ƃ�
				if (m_isWaitFadeout == false)
				{
					m_fadeTime -= g_gameTime->GetFrameDeltaTime();
					//�t�F�[�h���Ԃ�0.0�b�ɂȂ�����
					if (m_fadeTime < 0.0f)
					{
						//�t�F�[�h�A�E�g
						m_fade->StartFadeOut();
						m_fadeTime = 1.0f;
						m_isWaitFadeout = true;
					}
				}
				//�t�F�[�h�A�E�g�����Ƃ�
				else if (m_isWaitFadeout == true)
				{
					//�t�F�[�h�A�E�g���I������珉���l�ɖ߂�
					if (!m_fade->IsFade())
					{
						if (m_game->m_retryFlag == true)
						{
							m_game->Reset();
							Reset();
						}
						m_player->Reset();
						m_enemy->Reset();
						//if (m_game->m_2playerFlag != true)
						//{
						//	m_enemy->Reset();
						//}
						//else if (m_game->m_2playerFlag == true)
						//{
						//	m_player2->Reset();
						//}
						m_gametimer->Reset();
						m_frame->Reset();
						//�t�F�[�h�C��
						m_fade->StartFadeIn();
						for (int i = 0; i < State_Num; i++)
						{
							m_seFlag[i] = false;
						}
						m_roundState = State_Idle;
					}
				}
			}
		}
		// 1P vs 2P �̂Ƃ�
		else if (m_game->m_2playerFlag == true)
		{
			//���E���h���I������Ƃ��ɂ���A�j���[�V�������I������Ƃ�
			if (m_player->m_player.IsPlayingAnimation() == false && m_player2->m_player2.IsPlayingAnimation() == false)
			{
				//�v���C���[���v���C���[2�̃��E���h���擾����0�̂Ƃ�
				if (m_playerNoGetWin == 0 && m_player2NoGetWin == 0)
				{
					m_drawFlag = true;
				}
				//�v���C���[�̃��E���h���擾����0�̂Ƃ�
				else if (m_playerNoGetWin == 0)
				{
					m_1pWinFlag = true;
				}
				//�v���C���[2�̃��E���h���擾����0�̂Ƃ�
				else if (m_player2NoGetWin == 0)
				{
					m_2pWinFlag = true;
				}

				//�����������Ƃ��������Ȃ�
				if ((m_1pWinFlag == true || //�v���C���[����
					m_2pWinFlag == true || //�v���C���[2����
					m_drawFlag == true) && //��������
					m_game->m_retryFlag != true //�Đ�
					)
				{
					return;
				}

				//�t�F�[�h�A�E�g���Ă��Ȃ��Ƃ�
				if (m_isWaitFadeout == false)
				{
					m_fadeTime -= g_gameTime->GetFrameDeltaTime();
					//�t�F�[�h���Ԃ�0.0�b�ɂȂ�����
					if (m_fadeTime < 0.0f)
					{
						//�t�F�[�h�A�E�g
						m_fade->StartFadeOut();
						m_fadeTime = 1.0f;
						m_isWaitFadeout = true;
					}
				}
				//�t�F�[�h�A�E�g�����Ƃ�
				else if (m_isWaitFadeout == true)
				{
					//�t�F�[�h�A�E�g���I������珉���l�ɖ߂�
					if (!m_fade->IsFade())
					{
						if (m_game->m_retryFlag == true)
						{
							m_game->Reset();
							Reset();
						}
						m_player->Reset();
						m_player2->Reset();
						//if (m_game->m_2playerFlag != true)
						//{
						//	m_enemy->Reset();
						//}
						//else if (m_game->m_2playerFlag == true)
						//{
						//	m_player2->Reset();
						//}
						m_gametimer->Reset();
						m_frame->Reset();
						//�t�F�[�h�C��
						m_fade->StartFadeIn();
						for (int i = 0; i < State_Num; i++)
						{
							m_seFlag[i] = false;
						}
						m_roundState = State_Idle;
					}
				}
			}
		}
	}
	//���E���h��Ԃ��ҋ@�̂Ƃ�
	else if (m_roundState == State_Idle)
	{
		//�t�F�[�h�C����
		if (m_fade->IsFade())
		{
			m_isWaitFadeout = false;
			m_battleFinishFlag = false;
			m_roundState = State_Round;
		}
		//m_isWaitFadeout = false;
	}
	//���E���h��Ԃ����E���h�̂Ƃ�
	else if (m_roundState == State_Round)
	{
		//�t�F�[�h�C�����I�������
		if (!m_fade->IsFade())
		{
			m_roundFlag = true;
			//���ʉ����Đ����Ă��邩�H
			if (m_seFlag[State_Round] != true)
			{
				//���ʉ�
				m_roundSE = NewGO<SoundSource>(0);
				m_roundSE->Init(m_roundNo);
				m_roundSE->Play(false);
				m_roundSE->SetVolume(0.6f);
				m_seFlag[State_Round] = true;
			}
			//m_roundState = State_Fight;
		}

		//���E���h���\��������
		if (m_roundFlag == true)
		{
			m_roundTime -= 0.5*g_gameTime->GetFrameDeltaTime();
			//���E���h�\�����Ԃ�0.0�b�ɂȂ�����
			if (m_roundTime < 0.0f)
			{
				m_roundTime = 1.0f;
				m_roundFlag = false;
				m_fightFlag = true;
				m_roundState = State_Fight;
			}
		}
	}
	//���E���h��Ԃ��t�@�C�g�̂Ƃ�
	else if (m_roundState == State_Fight)
	{
		m_fightTime -= g_gameTime->GetFrameDeltaTime();
		//���ʉ����Đ����Ă��邩�H
		if (m_seFlag[State_Fight] != true)
		{
			//���ʉ�
			m_fightSE = NewGO<SoundSource>(0);
			m_fightSE->Init(12);
			m_fightSE->Play(false);
			m_fightSE->SetVolume(0.6f);
			m_seFlag[State_Fight] = true;
		}
		//�t�@�C�g�\�����Ԃ�0.0�b�ɂȂ�����
		if (m_fightTime < 0.0f)
		{
			m_fightTime = 1.0f;
			m_roundCount++;
			m_fightFlag = false;
			m_roundState = State_Fighting;
		}
	}
	//���E���h��Ԃ�KO�̂Ƃ�
	else if (m_roundState == State_KO)
	{
		m_koTime -= 1.5f * g_gameTime->GetFrameDeltaTime();
		//�_�u��KO���\��������
		if (m_doubleKOFlag == true)
		{
			//���ʉ����Đ����Ă��邩�H
			if (m_seFlag[State_KO] != true)
			{
				//���ʉ�
				m_doubleKOSE = NewGO<SoundSource>(0);
				m_doubleKOSE->Init(14);
				m_doubleKOSE->Play(false);
				m_doubleKOSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		//�p�[�t�F�N�gKO���\��������
		else if (m_perfectKOFlag == true)
		{
			//���ʉ����Đ����Ă��邩�H
			if (m_seFlag[State_KO] != true)
			{
				//���ʉ�
				m_koSE = NewGO<SoundSource>(0);
				m_koSE->Init(15);
				m_koSE->Play(false);
				m_koSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		else
		{
			//���ʉ����Đ����Ă��邩�H
			if (m_seFlag[State_KO] != true)
			{
				//���ʉ�
				m_koSE = NewGO<SoundSource>(0);
				m_koSE->Init(13);
				m_koSE->Play(false);
				m_koSE->SetVolume(0.6f);
				m_seFlag[State_KO] = true;
			}
		}
		//KO�\�����Ԃ�0.0�b�ɂȂ�����
		if (m_koTime < 0.0f)
		{
			m_koTime = 1.0f;
			m_koFlag = false;
			//�_�u��KO���\��������
			if (m_doubleKOFlag == true)
			{
				m_doubleKOFlag = false;
			}
			//�p�[�t�F�N�gKO���\��������
			else if(m_perfectKOFlag==true)
			{
				m_perfectKOFlag = false;
			}
			// 1P VS 2P �ł͂Ȃ��Ƃ�
			if (m_game->m_2playerFlag != true)
			{
				//���E���h���I������Ƃ��ɂ���A�j���[�V�������I������Ƃ�
				if ((((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //�p���`
					m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //�L�b�N
					(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) || //�n��U���܂��͋󒆍U��
					((m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Panch || //�p���`
						m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						(m_enemy->m_charaCon.IsOnGround() == true || m_enemy->m_charaCon.IsOnGround() != false))) && //�n��U���܂��͋󒆍U��
					((m_player->m_animationState == Player::EnAnimationState::enAnimationState_Lose &&
						m_player->m_player.IsPlayingAnimation() == false) || //���� 
						(m_enemy->m_animationState == Enemy::EnAnimationState::enAnimationState_Lose &&
							m_enemy->m_enemy.IsPlayingAnimation() == false)) //����
					)
				{
					m_roundState = State_Next;
				}
			}
			// 1P VS 2P �̂Ƃ�
			else if (m_game->m_2playerFlag == true)
			{
				//���E���h���I������Ƃ��ɂ���A�j���[�V�������I������Ƃ�
				if ((((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //�p���`
					m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //�L�b�N
					(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) || //�n��U���܂��͋󒆍U��
					((m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Panch || //�p���`
						m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						(m_player2->m_charaCon.IsOnGround() == true || m_player2->m_charaCon.IsOnGround() != false))) &&//�n��U���܂��͋󒆍U��
					((m_player->m_animationState == Player::EnAnimationState::enAnimationState_Lose &&
						m_player->m_player.IsPlayingAnimation() == false) || //����
						(m_player2->m_animationState == Player2::EnAnimationState::enAnimationState_Lose &&
							m_player2->m_player2.IsPlayingAnimation() == false)) //����
					)
				{
					m_roundState = State_Next;
				}
			}
		}
	}	
	//���E���h��Ԃ��^�C���A�b�v�̂Ƃ�
	else if (m_roundState == State_TimeUp)
	{
		m_timeUpTime -= 1.5f * g_gameTime->GetFrameDeltaTime();
		//���ʉ����Đ����Ă��邩�H
		if (m_seFlag[State_TimeUp] != true)
		{
			//���ʉ�
			m_koSE = NewGO<SoundSource>(0);
			m_koSE->Init(16);
			m_koSE->Play(false);
			m_koSE->SetVolume(0.6f);
			m_seFlag[State_TimeUp] = true;
		}
		//�^�C���A�b�v�\�����Ԃ�0.0�b�ɂȂ�����
		if (m_timeUpTime < 0.0f)
		{
			m_timeUpTime = 1.0f;
			m_timeUpFlag = false;
			// 1P VS 2P �ł͂Ȃ��Ƃ�
			if (m_game->m_2playerFlag != true)
			{
				//�ȉ��̍s�����Ă��Ȃ��Ƃ�
				if (m_player->m_animationState != Player::EnAnimationState::enAnimationState_Jump && //�W�����v
					m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Jump && //�W�����v
					((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //�p���`
						m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						m_player->m_charaCon.IsOnGround() != false) && //�n��U���܂��͋󒆍U��
					((m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Panch || //�p���`
						m_enemy->m_animationState != Enemy::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						(m_enemy->m_charaCon.IsOnGround() == true || m_enemy->m_charaCon.IsOnGround() != false)) //�n��U���܂��͋󒆍U��
					)
				{
					m_roundState = State_Next;
				}
			}
			// 1P VS 2P �̂Ƃ�
			else if (m_game->m_2playerFlag == true)
			{
				//�ȉ��̍s�����Ă��Ȃ��Ƃ�
				if (m_player->m_animationState != Player::EnAnimationState::enAnimationState_Jump && //�W�����v
					m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Jump &&//�W�����v
					((m_player->m_animationState != Player::EnAnimationState::enAnimationState_Panch || //�p���`
						m_player->m_animationState != Player::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						(m_player->m_charaCon.IsOnGround() == true || m_player->m_charaCon.IsOnGround() != false)) && //�n��U���܂��͋󒆍U��
					((m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Panch || //�p���`
						m_player2->m_animationState != Player2::EnAnimationState::enAnimationState_Kick) && //�L�b�N
						(m_player2->m_charaCon.IsOnGround() == true || m_player2->m_charaCon.IsOnGround() != false)) //�n��U���܂��͋󒆍U��
					)
				{
					m_roundState = State_Next;
				}
			}
			//m_roundState = State_Next;
		}
	}
}

bool Round::IsNoFighting()
{
	if (m_isWaitFadeout != true && m_battleFinishFlag != true)
	{
		//1P vs 2P �ł͂Ȃ��Ƃ�
		if (m_game->m_2playerFlag != true)
		{
			//���Ԑ؂�
			if (m_gametimer->m_time < 0.0f)
			{
				//�v���C���[��HP�̕��������Ƃ�
				if (m_player->m_playerHP > m_enemy->m_enemyHP)
				{
					//m_playerGetWin++;
					//m_playerNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_PlayerGetWIn;
					m_battleFinishFlag = true;
					m_1pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//�G��HP�̕��������Ƃ�
				else if (m_player->m_playerHP < m_enemy->m_enemyHP)
				{
					//m_enemyGetWin++;
					//m_enemyNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_EnemyGetWIn;
					m_battleFinishFlag = true;
					m_enemyGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//��������
				else if (m_player->m_playerHP == m_enemy->m_enemyHP)
				{
					m_roundState = State_TimeUp;
					//m_roundState = State_Draw;
					m_battleFinishFlag = true;
					m_getDrawFlag = true;
					m_timeUpFlag = true;
				}
				//return false;
				//�^�C���A�b�v���\��������
				if (m_timeUpFlag == true)
				{
					return true;
				}
			}
			//�v���C���[���������Ƃ�
			else if (m_enemy->m_enemyHP <= 0 && m_player->m_playerHP > 0)
			{
				//m_playerGetWin++;
				//m_playerNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_PlayerGetWIn;
				m_battleFinishFlag = true;
				m_1pGetWinFlag = true;
				m_koFlag = true;
				//�v���C���[�̗̑͂������Ă��Ȃ��Ƃ�
				if (m_player->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//�G���������Ƃ�
			else if (m_player->m_playerHP <= 0 && m_enemy->m_enemyHP > 0)
			{
				//m_enemyGetWin++;
				//m_enemyNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_EnemyGetWIn;
				m_battleFinishFlag = true;
				m_enemyGetWinFlag = true;
				m_koFlag = true;
				//�G�̗̑͂������Ă��Ȃ��Ƃ�
				if (m_enemy->m_enemyHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//��������
			else if (m_player->m_playerHP <= 0 && m_enemy->m_enemyHP <= 0)
			{
				m_roundState = State_KO;
				//m_roundState = State_Draw;
				m_battleFinishFlag = true;
				m_getDrawFlag = true;
				m_koFlag = true;
				m_doubleKOFlag = true;
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//���E���h��Ԃ����E���h�܂��̓t�@�C�g�̂Ƃ�
			else if (m_roundState == State_Round || m_roundState == State_Fight)
			{
				//return false;
				return true;
			}
			else
			{
				m_roundState = State_Fighting;
				//return true;
				return false;
			}
		}
		//1P vs 2P �̂Ƃ�
		else if (m_game->m_2playerFlag == true)
		{
			//���Ԑ؂�
			if (m_gametimer->m_time < 0.0f)
			{
				//�v���C���[��HP�̕��������Ƃ�
				if (m_player->m_playerHP > m_player2->m_playerHP)
				{
					//m_playerGetWin++;
					//m_playerNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_PlayerGetWIn;
					m_battleFinishFlag = true;
					m_1pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//�G��HP�̕��������Ƃ�
				else if (m_player->m_playerHP < m_player2->m_playerHP)
				{
					//m_enemyGetWin++;
					//m_enemyNoGetWin--;
					m_roundState = State_TimeUp;
					//m_roundState = State_EnemyGetWIn;
					m_battleFinishFlag = true;
					m_2pGetWinFlag = true;
					m_timeUpFlag = true;
				}
				//��������
				else if (m_player->m_playerHP == m_player2->m_playerHP)
				{
					m_roundState = State_TimeUp;
					//m_roundState = State_Draw;
					m_battleFinishFlag = true;
					m_getDrawFlag = true;
					m_timeUpFlag = true;
				}
				//return false;
				//�^�C���A�b�v���\��������
				if (m_timeUpFlag == true)
				{
					return true;
				}
			}
			//�v���C���[���������Ƃ�
			else if (m_player2->m_playerHP <= 0 && m_player->m_playerHP > 0)
			{
				//m_playerGetWin++;
				//m_playerNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_PlayerGetWIn;
				m_battleFinishFlag = true;
				m_1pGetWinFlag = true;
				m_koFlag = true;
				//�v���C���[�̗̑͂������Ă��Ȃ��Ƃ�
				if (m_player->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//�v���C���[2���������Ƃ�
			else if (m_player->m_playerHP <= 0 && m_player2->m_playerHP > 0)
			{
				//m_enemyGetWin++;
				//m_enemyNoGetWin--;
				m_roundState = State_KO;
				//m_roundState = State_EnemyGetWIn;
				m_battleFinishFlag = true;
				m_2pGetWinFlag = true;
				m_koFlag = true;
				//�v���C���[2�̗̑͂������Ă��Ȃ��Ƃ�
				if (m_player2->m_playerHP == 100)
				{
					m_perfectKOFlag = true;
				}
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//��������
			else if (m_player->m_playerHP <= 0 && m_player2->m_playerHP <= 0)
			{
				m_roundState = State_KO;
				//m_roundState = State_Draw;
				m_battleFinishFlag = true;
				m_getDrawFlag = true;
				m_koFlag = true;
				m_doubleKOFlag = true;
				//return false;
				//KO���\��������
				if (m_koFlag == true)
				{
					return true;
				}
			}
			//���E���h��Ԃ����E���h�܂��̓t�@�C�g�̂Ƃ�
			else if (m_roundState == State_Round || m_roundState == State_Fight)
			{
				//return false;
				return true;
			}
			else
			{
				m_roundState = State_Fighting;
				//return true;
				return false;
			}
		}
	}
}

void Round::Render(RenderContext& rc)
{
	////m_playerRoundIconD[0].Draw(rc);
	//m_playerRoundIconD[1].Draw(rc);
	////m_enemyRoundIconD[0].Draw(rc);
	//m_enemyRoundIconD[1].Draw(rc);	

	//m_playerRoundIconW[0].Draw(rc);
	////m_playerRoundIconW[1].Draw(rc);
	//m_enemyRoundIconW[0].Draw(rc);
	////m_enemyRoundIconW[1].Draw(rc);

	//for (int i = 0; i < 2; i++)
	//{
	//	//m_doubleKO[i].Draw(rc);
	//	//m_perfectKO[i].Draw(rc);
	//}

	//���E���h�`��
	if (m_roundFlag == true)
	{
		//�v���C���[�܂��͓G�܂��̓v���C���[2�̃��E���h�擾����0�̂Ƃ�
		if (m_playerGetWin==0&&(m_enemyGetWin==0||m_player2GetWin==0))
		{
			for (int i = 0; i < 2; i++)
			{
				//�t�@�C�i�����E���h�`��
				m_finalRound[i].Draw(rc);
			}
		}
		//���E���h�J�E���g��9�����̂Ƃ�
		else if(m_roundCount<9)
		{
			//���E���h1�`9�`��
			m_round[m_roundCount].Draw(rc);
		}
		//���E���h�J�E���g��8���傫���Ƃ�
		else if (m_roundCount>8)
		{
			//���E���h10�`�`��
			m_overround.Draw(rc);
		}
	}
	//�t�@�C�g�`��
	else if (m_fightFlag == true)
	{
		m_fight.Draw(rc);
	}
	//KO�`��
	else if (m_koFlag == true)
	{
		//�_�u��KO���\��������
		if (m_doubleKOFlag==true)
		{
			for (int i = 0; i < 2; i++)
			{
				m_doubleKO[i].Draw(rc);
			}
		}
		//�p�[�t�F�N�gKO���\��������
		else if(m_perfectKOFlag == true)
		{
			for (int i = 0; i < 2; i++)
			{
				m_perfectKO[i].Draw(rc);
			}
		}
		else
		{
			m_ko.Draw(rc);
		}
	}
	//�^�C���A�b�v�`��
	else if (m_timeUpFlag == true)
	{
		m_timeUp.Draw(rc);
	}

	//�v���C���[�f�t�H���g���E���h�A�C�R���`��
	if (m_playerNoGetWin != 0)
	{
		for (int i = m_playerNoGetWin; i > 0; i--)
		{
			m_playerRoundIconD[i + m_playerGetWin].Draw(rc);
		}
	}
	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�G�f�t�H���g���E���h�A�C�R���`��
		if (m_enemyNoGetWin != 0)
		{
			for (int i = m_enemyNoGetWin; i > 0; i--)
			{
				m_enemyRoundIconD[i + m_enemyGetWin].Draw(rc);
			}
		}
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�v���C���[2�f�t�H���g���E���h�A�C�R���`��
		if (m_player2NoGetWin != 0)
		{
			for (int i = m_player2NoGetWin; i > 0; i--)
			{
				m_player2RoundIconD[i + m_player2GetWin].Draw(rc);
			}
		}
	}

	//�v���C���[�������E���h�A�C�R���`��
	if (m_playerGetWin != -1)
	{
		for (int i = 0; i <= m_playerGetWin; i++)
		{
			m_playerRoundIconW[i].Draw(rc);
		}
	}
	// 1P VS 2P �ł͂Ȃ��Ƃ�
	if (m_game->m_2playerFlag != true)
	{
		//�G�������E���h�A�C�R���`��
		if (m_enemyGetWin != -1)
		{
			for (int i = 0; i <= m_enemyGetWin; i++)
			{
				m_enemyRoundIconW[i].Draw(rc);
			}
		}
	}
	// 1P VS 2P �̂Ƃ�
	else if (m_game->m_2playerFlag == true)
	{
		//�v���C���[2�������E���h�A�C�R���`��
		if (m_player2GetWin != -1)
		{
			for (int i = 0; i <= m_player2GetWin; i++)
			{
				m_player2RoundIconW[i].Draw(rc);
			}
		}
	}
}