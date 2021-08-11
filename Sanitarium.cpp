#include "framework.h"
#include "Sanitarium.h"
#include"CButton.h"
#include"CHeroList_button.h"
Sanitarium::Sanitarium()
{
}
Sanitarium::~Sanitarium()
{
}
HRESULT Sanitarium::Init()
{
    isActive = false;
    //나가기버튼
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->SetButtonSize(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &Sanitarium::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);

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
 
    if (!m_HeroList_button->GetDrag())
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
  
}

void Sanitarium::Release()
{
}

void Sanitarium::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
