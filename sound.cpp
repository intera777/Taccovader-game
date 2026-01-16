#pragma once
#include"invadergame2.h"

int SE_BULLET_SHOOT; //弾発射音.
int SE_ENEMY_BEAT; //敵撃破音.
int SE_USER_DAMAGED; //ユーザー被弾音.
int BGM_GAMEOVER; //ゲームオーバーBGM.
int BGM_STAGE1; //通常ステージBGM.
int BGM_GAMECLEAR; //ゲームクリアBGM.

void sound_initialize() {
	SE_BULLET_SHOOT = LoadSoundMem("sound/bullet_shoot.mp3"); //弾発射音.
	SE_ENEMY_BEAT = LoadSoundMem("sound/enemy_beat.mp3"); //敵撃破音.
	SE_USER_DAMAGED = LoadSoundMem("sound/user_damaged.mp3"); //ユーザー被弾音.
	BGM_GAMEOVER = LoadSoundMem("sound/gameover.wav"); //ゲームオーバーBGM.
	BGM_STAGE1 = LoadSoundMem("sound/normal.mp3"); //ステージ1BGM.
	BGM_GAMECLEAR = LoadSoundMem("sound/gameclear.mp3"); //ゲームクリアBGM.

	ChangeVolumeSoundMem(100, SE_ENEMY_BEAT);
	ChangeVolumeSoundMem(50, SE_BULLET_SHOOT);
	ChangeVolumeSoundMem(100, SE_USER_DAMAGED);
	ChangeVolumeSoundMem(80, BGM_GAMEOVER);
	ChangeVolumeSoundMem(70, BGM_STAGE1);
	ChangeVolumeSoundMem(70, BGM_GAMECLEAR);
}

void stop_allbgm() {
	StopSoundMem(BGM_GAMECLEAR);
	StopSoundMem(BGM_STAGE1);
	StopSoundMem(BGM_GAMEOVER);
}