#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include "Round.h"
#include "GameCamera.h"

#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

#include "collision/CollisionObject.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

bool Enemy::Start()
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

	//m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	//m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	//m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	m_enemy.Init("Assets/modelData/character/Enemy.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	//m_enemy.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�����ʒu
	if (m_initSide == enSideState_Left)
	{
		m_position = { -100.0f,0.0f,0.0f };
	}
	else if (m_initSide == enSideState_Right)
	{
		m_position = { 100.0f,0.0f,0.0f };
	}

	//�G�̏����ʒu��ݒ�
	m_enemy.SetPosition(m_position);
	m_charaCon.Init(10.0f, 50.0f, m_position);
	m_enemy.Update();

	//�A�j���[�V�����C�x���g
	m_enemy.AddAnimationEvent([&](const wchar_t* clipName, const wchar_t* eventName){
			OnAnimationEvent(clipName, eventName);
	});

	//���ʉ�
	g_soundEngine->ResistWaveFileBank(5, "Assets/SE/attack.wav");
	g_soundEngine->ResistWaveFileBank(6, "Assets/SE/guard.wav");

	//�C���X�^���X
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	m_round = FindGO<Round>("round");
	m_gameCamera = FindGO<GameCamera>("gamecamera");
	
	return true;
}

void Enemy::Update()
{
	srand(time(nullptr));
	//if (m_round->IsFighting() != false)
	if (m_round->IsNoFighting() != true)
	{
		//�L�����N�^�[����
		Move();

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
			m_enemy.SetPosition(m_position);
		}
	}

	//�L�����N�^�[��]
	Rotation();

	//�A�j���[�V�����Ǘ�
	ManageState();

	//�A�j���[�V����
	PlayAnimation();

	m_enemy.Update();
}

