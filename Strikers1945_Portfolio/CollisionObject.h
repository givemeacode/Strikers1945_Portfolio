#pragma once
class CollisionObject
{
private:
	RECT rcCollision;
public:
	CollisionObject();
	~CollisionObject();
public:
	bool Init();
};

