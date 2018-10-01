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

	UI* ui;
	//Monster* monster1;
	//Monster* monster2;

	std::list<Monster*> monsterList;
	Image* backImg;
	
	bool stage1;
	
	RECT rcGameClient;
	
	RECT leftRect;
	RECT rightRect;

	float _y;
	float deltaTime;
	float currentTime;
	float coolTime;
	// �ð�����	
	DWORD startTimer; // ��ü ���۽ð�

	DWORD RunTimer;	  // ��ü ����ð� üũ
		//RECT rcTest;
	Boss* boss;
	//RECT rcTest;
private:
	bool isStart1;
	bool isStart2;
	bool isStart3;
	bool isStart4;
	bool isStart5;
	bool isStart6;
	bool isStart7;
	bool isStart8;
	bool isStart9;
	bool isStart10;

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

