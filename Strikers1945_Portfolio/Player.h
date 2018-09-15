#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // �÷��̾� ��Ʈ�� ũ��
class Image;

class Gun;
//


class Player
{
private:

	Image * playerImage;
	Gun *	gun;
	int		dirChange;
	int		nCount;
	int		iIndex;
	
	float	x, y;
	float	angle;
	float	endx, endy;
	float	length;
	float	speed;

	RECT	collisionBox;	// �浹ó�� ���ִ� ��
	RECT	rc;				// �̹���ũ���� ��Ʈ

	//

	bool check; // �׽�Ʈ��

public:		
	Player();
	~Player();	
public:
	void Init();
	void Update();
	void Render(HDC hdc);
public:
	void PositionInit();
	void MoveKey();
	void FireKey();
	//========================
};

//�Լ��� : �ձ��� �빮��
//������ : �ڷ��� + �ձ��� �빮��
//�θ� ������ : m_******
//�Լ���� : _�ҹ���