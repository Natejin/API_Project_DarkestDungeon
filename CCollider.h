#pragma once
#include "CComponent.h"

class CCollider : public CComponent
{
private:

public:
	COLLIDERTYPE m_colliderType;
	Vector2 m_pos;
	Rect rect;

	CCollider();
	~CCollider();

	void SetRect(float l, float t, float r, float b);

	bool CheckXCollision(int x);

	bool CheckColliderBoxWithPoint(Vector2 pos);
	bool CheckColliderBoxWithPoint(POINT pos);
};