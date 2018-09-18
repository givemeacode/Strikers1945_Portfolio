#include "stdafx.h"
#include "Gun.h"
#include "Bullet.h"


Gun::Gun()
{
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
<<<<<<< master
	std::list<Bullet*>::iterator iter;
	for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
=======
	/*std::list<Bullet*>::iterator iter;
	if (!bulletList.empty())
>>>>>>> local
	{
		(*iter)->Render(hdc);
	}
<<<<<<< master
=======
	*/
>>>>>>> local

}

void Gun::Release()
{
}

void Gun::BulletFire(float x, float y)
{
<<<<<<< master
	Bullet* bullet = new Bullet();
	bullet->Init(x, y);
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);
=======
	//Bullet* bullet = new Bullet();
	//bullet->Init(x, y, 15);				// 반지름 사용 
	//bullet->SetIsBulletFire(true);
	//bulletList.push_back(bullet);


>>>>>>> local
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
<<<<<<< master
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
=======
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
>>>>>>> local
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
