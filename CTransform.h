#pragma once
#include "CComponent.h"

class Transform : public CComponent
{
public:
	Transform() {};
	~Transform() {};

	Vector2 m_pos;
	Vector2 m_scale;
	Vector2 m_pivot;
};