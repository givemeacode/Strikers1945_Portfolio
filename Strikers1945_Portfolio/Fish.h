#pragma once
#include "Monster.h"
class Fish
	: public Monster
{
public:
	Fish();
	Fish(GAMEPOS pos);
	~Fish();
public:
	bool Init(int x, int y);
	bool Init(const TCHAR* fileName, int x, int y);
	bool Init(const TCHAR* fileName);
	void Update();
	void Render(HDC hdc);
public:
	void MonsterAI();
};

