#include "stdafx.h"
#include "Player2.h"
#include "Game.h"
#include "Player.h"
#include "Frame.h"
#include "GameTimer.h"
#include "Round.h"
#include "GameCamera.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

#include "collision/CollisionObject.h"

Player2::Player2()
{

}

Player2::~Player2()
{

}

bool Player2::Start()
{
	//0.�ҋ@�A�j���[�V����
	m_animationClips[enAnimationClip_Idle].Load("Assets/animation/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//1.�W�����v�A�j���[�V����
	m_animationClips[enAnimationClip_Jump].Load("Assets/animation/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//2.�O�ړ��A�j���[�V����
	m_animationClips[enAnimationClip_Walk_Forward].Load("Assets/animation/walk_forward1.tka");
	m_animationClips[enAnimationClip_Walk_Forward].SetLoopFlag(true);
	//3.���ړ��A�j���[�V����
	m_animationClips[enAnimationClip_Walk_Back].Load("Assets/animation/walk_back1.tka");
	m_animationClips[enAnimationClip_Walk_Back].SetLoopFlag(true);
	//4.�O�X�e�b�v�A�j���[�V����
	m_animationClips[enAnimationClip_Step_Forward].Load("Assets/animation/step_forward1.tka");
	m_animationClips[enAnimationClip_Step_Forward].SetLoopFlag(false);
	//5.���X�e�b�v�A�j���[�V����
	m_animationClips[enAnimationClip_Step_Back].Load("Assets/animation/step_back1.tka");
	m_animationClips[enAnimationClip_Step_Back].SetLoopFlag(false);
	//6.�p���`�A�j���[�V����
	m_animationClips[enAnimationClip_Panch].Load("Assets/animation/panch.tka");
	m_animationClips[enAnimationClip_Panch].SetLoopFlag(false);
	//7.�󒆃p���`�A�j���[�V����
	m_animationClips[enAnimationClip_Panch_Jump].Load("Assets/animation/panch_jump.tka");
	m_animationClips[enAnimationClip_Panch_Jump].SetLoopFlag(false);
	//8.�p���`�K�[�h�A�j���[�V����
	m_animationClips[enAnimationClip_Panch_Guard].Load("Assets/animation/panch_guard.tka");
	m_animationClips[enAnimationClip_Panch_Guard].SetLoopFlag(false);
	//9.�p���`�_���[�W�A�j���[�V����
	m_animationClips[enAnimationClip_Panch_Damage].Load("Assets/animation/panch_damage.tka");
	m_animationClips[enAnimationClip_Panch_Damage].SetLoopFlag(false);
	//10.�L�b�N�A�j���[�V����
	m_animationClips[enAnimationClip_Kick].Load("Assets/animation/kick.tka");
	m_animationClips[enAnimationClip_Kick].SetLoopFlag(false);
	//11.�󒆃L�b�N�A�j���[�V����
	m_animationClips[enAnimationClip_Kick_Jump].Load("Assets/animation/kick_jump.tka");
	m_animationClips[enAnimationClip_Kick_Jump].SetLoopFlag(false);
	//12.�L�b�N�K�[�h�A�j���[�V����
	m_animationClips[enAnimationClip_Kick_Guard].Load("Assets/animation/kick_guard.tka");
	m_animationClips[enAnimationClip_Kick_Guard].SetLoopFlag(false);
	//13.�L�b�N�_���[�W�A�j���[�V����
	m_animationClips[enAnimationClip_Kick_Damage].Load("Assets/animation/kick_damage.tka");
	m_animationClips[enAnimationClip_Kick_Damage].SetLoopFlag(false);
	//14.�󒆃_���[�W�A�j���[�V����
	m_animationClips[enAnimationClip_Fly_Damage].Load("Assets/animation/fly_damage.tka");
	m_animationClips[enAnimationClip_Fly_Damage].SetLoopFlag(false);
	//15.�����A�j���[�V����
	m_animationClips[enAnimationClip_Win].Load("Assets/animation/win.tka");
	m_animationClips[enAnimationClip_Win].SetLoopFlag(false);
	//16.�����A�j���[�V����
	m_animationClips[enAnimationClip_Lose].Load("Assets/animation/lose.tka");
	m_animationClips[enAnimationClip_Lose].SetLoopFlag(false);
	//17.���Ԑ؂ꎞ�̕����A�j���[�V����
	m_animationClips[enAnimationClip_Lose_TimeUp].Load("Assets/animation/lose_timeup.tka");
	m_animationClips[enAnimationClip_Lose_TimeUp].SetLoopFlag(false);
	//18.���������A�j���[�V����
	m_animationClips[enAnimationClip_Draw].Load("Assets/animation/lose_timeup.tka");
	m_animationClips[enAnimationClip_Draw].SetLoopFlag(false);

	//m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	//m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	//m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	//m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	//m_player.Init("Assets/modelData/character/1P.tkm", m_animationClips, enAnimationClip_Num);
	//m_player.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_player2.Init("Assets/modelData/character/2P.tkm", m_animationClips, enAnimationClip_Num);

	//�����ʒu
	if (m_initSide == enSideState_Left)
	{
		m_position = { -100.0f,0.0f,0.0f };
	}
	else if (m_initSide == enSideState_Right)
	{
		m_position = { 100.0f,0.0f,0.0f };
	}

	//�v���C���[2�̏����ʒu��ݒ�
	m_player2.SetPosition(m_position);
	m_charaCon.Init(10.0f, 50.0f, m_position);
	m_player2.Update();

	//�A�j���[�V�����C�x���g
	m_player2.AddAnimationEvent([&](const wchar_t* clipName, const wchar_t* eventName) {
		OnAnimationEvent(clipName, eventName);
	});

	//���ʉ�
	g_soundEngine->ResistWaveFileBank(5, "Assets/SE/attack.wav");
	g_soundEngine->ResistWaveFileBank(6, "Assets/SE/guard.wav");

	//�C���X�^���X
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	m_frame = FindGO<Frame>("frame");
	m_round = FindGO<Round>("round");
	m_gameCamera = FindGO<GameCamera>("gamecamera");

	return true;
}

void Player2::Update()
{
	//HP��0�܂��͎��Ԑ؂�ɂȂ����珈�����Ȃ�
	//if (m_round->IsFighting() != false)
	if (m_round->IsNoFighting() != true)
	{
		//�L�����N�^�[����
		Move();

		//�t���[���Ǘ�
		FrameManage();

		//�����蔻��
		Collision();

		//�U��
		Attack();
	}
	//���E���h���I�������
	else if (m_round->m_roundState == Round::EnRoundState::State_KO || //�����I��
			 m_round->m_roundState == Round::EnRoundState::State_TimeUp //�^�C���A�b�v
		    )
	{
		//KO���\�����Ă��Ȃ��Ƃ�
		if (m_round->m_koFlag != true)
		{
			//�n�ʂɕt���Ă��Ȃ����H
			if (m_charaCon.IsOnGround() == false)
			{
				m_moveSpeed.y -= 25.0f;
			}
			m_moveSpeed.x = 0.0f;
			m_position = m_charaCon.Execute(m_moveSpeed, g_gameTime->GetFrameDeltaTime());
			m_player2.SetPosition(m_position);
		}
	}

	//�L�����N�^�[��]
	Rotation();

	//�A�j���[�V�����Ǘ�
	ManageState();

	//�A�j���[�V����
	PlayAnimation();

	//���f���X�V
	m_player2.Update();
}

void Player2::Move()
{
	//����
	m_distance = m_player->m_position - m_position;

	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	m_stickL.x = g_pad[m_gamepadNo]->GetLStickXF();
	m_stickL.y = g_pad[m_gamepadNo]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	forward *= m_stickL.y * 120.0f;
	right *= m_stickL.x * 120.0f;

	//�ȉ��̍s�����Ă��Ȃ��Ƃ��ړ����ł���
	if ((m_stepAnimationFlagRight != true && m_stepAnimationFlagLeft != true) && //�X�e�b�v
		(m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
		(m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //�󒆍U��
		(m_upGuardFlag != true && m_downGuardFlag != true) && //�K�[�h
		(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
		)
	{
		m_moveSpeed += right;
	}

	//���̂̏���
	//�ړ�
	if (m_moveDirectionState == enMoveState_Left || //���X�e�B�b�N�����ɓ|��
		m_moveDirectionState == enMoveState_Right   //���X�e�B�b�N���E�ɓ|��
		)
	{
		//�n�ʂɕt���Ă���Ƃ�
		if (m_charaCon.IsOnGround())
		{
			if (m_distance.Length() <= 20.0f)
			{
				//�v���C���[����ʒ[�ɍs���Ă��Ȃ����H
				if (m_player->m_noMove != true)
				{
					//�v���C���[2���E���ɂ���Ƃ�
					if (m_player->m_position.x < m_position.x)
					{
						//�v���C���[�����ɉ���
						m_player->m_position.x -= 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
					//�v���C���[2�������ɂ���Ƃ�
					else
					{
						//�v���C���[���E�ɉ���
						m_player->m_position.x += 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
				}
			}
		}
	}
	//����
	else
	{
		//�n�ʂɕt���Ă���Ƃ�
		if (m_charaCon.IsOnGround())
		{
			if (m_distance.Length() <= 20.0f)
			{
				//�ȉ��̏����ɂȂ��Ă�����v���C���[����ʒ[�܂ōs���ăv���C���[2���v���C���[�Ɍ����ăW�����v�����Ƃ���������
				if (m_player->m_noMove == true && //�v���C���[����ʒ[�ɍs�������H
					m_moveFlag != true && // ���̂��ړ����Ă��Ȃ����H
					m_moveJumpFlag == true // �W�����v���Ă��邩�H
				    )
				{
					//�v���C���[2���E���ɂ���Ƃ�
					if (m_rotationLeftFlag == true)
					{
						//�E�֔���
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					//�v���C���[2�������ɂ���Ƃ�
					else if (m_rotationRightFlag == true)
					{
						//���֔���
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					m_moveFlag = false;
				}
				else if (fabsf(m_position.x) > 530.0f && //��ʒ[����߂����H
					m_moveFlag != true && //���̂��ړ����Ă��Ȃ����H
					m_moveJumpFlag == true //�W�����v���Ă��邩�H
					)
				{
					Vector3 distance = Vector3::Zero;
					Vector3 move = m_repulsion;
					distance.x = m_position.x - m_player->m_position.x;
					m_player->m_position.x = m_player->m_position.x + (move.x + distance.x);
					m_player->m_charaCon.SetPosition(m_player->m_position);
					m_player->m_player.SetPosition(m_player->m_position);
					m_moveFlag = true;
					m_moveJumpFlag = false;
				}
				m_moveFlag = false;
			}
		}
		//�n�ʂɕt���Ă��Ȃ��Ƃ�
		else if (m_charaCon.IsOnGround() == false)
		{
			m_moveJumpFlag = true;
			if (m_distance.Length() <= 20.0f)
			{
				//�v���C���[����ʒ[�܂ōs���Ă��Ȃ��Ƃ��v���C���[2���v���C���[�Ɍ����ăW�����v�����Ƃ���������
				if (m_player->m_noMove != true &&
					fabsf(m_position.x) <= 530.0f //��ʒ[���痣��Ă��邩�H
					)
				{
					//�v���C���[2���E���ɂ���Ƃ�
					if (m_player->m_position.x < m_position.x)
					{
						//�E�֔���
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
					//�v���C���[2�������ɂ���Ƃ�
					else
					{
						//���֔���
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
				}
			}
		}
	}

	//�n�ʂɕt���Ă���Ƃ�
	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;
		//if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	moveSpeed.y = 250.0f;
		//}

		//�W�����v
		//�ȉ��̍s�����Ă��Ȃ��Ƃ��W�����v���ł���
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
			)
		{
			//if (m_stickL.y > 0.001f)
			//{
			//	m_moveSpeed.y = 500.0f;
			//}

			//�ύX��
			//�W�����v
			if (m_moveDirectionState == enMoveState_Left_Up || //����
				m_moveDirectionState == enMoveState_Up || //��
				m_moveDirectionState == enMoveState_Right_Up //�E��
			    )
			{
				m_moveSpeed.y = 525.0f;
				//m_moveSpeed.y = 500.0f;
			}
		}

		//���Ⴊ��
		//if (m_stickL.y < 0.0f)
		//{
		//	m_moveSpeed.x = 0.0f;
		//}	
		
		//�ύX��
		//���Ⴊ��
		if (m_moveDirectionState == enMoveState_Left_Down || //����
			m_moveDirectionState == enMoveState_Down || //��
			m_moveDirectionState == enMoveState_Right_Down //�E��
		   )
		{
			m_moveSpeed.x = 0.0f;
		}

		
		//if ((m_stickL.x > 0.001f && m_stickL.y == 0.0f))
		//{
		//	m_pushLeftFlag = false;
		//}
		//else if ((m_stickL.x < 0.0f && m_stickL.y == 0.0f))
		//{
		//	m_pushRightFlag = false;
		//}

		//�ύX��
		//�E
		if (m_moveDirectionState == enMoveState_Right)
		{
			m_pushLeftFlag = false;
		}
		//��
		else if (m_moveDirectionState == enMoveState_Left)
		{
			m_pushRightFlag = false;
		}
		//�����E���E�E��
		else if (m_moveDirectionState == enMoveState_Left_Down || m_moveDirectionState == enMoveState_Down || m_moveDirectionState == enMoveState_Right_Down)
		{
			m_pushLeftFlag = false;
			m_pushRightFlag = false;
		}

		//�U�����Ă��Ȃ��Ƃ��X�e�b�v���ł���
		if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
		{
			//�E�X�e�b�v
			if (m_moveDirectionState == enMoveState_Right)
			{
				//�ړ�
				m_pushRightFlag = true;
				//���߂Ĉړ�����
				m_startFlag = true;
				//�v���O�����ύX���Ȃ�
				//�t���[���̕ۊ�(�E)
				m_frameMemoryLeft = 0.0f;
				m_frameMemoryRight = m_frame->m_player2frame[1];

				//�X�e�b�v�t���O��true�̎�
				if (m_frameMemoryRight < m_frame->GetFrame(7.0f) && m_stepFlagRight == 1)
				{
					//�X�e�b�v
					m_stepFlagRight = 2;
				}
				else
				{
					//�ҋ@
					m_stepFlagRight = 0;
				}
			}
			//���X�e�b�v
			else if (m_moveDirectionState == enMoveState_Left)
			{
				//�ړ�
				m_pushLeftFlag = true;
				//���߂Ĉړ�����
				m_startFlag = true;
				//�v���O�����ύX���Ȃ�
				//�t���[���̕ۊ�(��)
				m_frameMemoryRight = 0.0f;
				m_frameMemoryLeft = m_frame->m_player2frame[4];

				//�X�e�b�v�t���O��true�̎�
				if (m_frameMemoryLeft < m_frame->GetFrame(7.0f) && m_stepFlagLeft == 1)
				{
					//�X�e�b�v
					m_stepFlagLeft = 2;
				}
				else
				{
					//�ҋ@
					m_stepFlagLeft = 0;
				}
			}
			else
			{
				//���߂Ĉړ�������
				if (m_startFlag == true)
				{
					//�E�������Ă��邩�H
					if (m_pushRightFlag == true)
					{
						m_stepFlagLeft = 0;
						//10F�ȓ���
						if (m_frameMemoryRight < m_frame->GetFrame(10.0f))
						{
							//10F�ȓ���
							if (m_frame->m_player2frame[0] < m_frame->GetFrame(10.0f))
							{
								m_stepFlagRight = 1;
							}
							else
							{
								m_stepFlagRight = 0;
							}
						}
					}
					//���������Ă��邩�H
					else if (m_pushLeftFlag == true)
					{
						m_stepFlagRight = 0;
						//10F�ȓ���
						if (m_frameMemoryLeft < m_frame->GetFrame(10.0f))
						{
							//10F�ȓ���
							if (m_frame->m_player2frame[0] < m_frame->GetFrame(10.0f))
							{
								m_stepFlagLeft = 1;
							}
							else
							{
								m_stepFlagLeft = 0;
							}
						}
					}
					else
					{
						m_stepFlagRight = 0;
						m_stepFlagLeft = 0;
					}
				}
			}

			//�E�X�e�b�v
			if (m_stepFlagRight == 2)
			{
				m_frame->m_frameDash += g_gameTime->GetFrameDeltaTime();
				m_moveSpeed.x += 1500.0f;

				m_frameMemoryDefault = 0.0f;
				m_stepFlagRight = 0;
				m_frame->m_frameDash = 0.0f;
				m_stepAnimationFlagRight = true;
			}
			//���X�e�b�v
			else if (m_stepFlagLeft == 2)
			{
				m_frame->m_frameDash += g_gameTime->GetFrameDeltaTime();
				m_moveSpeed.x -= 1500.0f;

				m_frameMemoryDefault = 0.0f;
				m_stepFlagLeft = 0;
				m_frame->m_frameDash = 0.0f;
				m_stepAnimationFlagLeft = true;
			}
		}
	}
	//�n�ʂɕt���ĂȂ��Ƃ�
	else
	{
		m_pushRightFlag = false;
		m_pushLeftFlag = false;
		m_moveSpeed.y -= 30.0f;
		//m_moveSpeed.y -= 25.0f;
	}

	//��ʒ[�ɍs�������̈ړ�
	//�v���C���[2���E���ɂ���Ƃ�
	if (m_player->m_position.x < m_position.x)
	{
		//�E
		if (m_moveDirectionState == enMoveState_Right || m_moveDirectionState == enMoveState_Right_Up)
		{
			//��ʒ[�ɍs������
			if (m_noMove == true)
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != false)
				{
					if (m_charaCon.GetPosition().x >= 550.0f)
					{
						m_position = { 550.0f,0.0f,0.0f };
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
				}
				else if (m_charaCon.GetPosition().x > -550.0f && m_charaCon.GetPosition().x < 550.0f)
				{
					m_position = m_noMovePosition;
					m_charaCon.SetPosition(m_position);
					m_player2.SetPosition(m_position);
				}
				m_moveSpeed.x = 0.0f;
			}
		}
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		//��
		if (m_moveDirectionState == enMoveState_Left || m_moveDirectionState == enMoveState_Left_Up)
		{
			//��ʒ[�ɍs������
			if (m_noMove == true)
			{
				//�n�ʂɕt���Ă�Ƃ�
				if (m_charaCon.IsOnGround() != false)
				{
					if (m_charaCon.GetPosition().x <= -550.0f)
					{
						m_position = { -550.0f,0.0f,0.0f };
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
				}
				else if (m_charaCon.GetPosition().x > -550.0f && m_charaCon.GetPosition().x < 550.0f)
				{
					m_position = m_noMovePosition;
					m_charaCon.SetPosition(m_position);
					m_player2.SetPosition(m_position);
				}
				m_moveSpeed.x = 0.0f;
			}
		}
	}

	m_position = m_charaCon.Execute(m_moveSpeed, 1.0f / 60.0f/*g_gameTime->GetFrameDeltaTime()*/);
	if (m_noMove != true)
	{
		m_noMovePosition = m_position;
	}

	//��ʒ[
	if (m_position.x > -550.0f && m_position.x < 550.0f)
	{
		if (m_gameCamera->m_movePos.x <= -100.0f)
		{
			m_noMove = true;
		}
		else
		{
			m_noMove = false;
		}
	}
	//�E��ʒ[
	else if (m_position.x >= 550.0f)
	{
		m_noMove = true;
		m_repulsion.x = -20.0f;
	}
	//����ʒ[
	else if (m_position.x <= -550.0f)
	{
		m_noMove = true;
		m_repulsion.x = 20.0f;
	}
	//��ʒ[�ł͂Ȃ��Ƃ�
	else
	{
		m_noMove = false;
		m_repulsion.x = 0.0f;
	}

	//z���Œ�
	m_position.z = 0.0f;
	m_player2.SetPosition(m_position);
}

void Player2::FrameManage()
{
	//�z��̗v�f��
	//0:�ҋ@
	//1:�E
	//2:�΂߉E��
	//3:�΂߉E��
	//4:��
	//5:�΂ߍ���
	//6:�΂ߍ���
	//7:��
	//8:��

	//if (m_stickL.y == -1.0f) //8:��
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Down;
	//	//m_frame->m_state = 8;
	//	m_frame->m_tenkey = 2;
	//}

	//else if (m_stickL.y == 1.0f) //7:��
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Up;
	//	//m_frame->m_state = 7;
	//	m_frame->m_tenkey = 8;
	//}

	//else if ((m_stickL.x<0.0f && m_stickL.x>-1.0f) && (m_stickL.y<0.0f && m_stickL.y>-1.0f)) //6:�΂ߍ���
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left_Down;
	//	//m_frame->m_state = 6;
	//	m_frame->m_tenkey = 1;
	//}

	//else if ((m_stickL.x<0.0f && m_stickL.x>-1.0f) && (m_stickL.y > 0.0f && m_stickL.y < 1.0f)) //5:�΂ߍ���
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left_Up;
	//	//m_frame->m_state = 5;
	//	m_frame->m_tenkey = 7;
	//}

	//else if (m_stickL.x == -1.0f) //4:��
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left;
	//	//m_frame->m_state = 4;
	//	m_frame->m_tenkey = 4;
	//}

	//else if ((m_stickL.x > 0.0f && m_stickL.x < 1.0f) && (m_stickL.y<0.0f && m_stickL.y>-1.0f)) //3:�΂߉E��
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right_Down;
	//	//m_frame->m_state = 3;
	//	m_frame->m_tenkey = 3;
	//}

	//else if ((m_stickL.x > 0.0f && m_stickL.x < 1.0f) && (m_stickL.y > 0.0f && m_stickL.y < 1.0f)) //2:�΂߉E��
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right_Up;
	//	//m_frame->m_state = 2;
	//	m_frame->m_tenkey = 9;
	//}

	//else if (m_stickL.x == 1.0f) //1:�E
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right;
	//	//m_frame->m_state = 1;
	//	m_frame->m_tenkey = 6;
	//}

	//else //0:�ҋ@
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Idle;
	//	//m_frame->m_state = 0;
	//	m_frame->m_tenkey = 5;
	//}

	//�ύX��_�Z
	if (((m_stickL.x >= 0.0f && m_stickL.x < 0.4f) || (m_stickL.x <= 0.0f && m_stickL.x > -0.4f)) && //x��
		(m_stickL.y <= -0.7f && m_stickL.y >= -1.0f) //y��
	   ) //8:��
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Down;
		//m_frame->m_state = 8;
		m_frame->m_player2tenkey = 2;
		m_moveDirectionState = enMoveState_Down;
	}
	//�ύX��_�Z
	else if (((m_stickL.x >= 0.0f && m_stickL.x < 0.4f) || (m_stickL.x <= 0.0f && m_stickL.x > -0.4f)) && //x��
		     (m_stickL.y >= 0.7f && m_stickL.y <= 1.0f) //y��
		    ) //7:��
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Up;
		//m_frame->m_state = 7;
		m_frame->m_player2tenkey = 8;
		m_moveDirectionState = enMoveState_Up;
	}
	//�ύX��
	else if ((m_stickL.x <= -0.4f && m_stickL.x > -1.0f) && //x��
			 (m_stickL.y <= -0.4f && m_stickL.y > -1.0f) //y��
			) //6:�΂ߍ���
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left_Down;
		//m_frame->m_state = 6;
		m_frame->m_player2tenkey = 1;
		m_moveDirectionState = enMoveState_Left_Down;
	}
	//�ύX��
	else if ((m_stickL.x <= -0.4f && m_stickL.x > -1.0f) && //x��
			 (m_stickL.y >= 0.4f && m_stickL.y < 1.0f) //y��
			) //5:�΂ߍ���
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left_Up;
		//m_frame->m_state = 5;
		m_frame->m_player2tenkey = 7;
		m_moveDirectionState = enMoveState_Left_Up;
	}
	//�ύX��_�Z
	else if ((m_stickL.x <= -0.7f && m_stickL.x >= -1.0f) && //x��
			 ((m_stickL.y >= 0.0f && m_stickL.y < 0.4f) || (m_stickL.y <= 0.0f && m_stickL.y > -0.4f)) //y��
		    ) //4:��
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left;
		//m_frame->m_state = 4;
		m_frame->m_player2tenkey = 4;
		m_moveDirectionState = enMoveState_Left;
	}
	//�ύX��
	else if ((m_stickL.x >= 0.4f && m_stickL.x < 1.0f) && //x��
			 (m_stickL.y <= -0.4f && m_stickL.y > -1.0f) //y��
		    ) //3:�΂߉E��
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right_Down;
		//m_frame->m_state = 3;
		m_frame->m_player2tenkey = 3;
		m_moveDirectionState = enMoveState_Right_Down;
	}
	//�ύX��
	else if ((m_stickL.x >= 0.4f && m_stickL.x < 1.0f) && //x��
			 (m_stickL.y >= 0.4f && m_stickL.y < 1.0f) //y��
		    ) //2:�΂߉E��
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right_Up;
		//m_frame->m_state = 2;
		m_frame->m_player2tenkey = 9;
		m_moveDirectionState = enMoveState_Right_Up;
	}
	//�ύX��_�Z
	else if ((m_stickL.x >= 0.7f && m_stickL.x <= 1.0f) && //x��
			 ((m_stickL.y >= 0.0f && m_stickL.y < 0.4f) || (m_stickL.y <= 0.0f && m_stickL.y > -0.4f)) //y��
		    ) //1:�E
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right;
		//m_frame->m_state = 1;
		m_frame->m_player2tenkey = 6;
		m_moveDirectionState = enMoveState_Right;
	}
	//�ύX��_�Z
	else //0:�ҋ@
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Idle;
		//m_frame->m_state = 0;
		m_frame->m_player2tenkey = 5;
		m_moveDirectionState = enMoveState_Idle;
	}
}

