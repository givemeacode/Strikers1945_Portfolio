#pragma once

#include "Monster.h"
class NormalMonster
	: public Monster
{
public:
	NormalMonster();
	NormalMonster(GAMEPOS pos);
	~NormalMonster();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	void Update();
	void Render(HDC hdc);
public:
	void MonsterAI();
};

