#pragma once
class Fade;
class Game;
class Title: public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//メンバ関数
	//拳のイージング設定
	void FistSetEasing();

	//拳のイージング
	void FistEasing();

	//タイトル名のイージング設定
	void TitleNameSetEasing();

	//タイトル名のイージング
	void TitleNameEasing();

	//1P:〇側選択の移動イージング設定
	void Player1SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition);	

	//2P:〇側選択の移動イージング設定
	void Player2SideMoveSetEasing(int mode,SpriteRender& target,Vector3 initPosition);

	//1P:〇側選択の移動イージング
	void Player1SideMoveEasing(SpriteRender& target);	

	//2P:〇側選択の移動イージング
	void Player2SideMoveEasing(SpriteRender& target);
	
	//フェード
	void ObjectFade();

	//選択・移動
	void Move();

	//プレイヤー〇側選択
	void PlayerSide();

	//1P VS CPU 用〇側選択・移動
	void OnePlayerSideMove();

	//1P VS 2P 用〇側選択・移動
	void TwoPlayerSideMove();

	//メンバ変数
	//選択状態
	enum enSelectState
	{
		enSelectState_Up, //上
		enSelectState_Down, //下
		enSelectState_Num //選択状態数
	};

	//ボタン状態
	enum enButtonState
	{
		enButtonState_A, //Aボタン
		enButtonState_B, //Bボタン
		enButtonState_X, //Xボタン
		enButtonState_Y, //Yボタン
		enButtonState_Num //ボタン状態数
	};

	//〇側状態
	enum enSideState
	{
		enSideState_Left, //左側
		enSideState_Right, //右側
		enSideState_Num, //〇側数
	};

	//〇側選択状態
	enum enSideSelectState
	{
		enSideSelectState_Left, //左側
		enSideSelectState_Right, //右側
		enSideSelectState_Center, //中央
		enSideSelectState_Num, //〇側選択数
	};

	SpriteRender m_titleBackGround; //タイトル背景
	SpriteRender m_fist; //拳
	SpriteRender m_titleName; //タイトル名
	SpriteRender m_pressButton; //プレスボタン
	SpriteRender m_mode; //モード
	SpriteRender m_vs[2]; //〇〇 VS 〇〇
	SpriteRender m_1p; //1P
	SpriteRender m_2p; //2P
	SpriteRender m_cpu[enSideState_Num]; //cpu
	SpriteRender m_playerSide[enSideSelectState_Num]; //プレイ中のプレイヤーの初期位置:〇側
	SpriteRender m_sideSelectText; //〇側の選択を促すテキスト
	SpriteRender m_select[enSelectState_Num]; //選択
	SpriteRender m_button[enButtonState_Num]; //ボタン

	FontRender m_text[50]; //テキスト

	Vector3 m_fistScale; //拳(大きさ)
	Vector3 m_fistScaleA; //拳(大きさ: イージング開始)
	Vector3 m_fistScaleB; //拳(大きさ: イージング終了)
	float m_fistT = 0.0f; //拳(イージング時間)
	bool m_fistSetEasingFlag = false; //拳イージング設定終了フラグ

	Vector3 m_titleNamePosition; //タイトル名(位置)
	Vector3 m_titleNamePositionA; //タイトル名(位置: イージング開始)
	Vector3 m_titleNamePositionB; //タイトル名(位置: イージング終了)
	float m_titleNameT = 0.0f; //タイトル名(イージング時間)
	bool m_titleNameSetEasingFlag = false; //タイトル名イージング設定終了フラグ	

	Vector3 m_1pSideSelectInitPosition; //1P:〇側選択用初期位置
	Vector3 m_1psideSelectPosition; //1P:〇側選択(位置)
	Vector3 m_1psideSelectPositionA; //1P:〇側選択(位置: イージング開始)
	Vector3 m_1psideSelectPositionB; //1P:〇側選択(位置: イージング終了)
	float m_1psideSelectT = 0.0f; //1P:〇側選択(イージング時間)
	bool m_1psideSelectSetEasingFlag = false; //1P:〇側選択イージング設定終了フラグ	

	Vector3 m_2pSideSelectInitPosition; //2P:〇側選択用初期位置
	Vector3 m_2psideSelectPosition; //2P:〇側選択(位置)
	Vector3 m_2psideSelectPositionA; //2P:〇側選択(位置: イージング開始)
	Vector3 m_2psideSelectPositionB; //2P:〇側選択(位置: イージング終了)
	float m_2psideSelectT = 0.0f; //2P:〇側選択(イージング時間)
	bool m_2psideSelectSetEasingFlag = false; //2P:〇側選択イージング設定終了フラグ

	float m_alpha = 0.0f; //透明度
	float m_halfFade = 1.0f; //フェード(半透明)
	float m_allfade = 1.0f; //フェード(透明)
	float m_pressButtonTime = 1.0f; //プレスボタン時間
	float m_selectTime = 1.0f; //選択時間
	float m_sideSelectTime = 1.0f; //〇側選択時間
	int m_selectNum = enSelectState_Up; //選択状態
	int m_onePlayerSideSelectNum = enSideSelectState_Center; //〇側選択状態(1P VS CPU)
	int m_twoPlayerSideSelectNum[2] = { enSideSelectState_Center,enSideSelectState_Center }; //〇側選択状態(1P VS 2P)
	int m_intTime = 0; //整数変換
	int m_gamepad = 2; //接続できるコントローラの数

	bool m_moveFlag = false; //スタート・モード操作フラグ
	bool m_sideMoveFlag = false; //〇側操作フラグ
	bool m_onePlayerSideMoveSelectFlag = false; //〇側選択操作フラグ(1P VS CPU)
	bool m_twoPlayerSideMoveSelectFlag[2] = { false ,false }; //〇側選択操作フラグ(1P VS 2P)
	bool m_pressButtonfadeFlag = false; //半透明フラグ
	bool m_selectFlag = false; //選択フラグ
	bool m_selectFadeFlag = false; //選択用透明フラグ
	bool m_flashingFlag = false; //点滅フラグ
	bool m_halfFadeFlag = false; //半透明フラグ
	bool m_halfFadeFinishFlag = false; //半透明終了フラグ
	bool m_brightenFlag = false; //不透明フラグ
	bool m_roadFlag = false; //ロードフラグ
	bool m_1pVScpuSelectFlag = false; //1P VS 2P 選択フラグ
	bool m_1pVS2pSelectFlag = false; //1P VS 2P 選択フラグ
	bool m_inGameFlag = false; //インゲームフラグ

	Fade* m_fade = nullptr;
	Game* m_game = nullptr;
	SoundSource* m_bgm = nullptr;
};

