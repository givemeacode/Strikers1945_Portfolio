#pragma once

#include "MainGame.h"
class Player;
class Monster;

class GameScene
	: public MainGame
{
private:
	//Player * player;
	Monster * _monster;
	Monster* _monster1;
	Monster* _monster2;
	Monster* _monster3;
	Monster* _monster4;
	Monster* _monster5;
	Monster* _monster6;
	Monster* _monster7;
	Monster* _monster8;
	Monster* _monster9;
	Monster* _monster10;

	std::list<Monster*> _monsterList;
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

