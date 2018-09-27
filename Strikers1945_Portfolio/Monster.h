#pragma once

class Gun;

enum MonsterType
{
	RandomType,
	Type1,
	Type2,
	MiddleType1, // BigAirPlan
	MiddleType2, // MidAirPlan
	MiddleType3, // Fish
	BOSS,

};
class Monster
{
protected:
	int score;
	float fPivotX;
	float fPivotY;
	float fHp;
	float fAngle;
	float fMoveAngle;
	float width;
	float height;
	bool isLive;
	bool isCollision;
	bool isDeadEffect;
	float effectX;
	float effectY;
protected:
	float coolTime;
	MonsterType mType;

protected:
	RECT rcMonster;
	POINT ptMonster;
	RECT lastRect;

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
	virtual bool Init(const TCHAR* fileName, int number, MonsterType _mType, GAMEPOS pos);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
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
	
	void DeCreaseHp(float _attackPoint);
	
	Gun* GetGun() { return _gun; }
	bool GetIsLive() { return isLive; }
	void SetIsLive(bool _isLive) { isLive = _isLive; }
	Image* GetImage() { return monsterImg; }
	RECT GetRectMonster() { return rcMonster; }
	RECT GetRectCollision() { return lastRect; }
	bool GetIsCollision() { return isCollision; }
	void SetIsCollision(bool _col) { isCollision = _col; }
	MonsterType GetType() { return mType; }

	int GetScore() { return score; }
	void SetScore(int _score) { score = _score; }

};
