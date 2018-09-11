#include "stdafx.h"
#include "Util.h"


namespace UTIL
{
	//float getDistance(float startX, float startY, float endX, float endY)
	//{
	//	float x = endX - startX;
	//	float y = endY - startY;


	//	return sqrtf(x * x + y * y);
	//}

	float getDistance(const float startX, const float startY, const float endX, const float endY)
	{
		float x = endX - startX;
		float y = endY - startY;


		return sqrtf(x * x + y * y);
	}
}