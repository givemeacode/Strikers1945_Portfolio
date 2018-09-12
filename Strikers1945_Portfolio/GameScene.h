#pragma once

#include "MainGame.h"
class Player;
class Monster;

class GameScene
	: public MainGame
{
private:
	Player * player;
	Monster * _monster;
public:
	GameScene();
	~GameScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

