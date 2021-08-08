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

void CCollider::SetRectAndTrans(CTransform* _trans, int width, int height)
{
	trans = _trans;
	rect.SetRect(_trans->m_pos.x, _trans->m_pos.y, _trans->m_pos.x + width, _trans->m_pos.y + height);
}

bool CCollider::CheckXCollision(int x)
{
	if (rect.l < x && rect.r > x)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(Vector2 _pos) 
{
	if (rect.l < _pos.x &&
		rect.r > _pos.x &&
		rect.t < _pos.y &&
		rect.b > _pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(Vector2 _pos) 
{
	if (rect.l < _pos.x &&
		rect.r > _pos.x &&
		rect.t < _pos.y &&
		rect.b > _pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(POINT _pos) 
{
	if (rect.l < _pos.x &&
		rect.r > _pos.x &&
		rect.t < _pos.y &&
		rect.b > _pos.y)
	{
		return true;
	}
	else return false;
}