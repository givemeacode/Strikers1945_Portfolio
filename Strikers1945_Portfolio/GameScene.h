#pragma once

#include "MainGame.h"
class Monster;

class GameScene
	: public MainGame
{
private:
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