void Player2::Rotation()
{
	//�ȉ��̏����ɂȂ��Ă�����������Œ肵�Ȃ�
	if (m_charaCon.IsOnGround() != false && //�n�ʂɂ��Ă���
		m_player->m_noMove != true //��ʒ[�܂ōs���Ă��Ȃ�
		)
	{
		m_rotationKeepFlag = false; //�������Œ肵�Ȃ�
	}

	//�v���C���[2���E���ɂ���Ƃ�
	if (m_player->m_position.x < m_position.x)
	{
		//�ȉ��̏����ɂȂ��Ă����������ς��鎖���ł���
		if (((m_panchAnimationFlag != true || m_kickAnimationFlag != true) || //�U��
			(m_flyingPanchAnimationFlag != true || m_flyingKickAttackCollision != true)) && //�󒆍U��
			m_rotationKeepFlag != true //�������Œ肵�Ă��Ȃ�
			)
		{
			if (m_charaCon.IsOnGround() != false)
			{
				m_rotation.SetRotationDegY(-90.0f);
			}
		}
		if (m_animationState == enAnimationState_Win)
		{
			m_rotation.SetRotationDegY(-180.0f);
		}
		else if (m_animationState == enAnimationState_Lose_TimeUp)
		{
			m_rotation.SetRotationDegY(-180.0f);
		}
		else if (m_animationState == enAnimationState_Draw)
		{
			m_rotation.SetRotationDegY(-180.0f);
		}
		if (m_rotationKeepFlag != true)
		{
			//�X�e�B�b�N�̕������ȉ��̕����Ɍ����Ă��Ȃ�������
			if (m_moveDirectionState != enMoveState_Left_Up && //����
				m_moveDirectionState != enMoveState_Up //��
				)
			{
				m_rotationLeftFlag = true; //���������Ă���
				m_rotationRightFlag = false; //�E�������Ă���
				m_rotationKeepFlag = true; //�������Œ肷��
			}
		}
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		//�ȉ��̏����ɂȂ��Ă����������ς��鎖���ł���
		if (((m_panchAnimationFlag != true || m_kickAnimationFlag != true) || //�U��
			(m_flyingPanchAnimationFlag != true || m_flyingKickAttackCollision != true)) && //�󒆍U��
			m_rotationKeepFlag != true //�������Œ肵�Ă��Ȃ�
			)
		{
			if (m_charaCon.IsOnGround() != false)
			{
				m_rotation.SetRotationDegY(90.0f);
			}
		}
		if (m_animationState == enAnimationState_Win)
		{
			m_rotation.SetRotationDegY(180.0f);
		}
		else if (m_animationState == enAnimationState_Lose_TimeUp)
		{
			m_rotation.SetRotationDegY(180.0f);
		}
		else if (m_animationState == enAnimationState_Draw)
		{
			m_rotation.SetRotationDegY(180.0f);
		}
		if (m_rotationKeepFlag != true)
		{
			//�X�e�B�b�N�̕������ȉ��̕����Ɍ����Ă��Ȃ�������
			if (m_moveDirectionState != enMoveState_Right_Up && //�E��
				m_moveDirectionState != enMoveState_Up //��
				)
			{
				m_rotationRightFlag = true; //�E�������Ă���
				m_rotationLeftFlag = false; //���������Ă���
				m_rotationKeepFlag = true; //�������Œ肷��
			}
		}
	}
	m_player2.SetRotation(m_rotation);
}

