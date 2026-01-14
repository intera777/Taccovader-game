#pragma once
#include"invadergame2.h"

int SE_BULLET_SHOOT; //弾発射音.
int SE_ENEMY_BEAT; //敵撃破音.
int SE_USER_DAMAGED; //ユーザー被弾音.
int BGM_GAMEOVER; //ゲームオーバーBGM.

void sound_initialize() {
	SE_BULLET_SHOOT = LoadSoundMem("sound/bullet_shoot.mp3"); //弾発射音.
	SE_ENEMY_BEAT = LoadSoundMem("sound/enemy_beat.mp3"); //敵撃破音.
	SE_USER_DAMAGED = LoadSoundMem("sound/user_damaged.mp3"); //ユーザー被弾音.
	BGM_GAMEOVER = LoadSoundMem("sound/gameover.wav"); //ゲームオーバーBGM.

	ChangeVolumeSoundMem(100, SE_ENEMY_BEAT);
	ChangeVolumeSoundMem(50, SE_BULLET_SHOOT);
	ChangeVolumeSoundMem(100, SE_USER_DAMAGED);
	ChangeVolumeSoundMem(80, BGM_GAMEOVER);
}