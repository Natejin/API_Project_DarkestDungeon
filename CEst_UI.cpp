#include "framework.h"
#include "CEst_UI.h"

CEst_UI::CEst_UI()
{
    m_layer = LAYER::UI;
}

CEst_UI::~CEst_UI()
{
}

HRESULT CEst_UI::Init()
{	
    return S_OK;
}

void CEst_UI::Update(float deltaTime, float worldTime)
{
	if (m_rect.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
		}
	}
}

void CEst_UI::LateUpdate()
{
}

void CEst_UI::BackRender(HDC _hdc)
{
}

void CEst_UI::Render(HDC _hdc)
{
	
}

void CEst_UI::FrontRender(HDC _hdc)
{
	//assert(m_image != nullptr);
	//m_image->renderUI(_hdc, m_transform);
	m_spriteRenderer->RenderUI(_hdc);
}

void CEst_UI::Release()
{
	GameObject::Release();
}
