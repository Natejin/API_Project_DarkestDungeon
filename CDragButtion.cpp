#include "framework.h"
#include "CDragButtion.h"

CDragButton::CDragButton()
{
    m_layer = LAYER::UIButton;

}

CDragButton::~CDragButton()
{
}

HRESULT CDragButton::Init()
{
    return S_OK;
}

void CDragButton::Update(float deltaTime, float worldTime)
{
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isStayKeyDown(VK_LBUTTON)) 
		{	
			//������ �ִ� ��ư�� ���콺��ǥ���� �̵��Ҽ��ְ� �����ؾ��Ѵ�.
			//Mouse_Move();
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

void CDragButton::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
}

void CDragButton::Mouse_Move(float width, float height)
{	
	//���콺 ��Ŭ���� �Ͽ����� �� ��ư�� �̹����� rect�� 
	//���� �̵��ϴ� ��ǥ�� ���� �ͼ� 
	//���� �������� �� ��ǥ���� ������ ��ġ��� 
	//�������Բ� ������ �Ѵ�. 
	m_rect.l = m_ptMouse.x - width + m_transform->m_pivot.x;
	m_rect.t = m_ptMouse.y - height * m_transform->m_pivot.y;
	m_rect.r = m_ptMouse.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_ptMouse.y + height * (1 - m_transform->m_pivot.y);
}

