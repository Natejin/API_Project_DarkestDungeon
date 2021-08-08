#include "framework.h"
#include "CampingTrainer.h"

CampingTrainer::CampingTrainer()
{
}

CampingTrainer::~CampingTrainer()
{
}

HRESULT CampingTrainer::Init()
{
    isUi = false;
    //나가기버튼
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;

    return S_OK;
}

void CampingTrainer::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();

}

void CampingTrainer::LateUpdate()
{
}

void CampingTrainer::BackRender(HDC _hdc)
{
}

void CampingTrainer::Render(HDC _hdc)
{
}

void CampingTrainer::FrontRender(HDC _hdc)
{
    if (isUI == true)
    {
        MG_IMAGE->findImage("camping_trainer.character.bg")->render(_hdc);
        MG_IMAGE->findImage("camping_trainer.character")->render(_hdc);
        m_quick->isActive = true;
    }
}

void CampingTrainer::Release()
{
}

void CampingTrainer::Setquick()
{
   
    m_quick->SetTriggerWhenClick(this, &CampingTrainer::FinishUI);
}

void CampingTrainer::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;
}
