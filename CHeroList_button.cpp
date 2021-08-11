#include "framework.h"
#include "CHeroList_button.h"
#include "TownScene.h"

CHeroList_button::CHeroList_button()
{
	m_layer = LAYER::UIButton;
	canTriggerDrag = false;
	isClick = false;
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
	if (clickable)
	{
		if (m_rect.CheckCollisionWithPoint(m_ptMouse))
		{
			
			if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
			{
				clickable = false;
				isDragging = true;
				originPos = m_transform->m_pos;

			}
		}
	}
	
	if (townScene->isDrag&&isDragging)
	{
		m_transform->m_pos = m_ptMouse;
		m_rect.l = m_ptMouse.x - buttonSize.x * m_transform->m_pivot.x;
		m_rect.t = m_ptMouse.y - buttonSize.y * m_transform->m_pivot.y;
		m_rect.r = m_ptMouse.x + buttonSize.x * (1 - m_transform->m_pivot.x);
		m_rect.b = m_ptMouse.y + buttonSize.y * (1 - m_transform->m_pivot.y);
	}
	if (MG_INPUT->isOnceKeyUp(VK_LBUTTON))
	{
		isDragging = false;
		m_transform->m_pos = originPos;

		m_rect.l = m_transform->m_pos.x - buttonSize.x * m_transform->m_pivot.x;
		m_rect.t = m_transform->m_pos.y - buttonSize.y * m_transform->m_pivot.y;
		m_rect.r = m_transform->m_pos.x + buttonSize.x * (1 - m_transform->m_pivot.x);
		m_rect.b = m_transform->m_pos.y + buttonSize.y * (1 - m_transform->m_pivot.y);

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

	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		Rectangle(_hdc,m_rect.l, m_rect.t, m_rect.r, m_rect.b);
	}
}
void CHeroList_button::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
	buttonSize = Vector2(width, height);
}