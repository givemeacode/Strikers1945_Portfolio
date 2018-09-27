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
#include "UI.h"

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
	GAMESYS->SetScore(0);

	// �ð�
	RunTimer = 0;
	startTimer = GetTickCount(); // ��ü ���۽ð�
	backImg = IMAGEMANAGER->FindImage("Stage_1");
	backImg->SetX(100.f);
	backImg->SetY((-18165.f + static_cast<float>(WINSIZEY)));
	_y = backImg->GetY();

	rcGameClient.left = 100.0f;
	rcGameClient.right = 900.0f;
	rcGameClient.top = 0.f;
	rcGameClient.bottom = static_cast<float>(WINSIZEY);

	ui = new UI();
	ui->Init();
	// �÷��̾�
	//player = new Player;
	//GAMESYS->SetPlayer(player);
	player = GAMESYS->GetPlayer();
	// ����


	//
	//monster1 = new Monster;
	//monster1->Init(MONSTER_TYPE_NONE, 0, 100);

	//monster2 = new Monster;
	//monster2->Init(MONSTER_TYPE_NONE, WINSIZEX, 100);
	//player = new Player;
	//GAMESYS->SetPlayer(player);
	
	//boss = new Boss();
	//boss->Init();

	//=========================
	leftRect = RectMake(0, 0, 100, WINSIZEY);
	rightRect = RectMake(900, 0, 100, WINSIZEY);

	//=========================

	return true;
}

void GameScene::Release()
{
	//GameNode::Release();
	//=========================================================
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Release();
	}
	monsterList.clear();
	backImg->Release();
	player->Release();
	SAFE_DELETE(player);
	SAFE_DELETE(boss);
	//=========================================================
	//=========================================================

}

void GameScene::Update()
{
	ui->Update();
	// BackGround
	_y -= 2.f;
	backImg->SetY(_y);

	//
	//GameNode::Update();
	//=========================================================
	// �ð�
	RunTimer = GetTickCount() - startTimer; // ��ü�ð�

	// �÷��̾�
	player->Update();

	if (GAMESYS->IsGameClear())
	{
		if (player->GetY() <= 0)
		{
			SCENEMANAGER->ChangeScene(eSceneType::SCENE_CLEAR);
			GAMESYS->SetIsGameClear(false);
			return;
		}
	}

// �׽�Ʈ
	if(GAMESYS->IsGameOver())
	{
		RunTimer = 0;
		startTimer = GetTickCount();
		GAMESYS->SetIsGameOver(false);
		return;
	}
	if (RunTimer % 2000 == 500  && RunTimer < 60 * THOU) // 2�ʸ��� ���� 60�� �������� ������ ��ġ���� ����
	{
		int iRand = RAND->getInt(6); // 0~5�� ���� �����ϰ� ������
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
		
	// ����
	//=============================== 30�� ~ 1�� ===================================

	if (RunTimer == 20 * THOU) // 30�� : 1�� ���� -> ������ �� [ 1]
	{
		AppearType1();
	}
	if (RunTimer == 25 * THOU) // 32�� :  ������ -> ���� �� [2] 
	{
		AppearType2();
	}
	if (RunTimer == 5 * THOU) // 35�� : �� -> �Ʒ� �߽����� �̵� (�߰� ĳ���� ) 
	{
		Monster* bigAirPlan = new BigAirPlan(GAMEPOS::G_UPDOWN1); 
		bigAirPlan->Init(TEXT("BigAirPlan"), 1, MonsterType::MiddleType1, GAMEPOS::G_CENTER1);

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
	if (RunTimer == 40 * THOU) // 40�� : 1�� 2�� ���� ����
	{
		AppearType1();
		AppearType2();
	}
	if (RunTimer == 45 * THOU) // 50�� : �߰� 2 ���� -> �� �Ʒ� 
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

	//=============================== 1�� ~ 1��30�� ===================================

	if (RunTimer == 50 * THOU) // 1�� : �߰� ũ�� 2����
	{
		Monster* bigAirPlan1 = new BigAirPlan(GAMEPOS::G_UPDOWN1);
		bigAirPlan1->Init(TEXT("BigAirPlan"),2, MonsterType::MiddleType1, GAMEPOS::G_CENTER1);

		monsterList.push_back(bigAirPlan1);

		Monster* bigAirPlan2 = new BigAirPlan(GAMEPOS::G_UPDOWN2);
 		bigAirPlan2->Init(TEXT("BigAirPlan"),2, MonsterType::MiddleType1, GAMEPOS::G_CENTER2);

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
	if (RunTimer == 55 * THOU) // 1�� 5�� : 1�� 2�� ���� ����
	{
		AppearType1();
		AppearType2();	
	}
	if (RunTimer == 65 * THOU) // 1�� 15�� : �߰�3 2���� ���� ���̵� ���� 
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

	//========================== 1�� 30��! ( ���� ���� ) ==============================
	
	//GAMESYS->DeleteObject(monsterList); // ������Լ� �κ�
	//80
	if (RunTimer == 80 * THOU) // 1�� 20�� : ���� 
	{
		boss = new Boss();
		boss->Init(WINSIZEX /2 , -500);
		GAMESYS->SetBoss(boss);

	}
	if (RunTimer >= 90 * THOU)
	{
		GAMESYS->DeleteObject(monsterList);
		if (!boss->GetIsLive())
		{
			GAMESYS->SetIsGameClear(true);
			//boss->Release();
			//SAFE_DELETE(boss);
		}
	}
	
	
	std::list<Monster*>::iterator it;

	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Update();
	}

	if (NULL != boss)
	{
		boss->Update();
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
	
	backImg->LoopRender(hdc, &rcGameClient, 0, _y);

	ui->Render(hdc);
	TIMEMANAGER->Render(hdc);


	// �÷��̾�

	// ����
	std::list<Monster*>::iterator it;
	for (it = monsterList.begin(); it != monsterList.end(); it++)
	{
		(*it)->Render(hdc);
	}
	DrawObject(hdc, leftRect, 1, RGB(0, 0, 0), RECTANGLE);
	DrawObject(hdc, rightRect, 1, RGB(0, 0, 0), RECTANGLE);

	if (NULL != boss)
	{
		boss->Render(hdc);
	}
	player->Render(hdc);


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