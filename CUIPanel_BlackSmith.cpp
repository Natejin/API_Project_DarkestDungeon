#include "framework.h"
#include "CButton.h"
#include "CUIPanel_BlackSmith.h"
#include"CHeroList_button.h"
CUIPanel_BlackSmith::CUIPanel_BlackSmith()
{
    m_layer = LAYER::UI;
   
}

CUIPanel_BlackSmith::~CUIPanel_BlackSmith()
{
}

HRESULT CUIPanel_BlackSmith::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::blacksmith_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::blacksmith_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_heroButton = new CHeroList_button();
    return S_OK;
}
void CUIPanel_BlackSmith::Update(float deltaTime, float worldTime)
{
  
}

void CUIPanel_BlackSmith::LateUpdate()
{
}

void CUIPanel_BlackSmith::BackRender(HDC _hdc)
{
}

void CUIPanel_BlackSmith::Render(HDC _hdc)
{
}

void CUIPanel_BlackSmith::FrontRender(HDC _hdc)
{
      m_windowPanelBG->Render(_hdc);
      m_windowPanelChar->Render(_hdc);
      m_quick->isActive = true;
}

void CUIPanel_BlackSmith::Release()
{
  
}
