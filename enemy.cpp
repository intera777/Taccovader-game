#pragma once
#include"invadergame2.h"

void check_enemy(objects& objects1) {
	vector<enemy>& ene = objects1.ene;
	vector<bullet>& bul = objects1.bul;
	vector<effect>& eff = objects1.exp_eff;
	int& s = objects1.score;
	for (int i = 0; i < ENEMYNUM; i++) {
		int x1 = ene.at(i).x, y1 = ene.at(i).y;
		for (int j = 0; j < MAXBULLETNUM; j++) {
			int x2 = bul.at(j).x, y2 = bul.at(j).y;
			if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (ENEMY_RAD + BULLET_RAD) * (ENEMY_RAD + BULLET_RAD)) && ene.at(i).state == 1 && bul.at(j).state == 1) {
				PlaySoundMem(SE_ENEMY_BEAT, DX_PLAYTYPE_BACK, TRUE);
				ene.at(i).state = 0;

				bul.at(j).x = -100;
				bul.at(j).y = -100;
				bul.at(j).state = 0;
				s += 50;
				eff.at(i).time = 15;
				eff.at(i).x = x1 - ENEMY_RAD;
				eff.at(i).y = y1 - ENEMY_RAD;
				break;
			}
		}
	}
}

void draw_enemy(objects& objects1) {
	vector<enemy>& ene = objects1.ene;
	int img_enemy = LoadGraph("image/invader1.png");
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 1) {
			DrawGraph(ene.at(i).x - 10, ene.at(i).y - 10, img_enemy, TRUE);
			//DrawCircle(ene.at(i).x, ene.at(i).y, ENEMY_RAD, RED, TRUE);
		}
	}
}

void move_enemy(objects& objects1) {
	vector<enemy>& ene = objects1.ene;
	int stage = objects1.stage;
	int speed = ENEMY_MOVE_SPEED;

	switch (stage) {
	case 1: {
		int& t = objects1.enemy_cycle;
		if (((0 <= t && t < speed) || (speed * 5 <= t && t < speed * 6)) && t % ENEMY_MOVE_COOLTIME == 0) {

			for (int i = 0; i < ENEMYNUM; i++) {
				ene.at(i).x -= ENEMY_MOVE_COOLTIME * 1.1;
			}
			if (t == speed * 6 - 1) {
				t = 0;
			}
			else {
				t++;
			}
		}
		else if (((speed <= t && t < speed * 2) || (speed * 4 <= t && t < speed * 5)) && t % ENEMY_MOVE_COOLTIME == 0) {
			if (t % 2 == 0) {
				for (int i = 0; i < ENEMYNUM; i++) {
					ene.at(i).y += max(ENEMY_MOVE_COOLTIME / 2, 1);
				}
			}
			t++;
		}
		else if (speed * 2 <= t && t < speed * 4) {
			for (int i = 0; i < ENEMYNUM; i++) {
				ene.at(i).x += ENEMY_MOVE_COOLTIME * 1.1;
			}
			t++;
		}
		break;
	}
	case 2: {
		for (int i = 0; i < ENEMYNUM; i++) {
			if (ene.at(i).state == 1) {
				ene.at(i).y += 0.5;
				if (i < ENEMYNUM / 2) {
					ene.at(i).x -= double(ene.at(i).y) / 600 + ENEMY_MOVE_COOLTIME;
				}
				else {
					ene.at(i).x -= double(ene.at(i).y) / 600 + ENEMY_MOVE_COOLTIME * 2;
				}
				if (ene.at(i).x < 0) {
					ene.at(i).x = WIDTH;
				}
			}
		}
		break;
	}

	case 3: {
		int& timer = objects1.timer_stage;
		if (timer % ENENY_APPEAR_COOLTIME == 0) {
			ene.at(2 * timer / ENENY_APPEAR_COOLTIME).state = 1;
			ene.at(2 * timer / ENENY_APPEAR_COOLTIME).x = 80;
			ene.at(2 * timer / ENENY_APPEAR_COOLTIME).y = 20;

			ene.at(2 * timer / ENENY_APPEAR_COOLTIME + 1).state = 1;
			ene.at(2 * timer / ENENY_APPEAR_COOLTIME + 1).x = WIDTH - 250;
			ene.at(2 * timer / ENENY_APPEAR_COOLTIME + 1).y = 20;
		}
		for (int i = 0; i < ENEMYNUM; i++) {
			int& c = ene.at(i).enemy_cycle;
			if (ene.at(i).state == 1) {
				switch (ene.at(i).move_type) {
				case 1: {
					if (0 <= c && c < 10) {
						ene.at(i).x += 4 * ENEMY_MOVE_COOLTIME;

					}
					else if (10 <= c && c < 30) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}
					else if (30 <= c && c < 40) {
						ene.at(i).x -= 4 * ENEMY_MOVE_COOLTIME;
					}
					else if (40 <= c && c < 50) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}

					c++;
					if (c == 50) {
						c = 0;
					}
					break;
				}
				case 2: {
					if (0 <= c && c < 30) {
						ene.at(i).x += 3 * ENEMY_MOVE_COOLTIME;

					}
					else if (30 <= c && c < 50) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}
					else if (50 <= c && c < 80) {
						ene.at(i).x -= 3 * ENEMY_MOVE_COOLTIME;
					}
					else if (80 <= c && c < 100) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}

					c++;
					if (c == 100) {
						c = 0;
					}
					break;
				}
				case 3: {
					if (0 <= c && c < 40) {
						ene.at(i).x += 4 * ENEMY_MOVE_COOLTIME;

					}
					else if (40 <= c && c < 60) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}
					else if (60 <= c && c < 100) {
						ene.at(i).x -= 4 * ENEMY_MOVE_COOLTIME;
					}
					else if (100 <= c && c < 120) {
						ene.at(i).y += 2 * ENEMY_MOVE_COOLTIME;
					}

					c++;
					if (c == 120) {
						c = 0;
					}
					break;
				}
				default:
					break;
				}
			}
		}
		if (timer < ENENY_APPEAR_COOLTIME * ENEMYNUM / 2 - 1) {
			timer++;
		}
		break;
	}
	default:
		break;

	}
}

