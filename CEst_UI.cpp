#include "framework.h"
#include "CEst_UI.h"
#include "CSpriteRenderer.h"

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
	
}

void CEst_UI::LateUpdate()
{
}

void CEst_UI::BackRender(HDC _hdc)
{
}

void CEst_UI::Render(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
}

void CEst_UI::FrontRender(HDC _hdc)
{
	//assert(m_image != nullptr);
	//m_image->renderUI(_hdc, m_transform);

}

void CEst_UI::Release()
{
	GameObject::Release();
	SAFE_DELETE(m_windowPanelBG);
	SAFE_DELETE(m_windowPanelChar);
}

