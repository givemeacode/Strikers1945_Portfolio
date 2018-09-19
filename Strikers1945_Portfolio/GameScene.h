#pragma once

//#include "MainGame.h"
#include "Scene.h"

class Player;
class Monster;

class GameScene
	: public Scene
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

