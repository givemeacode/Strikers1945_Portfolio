#include "stdafx.h"
#include "AirMonster.h"

#include "Gun.h"
#include "NormalGun.h"
#include "GuidedMissileGun.h"


AirMonster::AirMonster()
{	
}

AirMonster::AirMonster(GAMEPOS ePos)
{
	startPos = ePos;
	isLive = true;
	fHp = 1;
	score = 100;
	
}


AirMonster::~AirMonster()
{
}

bool AirMonster::Init(int x, int y)
{
	//================================================== 총알 연습 ================================
	//rcMonster = RectMakeCenter(x, y, 50, 50);
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);
	ptMonster.x = rcMonster.left + ((rcMonster.right - rcMonster.left) / 2);
	ptMonster.y = rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2);

	SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));
	// 피벗 위치 가운데 생성 
	//SetCenterPivot(rcMonster);

	//SetPivotX(x);
	//SetPivotY(y);

	//_gun = new Gun();
	_gun = new GuidedMissileGun();

	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool AirMonster::Init(const TCHAR * fileName, int x, int y)
{
	// 충돌 위치 초기화 
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);

	//SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	//SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));

	SetCenterPivot(rcMonster);

	// 몬스터 이미지 생성 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// Gun 생성 
	_gun = new GuidedMissileGun();
	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool AirMonster::Init(const TCHAR * fileName)
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
	_gun = new GuidedMissileGun();
	_gun->Init(GetPivotX(), GetPivotY());
	return true;
}

bool AirMonster::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName,number);

	airMonsterImg = IMAGEMANAGER->FindImage(file);
	monsterImg = airMonsterImg;
	StartPosition(airMonsterImg);
	LastPosition(pos);
	
	airMonsterImg->SetX(rcMonster.left);
	airMonsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	width = airMonsterImg->GetFrameWidth();
	height = airMonsterImg->GetFrameHeight();

	//
	// Gun 생성 
	//_gun = new NormalGun();
	_gun = new GuidedMissileGun();
	_gun->Init(GetPivotX(), GetPivotY());


	return true;
}

bool AirMonster::Init(const TCHAR * fileName, int number, MonsterType _mType, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName, number);

	airMonsterImg = IMAGEMANAGER->FindImage(file);
	monsterImg = airMonsterImg;
	StartPosition(airMonsterImg);
	LastPosition(pos);

	airMonsterImg->SetX(rcMonster.left);
	airMonsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	width = airMonsterImg->GetFrameWidth();
	height = airMonsterImg->GetFrameHeight();

	mType = _mType;
	//
	// Gun 생성 
	//_gun = new NormalGun();
	_gun = new GuidedMissileGun();
	_gun->Init(GetPivotX(), GetPivotY());
	//effectDeadImg = IMAGEMANAGER->FindImage(TEXT("Effect_5"));
	/*effectDead->Init(effectDeadImg, airMonsterImg->GetFrameWidth(), airMonsterImg->GetFrameHeight(),
		1, 1.0f);*/
	
	return true;
}

void AirMonster::Update()
{ 
	MonsterAI();

}

void AirMonster::Render(HDC hdc)
{
	if (GetIsLive() )
	{
		//DrawObject(hdc, rcMonster, 1, RGB(0, 255, 255), RECTANGLE);
		airMonsterImg->FrameRender(hdc, rcMonster.left, rcMonster.top, 0, 0);
	}
	else
	{
		EFFECTMANAGER->Render(hdc);
	}

	_gun->Render(hdc);


}

void AirMonster::Release()
{
 	_gun->Release();
	SAFE_DELETE(_gun);
	//SAFE_DELETE(monsterImg);
	monsterImg->Release();
}

void AirMonster::MonsterAI()
{
	//\
	
	if (_gun == NULL)
	{
		return;
	}
	if (isLive && fHp <= 0)
	{
		GAMESYS->AddScore(GetScore());
		GAMESYS->IsScore(true);
		//SetScore(GetScore() + 100);
		isLive = false;
	}

	//
	//////
	//
	//float _angle = UTIL::GetAngle(rcPosX, rcPosY,
	//	GAMESYS->GetPosInfo().ptGameCenterRight1.x, GAMESYS->GetPosInfo().ptGameCenterRight1.y);



	float _angle = UTIL::GetAngle(GetPivotX(), GetPivotY(),
		ptLastPos.x, ptLastPos.y);

	//rcPosX += (cosf(_angle) * 2.0f);
	//rcPosY += (-sinf(_angle) * 2.0f);

	////SetPivotX(GetPivotX() + (cosf(angle) * 2.0f));
	////SetPivotY(GetPivotX() + (-sinf(angle) * 2.0f));

	SetPivotX(GetPivotX() + (cosf(_angle) * 2.0f));
	SetPivotY(GetPivotY() + (-sinf(_angle) * 2.0f));


	if (CollisionRectAndRect(rcMonster, rcLastPos))
	{
		//Release();
		isLive = false;
		isCollision = true;
		//EFFECTMANAGER->Update();
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
			EFFECTMANAGER->Play(TEXT("Effect_1"), effectX, effectY);
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