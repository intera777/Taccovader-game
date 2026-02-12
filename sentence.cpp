#include"invadergame2.h"

int FONT_TITLE;
int FONT_TITLE_SMALL;

void sentence_initialize() {
	FONT_TITLE = CreateFontToHandle("Calibri", 70, 10, DX_FONTTYPE_ANTIALIASING_8X8);
	FONT_TITLE_SMALL = CreateFontToHandle("Calibri", 20, 10, DX_FONTTYPE_ANTIALIASING_8X8);
}