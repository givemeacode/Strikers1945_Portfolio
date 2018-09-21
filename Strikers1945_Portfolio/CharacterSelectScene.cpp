#include "stdafx.h"
#include "CharacterSelectScene.h"

// ============== ������, �Ҹ��� ======================
CharacterSelectScene::CharacterSelectScene()
{
}

CharacterSelectScene::~CharacterSelectScene()
{
}
//===================================================
bool CharacterSelectScene::Init()
{
	// ĳ���ͼ��� ��üȭ�� �̹���
	CharacterSelectImage = new Image;
	CharacterSelectImage->Init(TEXT("../Resource/Image/logo/character.bmp"), 4800, 900, 6, 1, true, RGB(0, 0, 0));
	CharacterSelectImage->SetX(100); // set�� ȭ�鿡�� �׷��� ������ ��ġ x��, y��.
	CharacterSelectImage->SetY(0);
	
	// �ϴ��� ����ī��Ʈ
	redTimerImage = new Image;
	redTimerImage->Init(TEXT("../Resource/Image/logo/RedNumber.bmp"), 241, 37, 10, 1, true, RGB(255, 255, 255));
	redTimerImage->SetX(550); // set�� ȭ�鿡�� �׷��� ������ ��ġ x��, y��.
	redTimerImage->SetY(WINSIZEY - 50);

	characterSelectIndex = 0;

	// �ð�üũ
	runTimer = 0;
	startTimer = GetTickCount(); // ��ü ���۽ð�
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
		if (choiceTime > 0) //  9 - (runTimer / 1000) ���� ...  0�̵Ǹ� ���ýð��� ����� ��.
		{
			runTimer = GetTickCount() - startTimer; // ��ü�ð�
		}
	}


	// ���� Ű - Left, Right
	ChoiceKey();

	// ���� Ű - Enter && �־����ð� �ٵǼ� �ڵ�����
	SelectKeyAndTimeOver();

	CharacterSelectImage->SetFrameX(characterSelectIndex); // CharacterSelectIndex��� ������ ����ؼ� ���° ��ü�� ������ �˷���.	
	
	redTimerIndex = choiceTime;
	redTimerImage->SetFrameX(redTimerIndex); // CharacterSelectIndex��� ������ ����ؼ� ���° ��ü�� ������ �˷���.	

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

	// ���ýð�.. 9�ʺ��� 0�ʱ���... 0�ʰ��Ǹ� ���� ��ġ�ϴ� �ε��������� �ڵ� ����.
	TCHAR tempChoiceTime[100] = { 0, };
	_stprintf_s(tempChoiceTime, sizeof(tempChoiceTime), TEXT("ChoiceTime : %d"), choiceTime);
	TextOut(hdc, WINSIZEX / 2 - 270, 150, TEXT(tempChoiceTime), _tcslen(TEXT(tempChoiceTime)));

	TCHAR choiceTime1[100] = { 0, };
	_stprintf_s(choiceTime1, sizeof(choiceTime1), TEXT("runTimer : %d"), runTimer);
	TextOut(hdc, WINSIZEX / 2 - 270, 180, TEXT(choiceTime1), _tcslen(TEXT(choiceTime1)));

	TCHAR playerName[100] = { 0, };
	_stprintf_s(playerName, sizeof(playerName), TEXT("���õ� ��ü : %d"), GetSelect());
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


		// ���� �ѱ��
		choiceTime = 0;
		SetSelect(characterSelectIndex);

	}
}

