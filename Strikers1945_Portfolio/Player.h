#pragma once
//#define PLAYERSPEED 5
#define PLAYERSIZE	22 // 플레이어 렉트의 크기
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
	float damage;
	// 충돌처리할때, isDead와 isClear false 일때만 충돌처리.
	bool	isDead;
	bool	isClear;
	//
	RECT	collisionBox;	// 충돌처리 해주는 원
	RECT	rc;				// 이미지크기의 렉트

	//
	Gun*	gun;

	// 시간체크에 필요한것들
	DWORD runTimer;	  // 전체 진행시간 체크
	DWORD deathTimer; // 죽은시간.

	//int deathMotionTime;
	float responTime;

	// 애니메이션
	Image *		deathEffect;
	Animation*	deathAnimation;
	// 테스트용
	bool check;
	//RECT target;

public:
	Player();
	~Player();
public:
	void Init();
	void Init(std::string fileName);
	void Update();
	void Render(HDC hdc);
public:
	int GetPlayerLevel() { return playerLevel; }
public:
	void PositionInit();
	void PositionInit(std::string fileName);

	void IsDead();
	void IsClear();

	void MoveKey();
	void FireKey();

	int GetX() { return x; } // collisionBox( 충돌처리를 담당할 원 )의...   x값을 구해오는 함수
	int GetY() { return y; } // collisionBox( 충돌처리를 담당할 원 )의...   y값을 구해오는 함수
	Gun* GetGun() { return gun; }
	void SetIsDead(bool _dead) { isDead = _dead; }
	bool GetIsDead() { return isDead; }
	float GetRadius() { return radius; }
	//========================
	void SetDamage(float _damage) { damage = _damage; }
	float GetDamage() { return damage; }

};

//함수명 : 앞글자 대문자
//변수명 : 자료형 + 앞글자 대문자
//부모 변수명 : m_******
//함수요소 : _소문자