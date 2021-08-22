#include "framework.h"
#include "CUIPanel_Guild.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_Guild::CUIPanel_Guild()
{
}

CUIPanel_Guild::~CUIPanel_Guild()
{
}

HRESULT CUIPanel_Guild::Init()
{
    CEst_UI::Init();
    isActive = false;
   
    m_windowPanelBG = new CSpriteRenderer(IMAGE::guild_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::guild_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
   
    //m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_Guild::Update(float deltaTime, float worldTime)
{
   
}

void CUIPanel_Guild::LateUpdate()
{
}

void CUIPanel_Guild::BackRender(HDC _hdc)
{
}

void CUIPanel_Guild::Render(HDC _hdc)
{
}

void CUIPanel_Guild::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quit->isActive = true;
}
