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
	RECT	collisionBox;	// 충돌처리 해주는 원
	RECT	rc;				// 이미지크기의 렉트

	//
	Gun*	gun;

	// 시간체크에 필요한것들
	DWORD runTimer;	  // 전체 진행시간 체크
	DWORD deathTimer; // 죽은시간.

	int deathMotionTime;
	float responTime;

	// 테스트용
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

	int GetX() { return x; } // collisionBox( 충돌처리를 담당할 원 )의...   x값을 구해오는 함수
	int GetY() { return y; } // collisionBox( 충돌처리를 담당할 원 )의...   y값을 구해오는 함수

	//========================
};

//함수명 : 앞글자 대문자
//변수명 : 자료형 + 앞글자 대문자
//부모 변수명 : m_******
//함수요소 : _소문자