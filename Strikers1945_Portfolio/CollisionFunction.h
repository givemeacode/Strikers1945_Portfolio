#pragma once
bool CollisionCircleAndPoint(const float r, const float x, const float y, float ptX, float ptY);
bool CollisionRectAndRect(const RECT& r1, const RECT& r2);
bool CollisionCircleAndCircle(const float r1, const float x1, const float y1, const float r2, const float x2, const float y2);// ù��°��( ��ŸƮ )�� r,x,y ... �ι�° �� ( end )�� r,x,y
bool CollisionCircleAndRect(const float r, const float x, const float y, const RECT& r1);