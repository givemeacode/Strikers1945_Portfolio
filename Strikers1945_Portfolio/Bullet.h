#pragma once
class Bullet
{
private:
	RECT rcBullet;			// �浹 ó�� ��üȭ? 
	float fPosX;
	float fPosY;
	float fPivotX;
	float fPivotY;
	float fRadius;
	bool isBulletFire;
	bool isCollision;
	float fAngle;
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
	bool GetIsCollision();
	void SetIsCollision(bool _iscollision);

	float GetAngle() { return fAngle; }
	void SetAngle(float _angle) { fAngle = _angle; }
};

