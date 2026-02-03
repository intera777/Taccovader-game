#pragma once
#include"invadergame2.h"

void draw_background() {
	int img_background = LoadGraph("image/background.png");
	DrawGraph(0, 0, img_background, FALSE);
}