void enemy_initialize(objects& objects1) {
	int stage = objects1.stage;
	vector<enemy>& ene = objects1.ene;
	switch (stage) {
	case 1: {
		for (int i = 0; i < ENEMYNUM; i++) {
			ene.at(i).x = 60 * (i % (ENEMYNUM / 2) + 1) + 80;
			ene.at(i).y = 20 + 40 * (i / (ENEMYNUM / 2));
			ene.at(i).state = 1;
		}
		break;
	}
	case 2: {
		for (int i = 0; i < ENEMYNUM; i++) {
			ene.at(i).x = 60 * (i % (ENEMYNUM / 2) + 1) + 80;
			ene.at(i).y = 20 + 30 * (i / (ENEMYNUM / 2));
			ene.at(i).state = 1;
		}
		break;
	}
	case 3: {
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<> dis(1, 3);
		for (int i = 0; i < ENEMYNUM; i++) {
			ene.at(i).move_type = dis(gen);
			ene.at(i).enemy_cycle = 0;
			ene.at(i).state = -1;//-1ÇÕìGÇ™ñ¢ê∂ê¨Ç≈Ç†ÇÈÇ±Ç∆Çï\Ç∑.
		}
	}

	default:
		break;
	}
}

void check_enemy_completed(objects& objects1) {
	vector<enemy>& ene = objects1.ene;

	int flag = 1;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state != 0) {
			flag = 0;
		}
	}
	if (flag == 1) {
		scene_change(CLEAR, objects1);
	}
}

void enemy_bullet_initialize(objects& objects1) {
	vector<bullet>& bul = objects1.ene_bul;
	for (int i = 0; i < ENEMYNUM; i++) {
		bul.at(i).x = -100;
		bul.at(i).y = -100;
		bul.at(i).state = 0;
	}
}

