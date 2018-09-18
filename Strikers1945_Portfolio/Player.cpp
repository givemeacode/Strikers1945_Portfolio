#include "stdafx.h"
#include "Player.h"
#include "Gun.h"

Player::Player()
{
	// 플레이어 이미지 초기화
	playerImage = new Image;
	playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage->SetX(WINSIZEX / 2 - playerImage->GetFrameWidth() / 2); // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 넓이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetY(WINSIZEY - 100 - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetFrameX(3); // 4번째 프레임으로 초기화값.

	// 플레이어 위치 초기값 설정.
	PositionInit();
}

Player::~Player()
{
	SAFE_DELETE(playerImage);
}

void Player::Init()
{
	gun = new Gun;
	gun->Init(eGunType::GUN_NONE, endx, endy);
}

void Player::Update()
{
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

	rc = RectMakeCenter(x, y, 32,32);
}

void Player::Render(HDC hdc)
{
	//이미지
	playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
		playerImage->GetFrameX(), playerImage->GetFrameY());

	if (check) // 체크 버튼은 D
	{
		//도형
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		//
		EllipseMakeCenter(hdc, x, y, PLAYERSIZE, PLAYERSIZE);
		LineMake(hdc, x, y, endx, endy);
	}

	gun->Render(hdc);
}

void Player::PositionInit()
{
	// 플레이어 객체 ( 렉트 ) 초기화
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2 + 4; // 4는 이미지 크기 맞추기위한 임시 값
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32는 이미지 크기
	speed = 8.f;
}

void Player::MoveKey()
{
	//======= 키 조작 .... 플레이어1의 x,y값을 이용해 클라이언트 영역 밖으로 나가는걸 제한함 =========
	if (KEYMANAGER->IsStayKeyDown(VK_LEFT) && rc.left  > 0)
	{
		angle += 0.04f;
		x -= speed;
		//
		playerImage->SetX(playerImage->GetX() - speed);
		dirChange = true;
		playerImage->SetFrameX(3);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT) && rc.right < WINSIZEX)
	{
		angle -= 0.04f;
		x += speed;
		//
		playerImage->SetX(playerImage->GetX() + speed);
		dirChange = false;
		playerImage->SetFrameX(3);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_UP) && rc.top > 0)
	{
		y -= speed;
		playerImage->SetY(playerImage->GetY() - speed);
	}
	if (KEYMANAGER->IsStayKeyDown(VK_DOWN) && rc.bottom < WINSIZEY)
	{
		y += speed;
		playerImage->SetY(playerImage->GetY() + speed);
	}
}

void Player::FireKey()
{
	// 스페이스 누르면 총알 발사
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		// 총알발사 함수
		gun->BulletFire(endx, endy);
	}
	gun->BulletMove();
}