#include "stdafx.h"
#include "MainGame.h"
#include "SceneManager.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}


bool MainGame::Init() // 초기화
{
	GameNode::Init(true);
	SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_TITLE);

	return true;
}

void MainGame::Release() // 해제
{
	GameNode::Release();
	
}

void MainGame::Update() // 변동
{
	//GameNode::Update();
	//============================
	GameNode::Update();
	SceneManager::getSingleton()->Update();


}

void MainGame::Render(HDC hdc) 
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	SceneManager::getSingleton()->Render(backDC);
	this->GetBackBuffer()->Render(hdc, 0, 0);
}

