#include "framework.h"
#include "CButton_move.h"

CButton_move::CButton_move()
{
    m_layer = LAYER::BackGround;
    countNum = 0;
}
CButton_move::~CButton_move() {}

HRESULT CButton_move::Init()
{
    return S_OK;
}

void CButton_move::Update(float deltaTime, float worldTime)
{
	Vector2 PointToVector = Vector2(g_ptMouse) + MG_CAMERA->getCameraPos();

	if (m_rect.CheckCollisionWithPoint(PointToVector))
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
		}
	}
}

void CButton_move::LateUpdate()
{
}

void CButton_move::BackRender(HDC _hdc)
{
}

void CButton_move::Render(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);
}

void CButton_move::FrontRender(HDC _hdc)
{
}

void CButton_move::Release()
{
	GameObject::Release();
}

void CButton_move::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}