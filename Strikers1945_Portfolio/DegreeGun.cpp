#include "stdafx.h"
#include "DegreeGun.h"
#include "Bullet.h"


DegreeGun::DegreeGun()
{
	degreeGunImage = IMAGEMANAGER->FindImage(TEXT("BossBullet"));
	degreeGunAni = new Animation;
	degreeGunAni->Init(degreeGunImage);
	degreeGunAni->setDefPlayFrame(false, true); // (������, ����)
	degreeGunAni->setFPS(1); // ������ 1 �����Ӵ� (n) - ������Ʈ�� Ŀ������ ���� �ֱⰡ ª����.

	cycleTypeAngle = 0.1f;
	fAngle = PI + PI / 2;
	fAngle2 = PI + PI / 2;
}


DegreeGun::~DegreeGun()
{
}

bool DegreeGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	fStartX = fPosX;
	fStartY = fPosY;
	

	return true;
}

void DegreeGun::Render(HDC hdc)
{
	std::list<Bullet*>::iterator iter;
	if (!bulletList.empty())
	{
		for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
		{

			if ((*iter)->GetIsBulletFire())
			{
				(*iter)->Render(hdc);
				degreeGunImage->AniRender(hdc, (*iter)->GetPivotX() - 26, (*iter)->GetPivotY() - 25, degreeGunAni); // �Ѿ��̹��� ũ�Ⱑ 52,51 �̴ϱ� 26,25��ŭ �����ؼ� �߰����� �Ȱ���.
			}
		}
	}
}

void DegreeGun::Release()
{
	SAFE_DELETE(degreeGunAni);
}

void DegreeGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 15);				// ������ ��� 
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);

	degreeGunAni->start();
}

void DegreeGun::BulletMove()
{
	std::list<Bullet*>::iterator iter;
	std::list<Bullet*>::iterator it;

	
	if (!bulletList.empty())
	{
		for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
		{
			if ((*iter)->GetIsBulletFire())
			{
				(*iter)->SetPivotX((*iter)->GetPivotX() + (cosf(fAngle)* fSpeed));
				//;

				(*iter)->SetPivotY((*iter)->GetPivotY() + ((-sinf(fAngle += cycleTypeAngle) * fSpeed) + 2.0f));
				//(*iter)->SetPivotY((*iter)->GetPivotY() + 3.0f);

				// ��ġ ����
				(*iter)->Update();

				// �浹ó��
				if ((*iter)->GetPivotY() <= 15 || (*iter)->GetPivotY() >= WINSIZEY)
				{
			 		(*iter)->SetIsBulletFire(false);
					(*iter)->SetIsCollision(true);
					
					//delete (*iter);
					//iter = bulletList.erase(iter);
					//
					//if (bulletList.empty())
					//{
					//	break;
					//}
				}
			}
		}

		if (bulletList.empty())
		{
			return;
		}

		// ���� 
		for (it = bulletList.begin(); it != bulletList.end(); it++)
		{
			if (!(*it)->GetIsBulletFire() && (*it)->GetIsCollision())
			{
				delete (*it);
				it = bulletList.erase(it);

				if (bulletList.empty())
				{
					break;
				}
			}
		}
	}	
	degreeGunAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

}
