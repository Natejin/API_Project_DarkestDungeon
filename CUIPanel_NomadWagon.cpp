#include "framework.h"
#include "CUIPanel_NomadWagon.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_NomadWagon::CUIPanel_NomadWagon()
{
}

CUIPanel_NomadWagon::~CUIPanel_NomadWagon()
{
}

HRESULT CUIPanel_NomadWagon::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::nomad_wagon_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::nomad_wagon_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_NomadWagon::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_NomadWagon::LateUpdate()
{
}

void CUIPanel_NomadWagon::BackRender(HDC _hdc)
{
}

void CUIPanel_NomadWagon::Render(HDC _hdc)
{
}

void CUIPanel_NomadWagon::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void CUIPanel_NomadWagon::Release()
{
}