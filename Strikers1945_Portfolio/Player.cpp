#include "stdafx.h"
#include "Player.h"
#include "Gun.h"
#include "PlayerGun.h"

Player::Player()
{
	// �÷��̾� ��ġ �ʱⰪ ����.
	PositionInit();

	isDead = false;
	isClear = false;
	radius = 10.f;
	// �ð�üũ
	runTimer = GetTickCount();
	deathTimer = 0; // �׾����� ������ �����ϱ�����.

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

Player::~Player()
{
	SAFE_DELETE(playerImage);
	SAFE_DELETE(deathAnimation);
}

void Player::Init()
{
}

void Player::Update()
{
	RECT temp;
	//if (IntersectRect(&temp, &collisionBox, &target))
	//{
	//	isDead = true;
	//}

	IsDead();
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

	/////////// �׽�Ʈ ///////////////////
	//OffsetRect(&target, 0, 5);
}

void Player::Render(HDC hdc)
{
	//�̹���
	playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
		playerImage->GetFrameX(), playerImage->GetFrameY());

	//�ִϸ��̼�
	if (isDead)
	{
		if (responTime < 1000)
		{
			deathEffect->AniRender(hdc, x-64, y-64, deathAnimation); // 64�� �̹��� ������/2
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
	if (!isDead && !isClear)
	{
		if (KEYMANAGER->IsStayKeyDown(VK_LEFT) && rc.left > 100) // 100�� ���߿� ���ʿ� ��κ� �߰��������� �����ؼ� ,,, ������ �κ� ����
		{
			angle += 0.04f;
			x -= speed;
			//
			//playerImage->SetX(playerImage->GetX() - speed);
			dirChange = true;
			playerImage->SetFrameX(3);
		}
		if (KEYMANAGER->IsStayKeyDown(VK_RIGHT) && rc.right < WINSIZEX - 100) // 100�� ���߿� ���ʿ� ��κ� �߰��������� �����ؼ� ,,, ������ �κ� ����
		{
			angle -= 0.04f;
			x += speed;
			//
			//playerImage->SetX(playerImage->GetX() + speed);
			dirChange = false;
			playerImage->SetFrameX(3);
		}
		if (KEYMANAGER->IsStayKeyDown(VK_UP) && rc.top > 0)
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
		}
		// �÷��̾� x,y���� ���� �̹����� ����;ߵǴϱ� ������Ʈ�ϴ� ���� �־���
	}
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4);
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);
}

void Player::FireKey()
{
	// �����̽� �ٸ� ������ �Ѿ� �߻�
	if (!isDead && !isClear)
	{
		if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
		{
			// �Ѿ˹߻� �Լ�
			gun->BulletFire(endx, endy);
		}
	}
	gun->BulletMove();
}


