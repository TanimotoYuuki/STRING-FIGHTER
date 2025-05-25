#pragma once
class Game;
class Round;
class Frame: public IGameObject
{
public:
	Frame();
	~Frame();
	bool Start();
	void Update();

	//メンバ関数
	//引数に値を入力したらその値をフレーム換算する
	float GetFrame(float frame)
	{
		m_getFrame = frame / 60;
		return m_getFrame;
	}

	void FrameState();

	//ラウンドが終わったら変数の値をリセットする
	void Reset()
	{
		m_playerMoveState = 0;
		m_player2MoveState = 0;
		m_playertenkey = 0;
		m_player2tenkey = 0;

		for (int i = 0; i < 9; i++)
		{
			m_playerframe[i] = 0.0f;
		}

		for (int i = 0; i < 9; i++)
		{
			m_player2frame[i] = 0.0f;
		}
		m_frameDash = 0.0f;
	}

	//メンバ変数
	//スティック方向状態
	enum EnDirectionState
	{
		enDirectionState_Idle, //中央
		enDirectionState_Right, //右
		enDirectionState_Right_Up, //右上
		enDirectionState_Right_Down, //右下
		enDirectionState_Left, //左
		enDirectionState_Left_Up, //左上
		enDirectionState_Left_Down, //左下
		enDirectionState_Up, //上
		enDirectionState_Down, //下
		enDirectionState_NUM //スティック方向状態数
	};
	int m_playerMoveState = 0; //プレイヤー用スティック方向状態
	int m_player2MoveState = 0; //プレイヤー2用スティック方向状態
	int m_playertenkey = 0; //プレイヤー用テンキー
	int m_player2tenkey = 0; //プレイヤー2用テンキー
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
	float m_playerframe[9] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; //プレイヤー用フレーム管理
	float m_player2frame[9] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; //プレイヤー2用フレーム管理
	float m_getFrame = 0.0f; //フレーム取得
	float m_frameDash = 0.0f; //ダッシュフレーム

	Game* m_game = nullptr;
	Round* m_round = nullptr;
};

