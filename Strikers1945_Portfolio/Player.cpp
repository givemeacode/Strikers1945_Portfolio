#include "stdafx.h"
#include "Player.h"
#include "Gun.h"
#include "PlayerGun.h"

#pragma comment (lib,"winmm")



Player::Player()
{
//	// �÷��̾� ��ġ �ʱⰪ ����.
//	PositionInit();
//
//	isDead = false;
//	isClear = false;
//	radius = 10.f;
//	// �ð�üũ
//	runTimer = GetTickCount();
//	deathTimer = 0; // �׾����� ������ �����ϱ�����.
//	damage = 1.f;
////	deathMotionTime = 0; // �׾����� ��� �������� �ð� ( ���� ��� )
//	responTime = 0.f; // �������ð�
//
//	//// �׽�Ʈ�� ////
//	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);
//
//	//
//	gun = new PlayerGun;
//	gun->Init(endx, endy);
//
//	// �ִϸ��̼�
//	deathEffect = IMAGEMANAGER->FindImage(TEXT("Effect_7"));
//	deathAnimation = new Animation;
//	deathAnimation->Init(deathEffect);
//	deathAnimation->setDefPlayFrame(false, true);
//	deathAnimation->setFPS(5.f); //
	isReset = false;
	isClear = false;
}

Player::~Player()
{
	SAFE_DELETE(playerImage);
	SAFE_DELETE(deathAnimation);
}

void Player::Init()
{
	// �÷��̾� ��ġ �ʱⰪ ����.
	PositionInit();

	isDead = false;
	isClear = false;
	radius = 10.f;
	// �ð�üũ
	runTimer = GetTickCount();
	deathTimer = 0; // �׾����� ������ �����ϱ�����.
	damage = 1.f;
	//	deathMotionTime = 0; // �׾����� ��� �������� �ð� ( ���� ��� )
	responTime = 0.f; // �������ð�

	//// �׽�Ʈ�� ////
	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

	//
	gun = new PlayerGun;
	gun->Init(endx, endy);

	// �ִϸ��̼�
	deathEffect = IMAGEMANAGER->FindImage(TEXT("Effect_7"));
	deathAnimation = new Animation;
	deathAnimation->Init(deathEffect);
	deathAnimation->setDefPlayFrame(false, true);
	deathAnimation->setFPS(5.f); //
}

void Player::Init(std::string fileName)
{
	// �÷��̾� ��ġ �ʱⰪ ����.
	PositionInit(fileName);
	playerInfoFileName = fileName;

	//
	playerLifeCountImage = new Image;
	playerLifeCountImage = IMAGEMANAGER->FindImage(TEXT("AV_8_Player_1"));
	playerLifeCountImage->SetFrameX(3);


	playerLifeCount = 30;

	playerLifeContinueCountTimer = 0;
	playerLifeContinueCount = 9;



	isDead = false;
	isClear = false;
	radius = 10.f;
	// �ð�üũ
	runTimer = GetTickCount();
	deathTimer = 0; // �׾����� ������ �����ϱ�����.
	damage = 1.f;
	//	deathMotionTime = 0; // �׾����� ��� �������� �ð� ( ���� ��� )
	responTime = 0.f; // �������ð�

	//// �׽�Ʈ�� ////
	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

	//
	gun = new PlayerGun;
	gun->Init(endx, endy);

	// �ִϸ��̼�
	deathEffect = IMAGEMANAGER->FindImage(TEXT("Effect_7"));
	deathAnimation = new Animation;
	deathAnimation->Init(deathEffect);
	deathAnimation->setDefPlayFrame(false, true);
	deathAnimation->setFPS(5.f); //
}

