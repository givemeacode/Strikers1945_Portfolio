#include "stdafx.h"
#include "GuidedMissileGun.h"
#include "Bullet.h"
#include "Player.h"


GuidedMissileGun::GuidedMissileGun()
{
	guidedMissileGunImage = IMAGEMANAGER->FindImage(TEXT("MGuide_Bullet"));
	guidedMissileGunAni = new Animation;
	guidedMissileGunAni->Init(guidedMissileGunImage);
	guidedMissileGunAni->setDefPlayFrame(true, true); // (리버스, 루프)
	guidedMissileGunAni->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.

	fAngle = PI + PI /2 ;
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
				guidedMissileGunImage->AniRender(hdc, (*iter)->GetPivotX() - 6, (*iter)->GetPivotY() - 8, guidedMissileGunAni); // 총알이미지 크기가 12,16 이니까 6,8만큼 조정해서 중간으로 옴겨줌.
			}
		}
	}
}

void GuidedMissileGun::Release()
{
	SAFE_DELETE(guidedMissileGunAni);
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

	guidedMissileGunAni->start();
}

void GuidedMissileGun::BulletMove()
{
	std::list<Bullet*>::iterator it;
	for (it = bulletList.begin(); it != bulletList.end(); it++)
	{
		if ((*it)->GetIsBulletFire())
		{
			(*it)->SetPivotX((*it)->GetPivotX() + cosf((*it)->GetAngle()) * fSpeed);
			(*it)->SetPivotY((*it)->GetPivotY() + (-sinf((*it)->GetAngle()) * fSpeed));

			(*it)->Update();
		}
	}
	guidedMissileGunAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

}	



