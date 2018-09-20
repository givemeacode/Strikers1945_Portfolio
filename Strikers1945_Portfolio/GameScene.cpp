#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

#include "Monster.h"
#include "Timer.h"

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
	

	// 플레이어
	player = new Player;
	GAMESYS->SetPlayer(player);

	fStartTime = GetTickCount();

	deltaTime = 0;
	// 몬스터

	//-------------
	Monster* monster1 = new Monster();
	monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2, 100);
	monsterList.push_back(monster1);

	//
	//monster1 = new Monster;
	//monster1->Init(MONSTER_TYPE_NONE, 0, 100);

	//monster2 = new Monster;
	//monster2->Init(MONSTER_TYPE_NONE, WINSIZEX, 100);
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
	//worldTime = TIMEMANAGER->getWorldTime();
	// 플레이어
	player->Update();
	_currentTime = GetTickCount();
	

	//deltaTime += TIMEMANAGER->getElapsedTime();
	deltaTime = (_currentTime - fStartTime);

	// 몬스터
	if (deltaTime == 1000 )
	{
		
		fStartTime = GetTickCount();
	}
	
	if (worldTime == 5)
	{
		

	}

	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
			(*it)->Update();
	}

	//monster1->Update();
	//monster2->Update();

	//GAMESYS->CollisionCharacter(_monster, rcTest);
	
}

void GameScene::Render(HDC hdc)
{
	//GameNode::Render(hdc);

	//HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	
	// 시간 테스트용 .. 현재 월드 진행 시간 출력
	//TCHAR testGetWorldTime[100] = { 0, };
	//_stprintf_s(testGetWorldTime, sizeof(testGetWorldTime), TEXT("WorldTime : %d"), worldTime);
	//TextOut(hdc, 700, 120, TEXT(testGetWorldTime), _tcslen(TEXT(testGetWorldTime)));
	//

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



	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	
	//=========================================================

	//this->GetBackBuffer()->Render(hdc, 0, 0);
}
