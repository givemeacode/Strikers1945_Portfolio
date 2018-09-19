#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

#include "Monster.h"

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
	player = new Player;
	GAMESYS->SetPlayer(player);
	
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
	player->Update();
	//GAMESYS->CollisionCharacter(_monster, rcTest);
	
}

void GameScene::Render(HDC hdc)
{
	//GameNode::Render(hdc);

	//HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=========================================================
	player->Render(hdc);
	//Rectangle(backDC, rcTest.left, rcTest.top, rcTest.right, rcTest.bottom);
	//=========================================================
	
	//=========================================================

	//this->GetBackBuffer()->Render(hdc, 0, 0);
}
