#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // 플레이어 렉트의 크기
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

	RECT	collisionBox;	// 충돌처리 해주는 원
	RECT	rc;				// 이미지크기의 렉트

	//

	bool check; // 테스트용

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

//함수명 : 앞글자 대문자
//변수명 : 자료형 + 앞글자 대문자
//부모 변수명 : m_******
//함수요소 : _소문자