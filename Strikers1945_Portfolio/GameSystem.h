#pragma once

#include "SingleTon.h"

class Player;
class Monster;
class Boss;

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

	POINT ptGameStart;
	POINT ptGameEnd;

	POINT ptGameCenter;

}CPOS;

class GameSystem
	: public SingletonBase<GameSystem>
{
private:
	CPOS posInfo;
	Player* player;
	Boss* boss;
private:
	float deltaTime;
	bool gameOver;
	int score;
	bool isScore;
	bool isGameClear;
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
	void DeleteObject(std::list<Monster*> monsterlist);
	void DeleteObject(Monster* monster);
	void GameOver();


	Player* GetPlayer() { return player; }

	void SetBoss(Boss* _boss) { boss = _boss; }
	Boss* GetBoss() { return boss; }

	bool IsGameOver() { return gameOver; }
	void SetIsGameOver(bool _isGameOver) { gameOver = _isGameOver; }

	void SetScore(int _score) { score = _score; }
	int GetScore() { return score; }
	void AddScore(int _score) { score += _score; }
	void IsScore(bool _isScore) { isScore = _isScore; }
	bool GetIsScore() { return isScore; }

	bool IsGameClear() { return isGameClear; }
	void SetIsGameClear(bool _isGameClear) { isGameClear = _isGameClear; }


};
