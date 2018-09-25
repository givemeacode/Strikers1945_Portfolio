#pragma once
#include "Gun.h"


class PlayerGun :public Gun
{
	int playerDMG;

	Image*		playerGunImage1;
	Animation*	playerGunAni1;

	Image*		playerGunImage2;
	Animation*	playerGunAni2;

	Image*		playerGunImage3;
	Animation*	playerGunAni3;

	Image*		playerGunImage4;
	Animation*	playerGunAni4;

	
public:
	PlayerGun();
	~PlayerGun();
public:
	bool Init(float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
};

