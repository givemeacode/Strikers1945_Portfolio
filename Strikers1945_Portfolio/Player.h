#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // �÷��̾� ��Ʈ�� ũ��
class Image;
//
struct Player1
{
	float x, y;
	float angle;
	float endx, endy;
	float length;
	float speed;

	RECT rc;
};

class Player
{
private:

	Image * playerImage;

	int		dirChange;
	int		nCount;
	int		iIndex;
	
	//
	Player1 player1;

	bool Check; // �׽�Ʈ��

public:		
	Player();
	~Player();	
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	//========================
};

//�Լ��� : �ձ��� �빮��
//������ : �ڷ��� + �ձ��� �빮��
//�θ� ������ : m_******
//�Լ���� : _�ҹ���