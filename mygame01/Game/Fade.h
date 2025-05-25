#pragma once
class Fade: public IGameObject
{
public:
	Fade();
	~Fade();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//メンバ関数
	/// フェードイン。
	void StartFadeIn()
	{
		m_fadeState = enState_FadeIn;
	}

	/// フェードアウト。
	void StartFadeOut()
	{
		m_fadeState = enState_FadeOut;
	}

	/// フェード中＞？
	const bool IsFade() const
	{
		return m_fadeState != enState_Idle;
	}

	/// α値を取得。
	const float GetCurrentAlpha() const
	{
		return m_currentAlpha;
	}

	//メンバ変数
	//フェード状態
	enum EnFadeState
	{
		enState_FadeIn,			//フェードイン中。
		enState_FadeOut,		//フェードアウト中。
		enState_Idle,			//アイドル中。
	};
	SpriteRender m_spriteRender; //フェード用背景
	EnFadeState m_fadeState = enState_FadeIn; //フェードの状態
	float m_currentAlpha = 1.0f; //フェード用時間
};

