#include "stdafx.h"
#include "DegreeGun.h"
#include "Bullet.h"


DegreeGun::DegreeGun()
{
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
				(*iter)->Render(hdc,1);
			}
		}
	}
}

void DegreeGun::Release()
{
}

void DegreeGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(TEXT("BossBullet"), x, y, 25);
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);			
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

				// 위치 갱신
				(*iter)->Update(1);

				// 충돌처리
				//if ((*iter)->GetPivotY() <= 15 || (*iter)->GetPivotY() >= WINSIZEY)
				//{
				 //	(*iter)->SetIsBulletFire(false);
				//	(*iter)->SetIsCollision(true);
				//	
				//	//delete (*iter);
				//	//iter = bulletList.erase(iter);
				//	//
				//	//if (bulletList.empty())
				//	//{
				//	//	break;
				//	//}
				//}
			}
		}

		if (bulletList.empty())
		{
			return;
		}

		// 삭제 
		for (it = bulletList.begin(); it != bulletList.end();)
		{
			if (!(*it)->GetIsBulletFire() && (*it)->GetIsCollision())
			{
				it = bulletList.erase(it);

				if (bulletList.empty())
				{
					break;
				}
			}
			else
			{
				it++;
			}
		}
	}	
}
