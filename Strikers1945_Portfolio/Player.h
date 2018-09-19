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
	int		playerLevel;
	int		dirChange;
	int		nCount;
	int		iIndex;

	float x, y;
	float angle;
	float endx, endy;
	float length;
	float speed;

	bool	isDead;

	//
	RECT	collisionBox;	// �浹ó�� ���ִ� ��
	RECT	rc;				// �̹���ũ���� ��Ʈ

	//
	Gun*	gun;

	// �ð�üũ�� �ʿ��Ѱ͵�
	DWORD runTimer;	  // ��ü ����ð� üũ
	DWORD deathTimer; // �����ð�.

	int deathMotionTime;
	float responTime;

	// �׽�Ʈ��
	bool check;
	RECT target;

public:
	Player();
	~Player();
public:
	void Init();
	void Update();
	void Render(HDC hdc);
public:
	int GetPlayerLevel() { return playerLevel; }
public:
	void PositionInit();
	void IsDead();

	void MoveKey();
	void FireKey();

	int GetX() { return x; } // collisionBox( �浹ó���� ����� �� )��...   x���� ���ؿ��� �Լ�
	int GetY() { return y; } // collisionBox( �浹ó���� ����� �� )��...   y���� ���ؿ��� �Լ�

	//========================
};

//�Լ��� : �ձ��� �빮��
//������ : �ڷ��� + �ձ��� �빮��
//�θ� ������ : m_******
//�Լ���� : _�ҹ���