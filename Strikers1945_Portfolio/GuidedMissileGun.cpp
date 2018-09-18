#include "stdafx.h"
#include "GuidedMissileGun.h"



GuidedMissileGun::GuidedMissileGun()
{
}


GuidedMissileGun::~GuidedMissileGun()
{
}

bool GuidedMissileGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	return true;
}

void GuidedMissileGun::Render(HDC hdc)
{
}

void GuidedMissileGun::Release()
{
}

void GuidedMissileGun::BulletFire(float x, float y)
{
}

void GuidedMissileGun::BulletMove()
{
}
