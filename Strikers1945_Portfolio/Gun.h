#pragma once

class Bullet;

enum eGunType
{
	GUN_NONE,

};


class Gun
{
private:
	float fCoolTime;
private:
	//RECT rcGun;
	float fPivotX;
	float fPivotY;
	float fPosX;
	float fPosY;
private:
	std::list<Bullet*> bulletList;
public:
	Gun();
	~Gun();
public:
	bool Init(eGunType type,float x, float y);
	void Render(HDC hdc);
	void Release();
public:
	void BulletFire(float x, float y);
	void BulletMove();
public:

	void SetPivot(float x, float y);
	float GetPivotX();
	float GetPivotY();
	void SetPivotX(float x);
	void SetPivotY(float y);

	void SetCenterPivot(RECT rc);
};

