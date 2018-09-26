#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

#include "Monster.h"
#include "Timer.h"
#include "Boss.h"
#include "AirMonster.h"
#include "BigAirPlan.h"
#include "MidAirPlan.h"
#include "Fish.h"

#pragma comment (lib,"winmm")

GameScene::GameScene()
{
	sceneType = eSceneType::SCENE_GAME1;
}

GameScene::~GameScene()
{

}

bool GameScene::Init()
{
	//GameNode::Init(true);
	//=========================================================
	
	// 시간
	RunTimer = 0;
	startTimer = GetTickCount(); // 전체 시작시간

	// 플레이어
	//player = new Player;
	//GAMESYS->SetPlayer(player);
	player = GAMESYS->GetPlayer();
	// 몬스터


	//
	//monster1 = new Monster;
	//monster1->Init(MONSTER_TYPE_NONE, 0, 100);

	//monster2 = new Monster;
	//monster2->Init(MONSTER_TYPE_NONE, WINSIZEX, 100);
	//player = new Player;
	//GAMESYS->SetPlayer(player);
	
	//boss = new Boss();
	//boss->Init();
	return true;
}

void GameScene::Release()
{
	//GameNode::Release();
	//=========================================================

//	SAFE_DELETE(player);

	//=========================================================
	//=========================================================

}

void GameScene::Update()
{
	//GameNode::Update();
	//=========================================================
	// 시간
	RunTimer = GetTickCount() - startTimer; // 전체시간

	// 플레이어
	player->Update();

// 테스트
	
	if (RunTimer % 2000 == 500  && RunTimer < 60 * THOU) // 2초마다 나옴 60초 이전까지 랜덤한 위치에서 나옴
	{
		int iRand = RAND->getInt(6); // 0~5의 값을 랜덤하게 가져옴
		GAMEPOS randIndex1;
		GAMEPOS randIndex2;

		switch (iRand)
		{
		case 0:
			randIndex1 = GAMEPOS::G_LEFT1;
			randIndex2 = GAMEPOS::G_RIGHT2;
			break;
		case 1:
			randIndex1 = GAMEPOS::G_LEFT2;
			randIndex2 = GAMEPOS::G_RIGHT3;
			break;
		case 2:
			randIndex1 = GAMEPOS::G_LEFT3;
			randIndex2 = GAMEPOS::G_RIGHT1;
			break;
		case 3:
			randIndex1 = GAMEPOS::G_RIGHT1;
			randIndex2 = GAMEPOS::G_LEFT2;
			break;
		case 4:
			randIndex1 = GAMEPOS::G_RIGHT2;
			randIndex2 = GAMEPOS::G_LEFT3;
			break;
		case 5:
			randIndex1 = GAMEPOS::G_RIGHT3;
			randIndex2 = GAMEPOS::G_LEFT1;
			break;
		}

		Monster* monster = new AirMonster(randIndex1);
		monster->Init(TEXT("air_Monster"), 8, MonsterType::RandomType, randIndex2);
		monsterList.push_back(monster);		
	}
		
	// 몬스터
	//=============================== 30초 ~ 1분 ===================================

	if (RunTimer == 20 * THOU) // 30초 : 1번 왼쪽 -> 오른쪽 위 [ 1]
	{
		AppearType1();
	}
	if (RunTimer == 25 * THOU) // 32초 :  오른쪽 -> 왼쪽 위 [2] 
	{
		AppearType2();
	}
	if (RunTimer == 30 * THOU) // 35초 : 위 -> 아래 중심으로 이동 (중간 캐릭터 ) 
	{
		Monster* bigAirPlan = new BigAirPlan(GAMEPOS::G_UPDOWN); 
		bigAirPlan->Init(TEXT("BigAirPlan"), 1, MonsterType::MiddleType1, GAMEPOS::G_RIGHT1);

		monsterList.push_back(bigAirPlan);
		

		int width = 0;
		std::list<Monster*>::iterator it;
		for (it = monsterList.begin(); it != monsterList.end(); it++)
		{
			if ((*it)->GetType() == MonsterType::MiddleType1)
			{
				width = (*it)->GetImage()->GetFrameWidth();
				(*it)->OffectX(width);
			}
		}
	}
	if (RunTimer == 40 * THOU) // 40초 : 1번 2번 같이 생성
	{
		AppearType1();
		AppearType2();
	}
	if (RunTimer == 45 * THOU) // 50초 : 중간 2 생성 -> 위 아래 
	{
		Monster* midAirPlan = new MidAirPlan(GAMEPOS::G_LEFT3);
		midAirPlan->Init(TEXT("MidAirPlan"), 1, MonsterType::MiddleType2, GAMEPOS::G_RIGHT3);

		monsterList.push_back(midAirPlan);

		int width = 0;
		std::list<Monster*>::iterator it;
		for (it = monsterList.begin(); it != monsterList.end(); it++)
		{
			if ((*it)->GetType() == MonsterType::MiddleType2)
			{
				width = (*it)->GetImage()->GetFrameWidth();
				(*it)->OffectX(width);
			}
		}
	}

	//=============================== 1분 ~ 1분30초 ===================================

	if (RunTimer == 50 * THOU) // 1분 : 중간 크기 2마리
	{
		Monster* bigAirPlan1 = new BigAirPlan(GAMEPOS::G_UPDOWN);
		bigAirPlan1->Init(TEXT("BigAirPlan"),2, MonsterType::MiddleType1, GAMEPOS::G_RIGHT1);

		monsterList.push_back(bigAirPlan1);

		Monster* bigAirPlan2 = new BigAirPlan(GAMEPOS::G_UPDOWN);
		bigAirPlan2->Init(TEXT("BigAirPlan"),2, MonsterType::MiddleType1, GAMEPOS::G_RIGHT2);

		monsterList.push_back(bigAirPlan2);


		int width = 0;
		std::list<Monster*>::iterator it;
		for (it = monsterList.begin(); it != monsterList.end(); it++)
		{
			if ((*it)->GetType() == MonsterType::MiddleType1)
			{
				width = (*it)->GetImage()->GetFrameWidth();
				(*it)->OffectX(width);
			}
		}
	}
	if (RunTimer == 55 * THOU) // 1분 5초 : 1번 2번 같이 생성
	{
		AppearType1();
		AppearType2();	
	}
	if (RunTimer == 65 * THOU) // 1분 15초 : 중간3 2마리 양쪽 사이드 생성 
	{
		Monster* fish1 = new Fish(GAMEPOS::G_LEFT3);
		fish1->Init(TEXT("fish"), 1, MonsterType::MiddleType3, GAMEPOS::G_RIGHT3);

		monsterList.push_back(fish1);

		Monster* fish2 = new Fish(GAMEPOS::G_RIGHT3);
		fish2->Init(TEXT("fish"), 2, MonsterType::MiddleType3, GAMEPOS::G_LEFT3);

		monsterList.push_back(fish2);


		int width = 0;
		std::list<Monster*>::iterator it;
		for (it = monsterList.begin(); it != monsterList.end(); it++)
		{
			if ((*it)->GetType() == MonsterType::MiddleType3)
			{
				width = (*it)->GetImage()->GetFrameWidth();
				(*it)->OffectX(width);
			}
		}
	}

	//========================== 1분 30초! ( 보스 등장 ) ==============================
	
	//GAMESYS->DeleteObject(monsterList); // 지우는함수 부분

	if (RunTimer == 80 * THOU) // 1분 20초 : 보스 
	{
		
	}


	
	std::list<Monster*>::iterator it;

	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Update();
	}

	GAMESYS->CollisionObject(monsterList);
	//monster1->Update();
	//monster2->Update();

	//player->Update();
	//boss->Update();
	//GAMESYS->CollisionCharacter(_monster, rcTest);
}

