#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	// �÷��̾� �̹��� �ʱ�ȭ
	playerImage = new Image;
	playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage->SetX(WINSIZEX / 2 - playerImage->GetFrameWidth() / 2); // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetY(WINSIZEY - 100 - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetFrameX(3); // 4��° ���������� �ʱ�ȭ��.


	// �÷��̾� ��ü ( ��Ʈ ) �ʱ�ȭ
	player1.angle = PI / 2.f;
	player1.x = static_cast<float>(WINSIZEX) / 2 +4 ; // 4�� �̹��� ũ�� ���߱����� �ӽ� ��
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
	//======= Ű ���� .... �÷��̾�1�� x,y���� �̿��� Ŭ���̾�Ʈ ���� ������ �����°� ������ =========
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

	// �����̽� ������ �Ѿ� �߻�  - Once Down
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		// �Ѿ˹߻� �Լ�
		//
		//
	}


	// ====== �׽�Ʈ�� ... D�� ������ �÷��̾��� ��Ʈ ���===============
	if (KEYMANAGER->isStayKeyDown(0x44))
	{
		Check = true;
	}
	if (KEYMANAGER->isOnceKeyUp(0x44))
	{
		Check = false;
	}



	// ====== �÷��̾��� �Ѿ��� ��������ġ�� endx, endy������ �ϱ����� endx, endy�� �������� =========
	player1.endx = player1.x;
	player1.endy = player1.y - (player1.length + 7);


	//player1.rc = RectMakeCenter(player1.x, player1.y, PLAYERSIZE, PLAYERSIZE);
}

void Player::Render(HDC hdc)
{
	//�̹���
	playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
		playerImage->GetFrameX(), playerImage->GetFrameY());

	if (Check) // üũ ��ư�� D
	{
		//����
		EllipseMakeCenter(hdc, player1.x, player1.y, PLAYERSIZE, PLAYERSIZE);
		lineMake(hdc, player1.x, player1.y, player1.endx, player1.endy);
	}

}

