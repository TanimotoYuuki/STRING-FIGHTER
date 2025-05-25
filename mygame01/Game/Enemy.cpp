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
	//0.待機アニメーション
	m_animationClips[enAnimationClip_Idle].Load("Assets/animation/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//1.ジャンプアニメーション
	m_animationClips[enAnimationClip_Jump].Load("Assets/animation/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//2.前移動アニメーション
	m_animationClips[enAnimationClip_Walk_Forward].Load("Assets/animation/walk_forward1.tka");
	m_animationClips[enAnimationClip_Walk_Forward].SetLoopFlag(true);
	//3.後ろ移動アニメーション
	m_animationClips[enAnimationClip_Walk_Back].Load("Assets/animation/walk_back1.tka");
	m_animationClips[enAnimationClip_Walk_Back].SetLoopFlag(true);
	//4.前ステップアニメーション
	m_animationClips[enAnimationClip_Step_Forward].Load("Assets/animation/step_forward1.tka");
	m_animationClips[enAnimationClip_Step_Forward].SetLoopFlag(false);
	//5.後ろステップアニメーション
	m_animationClips[enAnimationClip_Step_Back].Load("Assets/animation/step_back1.tka");
	m_animationClips[enAnimationClip_Step_Back].SetLoopFlag(false);
	//6.パンチアニメーション
	m_animationClips[enAnimationClip_Panch].Load("Assets/animation/panch.tka");
	m_animationClips[enAnimationClip_Panch].SetLoopFlag(false);
	//7.空中パンチアニメーション
	m_animationClips[enAnimationClip_Panch_Jump].Load("Assets/animation/panch_jump.tka");
	m_animationClips[enAnimationClip_Panch_Jump].SetLoopFlag(false);
	//8.パンチガードアニメーション
	m_animationClips[enAnimationClip_Panch_Guard].Load("Assets/animation/panch_guard.tka");
	m_animationClips[enAnimationClip_Panch_Guard].SetLoopFlag(false);
	//9.パンチダメージアニメーション
	m_animationClips[enAnimationClip_Panch_Damage].Load("Assets/animation/panch_damage.tka");
	m_animationClips[enAnimationClip_Panch_Damage].SetLoopFlag(false);
	//10.キックアニメーション
	m_animationClips[enAnimationClip_Kick].Load("Assets/animation/kick.tka");
	m_animationClips[enAnimationClip_Kick].SetLoopFlag(false);
	//11.空中キックアニメーション
	m_animationClips[enAnimationClip_Kick_Jump].Load("Assets/animation/kick_jump.tka");
	m_animationClips[enAnimationClip_Kick_Jump].SetLoopFlag(false);
	//12.キックガードアニメーション
	m_animationClips[enAnimationClip_Kick_Guard].Load("Assets/animation/kick_guard.tka");
	m_animationClips[enAnimationClip_Kick_Guard].SetLoopFlag(false);
	//13.キックダメージアニメーション
	m_animationClips[enAnimationClip_Kick_Damage].Load("Assets/animation/kick_damage.tka");
	m_animationClips[enAnimationClip_Kick_Damage].SetLoopFlag(false);
	//14.空中ダメージアニメーション
	m_animationClips[enAnimationClip_Fly_Damage].Load("Assets/animation/fly_damage.tka");
	m_animationClips[enAnimationClip_Fly_Damage].SetLoopFlag(false);
	//15.勝ちアニメーション
	m_animationClips[enAnimationClip_Win].Load("Assets/animation/win.tka");
	m_animationClips[enAnimationClip_Win].SetLoopFlag(false);
	//16.負けアニメーション
	m_animationClips[enAnimationClip_Lose].Load("Assets/animation/lose.tka");
	m_animationClips[enAnimationClip_Lose].SetLoopFlag(false);
	//17.時間切れ時の負けアニメーション
	m_animationClips[enAnimationClip_Lose_TimeUp].Load("Assets/animation/lose_timeup.tka");
	m_animationClips[enAnimationClip_Lose_TimeUp].SetLoopFlag(false);
	//18.引き分けアニメーション
	m_animationClips[enAnimationClip_Draw].Load("Assets/animation/lose_timeup.tka");
	m_animationClips[enAnimationClip_Draw].SetLoopFlag(false);

	//m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	//m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	//m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	m_enemy.Init("Assets/modelData/character/Enemy.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	//m_enemy.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	//初期位置
	if (m_initSide == enSideState_Left)
	{
		m_position = { -100.0f,0.0f,0.0f };
	}
	else if (m_initSide == enSideState_Right)
	{
		m_position = { 100.0f,0.0f,0.0f };
	}

	//敵の初期位置を設定
	m_enemy.SetPosition(m_position);
	m_charaCon.Init(10.0f, 50.0f, m_position);
	m_enemy.Update();

	//アニメーションイベント
	m_enemy.AddAnimationEvent([&](const wchar_t* clipName, const wchar_t* eventName){
			OnAnimationEvent(clipName, eventName);
	});

	//効果音
	g_soundEngine->ResistWaveFileBank(5, "Assets/SE/attack.wav");
	g_soundEngine->ResistWaveFileBank(6, "Assets/SE/guard.wav");

	//インスタンス
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
		//キャラクター操作
		Move();

		//当たり判定
		Collision();

		//攻撃
		Attack();
	}
	//ラウンドが終わったら
	else if (m_round->m_roundState == Round::EnRoundState::State_KO || //試合終了
		m_round->m_roundState == Round::EnRoundState::State_TimeUp //タイムアップ
		)
	{
		//KOが表示していないとき
		if (m_round->m_koFlag != true)
		{
			//地面に付いていないか？
			if (m_charaCon.IsOnGround() == false)
			{
				m_moveSpeed.y -= 25.0f;
			}
			m_moveSpeed.x = 0.0f;
			m_position = m_charaCon.Execute(m_moveSpeed, g_gameTime->GetFrameDeltaTime());
			m_enemy.SetPosition(m_position);
		}
	}

	//キャラクター回転
	Rotation();

	//アニメーション管理
	ManageState();

	//アニメーション
	PlayAnimation();

	m_enemy.Update();
}

