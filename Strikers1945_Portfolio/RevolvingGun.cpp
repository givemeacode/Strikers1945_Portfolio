#include "stdafx.h"
#include "RevolvingGun.h"
#include "Bullet.h"

RevolvingGun::RevolvingGun()
{
	revolvingGunImage = IMAGEMANAGER->FindImage(TEXT("LMBullet_Straight"));
	revolvingGunAni = new Animation;
	revolvingGunAni->Init(revolvingGunImage);
	revolvingGunAni->setDefPlayFrame(false, true); // (리버스, 루프)
	revolvingGunAni->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.

	fAngle = PI + PI / 2;

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
	std::list<Bullet*>::iterator it;
	if (!bulletList.empty())
	{
		for (it = bulletList.begin(); it != bulletList.end(); it++)
		{
			(*it)->Render(hdc);
			revolvingGunImage->AniRender(hdc, (*it)->GetPivotX() - 15, (*it)->GetPivotY() - 13, revolvingGunAni);// 총알이미지 크기가 30,25 이니까 15,13만큼 조정해서 중간으로 옴겨줌.
		}
	}
}

void RevolvingGun::Release()
{
	SAFE_DELETE(revolvingGunAni);

}

void RevolvingGun::BulletFire(float x, float y)
{
	for (int i = 0; i < 50; i++)
	{
		Bullet* bullet = new Bullet();
		bullet->Init(x, y, 10);
		bullet->SetIsBulletFire(true);
		bulletList.push_back(bullet);
	}

	std::list<Bullet*>::iterator it;
	int iCount = 0;
	for (it = bulletList.begin(); it != bulletList.end(); it++, iCount++)
	{
		(*it)->SetAngle(iCount);
	}
	revolvingGunAni->start();

}

void RevolvingGun::BulletMove()
{
	std::list<Bullet*>::iterator it;

	for (it = bulletList.begin(); it != bulletList.end(); it++)
	{
		if ((*it)->GetIsBulletFire())
		{
			(*it)->SetPivotX((*it)->GetPivotX() + cosf((*it)->GetAngle()) * fSpeed);
			(*it)->SetPivotY((*it)->GetPivotY() + -sinf((*it)->GetAngle()) * fSpeed);

			(*it)->Update();
		}
	}
	revolvingGunAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

}
