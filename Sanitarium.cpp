#include "framework.h"
#include "Sanitarium.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
Sanitarium::Sanitarium()
{
}
Sanitarium::~Sanitarium()
{
}
HRESULT Sanitarium::Init()
{
    CEst_UI::Init();
    isActive = false;
   
    m_windowPanelBG = new CSpriteRenderer(IMAGE::sanitarium_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::sanitarium_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void Sanitarium::Update(float deltaTime, float worldTime)
{

}

void Sanitarium::LateUpdate()
{
}

void Sanitarium::BackRender(HDC _hdc)
{
}

void Sanitarium::Render(HDC _hdc)
{
}

void Sanitarium::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void Sanitarium::Release()
{
    
}
