#include "stdafx.h"
#include "MultiGun.h"
#include "Bullet.h"


MultiGun::MultiGun()
{
	fAngle = PI + PI / 2;
	_cooltime = 5.0f;
}


MultiGun::~MultiGun()
{
}

bool MultiGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	
	return true;
}

void MultiGun::Render(HDC hdc)
{
	std::list<Bullet*>::iterator it;
	if (!bulletList.empty())
	{
		for (it = bulletList.begin(); it != bulletList.end(); it++)
		{
			(*it)->Render(hdc,1);
		}
	}
}

void MultiGun::Release()
{
}

void MultiGun::BulletFire(float x, float y)
{
	//for (int i = 0; i < 5; i++)
	//{
	//	Bullet* bullet[5] = {0,};
	//	bullet[5] = new Bullet();

	//	bullet[i]->Init(x, y, 10);
	//	bullet[i]->SetIsBulletFire(true);
	//	bulletList.push_back(bullet[i]);
	//	
	//	bullet[0]->SetAngle(fAngle);
	//	bullet[1]->SetAngle(fAngle + PI / 2);
	//	bullet[2]->SetAngle(fAngle + PI / 4);
	//	bullet[3]->SetAngle(fAngle - PI / 2);
	//	bullet[4]->SetAngle(fAngle - PI / 4);
	//}


	for (int i = 0; i < 5; i++)
	{
		Bullet* bullet = new Bullet();
		bullet->Init(TEXT("MBasic_Bullet2"), x, y, 10);				// 반지름 사용 
		bullet->Init(x, y, 10);
		bullet->SetIsBulletFire(true);
		bulletList.push_back(bullet);
	}

	std::list<Bullet*>::iterator it;
	int iCount = 0;
	for (it = bulletList.begin(); it != bulletList.end(); it++)
	{
		switch (iCount)
		{
		case 0:
			(*it)->SetAngle(fAngle);
			break;
		case 1:
			(*it)->SetAngle(fAngle + PI / 4);
			break;
		case 2:
			(*it)->SetAngle(fAngle + PI / 5);
			break;
		case 3:
			(*it)->SetAngle(fAngle - PI / 4);
			break;
		case 4:
			(*it)->SetAngle(fAngle - PI / 5);
			iCount = -1;
			break;
		}
		iCount++;
	}
}

void MultiGun::BulletMove()
{
	std::list<Bullet*>::iterator it;

	for (it = bulletList.begin(); it != bulletList.end(); it++)
	{
		if ((*it)->GetIsBulletFire())
		{
			(*it)->SetPivotX((*it)->GetPivotX() + cosf((*it)->GetAngle()) * fSpeed);
			(*it)->SetPivotY((*it)->GetPivotY() + -sinf((*it)->GetAngle()) * fSpeed);

			(*it)->Update(1);

		}
	}
}