void Player::Update()
{
	if (GAMESYS->IsGameClear())
	{
		isClear = true;
		IsClear();
		endingAni->frameUpdate(3.0f);
	}

	RECT temp;
	//if (IntersectRect(&temp, &collisionBox, &target))
	//{
	//	isDead = true;
	//}
	damage = playerLevel;

	score = GAMESYS->GetScore();

	
	if (500 <= score)
	{
		playerLevel = 2;
	}

	if (1000 <= score)
	{
		playerLevel = 3;
	}
	
	

	{
		IsDead(playerInfoFileName);
	}
	IsClear();

	// �̵� ( Ű���� ����Ű )
	MoveKey();

	// �߻� ( �����̽� �� )
	FireKey();
	
	// ====== �׽�Ʈ�� ... D�� ������ �÷��̾��� ��Ʈ ���===============
	if (KEYMANAGER->IsStayKeyDown(0x44))
	{
		check = true;
	}
	if (KEYMANAGER->IsOnceKeyUp(0x44))
	{
		check = false;
	}
	// ====== �÷��̾��� �Ѿ��� ��������ġ�� endx, endy������ �ϱ����� endx, endy�� �������� =========
	endx = x;
	endy = y - (length + 7);

	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32);

	// �ִϸ��̼�
	deathAnimation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);

	if (playerLifeCount != 0)
	{
		playerLifeContinueCountTimerIndex = GetTickCount();
	}
	if (playerLifeCount == 0)
	{
		playerLifeContinueCount = 9 - (playerLifeContinueCountTimer / 1000);
		if (playerLifeCount == 0) //  9 - (runTimer / 1000) ���� ...  0�̵Ǹ� ���ýð��� ����� ��.
		{
			//playerLifeContinueCountTimer = GetTickCount() - playerLifeContinueCountTimerIndex; // ��ü�ð�
			GAMESYS->GameOver();
			return;
		}
	}

	
	/////////// �׽�Ʈ ///////////////////
	//OffsetRect(&target, 0, 5);

}

void Player::Render(HDC hdc)
{
	//�̹���
	if (GAMESYS->IsGameClear())
	{
		endingImage->AniRender(hdc, playerImage->GetX(), playerImage->GetY(),
			endingAni);
	}
	else
	{
		playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
			playerImage->GetFrameX(), playerImage->GetFrameY());
	}
	

	//�ִϸ��̼�
	if (isDead)
	{
		if (responTime < 1000)
		{
			deathEffect->AniRender(hdc, x-64, y-64, deathAnimation); // 64�� �̹��� ������/2
		}
	}
	// ��� ( �׸����� ǥ�� )
	PlayerLifeCountFunc(hdc, playerInfoFileName);

	if (playerLifeCount <= 0)
	{
		TCHAR tempChoiceTime[100] = { 0, };
		_stprintf_s(tempChoiceTime, sizeof(tempChoiceTime), TEXT("Continue : %d"), playerLifeContinueCount);
		TextOut(hdc, WINSIZEX/2, WINSIZEY/2, TEXT(tempChoiceTime), _tcslen(TEXT(tempChoiceTime)));

		if (KEYMANAGER->IsOnceKeyDown(VK_RETURN))
		{
			playerLifeCount = 3;
			PositionInit(playerInfoFileName);
		}
	}

	///////////////        �׽�Ʈ        ///////////////////////////
	if (check) // üũ ��ư�� D
	{
		//����
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

		EllipseMakeCenter(hdc, x, y, PLAYERSIZE, PLAYERSIZE);
		LineMake(hdc, x, y, endx, endy);
	}

	//TCHAR szTemp[100] = { 0, };
	//_stprintf_s(szTemp, sizeof(szTemp), TEXT("runTimer : %d"), runTimer);
	//TextOut(hdc, WINSIZEX / 2 - 270, 120, TEXT(szTemp), _tcslen(TEXT(szTemp)));

	//// ���ýð�.. 9�ʺ��� 0�ʱ���... 0�ʰ��Ǹ� ���� ��ġ�ϴ� �ε��������� �ڵ� ����.
	//TCHAR tempChoiceTime[100] = { 0, };
	//_stprintf_s(tempChoiceTime, sizeof(tempChoiceTime), TEXT("deathTimer : %d"), deathTimer);
	//TextOut(hdc, WINSIZEX / 2 - 270, 150, TEXT(tempChoiceTime), _tcslen(TEXT(tempChoiceTime)));

	//TCHAR playerName[100] = { 0, };
	//_stprintf_s(playerName, sizeof(playerName), TEXT("responTime : %d"), responTime);
	//TextOut(hdc, WINSIZEX / 2 - 270, 210, TEXT(playerName), _tcslen(TEXT(playerName)));

	//	TCHAR choiceTime1[100] = { 0, };
	//	_stprintf_s(choiceTime1, sizeof(choiceTime1), TEXT("deathMotionTime : %d"), deathMotionTime);
	//	TextOut(hdc, WINSIZEX / 2 - 270, 180, TEXT(choiceTime1), _tcslen(TEXT(choiceTime1)));


	//Rectangle(hdc, target.left, target.top, target.right, target.bottom);

	//
	gun->Render(hdc);
}

