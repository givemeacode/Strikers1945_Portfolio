#include "stdafx.h"
#include "Player.h"
#include "Gun.h"

Player::Player()
{
	// �÷��̾� �̹��� �ʱ�ȭ
	playerImage = new Image;
	playerImage->Init(TEXT("../Resource/Image/Player/Move_LR_A.bmp"), 223, 33, 7, 1, true, RGB(0, 0, 0));
	playerImage->SetX(WINSIZEX / 2 - playerImage->GetFrameWidth() / 2); // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetY(WINSIZEY - 100 - playerImage->GetFrameHeight() / 2);  // ��Ʈ�� �߽ɺ��� �׷�����, �̹����� left,top���� �׸��ϱ� �̹����������� ������ ���� ������༭ �߽����� �ȱ��.
	playerImage->SetFrameX(3); // 4��° ���������� �ʱ�ȭ��.

	// �÷��̾� ��ġ �ʱⰪ ����.
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

	rc = RectMakeCenter(x, y, 32,32);
}

void Player::Render(HDC hdc)
{
	//�̹���
	playerImage->FrameRender(hdc, playerImage->GetX(), playerImage->GetY(),
		playerImage->GetFrameX(), playerImage->GetFrameY());

	if (check) // üũ ��ư�� D
	{
		//����
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		//
		EllipseMakeCenter(hdc, x, y, PLAYERSIZE, PLAYERSIZE);
		LineMake(hdc, x, y, endx, endy);
	}

	gun->Render(hdc);
}

void Player::PositionInit()
{
	// �÷��̾� ��ü ( ��Ʈ ) �ʱ�ȭ
	angle = PI / 2.f;
	x = static_cast<float>(WINSIZEX) / 2 + 4; // 4�� �̹��� ũ�� ���߱����� �ӽ� ��
	y = static_cast<float>(WINSIZEY) - 100;
	endx = x;
	endy = y - length + 20;
	length = PLAYERSIZE / 2;
	collisionBox = RectMakeCenter(x, y, PLAYERSIZE, PLAYERSIZE);
	rc = RectMakeCenter(x, y, 32, 32); // 32�� �̹��� ũ��
	speed = 8.f;
}

void Player::MoveKey()
{
	//======= Ű ���� .... �÷��̾�1�� x,y���� �̿��� Ŭ���̾�Ʈ ���� ������ �����°� ������ =========
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
	// �����̽� ������ �Ѿ� �߻�
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		// �Ѿ˹߻� �Լ�
		gun->BulletFire(endx, endy);
	}
	gun->BulletMove();
}