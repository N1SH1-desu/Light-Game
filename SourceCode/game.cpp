//******************************************************************************
//
//
//      ゲーム
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Game Game::instance_;

Game::Game() :
	isPaused(false)
	, background_(nullptr)
	, light_(nullptr)
{
	light_ = new light;
}

//--------------------------------
//  初期化処理
//--------------------------------
void Game::init()
{
	Scene::init();	    // 基底クラスのinitを呼ぶ

	isPaused = false;   // ポーズフラグの初期化

	background_ = sprite_load(L"Data/Images/background.png");

	light_->init();
}

//--------------------------------
//  終了処理
//--------------------------------
void Game::deinit()
{
	// テクスチャの解放
	texture::releaseAll();

	// 音楽のクリア
	music::clear();
}

//--------------------------------
//  更新処理
//--------------------------------
void Game::update()
{
	using namespace input;

	// ソフトリセット
	if ((STATE(0) & PAD_SELECT) &&  // 0コンのセレクトボタンが押されている状態で
		(TRG(0) & PAD_START))       // 0コンのスタートボタンが押された瞬間
	{
		changeScene(Title::instance());   // タイトルシーンに切り替える
		return;
	}

	// デバッグ文字列表示
	debug::setString("state:%d", state);
	debug::setString("timer:%d", timer);

	// ポーズ処理
	if (input::TRG(0) & PAD_START)
		isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
	if (isPaused) return;           // この時点でポーズ中ならリターン

	switch (state)
	{
	case 0:
		//////// 初期設定 ////////

		timer = 0;
		GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

		state++;    // 初期化処理の終了

		/*fallthrough*/     // case 1:の処理も同時に行う必要があるため、わざとbreak;を記述していない

	case 1:
		//////// 通常時の処理 ////////

		timer++;

		debug::setString("");
		debug::setString("Left Up Right Down");
		debug::setString("Z:Horizontal");
		debug::setString("X:Vertical");

		//ライト移動処理
		light_->update();

		break;
	}
}

//--------------------------------
//  描画処理
//--------------------------------
void Game::draw()
{
	// 画面クリア
	GameLib::clear(VECTOR4(0, 0, 0, 1));

	// ステンシルモード：通常
	DepthStencil::instance().set(DepthStencil::MODE::NONE);

	//バックグラウンド描画
	sprite_render(background_, 0, 0, 1, 1, 0, 0, 1920, 1080);

	//ライト描画
	light_->render();

}

//******************************************************************************
