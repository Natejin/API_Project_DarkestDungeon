#include "framework.h"
#include "CampingTrainer.h"
#include"CButton.h"
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
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);
    m_quick->AddColliderBox(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;
    
    m_windowPanelBG = new CSpriteRenderer(IMAGE::camping_trainer_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::camping_trainer_char, m_transform);
    m_transform->m_pivot = Vector2(0, 0);

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
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
}

void CampingTrainer::Release()
{
}

void CampingTrainer::Setquick()
{
   
    m_quick->SetTriggerWhenUp(this, &CampingTrainer::FinishUI);
}

void CampingTrainer::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;
}
