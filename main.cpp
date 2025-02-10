#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Hit.h"

const char kWindowTitle[] = "LC1B_25_ミヤシタツナグ_STGクラス化";

enum GAME { TITLE, PLAY };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	Enemy* enemy = new Enemy;
	Hit hit =  Hit();

	int scene = TITLE;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (scene) {
		default:
			break;
		case TITLE:
			///
			/// ↓更新処理ここから
			///

			if (keys[DIK_SPACE]) {
				player->isHit_ = false;
				scene = PLAY;
			}

			///
			/// ↑更新処理ここまで
			/// 

			///
			/// ↓描画処理ここから
			///

			Novice::ScreenPrintf(20, 20, "press space to start");

			///
			/// ↑描画処理ここまで
			///
			break;
		case PLAY:
			///
			/// ↓更新処理ここから
			///

			player->Update(keys, preKeys);
			enemy->Update();

			if (enemy->isActive_) {
				enemy->isHit_ = hit.isHit(enemy->pos_, enemy->radius_, player->bullet->pos_, player->bullet->radius_);
				player->isHit_ = hit.isHit(enemy->pos_, enemy->radius_, player->pos_,player->radius_);
			}

			if (player->GetIsHit()) {
				scene = TITLE;
			}

			///
			/// ↑更新処理ここまで
			/// 

			///
			/// ↓描画処理ここから
			///

			player->Draw();
			enemy->Draw();

			///
			/// ↑描画処理ここまで
			///
			break;
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
