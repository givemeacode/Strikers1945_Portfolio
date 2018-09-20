#include "stdafx.h"
#include "NormalGun.h"
#include "Bullet.h"


NormalGun::NormalGun()
{
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
		}
	}
}

void NormalGun::Release()
{
}

void NormalGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 2);
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);
	bullet->SetAngle(fAngle);
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
}
