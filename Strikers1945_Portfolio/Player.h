#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // 플레이어 렉트의 크기
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

	bool Check; // 테스트용

public:		
	Player();
	~Player();	
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	//========================
};

//함수명 : 앞글자 대문자
//변수명 : 자료형 + 앞글자 대문자
//부모 변수명 : m_******
//함수요소 : _소문자