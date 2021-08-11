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
	if (!selDragButton)
	{
		if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
		{
			if (MG_INPUT->IsDownLMB())
			{
				selDragButton = this;
				selKeyIndex = VK_LBUTTON;
				if (canTriggerDown)
				{
					m_triggerWhenDown();
				}
			}
		}
	}
	else {
		if (MG_INPUT->isOnceKeyUp(VK_LBUTTON))
		{
			if (canTriggerUp)
			{
				m_triggerWhenUp();
			}
			selDragButton = nullptr;
			selKeyIndex = -1;
		}
	}
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

//void CDragButton::SetButtonSize(float width, float height)
//{
//	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
//	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
//	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
//	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
//	buttonSize = Vector2(width, height);
//}

void CDragButton::Mouse_Move()
{
	//���콺 ��Ŭ���� �Ͽ����� �� ��ư�� �̹����� rect�� 
	//���� �̵��ϴ� ��ǥ�� ���� �ͼ� 
	//���� �������� �� ��ǥ���� ������ ��ġ��� 
	//�������Բ� ������ �Ѵ�. 

	m_transform->m_pos = m_ptMouse;
	//m_rect.l = m_ptMouse.x - buttonSize.x * m_transform->m_pivot.x;
	//m_rect.t = m_ptMouse.y - buttonSize.y * m_transform->m_pivot.y;
	//m_rect.r = m_ptMouse.x + buttonSize.x * (1 - m_transform->m_pivot.x);
	//m_rect.b = m_ptMouse.y + buttonSize.y * (1 - m_transform->m_pivot.y);
}
