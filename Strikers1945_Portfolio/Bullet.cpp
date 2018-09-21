#include "stdafx.h"
#include "Bullet.h"



Bullet::Bullet()
{
	isCollision = false;
	isBulletFire = false;
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
	// �浹 ó���� �� �Ѿ� ���� 
	rcBullet = RectMakeCenter(fPosX, fPosY, 15, 15); // �Ѿ� ũ�Ⱑ �ȹٲ�°� �̺κ� 30
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

bool Bullet::GetIsCollision()
{
	return isCollision;
}

void Bullet::SetIsCollision(bool _isCollision)
{
	isCollision = _isCollision;
}
