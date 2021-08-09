#include "framework.h"
#include "CButton.h"
#include "BlackSmith.h"

BlackSmith::BlackSmith()
{
    m_layer = LAYER::UI;
    m_quick2 = new CButton();
}

BlackSmith::~BlackSmith()
{
}

HRESULT BlackSmith::Init()
{
    isUi = false;
<<<<<<< Updated upstream
    
    m_quick2->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
=======

    m_quick2 = new CButton();
    m_quick2->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);
>>>>>>> Stashed changes
    m_quick2->SetButtonSize(200, 200);
    m_quick2->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick2);
    m_quick2->isActive = false;

<<<<<<< Updated upstream
=======
    m_windowPanelBG = new CSpriteRenderer(IMAGE::blacksmith_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::blacksmith_char, m_transform);
    m_transform->m_pivot = Vector2(0, 0);

>>>>>>> Stashed changes
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
