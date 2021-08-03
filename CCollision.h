#pragma once
#include "CComponent.h"

class Collision : public CComponent
{
public:
	COLLISIONTYPE m_collisionType;
	Vector2 pos;

	//forBox
};