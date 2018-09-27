#pragma once

#include "Scene.h"

class GameOver
	: public Scene
{
private:
	Image* backImg1;
	Image* backImg2;
private:
	RECT rcClient;
private:
	float deltaTime;
	int alpha;
	bool isSelect;
	int iSelectIndex;
public:
	GameOver();
	~GameOver();
public:
	bool Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

