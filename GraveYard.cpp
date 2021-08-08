#include "framework.h"
#include "GraveYard.h"

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
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;

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
        MG_IMAGE->findImage("graveyard.character.bg")->render(_hdc);
        MG_IMAGE->findImage("graveyard.character")->render(_hdc);
        m_quick->isActive = true;

    }
  
}

void GraveYard::Release()
{
}

void GraveYard::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &GraveYard::FinishUI);
}

void GraveYard::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
