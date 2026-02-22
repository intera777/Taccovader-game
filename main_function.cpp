#include"invadergame2.h"

//メインプレイ再開時の初期化.
void game_start_initialize(objects& objects1) {
	user_initialize(objects1);
	enemy_initialize(objects1);
	enemy_bullet_initialize(objects1);
	block_initialize(objects1);
	bullet_initialize(objects1);
	effect_initialize(objects1, ENEMYNUM);
	objects1.score = 0;
	change_background(objects1);
	objects1.timer_stage = 0;
}

void scene_change(int s, objects& objects1) { //引数は変更先のシーン.
	stop_allbgm();
	int& stage = objects1.stage;
	if (s == TITLE) {
		PlaySoundMem(BGM_TITLE, DX_PLAYTYPE_BACK, TRUE);
		stage = 1;
	}
	else if (s == PLAY) {
		PlaySoundMem(BGM_STAGE1, DX_PLAYTYPE_BACK | DX_PLAYTYPE_LOOP, TRUE);
		if (objects1.scene != CLEAR) {
			stage = 3; //特定のステージのテストをしたい場合はここを変更.
		}
	}
	else if (s == CLEAR) {
		PlaySoundMem(BGM_GAMECLEAR, DX_PLAYTYPE_BACK, TRUE);
		stage++;
	} else if (s == OVER) {
		PlaySoundMem(BGM_GAMEOVER, DX_PLAYTYPE_BACK, TRUE);
		stage = 1;
	}
	objects1.scene = s;
}