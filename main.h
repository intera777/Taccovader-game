#pragma once
#include"DxLIb.h"
#include<vector>



struct enemy;
struct user;
struct bullet;




const int WIDTH = 960;  //画面の幅
const int HEIGHT = 640; //画面の縦幅

const int BLUE = GetColor(0, 0, 255);
const int WHITE = GetColor(255, 255, 255);
const int RED = GetColor(255, 0, 0);
const int ORANGE = GetColor(255, 165, 0);
const int FLAMERATE = 33;
const int STAGE_NUM = 2;//ステージ数.


using std::vector;

enum { TITLE, PLAY, MENU, CLEAR, OVER, END };

const int FONT_TITLE = CreateFontToHandle("Arial Black", 40, 3, DX_FONTTYPE_ANTIALIASING_8X8);

