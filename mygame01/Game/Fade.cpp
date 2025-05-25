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
	//�t�F�[�h�w�i
	m_spriteRender.Init("Assets/screen/fade.dds", 1920.0f, 1080.0f);
	//�X�V
	m_spriteRender.Update();

	return true;
}

void Fade::Update()
{
	switch (m_fadeState)
	{
	case enState_FadeIn: //�����ɂ���
		m_currentAlpha -= 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f)
		{
			m_currentAlpha = 0.0f;
			m_fadeState = enState_Idle;
		}
		break;
	case enState_FadeOut: //�s�����ɂ���
		m_currentAlpha += 1.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f)
		{
			m_currentAlpha = 1.0f;
			m_fadeState = enState_Idle;
		}
	case enState_Idle: //�������Ȃ�
		break;
	}
}

void Fade::Render(RenderContext& rc)
{
	//�t�F�[�h�w�i�`��
	if (m_currentAlpha > 0.0f)
	{
		m_spriteRender.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
		m_spriteRender.Draw(rc);
	}
}