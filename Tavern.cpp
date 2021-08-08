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
    Setquick();
    return S_OK;
}

void Tavern::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
}

void Tavern::Release()
{
}

void Tavern::Setquick()
{   
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &Tavern::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void Tavern::FinishUI()
{
    isUi = false;
    isUI = false;
}
