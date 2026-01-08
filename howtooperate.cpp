#pragma once
#include"invadergame2.h"

void draw_howtooperate(void) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200); //透明度設定.
	DrawBox(0, 0, WIDTH, HEIGHT, GetColor(0, 0, 0), 1); //背景を黒で塗りつぶし.
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //ブレンドモード解除.
	SetFontSize(30);
	DrawString(100, 100, "操作方法", WHITE);
	SetFontSize(20);
	DrawString(100, 200, "右移動: Lキー", WHITE);
	DrawString(100, 250, "左移動: Jキー", WHITE);
	DrawString(100, 300, "弾発射: Zキー", WHITE);
}