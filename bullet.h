#pragma once
#include"DxLIb.h"
#include<vector>

struct user;
struct enemy;
struct objects;

struct bullet {
	int x;
	int y;
	int state;
	//0‚Í‘Ò‹@ó‘Ô,1‚ÍƒtƒB[ƒ‹ƒh“à‚É‘¶İ.
	int type; // 1‚Í’Êí‚Ìe’e,2‚ÍŠÑ’Ê’e.
};

const int MAXBULLETNUM = 10; //“¯‚É‘¶İ‚Å‚«‚é’e‚Ì”‚ÌÅ‘å’l.
const int BULLET_RAD = 10; //	’e‚Ì”¼Œa.
const int BULLET_COOLTIME = 15; //’e‚ª”­Ë‚³‚ê‚Ä‚©‚çŸ‚Ì’e‚ª”­Ë‰Â”\‚É‚È‚é‚Ü‚Å‚ÌŠÔ(ƒtƒŒ[ƒ€”).

void bullet_appear(objects& objects1);
//’e‚ª”­Ë‚Å‚«‚é‚©‚Ç‚¤‚©‚ğ”»’f‚µ,”­Ë‚Å‚«‚é‚È‚ç(x,y)‚ÌˆÊ’u‚É’e‚ğ”­Ë‚·‚é.

void bullet_move(objects& objects1, int r, int move_vector);
void draw_bullet(objects objects1, int r, int color);
void bullet_initialize(objects& objects1); //e’e‚Ìî•ñ‚ğ‰Šú‰».
