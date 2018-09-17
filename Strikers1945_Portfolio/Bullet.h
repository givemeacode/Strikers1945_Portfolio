#pragma once
class Bullet
{
private:
	RECT rcBullet;			// 面倒 贸府 按眉拳? 
	float fPosX;
	float fPosY;
	float fPivotX;
	float fPivotY;
	float fRadius;
	bool isBulletFire;
public:
	Bullet();
	~Bullet();
public:
	bool Init(float x, float y, float _radius);
	void Update();
	void Render(HDC hdc);
public:
	void SetIsBulletFire(bool isBulletFire);
	bool GetIsBulletFire();

	void SetPivot(float x, float y);
	float GetPivotX();
	float GetPivotY();
	void SetPivotX(float x);
	void SetPivotY(float y);

	void SetCenterPivot(RECT rc);

public:
	float GetRadius();
};

