#pragma once
#include"DxLib.h"
#include<vector>

struct objects;

struct effect {
	int time;
	int x;
	int y;
};

void draw_explosion(objects& objects1); //敵が倒された時のエフェクトを描画.
void effect_initialize(objects& objects1, int n); //初期化.
void draw_damage_square(objects& objects1); //ダメージを受けた時の赤い正方形を表示.


