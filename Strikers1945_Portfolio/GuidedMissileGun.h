#pragma once

#include "Gun.h"

class GuidedMissileGun
	: public Gun
{
	float fAngle;
	float fSpeed;

public:
	GuidedMissileGun();
	~GuidedMissileGun();
public:
	bool Init( float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
};

