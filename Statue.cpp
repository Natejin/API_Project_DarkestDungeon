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
    m_windowPanelBG = new CSpriteRenderer(IMAGE::statue_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::statue_char, m_transform);    
    m_transform->m_pivot = Vector2(0, 0);

>>>>>>> Stashed changes
    return S_OK;
}

void Statue::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
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
        m_quick->isActive = true;
    }
}

void Statue::Release()
{
}

void Statue::Setquick()
{
    m_quick->SetTriggerWhenClick(this, &Statue::FinishUI);
}

void Statue::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
