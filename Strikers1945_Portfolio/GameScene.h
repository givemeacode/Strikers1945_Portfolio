#pragma once

#include "MainGame.h"

class Monster;

class GameScene
	: public MainGame
{
private:
	RECT rcClient;
	Monster* _monster;

	Image* _backGround;
	float _y;

	float _startTime;
	float _daltaTime;
	float _currentTime;
	float _temp;
public:
	GameScene();
	~GameScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

