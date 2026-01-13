#pragma once
#include"invadergame2.h"

int SE_BULLET_SHOOT; //’e”­ŽË‰¹.
int SE_ENEMY_BEAT; //“GŒ‚”j‰¹.

void sound_initialize() {
	SE_BULLET_SHOOT = LoadSoundMem("sound/bullet_shoot.mp3"); //’e”­ŽË‰¹.
	SE_ENEMY_BEAT = LoadSoundMem("sound/enemy_beat.mp3"); //“GŒ‚”j‰¹.

	ChangeVolumeSoundMem(100, SE_ENEMY_BEAT);
	ChangeVolumeSoundMem(50, SE_BULLET_SHOOT);
}