#include "stdafx.h"
#include "Gun.h"
#include "Bullet.h"


Gun::Gun()
{
}


Gun::~Gun()
{
}

bool Gun::Init(eGunType type,float x, float y)
{
	switch (type)
	{
	case eGunType::GUN_NONE:
		fPosX = x;
 		fPosY = y + 3;
		break;
	}
	return true;
}



void Gun::Render(HDC hdc)
{
	std::list<Bullet*>::iterator iter;
	for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
	{
		(*iter)->Render(hdc);
	}

}

void Gun::Release()
{
}

void Gun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y);
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);
	//if (!_bullet->isFire)
	//{
	//	_bullet->isFire = true;
	//	_bullet->angle = _angle;
	//	_bullet->x = _end.x;
	//	_bullet->y = _end.y;
	//	_bullet->gravity = 9.8f;
	//}
}

void Gun::BulletMove()
{
	std::list<Bullet*>::iterator iter;
	for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
	{
		if ((*iter)->GetIsBulletFire())
		{
			(*iter)->SetPivotX((*iter)->GetPivotX() + (cosf(PI/ 2) * 3.0f));
			(*iter)->SetPivotY((*iter)->GetPivotY() + (-sinf(PI/2) * 3.0f));

		
			(*iter)->Update();
		}
	}
}

void Gun::SetPivot(float x, float y)
{
}

float Gun::GetPivotX()
{
	return 0.0f;
}

float Gun::GetPivotY()
{
	return 0.0f;
}

void Gun::SetPivotX(float x)
{
}

void Gun::SetPivotY(float y)
{
}

void Gun::SetCenterPivot(RECT rc)
{
}
