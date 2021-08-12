#include "framework.h"
#include "CDragButtion.h"


CDragButton* CDragButton::selDragButton = nullptr;
int CDragButton::selKeyIndex = -1;
CDragButton::CDragButton()
{
    m_layer = LAYER::UIButton;
	canTriggerDrag = false;
}

CDragButton::~CDragButton()
{
}

HRESULT CDragButton::Init()
{
	m_transform->m_pivot = Vector2(0.5, 0.5);
    return S_OK;
}

void CDragButton::Update(float deltaTime, float worldTime)
{
	/*if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isStayKeyDown(VK_LBUTTON)) 
		{
			if (canTriggerDrag) 
			{	
				m_triggerWhenDrag();
			}
		}
	}*/
}

void CDragButton::LateUpdate()
{
}

void CDragButton::BackRender(HDC _hdc)
{
}

void CDragButton::Render(HDC _hdc)
{
}

void CDragButton::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}
