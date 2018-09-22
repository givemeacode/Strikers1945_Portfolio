#include "stdafx.h"
#include "AirMonster.h"

#include "Gun.h"
#include "NormalGun.h"

AirMonster::AirMonster()
{
}

AirMonster::AirMonster(GAMEPOS ePos)
{
	startPos = ePos;
}


AirMonster::~AirMonster()
 {
}

bool AirMonster::Init(int x, int y)
{
	//================================================== �Ѿ� ���� ================================
	//rcMonster = RectMakeCenter(x, y, 50, 50);
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);
	ptMonster.x = rcMonster.left + ((rcMonster.right - rcMonster.left) / 2);
	ptMonster.y = rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2);

	SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));
	// �ǹ� ��ġ ��� ���� 
	//SetCenterPivot(rcMonster);

	//SetPivotX(x);
	//SetPivotY(y);

	//_gun = new Gun();
	_gun = new NormalGun();

	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool AirMonster::Init(const TCHAR * fileName, int x, int y)
{
	// �浹 ��ġ �ʱ�ȭ 
	rcMonster = RectMakeCenter(GAMESYS->GetPosInfo().ptGameCenterLeft1.x, GAMESYS->GetPosInfo().ptGameCenterLeft1.y,
		50, 50);

	//SetPivotX(rcMonster.left + ((rcMonster.right - rcMonster.left) / 2));
	//SetPivotY(rcMonster.bottom + ((rcMonster.bottom - rcMonster.top) / 2));

	SetCenterPivot(rcMonster);

	// ���� �̹��� ���� 
	monsterImg = IMAGEMANAGER->FindImage(TEXT(fileName));

	// Gun ���� 
	_gun = new NormalGun();
	_gun->Init(GetPivotX(), GetPivotY());

	return true;
}

bool AirMonster::Init(const TCHAR * fileName)
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
	_gun = new NormalGun();
	_gun->Init(GetPivotX(), GetPivotY());
	return true;
}

bool AirMonster::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	TCHAR file[256] = { 0, };

	_stprintf(file, TEXT("%s%d"), fileName,number);

	monsterImg = IMAGEMANAGER->FindImage(TEXT(file));

	StartPosition(monsterImg);
	LastPosition(pos);
	
	monsterImg->SetX(rcMonster.left);
	monsterImg->SetY(rcMonster.top);

	SetCenterPivot(rcMonster);

	ptMonster.x = GetPivotX();
	ptMonster.y = GetPivotY();

	rcPosX = static_cast<float>(GetPivotX());
	rcPosY = static_cast<float>(GetPivotY());

	//
	// Gun ���� 
	_gun = new NormalGun();
	_gun->Init(GetPivotX(), GetPivotY());


	return true;
}

void AirMonster::Update()
{ 
	MonsterAI();
}

void AirMonster::Render(HDC hdc)
{
	DrawObject(hdc, rcMonster, 1, RGB(0, 255, 255), RECTANGLE);

	monsterImg->FrameRender(hdc, rcMonster.left, rcMonster.top, 0, 0);

	_gun->Render(hdc);
}

void AirMonster::MonsterAI()
{

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


	//
	coolTime -= TIMEMANAGER->getElapsedTime();
	if (coolTime <= 0.0f) // 3.0f�ʸ��� ��.
	{
		_gun->BulletFire(GetPivotX(), GetPivotY());

		CoolTimeReset();
	}
	_gun->BulletMove();

	//
	rcMonster = RectMakeCenter(GetPivotX(), GetPivotY(), monsterImg->GetFrameWidth(), monsterImg->GetFrameHeight());
}