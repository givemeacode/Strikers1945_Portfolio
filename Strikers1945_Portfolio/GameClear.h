#pragma once

#include "Scene.h"


class GameClear
	: public Scene
{
private:
	RECT rcText1;
	RECT rcText2;
	RECT rcText3;
	RECT rcText4;


	Image* blackBG;
	Image* abcImg1;
	Image* abcImg2;
	Image* abcImg3;

	//char str[265] = "ÆùÆ® Test 1234";
	bool isScore;
	int iCount;
	bool isPrint;
	bool isOne;
	bool isTwo;
	bool isThr;

private:
	int iIndex1;
	int iIndex2;
	int iIndex3;

	int indexX, indexY;
private:
	float alpha;
public:
	GameClear();
	~GameClear();
public:
	bool Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

