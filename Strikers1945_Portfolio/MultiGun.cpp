#include "stdafx.h"
#include "MultiGun.h"



MultiGun::MultiGun()
{
}


MultiGun::~MultiGun()
{
}

bool MultiGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	return true;
}

void MultiGun::Render(HDC hdc)
{
}

void MultiGun::Release()
{
}

void MultiGun::BulletFire(float x, float y)
{
}

void MultiGun::BulletMove()
{
}
