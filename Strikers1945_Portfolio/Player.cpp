#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	// 플레이어 이미지 초기화
	playerImage = new Image;
	playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage->SetX(WINSIZEX / 2 - playerImage->GetFrameWidth() / 2); // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 넓이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetY(WINSIZEY - 100 - playerImage->GetFrameHeight() / 2);  // 렉트는 중심부터 그려지고, 이미지는 left,top부터 그리니까 이미지프레임의 높이의 반을 계산해줘서 중심으로 옴긴다.
	playerImage->SetFrameX(3); // 4번째 프레임으로 초기화값.


	// 플레이어 객체 ( 렉트 ) 초기화
	player1.angle = PI / 2.f;
	player1.x = static_cast<float>(WINSIZEX) / 2 +4 ; // 4는 이미지 크기 맞추기위한 임시 값
	player1.y = static_cast<float>(WINSIZEY) - 100;
	player1.endx = player1.x;
	player1.endy = player1.y - player1.length+20;
	player1.length = PLAYERSIZE/2;
	player1.rc = RectMakeCenter(player1.x, player1.y, PLAYERSIZE, PLAYERSIZE);
	player1.speed = 4.f;
}

Player::~Player()
{
	SAFE_DELETE(playerImage);
}

void Player::Init()
{
}

void Player::Update()
{
	//======= 키 조작 .... 플레이어1의 x,y값을 이용해 클라이언트 영역 밖으로 나가는걸 제한함 =========
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && player1.x  > 0)
	{
		player1.angle += 0.04f;
		player1.x -= player1.speed;
		//
		playerImage->SetX(playerImage->GetX() - player1.speed);
		dirChange = true;
		playerImage->SetFrameX(3);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && player1.x < WINSIZEX)
	{
		player1.angle -= 0.04f;
		player1.x += player1.speed;
		//
		playerImage->SetX(playerImage->GetX() + player1.speed);
		dirChange = false;
		playerImage->SetFrameX(3);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && player1.y > 0)
	{
		player1.y -= player1.speed;
		playerImage->SetY(playerImage->GetY() - player1.speed);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && player1.y < WINSIZEY)
	{
		player1.y += player1.speed;
		playerImage->SetY(playerImage->GetY() + player1.speed);
	}

	// 스페이스 누르면 총알 발사  - Once Down
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		// 총알발사 함수
		//
		//
	}


	// ====== 테스트용 ... D를 누르면 플레이어의 렉트 출력===============
	if (KEYMANAGER->isStayKeyDown(0x44))
	{
		Check = true;
	}
	if (KEYMANAGER->isOnceKeyUp(0x44))
	{
		Check = false;
	}



	// ====== 플레이어의 총알이 나가는위치는 endx, endy값으로 하기위해 endx, endy를 설정해줌 =========
	player1.endx = player1.x;
	player1.endy = player1.y - (player1.length + 7);


	//player1.rc = RectMakeCenter(player1.x, player1.y, PLAYERSIZE, PLAYERSIZE);
}

void Player::Render(HDC hdc)
{
	//이미지
	playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
		playerImage->GetFrameX(), playerImage->GetFrameY());

	if (Check) // 체크 버튼은 D
	{
		//도형
		EllipseMakeCenter(hdc, player1.x, player1.y, PLAYERSIZE, PLAYERSIZE);
		lineMake(hdc, player1.x, player1.y, player1.endx, player1.endy);
	}

}

