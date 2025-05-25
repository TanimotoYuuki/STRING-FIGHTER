#include "stdafx.h"
#include "Fade.h"

Fade::Fade()
{

}

Fade::~Fade()
{

}

bool Fade::Start()
{
	//フェード背景
	m_spriteRender.Init("Assets/screen/fade.dds", 1920.0f, 1080.0f);
	//更新
	m_spriteRender.Update();

	return true;
}

void Fade::Update()
{
	switch (m_fadeState)
	{
	case enState_FadeIn: //透明にする
		m_currentAlpha -= 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f)
		{
			m_currentAlpha = 0.0f;
			m_fadeState = enState_Idle;
		}
		break;
	case enState_FadeOut: //不透明にする
		m_currentAlpha += 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f)
		{
			m_currentAlpha = 1.0f;
			m_fadeState = enState_Idle;
		}
	case enState_Idle: //何もしない
		break;
	}
}

void Fade::Render(RenderContext& rc)
{
	//フェード背景描画
	if (m_currentAlpha > 0.0f)
	{
		m_spriteRender.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
		m_spriteRender.Draw(rc);
	}
}