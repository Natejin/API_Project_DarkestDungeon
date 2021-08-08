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
    Setquick();
    return S_OK;
}

void CampingTrainer::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
}

void CampingTrainer::Release()
{
}

void CampingTrainer::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &CampingTrainer::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void CampingTrainer::FinishUI()
{

    isUi = false;
    isUI = false;
}