void Player::Release()
{
	playerImage->Release();
	playerLifeCountImage->Release();
	deathEffect->Release();
	
	gun->Release();
	SAFE_DELETE(gun);
	SAFE_DELETE(playerImage);
	SAFE_DELETE(playerLifeCountImage);
	SAFE_DELETE(deathAnimation);

}

void Player::PositionInit()
{
	playerLevel = 1;
	// �÷��̾� ��ü ( ��Ʈ ) �ʱ�ȭ
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2;
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32�� �̹��� ũ��
	speed = 8.f;

	// �÷��̾� �̹��� �ʱ�ȭ
	//playerImage = new Image;
	//playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage = IMAGEMANAGER->FindImage("Move_LR_A");
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetFrameX(3); // 4��° ���������� �ʱ�ȭ��.
}

void Player::PositionInit(std::string fileName)
{
	playerLevel = 1;
	// �÷��̾� ��ü ( ��Ʈ ) �ʱ�ȭ
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2;
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32�� �̹��� ũ��
	speed = 8.f;

	// �÷��̾� �̹��� �ʱ�ȭ
	//playerImage = new Image;
	//playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage = IMAGEMANAGER->FindImage(fileName);
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetFrameX(3); // 4��° ���������� �ʱ�ȭ��.

	std::string file;
	file = fileName + "_Ending";
	//wsprintf(file, TEXT("%s_Ending"), TEXT(fileName));
	endingImage = IMAGEMANAGER->FindImage(file);

	endingImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	endingImage->SetY(y - playerImage->GetFrameHeight() / 2);

	endingAni = new Animation();
	endingAni->Init(endingImage);
	endingAni->setDefPlayFrame();
	endingAni->setFPS(1.f);

}

void Player::IsDead()
{
	if (!isDead) // ��������� �귯���� Ÿ�̸� ... �׾����� ���ߴ°� �̿��ؼ� �����ð��� üũ�غ���.
	{
		runTimer = GetTickCount();
	}

	if (isDead)
	{
		deathTimer = GetTickCount(); // �׾����� �귯���½ð�.

		if (responTime < 3000) // ��Ÿ��( ��ü )���� ����Ÿ��( ���� �ð� )�� ���� -> �׾��� �ð��̵�.
		{
			responTime = ((deathTimer - runTimer));
			//deathMotionTime = ((deathTimer - runTimer) / 1000);

			if (responTime < 1000)
			{
				deathAnimation->resume();
				// ���ĵǴ� �̹���.. �ִϸ��̼�?
			}
			else if (responTime >= 1000 && responTime < 3000)
			{
				PositionInit(); // �ڸ� �ʱ�ȭ�ϰ�

				y = -(responTime / 20) + WINSIZEY + 50; // ����� ����Ѱ�. responTomer 3000~4999
				playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
			}
		}
		else
		{
			responTime = 0;
			isDead = false;					// �������ð��� �Ǹ� isDead( ���� )�� false�� �Ǽ� �������� ����.
		}
	}
}

void Player::IsDead(std::string fileName)
{
	if (!isDead) // ��������� �귯���� Ÿ�̸� ... �׾����� ���ߴ°� �̿��ؼ� �����ð��� üũ�غ���.
	{
		runTimer = GetTickCount();
	}

	if (isDead)
	{

		deathTimer = GetTickCount(); // �׾����� �귯���½ð�.

		if (responTime < 3000) // ��Ÿ��( ��ü )���� ����Ÿ��( ���� �ð� )�� ���� -> �׾��� �ð��̵�.
		{
			responTime = ((deathTimer - runTimer));
			//deathMotionTime = ((deathTimer - runTimer) / 1000);

			if (responTime < 1000)
			{
				deathAnimation->resume();
				// ���ĵǴ� �̹���.. �ִϸ��̼�?
			}
			else if (responTime == 1000)
			{
				playerLifeCount--;
				if (playerLifeCount == 0)
				{
					x = WINSIZEX/2;
					y = WINSIZEY+100;
					responTime = 3000;
				}
			}
			else if (responTime > 1000 && responTime < 3000)
			{
				PositionInit(fileName); // �ڸ� �ʱ�ȭ�ϰ�

				y = -(responTime / 20) + WINSIZEY + 50; // ����� ����Ѱ�. responTomer 3000~4999
				playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
			
			}
		}
		else
		{
			responTime = 0;
			isDead = false;					// �������ð��� �Ǹ� isDead( ���� )�� false�� �Ǽ� �������� ����.
		}
	}
}

