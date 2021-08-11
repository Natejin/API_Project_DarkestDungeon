#include "framework.h"
#include "CButton.h"
#include "BlackSmith.h"
#include"CHeroList_button.h"
BlackSmith::BlackSmith()
{
    m_layer = LAYER::UI;
   
}

BlackSmith::~BlackSmith()
{
}

HRESULT BlackSmith::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::blacksmith_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::blacksmith_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_heroButton = new CHeroList_button();
    return S_OK;
}
void BlackSmith::Update(float deltaTime, float worldTime)
{
  
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
      m_windowPanelBG->Render(_hdc);
      m_windowPanelChar->Render(_hdc);
      m_quick->isActive = true;
}

void BlackSmith::Release()
{
  
}
