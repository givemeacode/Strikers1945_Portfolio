#pragma once
#include "Gun.h"

class NormalGun
	: public Gun
{
public:
	NormalGun();
	~NormalGun();
public:
	bool Init(float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
};

