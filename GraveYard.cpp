#include "framework.h"
#include "GraveYard.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
GraveYard::GraveYard()
{
}

GraveYard::~GraveYard()
{
}

HRESULT GraveYard::Init()
{
    CEst_UI::Init();
    isActive = false;
  
    m_windowPanelBG = new CSpriteRenderer(IMAGE::graveyard_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::graveyard_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
   
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void GraveYard::Update(float deltaTime, float worldTime)
{
}

void GraveYard::LateUpdate()
{
}

void GraveYard::BackRender(HDC _hdc)
{
}

void GraveYard::Render(HDC _hdc)
{
}

void GraveYard::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void GraveYard::Release()
{
   
}
