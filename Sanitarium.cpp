#include "framework.h"
#include "Sanitarium.h"

Sanitarium::Sanitarium()
{
}

Sanitarium::~Sanitarium()
{
}

HRESULT Sanitarium::Init()
{
    isUi = false;
    Setquick();
    return S_OK;
}

void Sanitarium::Update(float deltaTime, float worldTime)
{

    if (isUi == true)
    {

        isUI = true;

    }
}

void Sanitarium::LateUpdate()
{
}

void Sanitarium::BackRender(HDC _hdc)
{
}

void Sanitarium::Render(HDC _hdc)
{
}

void Sanitarium::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        MG_IMAGE->findImage("sanitarium.character.bg")->render(_hdc);
        MG_IMAGE->findImage("sanitarium.character")->render(_hdc);
    }
   
}

void Sanitarium::Release()
{
}

void Sanitarium::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &Sanitarium::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void Sanitarium::FinishUI()
{
    isUi = false;
    isUI = false;
}
