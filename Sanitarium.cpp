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
    //나가기버튼
<<<<<<< Updated upstream
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
=======
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 550, 100);
>>>>>>> Stashed changes
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;
<<<<<<< Updated upstream
=======

    m_windowPanelBG = new CSpriteRenderer(IMAGE::sanitarium_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::sanitarium_char, m_transform);
    m_transform->m_pivot = Vector2(0, 0);

>>>>>>> Stashed changes
    return S_OK;
}

void Sanitarium::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();

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
        m_quick->isActive = true;
    }
  
}

void Sanitarium::Release()
{
}

void Sanitarium::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &Sanitarium::FinishUI);
}

void Sanitarium::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
