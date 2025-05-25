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

	//ƒƒ“ƒo•Ï”

	SpriteRender m_1pWin[2]; //1PŸ—˜
	SpriteRender m_2pWin[2]; //2PŸ—˜
	SpriteRender m_enemyWin[2]; //“GŸ—˜
	SpriteRender m_draw; //ˆø‚«•ª‚¯

	Round* m_round = nullptr;
};

