#pragma once

#include "SingleTon.h"

class Player;

struct sCharacterPositon
{

	RECT rcGameLeft1;
	RECT rcGameLeft2;
	RECT rcGameLeft3;
	
	RECT rcGameRight1;
	RECT rcGameRight2;
	RECT rcGameRight3;

	POINT ptGameLeft1;
	POINT ptGameLeft2;
	POINT ptGameLeft3;

	POINT ptGameRight1;
	POINT ptGameRight2;
	POINT ptGameRight3;

};

class GameSystem
	: public SingletonBase<GameSystem>
{
private:
	sCharacterPositon posInfo;
	Player* player;
private:
	RECT rcClient;
public:
	GameSystem();
	~GameSystem();
public:
	bool Init();
public:
	RECT GetGameClientRect();
	void GamePositionInfoInit();
	void SetPlayer(Player* _player);
	Player* GetPlayer() { return player; }
};

