#include "stdafx.h"
#include "MultiGun.h"
#include "Bullet.h"


MultiGun::MultiGun()
{
	multiGunImage = IMAGEMANAGER->FindImage(TEXT("MBasic_Bullet2"));
	multiGunAni = new Animation;
	multiGunAni->Init(multiGunImage);
	multiGunAni->setDefPlayFrame(false, true); // (리버스, 루프)
	multiGunAni->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.

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
			(*it)->Render(hdc);
			multiGunImage->AniRender(hdc, (*it)->GetPivotX()-10, (*it)->GetPivotY()-10, multiGunAni);// 총알이미지 크기가 20,21 이니까 10,10만큼 조정해서 중간으로 옴겨줌.
		}
	}
}

void MultiGun::Release()
{
	SAFE_DELETE(multiGunAni);
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


	for (int i = 0; i < 7; i++)
	{
		Bullet* bullet = new Bullet();
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
			(*it)->SetAngle(fAngle + PI / 6);
			break;
		case 2:
			(*it)->SetAngle(fAngle + PI / 7);
			break;
		case 3:
			(*it)->SetAngle(fAngle + PI / 8);
			break;
		case 4:
			(*it)->SetAngle(fAngle - PI / 6);
			break;
		case 5:
			(*it)->SetAngle(fAngle - PI / 7);
			break;
		case 6:
			(*it)->SetAngle(fAngle - PI / 8);
			iCount = -1;
			break;
		}
		iCount++;
	}
	multiGunAni->start();
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

			(*it)->Update();
		}
	}
	multiGunAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}
