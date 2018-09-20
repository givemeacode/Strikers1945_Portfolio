#include "stdafx.h"
#include "GuidedMissileGun.h"
#include "Bullet.h"
#include "Player.h"


GuidedMissileGun::GuidedMissileGun()
{
	fAngle = PI + PI /2 ;

	fSpeed = 4.f;
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
	std::list<Bullet*>::iterator iter;
	if (!bulletList.empty())
	{
		for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
		{

			if ((*iter)->GetIsBulletFire())
			{
				(*iter)->Render(hdc);
			}
		}
	}
}

void GuidedMissileGun::Release()
{
}

void GuidedMissileGun::BulletFire(float x, float y)
{
	// 총알이 생성 
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 10);				// 반지름 사용 
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);

	float _angle = UTIL::GetAngle(bullet->GetPivotX(), bullet->GetPivotY(), GAMESYS->GetPlayer()->GetX(), GAMESYS->GetPlayer()->GetY());
	bullet->SetAngle(_angle);
}

void GuidedMissileGun::BulletMove()
{
	std::list<Bullet*>::iterator it;
	for (it = bulletList.begin(); it != bulletList.end(); it++)
	{
		if ((*it)->GetIsBulletFire())
		{
			(*it)->SetPivotX((*it)->GetPivotX() + cosf((*it)->GetAngle()) * 10.f);
			(*it)->SetPivotY((*it)->GetPivotY() + (-sinf((*it)->GetAngle()) * 10.f));

			(*it)->Update();

		}
	}
}	



