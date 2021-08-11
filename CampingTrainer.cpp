#include "framework.h"
#include "CampingTrainer.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
CampingTrainer::CampingTrainer()
{
}

CampingTrainer::~CampingTrainer()
{
}

HRESULT CampingTrainer::Init()
{
    CEst_UI::Init();
    isActive = false;
  
    m_windowPanelBG = new CSpriteRenderer(IMAGE::camping_trainer_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::camping_trainer_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
  
    m_HeroList_button = new CHeroList_button();

    return S_OK;
}

void CampingTrainer::Update(float deltaTime, float worldTime)
{
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
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void CampingTrainer::Release()
{
   
}
