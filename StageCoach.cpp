#include "framework.h"
#include "StageCoach.h"
#include"CButton.h"
#include"CHeroList_button.h"
StageCoach::StageCoach()
{
}

StageCoach::~StageCoach()
{
}
HRESULT StageCoach::Init()
{
    isActive = false;
    //나가기버튼
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->SetButtonSize(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &StageCoach::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);

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
    if (!m_HeroList_button->GetDrag())
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
}

void StageCoach::Release()
{
}
void StageCoach::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
