#include"invadergame2.h"

int FONT_TITLE;
int FONT_TITLE_SMALL;
int FONT_TITLE_FRAME;

void sentence_initialize() {
	AddFontResourceEx("font/Michroma-Regular.ttf", FR_PRIVATE, 0);

	FONT_TITLE = CreateFontToHandle("Michroma", 50, 10, DX_FONTTYPE_ANTIALIASING_8X8);
	FONT_TITLE_SMALL = CreateFontToHandle("HGPｺﾞｼｯｸE", 20, 10, DX_FONTTYPE_ANTIALIASING_8X8);
	FONT_TITLE_FRAME= CreateFontToHandle("Michroma", 50, 10, DX_FONTTYPE_EDGE);
}

void display_credit() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(180, 90, 700, 200, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawStringToHandle(200, 100, "音楽: 魔王魂, OtoLogic, ふりーむ! 素材ライブラリー", WHITE, FONT_TITLE_SMALL);
	DrawStringToHandle(200, 150, "効果音：Springin’ Sound Stock", WHITE, FONT_TITLE_SMALL);
}