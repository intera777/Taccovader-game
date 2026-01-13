#pragma once
#include"invadergame2.h"

int SE_BULLET_SHOOT; //’e”­ŽË‰¹.

void sound_initialize() {
	SE_BULLET_SHOOT = LoadSoundMem("sound/bullet_shoot.mp3"); //’e”­ŽË‰¹.
	ChangeVolumeSoundMem(50, SE_BULLET_SHOOT);
}