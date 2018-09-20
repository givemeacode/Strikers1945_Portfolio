#include "stdafx.h"
#include "Gun.h"
#include "Bullet.h"


Gun::Gun()
{
	fAngle = PI + (PI / 2);
	fSpeed = 10.f;
}


Gun::~Gun()
{
}

bool Gun::Init(float x, float y)
{
	/*fPosX = x;
	fPosY = y + 3;
	*/
	return true;
}



void Gun::Render(HDC hdc)
{
	/*std::list<Bullet*>::iterator iter;
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
	*/

}

void Gun::Release()
{
}

void Gun::BulletFire(float x, float y)
{
	 
	//Bullet* bullet = new Bullet();
	//bullet->Init(x, y, 15);				// 반지름 사용 
	//bullet->SetIsBulletFire(true);
	//bulletList.push_back(bullet);


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
	//std::list<Bullet*>::iterator iter;
	//if (!bulletList.empty())
	//{
	//	for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
	//	{
	//		if ((*iter)->GetIsBulletFire())
	//		{
	//			(*iter)->SetPivotX((*iter)->GetPivotX() + (cosf(fAngle) * 8.0f));
	//			(*iter)->SetPivotY((*iter)->GetPivotY() + (-sinf(fAngle) * 8.0f));
	//			// 위치 갱신
	//			(*iter)->Update();

	//			// 충돌처리
	//			if ((*iter)->GetPivotY() <= 15 || (*iter)->GetPivotY() >= WINSIZEY)
	//			{
	//		 		(*iter)->SetIsBulletFire(false);
	//				//delete (*iter);
	//				//iter = bulletList.erase(iter);
	//				//
	//				//if (bulletList.empty())
	//				//{
	//				//	break;
	//				//}
	//			}
	//		}
	//	}

	//	// 삭제 
	//	for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
	//	{
	//		if (!(*iter)->GetIsBulletFire())
	//		{
	//			delete (*iter);
	//			iter = bulletList.erase(iter);

	//			if (bulletList.empty())
	//			{
	//				break;
	//			}
	//		}
	//	}

	//}
}

void Gun::SetPivot(float x, float y)
{
}

float Gun::GetPivotX()
{
	return fPosX;
}

float Gun::GetPivotY()
{
	return fPosY;
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

std::list<Bullet*>& Gun::GetBulletList()
{
	return bulletList;
}
