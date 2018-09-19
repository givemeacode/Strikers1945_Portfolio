#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

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
	player = new Player;
	GAMESYS->SetPlayer(player);
	
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
	player->Update();
	//GAMESYS->CollisionCharacter(_monster, rcTest);
	
}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	player->Render(backDC);
	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	
	//=========================================================

	this->GetBackBuffer()->Render(hdc, 0, 0);
}
