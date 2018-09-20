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

	//Monster* monster1;
	//Monster* monster2;

	std::list<Monster*> monsterList;
	// 시간관련
	float	worldTime;
	float deltaTime;
	bool stage1;

	float _currentTime;
	float fStartTime;
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

