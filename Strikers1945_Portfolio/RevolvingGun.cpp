#include "stdafx.h"
#include "RevolvingGun.h"



RevolvingGun::RevolvingGun()
{
}


RevolvingGun::~RevolvingGun()
{
}

bool RevolvingGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	return true;
}

void RevolvingGun::Render(HDC hdc)
{
}

void RevolvingGun::Release()
{
}

void RevolvingGun::BulletFire(float x, float y)
{
}

void RevolvingGun::BulletMove()
{
}
