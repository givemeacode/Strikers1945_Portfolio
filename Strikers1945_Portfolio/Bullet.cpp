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

bool Bullet::Init(const TCHAR* fileName, float _x, float _y, float _radius)
{
	// �̹��� �˻� 

	bulletImg = IMAGEMANAGER->FindImage(fileName);

	// �ʱ�ȭ

	rcBullet = RectMakeCenter(_x, _y, _radius * 2, _radius * 2);
	fPosX = _x;
	fPosY = _y;
	fRadius = _radius;
	width = bulletImg->GetFrameWidth();
	height = bulletImg->GetFrameHeight();


	// �̹��� �ִϸ��̼�  ( ��� ���� ) 
	aniBullet = new Animation();
	aniBullet->Init(bulletImg);
	aniBullet->setFPS(1);
	aniBullet->setDefPlayFrame(false, true); 
	aniBullet->start();

	return true;
}

void Bullet::Update()
{
	// �浹 ó���� �� �Ѿ� ���� 
	rcBullet = RectMakeCenter(fPosX + width / 2 , fPosY + height + 2, width, height); // �Ѿ� ũ�Ⱑ �ȹٲ�°� �̺κ� 30

}

void Bullet::Update(int)
{
	// �浹 ó���� �� �Ѿ� ���� 
	rcBullet = RectMakeCenter(fPosX + width / 2, fPosY + height / 2, width, height); // �Ѿ� ũ�Ⱑ �ȹٲ�°� �̺κ� 30

	aniBullet->frameUpdate(TIMEMANAGER->getElapsedTime() * 10.f);
}

void Bullet::Render(HDC hdc)
{
	DrawObject(hdc, rcBullet, 1, RGB(255, 0, 255), ELLIPSE);
	
}

void Bullet::Render(HDC hdc , int )
{
	bulletImg->AniRender(hdc, fPosX, fPosY, aniBullet);

}

void Bullet::Release()
{
	SAFE_DELETE(aniBullet);

	bulletImg->Release();
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
