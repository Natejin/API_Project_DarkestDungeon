#include "framework.h"
#include "CHeroList_button.h"

CHeroList_button::CHeroList_button()
{
	m_layer = LAYER::UIButton;
	canTriggerDrag = false;
}

CHeroList_button::~CHeroList_button()
{
}

HRESULT CHeroList_button::Init()
{
	m_transform->m_pivot = Vector2(0.5, 0.5);
	
	m_heroBG = new CSpriteRenderer(IMAGE::rosterelement_res, m_transform);
	m_heroBG->useCustomPos = true;
	m_heroBG->pos = Vector2(130, 0);
	return S_OK;

}

void CHeroList_button::Update(float deltaTime, float worldTime)
{
	if (!selDragButton)
	{
		if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
		{
			if (MG_INPUT->IsDownLMB())
			{
				selDragButton = this;
				selKeyIndex = VK_LBUTTON;
				originPos = m_transform->m_pos;
				if (canTriggerDown)
				{
					m_triggerWhenDown();
				}
			}
		}

	}
	else if (selDragButton == this)
		//else
	{
		if (MG_INPUT->IsUpLMB())
		{
			m_transform->m_pos = originPos;
			if (canTriggerUp)
			{
				m_triggerWhenUp();
			}
			selDragButton = nullptr;
			selKeyIndex = -1;
		}
	}
}

void CHeroList_button::LateUpdate()
{
}

void CHeroList_button::BackRender(HDC _hdc)
{
}

void CHeroList_button::Render(HDC _hdc)
{
}

void CHeroList_button::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
	m_heroBG->RenderUI(_hdc);
}
