#pragma once

#include "SingleTon.h"

class Player;
class Monster;

typedef struct sCharacterPositon
{

	RECT rcGameLeft1;
	RECT rcGameLeft2;
	RECT rcGameLeft3;
	
	RECT rcGameRight1;
	RECT rcGameRight2;
	RECT rcGameRight3;

	POINT ptGameCenterLeft1;
	POINT ptGameCenterLeft2;
	POINT ptGameCenterLeft3;

	POINT ptGameCenterRight1;
	POINT ptGameCenterRight2;
	POINT ptGameCenterRight3;

}CPOS;

class GameSystem
	: public SingletonBase<GameSystem>
{
private:
	CPOS posInfo;
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
	void GameResourceInit();
	void SetPlayer(Player* _player);
	CPOS& GetPosInfo();
	void CollisionObject(std::list<Monster*> monsterlist);
	Player* GetPlayer() { return player; }
};

