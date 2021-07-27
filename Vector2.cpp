#include "Vector2.h"
#include "framework.h"
#include <math.h>
void Vector2::SetPos(float _x, float _y)
{
	x = _x;
	y = _y;
}



float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalize()
{
	float len = Magnitude();
	if (len == 0)
	{
		return Vector2(0, 0);
	}
	return Vector2(x / len, y / len);
}

float Vector2::Dot(Vector2& v1, Vector2& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}