void enemy_bullet_appear(objects& objects1) {
	vector<bullet>& bul = objects1.ene_bul;
	vector<enemy>& ene = objects1.ene;
	int& cooltime = objects1.enemy_bullet_cooltime;
	if (cooltime < ENEMYBULLETCOOLTIME) {
		cooltime++;
	}
	else {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(0, ENEMYNUM / 2 - 1);
		int bx = distrib(gen);
		for (int i = 0; i < 2; i++) {
			int index = bx + (1 - i) * (ENEMYNUM / 2);
			if (ene.at(index).state == 1 && bul.at(index).state == 0) {
				bul.at(index).x = ene.at(index).x;
				bul.at(index).y = ene.at(index).y + 40;
				bul.at(index).state = 1;
				break;
			}
			if (ene.at(index).state == 1 && bul.at(index).state == 1) {
				break;
			}
		}
		cooltime = 0;
	}

}

void enemy_bullet_move(objects& objects1, int r, int move_vector) {
	vector<bullet>& bul = objects1.ene_bul;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (bul.at(i).state == 1) {
			bul.at(i).y += move_vector;
			if (bul.at(i).y > HEIGHT) {
				bul.at(i).x = -100; bul.at(i).y = -100; bul.at(i).state = 0;
			}
		}
	}
}



void enemy_draw_bullet(objects& objects1, int r, int color) {
	vector<bullet>& bul = objects1.ene_bul;
	int img_bullet = LoadGraph("image/enemy_bullet.png");
	for (int i = 0; i < ENEMYNUM; i++) {
		if (bul.at(i).state == 1) {
			DrawGraph(bul.at(i).x - BULLET_RAD, bul.at(i).y - BULLET_RAD, img_bullet, FALSE);
		}
	}
}

int check_user_enemybullet(objects& objects1) {
	vector<bullet>& ene_bul = objects1.ene_bul;
	user& user1 = objects1.user1;
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene_bul.at(i).state == 0) { continue; }
		int ex = ene_bul.at(i).x, ey = ene_bul.at(i).y;

		//ìGÇ™â°Ç…Ç¢ÇÈÇ∆Ç´.
		if (ey >= HEIGHT - 40 && ux - ex <= BULLET_RAD && ux - ex >= -(40 + BULLET_RAD)) {
			ene_bul.at(i).state = 0; return 1;
		} //ìGÇ™è„Ç…Ç¢ÇÈÇ∆Ç´;
		else if (ux - ex <= BULLET_RAD && ux - ex >= -(40 + BULLET_RAD) && uy - ey <= BULLET_RAD) {
			ene_bul.at(i).state = 0; return 1;
		}
		else
		{
			if ((ux - ex) * (ux - ex) + (uy - ey) * (uy - ey) <= BULLET_RAD * BULLET_RAD ||
				((ux + 40) - ex) * ((ux + 40) - ex) + (uy - ey) * (uy - ey) <= BULLET_RAD * BULLET_RAD) {
				ene_bul.at(i).state = 0; return 1;
			}
		}
	}
	return 0;
}

int check_user_enemy(objects& objects1) {
	vector<enemy>& ene = objects1.ene;
	user& user1 = objects1.user1;
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 0) { continue; }
		int ex = ene.at(i).x, ey = ene.at(i).y;

		//ìGÇ™â°Ç…Ç¢ÇÈÇ∆Ç´.
		if (ey >= HEIGHT - 40 && ux - ex <= ENEMY_RAD && ux - ex >= -(40 + ENEMY_RAD)) {
			return 1;
		} //ìGÇ™è„Ç…Ç¢ÇÈÇ∆Ç´;
		else if (ux - ex <= ENEMY_RAD && ux - ex >= -(40 + ENEMY_RAD) && uy - ey <= ENEMY_RAD) {
			return 1;
		}
		else
		{
			if ((ux - ex) * (ux - ex) + (uy - ey) * (uy - ey) <= ENEMY_RAD * ENEMY_RAD ||
				((ux + 40) - ex) * ((ux + 40) - ex) + (uy - ey) * (uy - ey) <= ENEMY_RAD * ENEMY_RAD) {
				return 1;
			}
		}
	}
	return 0;
}