void Player2::Collision()
{
	if (m_animationState == enAnimationState_Damage ||
		m_animationState == enAnimationState_Guard
		)
	{
		return;
	}

	//��i
	const auto& panchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_attack");
	const auto& flyingPanchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_jump_attack");
	const auto& flyingKickCollision = g_collisionObjectManager->FindCollisionObject("player_kick_jump_attack");
	if (panchCollision->IsHit(m_charaCon) || //�p���`
		flyingPanchCollision->IsHit(m_charaCon) || //�󒆃p���`
		flyingKickCollision->IsHit(m_charaCon) //�󒆃L�b�N
	   )
	{
		//�K�[�h
		//�v���C���[2���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			//�ȉ��̍s�����Ă��Ȃ��Ƃ���i�K�[�h���ł���
			if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
				m_upGuardFlag != true && //��i�K�[�h
				m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
				)
			{
				//if (m_stickL.x > 0.001f)
				//�ύX��
				if (m_moveDirectionState == enMoveState_Right)
				{
					m_upGuardFlag = true;
					//m_panchAttack = false;
					m_collisionHitFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}
		//�v���C���[2�������ɂ���Ƃ�
		else
		{
			//�ȉ��̍s�����Ă��Ȃ��Ƃ���i�K�[�h���ł���
			if (m_panchAnimationFlag != true && m_kickAnimationFlag != true && //�U��
				m_upGuardFlag != true && //��i�K�[�h
				m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
				)
			{
				//if (m_stickL.x < 0.0f)
				//�ύX��
				if (m_moveDirectionState == enMoveState_Left)
				{
					m_upGuardFlag = true;
					//m_panchAttack = false;
					m_collisionHitFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}

		//�_���[�W
		if (m_targetAttackFlag != true && //�_���[�W�H�������
			m_upGuardFlag != true //��i�K�[�h
			)
		{
			m_playerHP =
				TargetAttack(m_playerHP, 5);
			//�v���C���[2���E���ɂ���Ƃ�
			if (m_player->m_position.x < m_position.x)
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != true)
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x += 60.0f;
					}
				}
				//�n�ʂɕt���Ă�Ƃ�
				else
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x += 25.0f;
					}
				}
			}
			//�v���C���[2�������ɂ���Ƃ�
			else
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != true)
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x -= 60.0f;
					}
				}
				//�n�ʂɕt���Ă���Ƃ�
				else
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x -= 25.0f;
					}
				}
			}
			m_charaCon.SetPosition(m_position);
			m_player2.SetPosition(m_position);

			//�E
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}
			//��
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}

			//�n�ʂɕt���Ă�Ƃ�
			if (m_charaCon.IsOnGround())
			{
				m_upDamageFlag = true;
			}
			//�n�ʂɕt���Ă��Ȃ��Ƃ�
			else
			{
				m_flyDamageFlag = true;
			}
			m_targetAttackFlag = true;
			m_collisionHitFlag = true;
			//m_panchAttack = false;
			//���ʉ�
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(5);
			se->Play(false);
			se->SetVolume(1.0f);
			return;
		}
	}

	//���i
	const auto& kickCollision = g_collisionObjectManager->FindCollisionObject("player_kick_attack");
	if (kickCollision->IsHit(m_charaCon) //�L�b�N
		)
	{
		//�K�[�h
		//�v���C���[2���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			//�ȉ��̍s�����Ă��Ȃ��Ƃ����i�K�[�h���ł���
			if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
				m_downGuardFlag != true && //���i�K�[�h
				m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
				)
			{
				//if (m_stickL.x == 0.5f && m_stickL.y == -0.5f)
				//�ύX��
				if (m_moveDirectionState == enMoveState_Right_Down)
				{
					m_downGuardFlag = true;
					//m_kickAttack = false;
					m_collisionHitFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}
		//�v���C���[2�������ɂ���Ƃ�
		else
		{
			//�ȉ��̍s�����Ă��Ȃ��Ƃ����i�K�[�h���ł���
			if (m_panchAnimationFlag != true && m_kickAnimationFlag != true && //�U��
				m_downGuardFlag != true && //���i�K�[�h
				m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
				)
			{
				//if (m_stickL.x == -0.5f && m_stickL.y == -0.5f)
				//�ύX��
				if (m_moveDirectionState == enMoveState_Left_Down)
				{
					m_downGuardFlag = true;
					//m_kickAttack = false;
					m_collisionHitFlag = true;
					//���ʉ�
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}

		//�_���[�W
		if (m_targetAttackFlag != true && //�_���[�W�H�������
			m_downGuardFlag != true //���i�K�[�h
			)
		{
			m_playerHP =
				TargetAttack(m_playerHP, 10);
			//�v���C���[2���E���ɂ���Ƃ�
			if (m_player->m_position.x < m_position.x)
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != true)
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x += 60.0f;
					}
				}
				//�n�ʂɕt���Ă���Ƃ�
				else
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x += 25.0f;
					}
				}
			}
			//�v���C���[2�������ɂ���Ƃ�
			else
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != true)
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x -= 60.0f;
					}
				}
				//�n�ʂɕt���Ă���Ƃ�
				else
				{
					//��ʒ[�ɍs���Ă��Ȃ��Ƃ�
					if (m_noMove != true)
					{
						//�m�b�N�o�b�N
						m_position.x -= 25.0f;
					}
				}
			}
			m_charaCon.SetPosition(m_position);
			m_player2.SetPosition(m_position);

			//�E
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}
			//��
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}

			//�n�ʂɕt���Ă�Ƃ�
			if (m_charaCon.IsOnGround())
			{
				m_downDamageFlag = true;
			}
			//�n�ʂɕt���Ă��Ȃ��Ƃ�
			else
			{
				m_flyDamageFlag = true;
			}
			m_targetAttackFlag = true;
			m_collisionHitFlag = true;
			//m_kickAttack = false;
			//���ʉ�
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(5);
			se->Play(false);
			se->SetVolume(1.0f);
			return;
		}
	}

	if (m_damageFlag == true)
	{
		m_damageCountTime += g_gameTime->GetFrameDeltaTime();
		if (m_damageCountTime > 1.0f)
		{
			m_damageCount = 0;
			m_damageFlag = false;
		}
	}

	////�p���`
	//if (g_pad[0]->IsTrigger(enButtonA))
	//{	
	//	
	//}
	////�L�b�N
	//else if (g_pad[0]->IsTrigger(enButtonB))
	//{
	//	m_enemy->m_enemy_hp = 
	//		PlayerAttack(m_enemy->m_enemy_hp,10);
	//}	
}

