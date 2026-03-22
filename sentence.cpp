#include"invadergame2.h"

int FONT_TITLE;
int FONT_TITLE_SMALL;
int FONT_TITLE_FRAME;

void sentence_initialize() {
	AddFontResourceEx("font/Michroma-Regular.ttf", FR_PRIVATE, 0);

	FONT_TITLE = CreateFontToHandle("Michroma", 50, 10, DX_FONTTYPE_ANTIALIASING_8X8);
	FONT_TITLE_SMALL = CreateFontToHandle("HGPºÞ¼¯¸E", 20, 10, DX_FONTTYPE_ANTIALIASING_8X8);
	FONT_TITLE_FRAME= CreateFontToHandle("Michroma", 50, 10, DX_FONTTYPE_EDGE);
}