void Enemy::Move()
{
	////デバッグ用
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

	//距離
	m_distance = m_player->m_position - m_position;

	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//移動
	//乱数の値を更新したか？
	if (m_flagRandom[enState_Walk] != true)
	{
		//-1～1のうちランダムで選ばれる
		//-1: 左
		//0: 待機
		//1: 右
		m_walkRandom = rand() % 3 - 1;
		m_move[enState_Walk] = float(m_walkRandom);
		m_flagRandom[enState_Walk] = true;
	}
	else
	{
		//0.3秒たつまで乱数の値を変えない
		if (m_walkRandom != 0)
		{
			if (m_timeRandom[enState_Walk] > 0.3f)
			{
				m_flagRandom[enState_Walk] = false;
				m_timeRandom[enState_Walk] = 0.0f;
				return;
			}
		}
		//0.1秒たつまで乱数の値を変えない
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

	//ジャンプ
	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;

		//以下の行動していないときジャンプができる
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
			)
		{
			if (m_distance.Length() <= 80.0f)
			{
				//乱数の値を更新したか？
				if (m_flagRandom[enState_Jump] != true)
				{
					if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
					{
						//1～100のうちランダムで選ばれる
						//1～49: 何もしない
						//50～100: ジャンプ
						m_jumpRandom = rand() % 100 + 1;
						//ジャンプ
						if (m_jumpRandom >= 50)
						{
							//1～100のうちランダムで選ばれる
							//1～49: 垂直ジャンプ
							//50～100: 斜めジャンプ
							m_jumpingRandom = rand() % 100 + 1;
							//斜めジャンプ
							if (m_jumpingRandom >= 50)
							{
								//敵が右側にいるとき
								if (m_player->m_position.x < m_position.x)
								{
									m_move[enState_Walk] = -0.5;
									m_move[enState_Jump] = 0.5f;
									m_moveSpeed.y = 525.0f;
									m_leftUpJumpFlag = true;
									m_flagRandom[enState_Jump] = true;
								}
								//敵が左側にいるとき
								else
								{
									m_move[enState_Walk] = 0.5f;
									m_move[enState_Jump] = 0.5f;
									m_moveSpeed.y = 525.0f;
									m_rightUpJumpFlag = true;
									m_flagRandom[enState_Jump] = true;
								}
							}
							//垂直ジャンプ
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
					//1.0秒たつまで乱数の値を変えない
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

	//以下の行動していないとき移動ができる
	if ((m_stepAnimationFlagRight != true && m_stepAnimationFlagLeft != true) && //ステップ
		(m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
		(m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //空中攻撃
		(m_upGuardFlag != true && m_downGuardFlag != true) && //ガード
		(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
	   )
	{
		m_moveSpeed += right;
	}

	//剛体の処理
	//移動
	if (m_walk.x < 0.0f || //左
		m_walk.x > 0.0f //右
		)
	{
		//地面に付いているとき
		if (m_charaCon.IsOnGround())
		{
			if (m_distance.Length() <= 20.0f)
			{
				//プレイヤーが画面端に行っていないか？
				if (m_player->m_noMove != true)
				{
					//敵が右側にいるとき
					if (m_player->m_position.x < m_position.x)
					{
						//プレイヤーを左に押す
						m_player->m_position.x -= 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
					//敵が左側にいるとき
					else
					{
						//プレイヤーを右に押す
						m_player->m_position.x += 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
				}
			}
		}
	}
	//反発
	else
	{
		//地面に付いているとき
		if (m_charaCon.IsOnGround())
		{
			if (m_distance.Length() <= 20.0f)
			{
				//以下の条件になっていたらプレイヤーが画面端まで行って敵がプレイヤーに向けてジャンプしたとき反発する
				if (m_player->m_noMove == true && //プレイヤーが画面端に行ったか？
					m_moveFlag != true && // 剛体が移動していないか？
					m_moveJumpFlag == true // ジャンプしているか？
					)
				{
					//敵が右側にいるとき
					if (m_rotationLeftFlag == true)
					{
						//右へ反発
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					//敵が左側にいるとき
					else if (m_rotationRightFlag == true)
					{
						//左へ反発
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					m_moveFlag = false;
				}
				else if (fabsf(m_position.x) > 530.0f && //画面端から近いか？
					m_moveFlag != true && //剛体が移動していないか？
					m_moveJumpFlag == true //ジャンプしているか？
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
		//地面に付いていないとき
		else if (m_charaCon.IsOnGround() == false)
		{
			m_moveJumpFlag = true;
			if (m_distance.Length() <= 20.0f)
			{
				//プレイヤーが画面端まで行っていないとき敵がプレイヤーに向けてジャンプしたとき反発する
				if (m_player->m_noMove != true &&
					fabsf(m_position.x) <= 530.0f //画面端から離れているか？
					)
				{
					//敵が右側にいるとき
					if (m_player->m_position.x < m_position.x)
					{
						//右へ反発
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
					//敵が左側にいるとき
					else
					{
						//左へ反発
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_enemy.SetPosition(m_position);
					}
				}
			}
		}
	}

	//地面についているとき
	if (m_charaCon.IsOnGround())
	{
		//しゃがみ
		if (m_jump.y < 0.0f)
		{
			m_moveSpeed.x = 0.0f;
		}

		if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
		{
			//右ステップ
			//敵が右側にいるとき
			if (m_player->m_position.x > m_position.x)
			{
				if (m_distance.Length() <= 200.0f && m_distance.Length() >= 80.0f)
				{
					//移動
					if (m_flagRandom[enState_Step] != true)
					{
						//1～100のうちランダムで選ばれる
						//1～19: 何もしない
						//20～100: 右ステップ
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
			//左ステップ
			//敵が左側にいるとき
			else if (m_player->m_position.x < m_position.x)
			{
				if (m_distance.Length() <= 200.0f && m_distance.Length() >= 80.0f)
				{
					//移動
					if (m_flagRandom[enState_Step] != true)
					{
						//1～100のうちランダムで選ばれる
						//1～19: 何もしない
						//20～100: 左ステップ
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
	//地面に付いていないとき
	else
	{
		m_moveSpeed.y -= 30.0f;
		//m_moveSpeed.y -= 25.0f;
	}

	//画面端に行った時の移動
	//敵が右側にいるとき
	if (m_player->m_position.x < m_position.x)
	{
		//右
		if (m_walk.x > 0.001f)
		{
			//画面端に行ったら
			if (m_noMove == true)
			{
				//地面に付いているとき
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
	//敵が左側にいるとき
	else
	{
		//左
		if (m_walk.x < 0.0f)
		{
			//画面端に行ったら
			if (m_noMove == true)
			{
				//地面に付いていないとき
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

	//画面端
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
	//右画面端
	else if (m_position.x >= 550.0f)
	{
		m_noMove = true;
		m_repulsion.x = -20.0f;
	}
	//左画面端
	else if (m_position.x <= -550.0f)
	{
		m_noMove = true;
		m_repulsion.x = 20.0f;
	}
	//画面端ではないとき
	else
	{
		m_noMove = false;
		m_repulsion.x = 0.0f;
	}
	
	//z軸固定
	m_position.z = 0.0f;
	m_enemy.SetPosition(m_position);
}

void Enemy::Rotation()
{
	//以下の条件になっていたら方向を固定しない
	if (m_charaCon.IsOnGround() != false && //地面についている
		m_player->m_noMove != true //画面端まで行っていない
		)
	{
		m_rotationKeepFlag = false; //方向を固定しない
	}

	//敵が右側にいるとき
	if (m_player->m_position.x < m_position.x)
	{
		//以下の条件になっていたら方向を変える事ができる
		if (((m_panchAnimationFlag != true || m_kickAnimationFlag != true) || //攻撃
			(m_flyingPanchAnimationFlag != true || m_flyingKickAttackCollision != true)) && //空中攻撃
			m_rotationKeepFlag != true //方向を固定していない
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
			//以下の行動していなかったら
			if (m_leftUpJumpFlag != true && //左斜めジャンプ
				m_upJumpFlag != true //垂直ジャンプ
				)
			{
				m_rotationLeftFlag = true; //左を向いている
				m_rotationRightFlag = false; //右を向いている
				m_rotationKeepFlag = true; //方向を固定する
			}
		}
	}
	//敵が左側にいるとき
	else
	{
		//以下の条件になっていたら方向を変える事ができる
		if (((m_panchAnimationFlag != true || m_kickAnimationFlag != true) || //攻撃
			(m_flyingPanchAnimationFlag != true || m_flyingKickAttackCollision != true)) && //空中攻撃
			m_rotationKeepFlag != true //方向を固定していない
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
			//以下の行動していなかったら
			if (m_rightUpJumpFlag != true && //右斜めジャンプ
				m_upJumpFlag != true //垂直ジャンプ
				)
			{
				m_rotationRightFlag = true; //右を向いている
				m_rotationLeftFlag = false; //左を向いている
				m_rotationKeepFlag = true; //方向を固定する
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

	//上段
	const auto& panchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_attack");
	const auto& flyingPanchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_jump_attack");
	const auto& flyingKickCollision = g_collisionObjectManager->FindCollisionObject("player_kick_jump_attack");
	if (panchCollision->IsHit(m_charaCon) || //パンチ
		flyingPanchCollision->IsHit(m_charaCon) || //空中パンチ
		flyingKickCollision->IsHit(m_charaCon) //空中キック
	  )
	{
		if (m_upGuardFlag != true && m_downGuardFlag != true)
		{
			//1～100のうちランダムで選ばれる
			//1～49: ダメージ
			//50～100: ガード
			m_guardRandom = rand() % 100 + 1;
		}

		//ガード
		//以下の行動していないとき上段ガードができる
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
			m_upGuardFlag != true && //上段ガード
			m_charaCon.IsOnGround() != false //地面に付いている
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
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}

		//ダメージ
		if (m_targetAttackFlag != true && //ダメージ食らったか
			m_upGuardFlag != true //上段ガード
			)
		{
			m_enemyHP =
				TargetAttack(m_enemyHP, 5);			
			//m_enemyHP =
			//	EnemyAttack(m_enemyHP, 100);
			//敵が右側にいるとき
			if (m_player->m_position.x < m_position.x)
			{
				//地面に付いていないとき
				if (m_charaCon.IsOnGround() != true)
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x += 60.0f;
					}
				}
				else
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x += 25.0f;
					}
				}
			}
			//敵が左側にいるとき
			else
			{
				//地面に付いていないとき
				if (m_charaCon.IsOnGround() != true)
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x -= 60.0f;
					}
				}
				else
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x -= 25.0f;
					}
				}
			}
			m_charaCon.SetPosition(m_position);
			m_enemy.SetPosition(m_position);

			//右
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}
			//左
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}

			//地面に付いているとき
			if (m_charaCon.IsOnGround())
			{
				m_upDamageFlag = true;
			}
			//地面に付いていないとき
			else
			{
				m_flyDamageFlag = true;
			}
			m_targetAttackFlag = true;
			m_collisionHitFlag = true;
			//m_panchAttack = false;
			//効果音
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(5);
			se->Play(false);
			se->SetVolume(1.0f);
			return;
		}
	}

	//下段
	const auto& kickCollision = g_collisionObjectManager->FindCollisionObject("player_kick_attack");
	if (kickCollision->IsHit(m_charaCon))
	{
		if (m_upGuardFlag != true && m_downGuardFlag != true)
		{
			//1～100のうちランダムで選ばれる
			//1～49: ダメージ
			//50～100: ガード
			m_guardRandom = rand() % 100 + 1;
		}

		//ガード
		//以下の行動していないとき下段ガードができる
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
			m_downGuardFlag != true && //下段ガード
			m_charaCon.IsOnGround() != false //地面に付いている
			)
		{
			if (m_player->m_kickAnimationFlag == true)
			{
				if (m_guardRandom >= 50)
				{
					m_downGuardFlag = true;
					//m_kickAttack = false;
					m_collisionHitFlag = true;
					//効果音
					SoundSource* se = NewGO<SoundSource>(0);
					se->Init(6);
					se->Play(false);
					se->SetVolume(1.0f);
					return;
				}
			}
		}

		//ダメージ
		if (m_targetAttackFlag != true && //ダメージ食らったか
			m_downGuardFlag != true //下段ガード
			)
		{
			m_enemyHP =
				TargetAttack(m_enemyHP, 10);			
			//m_enemyHP =
			//	EnemyAttack(m_enemyHP, 100);
			//敵が右側にいるとき
			if (m_player->m_position.x < m_position.x)
			{
				//地面に付いていないとき
				if (m_charaCon.IsOnGround() != true)
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x += 60.0f;
					}
				}
				//地面に付いているとき
				else
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x += 25.0f;
					}
				}
			}
			//敵が左側にいるとき
			else
			{
				//地面に付いていないとき
				if (m_charaCon.IsOnGround() != true)
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x -= 60.0f;
					}
				}
				//地面に付いているとき
				else
				{
					//画面端に行っていないとき
					if (m_noMove != true)
					{
						//ノックバック
						m_position.x -= 25.0f;
					}
				}
			}
			m_charaCon.SetPosition(m_position);
			m_enemy.SetPosition(m_position);

			//右
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}
			//左
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_enemy.SetPosition(m_position);
			}

			//地面に付いているとき
			if (m_charaCon.IsOnGround())
			{
				m_downDamageFlag = true;
			}
			//地面に付いていないとき
			else
			{
				m_flyDamageFlag = true;
			}
			m_targetAttackFlag = true;
			m_collisionHitFlag = true;
			//m_kickAttack = false;
			//効果音
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
	//地上攻撃
	if (m_charaCon.IsOnGround())
	{
		//乱数の値を更新したか？
		if (m_flagRandom[enState_Attack] != true)
		{
			if (m_distance.Length() <= 50.0f)
			{
				//if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
				//{
				//	m_attackRandom = rand() % 3;
				//}

				//以下の行動していないとき攻撃できる
				if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
					(m_stepAnimationFlagLeft != true && m_stepAnimationFlagRight != true) && //ステップ
					(m_upGuardFlag != true && m_downGuardFlag != true) && //ガード
					(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ)
					)
				{
					//0～2のうちランダムで選ばれる
					//0: パンチ
					//1: キック
					//2: 何もしない
					m_attackRandom = rand() % 3;
				}

				////以下の行動していないとき攻撃できる
				//if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
				//	(m_dashAnimationFlagLeft != true && m_dashAnimationFlagRight != true) && //ダッシュ
				//	(m_upGuardFlag != true && m_downGuardFlag != true) && //ガード
				//	(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ)
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
			//0.2秒たつまで乱数の値を変えない
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

		//パンチ
		if (m_panchAttackCollision == true)
		{
			//パンチ攻撃用のコリジョンを作成
			MakePanchAttackCollision();
		}
		//キック
		else if (m_kickAttackCollision == true)
		{
			//キック攻撃用のコリジョンを作成
			MakeKickAttackCollision();
		}

		////パンチ
		//if (m_panchAnimationFlag != true)
		//{
		//	if (g_pad[0]->IsTrigger(enButtonA))
		//	{
		//		m_player->m_playerHP =
		//			EnemyAttack(m_player->m_playerHP, 5);
		//		m_panchAnimationFlag = true;
		//	}
		//}
		////キック
		//else if (m_kickAnimationFlag != true)
		//{
		//	if (g_pad[0]->IsTrigger(enButtonB))
		//	{
		//		m_player->m_playerHP =
		//			EnemyAttack(m_player->m_playerHP, 10);
		//		m_kickAnimationFlag = true;
		//	}
		//}
		////必殺技
		//else if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	m_player->m_playerHP =
		//		EnemyAttack(m_player->m_playerHP, 20);
		//}
	}
	//空中攻撃
	else
	{
		if (m_flagRandom[enState_FlyingAttack] != true)
		{
			if (m_distance.Length() <= 80.0f)
			{
				//以下の行動していないとき攻撃できる
				if ((m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //攻撃
					(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
					)
				{
					//0～2のうちランダムで選ばれる
					//0: パンチ
					//1: キック
					//2: 何もしない
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

			////パンチ
			//if (m_flyingPanchAttackCollision == true)
			//{
			//	//パンチ攻撃用のコリジョンを作成
			//	MakeFlyingPanchAttackCollision();
			//}
			////キック
			//else if (m_flyingKickAttackCollision == true)
			//{
			//	//キック攻撃用のコリジョンを作成
			//	MakeFlyingKickAttackCollision();
			//}
		}

		if (m_player->m_collisionHitFlag == true)
		{
			return;
		}

		//パンチ
		if (m_flyingPanchAttackCollision == true)
		{
			//パンチ攻撃用のコリジョンを作成
			MakeFlyingPanchAttackCollision();
		}
		//キック
		else if (m_flyingKickAttackCollision == true)
		{
			//キック攻撃用のコリジョンを作成
			MakeFlyingKickAttackCollision();
		}
	}
}

void Enemy::MakePanchAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//敵が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f + m_up * 50.0f;
	}
	//敵が左側にいるとき
	else
	{
		collisionPosition += m_side * 30.0f + m_up * 50.0f;
	}
	////球状のコリジョンを作成する。
	//collisionObject->CreateSphere(collisionPosition, //座標。
	//	Quaternion::Identity, //回転。
	//	70.0f //半径。
	//);

	collisionObject->CreateBox(collisionPosition, //座標
		Quaternion::Identity, //回転
		Vector3{ 35.0f,25.0f,25.0f } //サイズ
	);

	collisionObject->SetName("enemy_panch_attack");
}

void Enemy::MakeFlyingPanchAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//敵が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f;
	}
	//敵が左側にいるとき
	else
	{
		collisionPosition += m_side * 30.0f;
	}
	////球状のコリジョンを作成する。
	//collisionObject->CreateSphere(collisionPosition, //座標。
	//	Quaternion::Identity, //回転。
	//	70.0f //半径。
	//);

	collisionObject->CreateBox(collisionPosition, //座標
		Quaternion::Identity, //回転
		Vector3{ 35.0f,25.0f,25.0f } //サイズ
	);

	collisionObject->SetName("enemy_panch_jump_attack");
}

void Enemy::MakeKickAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//敵が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f + m_up * 25.0f;
	}
	//敵が左側にいるとき
	else
	{
		collisionPosition += m_side * 35.0f + m_up * 25.0f;
	}
	////球状のコリジョンを作成する。
	//collisionObject->CreateSphere(collisionPosition, //座標。
	//	Quaternion::Identity, //回転。
	//	70.0f //半径。
	//);

	collisionObject->CreateBox(collisionPosition, //座標
		Quaternion::Identity, //回転
		Vector3{ 45.0f,25.0f,25.0f } //サイズ
	);

	collisionObject->SetName("enemy_kick_attack");
}

void Enemy::MakeFlyingKickAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//敵が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f;
	}
	//敵が左側にいるとき
	else
	{
		collisionPosition += m_side * 35.0f;
	}
	////球状のコリジョンを作成する。
	//collisionObject->CreateSphere(collisionPosition, //座標。
	//	Quaternion::Identity, //回転。
	//	70.0f //半径。
	//);

	collisionObject->CreateBox(collisionPosition, //座標
		Quaternion::Identity, //回転
		Vector3{ 45.0f,25.0f,25.0f } //サイズ
	);

	collisionObject->SetName("enemy_kick_jump_attack");
}

void Enemy::ManageState()
{
	////ジャンプ
	//if (m_charaCon.IsOnGround() == false)
	//{
	//	//ステートを1(ジャンプ中)にする。
	//	m_playerState = AnimationState_Jump;

	//	//ここでManageState関数の処理を終わらせる。
	//	return;
	//}
	////移動
	//if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	//{
	//	//ステートを2(歩き)にする。
	//	m_playerState = AnimationState_Walk;
	//}
	//else
	//{
	//	//ステートを0(待機)にする。
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
		//負け
		if (m_enemyHP <= 0)
		{
			m_animationState = enAnimationState_Lose;
			return;
		}
		//時間切れ時の負け
		else if (m_enemyHP <= m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Lose_TimeUp;
			return;
		}
		//引き分け
		else if (m_enemyHP == m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Draw;
			return;
		}
		//勝ち
		else
		{
			m_animationState = enAnimationState_Win;
			return;
		}
	}
	else
	{
		//ラウンド開始
		if (m_round->m_roundState == Round::EnRoundState::State_Round ||
			m_round->m_roundState == Round::EnRoundState::State_Fight
			)
		{
			//ステートを0(待機)にする。
			m_animationState = enAnimationState_Idle;
			return;
		}
		//ラウンド終了
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
					//空中パンチ
					if (m_flyingPanchAnimationFlag == true)
					{
						//ステートを3(パンチ)にする。
						m_animationState = enAnimationState_Panch;
					}
					//空中キック
					else if (m_flyingKickAnimationFlag == true)
					{
						//ステートを4(キック)にする。
						m_animationState = enAnimationState_Kick;
					}
				}
				else
				{
					//パンチ
					if (m_panchAnimationFlag == true)
					{
						//ステートを3(パンチ)にする。
						m_animationState = enAnimationState_Panch;
						if (m_enemy.IsPlayingAnimation() == false)
						{
							m_panchAnimationFlag = false;
						}
					}
					//キック
					else if (m_kickAnimationFlag == true)
					{
						//ステートを4(キック)にする。
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
		//タイムアップ
		else if (m_round->m_roundState == Round::EnRoundState::State_TimeUp)
		{
			if (m_charaCon.IsOnGround() == false)
			{
				//空中パンチ
				if (m_flyingPanchAnimationFlag == true)
				{
					//ステートを3(パンチ)にする。
					m_animationState = enAnimationState_Panch;
				}
				//空中キック
				else if (m_flyingKickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
					m_animationState = enAnimationState_Kick;
				}
				//ジャンプ
				else
				{
					m_animationState = enAnimationState_Jump;
				}
			}
			else
			{
				//パンチ
				if (m_panchAnimationFlag == true)
				{
					//ステートを3(パンチ)にする。
					m_animationState = enAnimationState_Panch;
					if (m_enemy.IsPlayingAnimation() == false)
					{
						m_panchAnimationFlag = false;
					}
				}
				//キック
				else if (m_kickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
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

		//ジャンプ
		if (m_charaCon.IsOnGround() == false)
		{
			//相手の攻撃が当たっていないとき
			if (m_flyDamageFlag != true)
			{
				//空中パンチ
				if (m_flyingPanchAnimationFlag == true)
				{
					//ステートを3(パンチ)にする。
					m_animationState = enAnimationState_Panch;
					return;
				}
				//空中キック
				else if (m_flyingKickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
					m_animationState = enAnimationState_Kick;
					return;
				}
				//ジャンプ
				else
				{
					//ステートを1(ジャンプ中)にする。
					m_animationState = enAnimationState_Jump;
					return;
				}
			}
			//相手の攻撃が当たったら
			else
			{
				m_animationState = enAnimationState_Damage;
				m_flyingPanchAnimationFlag = false;
				m_flyingKickAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				m_flyingKickAttackCollision = false;

				//相打ちの場合
				if (m_player->m_animationState == Player::EnAnimationState::enAnimationState_Damage)
				{
					m_player->m_collisionHitFlag = false;
				}
				return;
			}
		}
		else if (m_charaCon.IsOnGround() == true)
		{
			//空中パンチ
			if (m_flyingPanchAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
				m_flagRandom[enState_FlyingAttack] = false;
				m_flyingPanchAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				return;
			}
			//空中キック
			else if (m_flyingKickAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
				m_flagRandom[enState_FlyingAttack] = false;
				m_flyingKickAnimationFlag = false;
				m_flyingKickAttackCollision = false;
				return;
			}

			//相手の攻撃が当たっていないとき
			if (m_upDamageFlag != true && m_downDamageFlag != true)
			{
				//パンチ
				if (m_panchAnimationFlag == true)
				{
					//ステートを3(パンチ)にする。
					m_animationState = enAnimationState_Panch;
					if (m_enemy.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_flagRandom[enState_Attack] = true;
						m_panchAnimationFlag = false;
					}
					return;
				}
				//キック
				else if (m_kickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
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
			//相手の攻撃が当たったら
			else
			{
				m_animationState = enAnimationState_Damage;
				m_panchAnimationFlag = false;
				m_kickAnimationFlag = false;
				m_panchAttackCollision = false;
				m_kickAttackCollision = false;
				//m_collisionHitFlag = false;

				//相打ちの場合
				if (m_player->m_animationState == Player::EnAnimationState::enAnimationState_Damage)
				{
					m_player->m_collisionHitFlag = false;
				}
			}

			//上段ガード
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
			//下段ガード
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

			//上段ダメージ
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
			//下段ダメージ
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
			//空中ダメージ
			else if (m_flyDamageFlag == true)
			{
				m_targetAttackFlag = false;
				m_flyDamageFlag = false;
				return;
			}

			//移動
			if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
			{
				//ステートを2(歩き)にする。
				m_animationState = enAnimationState_Walk;
				return;
			}
			//右ステップ
			else if (m_stepAnimationFlagRight==true)
			{
				m_animationState = enAnimationState_Step;
				if (m_enemy.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagRight = false;
				}
				return;
			}
			//左ステップ
			else if (m_stepAnimationFlagLeft == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_enemy.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagLeft = false;
				}
				return;
			}
			//待機
			else
			{
				//ステートを0(待機)にする。
				m_animationState = enAnimationState_Idle;
				return;
			}
		}
	}
}

void Enemy::PlayAnimation()
{
	//KOが表示していないとき
	if (m_round->m_koFlag!=true)
	{
		m_enemy.SetAnimationSpeed(1.0f);
	}
	//KOが表示しているとき
	else
	{
		m_enemy.SetAnimationSpeed(0.0f);
	}
	switch (m_animationState)
	{
	case enAnimationState_Idle: //待機
		m_enemy.PlayAnimation(enAnimationClip_Idle, 0.1f);
		break;
	case enAnimationState_Jump: //ジャンプ
		m_enemy.SetAnimationSpeed(0.8f);
		m_enemy.PlayAnimation(enAnimationClip_Jump);
		break;
	case enAnimationState_Walk: //移動
		//敵が右側にいるとき
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
		//敵が左側にいるとき
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
	case enAnimationState_Step: //ステップ
		m_enemy.SetAnimationSpeed(2.5f);
		//敵が右側にいるとき
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
		//敵が左側にいるとき
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
	case enAnimationState_Panch: //パンチ
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
	case enAnimationState_Kick: //キック
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
	case enAnimationState_Guard: //ガード
		if (m_upGuardFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Panch_Guard, 0.1);
		}
		else if (m_downGuardFlag == true)
		{
			m_enemy.PlayAnimation(enAnimationClip_Kick_Guard, 0.1);
		}
		break;
	case enAnimationState_Damage: //ダメージ
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
	case enAnimationState_Win: //勝ち
		m_enemy.PlayAnimation(enAnimationClip_Win);
		break;
	case enAnimationState_Lose: //負け
		m_enemy.PlayAnimation(enAnimationClip_Lose);
		break;
	case enAnimationState_Lose_TimeUp: //負け
		m_enemy.PlayAnimation(enAnimationClip_Lose_TimeUp);
		break;
	case enAnimationState_Draw: //引き分け
		m_enemy.PlayAnimation(enAnimationClip_Draw);
		break;
	default:
		break;
	}
}

void Enemy::OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName)
{
	(void)clipName;
	//キーの名前が「panch_attack_start」の時。
	if (wcscmp(eventName, L"panch_attack_start") == 0)
	{
		//攻撃中(パンチ)
		m_panchAttackCollision = true;
	}
	//キーの名前が「panch_attack_end」の時。
	else if (wcscmp(eventName, L"panch_attack_end") == 0)
	{
		//攻撃終わる(パンチ)
		m_panchAttackCollision = false;
		//m_player->m_collisionHitFlag = false;
	}

	//キーの名前が「kick_attack_start」の時。
	if (wcscmp(eventName, L"kick_attack_start") == 0)
	{
		//攻撃中(キック)
		m_kickAttackCollision = true;
	}
	//キーの名前が「kick_attack_end」の時。
	else if (wcscmp(eventName, L"kick_attack_end") == 0)
	{
		//攻撃終わる(キック)
		m_kickAttackCollision = false;
		//m_player->m_collisionHitFlag = false;
	}

}

void Enemy::Render(RenderContext& rc)
{
	//敵描画
	m_enemy.Draw(rc);
}