#include"invadergame2.h"

void game_start_initialize(objects& objects1) {
	user_initialize(objects1);
	enemy_initialize(objects1);
	enemy_bullet_initialize(objects1);
	block_initialize(objects1);
	bullet_initialize(objects1);
	effect_initialize(objects1, ENEMYNUM);
	objects1.score = 0;
}

void scene_change(int s, objects& objects1) { //à¯êîÇÕïœçXêÊÇÃÉVÅ[Éì.
	stop_allbgm();
	objects1.scene = s;
	if (s == TITLE) {
		PlaySoundMem(BGM_TITLE, DX_PLAYTYPE_BACK, TRUE);
	}
	else if (s == PLAY) {
		PlaySoundMem(BGM_STAGE1, DX_PLAYTYPE_BACK | DX_PLAYTYPE_LOOP, TRUE);
	}
	else if (s == CLEAR) {
		PlaySoundMem(BGM_GAMECLEAR, DX_PLAYTYPE_BACK, TRUE);
	} else if (s == OVER) {
		PlaySoundMem(BGM_GAMEOVER, DX_PLAYTYPE_BACK, TRUE);
	}
}