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

	//m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	//m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	//m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	//m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	//m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	//m_player.Init("Assets/modelData/character/1P.tkm", m_animationClips, enAnimationClip_Num);
	//m_player.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_player2.Init("Assets/modelData/character/2P.tkm", m_animationClips, enAnimationClip_Num);

	//初期位置
	if (m_initSide == enSideState_Left)
	{
		m_position = { -100.0f,0.0f,0.0f };
	}
	else if (m_initSide == enSideState_Right)
	{
		m_position = { 100.0f,0.0f,0.0f };
	}

	//プレイヤー2の初期位置を設定
	m_player2.SetPosition(m_position);
	m_charaCon.Init(10.0f, 50.0f, m_position);
	m_player2.Update();

	//アニメーションイベント
	m_player2.AddAnimationEvent([&](const wchar_t* clipName, const wchar_t* eventName) {
		OnAnimationEvent(clipName, eventName);
	});

	//効果音
	g_soundEngine->ResistWaveFileBank(5, "Assets/SE/attack.wav");
	g_soundEngine->ResistWaveFileBank(6, "Assets/SE/guard.wav");

	//インスタンス
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	m_frame = FindGO<Frame>("frame");
	m_round = FindGO<Round>("round");
	m_gameCamera = FindGO<GameCamera>("gamecamera");

	return true;
}

void Player2::Update()
{
	//HPが0または時間切れになったら処理しない
	//if (m_round->IsFighting() != false)
	if (m_round->IsNoFighting() != true)
	{
		//キャラクター操作
		Move();

		//フレーム管理
		FrameManage();

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
			m_player2.SetPosition(m_position);
		}
	}

	//キャラクター回転
	Rotation();

	//アニメーション管理
	ManageState();

	//アニメーション
	PlayAnimation();

	//モデル更新
	m_player2.Update();
}

