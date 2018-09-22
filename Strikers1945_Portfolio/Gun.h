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
	float fSpeed;
	float _cooltime;
protected:
	std::list<Bullet*> bulletList;
public:
	Gun();
	virtual ~Gun();
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
	void SetAngle(float _angle) { fAngle = _angle; }

	float GetSpeed() { return fSpeed; }
	void SetSpeed(float _speed) { fSpeed = _speed; }
};

