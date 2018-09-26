#pragma once

//#include "MainGame.h"
#include "Scene.h"

class Player;
class Monster;
class Boss;
class UI;

class GameScene
	: public Scene
{
private:
	Player * player;


	UI*	ui;
	//Monster* monster1;
	//Monster* monster2;

	std::list<Monster*> monsterList;
	
	
	bool stage1;
	
	// 시간관련	
	DWORD startTimer; // 전체 시작시간

	DWORD RunTimer;	  // 전체 진행시간 체크
		//RECT rcTest;
	Boss* boss;
	//RECT rcTest;
public:
	GameScene();
	~GameScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
public:
	void AppearType1();
	void AppearType2();
};

