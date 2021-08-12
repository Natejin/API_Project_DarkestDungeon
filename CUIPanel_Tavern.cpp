#include "framework.h"
#include "CUIPanel_Tavern.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_Tavern::CUIPanel_Tavern()
{
}

CUIPanel_Tavern::~CUIPanel_Tavern()
{
}

HRESULT CUIPanel_Tavern::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::tavern_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::tavern_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_Tavern::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_Tavern::LateUpdate()
{
}

void CUIPanel_Tavern::BackRender(HDC _hdc)
{
}

void CUIPanel_Tavern::Render(HDC _hdc)
{
}

void CUIPanel_Tavern::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true; 
}

void CUIPanel_Tavern::Release()
{
   
}
