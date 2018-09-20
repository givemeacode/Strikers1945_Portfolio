#include "stdafx.h"
#include "RevolvingGun.h"
#include "Bullet.h"

RevolvingGun::RevolvingGun()
{
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
		}
	}
}

void RevolvingGun::Release()
{
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
}