void Player2::Move()
{
	//距離
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
	if (m_moveDirectionState == enMoveState_Left || //左スティックを左に倒す
		m_moveDirectionState == enMoveState_Right   //左スティックを右に倒す
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
					//プレイヤー2が右側にいるとき
					if (m_player->m_position.x < m_position.x)
					{
						//プレイヤーを左に押す
						m_player->m_position.x -= 2.5f;
						m_player->m_charaCon.SetPosition(m_player->m_position);
						m_player->m_player.SetPosition(m_player->m_position);
					}
					//プレイヤー2が左側にいるとき
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
				//以下の条件になっていたらプレイヤーが画面端まで行ってプレイヤー2がプレイヤーに向けてジャンプしたとき反発する
				if (m_player->m_noMove == true && //プレイヤーが画面端に行ったか？
					m_moveFlag != true && // 剛体が移動していないか？
					m_moveJumpFlag == true // ジャンプしているか？
				    )
				{
					//プレイヤー2が右側にいるとき
					if (m_rotationLeftFlag == true)
					{
						//右へ反発
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
						m_moveFlag = true;
						m_moveJumpFlag = false;
					}
					//プレイヤー2が左側にいるとき
					else if (m_rotationRightFlag == true)
					{
						//左へ反発
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
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
				//プレイヤーが画面端まで行っていないときプレイヤー2がプレイヤーに向けてジャンプしたとき反発する
				if (m_player->m_noMove != true &&
					fabsf(m_position.x) <= 530.0f //画面端から離れているか？
					)
				{
					//プレイヤー2が右側にいるとき
					if (m_player->m_position.x < m_position.x)
					{
						//右へ反発
						m_position.x = m_player->m_position.x + 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
					//プレイヤー2が左側にいるとき
					else
					{
						//左へ反発
						m_position.x = m_player->m_position.x - 20.0f;
						m_charaCon.SetPosition(m_position);
						m_player2.SetPosition(m_position);
					}
				}
			}
		}
	}

	//地面に付いているとき
	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;
		//if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	moveSpeed.y = 250.0f;
		//}

		//ジャンプ
		//以下の行動していないときジャンプができる
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
			)
		{
			//if (m_stickL.y > 0.001f)
			//{
			//	m_moveSpeed.y = 500.0f;
			//}

			//変更済
			//ジャンプ
			if (m_moveDirectionState == enMoveState_Left_Up || //左上
				m_moveDirectionState == enMoveState_Up || //上
				m_moveDirectionState == enMoveState_Right_Up //右上
			    )
			{
				m_moveSpeed.y = 525.0f;
				//m_moveSpeed.y = 500.0f;
			}
		}

		//しゃがみ
		//if (m_stickL.y < 0.0f)
		//{
		//	m_moveSpeed.x = 0.0f;
		//}	
		
		//変更済
		//しゃがみ
		if (m_moveDirectionState == enMoveState_Left_Down || //左下
			m_moveDirectionState == enMoveState_Down || //下
			m_moveDirectionState == enMoveState_Right_Down //右下
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

		//変更済
		//右
		if (m_moveDirectionState == enMoveState_Right)
		{
			m_pushLeftFlag = false;
		}
		//左
		else if (m_moveDirectionState == enMoveState_Left)
		{
			m_pushRightFlag = false;
		}
		//左下・下・右下
		else if (m_moveDirectionState == enMoveState_Left_Down || m_moveDirectionState == enMoveState_Down || m_moveDirectionState == enMoveState_Right_Down)
		{
			m_pushLeftFlag = false;
			m_pushRightFlag = false;
		}

		//攻撃していないときステップができる
		if (m_panchAnimationFlag != true && m_kickAnimationFlag != true)
		{
			//右ステップ
			if (m_moveDirectionState == enMoveState_Right)
			{
				//移動
				m_pushRightFlag = true;
				//初めて移動した
				m_startFlag = true;
				//プログラム変更しない
				//フレームの保管(右)
				m_frameMemoryLeft = 0.0f;
				m_frameMemoryRight = m_frame->m_player2frame[1];

				//ステップフラグがtrueの時
				if (m_frameMemoryRight < m_frame->GetFrame(7.0f) && m_stepFlagRight == 1)
				{
					//ステップ
					m_stepFlagRight = 2;
				}
				else
				{
					//待機
					m_stepFlagRight = 0;
				}
			}
			//左ステップ
			else if (m_moveDirectionState == enMoveState_Left)
			{
				//移動
				m_pushLeftFlag = true;
				//初めて移動した
				m_startFlag = true;
				//プログラム変更しない
				//フレームの保管(左)
				m_frameMemoryRight = 0.0f;
				m_frameMemoryLeft = m_frame->m_player2frame[4];

				//ステップフラグがtrueの時
				if (m_frameMemoryLeft < m_frame->GetFrame(7.0f) && m_stepFlagLeft == 1)
				{
					//ステップ
					m_stepFlagLeft = 2;
				}
				else
				{
					//待機
					m_stepFlagLeft = 0;
				}
			}
			else
			{
				//初めて移動した時
				if (m_startFlag == true)
				{
					//右を押しているか？
					if (m_pushRightFlag == true)
					{
						m_stepFlagLeft = 0;
						//10F以内に
						if (m_frameMemoryRight < m_frame->GetFrame(10.0f))
						{
							//10F以内に
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
					//左を押しているか？
					else if (m_pushLeftFlag == true)
					{
						m_stepFlagRight = 0;
						//10F以内に
						if (m_frameMemoryLeft < m_frame->GetFrame(10.0f))
						{
							//10F以内に
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

			//右ステップ
			if (m_stepFlagRight == 2)
			{
				m_frame->m_frameDash += g_gameTime->GetFrameDeltaTime();
				m_moveSpeed.x += 1500.0f;

				m_frameMemoryDefault = 0.0f;
				m_stepFlagRight = 0;
				m_frame->m_frameDash = 0.0f;
				m_stepAnimationFlagRight = true;
			}
			//左ステップ
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
	//地面に付いてないとき
	else
	{
		m_pushRightFlag = false;
		m_pushLeftFlag = false;
		m_moveSpeed.y -= 30.0f;
		//m_moveSpeed.y -= 25.0f;
	}

	//画面端に行った時の移動
	//プレイヤー2が右側にいるとき
	if (m_player->m_position.x < m_position.x)
	{
		//右
		if (m_moveDirectionState == enMoveState_Right || m_moveDirectionState == enMoveState_Right_Up)
		{
			//画面端に行ったら
			if (m_noMove == true)
			{
				//地面に付いていないとき
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
	//プレイヤー2が左側にいるとき
	else
	{
		//左
		if (m_moveDirectionState == enMoveState_Left || m_moveDirectionState == enMoveState_Left_Up)
		{
			//画面端に行ったら
			if (m_noMove == true)
			{
				//地面に付いてるとき
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
	m_player2.SetPosition(m_position);
}

void Player2::FrameManage()
{
	//配列の要素数
	//0:待機
	//1:右
	//2:斜め右上
	//3:斜め右下
	//4:左
	//5:斜め左上
	//6:斜め左下
	//7:上
	//8:下

	//if (m_stickL.y == -1.0f) //8:下
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Down;
	//	//m_frame->m_state = 8;
	//	m_frame->m_tenkey = 2;
	//}

	//else if (m_stickL.y == 1.0f) //7:上
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Up;
	//	//m_frame->m_state = 7;
	//	m_frame->m_tenkey = 8;
	//}

	//else if ((m_stickL.x<0.0f && m_stickL.x>-1.0f) && (m_stickL.y<0.0f && m_stickL.y>-1.0f)) //6:斜め左下
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left_Down;
	//	//m_frame->m_state = 6;
	//	m_frame->m_tenkey = 1;
	//}

	//else if ((m_stickL.x<0.0f && m_stickL.x>-1.0f) && (m_stickL.y > 0.0f && m_stickL.y < 1.0f)) //5:斜め左上
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left_Up;
	//	//m_frame->m_state = 5;
	//	m_frame->m_tenkey = 7;
	//}

	//else if (m_stickL.x == -1.0f) //4:左
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Left;
	//	//m_frame->m_state = 4;
	//	m_frame->m_tenkey = 4;
	//}

	//else if ((m_stickL.x > 0.0f && m_stickL.x < 1.0f) && (m_stickL.y<0.0f && m_stickL.y>-1.0f)) //3:斜め右下
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right_Down;
	//	//m_frame->m_state = 3;
	//	m_frame->m_tenkey = 3;
	//}

	//else if ((m_stickL.x > 0.0f && m_stickL.x < 1.0f) && (m_stickL.y > 0.0f && m_stickL.y < 1.0f)) //2:斜め右上
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right_Up;
	//	//m_frame->m_state = 2;
	//	m_frame->m_tenkey = 9;
	//}

	//else if (m_stickL.x == 1.0f) //1:右
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Right;
	//	//m_frame->m_state = 1;
	//	m_frame->m_tenkey = 6;
	//}

	//else //0:待機
	//{
	//	m_frame->m_state = Frame::EnDirectionState::enDirectionState_Idle;
	//	//m_frame->m_state = 0;
	//	m_frame->m_tenkey = 5;
	//}

	//変更済_〇
	if (((m_stickL.x >= 0.0f && m_stickL.x < 0.4f) || (m_stickL.x <= 0.0f && m_stickL.x > -0.4f)) && //x軸
		(m_stickL.y <= -0.7f && m_stickL.y >= -1.0f) //y軸
	   ) //8:下
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Down;
		//m_frame->m_state = 8;
		m_frame->m_player2tenkey = 2;
		m_moveDirectionState = enMoveState_Down;
	}
	//変更済_〇
	else if (((m_stickL.x >= 0.0f && m_stickL.x < 0.4f) || (m_stickL.x <= 0.0f && m_stickL.x > -0.4f)) && //x軸
		     (m_stickL.y >= 0.7f && m_stickL.y <= 1.0f) //y軸
		    ) //7:上
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Up;
		//m_frame->m_state = 7;
		m_frame->m_player2tenkey = 8;
		m_moveDirectionState = enMoveState_Up;
	}
	//変更済
	else if ((m_stickL.x <= -0.4f && m_stickL.x > -1.0f) && //x軸
			 (m_stickL.y <= -0.4f && m_stickL.y > -1.0f) //y軸
			) //6:斜め左下
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left_Down;
		//m_frame->m_state = 6;
		m_frame->m_player2tenkey = 1;
		m_moveDirectionState = enMoveState_Left_Down;
	}
	//変更済
	else if ((m_stickL.x <= -0.4f && m_stickL.x > -1.0f) && //x軸
			 (m_stickL.y >= 0.4f && m_stickL.y < 1.0f) //y軸
			) //5:斜め左上
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left_Up;
		//m_frame->m_state = 5;
		m_frame->m_player2tenkey = 7;
		m_moveDirectionState = enMoveState_Left_Up;
	}
	//変更済_〇
	else if ((m_stickL.x <= -0.7f && m_stickL.x >= -1.0f) && //x軸
			 ((m_stickL.y >= 0.0f && m_stickL.y < 0.4f) || (m_stickL.y <= 0.0f && m_stickL.y > -0.4f)) //y軸
		    ) //4:左
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Left;
		//m_frame->m_state = 4;
		m_frame->m_player2tenkey = 4;
		m_moveDirectionState = enMoveState_Left;
	}
	//変更済
	else if ((m_stickL.x >= 0.4f && m_stickL.x < 1.0f) && //x軸
			 (m_stickL.y <= -0.4f && m_stickL.y > -1.0f) //y軸
		    ) //3:斜め右下
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right_Down;
		//m_frame->m_state = 3;
		m_frame->m_player2tenkey = 3;
		m_moveDirectionState = enMoveState_Right_Down;
	}
	//変更済
	else if ((m_stickL.x >= 0.4f && m_stickL.x < 1.0f) && //x軸
			 (m_stickL.y >= 0.4f && m_stickL.y < 1.0f) //y軸
		    ) //2:斜め右上
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right_Up;
		//m_frame->m_state = 2;
		m_frame->m_player2tenkey = 9;
		m_moveDirectionState = enMoveState_Right_Up;
	}
	//変更済_〇
	else if ((m_stickL.x >= 0.7f && m_stickL.x <= 1.0f) && //x軸
			 ((m_stickL.y >= 0.0f && m_stickL.y < 0.4f) || (m_stickL.y <= 0.0f && m_stickL.y > -0.4f)) //y軸
		    ) //1:右
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Right;
		//m_frame->m_state = 1;
		m_frame->m_player2tenkey = 6;
		m_moveDirectionState = enMoveState_Right;
	}
	//変更済_〇
	else //0:待機
	{
		m_frame->m_player2MoveState = Frame::EnDirectionState::enDirectionState_Idle;
		//m_frame->m_state = 0;
		m_frame->m_player2tenkey = 5;
		m_moveDirectionState = enMoveState_Idle;
	}
}

void Player2::Rotation()
{
	//以下の条件になっていたら方向を固定しない
	if (m_charaCon.IsOnGround() != false && //地面についている
		m_player->m_noMove != true //画面端まで行っていない
		)
	{
		m_rotationKeepFlag = false; //方向を固定しない
	}

	//プレイヤー2が右側にいるとき
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
			//スティックの方向が以下の方向に向いていなかったら
			if (m_moveDirectionState != enMoveState_Left_Up && //左上
				m_moveDirectionState != enMoveState_Up //上
				)
			{
				m_rotationLeftFlag = true; //左を向いている
				m_rotationRightFlag = false; //右を向いている
				m_rotationKeepFlag = true; //方向を固定する
			}
		}
	}
	//プレイヤー2が左側にいるとき
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
			//スティックの方向が以下の方向に向いていなかったら
			if (m_moveDirectionState != enMoveState_Right_Up && //右上
				m_moveDirectionState != enMoveState_Up //上
				)
			{
				m_rotationRightFlag = true; //右を向いている
				m_rotationLeftFlag = false; //左を向いている
				m_rotationKeepFlag = true; //方向を固定する
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

	//上段
	const auto& panchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_attack");
	const auto& flyingPanchCollision = g_collisionObjectManager->FindCollisionObject("player_panch_jump_attack");
	const auto& flyingKickCollision = g_collisionObjectManager->FindCollisionObject("player_kick_jump_attack");
	if (panchCollision->IsHit(m_charaCon) || //パンチ
		flyingPanchCollision->IsHit(m_charaCon) || //空中パンチ
		flyingKickCollision->IsHit(m_charaCon) //空中キック
	   )
	{
		//ガード
		//プレイヤー2が右側にいるとき
		if (m_player->m_position.x < m_position.x)
		{
			//以下の行動していないとき上段ガードができる
			if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
				m_upGuardFlag != true && //上段ガード
				m_charaCon.IsOnGround() != false //地面に付いている
				)
			{
				//if (m_stickL.x > 0.001f)
				//変更済
				if (m_moveDirectionState == enMoveState_Right)
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
		//プレイヤー2が左側にいるとき
		else
		{
			//以下の行動していないとき上段ガードができる
			if (m_panchAnimationFlag != true && m_kickAnimationFlag != true && //攻撃
				m_upGuardFlag != true && //上段ガード
				m_charaCon.IsOnGround() != false //地面に付いている
				)
			{
				//if (m_stickL.x < 0.0f)
				//変更済
				if (m_moveDirectionState == enMoveState_Left)
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
			m_playerHP =
				TargetAttack(m_playerHP, 5);
			//プレイヤー2が右側にいるとき
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
				//地面に付いてるとき
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
			//プレイヤー2が左側にいるとき
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
			m_player2.SetPosition(m_position);

			//右
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}
			//左
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}

			//地面に付いてるとき
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
	if (kickCollision->IsHit(m_charaCon) //キック
		)
	{
		//ガード
		//プレイヤー2が右側にいるとき
		if (m_player->m_position.x < m_position.x)
		{
			//以下の行動していないとき下段ガードができる
			if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
				m_downGuardFlag != true && //下段ガード
				m_charaCon.IsOnGround() != false //地面に付いている
				)
			{
				//if (m_stickL.x == 0.5f && m_stickL.y == -0.5f)
				//変更済
				if (m_moveDirectionState == enMoveState_Right_Down)
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
		//プレイヤー2が左側にいるとき
		else
		{
			//以下の行動していないとき下段ガードができる
			if (m_panchAnimationFlag != true && m_kickAnimationFlag != true && //攻撃
				m_downGuardFlag != true && //下段ガード
				m_charaCon.IsOnGround() != false //地面に付いている
				)
			{
				//if (m_stickL.x == -0.5f && m_stickL.y == -0.5f)
				//変更済
				if (m_moveDirectionState == enMoveState_Left_Down)
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
			m_playerHP =
				TargetAttack(m_playerHP, 10);
			//プレイヤー2が右側にいるとき
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
			//プレイヤー2が左側にいるとき
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
			m_player2.SetPosition(m_position);

			//右
			if (m_charaCon.GetPosition().x >= 550.0f)
			{
				m_position = { 550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}
			//左
			else if (m_charaCon.GetPosition().x <= -550.0f)
			{
				m_position = { -550.0f,0.0f,0.0f };
				m_charaCon.SetPosition(m_position);
				m_player2.SetPosition(m_position);
			}

			//地面に付いてるとき
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

	////パンチ
	//if (g_pad[0]->IsTrigger(enButtonA))
	//{	
	//	
	//}
	////キック
	//else if (g_pad[0]->IsTrigger(enButtonB))
	//{
	//	m_enemy->m_enemy_hp = 
	//		PlayerAttack(m_enemy->m_enemy_hp,10);
	//}	
}

void Player2::Attack()
{
	//地上攻撃
	if (m_charaCon.IsOnGround())
	{
		//以下の行動していないとき攻撃できる
		if ((m_panchAnimationFlag != true && m_kickAnimationFlag != true) && //攻撃
			(m_stepAnimationFlagLeft != true && m_stepAnimationFlagRight != true) && //ステップ
			(m_upGuardFlag != true && m_downGuardFlag != true) && //ガード
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
		   )
		{
			if (g_pad[m_gamepadNo]->IsTrigger(enButtonA))
			{
				m_panchAnimationFlag = true;
				////デバッグ用
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

		//必殺技
		//else if (g_pad[0]->IsTrigger(enButtonX))
		//{
		//	m_enemy->m_enemyHP = 
		//		PlayerAttack(m_enemy->m_enemyHP, 20);
		//}
	}
	//空中攻撃
	else
	{
		//以下の行動していないとき攻撃できる
		if ((m_flyingPanchAnimationFlag != true && m_flyingKickAnimationFlag != true) && //攻撃
			(m_upDamageFlag != true && m_downDamageFlag != true && m_flyDamageFlag != true) //ダメージ
			)
		{
			if (g_pad[m_gamepadNo]->IsTrigger(enButtonA))
			{
				m_flyingPanchAnimationFlag = true;
				m_flyingPanchAttackCollision = true;
				////デバッグ用
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

			////パンチ
			//if (m_flyingPanchAttackCollision == true)
			//{
			//	//空中パンチ攻撃用のコリジョンを作成
			//	MakeFlyingPanchAttackCollision();
			//}
			////キック
			//else if (m_flyingKickAttackCollision == true)
			//{
			//	//空中キック攻撃用のコリジョンを作成
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
			//空中パンチ攻撃用のコリジョンを作成
			MakeFlyingPanchAttackCollision();
		}
		//キック
		else if (m_flyingKickAttackCollision == true)
		{
			//空中キック攻撃用のコリジョンを作成
			MakeFlyingKickAttackCollision();
		}
	}
}

void Player2::MakePanchAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//プレイヤー2が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f + m_up * 50.0f;
	}
	//プレイヤー2が左側にいるとき
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

	collisionObject->SetName("player2_panch_attack");
}

void Player2::MakeFlyingPanchAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//プレイヤー2が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -30.0f;
	}
	//プレイヤー2が左側にいるとき
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

	collisionObject->SetName("player2_panch_jump_attack");
}

void Player2::MakeKickAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//プレイヤー2が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f + m_up * 25.0f;
	}
	//プレイヤー2が左側にいるとき
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

	collisionObject->SetName("player2_kick_attack");
}

void Player2::MakeFlyingKickAttackCollision()
{
	//コリジョンオブジェクトを作成する。
	auto collisionObject = NewGO<CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//プレイヤー2が右側にいるとき
	//if (m_player->m_position.x < m_position.x)
	if (m_rotationLeftFlag == true)
	{
		collisionPosition += m_side * -35.0f;
	}
	//プレイヤー2が左側にいるとき
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

	collisionObject->SetName("player2_kick_jump_attack");
}

void Player2::ManageState()
{
	////パンチ
	//if (g_pad[0]->IsTrigger(enButtonA))
	//{
	//	//ステートを3(パンチ)にする。
	//	m_animationState = AnimationState_Panch;
	//	return;
	//}
	////キック
	//else if (g_pad[0]->IsTrigger(enButtonB))
	//{
	//	//ステートを4(キック)にする。
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
		//負け
		if (m_playerHP <= 0)
		{
			m_animationState = enAnimationState_Lose;
			return;
		}
		//時間切れ時の負け
		else if (m_playerHP <= m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Lose_TimeUp;
			return;
		}
		//引き分け
		else if (m_playerHP == m_player->m_playerHP)
		{
			m_animationState = enAnimationState_Draw;
			return;
		}
		//勝ち
		else
		{
			m_animationState = enAnimationState_Win;
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
						if (m_player2.IsPlayingAnimation() == false)
						{
							m_panchAnimationFlag = false;
						}
					}
					//キック
					else if (m_kickAnimationFlag == true)
					{
						//ステートを4(キック)にする。
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
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_panchAnimationFlag = false;
					}
				}
				//キック
				else if (m_kickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
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
				m_flyingPanchAnimationFlag = false;
				m_flyingPanchAttackCollision = false;
				return;
			}
			//空中キック
			else if (m_flyingKickAnimationFlag == true)
			{
				m_animationState = enAnimationState_Idle;
				m_player->m_collisionHitFlag = false;
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
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
						m_panchAnimationFlag = false;
					}
					return;
				}
				//キック
				else if (m_kickAnimationFlag == true)
				{
					//ステートを4(キック)にする。
					m_animationState = enAnimationState_Kick;
					if (m_player2.IsPlayingAnimation() == false)
					{
						m_player->m_collisionHitFlag = false;
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
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_upGuardFlag = false;
				}
				return;
			}
			//下段ガード
			else if (m_downGuardFlag == true)
			{
				m_animationState = enAnimationState_Guard;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_downGuardFlag = false;
				}
				return;
			}

			//上段ダメージ
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
			//下段ダメージ
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
			//空中ダメージ
			else if (m_flyDamageFlag == true)
			{
				m_targetAttackFlag = false;
				m_flyDamageFlag = false;
				return;
			}

			//移動
			if (m_moveDirectionState != enMoveState_Left_Up && //左上ではない
				m_moveDirectionState != enMoveState_Up && //上ではない
				m_moveDirectionState != enMoveState_Right_Up && //右上ではない
				fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f //スティックが動いていたら
				)
			{
				//ステートを2(歩き)にする。
				m_animationState = enAnimationState_Walk;
				return;
			}
			//右ステップ
			else if (m_stepAnimationFlagRight == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_player2.IsPlayingAnimation() == false)
				{
					m_stepAnimationFlagRight = false;
				}
				return;
			}
			//左ステップ
			else if (m_stepAnimationFlagLeft == true)
			{
				m_animationState = enAnimationState_Step;
				if (m_player2.IsPlayingAnimation() == false)
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

	////移動
	//if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	//{
	//	//ステートを2(歩き)にする。
	//	m_animationState = AnimationState_Walk;
	//	return;
	//}
	////待機
	//else
	//{
	//	//ステートを0(待機)にする。
	//	m_animationState = AnimationState_Idle;
	//	return;
	//}

}

void Player2::PlayAnimation()
{
	//KOが表示していないとき
	if (m_round->m_koFlag!=true)
	{
		m_player2.SetAnimationSpeed(1.0f);
	}
	//KOが表示しているとき
	else
	{
		m_player2.SetAnimationSpeed(0.0f);
	}
	switch (m_animationState)
	{
	case enAnimationState_Idle: //待機
		m_player2.PlayAnimation(enAnimationClip_Idle, 0.1);
		break;
	case enAnimationState_Jump: //ジャンプ
		m_player2.SetAnimationSpeed(0.8f);
		m_player2.PlayAnimation(enAnimationClip_Jump);
		break;
	case enAnimationState_Walk: //歩き
		//プレイヤー2が右側にいるとき
		if (m_player->m_position.x < m_position.x)
		{
			//if (m_stickL.x > 0.001f)
			//変更済
			if (m_moveDirectionState == enMoveState_Right)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Back);
			}
			//else if (m_stickL.x < 0.0f)
			//変更済
			if (m_moveDirectionState == enMoveState_Left)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Forward);
			}
		}
		//プレイヤー2が左側にいるとき
		else
		{
			//if (m_stickL.x > 0.001f)
			//変更済
			if (m_moveDirectionState == enMoveState_Right)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Forward);
			}
			//else if (m_stickL.x < 0.0)
			//変更済
			if (m_moveDirectionState == enMoveState_Left)
			{
				m_player2.PlayAnimation(enAnimationClip_Walk_Back);
			}
		}
		break;
	case enAnimationState_Step: //ステップ
		m_player2.SetAnimationSpeed(2.5f);
		//プレイヤー2が右側にいるとき
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
		//プレイヤー2が左側にいるとき
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
	case enAnimationState_Panch: //パンチ
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
	case enAnimationState_Kick: //キック
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
	case enAnimationState_Guard: //ガード
		if (m_upGuardFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Panch_Guard, 0.1);
		}
		else if (m_downGuardFlag == true)
		{
			m_player2.PlayAnimation(enAnimationClip_Kick_Guard, 0.1);
		}
		break;
	case enAnimationState_Damage: //ダメージ
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
	case enAnimationState_Win: //勝ち
		m_player2.PlayAnimation(enAnimationClip_Win);
		break;
	case enAnimationState_Lose: //負け
		m_player2.PlayAnimation(enAnimationClip_Lose);
		break;
	case enAnimationState_Lose_TimeUp: //負け
		m_player2.PlayAnimation(enAnimationClip_Lose_TimeUp);
		break;
	case enAnimationState_Draw: //引き分け
		m_player2.PlayAnimation(enAnimationClip_Draw);
		break;
	default:
		break;
	}
}

void Player2::OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName)
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

void Player2::Render(RenderContext& rc)
{
	//プレイヤー描画
	m_player2.Draw(rc);
}