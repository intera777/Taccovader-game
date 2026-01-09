#pragma once
#include"invadergame2.h"

void draw_score(objects& objects1) {
	int s = objects1.score;
	DrawFormatString(WIDTH - 180, 0, WHITE, "ÉXÉRÉA: %d", s);
}