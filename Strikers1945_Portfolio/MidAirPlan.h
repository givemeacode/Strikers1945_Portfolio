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
	bool Init(const TCHAR * fileName, int number, GAMEPOS pos);
	bool Init(const TCHAR* fileName, int number, MonsterType _mType, GAMEPOS pos);

	void Update();
	void Render(HDC hdc);
	void Release();

public:
	void MonsterAI();
};

