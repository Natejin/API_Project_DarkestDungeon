#include "framework.h"
#include "CMinimapButton.h"

CMinimapButton::CMinimapButton()
{
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
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
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
}
