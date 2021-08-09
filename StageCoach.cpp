#include "framework.h"
#include "StageCoach.h"

StageCoach::StageCoach()
{
}

StageCoach::~StageCoach()
{
}

HRESULT StageCoach::Init()
{
    isUi = false;
    //나가기버튼
<<<<<<< Updated upstream
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
=======
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);
>>>>>>> Stashed changes
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;
<<<<<<< Updated upstream
=======

    m_windowPanelBG = new CSpriteRenderer(IMAGE::stage_coach_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::stage_coach_char, m_transform);
    m_transform->m_pivot = Vector2(0, 0);

>>>>>>> Stashed changes
    return S_OK;
}

void StageCoach::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
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
    if (isUI)
    {
        MG_IMAGE->findImage("stage_coach.character.bg")->render(_hdc);
        MG_IMAGE->findImage("stage_coach.character")->render(_hdc);
        m_quick->isActive = true;

    }
}

void StageCoach::Release()
{
}

void StageCoach::Setquick()
{
   
    m_quick->SetTriggerWhenClick(this, &StageCoach::FinishUI);
}

void StageCoach::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
