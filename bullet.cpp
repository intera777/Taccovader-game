#pragma once
#include"invadergame2.h"

void bullet_appear(objects& objects1) {
	int& cooltime = objects1.bullet_cooltime;
	vector<bullet>& vec = objects1.bul;
	int& x = objects1.user1.x;
	int& y = objects1.user1.y;
	if (cooltime > 0) { cooltime--; }
	else if(CheckHitKey(KEY_INPUT_Z)==1){
		for (int i = 0; i < MAXBULLETNUM; i++) {
			if (vec.at(i).state == 0) {
				vec.at(i).state = 1;
				vec.at(i).x = x;
				vec.at(i).y = y;
				cooltime = BULLET_COOLTIME;
				break;
			}
		}
	}
}

void bullet_move(objects& objects1, int r,int move_vector) {
	vector<bullet>& vec = objects1.bul;
	for (int i = 0; i < MAXBULLETNUM; i++) {
		if (vec.at(i).state == 1) {
			vec.at(i).y +=move_vector;
			if (vec.at(i).y < r) {
				vec.at(i).x = -100; vec.at(i).y = -100; vec.at(i).state = 0;
			}
		}
	}
}

void draw_bullet(objects objects1, int r, int color) {
	vector<bullet>bul = objects1.bul;
	for (int i = 0; i < MAXBULLETNUM; i++) {
		if (bul.at(i).state == 1) {
			DrawCircle(bul.at(i).x, bul.at(i).y, r, color, TRUE);
		}
	}
}

void bullet_initialize(objects& objects1) {
	vector<bullet>& bul = objects1.bul;
	for (int i = 0; i < MAXBULLETNUM; i++) {
		bul.at(i).x = -100; bul.at(i).y = -100; bul.at(i).state = 0;
	}
}