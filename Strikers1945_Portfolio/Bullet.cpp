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
	// 이미지 검색 

	bulletImg = IMAGEMANAGER->FindImage(fileName);

	// 초기화

	rcBullet = RectMakeCenter(_x, _y, _radius * 2, _radius * 2);
	fPosX = _x;
	fPosY = _y;
	fRadius = _radius;
	width = bulletImg->GetFrameWidth();
	height = bulletImg->GetFrameHeight();


	// 이미지 애니메이션  ( 계속 루프 ) 
	aniBullet = new Animation();
	aniBullet->Init(bulletImg);
	aniBullet->setFPS(1);
	aniBullet->setDefPlayFrame(false, true); 
	aniBullet->start();

	return true;
}

void Bullet::Update()
{
	// 충돌 처리를 할 총알 갱신 
	rcBullet = RectMakeCenter(fPosX + width / 2 , fPosY + height + 2, width, height); // 총알 크기가 안바뀌는건 이부분 30

}

void Bullet::Update(int)
{
	// 충돌 처리를 할 총알 갱신 
	rcBullet = RectMakeCenter(fPosX + width / 2, fPosY + height / 2, width, height); // 총알 크기가 안바뀌는건 이부분 30

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
