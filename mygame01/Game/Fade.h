#pragma once
class Fade: public IGameObject
{
public:
	Fade();
	~Fade();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//�����o�֐�
	/// �t�F�[�h�C���B
	void StartFadeIn()
	{
		m_fadeState = enState_FadeIn;
	}

	/// �t�F�[�h�A�E�g�B
	void StartFadeOut()
	{
		m_fadeState = enState_FadeOut;
	}

	/// �t�F�[�h�����H
	const bool IsFade() const
	{
		return m_fadeState != enState_Idle;
	}

	/// ���l���擾�B
	const float GetCurrentAlpha() const
	{
		return m_currentAlpha;
	}

	//�����o�ϐ�
	//�t�F�[�h���
	enum EnFadeState
	{
		enState_FadeIn,			//�t�F�[�h�C�����B
		enState_FadeOut,		//�t�F�[�h�A�E�g���B
		enState_Idle,			//�A�C�h�����B
	};
	SpriteRender m_spriteRender; //�t�F�[�h�p�w�i
	EnFadeState m_fadeState = enState_FadeIn; //�t�F�[�h�̏��
	float m_currentAlpha = 1.0f; //�t�F�[�h�p����
};