void Player2::Attack()
{
	//�n��U��
	if (m_charaCon.IsOnGround())
	{
		//�ȉ��̍s�����Ă��Ȃ��Ƃ��U���ł���
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
			(m_stepAnimationFlagLeft != true && m_stepAnimationFlagRight != true) && //�X�e�b�v
			(m_upGuardFlag != true && m_downGuardFlag != true) && //�K�[�h
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
		   )
		{
			if (g_pad[m_gamepadNo]->IsTrigger(enButtonA))
			{
				m_panchAnimationFlag = true;
				////�f�o�b�O�p
				//m_playerHP =
				//	PlayerAttack(m_playerHP, 5);
			}
			else if (g_pad[m_gamepadNo]->IsTrigger(enButtonB))
			{
				m_kickAnimationFlag = true;
			}
		}

		//if ((m_player->m_upGuardFlag == true || m_player->m_upDamageFlag == true) ||
		//	(m_player->m_downGuardFlag == true || m_player->m_downDamageFlag == true)
		//	)
		//{
		//	return;
		//}

		if (m_player->m_collisionHitFlag == true)
		{
			return;
		}

		//�p���`
		if (m_panchAttackCollision == true)
		{
			//�p���`�U���p�̃R���W�������쐬
			MakePanchAttackCollision();
		}
		//�L�b�N
		else if (m_kickAttackCollision == true)
		{
			//�L�b�N�U���p�̃R���W�������쐬
			MakeKickAttackCollision();
		}

		//�K�E�Z
		//else if (g_pad[0]->IsTrigger(enButtonX))
		//{
		//	m_enemy->m_enemyHP = 
		//		PlayerAttack(m_enemy->m_enemyHP, 20);
		//}
	}
	//�󒆍U��
	else
	{
		//�ȉ��̍s�����Ă��Ȃ��Ƃ��U���ł���
		if ((m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //�U��
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
			)
		{
			if (g_pad[m_gamepadNo]->IsTrigger(enButtonA))
			{
				m_flyingPanchAnimationFlag = true;
				m_flyingPanchAttackCollision = true;
				////�f�o�b�O�p
				//m_playerHP =
				//	PlayerAttack(m_playerHP, 5);
			}
			else if (g_pad[m_gamepadNo]->IsTrigger(enButtonB))
			{
				m_flyingKickAnimationFlag = true;
				m_flyingKickAttackCollision = true;
			}

			//if (m_player->m_collisionHitFlag == true)
			//{
			//	return;
			//}

			////�p���`
			//if (m_flyingPanchAttackCollision == true)
			//{
			//	//�󒆃p���`�U���p�̃R���W�������쐬
			//	MakeFlyingPanchAttackCollision();
			//}
			////�L�b�N
			//else if (m_flyingKickAttackCollision == true)
			//{
			//	//�󒆃L�b�N�U���p�̃R���W�������쐬
			//	MakeFlyingKickAttackCollision();
			//}
		}

		if (m_player->m_collisionHitFlag == true)
		{
			return;
		}

		//�p���`
		if (m_flyingPanchAttackCollision == true)
		{
			//�󒆃p���`�U���p�̃R���W�������쐬
			MakeFlyingPanchAttackCollision();
		}
		//�L�b�N
		else if (m_flyingKickAttackCollision == true)
		{
			//�󒆃L�b�N�U���p�̃R���W�������쐬
			MakeFlyingKickAttackCollision();
		}
	}
}

