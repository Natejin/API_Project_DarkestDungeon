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
    Setquick();
    return S_OK;
}

void StageCoach::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
}

void StageCoach::Release()
{
}

void StageCoach::Setquick()
{
    //�������ư
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &StageCoach::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void StageCoach::FinishUI()
{
    isUi = false;
    isUI = false;
}
