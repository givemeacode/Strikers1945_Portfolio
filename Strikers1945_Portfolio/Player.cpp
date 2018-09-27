#include "stdafx.h"
#include "Player.h"
#include "Gun.h"
#include "PlayerGun.h"

#pragma comment (lib,"winmm")



Player::Player()
{
//	// 플레이어 위치 초기값 설정.
//	PositionInit();
//
//	isDead = false;
//	isClear = false;
//	radius = 10.f;
//	// 시간체크
//	runTimer = GetTickCount();
//	deathTimer = 0; // 죽었을때 시점을 저장하기위해.
//	damage = 1.f;
////	deathMotionTime = 0; // 죽었을때 잠깐 없어지는 시간 ( 폭파 모션 )
//	responTime = 0.f; // 리스폰시간
//
//	//// 테스트용 ////
//	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);
//
//	//
//	gun = new PlayerGun;
//	gun->Init(endx, endy);
//
//	// 애니메이션
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
	// 플레이어 위치 초기값 설정.
	PositionInit();

	isDead = false;
	isClear = false;
	radius = 10.f;
	// 시간체크
	runTimer = GetTickCount();
	deathTimer = 0; // 죽었을때 시점을 저장하기위해.
	damage = 1.f;
	//	deathMotionTime = 0; // 죽었을때 잠깐 없어지는 시간 ( 폭파 모션 )
	responTime = 0.f; // 리스폰시간

	//// 테스트용 ////
	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

	//
	gun = new PlayerGun;
	gun->Init(endx, endy);

	// 애니메이션
	deathEffect = IMAGEMANAGER->FindImage(TEXT("Effect_7"));
	deathAnimation = new Animation;
	deathAnimation->Init(deathEffect);
	deathAnimation->setDefPlayFrame(false, true);
	deathAnimation->setFPS(5.f); //
}

void Player::Init(std::string fileName)
{
	// 플레이어 위치 초기값 설정.
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
	// 시간체크
	runTimer = GetTickCount();
	deathTimer = 0; // 죽었을때 시점을 저장하기위해.
	damage = 1.f;
	//	deathMotionTime = 0; // 죽었을때 잠깐 없어지는 시간 ( 폭파 모션 )
	responTime = 0.f; // 리스폰시간

	//// 테스트용 ////
	//target = RectMakeCenter(WINSIZEX / 2, 50, 50, 50);

	//
	gun = new PlayerGun;
	gun->Init(endx, endy);

	// 애니메이션
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

	// 이동 ( 키보드 방향키 )
	MoveKey();

	// 발사 ( 스페이스 바 )
	FireKey();
	
	// ====== 테스트용 ... D를 누르면 플레이어의 렉트 출력===============
	if (KEYMANAGER->IsStayKeyDown(0x44))
	{
		check = true;
	}
	if (KEYMANAGER->IsOnceKeyUp(0x44))
	{
		check = false;
	}
	// ====== 플레이어의 총알이 나가는위치는 endx, endy값으로 하기위해 endx, endy를 설정해줌 =========
	endx = x;
	endy = y - (length + 7);

	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32);

	// 애니메이션
	deathAnimation->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);

	if (playerLifeCount != 0)
	{
		playerLifeContinueCountTimerIndex = GetTickCount();
	}
	if (playerLifeCount == 0)
	{
		playerLifeContinueCount = 9 - (playerLifeContinueCountTimer / 1000);
		if (playerLifeCount == 0) //  9 - (runTimer / 1000) 값이 ...  0이되면 선택시간이 종료된 것.
		{
			//playerLifeContinueCountTimer = GetTickCount() - playerLifeContinueCountTimerIndex; // 전체시간
			GAMESYS->GameOver();
			return;
		}
	}

	
	/////////// 테스트 ///////////////////
	//OffsetRect(&target, 0, 5);

}

void Player::Render(HDC hdc)
{
	//이미지
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
	

	//애니메이션
	if (isDead)
	{
		if (responTime < 1000)
		{
			deathEffect->AniRender(hdc, x-64, y-64, deathAnimation); // 64는 이미지 사이즈/2
		}
	}
	// 목숨 ( 그림으로 표시 )
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

	///////////////        테스트        ///////////////////////////
	if (check) // 체크 버튼은 D
	{
		//도형
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

		EllipseMakeCenter(hdc, x, y, PLAYERSIZE, PLAYERSIZE);
		LineMake(hdc, x, y, endx, endy);
	}

	//TCHAR szTemp[100] = { 0, };
	//_stprintf_s(szTemp, sizeof(szTemp), TEXT("runTimer : %d"), runTimer);
	//TextOut(hdc, WINSIZEX / 2 - 270, 120, TEXT(szTemp), _tcslen(TEXT(szTemp)));

	//// 선택시간.. 9초부터 0초까지... 0초가되면 현재 위치하는 인덱스값으로 자동 결정.
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
	// 플레이어 객체 ( 렉트 ) 초기화
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2;
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32는 이미지 크기
	speed = 8.f;

	// 플레이어 이미지 초기화
	//playerImage = new Image;
	//playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage = IMAGEMANAGER->FindImage("Move_LR_A");
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 넓이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetFrameX(3); // 4번째 프레임으로 초기화값.
}

