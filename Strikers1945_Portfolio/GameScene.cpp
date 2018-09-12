#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

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

	//=========================================================


	return true;
}

void GameScene::Release()
{
	MainGame::Release();
	//=========================================================

	SAFE_DELETE(player);

	//=========================================================

}

void GameScene::Update()
{
	MainGame::Update();
	//=========================================================
	player->Update();

	//=========================================================

}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	player->Render(backDC);

	//=========================================================

	this->GetBackBuffer()->Render(hdc, 0, 0);
}
