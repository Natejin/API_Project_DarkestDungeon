#pragma once
#include "CComponent.h"

class CTransform : public CComponent
{
public:
	CTransform() {};
	~CTransform() {};

	Vector2 m_pos;
	Vector2 m_scale;
	Vector2 m_pivot;
};