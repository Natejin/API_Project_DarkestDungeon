#include "framework.h"
#include "CButton.h"
#include "DungeonScene.h"

CButton::CButton()
{
	m_layer = LAYER::UI;
	countNum = 0;
}

CButton::~CButton()
{
}

HRESULT CButton::Init()
{

	return S_OK;
}

void CButton::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
	{
		if (m_rect.CheckCollisionWithPoint(m_ptMouse))
		{
			m_triggerWhenClick();
		}
	}
}



void CButton::LateUpdate()
{
}

void CButton::BackRender(HDC _hdc)
{

}

void CButton::Render(HDC _hdc)
{

}

void CButton::FrontRender(HDC _hdc)
{
	assert(m_image != nullptr);
	m_image->renderUI(_hdc, m_transform);

	Rectangle(_hdc, m_rect.l, m_rect.t, m_rect.r, m_rect.b);
}

void CButton::Release()
{
	GameObject::Release();
}

void CButton::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}




