#pragma once
#include"invadergame2.h"

void draw_explosion(objects& objects1) {
	vector<effect>& eff = objects1.exp_eff;
	int img_explosion = LoadGraph("image/explosion.png");
	for (int i = 0; i < ENEMYNUM; i++) {
		if (eff.at(i).time > 0) {
			DrawGraph(eff.at(i).x, eff.at(i).y, img_explosion, TRUE);
			eff.at(i).time--;
		}
	}
}

void effect_initialize(objects& objects1, int n) {
	vector<effect>& eff = objects1.exp_eff;
	for (int i = 0; i < n; i++) {
		eff.at(i).x = -100;
		eff.at(i).y = -100;
		eff.at(i).time = 0;
	}
}

void draw_damage_square(objects& objects1) {
	user user1 = objects1.user1;
	int& t = objects1.user1.damage_timer;
	if (t > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawBox(user1.x, user1.y, user1.x + USER_SIZE, user1.y + USER_SIZE, GetColor(255, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		t--;
	}
}