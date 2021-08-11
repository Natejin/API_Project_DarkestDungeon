#include "framework.h"
#include "CButton.h"
#include "BlackSmith.h"
#include"CHeroList_button.h"
BlackSmith::BlackSmith()
{
    m_layer = LAYER::UI;
   
}

BlackSmith::~BlackSmith()
{
}

HRESULT BlackSmith::Init()
{
    isActive = false;

    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->SetButtonSize(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &BlackSmith::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
   

    m_windowPanelBG = new CSpriteRenderer(IMAGE::blacksmith_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::blacksmith_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_heroButton = new CHeroList_button();
    return S_OK;
}
void BlackSmith::Update(float deltaTime, float worldTime)
{
  
}

void BlackSmith::LateUpdate()
{
}

void BlackSmith::BackRender(HDC _hdc)
{
}

void BlackSmith::Render(HDC _hdc)
{
}

void BlackSmith::FrontRender(HDC _hdc)
{
    if (!m_heroButton->GetDrag())
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    }
}

void BlackSmith::Release()
{
}

void BlackSmith::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
