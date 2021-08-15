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

CCollider::CCollider(CTransform* transform) 
{
	m_transform = transform;
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

void CCollider::SetRect(float l, float t, float r, float b)
{
	rect.SetRect(l, t, r, b);
}

void CCollider::SetColliderBox(Vector2 pos, Vector2 size)
{
	m_pos = pos;
	rect.SetRect(
		pos.x - size.x, 
		pos.y - size.y, 
		pos.x + size.x, 
		pos.y + size.y);
}

bool CCollider::CheckXCollision(int x)
{
	if (rect.l < x && rect.r > x)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(Vector2 pos) 
{
	pos += MG_CAMERA->GetPos();
	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(POINT _pos)
{
	Vector2 pos = _pos;
	pos += MG_CAMERA->GetPos();
	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::UICheckColliderBoxWithPoint(Vector2 pos)
{

	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::UICheckColliderBoxWithPoint(POINT pos)
{
	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}