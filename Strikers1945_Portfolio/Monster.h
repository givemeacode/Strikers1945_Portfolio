#pragma once

class Gun;

enum eMonsterType
{
	MONSTER_TYPE_NONE,
	MONSTER_TYPE_MIDLLEBOSS,
	//MONSTER_TYPE_BOSS,
};

class Monster
{
private:
	float fPivotX;
	float fPivotY;
	float fHp;
	float fAngle;
	RECT rcMonster;
	RECT rcCollision;
	bool isLive;

private:
	//RECT rcMonster1;
	//RECT rcMonster2;
	//RECT rcMonster3;
	//RECT rcMonster4;
	//RECT rcMonster5;
	//RECT rcMonster6;

	//RECT rcGameClient;

	//RECT rcObj;
	////POINT rcObjPos;
	//float rcPosX;
	//float rcPosY;
private:
	Gun* _gun;

	float fStartTime;
	float CurrentTime;
	float deltaTime;
	float coolTime;
public:
	Monster();
	~Monster();
public:
	bool Init(eMonsterType type, int x, int y);
	void Update();
	void Render(HDC hdc);
public:
	void MonsterAI();

public:
	void SetPivot(float x, float y);
	float GetPivotX();
	float GetPivotY();
	void SetPivotX(float x);
	void SetPivotY(float y);

	void SetCenterPivot(RECT rc);

	Gun* GetGun() { return _gun; }
	bool GetIsLive() { return isLive; }
	void SetIsLive(bool _isLive) { isLive = _isLive; }

};

