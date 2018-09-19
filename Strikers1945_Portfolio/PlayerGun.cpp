#include "stdafx.h"
#include "PlayerGun.h"
#include "Bullet.h"
#include "Player.h"

PlayerGun::PlayerGun()
{
}


PlayerGun::~PlayerGun()
{
}

bool PlayerGun::Init(float x, float y)
{
	fPosX = x;
	fPosY = y + 3;

	fAngle = PI / 2;
	fSpeed = 10.f;
	
	return true;
}

void PlayerGun::Render(HDC hdc)
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

void PlayerGun::Release()
{
}

void PlayerGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 15);				// ������ ��� 
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);


}

void PlayerGun::BulletMove()
{
	std::list<Bullet*>::iterator iter;
	std::list<Bullet*>::iterator it;

	if (GAMESYS->GetPlayer()->GetPlayerLevel() == 1)
	{
		playerDMG = 1;
		// ����1 �̹���
	}
	if (GAMESYS->GetPlayer()->GetPlayerLevel() == 2)
	{
		playerDMG = 2;
		// ����2 �̹���
	}
	if (GAMESYS->GetPlayer()->GetPlayerLevel() == 3)
	{
		playerDMG = 3;
		// ����3 �̹���
	}
	if (GAMESYS->GetPlayer()->GetPlayerLevel() == 4)
	{
		playerDMG = 4;
		// ����4 �̹���
	}


	if (!bulletList.empty())
	{
		for (iter = bulletList.begin(); iter != bulletList.end(); iter++)
		{
			if ((*iter)->GetIsBulletFire())
			{
				(*iter)->SetPivotX((*iter)->GetPivotX() + (cosf(fAngle)* fSpeed));
				//;

				(*iter)->SetPivotY((*iter)->GetPivotY() + ((-sinf(fAngle) * fSpeed)));
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
}
