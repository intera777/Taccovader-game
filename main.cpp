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

	user& user1=objects1.user1; //ユーザーの情報を持つ構造体.
	vector<bullet>& bul=objects1.bul; //弾の情報を持つ構造体の配列.
	vector<bullet>& ene_bul=objects1.ene_bul; //敵が撃つ弾の情報を持つ構造体の配列.
	vector<enemy>& ene=objects1.ene; //敵の情報を持つ構造体の配列.
	vector<block>& blo=objects1.blo; //ブロックの情報を持つ構造体の配列.
	vector<effect>& exp_eff=objects1.exp_eff; //敵が倒された時のエフェクトの情報を持つ構造体.
	
	//配列の大きさを指定.
	bul.resize(MAXBULLETNUM);
	ene_bul.resize(ENEMYNUM);
	ene.resize(ENEMYNUM);
	blo.resize(BLOCKNUM);
	exp_eff.resize(ENEMYNUM);

	objects1.bullet_cooltime = 0; //再び銃弾が発射可能になるまでの時間.

	//敵関係の定数
	objects1.enemy_cycle= 0; //敵の動きが一周したらリセット.
	objects1.enemy_bullet_cooltime = 0;

	objects1.score = 0;
	objects1.stage = 1;//現在のステージ.
	objects1.scene = TITLE;

	int& bullet_cooltime = objects1.bullet_cooltime;
	int& enemy_cycle = objects1.enemy_cycle;
	int& enemy_bullet_cooltime = objects1.enemy_bullet_cooltime;
	int& score = objects1.score;
	int& stage = objects1.stage;

	int& scene = objects1.scene;

	while (1) {
		ClearDrawScreen();

		if (scene == END) { break; }
		switch (scene) {

		case TITLE:
			SetFontSize(50);
			DrawString(200, HEIGHT / 2, "インベーダーゲーム(仮)", WHITE);
			SetFontSize(20);
			DrawString(250, HEIGHT * 2 / 3, "Sキーを押すとゲームを開始します", WHITE);
			DrawString(250, HEIGHT * 3 / 4, "右移動:L 左移動:J 弾発射: Z", WHITE);
			DrawString(700, HEIGHT * 5 / 6, "ver 0.0.2", WHITE);
			if (CheckHitKey(KEY_INPUT_S) == 1) { 
				scene = PLAY;
				game_start_initialize(objects1);
			}
			break;

		case PLAY:


			//ユーザーの移動.
			move_user(objects1);

			//ユーザーの描画
			draw_user(objects1);

			
			check_block_bullet(objects1);
			draw_block(objects1);

			//爆発のエフェクトを描画.
			draw_explosion(exp_eff);


			//敵が全て倒されたかチェック.
			check_enemy_completed(objects1);

			//敵が倒されたかチェック
			check_enemy(objects1);

			//敵の移動.
			move_enemy(objects1);

			//敵の描画.
			draw_enemy(objects1);

			//敵が倒された時のエフェクトの描画.
			draw_explosion(exp_eff);

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

			check_user_alive(objects1, scene);

			draw_score(score);

			draw_hp(objects1);

			SetFontSize(20);
			DrawString(10, 10, "Hキーを押すと操作方法が表示されます", WHITE);

			//ここで画面に操作方法を表示する処理.
			if (CheckHitKey(KEY_INPUT_H) == 1) {
				draw_howtooperate();
			}

			if (user1.state == 0) { scene = OVER; }
			break;

		case OVER:
			SetFontSize(50);
			DrawString(250, HEIGHT / 2, "ゲームオーバー", WHITE);
			SetFontSize(20);
			DrawString(300, HEIGHT * 2 / 3, "Sキーを押すとリスタートします", WHITE);
			DrawString(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE);
			if (CheckHitKey(KEY_INPUT_S) == 1) { scene = TITLE;}
			else if (CheckHitKey(KEY_INPUT_Q) == 1) { scene = END; }
			break;

		case CLEAR:
			SetFontSize(50);
			if(stage==1){
				DrawString(300, HEIGHT / 2, "ステージクリア!", WHITE);
				SetFontSize(20);
				DrawString(300, HEIGHT * 2 / 3, "Sキーを押すと次のステージへ進みます", WHITE);
				DrawString(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE);
				if (CheckHitKey(KEY_INPUT_S) == 1) {
					scene = PLAY;
					stage++;
					game_start_initialize(objects1);
				}
				else if (CheckHitKey(KEY_INPUT_Q) == 1) {
					scene = END;
				}
			}
			else {
				DrawString(250, HEIGHT / 2, "ゲームクリア!", WHITE);
				SetFontSize(20);
				DrawString(300, HEIGHT * 2 / 3, "Sキーを押すとリスタートします", WHITE);
				DrawString(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE);
				if (CheckHitKey(KEY_INPUT_S) == 1) { scene = TITLE; }
				else if (CheckHitKey(KEY_INPUT_Q) == 1) { scene = END; }
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