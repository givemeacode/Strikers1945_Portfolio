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
	bool Init(const TCHAR * fileName, int number, GAMEPOS pos);
	bool Init(const TCHAR* fileName, int number, MonsterType _mType, GAMEPOS pos);

	void Update();
	void Render(HDC hdc);
	void Release();

public:
	void MonsterAI();
};

