#include "stdafx.h"
#include "CharacterSelectScene.h"

// ============== 생성자, 소멸자 ======================
CharacterSelectScene::CharacterSelectScene()
{
}

CharacterSelectScene::~CharacterSelectScene()
{
}
//===================================================
bool CharacterSelectScene::Init()
{
	// 캐릭터선택 전체화면 이미지
	CharacterSelectImage = new Image;
	CharacterSelectImage->Init(TEXT("../Resource/Image/logo/character.bmp"), 4800, 900, 6, 1, true, RGB(0, 0, 0));
	CharacterSelectImage->SetX(100); // set은 화면에서 그려기 시작할 위치 x값, y값.
	CharacterSelectImage->SetY(0);
	
	// 하단의 레드카운트
	redTimerImage = new Image;
	redTimerImage->Init(TEXT("../Resource/Image/logo/RedNumber.bmp"), 241, 37, 10, 1, true, RGB(255, 255, 255));
	redTimerImage->SetX(550); // set은 화면에서 그려기 시작할 위치 x값, y값.
	redTimerImage->SetY(WINSIZEY - 50);

	characterSelectIndex = 0;

	// 시간체크
	runTimer = 0;
	startTimer = GetTickCount(); // 전체 시작시간
	choiceTime = 9;

	//
	isChoice = true;

	return true;
}

void CharacterSelectScene::Release()
{
	SAFE_DELETE(CharacterSelectImage);
}

void CharacterSelectScene::Update()
{
	if (isChoice)
	{
		choiceTime = 9 - (runTimer / 1000);
		if (choiceTime > 0) //  9 - (runTimer / 1000) 값이 ...  0이되면 선택시간이 종료된 것.
		{
			runTimer = GetTickCount() - startTimer; // 전체시간
		}
	}


	// 고르는 키 - Left, Right
	ChoiceKey();

	// 결정 키 - Enter && 주어진시간 다되서 자동선택
	SelectKeyAndTimeOver();

	CharacterSelectImage->SetFrameX(characterSelectIndex); // CharacterSelectIndex라는 변수를 사용해서 몇번째 기체를 고르는지 알려줌.	
	
	redTimerIndex = choiceTime;
	redTimerImage->SetFrameX(redTimerIndex); // CharacterSelectIndex라는 변수를 사용해서 몇번째 기체를 고르는지 알려줌.	

}

void CharacterSelectScene::Render(HDC hdc)
{
	CharacterSelectImage->FrameRender(hdc, CharacterSelectImage->GetX(), CharacterSelectImage->GetY(),
		CharacterSelectImage->GetFrameX(), CharacterSelectImage->GetFrameY());

	redTimerImage->FrameRender(hdc, redTimerImage->GetX(), redTimerImage->GetY(),
		redTimerImage->GetFrameX(), redTimerImage->GetFrameY());


	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("Selected Player : %d"), characterSelectIndex + 1);
	TextOut(hdc, WINSIZEX / 2 - 270, 120, TEXT(szTemp), _tcslen(TEXT(szTemp)));

	// 선택시간.. 9초부터 0초까지... 0초가되면 현재 위치하는 인덱스값으로 자동 결정.
	TCHAR tempChoiceTime[100] = { 0, };
	_stprintf_s(tempChoiceTime, sizeof(tempChoiceTime), TEXT("ChoiceTime : %d"), choiceTime);
	TextOut(hdc, WINSIZEX / 2 - 270, 150, TEXT(tempChoiceTime), _tcslen(TEXT(tempChoiceTime)));

	TCHAR choiceTime1[100] = { 0, };
	_stprintf_s(choiceTime1, sizeof(choiceTime1), TEXT("runTimer : %d"), runTimer);
	TextOut(hdc, WINSIZEX / 2 - 270, 180, TEXT(choiceTime1), _tcslen(TEXT(choiceTime1)));

	TCHAR playerName[100] = { 0, };
	_stprintf_s(playerName, sizeof(playerName), TEXT("선택된 기체 : %d"), GetSelect());
	TextOut(hdc, WINSIZEX / 2 - 270, 210, TEXT(playerName), _tcslen(TEXT(playerName)));

}

void CharacterSelectScene::ChoiceKey()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_LEFT) && characterSelectIndex > 0 && isChoice == true)
	{
		characterSelectIndex--;
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_RIGHT) && characterSelectIndex < 5 && isChoice == true)
	{
		characterSelectIndex++;
	}
}

void CharacterSelectScene::SelectKeyAndTimeOver()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_RETURN) || choiceTime <= 0)
	{
		isChoice = false;


		// 정보 넘기기
		choiceTime = 0;
		SetSelect(characterSelectIndex);

	}
}

