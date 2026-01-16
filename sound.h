#pragma once
#include"DxLIb.h"
#include<vector>

extern int SE_BULLET_SHOOT; //弾発射音.
extern int SE_ENEMY_BEAT; //敵撃破音.
extern int SE_USER_DAMAGED; //ユーザー被弾音.
extern int BGM_GAMEOVER; //ゲームオーバーBGM.
extern int BGM_STAGE1; //ステージ1BGM.
extern int BGM_GAMECLEAR; //ゲームクリアBGM.
extern int BGM_TITLE; //タイトルBGM.

void sound_initialize();
void stop_allbgm();