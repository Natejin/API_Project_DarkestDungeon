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
    
    m_quick2->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick2->SetButtonSize(200, 200);
    m_quick2->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick2);
    m_quick2->isActive = false;

    return S_OK;
}

void BlackSmith::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
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
        m_quick2->isActive = true;
    }
}

void BlackSmith::Release()
{
}

void BlackSmith::Setquick()
{
    //나가기버튼
    m_quick2->SetTriggerWhenClick(this, &BlackSmith::FinishUI);
}

void BlackSmith::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick2->isActive = false;

}
