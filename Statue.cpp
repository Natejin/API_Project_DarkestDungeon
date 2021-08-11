#include "framework.h"
#include "Statue.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
Statue::Statue()
{
}
Statue::~Statue()
{
}
HRESULT Statue::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::statue_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::statue_char, m_transform);    
    m_transform->m_pivot = Vector2(-0.095, -0.095);
  
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void Statue::Update(float deltaTime, float worldTime)
{
}

void Statue::LateUpdate()
{
}

void Statue::BackRender(HDC _hdc)
{
}

void Statue::Render(HDC _hdc)
{
}

void Statue::FrontRender(HDC _hdc)
{
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
}

void Statue::Release()
{
  
}