void Player2::MakePanchAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�v���C���[2���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f + m_up * 50.0f;
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		collisionPosition += m_side * 30.0f + m_up * 50.0f;
	}
	////����̃R���W�������쐬����B
	//collisionObject->CreateSphere(collisionPosition, //���W�B
	//	Quaternion::Identity, //��]�B
	//	70.0f //���a�B
	//);
	collisionObject->CreateBox(collisionPosition, //���W
		Quaternion::Identity, //��]
		Vector3{ 35.0f,25.0f,25.0f } //�T�C�Y
	);

	collisionObject->SetName("player2_panch_attack");
}

void Player2::MakeFlyingPanchAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�v���C���[2���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f;
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		collisionPosition += m_side * 30.0f;
	}
	////����̃R���W�������쐬����B
	//collisionObject->CreateSphere(collisionPosition, //���W�B
	//	Quaternion::Identity, //��]�B
	//	70.0f //���a�B
	//);
	collisionObject->CreateBox(collisionPosition, //���W
		Quaternion::Identity, //��]
		Vector3{ 35.0f,25.0f,25.0f } //�T�C�Y
	);

	collisionObject->SetName("player2_panch_jump_attack");
}

void Player2::MakeKickAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�v���C���[2���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f + m_up * 25.0f;
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		collisionPosition += m_side * 35.0f + m_up * 25.0f;
	}
	////����̃R���W�������쐬����B
	//collisionObject->CreateSphere(collisionPosition, //���W�B
	//	Quaternion::Identity, //��]�B
	//	70.0f //���a�B
	//);
	collisionObject->CreateBox(collisionPosition, //���W
		Quaternion::Identity, //��]
		Vector3{ 45.0f,25.0f,25.0f } //�T�C�Y
	);

	collisionObject->SetName("player2_kick_attack");
}

