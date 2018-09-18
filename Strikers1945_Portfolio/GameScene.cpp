#include "stdafx.h"
#include "GameScene.h"
//#include "Player.h"
#include "Monster.h"

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
<<<<<<< master
	_monster = new Monster();
	_monster->Init(eMonsterType::MONSTER_TYPE_NONE);
=======
	// GAMESYS->SetPlayer(player);
	_monster = new Monster();
	_monster->Init(eMonsterType::MONSTER_TYPE_NONE,WINSIZEX/ 2, 100	);

	//rcTest = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

>>>>>>> local
	//=========================================================

<<<<<<< master
=======
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
>>>>>>> local

	return true;
}

void GameScene::Release()
{
	MainGame::Release();
	//=========================================================

//	SAFE_DELETE(player);

	//=========================================================

}

void GameScene::Update()
{
	MainGame::Update();
	//=========================================================
	//player->Update();
	_monster->Update();
<<<<<<< master
=======
	//GAMESYS->CollisionCharacter(_monster, rcTest);
	std::list<Monster*>::iterator it;

	for (it = _monsterList.begin(); it != _monsterList.end(); it++)
	{
		//(*it)->Update();
	}
	//=========================================================
>>>>>>> local
	//=========================================================

}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	//player->Render(backDC);
	_monster->Render(backDC);
<<<<<<< master
=======
	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	std::list<Monster*>::iterator it;

	for (it = _monsterList.begin(); it != _monsterList.end(); it++)
	{
		//(*it)->Render(backDC);
	}
>>>>>>> local
	//=========================================================

	this->GetBackBuffer()->Render(hdc, 0, 0);
}
