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
	// 1랩총알
	playerGunImage1 = IMAGEMANAGER->FindImage(TEXT("AV_8_Player_Bullet1"));
	playerGunAni1 = new Animation;
	playerGunAni1->Init(playerGunImage1);
	playerGunAni1->setDefPlayFrame(true, true); // (리버스, 루프)
	playerGunAni1->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.

	// 2랩총알
	playerGunImage2 = IMAGEMANAGER->FindImage(TEXT("AV_8_Player_Bullet2"));
	playerGunAni2 = new Animation;
	playerGunAni2->Init(playerGunImage2);
	playerGunAni2->setDefPlayFrame(true, true); // (리버스, 루프)
	playerGunAni2->setFPS(1);

	// 3랩총알
	playerGunImage3 = IMAGEMANAGER->FindImage(TEXT("AV_8_Player_Bullet3"));
	playerGunAni3 = new Animation;
	playerGunAni3->Init(playerGunImage3);
	playerGunAni3->setDefPlayFrame(true, true); // (리버스, 루프)
	playerGunAni3->setFPS(1);

	// 4랩총알
	playerGunImage4 = IMAGEMANAGER->FindImage(TEXT("AV_8_Player_Bullet4"));
	playerGunAni4 = new Animation;
	playerGunAni4->Init(playerGunImage4);
	playerGunAni4->setDefPlayFrame(true, true); // (리버스, 루프)
	playerGunAni4->setFPS(1);

	fPosX = x;
	fPosY = y + 3;

	fAngle = PI / 2;
	fSpeed = 7.f; // 총알 속도. -> 지정하지않으면 Gun에 있는 fSpeed로 지정됨.

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
				//(*iter)->Render(hdc);

				// AniRender함수에 들어갈 값은 left,top인데 GetPivot값은 중심값을 가져오는거라서, 총알의 크기 반절만큼, 조정을 해줬음
				if (GAMESYS->GetPlayer()->GetPlayerLevel() == 1)
				{
					playerGunImage1->AniRender(hdc, (*iter)->GetPivotX() - 17, (*iter)->GetPivotY() - 25, playerGunAni1);
				}
				if (GAMESYS->GetPlayer()->GetPlayerLevel() == 2)
				{
					playerGunImage2->AniRender(hdc, (*iter)->GetPivotX() - 17, (*iter)->GetPivotY() - 25, playerGunAni2);
				}
				if (GAMESYS->GetPlayer()->GetPlayerLevel() == 3)
				{
					playerGunImage3->AniRender(hdc, (*iter)->GetPivotX() - 17, (*iter)->GetPivotY() - 25, playerGunAni3);
				}
				if (GAMESYS->GetPlayer()->GetPlayerLevel() == 4)
				{
					playerGunImage4->AniRender(hdc, (*iter)->GetPivotX() - 17, (*iter)->GetPivotY() - 25, playerGunAni4);
				}
			}
		}
	}
}

void PlayerGun::Release()
{
	SAFE_DELETE(playerGunAni1);
	SAFE_DELETE(playerGunAni2);
	SAFE_DELETE(playerGunAni3);
	SAFE_DELETE(playerGunAni4);
}

void PlayerGun::BulletFire(float x, float y)
{
	Bullet* bullet = new Bullet();
	bullet->Init(x, y, 15);				// 반지름 사용 
	bullet->SetIsBulletFire(true);
	bulletList.push_back(bullet);


	if (GAMESYS->GetPlayer()->GetPlayerLevel() == 1)
	{
		playerGunAni1->start();

		playerDMG = 1;
		
	}
	else if (GAMESYS->GetPlayer()->GetPlayerLevel() == 2)
	{
		playerGunAni2->start();

		playerDMG = 2;
	}
	else if (GAMESYS->GetPlayer()->GetPlayerLevel() == 3)
	{
		playerGunAni3->start();

		playerDMG = 3;
	}
	else if (GAMESYS->GetPlayer()->GetPlayerLevel() == 4)
	{
		playerGunAni4->start();

		playerDMG = 4;
	}
}

void PlayerGun::BulletMove()
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

				(*iter)->SetPivotY((*iter)->GetPivotY() + ((-sinf(fAngle) * fSpeed)));
				//(*iter)->SetPivotY((*iter)->GetPivotY() + 3.0f);

				// 위치 갱신
				(*iter)->Update();

				// 충돌처리
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

		// 삭제 
		for (it = bulletList.begin(); it != bulletList.end();)
		{
			if (!(*it)->GetIsBulletFire())
			{
				it = bulletList.erase(it);
			}
			else
			{
				++it;
			}
		}

	}

	playerGunAni1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	playerGunAni2->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	playerGunAni3->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	playerGunAni4->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}