void Player2::MakeFlyingKickAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�v���C���[2���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f;
	}
	//�v���C���[2�������ɂ���Ƃ�
	else
	{
		collisionPosition += m_side * 35.0f;
	}
	////����̃R���W�������쐬����B
	//collisionObject->CreateSphere(collisionPosition, //���W�B
	//	Quaternion::Identity, //��]�B
	//	70.0f //���a�B
	//);
	collisionObject->CreateBox(collisionPosition, //���W
		Quaternion::Identity, //��]
		Vector3{ 45.0f,25.0f,25.0f } //�T�C�Y
	);

	collisionObject->SetName("player2_kick_jump_attack");
}

void Player2::ManageState()
{
	////�p���`
	//if (g_pad[0]->IsTrigger(enButtonA))
	//{
	//	//�X�e�[�g��3(�p���`)�ɂ���B
	//	m_animationState = AnimationState_Panch;
	//	return;
	//}
	////�L�b�N
	//else if (g_pad[0]->IsTrigger(enButtonB))
	//{
	//	//�X�e�[�g��4(�L�b�N)�ɂ���B
	//	m_animationState = AnimationState_Kick;
	//	return;
	//}

	//if (m_round->IsFighting() == false)
	if (m_round->IsNoFighting() == true &&
		m_round->m_roundState != Round::EnRoundState::State_Round &&
		m_round->m_roundState != Round::EnRoundState::State_Fight &&
		m_round->m_roundState != Round::EnRoundState::State_KO &&
		m_round->m_roundState != Round::EnRoundState::State_TimeUp
		)
	{
		//����
		if (m_playerHP <= 0)
		{
			m_animationState = enAnimationState_Lose;
			return;
		}
		//���Ԑ؂ꎞ�̕���
		else if (m_playerHP <= m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Lose_TimeUp;
			return;
		}
		//��������
		else if (m_playerHP == m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Draw;
			return;
		}
		//����
		else
		{
			m_animationState = enAnimationState_Win;
		}
	}
	else
	{
		//���E���h�J�n
		if (m_round->m_roundState == Round::EnRoundState::State_Round ||
			m_round->m_roundState == Round::EnRoundState::State_Fight
			)
		{
			//�X�e�[�g��0(�ҋ@)�ɂ���B
			m_animationState = enAnimationState_Idle;
			return;
		}
		//���E���h�I��
		else if (m_round->m_roundState == Round::EnRoundState::State_KO)
		{
			//if (m_round->m_roundState == Round::EnRoundState::State_KO)
			//{
			//	m_player2.SetAnimationSpeed(0.0f);
			//}
			if (m_playerHP <= 0)
			{
				m_animationState = enAnimationState_Lose;
			}
			else
			{
				if (m_charaCon.IsOnGround() == false)
				{
					//�󒆃p���`
					if (m_flyingPanchAnimationFlag == true)
					{
						//�X�e�[�g��3(�p���`)�ɂ���B
						m_animationState = enAnimationState_Panch;
					}
					//�󒆃L�b�N
					else if (m_flyingKickAnimationFlag == true)
					{
						//�X�e�[�g��4(�L�b�N)�ɂ���B
						m_animationState = enAnimationState_Kick;
					}
				}
				else
				{
					//�p���`
					if (m_panchAnimationFlag == true)
					{
						//�X�e�[�g��3(�p���`)�ɂ���B
						m_animationState = enAnimationState_Panch;
						if (m_player2.IsPlayingAnimation() == false)
						{
							m_panchAnimationFlag = false;
						}
					}
					//�L�b�N
					else if (m_kickAnimationFlag == true)
					{
						//�X�e�[�g��4(�L�b�N)�ɂ���B
						m_animationState = enAnimationState_Kick;
						if (m_player2.IsPlayingAnimation() == false)
						{
							m_kickAnimationFlag = false;
						}
					}
					else
					{
						m_animationState = enAnimationState_Idle;
					}
				}
				//m_animationState = enAnimationState_Idle;
			}
			return;
		}
		//�^�C���A�b�v
		else if (m_round->m_roundState == Round::EnRoundState::State_TimeUp)
		{
			if (m_charaCon.IsOnGround() == false)
			{
				//�󒆃p���`
				if (m_flyingPanchAnimationFlag == true)
				{
					//�X�e�[�g��3(�p���`)�ɂ���B
					m_animationState = enAnimationState_Panch;
				}
				//�󒆃L�b�N
				else if (m_flyingKickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
				}
				//�W�����v
				else
				{
					m_animationState = enAnimationState_Jump;
				}
			}
			else
			{
				//�p���`
				if (m_panchAnimationFlag == true)
				{
					//�X�e�[�g��3(�p���`)�ɂ���B
					m_animationState = enAnimationState_Panch;
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_panchAnimationFlag = false;
					}
				}
				//�L�b�N
				else if (m_kickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_kickAnimationFlag = false;
					}
				}
				else
				{
					m_animationState = enAnimationState_Idle;
				}
			}
			return;
		}

		//�W�����v
		if (m_charaCon.IsOnGround() == false)
		{
			//����̍U�����������Ă��Ȃ��Ƃ�
			if (m_flyDamageFlag != true)
			{
				//�󒆃p���`
				if (m_flyingPanchAnimationFlag == true)
				{
					//�X�e�[�g��3(�p���`)�ɂ���B
					m_animationState = enAnimationState_Panch;
					return;
				}
				//�󒆃L�b�N
				else if (m_flyingKickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
					return;
				}
				//�W�����v
				else
				{
					//�X�e�[�g��1(�W�����v��)�ɂ���B
					m_animationState = enAnimationState_Jump;
					return;
				}
			}
			//����̍U��������������
			else
			{
				m_animationState = enAnimationState_Damage;
				m_flyingPanchAnimationFlag = false;
				m_flyingKickAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				m_flyingKickAttackCollision = false;

				//���ł��̏ꍇ
				if (m_player->m_animationState == Player::EnAnimationState::enAnimationState_Damage)
				{
					m_player->m_collisionHitFlag = false;
				}
				return;
			}
		}
		else if (m_charaCon.IsOnGround() == true)
		{
			//�󒆃p���`
			if (m_flyingPanchAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
				m_flyingPanchAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				return;
			}
			//�󒆃L�b�N
			else if (m_flyingKickAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
				m_flyingKickAnimationFlag = false;
				m_flyingKickAttackCollision = false;
				return;
			}

			//����̍U�����������Ă��Ȃ��Ƃ�
			if (m_upDamageFlag != true && m_downDamageFlag != true)
			{
				//�p���`
				if (m_panchAnimationFlag == true)
				{
					//�X�e�[�g��3(�p���`)�ɂ���B
					m_animationState = enAnimationState_Panch;
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_panchAnimationFlag = false;
					}
					return;
				}
				//�L�b�N
				else if (m_kickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_kickAnimationFlag = false;
					}
					return;
				}
			}
			//����̍U��������������
			else
			{
				m_animationState = enAnimationState_Damage;
				m_panchAnimationFlag = false;
				m_kickAnimationFlag = false;
				m_panchAttackCollision = false;
				m_kickAttackCollision = false;
				//m_collisionHitFlag = false;

				//���ł��̏ꍇ
				if (m_player->m_animationState == Player::EnAnimationState::enAnimationState_Damage)
				{
					m_player->m_collisionHitFlag = false;
				}
			}

			//��i�K�[�h
			if (m_upGuardFlag == true)
			{
				m_animationState = enAnimationState_Guard;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_upGuardFlag = false;
				}
				return;
			}
			//���i�K�[�h
			else if (m_downGuardFlag == true)
			{
				m_animationState = enAnimationState_Guard;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_downGuardFlag = false;
				}
				return;
			}

			//��i�_���[�W
			if (m_upDamageFlag == true)
			{
				m_animationState = enAnimationState_Damage;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_targetAttackFlag = false;
					m_upDamageFlag = false;
				}
				return;
			}
			//���i�_���[�W
			else if (m_downDamageFlag == true)
			{
				m_animationState = enAnimationState_Damage;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_targetAttackFlag = false;
					m_downDamageFlag = false;
				}
				return;
			}
			//�󒆃_���[�W
			else if (m_flyDamageFlag == true)
			{
				m_targetAttackFlag = false;
				m_flyDamageFlag = false;
				return;
			}

			//�ړ�
			if (m_moveDirectionState != enMoveState_Left_Up && //����ł͂Ȃ�
				m_moveDirectionState != enMoveState_Up && //��ł͂Ȃ�
				m_moveDirectionState != enMoveState_Right_Up && //�E��ł͂Ȃ�
				fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f //�X�e�B�b�N�������Ă�����
				)
			{
				//�X�e�[�g��2(����)�ɂ���B
				m_animationState = enAnimationState_Walk;
				return;
			}
			//�E�X�e�b�v
			else if (m_stepAnimationFlagRight == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagRight = false;
				}
				return;
			}
			//���X�e�b�v
			else if (m_stepAnimationFlagLeft == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagLeft = false;
				}
				return;
			}
			//�ҋ@
			else
			{
				//�X�e�[�g��0(�ҋ@)�ɂ���B
				m_animationState = enAnimationState_Idle;
				return;
			}
		}
	}

	////�ړ�
	//if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	//{
	//	//�X�e�[�g��2(����)�ɂ���B
	//	m_animationState = AnimationState_Walk;
	//	return;
	//}
	////�ҋ@
	//else
	//{
	//	//�X�e�[�g��0(�ҋ@)�ɂ���B
	//	m_animationState = AnimationState_Idle;
	//	return;
	//}

}

