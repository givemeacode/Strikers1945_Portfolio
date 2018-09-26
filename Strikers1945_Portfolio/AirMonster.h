#pragma once

#include "Monster.h"
class AirMonster
	: public Monster
{
private:
	Image* airMonsterImg;
public:
	AirMonster();
	AirMonster(GAMEPOS ePos);
	~AirMonster();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	bool Init(const TCHAR* fileName, int number, GAMEPOS pos);
	bool Init(const TCHAR* fileName, int number, MonsterType _mType, GAMEPOS pos);

	void Update();
	void Render(HDC hdc);
	void Release();
public:
	void MonsterAI();
};

