#pragma once
class Game;
class Round;
class GameTimer: public IGameObject
{
public:
	GameTimer();
	~GameTimer();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//メンバ関数
	//ラウンドが終わったら変数の値をリセットする
	void Reset()
	{
		m_time = 99.9f;
		m_timeFirstView = 0;
		m_timeSecondView = 0;
	}

	//メンバ変数

	SpriteRender m_timeFirstNumber[10]; //残り時間下2桁目
	SpriteRender m_timeSecondNumber[10]; //残り時間下1桁目
	float m_time = 99.9f; //残り時間
	int m_timeFirstView = 0; //残り時間下2桁整数変換
	int m_timeSecondView = 0; //残り時間下1桁整数変換

	Game* m_game = nullptr;
	Round* m_round = nullptr;
};

