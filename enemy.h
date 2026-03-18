#pragma once
#include"DxLIb.h"
#include<vector>
#include<random>
using namespace std;

struct bullet;
struct user;
struct effect;
struct objects;

struct enemy {
	double x;
	double y;
	int state;
	int hp; //0‚É‚È‚é‚Æstate=0.
	int enemy_type; //“G‚Ìí—Ş.
	int move_type; //ƒXƒe[ƒW3‚É‚¨‚¯‚é“G‚Ì“®‚«‚Ìƒpƒ^[ƒ“‚ğŠÇ—‚·‚é•Ï”.
	int enemy_cycle;
};

extern int img_enemy1;
extern int img_enemy2;
extern int enemy_bullet1;
extern int enemy_bullet2;

const int ENEMYNUM = 24;//“G‚Ì”.
const int ENEMY_RAD = 10; //“G‚Ì”¼Œa.
const int ENEMY_MOVE_SPEED = 40; //“G‚ª1‰ñ‚ÌˆÚ“®‚Å“®‚­‹——£(‰¡).
const int ENEMY_MOVE_COOLTIME = 1;//“G‚ª“®‚¢‚Ä‚©‚çÄ‚Ñ“®‚­‚Ü‚Å‚ÌƒN[ƒ‹ƒ^ƒCƒ€(ƒtƒŒ[ƒ€”).
const int ENEMYCYCLE = 150; //“G‚Ì“®‚«‚ÌüŠú;
const int ENEMYBULLETCOOLTIME = 5; //“G‚ÌUŒ‚‚ÌüŠú.
const int ENENY_APPEAR_COOLTIME = 120; //“G‚ªoŒ»‚µ‚Ä‚©‚çŸ‚Ì“G‚ªoŒ»‚·‚é‚Ü‚Å‚ÌƒN[ƒ‹ƒ^ƒCƒ€(ƒXƒe[ƒW3).
const int ENEMYNUM_BACK = 9;//ƒƒjƒ…[‰æ–Ê‚Ì”wŒi‚Ì“G‚Ì”.



void load_img_enemy(); //“G‚Ì‰æ‘œ‚ğƒ[ƒh.
void check_enemy(objects& objects1); //“G‚Ì¶€‚ğŠm”F.
void draw_enemy(objects& objects1); //“G‚ğ•`‰æ.
void draw_enemy_back(objects& objects1); //ƒƒjƒ…[‰æ–Ê‚Ì”wŒi‚Ì“G‚ğ•`‰æ.
void enemy_background_initialize(objects& objects1); //ƒƒjƒ…[‰æ–Ê‚Ì”wŒi‚Ì“G‚Ì‰Šú‰».
void check_enemy_background(objects& objects1); //ƒƒjƒ…[‰æ–Ê‚Ì”wŒi‚Ì“G‚ª‰æ–ÊŠO‚Éo‚Ä‚¢‚È‚¢‚©‚ğŠm”F.
void move_enemy(objects& objects1); //“G‚ğ“®‚©‚·.
void enemy_initialize(objects& objects1);
void check_enemy_completed(objects& objects1); //“G‚ª‘S•”“|‚³‚ê‚½‚©ƒ`ƒFƒbƒN.
void enemy_bullet_initialize(objects& objects1); //“G‚Ìe’e‚Ì‰Šú‰»
void enemy_bullet_appear(objects& objects1); //“G‚Ìe’e‚ğ¶¬
void enemy_bullet_move(objects& objects1, int r, int move_vector); //“G‚Ìe’e‚ğ“®‚©‚·.
void enemy_draw_bullet(objects& objects1, int r, int color); //“G‚Ìe’e‚ğ•`‰æ.
int check_user_enemybullet(objects& objects1); //ƒ†[ƒU[‚Æ“G‚Ìe’e‚ªG‚ê‚Ä‚¢‚é‚©‚ğ”»’è.
int check_user_enemy(objects& objects1); //ƒ†[ƒU[‚Æ“G‚ª’¼ÚG‚ê‚Ä‚¢‚é‚©‚ğ”»’è.