#include "stdafx.h"
#include "GameScene.h"

#include "Monster.h"

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
	_backGround = new Image();
	_backGround->Init(TEXT("../Resource/Image/StageBack/Stage_1_1.bmp"),
		100.0f, (-18165.f + static_cast<float>(WINSIZEY)), 800, 18165);
	_y = _backGround->GetY();

	_monster = new Monster();
	_monster->Init();
	//=========================================================
	_startTime = GetTickCount();
	_daltaTime = 0.0f;
	_currentTime = 0.0f;
	_temp = 1.0f;

	rcClient.left = 100.0f;
	rcClient.right = 900.0f;
	rcClient.top = 0.f;
	rcClient.bottom = static_cast<float>(WINSIZEY);
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
	_y += 3.f;
	_backGround->SetY(_y);
	_currentTime = GetTickCount();
	_daltaTime = (_currentTime - _startTime) / 1000.f;
	if (_daltaTime < 1.0f)
	{
		_temp += 1.0f;
		_startTime = GetTickCount();
	}

	_monster->Update();
	//=========================================================

}

void GameScene::Render(HDC hdc)
{
	HDC	backDC = (this->GetBackBuffer())->GetMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//=========================================================
	_backGround->Render(backDC);
	//_backGround->LoopRender(backDC, &rcClient, 0, _y);  //

	TCHAR szTemp[100] = { 0, };

	_stprintf_s(szTemp, sizeof(szTemp), TEXT("TIMER : %3.f"), _temp);
	TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, TEXT(szTemp), _tcslen((szTemp)));
	//=========================================================

	_monster->Render(hdc);
	this->GetBackBuffer()->Render(hdc, 0, 0);
}
