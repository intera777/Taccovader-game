#include"invadergame2.h"
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ldCmdLine, int nCmdShow)
{

	SetWindowText("インベーダーゲーム");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	objects objects1;

	user& user1 = objects1.user1; //ユーザーの情報を持つ構造体.
	vector<bullet>& bul = objects1.bul; //弾の情報を持つ構造体の配列.
	vector<bullet>& ene_bul = objects1.ene_bul; //敵が撃つ弾の情報を持つ構造体の配列.
	vector<enemy>& ene = objects1.ene; //敵の情報を持つ構造体の配列.
	vector<block>& blo = objects1.blo; //ブロックの情報を持つ構造体の配列.
	vector<effect>& exp_eff = objects1.exp_eff; //敵が倒された時のエフェクトの情報を持つ構造体.
	vector<enemy>& ene_back = objects1.ene_back; //メニュー画面の背景の敵の情報を持つ構造体の配列.

	vector<enemy> ene_background; //メニュー画面の背景の敵の情報を持つ構造体の配列.


	//配列の大きさを指定.
	bul.resize(MAXBULLETNUM);
	ene_bul.resize(ENEMYNUM);
	ene.resize(ENEMYNUM);
	blo.resize(BLOCKNUM);
	exp_eff.resize(ENEMYNUM);
	ene_back.resize(ENEMYNUM_BACK);

	objects1.bullet_cooltime = 0; //再び銃弾が発射可能になるまでの時間.

	//敵関係の定数
	objects1.enemy_cycle = 0; //敵の動きが一周したらリセット.
	objects1.enemy_bullet_cooltime = 0;

	objects1.score = 0;
	objects1.stage = 3;//現在のステージ.

	int& bullet_cooltime = objects1.bullet_cooltime;
	int& enemy_cycle = objects1.enemy_cycle;
	int& enemy_bullet_cooltime = objects1.enemy_bullet_cooltime;
	int& score = objects1.score;
	int& stage = objects1.stage;

	int& scene = objects1.scene;

	sound_initialize();

	background_initialize();

	sentence_initialize();

	load_img_enemy();

	load_user_bullet();

	scene_change(TITLE, objects1);

	while (1) {
		ClearDrawScreen();

		if (scene == END) { break; }
		switch (scene) {

		case TITLE: {
			draw_back_title();
			DrawStringToHandle(97, HEIGHT / 3 - 3, "TACCOVADER GAME", ORANGE, FONT_TITLE);
			DrawStringToHandle(100, HEIGHT / 3, "TACCOVADER GAME", WHITE, FONT_TITLE);
			DrawStringToHandle(250, HEIGHT * 2 / 3, "Sキーを押すとゲームを開始します", WHITE, FONT_TITLE_SMALL);
			DrawStringToHandle(250, HEIGHT * 3 / 4, "右移動:L 左移動:J 弾発射: Z", WHITE, FONT_TITLE_SMALL);
			DrawStringToHandle(700, HEIGHT * 5 / 6, "ver 1.0.0", WHITE, FONT_TITLE_SMALL);
			if (CheckHitKey(KEY_INPUT_S) == 1) {
				scene_change(PLAY, objects1);
				game_start_initialize(objects1);

				//クリア画面のデバック用.
				/*scene_change(CLEAR, objects1);
				Sleep(1000);
				game_start_initialize(objects1);*/
			}
			break;
		}

		case PLAY:

			draw_background(objects1);
			//ユーザーの移動.
			move_user(objects1);

			//ユーザーの描画
			draw_user(objects1);

			draw_damage_square(objects1);


			check_block_bullet(objects1);
			draw_block(objects1);

			//爆発のエフェクトを描画.
			draw_explosion(objects1);


			//敵が全て倒されたかチェック.
			check_enemy_completed(objects1);

			//敵が倒されたかチェック
			check_enemy(objects1);

			//敵の移動.
			move_enemy(objects1);

			//敵の描画.
			draw_enemy(objects1);

			//敵が倒された時のエフェクトの描画.

			//銃弾の移動.
			bullet_move(objects1, BULLET_RAD, -20);

			draw_bullet(objects1, BULLET_RAD, WHITE);
			//銃弾の生成.
			bullet_appear(objects1);

			//敵の銃弾の生成.
			enemy_bullet_appear(objects1);

			//敵の銃弾の移動.
			enemy_bullet_move(objects1, BULLET_RAD, 20);

			//敵の銃弾の描画.
			enemy_draw_bullet(objects1, BULLET_RAD, ORANGE);

			check_block_enemybullet(objects1);

			check_user_alive(objects1);

			draw_score(objects1);

			draw_hp(objects1);

			SetFontSize(20);
			DrawString(10, 10, "Hキーを押すと操作方法が表示されます", WHITE);

			//ここで画面に操作方法を表示する処理.
			if (CheckHitKey(KEY_INPUT_H) == 1) {
				draw_howtooperate();
			}

			if (user1.state == 0) {
				scene_change(OVER, objects1);
			}
			break;

		case OVER:
			draw_back_over();
			DrawStringToHandle(250, HEIGHT / 2, "GAME OVER!", WHITE, FONT_TITLE);
			DrawStringToHandle(300, HEIGHT * 2 / 3, "Sキーを押すとリスタートします", WHITE, FONT_TITLE_SMALL);
			DrawStringToHandle(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE, FONT_TITLE_SMALL);
			if (CheckHitKey(KEY_INPUT_S) == 1) {
				scene_change(TITLE, objects1);
			}
			else if (CheckHitKey(KEY_INPUT_Q) == 1) {
				scene_change(END, objects1);
			}
			break;

		case CLEAR:
			draw_back_clear();
			draw_backenemy(objects1);
			if (stage <= 5) { //次のステージがある場合.
				DrawStringToHandle(250, HEIGHT / 2, "STAGE CLEAR!", WHITE, FONT_TITLE_FRAME);
				DrawStringToHandle(300, HEIGHT * 2 / 3, "Sキーを押すと次のステージへ進みます", WHITE, FONT_TITLE_SMALL);
				DrawStringToHandle(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE, FONT_TITLE_SMALL);
				if (CheckHitKey(KEY_INPUT_S) == 1) {
					scene_change(PLAY, objects1);
					game_start_initialize(objects1);
				}
				else if (CheckHitKey(KEY_INPUT_Q) == 1) {
					scene_change(END, objects1);
				}
			}
			else {
				display_credit();
				DrawStringToHandle(250, HEIGHT / 2, "GAME CLEAR!", WHITE, FONT_TITLE_FRAME);
				DrawStringToHandle(300, HEIGHT * 2 / 3, "Sキーを押すとタイトル画面に戻ります", WHITE, FONT_TITLE_SMALL);
				DrawStringToHandle(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE, FONT_TITLE_SMALL);
				if (CheckHitKey(KEY_INPUT_S) == 1) {
					scene_change(TITLE, objects1);
					Sleep(300);
				}
				else if (CheckHitKey(KEY_INPUT_Q) == 1) {
					scene_change(END, objects1);
				}
			}
			break;
		}
		ScreenFlip();
		WaitTimer(33);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}


	DxLib_End();
	return 0;
}