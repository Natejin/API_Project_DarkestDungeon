#include "framework.h"
#include "CUIPanel_StageCoach.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CUIPanel_StageCoach::CUIPanel_StageCoach()
{
}

CUIPanel_StageCoach::~CUIPanel_StageCoach()
{
}
HRESULT CUIPanel_StageCoach::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::stage_coach_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::stage_coach_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void CUIPanel_StageCoach::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_StageCoach::LateUpdate()
{
}

void CUIPanel_StageCoach::BackRender(HDC _hdc)
{
}

void CUIPanel_StageCoach::Render(HDC _hdc)
{
}

void CUIPanel_StageCoach::FrontRender(HDC _hdc)
{
    m_windowPanelBG->Render(_hdc);
    m_windowPanelChar->Render(_hdc);
    m_quit->isActive = true;
}

void CUIPanel_StageCoach::Release()
{
    
}
