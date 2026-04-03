#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

struct block {
	int x; //左上の座標
	int y;
	int hp;
	int state; //0なら非存在,1なら存在.
};

const int BLOCKNUM = 24; //ブロックの初期個数.
const int BLOCKSIZE = 20; //ブロックの一辺の長さ.

void load_block();
void draw_block(objects objects1);
void check_block_bullet(objects& objects1);
void block_initialize(objects& objects1);
void check_block_enemybullet(objects& objects1);  //ブロックと敵の銃弾が触れていれば銃弾を削除.

extern int img_block;