void Player::PositionInit(std::string fileName)
{
	playerLevel = 1;
	// 플레이어 객체 ( 렉트 ) 초기화
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2;
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32는 이미지 크기
	speed = 8.f;

	// 플레이어 이미지 초기화
	//playerImage = new Image;
	//playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage = IMAGEMANAGER->FindImage(fileName);
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 넓이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetFrameX(3); // 4번째 프레임으로 초기화값.

	std::string file;
	file = fileName + "_Ending";
	//wsprintf(file, TEXT("%s_Ending"), TEXT(fileName));
	endingImage = IMAGEMANAGER->FindImage(file);

	endingImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4); // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 넓이의 반을 계산해줘서 중심으로 옴긴다.
	endingImage->SetY(y - playerImage->GetFrameHeight() / 2);

	endingAni = new Animation();
	endingAni->Init(endingImage);
	endingAni->setDefPlayFrame();
	endingAni->setFPS(1.f);

}

void Player::IsDead()
{
	if (!isDead) // 살아있을떄 흘러가는 타이머 ... 죽었을떄 멈추는걸 이용해서 죽은시간을 체크해보자.
	{
		runTimer = GetTickCount();
	}

	if (isDead)
	{
		deathTimer = GetTickCount(); // 죽었을떄 흘러가는시간.

		if (responTime < 3000) // 런타임( 전체 )에서 데스타임( 죽은 시간 )을 빼면 -> 죽었던 시간이됨.
		{
			responTime = ((deathTimer - runTimer));
			//deathMotionTime = ((deathTimer - runTimer) / 1000);

			if (responTime < 1000)
			{
				deathAnimation->resume();
				// 폭파되는 이미지.. 애니메이션?
			}
			else if (responTime >= 1000 && responTime < 3000)
			{
				PositionInit(); // 자리 초기화하고

				y = -(responTime / 20) + WINSIZEY + 50; // 계산기로 계산한값. responTomer 3000~4999
				playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
			}
		}
		else
		{
			responTime = 0;
			isDead = false;					// 리스폰시간이 되면 isDead( 상태 )는 false가 되서 이프문을 나감.
		}
	}
}

void Player::IsDead(std::string fileName)
{
	if (!isDead) // 살아있을떄 흘러가는 타이머 ... 죽었을떄 멈추는걸 이용해서 죽은시간을 체크해보자.
	{
		runTimer = GetTickCount();
	}

	if (isDead)
	{

		deathTimer = GetTickCount(); // 죽었을떄 흘러가는시간.

		if (responTime < 3000) // 런타임( 전체 )에서 데스타임( 죽은 시간 )을 빼면 -> 죽었던 시간이됨.
		{
			responTime = ((deathTimer - runTimer));
			//deathMotionTime = ((deathTimer - runTimer) / 1000);

			if (responTime < 1000)
			{
				deathAnimation->resume();
				// 폭파되는 이미지.. 애니메이션?
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
				PositionInit(fileName); // 자리 초기화하고

				y = -(responTime / 20) + WINSIZEY + 50; // 계산기로 계산한값. responTomer 3000~4999
				playerImage->SetY(y - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
			
			}
		}
		else
		{
			responTime = 0;
			isDead = false;					// 리스폰시간이 되면 isDead( 상태 )는 false가 되서 이프문을 나감.
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
			// 클리어 음악추가?
			y -= 7;
		}
	}
}

void Player::MoveKey()
{
	//======= 키 조작 .... 플레이어1의 x,y값을 이용해 클라이언트 영역 밖으로 나가는걸 제한함 =========
	if (!isDead && !isClear && playerLifeCount > 0)
	{
		if (!isClear&& KEYMANAGER->IsStayKeyDown(VK_LEFT) && rc.left > 100) // 100은 나중에 양쪽에 까만부분 추가했을때를 생각해서 ,,, 움직일 부분 제한
		{
			angle += 0.04f;
			x -= speed;
			//
			//playerImage->SetX(playerImage->GetX() - speed);
			dirChange = true;
			playerImage->SetFrameX(3);
		}
		if (!isClear&&KEYMANAGER->IsStayKeyDown(VK_RIGHT) && rc.right < WINSIZEX - 100) // 100은 나중에 양쪽에 까만부분 추가했을때를 생각해서 ,,, 움직일 부분 제한
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
		//======================== 테스트 ==========================================================================================================
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
		// 플레이어 x,y값에 따라 이미지가 따라와야되니까 업데이트하는 곳에 넣어줌
	}
	playerImage->SetX(x - playerImage->GetFrameWidth() / 2 - 4);
	playerImage->SetY(y - playerImage->GetFrameHeight() / 2);
}

void Player::FireKey()
{
	// 스페이스 바를 누르면 총알 발사
	if (!isDead && !isClear && playerLifeCount > 0)
	{
		if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
		{
			// 총알발사 함수
			gun->BulletFire(endx, endy);
			//PlaySound(TEXT("../Resource/Sound/Missile.wav"), NULL, SND_ASYNC);
		}
	}
	gun->BulletMove();
}