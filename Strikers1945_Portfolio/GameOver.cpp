#include "stdafx.h"
#include "GameOver.h"



GameOver::GameOver()
{
	sceneType = eSceneType::SCENE_END;
	alpha = 0;
	GetClientRect(_hWnd, &rcClient);
	iSelectIndex = 0;
}


GameOver::~GameOver()
{
	backImg1->Release();
	backImg2->Release();

}

bool GameOver::Init()
{
	backImg1 = IMAGEMANAGER->AddImage(TEXT("GameOverBG1"), TEXT("../Resource/Image/UI/CONTINUE1.bmp"), WINSIZEX, WINSIZEY,
		false, RGB(0, 0, 0));
	backImg2 = IMAGEMANAGER->AddImage(TEXT("GameOverBG2"), TEXT("../Resource/Image/UI/CONTINUE2.bmp"), WINSIZEX, WINSIZEY,
		false, RGB(0, 0, 0));


	return true;
}

void GameOver::Update()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_LEFT))
	{
		iSelectIndex--;
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_RIGHT))
	{
		iSelectIndex++;
	}

	//
	if (iSelectIndex < 0)
	{
		iSelectIndex = 0;
	}

	if (iSelectIndex > 1)
	{
		iSelectIndex = 1;
	}

	//
	if (KEYMANAGER->IsOnceKeyDown(VK_RETURN))
	{
		if (isSelect)
		{
			switch (iSelectIndex)
			{
			case 0:
				SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_CHARACTER);
				break;
			case 1:
				PostQuitMessage(0);
				break;
			}
		}
	}


	alpha++;

	//한계수치가 넘을경우 0으로 초기화 한다.
	if (alpha > 255)
	{
		alpha = 255;
		isSelect = true;
	}
}

void GameOver::Render(HDC hdc)
{
	DrawObject(hdc, rcClient, 1, RGB(0, 0, 0), RECTANGLE);
	switch (iSelectIndex)
	{
	case 0:
		backImg1->AlphaRender(hdc, 0, 0, alpha);
		break;
	case 1:
		backImg2->AlphaRender(hdc, 0, 0, alpha);
		break;
	}
}

void GameOver::Release()
{

}
