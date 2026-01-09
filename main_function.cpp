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