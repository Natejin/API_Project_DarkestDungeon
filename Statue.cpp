#include "framework.h"
#include "Statue.h"
#include"CButton.h"

Statue::Statue()
{
}

Statue::~Statue()
{
}

HRESULT Statue::Init()
{
    isUi = false;
    //나가기버튼
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::statue_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::statue_char, m_transform);    
    m_transform->m_pivot = Vector2(0, 0);

    return S_OK;
}

void Statue::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
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
    if (isUI)
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
}

void Statue::Release()
{
}

void Statue::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &Statue::FinishUI);
}

void Statue::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
