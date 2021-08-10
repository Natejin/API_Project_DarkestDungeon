#pragma once
#include "CComponent.h"

class CTransform : public CComponent
{
public:
	CTransform() {
		m_scale = Vector2( 1, 1);
		m_pos = Vector2( 0, 0);
		m_pivot = Vector2(0, 0);
	};
	~CTransform() {};

	Vector2 m_pos;
	Vector2 m_scale;
	Vector2 m_pivot;
	float angle;
};