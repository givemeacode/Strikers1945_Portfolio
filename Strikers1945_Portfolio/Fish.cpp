#include "stdafx.h"
#include "Fish.h"

#include "Gun.h"
#include "RevolvingGun.h"

Fish::Fish()
{
}

Fish::Fish(GAMEPOS ePos)
{
	startPos = ePos;
	isLive = true;
	fHp = 20.0f;
	score = 500;

}


Fish::~Fish()
{
}

bool Fish::Init(int x, int y)
{
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);
	ptMonster.x = rcMonster.left + ((rcMonster.right - rcMonster.left) / 2);
	ptMonster.y = rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2);

	SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));
	
	_gun = new RevolvingGun();

	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool Fish::Init(const TCHAR * fileName, int x, int y)
{
	// �浹 ��ġ �ʱ�ȭ 
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);

	SetCenterPivot(rcMonster);

	// ���� �̹��� ���� 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// Gun ���� 
	_gun = new RevolvingGun();
	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool Fish::Init(const TCHAR * fileName)
{
	// ���� �̹��� ���� 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// ���� �ʱ� ��ġ 
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
	// Gun ���� 
	_gun = new RevolvingGun();
	_gun->Init(GetPivotX(), GetPivotY());
	return true;
}

bool Fish::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName, number);

	monsterImg = IMAGEMANAGER->FindImage(file);
	//monsterImg = airMonsterImg;
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
	// Gun ���� 
	_gun = new RevolvingGun();
	_gun->Init(GetPivotX(), GetPivotY());


	return true;
}

bool Fish::Init(const TCHAR * fileName, int number, MonsterType _mType, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName, number);

	monsterImg = IMAGEMANAGER->FindImage(file);
	//monsterImg = airMonsterImg;
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
	//
	// Gun ���� 
	_gun = new RevolvingGun();
	_gun->Init(GetPivotX(), GetPivotY());


	return true;
}

void Fish::Update()
{
	MonsterAI();

}

void Fish::Render(HDC hdc)
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

void Fish::Release()
{
	_gun->Release();
	SAFE_DELETE(_gun);
	monsterImg->Release();
}

void Fish::MonsterAI()
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


	float _angle = UTIL::GetAngle(GetPivotX(), GetPivotY(),
		ptLastPos.x, ptLastPos.y);

	SetPivotX(GetPivotX() + (cosf(_angle) * 2.0f));
	SetPivotY(GetPivotY() + (-sinf(_angle) * 2.0f));


	if (CollisionRectAndRect(rcMonster, rcLastPos))
	{
		//Release();
		isLive = false;
		isCollision = true;
	}

	//
	coolTime -= TIMEMANAGER->getElapsedTime();
	if (isLive)
	{
		if (coolTime <= 0.0f) // 3.0f�ʸ��� ��.
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
			EFFECTMANAGER->Play(TEXT("Effect_4"), effectX, effectY);
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