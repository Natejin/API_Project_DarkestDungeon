#include "framework.h"
#include "GraveYard.h"
#include"CButton.h"

GraveYard::GraveYard()
{
}

GraveYard::~GraveYard()
{
}

HRESULT GraveYard::Init()
{
    isUi = false;
    //나가기버튼
    m_quick = new CButton();

    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);

    m_quick->AddColliderBox(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::graveyard_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::graveyard_char, m_transform);

    m_transform->m_pivot = Vector2(0, 0);


    return S_OK;
}

void GraveYard::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
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
    if (isUI)
    {
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;

    }
  
}

void GraveYard::Release()
{
}

void GraveYard::Setquick()
{
    m_quick->SetTriggerWhenUp(this, &GraveYard::FinishUI);
}

void GraveYard::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
