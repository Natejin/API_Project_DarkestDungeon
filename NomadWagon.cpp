#include "framework.h"
#include "NomadWagon.h"

NomadWagon::NomadWagon()
{
}

NomadWagon::~NomadWagon()
{
}

HRESULT NomadWagon::Init()
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

void NomadWagon::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();

}

void NomadWagon::LateUpdate()
{
}

void NomadWagon::BackRender(HDC _hdc)
{
}

void NomadWagon::Render(HDC _hdc)
{
}

void NomadWagon::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        MG_IMAGE->findImage("nomad_wagon.character.bg")->render(_hdc);
        MG_IMAGE->findImage("nomad_wagon.character")->render(_hdc);
        m_quick->isActive = true;

    }
   
}

void NomadWagon::Release()
{
}

void NomadWagon::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &NomadWagon::FinishUI);
}

void NomadWagon::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
