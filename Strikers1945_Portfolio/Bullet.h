#pragma once
class Bullet
{
private:
	RECT rcBullet;			// 面倒 贸府 按眉拳? 
	POINT ptBullet;

	Image* bulletImg;
	Animation* aniBullet;

	float fPosX;
	float fPosY;
	float fPivotX;
	float fPivotY;
	float fRadius;
	bool isBulletFire;
	bool isCollision;
	float fAngle;
	float width;
	float height;
public:
	Bullet();
	~Bullet();
public:
	bool Init(float x, float y, float _radius);
	bool Init(const TCHAR* fileName, float x, float y, float _radius);
	void Update();
	void Update(int);

	void Render(HDC hdc);
	void Render(HDC hdc, int);

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
	bool GetIsCollision();
	void SetIsCollision(bool _iscollision);

	float GetAngle() { return fAngle; }
	void SetAngle(float _angle) { fAngle = _angle; }
};

