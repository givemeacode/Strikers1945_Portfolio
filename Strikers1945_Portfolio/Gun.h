#pragma once

class Bullet;


class Gun
{
protected:
	float fCoolTime;
	float fPivotX;
	float fPivotY;
	float fPosX;
	float fPosY;
	float fAngle;
protected:
	std::list<Bullet*> bulletList;
public:
	Gun();
	~Gun();
public:
	virtual bool Init(float x, float y);
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	virtual void BulletFire(float x, float y);
	virtual void BulletMove();
public:

	void SetPivot(float x, float y);
	float GetPivotX();
	float GetPivotY();
	void SetPivotX(float x);
	void SetPivotY(float y);

	void SetCenterPivot(RECT rc);
	std::list<Bullet*>& GetBulletList();
};

