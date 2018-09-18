#pragma once

#include "Gun.h"
class RevolvingGun
	: public Gun
{
public:
	RevolvingGun();
	~RevolvingGun();
public:
	bool Init(float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
};

