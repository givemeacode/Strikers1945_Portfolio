#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}


bool MainGame::Init() // 초기화
{
	GameNode::Init();

	

	return true;
}

void MainGame::Release() // 해제
{
	GameNode::Release();
	
}

void MainGame::Update() // 변동
{
	GameNode::Update();
	

}

void MainGame::Render(HDC hdc) 
{
	
}

