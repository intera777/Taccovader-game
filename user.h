#pragma once
#include"DxLib.h"
#include<vector>

struct bullet;
struct enemy;
struct objects;

struct user {
	int x; //ユーザーの左上の座標.
	int y;
	int state; //0のときは死んでおり,1のときは生きている.
	int hp;
};

const int USER_SIZE = 40; //ユーザーのサイズ.

void draw_user(objects& objects1);
void move_user(objects& objects1);
void check_user_alive(objects& objects1);
void user_initialize(objects& objects1); //ユーザー情報を初期化.
void draw_hp(objects& objects1); //ユーザーのHPの描画.
void user_background_initialize(objects& objects1); //メニュー画面の背景のユーザーの情報を初期化.
void check_user_background(objects& objects1); //メニュー画面の背景のユーザーが画面外にいるか判定.
void draw_user_back(objects& objects1); //メニュー画面の背景のユーザーの描画.