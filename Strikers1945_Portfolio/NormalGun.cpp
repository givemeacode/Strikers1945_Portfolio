#include "stdafx.h"
#include "NormalGun.h"
#include "Bullet.h"

NormalGun::NormalGun()
{
	normalGunImage = IMAGEMANAGER->FindImage(TEXT("MBasic_Bullet"));
	normalGunAni = new Animation;
	normalGunAni->Init(normalGunImage);
	normalGunAni->setDefPlayFrame(true, true); // (리버스, 루프)
	normalGunAni->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.

	fAngle = PI + PI / 2;
}


NormalGun::~NormalGun()
{
}

bool NormalGun::Init(float x, float y)
{
	return true;
}

void NormalGun::Render(HDC hdc)
{
	std::list<Bullet*>::iterator it;
	if (!bulletList.empty())
	{
		for (it = bulletList.begin(); it != bulletList.end(); it++)
		{
			(*it)->Render(hdc);
			normalGunImage->AniRender(hdc, (*it)->GetPivotX() - 4, (*it)->GetPivotY() - 5, normalGunAni); // 총알이미지 크기가 8,10 이니까 4,5만큼 조정해서 중간으로 옴겨줌.
		}
	}
}

void NormalGun::Release()
{
	SAFE_DELETE(normalGunAni);
}

void NormalGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 2);
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);
	bullet->SetAngle(fAngle);

	normalGunAni->start();
}

void NormalGun::BulletMove()
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
	normalGunAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}