void GameScene::Render(HDC hdc)
{
	//GameNode::Render(hdc);

	//HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	
	TIMEMANAGER->Render(hdc);

	// 플레이어
	player->Render(hdc);

	// 몬스터
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Render(hdc);
	}


	//monster1->Render(hdc);
	//monster2->Render(hdc);

	//player->Render(hdc);
	//boss->Render(hdc);

	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	
	//=========================================================

	//this->GetBackBuffer()->Render(hdc, 0, 0);
}

void GameScene::AppearType1()
{
	for (int i = 0; i < 5; i++)
	{
		Monster* monster1 = new AirMonster(GAMEPOS::G_LEFT1);
		monster1->Init(TEXT("air_Monster"), 1, MonsterType::Type1, GAMEPOS::G_RIGHT3);

		monsterList.push_back(monster1);
	}

	int offset = 100;
	int width = 0;
	int height = 0;
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		if ((*it)->GetType() == MonsterType::Type1)
		{
			width = (*it)->GetImage()->GetFrameWidth();
			(*it)->OffectX(width + offset);
			offset += 50;
		}
	}
}

void GameScene::AppearType2()
{
	for (int i = 0; i < 5; i++)
	{
		Monster* monster2 = new AirMonster(GAMEPOS::G_RIGHT1);
		monster2->Init(TEXT("air_Monster"), 2, MonsterType::Type2, GAMEPOS::G_LEFT3);

		monsterList.push_back(monster2);
	}

	int offset = 100;
	int width = 0;
	int height = 0;
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		if ((*it)->GetType() == MonsterType::Type2)
		{
			width = (*it)->GetImage()->GetFrameWidth();
			(*it)->OffectX(width + offset);
			offset += 50;
		}
	}
}