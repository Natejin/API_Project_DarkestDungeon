#pragma once
#include "CComponent.h"
#include "GameObject.h"

class CCollider : public CComponent
{
private:
	CTransform* m_transform;
	friend GameObject;

protected:
	CCollider();

public:
	COLLIDERTYPE m_colliderType;
	Vector2 m_pos;
	Rect rect;
	Rect transRect;

	CCollider(CTransform* transform);
	~CCollider();

	void SetRect(float l, float t, float r, float b);
	//void SetTransRect(float l, float t, float r, float b);

	bool CheckXCollision(int x);

	bool CheckColliderBoxWithPoint(Vector2 pos);
	bool CheckColliderBoxWithPoint(POINT pos);

	bool new_CheckColliderBoxWithPoint(Vector2 pos);
	bool new_CheckColliderBoxWithPoint(POINT pos);
};