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
		{	// 좌버튼을 누르고 있는다 ->잡는다. ->움직여야지.
			//마우스가 움직이면 움직인 위치로 객체도 같이 이동해야 한다.
			//그러면 옮기는 도형이든 이미지든 옮겨져야하는데.
			//이건 어디서 받아 오는가.
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
