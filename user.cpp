#pragma once
#include"invadergame2.h"

void draw_user(objects& objects1) {
	int& x = objects1.user1.x;
	int& y = objects1.user1.y;
	DrawBox(x, y, x + 40, y + 40, BLUE, TRUE);
	DrawBox(x + 10, y, x + 30, y + 20, WHITE, TRUE);
}

void move_user(objects& objects1) {
	int& x = objects1.user1.x;
	int& y = objects1.user1.y;
	if (CheckHitKey(KEY_INPUT_J) && x > 9) {
		x -= 10;
	}
	else if (CheckHitKey(KEY_INPUT_L) && x < WIDTH - 10) {
		x += 10;
	}
}

void check_user_alive(objects& objects1, int& scene) {
	vector<enemy>& ene = objects1.ene;
	vector<bullet>& ene_bul = objects1.ene_bul;
	user& user1 = objects1.user1;
	
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 0) { continue; }
		int ex = ene.at(i).x, ey = ene.at(i).y;
		//“G‚ª‰æ–Ê‰º‚Ü‚Å”—‚Á‚Ä‚«‚½‚Æ‚«
		if (ey + BULLET_RAD > HEIGHT - 140) { user1.hp--; }
		if (check_user_enemy(ene, user1) == 1) { //“G‚Æƒ†[ƒU[‚ª’¼ÚÚG‚µ‚Ä‚¢‚½‚çI—¹.
			scene = OVER; break;
		}
		if (check_user_enemybullet(ene_bul, user1) == 1) {
			user1.hp--; break;
		}
	}
	if (user1.hp <= 0) {
		scene = OVER;
	}
}

void user_initialize(objects& objects1) {
	user& user1 = objects1.user1;
	user1.x = WIDTH / 2;
	user1.y = HEIGHT - 40;
	user1.state = 1;
	user1.hp = 3;
}

void draw_hp(objects& objects1) {
	user& user1 = objects1.user1;
	DrawFormatString(WIDTH - 180, 20, WHITE, "HP: %d", user1.hp);
}