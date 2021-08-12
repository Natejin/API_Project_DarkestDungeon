#include "framework.h"
#include "CUIPanel_Sanitarium.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
CUIPanel_Sanitarium::CUIPanel_Sanitarium()
{
}
CUIPanel_Sanitarium::~CUIPanel_Sanitarium()
{
}
HRESULT CUIPanel_Sanitarium::Init()
{
    CEst_UI::Init();
    isActive = false;
   
    m_windowPanelBG = new CSpriteRenderer(IMAGE::sanitarium_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::sanitarium_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_Sanitarium::Update(float deltaTime, float worldTime)
{

}

void CUIPanel_Sanitarium::LateUpdate()
{
}

void CUIPanel_Sanitarium::BackRender(HDC _hdc)
{
}

void CUIPanel_Sanitarium::Render(HDC _hdc)
{
}

void CUIPanel_Sanitarium::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void CUIPanel_Sanitarium::Release()
{
    
}
