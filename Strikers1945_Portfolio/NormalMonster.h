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
	bool Init(const TCHAR * fileName, int number, GAMEPOS pos);
	void Update();
	void Render(HDC hdc);
	void Release();

public:
	void MonsterAI();
};

