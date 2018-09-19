#pragma once

#include "MainGame.h"
class Player;
class Monster;

class GameScene
	: public MainGame
{
private:
	Player * player;

	//RECT rcTest;
public:
	GameScene();
	~GameScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

