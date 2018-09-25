#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

#include "Monster.h"
#include "Timer.h"
#include "Boss.h"
#include "AirMonster.h"
#pragma comment (lib,"winmm")

GameScene::GameScene()
{
	sceneType = eSceneType::SCENE_TEST1;
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
	player = new Player;
	GAMESYS->SetPlayer(player);

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
	if (RunTimer == 2 * THOU) // 30초 : 1번 왼쪽 -> 오른쪽 위 [ 1]
	{
		for (int i = 0; i < 10; i++)
		{
			Monster* monster1 = new AirMonster(GAMEPOS::G_LEFT1);
			//monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2, 100);
			//monster1->Init(TEXT("air_Monster1"));
			monster1->Init(TEXT("air_Monster"), 1, GAMEPOS::G_RIGHT1);

			monsterList.push_back(monster1);
		}

		//
		int offset = 100;
		int width = 0;
		int height = 0;
		std::list<Monster*>::iterator it;
		for (it = monsterList.begin(); it != monsterList.end(); it++)
		{
			width = (*it)->GetImage()->GetFrameWidth();
			(*it)->OffectX(width + offset);
			offset += 50;
		}
		
	}
//
	// 몬스터
	//=============================== 30초 ~ 1분 ===================================

	if (RunTimer == 30 * THOU) // 30초 : 1번 왼쪽 -> 오른쪽 위 [ 1]
	{
	
	}
	if (RunTimer == 32 * THOU) // 32초 :  오른쪽 -> 왼쪽 위 [2] 
	{
		
	}
	if (RunTimer == 35 * THOU) // 35초 : 위 -> 아래 중심으로 이동 (중간 캐릭터 ) 
	{
		
	}
	if (RunTimer == 40 * THOU) // 40초 : 1번 2번 같이 생성
	{
		
	}
	if (RunTimer == 50 * THOU) // 50초 : 중간 2 생성 -> 위 아래 
	{

	}

	//=============================== 1분 ~ 1분30초 ===================================

	if (RunTimer == 60 * THOU) // 1분 : 중간 크기 2마리 
	{
	
	}
	if (RunTimer == 65 * THOU) // 1분 5초 : 1번 2번 같이 생성
	{
	
	}
	if (RunTimer == 75 * THOU) // 1분 15초 : 중간3 2마리 양쪽 사이드 생성 
	{
	
	}

	//========================== 1분 30초! ( 보스 등장 ) ==============================

	if (RunTimer == 90 * THOU) // 1분 30초 : 보스 
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
