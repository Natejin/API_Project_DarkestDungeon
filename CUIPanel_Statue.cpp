#include "framework.h"
#include "CUIPanel_Statue.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_Statue::CUIPanel_Statue()
{
}
CUIPanel_Statue::~CUIPanel_Statue()
{
}
HRESULT CUIPanel_Statue::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::statue_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::statue_char, m_transform);    
    m_transform->m_pivot = Vector2(-0.095, -0.095);
  
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_Statue::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_Statue::LateUpdate()
{
}

void CUIPanel_Statue::BackRender(HDC _hdc)
{
}

void CUIPanel_Statue::Render(HDC _hdc)
{
}

void CUIPanel_Statue::FrontRender(HDC _hdc)
{
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quit->isActive = true;
}

void CUIPanel_Statue::Release()
{
  
}
