#include "stdafx.h"
#include "GameScene.h"
//#include "Player.h"
#include "Monster.h"

#pragma comment (lib,"winmm")

GameScene::GameScene()
{
}


GameScene::~GameScene()
{

}

bool GameScene::Init()
{
	MainGame::Init();
	//=========================================================
//	player = new Player;
	// GAMESYS->SetPlayer(player);
	_monster = new Monster();
	_monster->Init(eMonsterType::MONSTER_TYPE_NONE, WINSIZEX / 2, 100);

	//rcTest = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

	//=========================================================
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	//=========================================================
	{
		// Stage1
		//_monster1 = new Monster();
		//_monster1->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 100);
		//_monsterList.push_back(_monster1);

		//_monster2 = new Monster();
		//_monster2->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 200);
		//_monsterList.push_back(_monster2);

		//_monster3 = new Monster();
		//_monster3->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 300);
		//_monsterList.push_back(_monster3);

		//_monster4 = new Monster();
		//_monster4->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 400);
		//_monsterList.push_back(_monster4);

		//_monster5 = new Monster();
		//_monster5->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 500);
		//_monsterList.push_back(_monster5);

		//_monster6 = new Monster();
		//_monster6->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 600);
		//_monsterList.push_back(_monster6);

		//_monster7 = new Monster();
		//_monster7->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 700);
		//_monsterList.push_back(_monster7);

		//_monster8 = new Monster();
		//_monster8->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 800);
		//_monsterList.push_back(_monster8);

		//_monster9 = new Monster();
		//_monster9->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 900);
		//_monsterList.push_back(_monster9);

		//_monster10 = new Monster();
		//_monster10->Init(eMonsterType::MONSTER_TYPE_NONE, 0, 1000);
		//_monsterList.push_back(_monster10);


	}

	{
		// Stage2
		for (int i = 0; i < 100; i++)
		{
			//Monster* monster = new Monster();
			//monster->Init(eMonsterType::MONSTER_TYPE_NONE, WINSIZEX / 2, 500);
			//_monsterList.push_back(monster);
		}
	}

	{
		// Stage3

	}
	//=========================================================

	return true;
}

void GameScene::Release()
{
	MainGame::Release();
	//=========================================================

//	SAFE_DELETE(player);

	//=========================================================
	//=========================================================

}

void GameScene::Update()
{
	MainGame::Update();
	//=========================================================
	//player->Update();
	_monster->Update();
	//GAMESYS->CollisionCharacter(_monster, rcTest);
	std::list<Monster*>::iterator it;

	for (it = _monsterList.begin(); it != _monsterList.end(); it++)
	{
		//(*it)->Update();
	}
	//=========================================================
	//=========================================================

}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	//player->Render(backDC);
	_monster->Render(backDC);
	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	std::list<Monster*>::iterator it;

	for (it = _monsterList.begin(); it != _monsterList.end(); it++)
	{
		//(*it)->Render(backDC);
	}
	//=========================================================

	this->GetBackBuffer()->Render(hdc, 0, 0);
}
