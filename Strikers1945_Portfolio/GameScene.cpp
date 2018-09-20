#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

#include "Monster.h"
#include "Timer.h"
#include "Boss.h"
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
	
	// �ð�
	RunTimer = 0;
	startTimer = GetTickCount(); // ��ü ���۽ð�

	// �÷��̾�
	player = new Player;
	GAMESYS->SetPlayer(player);

	// ����



	//
	//monster1 = new Monster;
	//monster1->Init(MONSTER_TYPE_NONE, 0, 100);

	//monster2 = new Monster;
	//monster2->Init(MONSTER_TYPE_NONE, WINSIZEX, 100);
	//player = new Player;
	//GAMESYS->SetPlayer(player);
	
	boss = new Boss();
	boss->Init();
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

	// �ð�
	RunTimer = GetTickCount() - startTimer; // ��ü�ð�

	// �÷��̾�
	player->Update();

// �׽�Ʈ
	if (RunTimer == 5 * THOU) // 30�� : 1�� ���� -> ������ �� [ 1]
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2, 100);
		monsterList.push_back(monster1);
	}
//
	// ����
	//=============================== 30�� ~ 1�� ===================================

	if (RunTimer == 30 * THOU) // 30�� : 1�� ���� -> ������ �� [ 1]
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2, 100);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 32 * THOU) // 32�� :  ������ -> ���� �� [2] 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 100);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 35 * THOU) // 35�� : �� -> �Ʒ� �߽����� �̵� (�߰� ĳ���� ) 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 500);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 40 * THOU) // 40�� : 1�� 2�� ���� ����
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 50 * THOU) // 50�� : �߰� 2 ���� -> �� �Ʒ� 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}

	//=============================== 1�� ~ 1��30�� ===================================

	if (RunTimer == 60 * THOU) // 1�� : �߰� ũ�� 2���� 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 65 * THOU) // 1�� 5�� : 1�� 2�� ���� ����
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}
	if (RunTimer == 75 * THOU) // 1�� 15�� : �߰�3 2���� ���� ���̵� ���� 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}

	//========================== 1�� 30��! ( ���� ���� ) ==============================

	if (RunTimer == 90 * THOU) // 1�� 30�� : ���� 
	{
		Monster* monster1 = new Monster();
		monster1->Init(MONSTER_TYPE_NONE, WINSIZEX / 2 - 200, 200);
		monsterList.push_back(monster1);
	}













	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
			(*it)->Update();
	}

	//monster1->Update();
	//monster2->Update();

	//player->Update();
	boss->Update();
	//GAMESYS->CollisionCharacter(_monster, rcTest);
	
}

void GameScene::Render(HDC hdc)
{
	//GameNode::Render(hdc);

	//HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	
	TIMEMANAGER->Render(hdc);

	// �÷��̾�
	player->Render(hdc);

	// ����
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Render(hdc);
	}
	//monster1->Render(hdc);
	//monster2->Render(hdc);




	//player->Render(hdc);
	boss->Render(hdc);

	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	
	//=========================================================

	//this->GetBackBuffer()->Render(hdc, 0, 0);
}
