#include "framework.h"
#include "Tavern.h"

Tavern::Tavern()
{
}

Tavern::~Tavern()
{
}

HRESULT Tavern::Init()
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

void Tavern::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
}

void Tavern::LateUpdate()
{
}

void Tavern::BackRender(HDC _hdc)
{
}

void Tavern::Render(HDC _hdc)
{
}

void Tavern::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        MG_IMAGE->findImage("tavern.character.bg")->render(_hdc);
        MG_IMAGE->findImage("tavern.character")->render(_hdc);
        m_quick->isActive = true;

    }
}

void Tavern::Release()
{
}

void Tavern::Setquick()
{   
    m_quick->SetTriggerWhenClick(this, &Tavern::FinishUI);
}

void Tavern::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
