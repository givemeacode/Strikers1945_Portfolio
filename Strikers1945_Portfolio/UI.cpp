#include "stdafx.h"
#include "GameSystem.h"
#include "UI.h"

UI::UI()
{
	scoreImage = new Image;
	scoreImage = IMAGEMANAGER->FindImage(TEXT("Score"));

	scoreImage10 = new Image;
	scoreImage10 = IMAGEMANAGER->FindImage(TEXT("Score"));

	scoreImage100 = new Image;
	scoreImage100 = IMAGEMANAGER->FindImage(TEXT("Score"));

	scoreImage1000 = new Image;
	scoreImage1000 = IMAGEMANAGER->FindImage(TEXT("Score"));

	scoreImage10000 = new Image;
	scoreImage10000 = IMAGEMANAGER->FindImage(TEXT("Score"));

	scoreIndex = 0;
	scoreIndex10 = 0;
	scoreIndex100 = 0;
	scoreIndex1000 = 0;
	scoreIndex10000 = 0;

	score = 0;
}


UI::~UI()
{
}

bool UI::Init()
{
	return true;
}

void UI::Release()
{
}

void UI::Update()
{
	// 스코어에 따라서 글자 프레임을 결정하는... scoreIndex 값을 구해주는 함수.
	if (GAMESYS->GetIsScore())
	{
		ScoreFunc(GAMESYS->GetScore());
		GAMESYS->IsScore(false);
	}
}

void UI::Render(HDC hdc)
{
	scoreImage->FrameRender(hdc, 300, 50,
		scoreImage->GetFrameX(), scoreIndex);

	scoreImage10->FrameRender(hdc, 250, 50,
		scoreImage10->GetFrameX(), scoreIndex10);

	scoreImage100->FrameRender(hdc, 200, 50,
		scoreImage100->GetFrameX(), scoreIndex100);

	scoreImage1000->FrameRender(hdc, 150, 50,
		scoreImage1000->GetFrameX(), scoreIndex1000);

	scoreImage10000->FrameRender(hdc, 100, 50,
		scoreImage10000->GetFrameX(), scoreIndex10000);
}

void UI::ScoreFunc(int _score)
{
	if (_score <= 0)
	{
		scoreIndex = 0;
		scoreIndex10 = 0;
		scoreIndex100 = 0;
		scoreIndex1000 = 0;
		scoreIndex10000 = 0;
	}
	else if (_score > 0 && _score < 10)
	{
		scoreIndex = _score % 10;
	}
	else if (_score >= 10 && _score < 100)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex) / 10;
	}
	else if (_score >= 100 && _score < 1000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex) / 10;
		scoreIndex100 = (_score % 1000 - scoreIndex10) / 100;
	}
	else if (_score >= 1000 && _score < 10000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex) / 10;
		scoreIndex100 = (_score % 1000 - scoreIndex10) / 100;
		scoreIndex1000 = (_score % 10000 - scoreIndex100) / 1000;
	}
	else if (_score >= 10000 && _score < 100000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex) / 10;
		scoreIndex100 = (_score % 1000 - scoreIndex10) / 100;
		scoreIndex1000 = (_score % 10000 - scoreIndex100) / 1000;
		scoreIndex10000 = (_score % 100000 - scoreIndex1000) / 10000;
	}
	//99999가 최대.
}
