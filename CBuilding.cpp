#include "framework.h"
#include "CBuilding.h"

CBuilding::CBuilding() 
{
	m_layer = LAYER::Building;
	countNum = 0;
}

CBuilding::~CBuilding()
{
}

HRESULT CBuilding::Init()
{
	m_transform->m_pivot = Vector2(0.5,0.5);
	return S_OK;
}

void CBuilding::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->IsDownLMB())
		{
			if (canTriggerDown)
			{
				m_triggerWhenDown();
			}
		}
	}
}

void CBuilding::LateUpdate()
{
}


void CBuilding::BackRender(HDC _hdc)
{
}

void CBuilding::Render(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);

#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}

void CBuilding::FrontRender(HDC _hdc)
{

}

//void CBuilding::SetButtonSize(float width, float height)
//{
//	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
//	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
//	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
//	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
//}