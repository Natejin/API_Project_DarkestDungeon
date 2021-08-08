#include "framework.h"
#include "BlackSmith.h"

BlackSmith::BlackSmith()
{
    m_layer = LAYER::UI;
}

BlackSmith::~BlackSmith()
{
}

HRESULT BlackSmith::Init()
{
    isUi = false;
    Setquick();
    return S_OK;
}

void BlackSmith::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
}

void BlackSmith::LateUpdate()
{
}

void BlackSmith::BackRender(HDC _hdc)
{
}

void BlackSmith::Render(HDC _hdc)
{
}

void BlackSmith::FrontRender(HDC _hdc)
{
    if (isUI == true)
    {
        MG_IMAGE->findImage("blacksmith.character.bg")->render(_hdc);
        MG_IMAGE->findImage("blacksmith.character")->render(_hdc);
    }
}

void BlackSmith::Release()
{
}

void BlackSmith::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &BlackSmith::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void BlackSmith::FinishUI()
{
    isUi = false;
    isUI = false;
}