void Player::PlayerLifeCountFunc(HDC hdc, std::string fileName)
{
	for (int i = playerLifeCount; i > 0; i--)
	{	
		playerLifeCountImage->SetX(50 + i*30);

		playerLifeCountImage->SetY(WINSIZEY - 100);

		playerLifeCountImage->FrameRender(hdc, playerLifeCountImage->GetX(), playerLifeCountImage->GetY(),
			playerLifeCountImage->GetFrameX(), playerLifeCountImage->GetFrameY());
	}

	
}

void Player::IsClear()
{
	if (isClear)
	{
		if (y > 0)
		{
			// Ŭ���� �����߰�?
			y -= 7;
		}
	}
}

void Player::MoveKey()
{
	//======= Ű ���� .... �÷��̾�1�� x,y���� �̿��� Ŭ���̾�Ʈ ���� ������ �����°� ������ =========
	if (!isDead && !isClear && playerLifeCount > 0)
	{
		if (!isClear&& KEYMANAGER->IsStayKeyDown(VK_LEFT) && rc.left > 100) // 100�� ���߿� ���ʿ� ��κ� �߰��������� �����ؼ� ,,, ������ �κ� ����
		{
			angle += 0.04f;
			x -= speed;
			//
			//playerImage->SetX(playerImage->GetX() - speed);
			dirChange = true;
			playerImage->SetFrameX(3);
		}
		if (!isClear&&KEYMANAGER->IsStayKeyDown(VK_RIGHT) && rc.right < WINSIZEX - 100) // 100�� ���߿� ���ʿ� ��κ� �߰��������� �����ؼ� ,,, ������ �κ� ����
		{
			angle -= 0.04f;
			x += speed;
			//
			//playerImage->SetX(playerImage->GetX() + speed);
			dirChange = false;
			playerImage->SetFrameX(3);
		}
		if (!isClear && KEYMANAGER->IsStayKeyDown(VK_UP) && rc.top > 0)
		{
			y -= speed;
			//playerImage->SetY(playerImage->GetY() - speed);
		}
		if (KEYMANAGER->IsStayKeyDown(VK_DOWN) && rc.bottom < WINSIZEY)
		{
			y += speed;
			//playerImage->SetY(playerImage->GetY() + speed);
		}
		//======================== �׽�Ʈ ==========================================================================================================
		if (KEYMANAGER->IsOnceKeyDown('1'))
		{
			playerLevel = 1;
		}
		if (KEYMANAGER->IsOnceKeyDown('2'))
		{
			playerLevel = 2;
		}
		if (KEYMANAGER->IsOnceKeyDown('3'))
		{
			playerLevel = 3;
			
		}
		if (KEYMANAGER->IsOnceKeyDown('4'))
		{
			playerLevel = 4;
			GAMESYS->SetIsGameClear(true);
			isClear = true;
		}

		if (KEYMANAGER->IsOnceKeyDown('5'))
		{
			playerLevel = 100;
		}
		// �÷��̾� x,y���� ���� �̹����� ����;ߵǴϱ� ������Ʈ�ϴ� ���� �־���
	}
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4);
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);
}

void Player::FireKey()
{
	// �����̽� �ٸ� ������ �Ѿ� �߻�
	if (!isDead && !isClear && playerLifeCount > 0)
	{
		if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
		{
			// �Ѿ˹߻� �Լ�
			gun->BulletFire(endx, endy);
			//PlaySound(TEXT("../Resource/Sound/Missile.wav"), NULL, SND_ASYNC);
		}
	}
	gun->BulletMove();
}