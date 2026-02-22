#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

struct bullet;
struct user;
struct enemy;
struct block;
struct effect;

struct objects {
	user user1;
	vector<bullet> bul;
	vector<enemy> ene;
	vector<bullet> ene_bul;
	vector<block> blo;
	vector<effect> exp_eff;
	vector<enemy> ene_back; //メニュー画面の背景の敵の情報を持つ構造体の配列.
	int bullet_cooltime;
	int enemy_cycle;
	int enemy_bullet_cooltime;
	int score;
	int stage; //現在のステージ.
	int scene; //現在のゲームモード.
	int current_background; // 現在の背景画像のID.
	int timer_stage; // ステージの経過時間を管理するタイマー.
	int timer_background; // 背景の描画に関するタイマー.
};

void game_start_initialize(objects& objects1);
void scene_change(int s, objects& objects1);