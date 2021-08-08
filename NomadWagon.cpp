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
    Setquick();
    return S_OK;
}

void NomadWagon::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
   
}

void NomadWagon::Release()
{
}

void NomadWagon::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &NomadWagon::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void NomadWagon::FinishUI()
{
    isUi = false;
    isUI = false;
}
