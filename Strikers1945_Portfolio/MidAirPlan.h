#pragma once
#include "Monster.h"

class MidAirPlan
	: public Monster
{
public:
	MidAirPlan();
	MidAirPlan(GAMEPOS pos);
	~MidAirPlan();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	void Update();
	void Render(HDC hdc);
	void MonsterAI();
};