void Enemy::Move()
{
	////�f�o�b�O�p
	//if (g_pad[0]->IsPress(enButtonX))
	//{
	//	if (g_pad[0]->IsPress(enButtonY))
	//	{
	//		m_moveSpeed.x += 2.0f;
	//	}
	//	else
	//	{
	//		m_moveSpeed.x -= 2.0f;
	//	}
	//}
	//else
	//{
	//	m_moveSpeed.x = 0.0f;
	//}

	//����
	m_distance = m_player->m_position - m_position;

	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//�ړ�
	//�����̒l���X�V�������H
	if (m_flagRandom[enState_Walk] != true)
	{
		//-1�`1�̂��������_���őI�΂��
		//-1: ��
		//0: �ҋ@
		//1: �E
		m_walkRandom = rand() % 3 - 1;
		m_move[enState_Walk] = float(m_walkRandom);
		m_flagRandom[enState_Walk] = true;
	}
	else
	{
		//0.3�b���܂ŗ����̒l��ς��Ȃ�
		if (m_walkRandom != 0)
		{
			if (m_timeRandom[enState_Walk] > 0.3f)
			{
				m_flagRandom[enState_Walk] = false;
				m_timeRandom[enState_Walk] = 0.0f;
				return;
			}
		}
		//0.1�b���܂ŗ����̒l��ς��Ȃ�
		else
		{
			if (m_timeRandom[enState_Walk] > 0.1f)
			{
				m_flagRandom[enState_Walk] = false;
				m_timeRandom[enState_Walk] = 0.0f;
				return;
			}
		}
		m_timeRandom[enState_Walk] += g_gameTime->GetFrameDeltaTime();
	}

	//�W�����v
	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;

		//�ȉ��̍s�����Ă��Ȃ��Ƃ��W�����v���ł���
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
			)
		{
			if (m_distance.Length() <= 80.0f)
			{
				//�����̒l���X�V�������H
				if (m_flagRandom[enState_Jump] != true)
				{
					if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
					{
						//1�`100�̂��������_���őI�΂��
						//1�`49: �������Ȃ�
						//50�`100: �W�����v
						m_jumpRandom = rand() % 100 + 1;
						//�W�����v
						if (m_jumpRandom >= 50)
						{
							//1�`100�̂��������_���őI�΂��
							//1�`49: �����W�����v
							//50�`100: �΂߃W�����v
							m_jumpingRandom = rand() % 100 + 1;
							//�΂߃W�����v
							if (m_jumpingRandom >= 50)
							{
								//�G���E���ɂ���Ƃ�
								if (m_player->m_position.x < m_position.x)
								{
									m_move[enState_Walk] = -0.5;
									m_move[enState_Jump] = 0.5f;
									m_moveSpeed.y = 525.0f;
									m_leftUpJumpFlag = true;
									m_flagRandom[enState_Jump] = true;
								}
								//�G�������ɂ���Ƃ�
								else
								{
									m_move[enState_Walk] = 0.5f;
									m_move[enState_Jump] = 0.5f;
									m_moveSpeed.y = 525.0f;
									m_rightUpJumpFlag = true;
									m_flagRandom[enState_Jump] = true;
								}
							}
							//�����W�����v
							else
							{
								m_move[enState_Walk] = 0.0f;
								m_move[enState_Jump] = 1.0f;
								m_moveSpeed.y = 525.0f;
								m_upJumpFlag = true;
								m_flagRandom[enState_Jump] = true;
							}
						}
						else
						{
							m_move[enState_Jump] = 0.0f;
						}
					}
				}
				else
				{
					//1.0�b���܂ŗ����̒l��ς��Ȃ�
					if (m_timeRandom[enState_Jump] > 1.0f)
					{
						m_flagRandom[enState_Jump] = false;
						m_timeRandom[enState_Jump] = 0.0f;
						return;
					}
					m_upJumpFlag = false;
					m_leftUpJumpFlag = false;
					m_rightUpJumpFlag = false;
					m_timeRandom[enState_Jump] += g_gameTime->GetFrameDeltaTime();
				}
			}
			else
			{
				m_jumpRandom = 0;
				m_jumpingRandom = 0;
			}
		}
	}
	else
	{
		m_jumpRandom = 0;
		m_jumpingRandom = 0;
	}

	if (m_charaCon.IsOnGround() != false)
	{
		m_walk.x = m_move[enState_Walk];
		m_jump.y = m_move[enState_Jump];
	}

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	forward *= m_jump.y * 120.0f;
	right *= m_walk.x * 120.0f;

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
	if (m_walk.x < 0.0f || //��
		m_walk.x > 0.0f //�E
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
					//�G���E���ɂ���Ƃ�
					if (m_player->m_position.x < m_position.x)
					{
						//�v���C���[�����ɉ���
						m_player->m_position.x -= 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
					//�G�������ɂ���Ƃ�
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
				//�ȉ��̏����ɂȂ��Ă�����v���C���[����ʒ[�܂ōs���ēG���v���C���[�Ɍ����ăW�����v�����Ƃ���������
				if (m_player->m_noMove == true && //�v���C���[����ʒ[�ɍs�������H
					m_moveFlag != true && // ���̂��ړ����Ă��Ȃ����H
					m_moveJumpFlag == true // �W�����v���Ă��邩�H
					)
				{
					//�G���E���ɂ���Ƃ�
					if (m_rotationLeftFlag == true)
					{
						//�E�֔���
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					//�G�������ɂ���Ƃ�
					else if (m_rotationRightFlag == true)
					{
						//���֔���
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
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
				//�v���C���[����ʒ[�܂ōs���Ă��Ȃ��Ƃ��G���v���C���[�Ɍ����ăW�����v�����Ƃ���������
				if (m_player->m_noMove != true &&
					fabsf(m_position.x) <= 530.0f //��ʒ[���痣��Ă��邩�H
					)
				{
					//�G���E���ɂ���Ƃ�
					if (m_player->m_position.x < m_position.x)
					{
						//�E�֔���
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
					//�G�������ɂ���Ƃ�
					else
					{
						//���֔���
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
				}
			}
		}
	}

	//�n�ʂɂ��Ă���Ƃ�
	if (m_charaCon.IsOnGround())
	{
		//���Ⴊ��
		if (m_jump.y < 0.0f)
		{
			m_moveSpeed.x = 0.0f;
		}

		if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
		{
			//�E�X�e�b�v
			//�G���E���ɂ���Ƃ�
			if (m_player->m_position.x > m_position.x)
			{
				if (m_distance.Length() <= 200.0f && m_distance.Length() >= 80.0f)
				{
					//�ړ�
					if (m_flagRandom[enState_Step] != true)
					{
						//1�`100�̂��������_���őI�΂��
						//1�`19: �������Ȃ�
						//20�`100: �E�X�e�b�v
						m_walkRandom = rand() % 100 + 1;
						if (m_walkRandom >= 20)
						{
							m_moveSpeed.x += 1500.0f;
							m_walk.x = 1;
							m_stepAnimationFlagRight = true;
							m_flagRandom[enState_Step] = true;
						}
					}
					else
					{
						if (m_timeRandom[enState_Step] > 0.5f)
						{
							m_flagRandom[enState_Step] = false;
							m_timeRandom[enState_Step] = 0.0f;
							return;
						}
						m_timeRandom[enState_Step] += g_gameTime->GetFrameDeltaTime();
					}
				}
			}
			//���X�e�b�v
			//�G�������ɂ���Ƃ�
			else if (m_player->m_position.x < m_position.x)
			{
				if (m_distance.Length() <= 200.0f && m_distance.Length() >= 80.0f)
				{
					//�ړ�
					if (m_flagRandom[enState_Step] != true)
					{
						//1�`100�̂��������_���őI�΂��
						//1�`19: �������Ȃ�
						//20�`100: ���X�e�b�v
						m_walkRandom = rand() % 100 + 1;
						if (m_walkRandom >= 20)
						{
							m_moveSpeed.x -= 1500.0f;
							m_walk.x = -1;
							m_stepAnimationFlagLeft = true;
							m_flagRandom[enState_Step] = true;
						}
					}
					else
					{
						if (m_timeRandom[enState_Step] > 0.5f)
						{
							m_flagRandom[enState_Step] = false;
							m_timeRandom[enState_Step] = 0.0f;
							return;
						}
						m_timeRandom[enState_Step] += g_gameTime->GetFrameDeltaTime();
					}
				}
			}
		}
	}
	//�n�ʂɕt���Ă��Ȃ��Ƃ�
	else
	{
		m_moveSpeed.y -= 30.0f;
		//m_moveSpeed.y -= 25.0f;
	}

	//��ʒ[�ɍs�������̈ړ�
	//�G���E���ɂ���Ƃ�
	if (m_player->m_position.x < m_position.x)
	{
		//�E
		if (m_walk.x > 0.001f)
		{
			//��ʒ[�ɍs������
			if (m_noMove == true)
			{
				//�n�ʂɕt���Ă���Ƃ�
				if (m_charaCon.IsOnGround() != false)
				{
					if (m_charaCon.GetPosition().x >= 550.0f)
					{
						m_position = { 550.0f,0.0f,0.0f };
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
				}
				else if (m_charaCon.GetPosition().x > -550.0f && m_charaCon.GetPosition().x < 550.0f)
				{
					m_position = m_noMovePosition;
					m_charaCon.SetPosition(m_position);
					m_enemy.SetPosition(m_position);
				}
				m_moveSpeed.x = 0.0f;
			}
		}
	}
	//�G�������ɂ���Ƃ�
	else
	{
		//��
		if (m_walk.x < 0.0f)
		{
			//��ʒ[�ɍs������
			if (m_noMove == true)
			{
				//�n�ʂɕt���Ă��Ȃ��Ƃ�
				if (m_charaCon.IsOnGround() != false)
				{
					if (m_charaCon.GetPosition().x <= -550.0f)
					{
						m_position = { -550.0f,0.0f,0.0f };
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
				}
				else if (m_charaCon.GetPosition().x > -550.0f && m_charaCon.GetPosition().x < 550.0f)
				{
					m_position = m_noMovePosition;
					m_charaCon.SetPosition(m_position);
					m_enemy.SetPosition(m_position);
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
	m_enemy.SetPosition(m_position);
}

void Enemy::Rotation()
{
	//�ȉ��̏����ɂȂ��Ă�����������Œ肵�Ȃ�
	if (m_charaCon.IsOnGround() != false && //�n�ʂɂ��Ă���
		m_player->m_noMove != true //��ʒ[�܂ōs���Ă��Ȃ�
		)
	{
		m_rotationKeepFlag = false; //�������Œ肵�Ȃ�
	}

	//�G���E���ɂ���Ƃ�
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
			//�ȉ��̍s�����Ă��Ȃ�������
			if (m_leftUpJumpFlag != true && //���΂߃W�����v
				m_upJumpFlag != true //�����W�����v
				)
			{
				m_rotationLeftFlag = true; //���������Ă���
				m_rotationRightFlag = false; //�E�������Ă���
				m_rotationKeepFlag = true; //�������Œ肷��
			}
		}
	}
	//�G�������ɂ���Ƃ�
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
			//�ȉ��̍s�����Ă��Ȃ�������
			if (m_rightUpJumpFlag != true && //�E�΂߃W�����v
				m_upJumpFlag != true //�����W�����v
				)
			{
				m_rotationRightFlag = true; //�E�������Ă���
				m_rotationLeftFlag = false; //���������Ă���
				m_rotationKeepFlag = true; //�������Œ肷��
			}
		}
	}
	m_enemy.SetRotation(m_rotation);
}

void Enemy::Collision()
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
		if (m_upGuardFlag != true && m_downGuardFlag != true)
		{
			//1�`100�̂��������_���őI�΂��
			//1�`49: �_���[�W
			//50�`100: �K�[�h
			m_guardRandom = rand() % 100 + 1;
		}

		//�K�[�h
		//�ȉ��̍s�����Ă��Ȃ��Ƃ���i�K�[�h���ł���
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
			m_upGuardFlag != true && //��i�K�[�h
			m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
			)
		{
			if (m_player->m_panchAnimationFlag == true ||
				m_player->m_flyingPanchAnimationFlag == true ||
				m_player->m_flyingKickAnimationFlag == true
				)
			{
				if (m_guardRandom >= 50)
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
			m_enemyHP =
				TargetAttack(m_enemyHP, 5);			
			//m_enemyHP =
			//	EnemyAttack(m_enemyHP, 100);
			//�G���E���ɂ���Ƃ�
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
			//�G�������ɂ���Ƃ�
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
			m_enemy.SetPosition(m_position);

			//�E
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}
			//��
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}

			//�n�ʂɕt���Ă���Ƃ�
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
	if (kickCollision->IsHit(m_charaCon))
	{
		if (m_upGuardFlag != true && m_downGuardFlag != true)
		{
			//1�`100�̂��������_���őI�΂��
			//1�`49: �_���[�W
			//50�`100: �K�[�h
			m_guardRandom = rand() % 100 + 1;
		}

		//�K�[�h
		//�ȉ��̍s�����Ă��Ȃ��Ƃ����i�K�[�h���ł���
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
			m_downGuardFlag != true && //���i�K�[�h
			m_charaCon.IsOnGround() != false //�n�ʂɕt���Ă���
			)
		{
			if (m_player->m_kickAnimationFlag == true)
			{
				if (m_guardRandom >= 50)
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
			m_enemyHP =
				TargetAttack(m_enemyHP, 10);			
			//m_enemyHP =
			//	EnemyAttack(m_enemyHP, 100);
			//�G���E���ɂ���Ƃ�
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
			//�G�������ɂ���Ƃ�
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
			m_enemy.SetPosition(m_position);

			//�E
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}
			//��
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}

			//�n�ʂɕt���Ă���Ƃ�
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
}

void Enemy::Attack()
{
	//�n��U��
	if (m_charaCon.IsOnGround())
	{
		//�����̒l���X�V�������H
		if (m_flagRandom[enState_Attack] != true)
		{
			if (m_distance.Length() <= 50.0f)
			{
				//if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
				//{
				//	m_attackRandom = rand() % 3;
				//}

				//�ȉ��̍s�����Ă��Ȃ��Ƃ��U���ł���
				if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
					(m_stepAnimationFlagLeft != true && m_stepAnimationFlagRight != true) && //�X�e�b�v
					(m_upGuardFlag != true && m_downGuardFlag != true) && //�K�[�h
					(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W)
					)
				{
					//0�`2�̂��������_���őI�΂��
					//0: �p���`
					//1: �L�b�N
					//2: �������Ȃ�
					m_attackRandom = rand() % 3;
				}

				////�ȉ��̍s�����Ă��Ȃ��Ƃ��U���ł���
				//if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //�U��
				//	(m_dashAnimationFlagLeft != true && m_dashAnimationFlagRight != true) && //�_�b�V��
				//	(m_upGuardFlag != true && m_downGuardFlag != true) && //�K�[�h
				//	(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W)
				//   )
				//{
				//	if (m_attackRandom == enAttackState_Panch)
				//	{
				//		m_panchAnimationFlag = true;
				//	}
				//	else if (m_attackRandom == enAttackState_Kick)
				//	{
				//		m_kickAnimationFlag = true;
				//	}
				//	else
				//	{
				//		m_flagRandom[enState_Attack] = true;
				//	}
				//}

				if (m_attackRandom == enAttackState_Panch)
				{
					m_panchAnimationFlag = true;
				}
				else if (m_attackRandom == enAttackState_Kick)
				{
					m_kickAnimationFlag = true;
				}
				else
				{
					m_flagRandom[enState_Attack] = true;
				}
			}
		}
		else
		{
			//0.2�b���܂ŗ����̒l��ς��Ȃ�
			if (m_timeRandom[enState_Attack] > 0.2f)
			{
				m_flagRandom[enState_Attack] = false;
				m_timeRandom[enState_Attack] = 0.0f;
				return;
			}
			m_timeRandom[enState_Attack] += g_gameTime->GetFrameDeltaTime();
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

		////�p���`
		//if (m_panchAnimationFlag != true)
		//{
		//	if (g_pad[0]->IsTrigger(enButtonA))
		//	{
		//		m_player->m_playerHP =
		//			EnemyAttack(m_player->m_playerHP, 5);
		//		m_panchAnimationFlag = true;
		//	}
		//}
		////�L�b�N
		//else if (m_kickAnimationFlag != true)
		//{
		//	if (g_pad[0]->IsTrigger(enButtonB))
		//	{
		//		m_player->m_playerHP =
		//			EnemyAttack(m_player->m_playerHP, 10);
		//		m_kickAnimationFlag = true;
		//	}
		//}
		////�K�E�Z
		//else if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	m_player->m_playerHP =
		//		EnemyAttack(m_player->m_playerHP, 20);
		//}
	}
	//�󒆍U��
	else
	{
		if (m_flagRandom[enState_FlyingAttack] != true)
		{
			if (m_distance.Length() <= 80.0f)
			{
				//�ȉ��̍s�����Ă��Ȃ��Ƃ��U���ł���
				if ((m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //�U��
					(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //�_���[�W
					)
				{
					//0�`2�̂��������_���őI�΂��
					//0: �p���`
					//1: �L�b�N
					//2: �������Ȃ�
					m_attackRandom = rand() % 3;
				}

				if (m_moveSpeed.y < 0.0f)
				{
					if (m_position.y <= 100.0f)
					{
						if (m_attackRandom == enAttackState_Panch)
						{
							m_flyingPanchAnimationFlag = true;
							m_flyingPanchAttackCollision = true;
						}
						else if (m_attackRandom == enAttackState_Kick)
						{
							m_flyingKickAnimationFlag = true;
							m_flyingKickAttackCollision = true;
						}
					}
				}
			}

			//if (m_player->m_collisionHitFlag == true)
			//{
			//	return;
			//}

			////�p���`
			//if (m_flyingPanchAttackCollision == true)
			//{
			//	//�p���`�U���p�̃R���W�������쐬
			//	MakeFlyingPanchAttackCollision();
			//}
			////�L�b�N
			//else if (m_flyingKickAttackCollision == true)
			//{
			//	//�L�b�N�U���p�̃R���W�������쐬
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
			//�p���`�U���p�̃R���W�������쐬
			MakeFlyingPanchAttackCollision();
		}
		//�L�b�N
		else if (m_flyingKickAttackCollision == true)
		{
			//�L�b�N�U���p�̃R���W�������쐬
			MakeFlyingKickAttackCollision();
		}
	}
}

void Enemy::MakePanchAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�G���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f + m_up * 50.0f;
	}
	//�G�������ɂ���Ƃ�
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

	collisionObject->SetName("enemy_panch_attack");
}

void Enemy::MakeFlyingPanchAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�G���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f;
	}
	//�G�������ɂ���Ƃ�
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

	collisionObject->SetName("enemy_panch_jump_attack");
}

void Enemy::MakeKickAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�G���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f + m_up * 25.0f;
	}
	//�G�������ɂ���Ƃ�
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

	collisionObject->SetName("enemy_kick_attack");
}

