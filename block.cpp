#pragma once
#include"invadergame2.h"

void draw_block(objects objects1) {
	vector<block> blo = objects1.blo;
	int img_block = LoadGraph("image/block.png");
	for (int i = 0; i < BLOCKNUM; i++) {
		int x = blo.at(i).x, y = blo.at(i).y, state = blo.at(i).state;
		if (state == 1) {
			DrawGraph(x, y, img_block, FALSE);
		}
	}
}

void check_block_bullet(objects& objects1) {
	vector<bullet>& bul = objects1.bul;
	vector<block>& blo = objects1.blo;
	for (int i = 0; i < BLOCKNUM; i++) {
		int block_x = blo.at(i).x;
		int block_y = blo.at(i).y;
		int block_right = block_x + BLOCKSIZE;
		int block_bottom = block_y + BLOCKSIZE;
		for (int j = 0; j < MAXBULLETNUM; j++) {
			if (bul.at(j).state != 1) continue; //弾が存在しないときはスキップ.
			int bullet_x = bul.at(j).x;
			int bullet_y = bul.at(j).y;

			int closestX = (bullet_x < block_x) ? block_x : (bullet_x > block_right ? block_right : bullet_x);
			int closestY = (bullet_y < block_y) ? block_y : (bullet_y > block_bottom ? block_bottom : bullet_y);

			int dx = bullet_x - closestX;
			int dy = bullet_y - closestY;

			if (dx * dx + dy * dy <= (BULLET_RAD * BULLET_RAD)) {
				bul.at(j).state = 0;
			}
		}
	}
}

void check_block_enemybullet(objects& objects1) {
	vector<bullet>& ene_bul = objects1.ene_bul;
	vector<block>& blo = objects1.blo;
	for (int i = 0; i < BLOCKNUM; i++) {
		int block_x = blo.at(i).x;
		int block_y = blo.at(i).y;
		int block_right = block_x + BLOCKSIZE;
		int block_bottom = block_y + BLOCKSIZE;
		for (int j = 0; j < ENEMYNUM; j++) {
			if (ene_bul.at(j).state != 1) continue; //弾が存在しないときはスキップ.
			int bullet_x = ene_bul.at(j).x;
			int bullet_y = ene_bul.at(j).y;

			int closestX = (bullet_x < block_x) ? block_x : (bullet_x > block_right ? block_right : bullet_x);
			int closestY = (bullet_y < block_y) ? block_y : (bullet_y > block_bottom ? block_bottom : bullet_y);

			int dx = bullet_x - closestX;
			int dy = bullet_y - closestY;

			if (dx * dx + dy * dy <= (BULLET_RAD * BULLET_RAD)) {
				ene_bul.at(j).state = 0;
			}
		}
	}
}

void block_initialize(objects& objects1) {
	vector<block>& blo = objects1.blo;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				blo.at(8 * i + 4 * j + k).x = 320 * (i + 1) + k * BLOCKSIZE - 200;
				blo.at(8 * i + 4 * j + k).y = HEIGHT - 140 + BLOCKSIZE * j;
				blo.at(8 * i + 4 * j + k).hp = 1;
				blo.at(8 * i + 4 * j + k).state = 1;
			}
		}
	}
}



