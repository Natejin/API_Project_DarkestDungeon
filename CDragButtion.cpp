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
		{	
			//누르고 있는 버튼을 마우스좌표따라 이동할수있게 변경해야한다.
			//Mouse_Move();
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
	m_spriteRenderer->RenderUI(_hdc);
}

void CDragButtion::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x - width * m_transform->m_pivot.x;
	m_rect.t = m_transform->m_pos.y - height * m_transform->m_pivot.y;
	m_rect.r = m_transform->m_pos.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_transform->m_pos.y + height * (1 - m_transform->m_pivot.y);
}

void CDragButtion::Mouse_Move(float width, float height)
{	
	//마우스 좌클릭을 하였을때 그 버튼의 이미지와 rect가 
	//내가 이동하는 좌표로 따라 와서 
	//내가 놓았을떄 그 좌표값이 적절한 위치라면 
	//떨어지게끔 만들어야 한다. 
	m_rect.l = m_ptMouse.x - width + m_transform->m_pivot.x;
	m_rect.t = m_ptMouse.y - height * m_transform->m_pivot.y;
	m_rect.r = m_ptMouse.x + width * (1 - m_transform->m_pivot.x);
	m_rect.b = m_ptMouse.y + height * (1 - m_transform->m_pivot.y);
}

