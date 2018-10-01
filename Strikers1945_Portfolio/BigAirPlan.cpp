#include "stdafx.h"
#include "BigAirPlan.h"

#include "Gun.h"
#include "MultiGun.h"

BigAirPlan::BigAirPlan()
{
	
}

BigAirPlan::BigAirPlan(GAMEPOS ePos)
{
	startPos = ePos;
	isLive = true;
	isMove = false;
	deltaTime = 10.f;
	fHp = 30.f;
	score = 500;

}


BigAirPlan::~BigAirPlan()
{
}

bool BigAirPlan::Init(int x, int y)
{
	//================================================== 총알 연습 ================================
	//rcMonster = RectMakeCenter(x, y, 50, 50);
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);
	ptMonster.x = rcMonster.left + ((rcMonster.right - rcMonster.left) / 2);
	ptMonster.y = rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2);

	SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));

	_gun = new MultiGun();

	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool BigAirPlan::Init(const TCHAR * fileName, int x, int y)
{
	// 충돌 위치 초기화 
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);

	SetCenterPivot(rcMonster);

	// 몬스터 이미지 생성 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// Gun 생성 
	_gun = new MultiGun();
	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool BigAirPlan::Init(const TCHAR * fileName)
{
	// 몬스터 이미지 생성 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// 몬스터 초기 위치 
	rcMonster = RectMakeCenter(
		GAMESYS->GetPosInfo().ptGameCenterLeft1.x,
		GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		monsterImg->GetFrameWidth(), monsterImg->GetFrameHeight()
	);

	monsterImg->SetX(rcMonster.left);
	monsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	//
	// Gun 생성 
	_gun = new MultiGun();
	_gun->Init(GetPivotX(), GetPivotY());
	return true;
}

bool BigAirPlan::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName, number);

	monsterImg = IMAGEMANAGER->FindImage(file);
	StartPosition(monsterImg);
	LastPosition(pos);

	monsterImg->SetX(rcMonster.left);
	monsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	width = monsterImg->GetFrameWidth();
	height = monsterImg->GetFrameHeight();

	//
	// Gun 생성 
	_gun = new MultiGun();
	_gun->Init(GetPivotX(), GetPivotY());


	return true;
}

bool BigAirPlan::Init(const TCHAR * fileName, int number, MonsterType _mType, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName, number);

	monsterImg = IMAGEMANAGER->FindImage(file);
	StartPosition(monsterImg);
	LastPosition(pos);

	monsterImg->SetX(rcMonster.left);
	monsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	width = monsterImg->GetFrameWidth();
	height = monsterImg->GetFrameHeight();

	mType = _mType;
	// Gun 생성 
	_gun = new MultiGun();
	_gun->Init(GetPivotX(), GetPivotY());


	//
	return true;
}

void BigAirPlan::Update()
{
	MonsterAI();

}

void BigAirPlan::Render(HDC hdc)
{
	if (GetIsLive())
	{
		//DrawObject(hdc, rcMonster, 1, RGB(0, 255, 255), RECTANGLE);
		monsterImg->FrameRender(hdc, rcMonster.left, rcMonster.top, 0, 0);
	}
	else
	{
		EFFECTMANAGER->Render(hdc);
	}

	_gun->Render(hdc);


}

void BigAirPlan::Release()
{
	_gun->Release();
	SAFE_DELETE(_gun);
	monsterImg->Release();
}

void BigAirPlan::MonsterAI()
{
	if (_gun == NULL)
	{
		return;
	}
	//
	if (isLive && fHp <= 0)
	{
		GAMESYS->AddScore(GetScore());
		GAMESYS->IsScore(true);
		isLive = false;
	}

	if (isStop)
	{
		deltaTime -= TIMEMANAGER->getElapsedTime();

		if (deltaTime <= 0.0f)
		{
			isMove = true;
		}
	}




	float _angle = UTIL::GetAngle(GetPivotX(), GetPivotY(),
		ptLastPos.x, ptLastPos.y);


	if (isStop == false)
	{
		SetPivotY(GetPivotY() + 3.f);
	}

	if (!isMove)
	{
		if (ptLastPos.y < GetPivotY())
		{
			isStop = true;
			SetPivotY(ptLastPos.y);
		}
	}
	else
	{
		SetPivotY(GetPivotY() + 3.f);

		if (GetPivotY() >= WINSIZEY + monsterImg->GetFrameHeight() + 200.f)
		{
			isLive = false;
			isCollision = true;
		}
	}
	

	if (CollisionRectAndRect(rcMonster, rcLastPos))
	{
		isLive = false;
		isCollision = true;
	}

	//
	coolTime -= TIMEMANAGER->getElapsedTime();
	if (isLive)
	{
		if (coolTime <= 0.0f) // 3.0f초마다 쏨.
		{
			_gun->BulletFire(GetPivotX(), GetPivotY());

			CoolTimeReset();
		}
	}

	if (!isDeadEffect)
	{
		if (!isLive && !isCollision)
		{
			effectX = GetPivotX();
			effectY = GetPivotY(); 
  			EFFECTMANAGER->Play(TEXT("Effect_5"), effectX, effectY);
			isDeadEffect = true;

		}

	}
	else
	{
		EFFECTMANAGER->Update();
	}


	_gun->BulletMove();

	rcMonster = RectMakeCenter(GetPivotX(), GetPivotY(), width, height);

}
