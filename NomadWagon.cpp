#include "framework.h"
#include "NomadWagon.h"
#include"CButton.h"

NomadWagon::NomadWagon()
{
}

NomadWagon::~NomadWagon()
{
}

HRESULT NomadWagon::Init()
{   
    isUi = false;
    //나가기버튼
    m_quick = new CButton();

    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);

    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::nomad_wagon_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::nomad_wagon_char, m_transform);

    m_transform->m_pivot = Vector2(0, 0);


    return S_OK;
}

void NomadWagon::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();

}

void NomadWagon::LateUpdate()
{
}

void NomadWagon::BackRender(HDC _hdc)
{
}

void NomadWagon::Render(HDC _hdc)
{
}

void NomadWagon::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;

    }
   
}

void NomadWagon::Release()
{
}

void NomadWagon::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &NomadWagon::FinishUI);
}

void NomadWagon::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
