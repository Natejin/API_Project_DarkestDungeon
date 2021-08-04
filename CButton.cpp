#include "framework.h"
#include "CButton.h"
#include "DungeonScene.h"

CButton::CButton()
{
	m_layer = LAYER::UI;
	countNum = 0;
	m_rect.l = 0;
	m_rect.t = 0;
	m_rect.r = 0;
	m_rect.b = 0;
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
<<<<<<< Updated upstream
	/*if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
=======
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
>>>>>>> Stashed changes
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
		}
	}*/

	if (m_rect.CheckCollisionWithPoint(m_ptMouse))

	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
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
	//assert(m_image != nullptr);
	//m_image->renderUI(_hdc, m_transform);

	//Rectangle(_hdc, m_rect.l, m_rect.t, m_rect.r, m_rect.b);
<<<<<<< Updated upstream
=======

	//char str[256];
	//string strFrame;
	//sprintf_s(str, "ButtonTest : %f, %f,%f,%f", m_rect.l, m_rect.t, m_rect.r, m_rect.b);
	//TextOut(_hdc, textPos.x, textPos.y, str, strlen(str));

>>>>>>> Stashed changes
}

void CButton::Release()
{
	GameObject::Release();
}

void CButton::SetButtonSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}




