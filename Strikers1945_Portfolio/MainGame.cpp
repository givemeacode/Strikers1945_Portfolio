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
	GameNode::Init();
	SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_TEST1);

	

	return true;
}

void MainGame::Release() // 해제
{
	GameNode::Release();
	
}

void MainGame::Update() // 변동
{
	GameNode::Update();
	SceneManager::getSingleton()->Update();

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_TEST2);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_TEST1);
	}

}

void MainGame::Render(HDC hdc) 
{
	//GameNode::Render(hdc);
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	SceneManager::getSingleton()->Render(backDC);
	this->GetBackBuffer()->Render(hdc, 0, 0);

}

