#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}


bool MainGame::Init() // �ʱ�ȭ
{
	GameNode::Init();

	

	return true;
}

void MainGame::Release() // ����
{
	GameNode::Release();
	
}

void MainGame::Update() // ����
{
	GameNode::Update();
	

}

void MainGame::Render(HDC hdc) 
{
	
}

