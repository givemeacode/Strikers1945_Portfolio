#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"
#include "DegreeGun.h"
#include "GuidedMissileGun.h"
#include "MultiGun.h"
#include "RevolvingGun.h"
#include "NormalGun.h"


Monster::Monster()
{
	fAngle = PI + PI / 2;
	coolTime = 2.0f;
	startPos = GAMEPOS::G_NONE;
	lastPos = GAMEPOS::G_NONE;
	isLive = true;
	fHp = 10.0f;
	isCollision = false;
}


Monster::~Monster()
{
}

bool Monster::Init(int x, int y)
{
	
	return true;
}

bool Monster::Init(const TCHAR * fileName, int x, int y)
{
	
	return true;
}

bool Monster::Init(const TCHAR * fileName)
{
	//// 몬스터 이미지 생성 
	//monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));


	return true;
}

bool Monster::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	return true;
}

bool Monster::Init(const TCHAR * fileName, int number, MonsterType _mType, GAMEPOS pos)
{
	return true;
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{


}

void Monster::Release()
{
}
//
//void Monster::MonsterAI()
//{
//
//	////
//	float _angle = UTIL::GetAngle(rcPosX, rcPosY,
//		GAMESYS->GetPosInfo().ptGameCenterRight1.x , GAMESYS->GetPosInfo().ptGameCenterRight1.y  );
//
//	rcPosX += (cosf(_angle) * 2.0f);
//	rcPosY += (-sinf(_angle) * 2.0f);
//
//	////SetPivotX(GetPivotX() + (cosf(angle) * 2.0f));
//	////SetPivotY(GetPivotX() + (-sinf(angle) * 2.0f));
//
//	SetPivotX(rcPosX);
//	SetPivotY(rcPosY);
//
//
//	//
//	coolTime -= TIMEMANAGER->getElapsedTime();
//	if (coolTime <= 0.0f) // 3.0f초마다 쏨.
//	{
//		_gun->BulletFire(GetPivotX(), GetPivotY());
//		
//		CoolTimeReset();
//	}
//	_gun->BulletMove();
//
//	//
//	rcMonster = RectMakeCenter(GetPivotX(), GetPivotY(), monsterImg->GetFrameWidth(), monsterImg->GetFrameHeight());
//
//}


void Monster::SetPivot(float x, float y)
{
	fPivotX = x;
	fPivotY = y;
}
float Monster::GetPivotX()
{
	return fPivotX;
}
float Monster::GetPivotY()
{
	return fPivotY;
}

void Monster::SetPivotX(float x)
{
	fPivotX = x;
}

void Monster::SetPivotY(float y)
{
	fPivotY = y;
}

void Monster::SetCenterPivot(RECT rc)
{
	fPivotX = static_cast<float>(rc.left + ((rc.right - rc.left) / 2));
	fPivotY = static_cast<float>(rc.top + ((rc.bottom - rc.top) / 2));
}

void Monster::CoolTimeReset()
{
	coolTime = 2.0f;
}

void Monster::OffectX(float x)
{
	if (GAMEPOS::G_LEFT1 == startPos || GAMEPOS::G_LEFT2 == startPos || GAMEPOS::G_LEFT3 == startPos)
	{
		SetPivotX(GetPivotX() - x);
	}
	else if (GAMEPOS::G_RIGHT1 == startPos || GAMEPOS::G_RIGHT2 == startPos || GAMEPOS::G_RIGHT3 == startPos)
	{
		SetPivotX(GetPivotX() + x);
	}
}

void Monster::OffectY(float y)
{
	if (GAMEPOS::G_LEFT1 == startPos || GAMEPOS::G_LEFT2 == startPos || GAMEPOS::G_LEFT3 == startPos)
	{
		SetPivotY(GetPivotY() - y);
	}
	else if (GAMEPOS::G_RIGHT1 == startPos || GAMEPOS::G_RIGHT2 == startPos || GAMEPOS::G_RIGHT3 == startPos)
	{
		SetPivotY(GetPivotY() + y);
	}

}

void Monster::StartPosition(Image * img)
{

	switch (startPos)
	{
	case GAMEPOS::G_LEFT1:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterLeft1.x,
			GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_LEFT2:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterLeft2.x,
			GAMESYS->GetPosInfo().ptGameCenterLeft2.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_LEFT3:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterLeft3.x,
			GAMESYS->GetPosInfo().ptGameCenterLeft3.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_RIGHT1:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterRight1.x,
			GAMESYS->GetPosInfo().ptGameCenterRight1.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_RIGHT2:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterRight2.x,
			GAMESYS->GetPosInfo().ptGameCenterRight2.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_RIGHT3:
		rcMonster = RectMakeCenter(
			GAMESYS->GetPosInfo().ptGameCenterRight3.x,
			GAMESYS->GetPosInfo().ptGameCenterRight3.y,
			img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_UPDOWN1:
		rcMonster = RectMakeCenter(
			WINSIZEX / 3 , -(img->GetFrameHeight()), img->GetFrameWidth(), img->GetFrameHeight()
		);
		break;
	case GAMEPOS::G_UPDOWN2:
		rcMonster = RectMakeCenter(
			(WINSIZEX - WINSIZEX / 3), -(img->GetFrameHeight()), img->GetFrameWidth(), img->GetFrameHeight()
		);

		break;
	}
}

void Monster::LastPosition(GAMEPOS pos)
{
	switch (pos)
	{
	case GAMEPOS::G_LEFT1:
		rcLastPos = GAMESYS->GetPosInfo().rcGameLeft1;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterLeft1;
		break;
	case GAMEPOS::G_LEFT2:
		rcLastPos = GAMESYS->GetPosInfo().rcGameLeft2;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterLeft2;
		break;
	case GAMEPOS::G_LEFT3:
		rcLastPos = GAMESYS->GetPosInfo().rcGameLeft3;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterLeft3;
		break;
	case GAMEPOS::G_RIGHT1:
		rcLastPos = GAMESYS->GetPosInfo().rcGameRight1;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterRight1;
		break;
	case GAMEPOS::G_RIGHT2:
		rcLastPos = GAMESYS->GetPosInfo().rcGameRight2;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterRight2;
		break;
	case GAMEPOS::G_RIGHT3:
		rcLastPos = GAMESYS->GetPosInfo().rcGameRight3;
		ptLastPos = GAMESYS->GetPosInfo().ptGameCenterRight3;
		break;
	case GAMEPOS::G_CENTER1:
		ptLastPos = { WINSIZEX / 3 , WINSIZEY / 2 - 150 };
		break;
	case GAMEPOS::G_CENTER2:
		ptLastPos = { (WINSIZEX - WINSIZEX / 3), WINSIZEY / 2 - 300 };
		break;
	}
}

void Monster::DeCreaseHp(float _attackPoint)
{
	fHp -= _attackPoint;
}
