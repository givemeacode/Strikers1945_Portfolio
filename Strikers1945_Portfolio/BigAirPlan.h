#pragma once

#include "Monster.h"

class BigAirPlan
	: public Monster
{
public:
	BigAirPlan();
	BigAirPlan(GAMEPOS pos);
	~BigAirPlan();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	void Update();
	void Render(HDC hdc);
public:
	void MonsterAI();
};