void Enemy::MakeFlyingKickAttackCollision()
{
	//�R���W�����I�u�W�F�N�g���쐬����B
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�G���E���ɂ���Ƃ�
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f;
	}
	//�G�������ɂ���Ƃ�
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

	collisionObject->SetName("enemy_kick_jump_attack");
}

void Enemy::ManageState()
{
	////�W�����v
	//if (m_charaCon.IsOnGround() == false)
	//{
	//	//�X�e�[�g��1(�W�����v��)�ɂ���B
	//	m_playerState = AnimationState_Jump;

	//	//������ManageState�֐��̏������I��点��B
	//	return;
	//}
	////�ړ�
	//if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	//{
	//	//�X�e�[�g��2(����)�ɂ���B
	//	m_playerState = AnimationState_Walk;
	//}
	//else
	//{
	//	//�X�e�[�g��0(�ҋ@)�ɂ���B
	//	m_playerState = AnimationState_Idle;
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
		if (m_enemyHP <= 0)
		{
			m_animationState = enAnimationState_Lose;
			return;
		}
		//���Ԑ؂ꎞ�̕���
		else if (m_enemyHP <= m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Lose_TimeUp;
			return;
		}
		//��������
		else if (m_enemyHP == m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Draw;
			return;
		}
		//����
		else
		{
			m_animationState = enAnimationState_Win;
			return;
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
			//	m_enemy.SetAnimationSpeed(0.0f);
			//}
			if (m_enemyHP <= 0)
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
						if (m_enemy.IsPlayingAnimation() == false)
						{
							m_panchAnimationFlag = false;
						}
					}
					//�L�b�N
					else if (m_kickAnimationFlag == true)
					{
						//�X�e�[�g��4(�L�b�N)�ɂ���B
						m_animationState = enAnimationState_Kick;
						if (m_enemy.IsPlayingAnimation() == false)
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
					if (m_enemy.IsPlayingAnimation() == false)
					{
						m_panchAnimationFlag = false;
					}
				}
				//�L�b�N
				else if (m_kickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
					if (m_enemy.IsPlayingAnimation() == false)
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
				m_flagRandom[enState_FlyingAttack] = false;
				m_flyingPanchAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				return;
			}
			//�󒆃L�b�N
			else if (m_flyingKickAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
				m_flagRandom[enState_FlyingAttack] = false;
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
					if (m_enemy.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_flagRandom[enState_Attack] = true;
						m_panchAnimationFlag = false;
					}
					return;
				}
				//�L�b�N
				else if (m_kickAnimationFlag == true)
				{
					//�X�e�[�g��4(�L�b�N)�ɂ���B
					m_animationState = enAnimationState_Kick;
					if (m_enemy.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_flagRandom[enState_Attack] = true;
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
				if (m_enemy.IsPlayingAnimation() == false)
				{
					m_guardRandom = 0;
					m_upGuardFlag = false;
				}
				return;
			}
			//���i�K�[�h
			else if (m_downGuardFlag == true)
			{
				m_animationState = enAnimationState_Guard;
				if (m_enemy.IsPlayingAnimation() == false)
				{
					m_guardRandom = 0;
					m_downGuardFlag = false;
				}
				return;
			}

			//��i�_���[�W
			if (m_upDamageFlag == true)
			{
				m_animationState = enAnimationState_Damage;
				if (m_enemy.IsPlayingAnimation() == false)
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
				if (m_enemy.IsPlayingAnimation() == false)
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
			if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
			{
				//�X�e�[�g��2(����)�ɂ���B
				m_animationState = enAnimationState_Walk;
				return;
			}
			//�E�X�e�b�v
			else if (m_stepAnimationFlagRight==true)
			{
				m_animationState = enAnimationState_Step;
				if (m_enemy.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagRight = false;
				}
				return;
			}
			//���X�e�b�v
			else if (m_stepAnimationFlagLeft == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_enemy.IsPlayingAnimation() == false)
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
}

void Enemy::PlayAnimation()
{
	//KO���\�����Ă��Ȃ��Ƃ�
	if (m_round->m_koFlag!=true)
	{
		m_enemy.SetAnimationSpeed(1.0f);
	}
	//KO���\�����Ă���Ƃ�
	else
	{
		m_enemy.SetAnimationSpeed(0.0f);
	}
	switch (m_animationState)
	{
	case enAnimationState_Idle: //�ҋ@
		m_enemy.PlayAnimation(enAnimationClip_Idle, 0.1f);
		break;
	case enAnimationState_Jump: //�W�����v
		m_enemy.SetAnimationSpeed(0.8f);
		m_enemy.PlayAnimation(enAnimationClip_Jump);
		break;
	case enAnimationState_Walk: //�ړ�
		//�G���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			if (m_walk.x > 0.001f)
			{
				m_enemy.PlayAnimation(enAnimationClip_Walk_Back);
			}
			else
			{
				m_enemy.PlayAnimation(enAnimationClip_Walk_Forward);
			}
		}
		//�G�������ɂ���Ƃ�
		else
		{
			if (m_walk.x>0.001f)
			{
				m_enemy.PlayAnimation(enAnimationClip_Walk_Forward);
			}
			else
			{
				m_enemy.PlayAnimation(enAnimationClip_Walk_Back);
			}
		}
		break;
	case enAnimationState_Step: //�X�e�b�v
		m_enemy.SetAnimationSpeed(2.5f);
		//�G���E���ɂ���Ƃ�
		if (m_player->m_position.x < m_position.x)
		{
			if (m_stepAnimationFlagRight == true)
			{
				m_enemy.PlayAnimation(enAnimationClip_Step_Back);
			}
			else if (m_stepAnimationFlagLeft == true)
			{
				m_enemy.PlayAnimation(enAnimationClip_Step_Forward);
			}
		}
		//�G�������ɂ���Ƃ�
		else
		{
			if (m_stepAnimationFlagRight == true)
			{
				m_enemy.PlayAnimation(enAnimationClip_Step_Forward);
			}
			else if (m_stepAnimationFlagLeft == true)
			{
				m_enemy.PlayAnimation(enAnimationClip_Step_Back);
			}
		}
		break;
	case enAnimationState_Panch: //�p���`
		if (m_charaCon.IsOnGround() != true)
		{
			m_enemy.SetAnimationSpeed(1.5f);
			m_enemy.PlayAnimation(enAnimationClip_Panch_Jump, 0.1);
		}
		else
		{
			m_enemy.PlayAnimation(enAnimationClip_Panch, 0.1);
		}
		break;
	case enAnimationState_Kick: //�L�b�N
		if (m_charaCon.IsOnGround() != true)
		{
			m_enemy.SetAnimationSpeed(1.5f);
			m_enemy.PlayAnimation(enAnimationClip_Kick_Jump, 0.1);
		}
		else
		{
			m_enemy.PlayAnimation(enAnimationClip_Kick, 0.1);
		}
		break;
	case enAnimationState_Guard: //�K�[�h
		if (m_upGuardFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Panch_Guard, 0.1);
		}
		else if (m_downGuardFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Kick_Guard, 0.1);
		}
		break;
	case enAnimationState_Damage: //�_���[�W
		if (m_upDamageFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Panch_Damage, 0.1);
		}
		else if (m_downDamageFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Kick_Damage, 0.1);
		}
		else if (m_flyDamageFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Fly_Damage, 0.1);
		}
		break;
	case enAnimationState_Win: //����
		m_enemy.PlayAnimation(enAnimationClip_Win);
		break;
	case enAnimationState_Lose: //����
		m_enemy.PlayAnimation(enAnimationClip_Lose);
		break;
	case enAnimationState_Lose_TimeUp: //����
		m_enemy.PlayAnimation(enAnimationClip_Lose_TimeUp);
		break;
	case enAnimationState_Draw: //��������
		m_enemy.PlayAnimation(enAnimationClip_Draw);
		break;
	default:
		break;
	}
}

void Enemy::OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName)
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

void Enemy::Render(RenderContext& rc)
{
	//�G�`��
	m_enemy.Draw(rc);
}