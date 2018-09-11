#include "stdafx.h"
#include "GameScene.h"

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


	//=========================================================


	return true;
}

void GameScene::Release()
{
	MainGame::Release();
	//=========================================================


	//=========================================================

}

void GameScene::Update()
{
	MainGame::Update();
	//=========================================================


	//=========================================================

}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//=========================================================


	//=========================================================

	this->GetBackBuffer()->Render(hdc, 0, 0);
}