void Player2::PlayAnimation()
{
	//KO���\�����Ă��Ȃ��Ƃ�
	if (m_round->m_koFlag!=true)
	{
		m_player2.SetAnimationSpeed(1.0f);
	}
	//KO���\�����Ă���Ƃ�
	else
	{
		m_player2.SetAnimationSpeed(0.0f);
	}
	switch (m_animationState)
	{
	case enAnimationState_Idle: //�ҋ@
		m_player2.PlayAnimation(enAnimationClip_Idle, 0.1);
		break;
	case enAnimationState_Jump: //�W�����v
		m_player2.SetAnimationSpeed(0.8f);
		m_player2.PlayAnimation(enAnimationClip_Jump);
		break;
	case enAnimationState_Walk: //����
		//�v���C���[2���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			//if (m_stickL.x > 0.001f)
			//�ύX��
			if (m_moveDirectionState == enMoveState_Right)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Back);
			}
			//else if (m_stickL.x < 0.0f)
			//�ύX��
			if (m_moveDirectionState == enMoveState_Left)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Forward);
			}
		}
		//�v���C���[2�������ɂ���Ƃ�
		else
		{
			//if (m_stickL.x > 0.001f)
			//�ύX��
			if (m_moveDirectionState == enMoveState_Right)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Forward);
			}
			//else if (m_stickL.x < 0.0)
			//�ύX��
			if (m_moveDirectionState == enMoveState_Left)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Back);
			}
		}
		break;
	case enAnimationState_Step: //�X�e�b�v
		m_player2.SetAnimationSpeed(2.5f);
		//�v���C���[2���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			if (m_stepAnimationFlagRight == true)
			{
				m_player2.PlayAnimation(enAnimationClip_Step_Back);
			}
			else if (m_stepAnimationFlagLeft == true)
			{
				m_player2.PlayAnimation(enAnimationClip_Step_Forward);
			}
		}
		//�v���C���[2�������ɂ���Ƃ�
		else
		{
			if (m_stepAnimationFlagRight == true)
			{
				m_player2.PlayAnimation(enAnimationClip_Step_Forward);
			}
			else if (m_stepAnimationFlagLeft == true)
			{
				m_player2.PlayAnimation(enAnimationClip_Step_Back);
			}
		}
		break;
	case enAnimationState_Panch: //�p���`
		if (m_charaCon.IsOnGround() != true)
		{
			m_player2.SetAnimationSpeed(1.5f);
			m_player2.PlayAnimation(enAnimationClip_Panch_Jump, 0.1);
		}
		else
		{
			m_player2.PlayAnimation(enAnimationClip_Panch, 0.1);
		}
		break;
	case enAnimationState_Kick: //�L�b�N
		if (m_charaCon.IsOnGround() != true)
		{
			m_player2.SetAnimationSpeed(1.5f);
			m_player2.PlayAnimation(enAnimationClip_Kick_Jump, 0.1);
		}
		else
		{
			m_player2.PlayAnimation(enAnimationClip_Kick, 0.1);
		}
		break;
	case enAnimationState_Guard: //�K�[�h
		if (m_upGuardFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Panch_Guard, 0.1);
		}
		else if (m_downGuardFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Kick_Guard, 0.1);
		}
		break;
	case enAnimationState_Damage: //�_���[�W
		if (m_upDamageFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Panch_Damage, 0.1);
		}
		else if (m_downDamageFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Kick_Damage, 0.1);
		}
		else if (m_flyDamageFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Fly_Damage, 0.1);
		}
		break;
	case enAnimationState_Win: //����
		m_player2.PlayAnimation(enAnimationClip_Win);
		break;
	case enAnimationState_Lose: //����
		m_player2.PlayAnimation(enAnimationClip_Lose);
		break;
	case enAnimationState_Lose_TimeUp: //����
		m_player2.PlayAnimation(enAnimationClip_Lose_TimeUp);
		break;
	case enAnimationState_Draw: //��������
		m_player2.PlayAnimation(enAnimationClip_Draw);
		break;
	default:
		break;
	}
}

void Player2::OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName)
{
	(void)clipName;
	//�L�[�̖��O���upanch_attack_start�v�̎��B
	if (wcscmp(eventName, L"panch_attack_start") == 0)
	{
		//�U����(�p���`)
		m_panchAttackCollision = true;
	}
	//�L�[�̖��O���upanch_attack_end�v�̎��B
	else if (wcscmp(eventName, L"panch_attack_end") == 0)
	{
		//�U���I���(�p���`)
		m_panchAttackCollision = false;
		//m_player->m_collisionHitFlag = false;
	}

	//�L�[�̖��O���ukick_attack_start�v�̎��B
	if (wcscmp(eventName, L"kick_attack_start") == 0)
	{
		//�U����(�L�b�N)
		m_kickAttackCollision = true;
	}
	//�L�[�̖��O���ukick_attack_end�v�̎��B
	else if (wcscmp(eventName, L"kick_attack_end") == 0)
	{
		//�U���I���(�L�b�N)
		m_kickAttackCollision = false;
		//m_player->m_collisionHitFlag = false;
	}
}

void Player2::Render(RenderContext& rc)
{
	//�v���C���[�`��
	m_player2.Draw(rc);
}