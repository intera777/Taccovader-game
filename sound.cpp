#pragma once
#include"invadergame2.h"

int SE_BULLET_SHOOT; //’e”­Ë‰¹.
int SE_ENEMY_BEAT; //“GŒ‚”j‰¹.
int SE_USER_DAMAGED; //ƒ†[ƒU[”í’e‰¹.

void sound_initialize() {
	SE_BULLET_SHOOT = LoadSoundMem("sound/bullet_shoot.mp3"); //’e”­Ë‰¹.
	SE_ENEMY_BEAT = LoadSoundMem("sound/enemy_beat.mp3"); //“GŒ‚”j‰¹.
	SE_USER_DAMAGED = LoadSoundMem("sound/user_damaged.mp3"); //ƒ†[ƒU[”í’e‰¹.

	ChangeVolumeSoundMem(100, SE_ENEMY_BEAT);
	ChangeVolumeSoundMem(50, SE_BULLET_SHOOT);
	ChangeVolumeSoundMem(100, SE_USER_DAMAGED);
}