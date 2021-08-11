#include "framework.h"
#include "Tavern.h"
#include"CButton.h"
#include"CHeroList_button.h"
Tavern::Tavern()
{
}

Tavern::~Tavern()
{
}

HRESULT Tavern::Init()
{
    isActive = false;

    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->SetButtonSize(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &Tavern::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);

    m_windowPanelBG = new CSpriteRenderer(IMAGE::tavern_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::tavern_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void Tavern::Update(float deltaTime, float worldTime)
{
}

void Tavern::LateUpdate()
{
}

void Tavern::BackRender(HDC _hdc)
{
}

void Tavern::Render(HDC _hdc)
{
}

void Tavern::FrontRender(HDC _hdc)
{
    if (!m_HeroList_button->GetDrag())
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
}

void Tavern::Release()
{
}

void Tavern::Setquick()
{   
}

void Tavern::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
