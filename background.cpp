#pragma once
#include"invadergame2.h"
using namespace std;


//10Ží—Þ‚Ì”wŒi‚ÌƒpƒX.
int BACK1;
int BACK2;
int BACK3;
int BACK4;
int BACK5;
int BACK6;
int BACK7;
int BACK8;
int BACK9;
int BACK10;

void background_initialize() {
	BACK1 = LoadGraph("image/back1.png");
	BACK2 = LoadGraph("image/back2.png");
	BACK3 = LoadGraph("image/back3.png");
	BACK4 = LoadGraph("image/back4.png");
	BACK5 = LoadGraph("image/back5.png");
	BACK6 = LoadGraph("image/back6.png");
	BACK7 = LoadGraph("image/back7.png");
	BACK8 = LoadGraph("image/back8.png");
	BACK9 = LoadGraph("image/back9.png");
	BACK10 = LoadGraph("image/back10.png");
}

void draw_background(objects& objects1) {
	int img_background = objects1.current_background;
	DrawGraph(0, 0, img_background, FALSE);
}

void change_background(objects& objects1) {
	int& bg = objects1.current_background;
	int temp;

	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dis(1, 10);
	temp = dis(gen);

	switch (temp) {
	case 1:
		bg = BACK1;
		break;
	case 2:
		bg = BACK2;
		break;
	case 3:
		bg = BACK3;
		break;
	case 4:
		bg = BACK4;
		break;
	case 5:
		bg = BACK5;
		break;
	case 6:
		bg = BACK6;
		break;
	case 7:
		bg = BACK7;
		break;
	case 8:
		bg = BACK8;
		break;
	case 9:
		bg = BACK9;
		break;
	case 10:
		bg = BACK10;
		break;
	dafault:
		bg = BACK1;
		break;
	}
}