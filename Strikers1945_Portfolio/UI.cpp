#include "stdafx.h"
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
	// 테스트용.. 숫자가 증가하는지
	score++;


	// 스코어에 따라서 글자 프레임을 결정하는... scoreIndex 값을 구해주는 함수.
	ScoreFunc(score);

	//scoreImage->SetFrameY(score);
	//scoreImage10->SetFrameY(score10);
	//scoreImage100->SetFrameY(score100);
	//scoreImage1000->SetFrameY(score1000);
	//scoreImage10000->SetFrameY(score10000);
}

void UI::Render(HDC hdc)
{
	//scoreImage->FrameRender(hdc, scoreImage->GetX(), scoreImage->GetY(),
	//	scoreImage->GetFrameX(), scoreImage->GetFrameY());

	//scoreImage10->FrameRender(hdc, scoreImage10->GetX()+50, scoreImage10->GetY(),
	//	scoreImage10->GetFrameX(), scoreImage10->GetFrameY());

	//scoreImage100->FrameRender(hdc, scoreImage100->GetX() + 100, scoreImage100->GetY(),
	//	scoreImage100->GetFrameX(), scoreImage100->GetFrameY());

	//scoreImage1000->FrameRender(hdc, scoreImage1000->GetX() + 150, scoreImage1000->GetY(),
	//	scoreImage1000->GetFrameX(), scoreImage1000->GetFrameY());

	//scoreImage10000->FrameRender(hdc, scoreImage10000->GetX() + 200, scoreImage10000->GetY(),
	//	scoreImage10000->GetFrameX(), scoreImage10000->GetFrameY());

	scoreImage->FrameRender(hdc, 500, 100,
		scoreImage->GetFrameX(), scoreIndex);

	scoreImage10->FrameRender(hdc, 450, 100,
		scoreImage10->GetFrameX(), scoreIndex10);

	scoreImage100->FrameRender(hdc, 400, 100,
		scoreImage100->GetFrameX(), scoreIndex100);

	scoreImage1000->FrameRender(hdc, 350, 100,
		scoreImage1000->GetFrameX(), scoreIndex1000);

	scoreImage10000->FrameRender(hdc, 300, 100,
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
		scoreIndex10 = (_score % 100 - scoreIndex)/10;
	}
	else if (_score >= 100 && _score < 1000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex)/10;
		scoreIndex100 = (_score % 1000 - scoreIndex10)/100;
	}
	else if (_score >= 1000 && _score < 10000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex)/10;
		scoreIndex100 = (_score % 1000 - scoreIndex10)/100;
		scoreIndex1000 = (_score % 10000 - scoreIndex100)/1000;
	}
	else if (_score >= 10000 && _score < 100000)
	{
		scoreIndex = _score % 10;
		scoreIndex10 = (_score % 100 - scoreIndex)/10;
		scoreIndex100 = (_score % 1000 - scoreIndex10)/100;
		scoreIndex1000 = (_score % 10000 - scoreIndex100)/1000;
		scoreIndex10000 = (_score % 100000 - scoreIndex1000)/10000;
	}
	//===============================================================================
	//else if (_score >= 100000) // 10만이 최대. 10만이 넘어가면 000000으로 표시
	//{
	//	score = 0;
	//	score10 = 0;
	//	score100 = 0;
	//	score1000 = 0;
	//	score10000 = 0;
	//}
}
