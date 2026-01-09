#pragma once
#include"invadergame2.h"

void draw_explosion(objects& objects1){
	vector<effect>& eff = objects1.exp_eff;
	int img_explosion = LoadGraph("image/explosion.png");
	for (int i = 0; i < ENEMYNUM; i++) {
		if (eff.at(i).time > 0) {
			DrawGraph(eff.at(i).x, eff.at(i).y, img_explosion, FALSE);
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