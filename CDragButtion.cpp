#include "framework.h"
#include "CDragButtion.h"

CDragButtion::CDragButtion()
{
    m_layer = LAYER::UIButton;

}

CDragButtion::~CDragButtion()
{
}

HRESULT CDragButtion::Init()
{
    return S_OK;
}

void CDragButtion::Update(float deltaTime, float worldTime)
{
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isStayKeyDown(VK_LBUTTON)) 
		{	// �¹�ư�� ������ �ִ´� ->��´�. ->����������.
			//���콺�� �����̸� ������ ��ġ�� ��ü�� ���� �̵��ؾ� �Ѵ�.
			//�׷��� �ű�� �����̵� �̹����� �Ű������ϴµ�.
			//�̰� ��� �޾� ���°�.
			m_triggerWhenClick();
		}
	}
	

}

void CDragButtion::LateUpdate()
{
}

void CDragButtion::BackRender(HDC _hdc)
{
}

void CDragButtion::Render(HDC _hdc)
{
}

void CDragButtion::FrontRender(HDC _hdc)
{
}

void CDragButtion::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
}
