#include "framework.h"
#include "CButton.h"
#include "DungeonScene.h"

CButton::CButton()
{
	m_layer = LAYER::UIButton;
	countNum = 0;
	canTriggerClick = false;
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
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyClick(VK_LBUTTON))
		{
			if (canTriggerClick)
			{
				m_triggerWhenUp();
			}
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
	m_spriteRenderer->RenderUI(_hdc);

#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_rect);
	}

#endif // _DEBUG
}

void CButton::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
}

void CButton::SetButtonSize()
{
	if (m_spriteRenderer)
	{
		Vector2 imageSize = m_spriteRenderer->GetImageSize();
		m_rect.l = m_transform->m_pos.x - imageSize.x * m_transform->m_pivot.x;
		m_rect.t = m_transform->m_pos.y - imageSize.y * m_transform->m_pivot.y;
		m_rect.r = m_transform->m_pos.x + imageSize.x * (1 - m_transform->m_pivot.x);
		m_rect.b = m_transform->m_pos.y + imageSize.y * (1 - m_transform->m_pivot.y);
	}
}