#pragma once
#include"DxLib.h"

extern int BACK1;
extern int BACK2;
extern int BACK3;
extern int BACK4;
extern int BACK5;
extern int BACK6;
extern int BACK7;
extern int BACK8;
extern int BACK9;
extern int BACK10;
extern int BACK_CLEAR;
extern int BACK_OVER;
extern int BACK_TITLE;

void background_initialize();
void draw_background(objects& objects1);
void change_background(objects& objects1);
void draw_backenemy(objects& objects1);
void draw_back_title();
void draw_back_clear();
void draw_back_over();