#pragma once
#include "CComponent.h"

class CCollider : public CComponent
{
private:
	class CTransform* trans;

public:
	COLLIDERTYPE m_colliderType;
	Vector2 m_pos;
	Rect rect;

	CCollider();
	~CCollider();

	void SetTrans(class CTransform* _trans) { trans = _trans; }
	void SetRectAndTrans(CTransform* _trans, int width, int height);

	bool CheckXCollision(int x);

	bool CheckColliderBoxWithPoint(Vector2 pos);
	bool CheckColliderBoxWithPoint(POINT pos);
};