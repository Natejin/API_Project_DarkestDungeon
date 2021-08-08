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
    Setquick();
    return S_OK;
}

void GraveYard::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
  
}

void GraveYard::Release()
{
}

void GraveYard::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &GraveYard::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void GraveYard::FinishUI()
{
    isUi = false;
    isUI = false;
}
