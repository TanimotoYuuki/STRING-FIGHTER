#pragma once
class Game;
class Player;
class Round;
class GameCamera;
class Enemy: public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//キャラクター操作
	void Move();

	//キャラクター回転
	void Rotation();

	//当たり判定
	void Collision();

	//攻撃
	void Attack();

	//アニメーション管理
	void ManageState();

	//アニメーション
	void PlayAnimation();

	//アニメーションイベント
	void OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName);

	//パンチ攻撃用コリジョン
	void MakePanchAttackCollision();

	//空中パンチ攻撃用コリジョン
	void MakeFlyingPanchAttackCollision();

	//キック攻撃用コリジョン
	void MakeKickAttackCollision();

	//空中キック攻撃用コリジョン
	void MakeFlyingKickAttackCollision();

	//メンバ関数
	//攻撃をくらう側の体力を減らす
	//引数:プレイヤーの体力,技の攻撃力
	int TargetAttack(int HP, int ATK)
	{
		HP -= ATK;
		m_damageCount += ATK;
		m_damageFlag = true;
		return HP;
	}
	//ラウンドが終わったら変数の値をリセットする
	void Reset()
	{
		if (m_initSide == enSideState_Left)
		{
			m_position = { -100.0f,0.0f,0.0f };
		}
		else if (m_initSide == enSideState_Right)
		{
			m_position = { 100.0f,0.0f,0.0f };
		}
		m_charaCon.SetPosition(m_position);
		m_enemy.SetPosition(m_position);
		m_enemy.Update();
		m_noMovePosition = Vector3::Zero;
		m_repulsion = Vector3::Zero;

		m_animationState = 0;
		m_enemyHP = 100;
		m_enemyMaxHP = 100;
		m_damageCount = 0;
		m_damageCountTime = 0.0f;
		m_walkRandom = 0;
		m_jumpRandom = 0;
		m_jumpingRandom = 0;
		m_attackRandom = 0;
		m_guardRandom = 0;
		for (int i = 0; i < enState_Num; i++)
		{
			m_move[i] = 0;
			m_timeRandom[i] = 0;
			m_flagRandom[i] = false;
		}
		m_collisionHitFlag = false;
		m_panchAttackCollision = false;
		m_flyingPanchAttackCollision = false;
		m_kickAttackCollision = false;
		m_flyingKickAttackCollision = false;
		m_noMove = false;
		m_moveFlag = false;
		m_moveJumpFlag = false;
		m_rotationRightFlag = false;
		m_rotationLeftFlag = false;
		m_rotationKeepFlag = false;
		m_upJumpFlag = false;
		m_rightUpJumpFlag = false;
		m_leftUpJumpFlag = false;
		m_targetAttackFlag = false;
		m_upGuardFlag = false;
		m_downGuardFlag = false;
		m_upDamageFlag = false;
		m_downDamageFlag = false;
		m_flyDamageFlag = false;
		m_panchAnimationFlag = false;
		m_flyingPanchAnimationFlag = false;
		m_kickAnimationFlag = false;
		m_flyingKickAnimationFlag = false;
		m_stepAnimationFlagRight = false;
		m_stepAnimationFlagLeft = false;
		m_damageFlag = false;
	}

	//メンバ変数
	//〇側状態
	enum enSideState
	{
		enSideState_Left, //左側
		enSideState_Right, //右側
		enSideState_Num, //〇側数
	};

	//アニメーションクリップ
	enum EnAnimationClip {
		enAnimationClip_Idle, //待機
		enAnimationClip_Jump, //ジャンプ
		enAnimationClip_Walk_Forward, //前移動
		enAnimationClip_Walk_Back, //後ろ移動
		enAnimationClip_Step_Forward, //前ステップ
		enAnimationClip_Step_Back, //後ろステップ
		enAnimationClip_Panch, //パンチ
		enAnimationClip_Panch_Jump, //空中パンチ
		enAnimationClip_Panch_Guard, //パンチガード
		enAnimationClip_Panch_Damage, //パンチダメージ
		enAnimationClip_Kick, //キック
		enAnimationClip_Kick_Jump, //空中キック
		enAnimationClip_Kick_Guard, //キックガード
		enAnimationClip_Kick_Damage, //キックダメージ
		enAnimationClip_Fly_Damage, //空中ダメージ
		enAnimationClip_Win, //勝利
		enAnimationClip_Lose, //敗北
		enAnimationClip_Lose_TimeUp, //タイムアップ敗北
		enAnimationClip_Draw, //引き分け
		enAnimationClip_Num, //アニメーションクリップ数
	};
	//アニメーション状態
	enum EnAnimationState
	{
		enAnimationState_Idle, //待機
		enAnimationState_Jump, //ジャンプ
		enAnimationState_Walk, //移動
		enAnimationState_Step, //ステップ
		enAnimationState_Panch, //パンチ
		enAnimationState_Kick, //キック
		enAnimationState_Guard, //ガード
		enAnimationState_Damage, //ダメージ
		enAnimationState_Win, //勝利
		enAnimationState_Lose, //敗北
		enAnimationState_Lose_TimeUp, //タイムアップ敗北
		enAnimationState_Draw, //引き分け
		enAnimationState_Num, //アニメーション状態数
	};
	//状態
	enum EnState
	{
		enState_Idle, //待機
		enState_Jump, //ジャンプ
		enState_Walk, //移動
		enState_Step, //ステップ
		enState_Attack, //攻撃
		enState_FlyingAttack, //空中攻撃
		enState_Num //状態数
	};
	//攻撃
	enum EnAttackState
	{
		enAttackState_Panch, //パンチ
		enAttackState_Kick, //キック
		enAttackState_Num //攻撃数
	};

	AnimationClip m_animationClips[enAnimationClip_Num]; //アニメーションクリップ
	CharacterController m_charaCon; //キャラクターコントローラ
	ModelRender m_enemy; //モデル
	Vector3 m_position; //敵の位置
	Vector3 m_noMovePosition; //画面端に行ったときの位置
	Vector3 m_repulsion; //反発(画面端用)
	Vector3 m_moveSpeed; //敵の速度
	Vector3 m_side = Vector3::AxisX; //当たり判定の幅
	Vector3 m_up = Vector3::AxisY; //当たり判定の高さ
	Vector3 m_walk; //移動状態
	Vector3 m_jump; //ジャンプ状態
	Vector3 m_distance; //距離
	Quaternion m_rotation; //敵の方向
	int m_animationState = 0; //アニメーション状態
	//int m_finishflag = 0;
	int m_enemyHP = 100; //敵の体力
	int m_enemyMaxHP = 100; //敵の最大体力
	int m_damageCount = 0; //ダメージカウント(デバッグ用)
	float m_damageCountTime = 0.0f; //ダメージカウント時間(デバッグ用)
	int m_walkRandom = 0; //移動用ランダム
	int m_jumpRandom = 0; //ジャンプ用ランダム
	int m_jumpingRandom = 0; //斜めジャンプ用ランダム
	int m_attackRandom = 0; //攻撃用ランダム
	int m_guardRandom = 0; //ガード用ランダム
	int m_initSide = 0; //初期位置:〇側
	float m_move[enState_Num] = { 0.0f,0.0f,0.0f,0.0f,0.0f }; //敵の状態
	float m_timeRandom[enState_Num] = { 0.0f,0.0f,0.0f,0.0f,0.0f }; //ランダム用時間
	bool m_flagRandom[enState_Num]; //ランダム用フラグ
	bool m_collisionHitFlag = false; //当たり判定が当たったか？
	bool m_panchAttackCollision = false; //パンチ用当たり判定発生フラグ
	bool m_flyingPanchAttackCollision = false; //空中パンチ用当たり判定発生フラグ
	bool m_kickAttackCollision = false; //キック用当たり判定発生フラグ
	bool m_flyingKickAttackCollision = false; //空中キック用当たり判定発生フラグ
	bool m_noMove = false; //画面端フラグ
	bool m_moveFlag = false; //移動したか？(画面端用)
	bool m_moveJumpFlag = false; //ジャンプしたか？(画面端用)
	bool m_rotationRightFlag = false; //右向いているか？
	bool m_rotationLeftFlag = false; //左向いているか？
	bool m_rotationKeepFlag = false; //方向を固定
	bool m_upJumpFlag = false; //垂直ジャンプフラグ
	bool m_rightUpJumpFlag = false; //右斜めジャンプフラグ
	bool m_leftUpJumpFlag = false; //左斜めジャンプフラグ
	bool m_targetAttackFlag = false; //ターゲットが攻撃したか？
	bool m_upGuardFlag = false; //上段ガードフラグ
	bool m_downGuardFlag = false; //下段ガードフラグ
	bool m_upDamageFlag = false; //上段ダメージフラグ
	bool m_downDamageFlag = false; //下段ダメージフラグ
	bool m_flyDamageFlag = false; //空中ダメージフラグ
	bool m_panchAnimationFlag = false; //パンチアニメーションフラグ
	bool m_flyingPanchAnimationFlag = false; //空中パンチアニメーションフラグ
	bool m_kickAnimationFlag = false; //キックアニメーションフラグ
	bool m_flyingKickAnimationFlag = false; //空中キックアニメーションフラグ
	bool m_stepAnimationFlagRight = false; //右ステップアニメーションフラグ
	bool m_stepAnimationFlagLeft = false; //左ステップアニメーションフラグ
	bool m_damageFlag = false; //ダメージフラグ(デバッグ用)

	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Round* m_round = nullptr;
	GameCamera* m_gameCamera = nullptr;
};

