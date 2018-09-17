#include "stdafx.h"
#include "Monster.h"
#include "Gun.h"

Monster::Monster()
{
	fAngle = PI + PI / 2;
}


Monster::~Monster()
{
}

bool Monster::Init(eMonsterType type, int x , int y)
{
	//rcGameClient = GAMESYS->GetGameClientRect();
	//rcGameClient.left = rcGameClient.left + 100;
	//rcGameClient.right -= 100;

	//rcMonster1 = RectMakeCenter(rcGameClient.left - 50, WINSIZEY / 2, 50, 50);
	//rcMonster2 = RectMakeCenter(rcGameClient.right + 50, WINSIZEY / 2, 50, 50);

	//rcMonster3 = RectMakeCenter(rcGameClient.left - 50, WINSIZEY / 4, 50, 50);
	//rcMonster4 = RectMakeCenter(rcGameClient.right + 50, WINSIZEY / 4, 50, 50);

	//rcMonster5 = RectMakeCenter(rcGameClient.left - 50, rcGameClient.top +25, 50, 50);
	//rcMonster6 = RectMakeCenter(rcGameClient.right + 50, rcGameClient.top +25, 50, 50);


	////rcObj = rcMonster1;
	//rcObj = RectMakeCenter(rcGameClient.left - 50, WINSIZEY / 2, 50, 50);
	////rcObjPos = { (rcObj.left + (rcObj.right - rcObj.left)), (rcObj.top + (rcObj.bottom - rcObj.top)) };
	//rcPosX = (rcObj.left + ((rcObj.right - rcObj.left)/2));
	//rcPosY = (rcObj.top + ((rcObj.bottom - rcObj.top)/2));
	
	//================================================== ÃÑ¾Ë ¿¬½À ================================
	rcMonster = RectMakeCenter(x,y , 50, 50);
	
	SetCenterPivot(rcMonster);
	
	_gun = new Gun();
	_gun->Init(eGunType::GUN_NONE, GetPivotX(), GetPivotY()); 

	fStartTime = GetTickCount();
	return true;
}

void Monster::Update()
{
	CurrentTime = GetTickCount();

	MonsterAI();
}

void Monster::Render(HDC hdc)
{
	//DrawObject(hdc, rcGameClient, 1, RGB(0, 128, 128), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster1, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster2, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster3, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster4, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster5, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcMonster6, 1, RGB(0, 255, 0), OBJ_TYPE::RECTANGLE);
	//DrawObject(hdc, rcObj, 1, RGB(0, 255, 255), OBJ_TYPE::RECTANGLE);
	DrawObject(hdc, rcMonster, 1, RGB(0, 255, 255), OBJ_TYPE::RECTANGLE);
	_gun->Render(hdc);
}

void Monster::MonsterAI()
{

	//rcObj.right += cosf(0) * 2.0f;
	//rcObj.left += cosf(0) * 2.0f;
	//rcObj.top += -sinf(PI) * 2.0f;
	//rcObj.bottom += -sinf(PI) * 2.0f;
	//float angle = UTIL::GetAngle((rcObj.left + (rcObj.right - rcObj.left)), (rcObj.top + (rcObj.bottom - rcObj.top)),
	//	(rcMonster2.left + ((rcMonster2.right - rcMonster2.left) /2)), (rcMonster2.top + ((rcMonster2.bottom - rcMonster2.top)/2)));
	//rcObj.left += cosf(angle) * 2.0f;
	//rcObj.right += cosf(angle) * 2.0f;
	//rcObj.top += -sinf(angle) * 2.0f;
	//rcObj.bottom += -sinf(angle) * 2.0f;

	//float angle = UTIL::GetAngle(rcPosX, rcPosY,
	//	(rcMonster4.left + ((rcMonster4.right - rcMonster4.left) / 2)), (rcMonster4.top + ((rcMonster4.bottom - rcMonster4.top) / 2)));
	//rcPosX += cosf(angle) * 2.0f;
	//rcPosY += -sinf(angle) * 2.0f;


	//
	//rcObj = RectMakeCenter(rcPosX, rcPosY, 50, 50);
	/*
	if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
	{
		SetPivotX(GetPivotX() - (cosf(0)) * 2.0f);
	}

	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
	{
		SetPivotX(GetPivotX() + (cosf(0)) * 2.0f);
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		_gun->BulletFire(GetPivotX(),GetPivotY());
	}
*/	

	float deltaTime = (CurrentTime - fStartTime) / 1000.f;
	if (deltaTime > 0.5f)
	{
		_gun->BulletFire(GetPivotX(), GetPivotY());
		fStartTime = GetTickCount();
	}
	_gun->BulletMove();
	//
	rcMonster = RectMakeCenter(GetPivotX(), GetPivotY(), 50, 50);
	
}


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
