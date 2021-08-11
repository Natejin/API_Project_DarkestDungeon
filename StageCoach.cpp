#include "framework.h"
#include "StageCoach.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
StageCoach::StageCoach()
{
}

StageCoach::~StageCoach()
{
}
HRESULT StageCoach::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::stage_coach_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::stage_coach_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void StageCoach::Update(float deltaTime, float worldTime)
{
}

void StageCoach::LateUpdate()
{
}

void StageCoach::BackRender(HDC _hdc)
{
}

void StageCoach::Render(HDC _hdc)
{
}

void StageCoach::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void StageCoach::Release()
{
    
}
