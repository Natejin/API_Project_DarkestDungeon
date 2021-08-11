#include "framework.h"
#include "GraveYard.h"
#include"CButton.h"
#include"CHeroList_button.h"
GraveYard::GraveYard()
{
}

GraveYard::~GraveYard()
{
}

HRESULT GraveYard::Init()
{
    isActive = false;
    //나가기버튼
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->AddColliderBox(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &GraveYard::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
   
    m_windowPanelBG = new CSpriteRenderer(IMAGE::graveyard_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::graveyard_char, m_transform);

    m_transform->m_pivot = Vector2(-0.095, -0.095);
   
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void GraveYard::Update(float deltaTime, float worldTime)
{
  
}

void GraveYard::LateUpdate()
{
}

void GraveYard::BackRender(HDC _hdc)
{
}

void GraveYard::Render(HDC _hdc)
{
}

void GraveYard::FrontRender(HDC _hdc)
{
   
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
   
}

void GraveYard::Release()
{
}

void GraveYard::Setquick()
{
   
}

void GraveYard::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
