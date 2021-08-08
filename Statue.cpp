#include "framework.h"
#include "Statue.h"

Statue::Statue()
{
}

Statue::~Statue()
{
}

HRESULT Statue::Init()
{
    isUi = false;
    Setquick();
    return S_OK;
}

void Statue::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
}

void Statue::LateUpdate()
{
}

void Statue::BackRender(HDC _hdc)
{
}

void Statue::Render(HDC _hdc)
{
}

void Statue::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        MG_IMAGE->findImage("statue.character.bg")->render(_hdc);
        MG_IMAGE->findImage("statue.character")->render(_hdc);
    }
}

void Statue::Release()
{
}

void Statue::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &Statue::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void Statue::FinishUI()
{

    isUi = false;
    isUI = false;
}
