#include "stdafx.h"
#include "NormalMonster.h"

#include "Gun.h"
#include "NormalGun.h"

NormalMonster::NormalMonster()
{
}

NormalMonster::NormalMonster(GAMEPOS ePos)
{

}


NormalMonster::~NormalMonster()
{
}

bool NormalMonster::Init(int x, int y)
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

bool NormalMonster::Init(const TCHAR * fileName, int x, int y)
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

bool NormalMonster::Init(const TCHAR * fileName)
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

void NormalMonster::Update()
{
	MonsterAI();
}

void NormalMonster::Render(HDC hdc)
{
	DrawObject(hdc, rcMonster, 1, RGB(0, 255, 255), RECTANGLE);

	monsterImg->FrameRender(hdc, rcMonster.left, rcMonster.top, 0, 0);
	_gun->Render(hdc);
}

void NormalMonster::MonsterAI()
{

	////
	float _angle = UTIL::GetAngle(rcPosX, rcPosY,
		GAMESYS->GetPosInfo().ptGameCenterRight1.x, GAMESYS->GetPosInfo().ptGameCenterRight1.y);

	rcPosX += (cosf(_angle) * 2.0f);
	rcPosY += (-sinf(_angle) * 2.0f);

	////SetPivotX(GetPivotX() + (cosf(angle) * 2.0f));
	////SetPivotY(GetPivotX() + (-sinf(angle) * 2.0f));

	SetPivotX(rcPosX);
	SetPivotY(rcPosY);


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
