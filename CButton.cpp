#include "framework.h"
#include "CButton.h"
#include "DungeonScene.h"

CButton::CButton()
{
	m_layer = LAYER::UIButton;
	countNum = 0;
	canTriggerDown = false;
	canTriggerUp = false;
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
	if (m_collider->new_CheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->IsDownLMB())
		{
			if (canTriggerDown)
			{
				m_triggerWhenDown();
			}
	
		}
	}

	if (m_collider->new_CheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->IsUpLMB())
		{
			if (canTriggerUp)
			{
				m_triggerWhenUp();
			}
			
		}
		if (MG_INPUT->IsUpLMB())
		{
			if (canTriggerUp)
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
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}
