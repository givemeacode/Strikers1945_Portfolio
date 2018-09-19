#pragma once
#include "Gun.h"

class PlayerGun :public Gun
{
	int playerDMG;
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

