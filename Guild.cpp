#include "framework.h"
#include "Guild.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
Guild::Guild()
{
}

Guild::~Guild()
{
}

HRESULT Guild::Init()
{
    CEst_UI::Init();
    isActive = false;
   
    m_windowPanelBG = new CSpriteRenderer(IMAGE::guild_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::guild_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
   
    m_HeroList_button = new CHeroList_button();
    return S_OK;
}

void Guild::Update(float deltaTime, float worldTime)
{
   
}

void Guild::LateUpdate()
{
}

void Guild::BackRender(HDC _hdc)
{
}

void Guild::Render(HDC _hdc)
{
}

void Guild::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quick->isActive = true;
}

void Guild::Release()
{
  
}
