#include "stdafx.h"
#include "CollisionObject.h"



CollisionObject::CollisionObject()
{
}


CollisionObject::~CollisionObject()
{
}

bool CollisionObject::Init()
{
	return true;
}

RECT CollisionObject::GetRectCollision()
{
	return rcCollision;
}

void CollisionObject::SetRectCollision(RECT rc)
{
	rcCollision = rc;
}
