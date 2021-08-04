#include "framework.h"
#include "CCollider.h"

CCollider::CCollider()
{
	rect.l = 0;
	rect.t = 0;
	rect.r = 0;
	rect.b = 0;
	m_pos = Vector2(0, 0);
	m_colliderType = COLLIDERTYPE::BOX;
}

CCollider::~CCollider()
{
	
}

bool CCollider::CheckColliderBoxWithPoint(Vector2 _pos) {
	Vector2 tempPos = trans->m_pos + m_pos;
	if (rect.l + tempPos.x < _pos.x &&
		rect.r + tempPos.x > _pos.x &&
		rect.t + tempPos.y < _pos.y &&
		rect.b + tempPos.y > _pos.y)
	{
		return true;
	}
	return false;
}

bool CCollider::CheckColliderBoxWithPoint(POINT _pos) {
	Vector2 tempPos = trans->m_pos + m_pos;
	if (rect.l + tempPos.x < _pos.x &&
		rect.r + tempPos.x > _pos.x &&
		rect.t + tempPos.y < _pos.y &&
		rect.b + tempPos.y > _pos.y)
	{
		return true;
	}
	return false;
}