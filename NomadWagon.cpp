#include "framework.h"
#include "NomadWagon.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
NomadWagon::NomadWagon()
{
}

NomadWagon::~NomadWagon()
{
}

HRESULT NomadWagon::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::nomad_wagon_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::nomad_wagon_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void NomadWagon::Update(float deltaTime, float worldTime)
{
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
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void NomadWagon::Release()
{
}