#include "stdafx.h"
#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

bool Bullet::Init(float _x, float _y, float _radius)
{
	rcBullet = RectMakeCenter(_x, _y, _radius * 2, _radius * 2);
	fPosX = _x;
	fPosY = _y;
	fRadius = _radius;
	return true;
}

void Bullet::Update()
{
	// 충돌 처리를 할 총알 갱신 
	rcBullet = RectMakeCenter(fPosX, fPosY, 30, 30);
}

void Bullet::Render(HDC hdc)
{
	DrawObject(hdc, rcBullet, 1, RGB(255, 0, 255), ELLIPSE);
}

void Bullet::SetIsBulletFire(bool _isBulletFire)
{
	isBulletFire = _isBulletFire;
}
bool Bullet::GetIsBulletFire()
{
	return isBulletFire;
}

void Bullet::SetPivot(float x, float y)
{
}

float Bullet::GetPivotX()
{
	return fPosX;
}

float Bullet::GetPivotY()
{
	return fPosY;
}

void Bullet::SetPivotX(float x)
{
	fPosX = x;
}

void Bullet::SetPivotY(float y)
{
	fPosY = y;
}

void Bullet::SetCenterPivot(RECT rc)
{
}

float Bullet::GetRadius()
{
	return fRadius;
}
