#include "framework.h"
#include "CMinimapButton.h"

CMinimapButton::CMinimapButton()
{
	m_layer = LAYER::UIButton;
}

CMinimapButton::~CMinimapButton()
{
}

HRESULT CMinimapButton::Init()
{
	return S_OK;
}

void CMinimapButton::Update(float deltaTime, float worldTime)
{
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyUp(VK_LBUTTON))
		{
			if (canTriggerClick)
			{
				m_triggerWhenUp();
			}
		}
	}
}

void CMinimapButton::LateUpdate()
{
}

void CMinimapButton::BackRender(HDC _hdc)
{
}

void CMinimapButton::Render(HDC _hdc)
{
	
}

void CMinimapButton::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}
