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

	//�����o�֐�
	//���E���h���I�������ϐ��̒l�����Z�b�g����
	void Reset()
	{
		m_time = 99.9f;
		m_timeFirstView = 0;
		m_timeSecondView = 0;
	}

	//�����o�ϐ�

	SpriteRender m_timeFirstNumber[10]; //�c�莞�ԉ�2����
	SpriteRender m_timeSecondNumber[10]; //�c�莞�ԉ�1����
	float m_time = 99.9f; //�c�莞��
	int m_timeFirstView = 0; //�c�莞�ԉ�2�������ϊ�
	int m_timeSecondView = 0; //�c�莞�ԉ�1�������ϊ�

	Game* m_game = nullptr;
	Round* m_round = nullptr;
};

