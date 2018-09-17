#pragma once

#include "SingleTon.h"

class Player;
class Monster;

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
	RECT rcClient;
	Player* player;
	
public:
	GameSystem();
	~GameSystem();
public:
	RECT GetGameClientRect();
public:
	void SetPlayer(Player* _player);
	void CollisionCharacter(Monster* _monster,RECT& rcTest);
	void GameSceneMonsterInit();
};

