#pragma once
class Round;
class Result: public IGameObject
{
public:
	Result();
	~Result();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//�����o�ϐ�

	SpriteRender m_1pWin[2]; //1P����
	SpriteRender m_2pWin[2]; //2P����
	SpriteRender m_enemyWin[2]; //�G����
	SpriteRender m_draw; //��������

	Round* m_round = nullptr;
};

