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

	//メンバ変数

	SpriteRender m_1pWin[2]; //1P勝利
	SpriteRender m_2pWin[2]; //2P勝利
	SpriteRender m_enemyWin[2]; //敵勝利
	SpriteRender m_draw; //引き分け

	Round* m_round = nullptr;
};

