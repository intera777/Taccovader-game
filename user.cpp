#pragma once
#include"invadergame2.h"

void draw_user(objects& objects1) {
	int& x = objects1.user1.x;
	int& y = objects1.user1.y;
	int img_user = LoadGraph("image/user.png");
	DrawGraph(x, y, img_user, TRUE);
	//DrawBox(x, y, x + 40, y + 40, BLUE, TRUE);
	//DrawBox(x + 10, y, x + 30, y + 20, WHITE, TRUE);
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

void check_user_alive(objects& objects1) {
	int& scene = objects1.scene;
	vector<enemy>& ene = objects1.ene;
	vector<bullet>& ene_bul = objects1.ene_bul;
	user& user1 = objects1.user1;
	
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 0) { continue; }
		int ex = ene.at(i).x, ey = ene.at(i).y;
		//“G‚ª‰æ–Ê‰º‚Ü‚Å”—‚Á‚Ä‚«‚½‚Æ‚«
		if (ey + BULLET_RAD > HEIGHT - 140) { user1.hp--; }
		if (check_user_enemy(objects1) == 1) { //“G‚Æƒ†[ƒU[‚ª’¼ÚÚG‚µ‚Ä‚¢‚½‚çI—¹.
			user1.hp = 0;
			break;
		}
		if (check_user_enemybullet(objects1) == 1) {
			PlaySoundMem(SE_USER_DAMAGED, DX_PLAYTYPE_BACK, TRUE);
			user1.hp--;
			user1.damage_timer = DAMAGE_TIMER;
			break;
		}
	}
	if (user1.hp <= 0) {
		scene_change(OVER, objects1);
	}
}

void user_initialize(objects& objects1) {
	user& user1 = objects1.user1;
	user1.x = WIDTH / 2;
	user1.y = HEIGHT - 40;
	user1.state = 1;
	user1.hp = 3;
	user1.damage_timer = 0;
}

void draw_hp(objects& objects1) {
	user& user1 = objects1.user1;
	DrawFormatString(WIDTH - 180, 20, WHITE, "HP: %d", user1.hp);
}

void user_background_initialize(objects& objects1) {
	user& user_back = objects1.user_back;
	user_back.x = 180;
	user_back.y = HEIGHT - 40;
	user_back.state = 1;
	user_back.hp = 3;
}

void check_user_background(objects& objects1) {
	user& user_back = objects1.user_back;
	if (user_back.x < 0 || WIDTH < user_back.x || user_back.y < 0 || HEIGHT < user_back.y) {
		user_back.state = 0;
	}
}

void draw_user_back(objects& objects1) {
	user& user_back = objects1.user_back;
	int img_user = LoadGraph("image/user.png");
	if (user_back.state == 1) {
		DrawGraph(user_back.x, user_back.y, img_user, TRUE);
		user_back.y -= 3;
		check_user_background(objects1);
	}
}