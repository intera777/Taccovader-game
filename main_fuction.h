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
	int bullet_cooltime;
	int enemy_cycle;
	int enemy_bullet_cooltime;
	int score;
	int stage;
	int scene;
	int current_background;
};

void game_start_initialize(objects& objects1);
void scene_change(int s, objects& objects1);