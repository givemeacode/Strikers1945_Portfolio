#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // �÷��̾� ��Ʈ�� ũ��
class Image;
class Gun;
//

class Player
{
private:

	Image* playerImage;
	int		playerLevel;
	int		dirChange;
	int		nCount;
	int		iIndex;

	float x, y;
	float angle;
	float endx, endy;
	float length;
	float speed;
	float radius;
	// �浹ó���Ҷ�, isDead�� isClear false �϶��� �浹ó��.
	bool	isDead;
	bool	isClear;
	//
	RECT	collisionBox;	// �浹ó�� ���ִ� ��
	RECT	rc;				// �̹���ũ���� ��Ʈ

	//
	Gun*	gun;

	// �ð�üũ�� �ʿ��Ѱ͵�
	DWORD runTimer;	  // ��ü ����ð� üũ
	DWORD deathTimer; // �����ð�.

	//int deathMotionTime;
	float responTime;

	// �ִϸ��̼�
	Image *		deathEffect;
	Animation*	deathAnimation;
	// �׽�Ʈ��
	bool check;
	//RECT target;

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
	void IsClear();

	void MoveKey();
	void FireKey();

	int GetX() { return x; } // collisionBox( �浹ó���� ����� �� )��...   x���� ���ؿ��� �Լ�
	int GetY() { return y; } // collisionBox( �浹ó���� ����� �� )��...   y���� ���ؿ��� �Լ�
	Gun* GetGun() { return gun; }
	void SetIsDead(bool _dead) { isDead = _dead; }
	bool GetIsDead() { return isDead; }
	float GetRadius() { return radius; }
	//========================

};

//�Լ��� : �ձ��� �빮��
//������ : �ڷ��� + �ձ��� �빮��
//�θ� ������ : m_******
//�Լ���� : _�ҹ���