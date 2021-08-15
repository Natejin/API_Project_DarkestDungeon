#include "framework.h"
#include "CUIPanel_GraveYard.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_GraveYard::CUIPanel_GraveYard()
{
}

CUIPanel_GraveYard::~CUIPanel_GraveYard()
{
}

HRESULT CUIPanel_GraveYard::Init()
{
    CEst_UI::Init();
    isActive = false;
  
    m_windowPanelBG = new CSpriteRenderer(IMAGE::graveyard_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::graveyard_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
   
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_GraveYard::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_GraveYard::LateUpdate()
{
}

void CUIPanel_GraveYard::BackRender(HDC _hdc)
{
}

void CUIPanel_GraveYard::Render(HDC _hdc)
{
}

void CUIPanel_GraveYard::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quit->isActive = true;
}

void CUIPanel_GraveYard::Release()
{
   
}
