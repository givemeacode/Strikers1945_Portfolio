#pragma once

#include "Monster.h"
class AirMonster
	: public Monster
{
public:
	AirMonster();
	AirMonster(GAMEPOS ePos);
	~AirMonster();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	bool Init(const TCHAR* fileName, int number, GAMEPOS pos);

	void Update();
	void Render(HDC hdc);
public:
	void MonsterAI();
};

