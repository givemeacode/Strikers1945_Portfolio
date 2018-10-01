#include "stdafx.h"
#include "GameClear.h"
#include "Backbuffer.h"
#include <conio.h>
GameClear::GameClear()
{
	sceneType = eSceneType::SCENE_CLEAR;
	alpha = 255;
	isPrint = false;
	iCount = 0;
	indexX, indexY = 0;
}


GameClear::~GameClear()
{
	//blackBG->Release();
}
bool GameClear::Init()
{
	blackBG = IMAGEMANAGER->AddImage(TEXT("BlackBG"), TEXT("../Resource/Image/UI/BlackBG.bmp"), WINSIZEX, WINSIZEY,
		false, RGB(0, 0, 0));

	rcText1 = RectMakeCenter(100, 100, 100, 100);
	rcText2 = RectMakeCenter(100, 300, 100, 100);
	rcText3 = RectMakeCenter(500, 300, 100, 100);
	rcText4 = RectMakeCenter(WINSIZEX / 2, 600, 100, 100);



	abcImg1 = IMAGEMANAGER->AddFrameImage(TEXT("ABC1"), TEXT("../Resource/Image/UI/QWE.bmp"), 3380, 158, 26, 1,
		true, RGB(255, 255, 255));
	abcImg2 = IMAGEMANAGER->AddFrameImage(TEXT("ABC2"), TEXT("../Resource/Image/UI/QWE.bmp"), 3380, 158, 26, 1,
		true, RGB(255, 255, 255));
	abcImg3 = IMAGEMANAGER->AddFrameImage(TEXT("ABC3"), TEXT("../Resource/Image/UI/QWE.bmp"), 3380, 158, 26, 1,
		true, RGB(255, 255, 0));

	return true;
}

void GameClear::Update()
{
	alpha -= 1;

	if (alpha <= 0)
	{
		alpha = 0;
		isPrint = true;


	}

	if (isPrint)
	{

		if (KEYMANAGER->IsOnceKeyDown(VK_UP))
		{
			if (!isOne && !isOne && !isThr)
			{
				iIndex1--;
			}
			if (!isTwo && isOne && !isThr)
			{
				iIndex2--;
			}
			if (isTwo && isOne && !isThr)
			{
				iIndex3--;
			}

		}

		if (KEYMANAGER->IsOnceKeyDown(VK_DOWN))
		{
			if (!isOne && !isOne && !isThr)
			{
				iIndex1++;
			}
			if (!isTwo && isOne && !isThr)
			{
				iIndex2++;
			}
			if (isTwo && isOne && !isThr)
			{
				iIndex3++;
			}
		}

		if (iIndex1 <= 0)
		{
			iIndex1 = 0;

		}
		if (iIndex2 <= 0)
		{
			iIndex2 = 0;

		}
		if (iIndex3 <= 0)
		{
			iIndex3 = 0;

		}
		
		if (iIndex1 >= 25)
		{
			iIndex1 = 25;

		}
		if (iIndex2 >= 25)
		{
			iIndex2 = 25;

		}
		if (iIndex3 >= 25)
		{
			iIndex3 = 25;

		}
		


		if (KEYMANAGER->IsOnceKeyDown(VK_RETURN))
		{
			iCount++;
			switch (iCount)
			{
			case 1:
				isOne = true;
				break;
			case 2:
				isTwo = true;
				break;
			case 3:
				isThr = true;
				break;
			}

			if (iCount >= 3)
			{
				isScore = true;
			}
			
		}
		if (isScore)
		{
			if (KEYMANAGER->IsOnceKeyDown('R'))
			{
				SCENEMANAGER->ChangeScene(eSceneType::SCENE_TITLE);
			}
		}
		
			
	}
}

void GameClear::Render(HDC hdc)
{
	blackBG->AlphaRender(hdc, 0, 0, alpha);
	if (isPrint)
	{
		FontObject(hdc, TEXT("이름을 입력 해 주세요 : "), rcText1, 30, RGB(0, 0, 0));
		abcImg1->FrameRender(hdc, 500, 100, iIndex1, 0);
		abcImg2->FrameRender(hdc, 600, 100, iIndex2, 0);
		abcImg3->FrameRender(hdc, 700, 100, iIndex3, 0);

		if (isScore)
		{
			FontObject(hdc, TEXT("나의 점수는 ? : "), rcText2, 30, RGB(0, 0, 0));

			TCHAR score[256] = { 0, };
			int Score = GAMESYS->GetScore();
			wsprintf(score, TEXT("%d"), Score);
			FontObject(hdc, score, rcText3, 30, RGB(225, 25, 25));
			FontObject(hdc, TEXT("재시작 ( R ) "), rcText4, 30, RGB(0, 255, 255));


		}
	}

	///abcImg2->Render(hdc);
	//abcImg3->Render(hdc);



}

void GameClear::Release()
{
}
