#include "framework.h"
#include "CHeroList_button.h"
#include"CHero.h"

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
	originPos = Vector2(0, 0);
	SetTriggerWhenDrag(this, &CHeroList_button::DragHeroList);

	m_hero = new CHero();
	return S_OK;

}

void CHeroList_button::Update(float deltaTime, float worldTime)
{
	if (!selDragButton)
	{
		if (m_collider->new_CheckColliderBoxWithPoint(g_ptMouse))
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
			if (canTriggerUp)
			{
				m_triggerWhenUp();
			}
			else
			{
				m_transform->m_pos = originPos;
				selDragButton = nullptr;
				selKeyIndex = -1;
			}
			
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
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
	//for (size_t i = 0; i < MG_GAME->m_partyOrigin.size(); i++)
	//{
	//	char str[256];
	//	sprintf_s(str, "(%d , %d)",(int)originPos.x, (int)originPos.y);
	//	TextOut(_hdc, 500, 500+i*50, str, strlen(str));
	//	//OutputDebugString(TEXT(str));
	//}
	
}

void CHeroList_button::DragHeroList()
{
	m_transform->m_pos += CInputManager::getSingleton()->GetptDeltaMouse();
}

//void CHeroList_button::AddColliderBox(float width, float height)
//{
//	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
//	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
//	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
//	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
//	buttonSize = Vector2(width, height);
//}
