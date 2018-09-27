#pragma once

#include "Scene.h"

enum eKey
{
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
};
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

