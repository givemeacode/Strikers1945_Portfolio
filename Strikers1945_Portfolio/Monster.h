#pragma once

class Gun;

class Monster
{
protected:
	float fPivotX;
	float fPivotY;
	float fHp;
	float fAngle;
	float fMoveAngle;
	float width;
	float height;
	bool isLive;
protected:
	float coolTime;
protected:
	RECT rcMonster;
	POINT ptMonster;
	RECT rcCollision;

	RECT rcLastPos;
	POINT ptLastPos;
protected:
	Image* monsterImg;
protected:
	float rcPosX;
	float rcPosY;
protected:
	Gun* _gun;
	GAMEPOS startPos;
	GAMEPOS lastPos;
public:
	Monster();
	virtual ~Monster();
public:
	virtual bool Init(int x, int y);
	virtual bool Init(const TCHAR* fileName, int x, int y);
	virtual bool Init(const TCHAR* fileName);
	virtual bool Init(const TCHAR* fileName, int number, GAMEPOS pos);
	virtual void Update();
	virtual void Render(HDC hdc);
public:
	void MonsterAI();

public:
	void SetPivot(float x, float y);
	float GetPivotX();
	float GetPivotY();
	void SetPivotX(float x);
	void SetPivotY(float y);

	void SetCenterPivot(RECT rc);
	void CoolTimeReset();

	void OffectX(float x);
	void OffectY(float y);
	
	void StartPosition(Image* img);
	void LastPosition(GAMEPOS pos);
	Gun* GetGun() { return _gun; }
	bool GetIsLive() { return isLive; }
	void SetIsLive(bool _isLive) { isLive = _isLive; }
	Image* GetImage() { return monsterImg; }
	RECT GetRectMonster() { return rcMonster; }

	
};

