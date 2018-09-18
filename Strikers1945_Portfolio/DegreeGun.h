#pragma once

#include "Gun.h"

class DegreeGun
	: public Gun
{
private:
	float cycleTypeAngle;
	float fStartX;
	float fStartY;
	float fAngle2 = 0.0f;
public:
	DegreeGun();
	~DegreeGun();
public:
	bool Init(float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
};

