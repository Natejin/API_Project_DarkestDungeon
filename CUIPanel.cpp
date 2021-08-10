#include "framework.h"
#include "CUIPanel.h"

CUIPanel::CUIPanel()
{
    m_layer = LAYER::UI;
}

CUIPanel::~CUIPanel()
{
}

HRESULT CUIPanel::Init()
{
    UseRender();
    m_transform->m_pivot = Vector2(0, 0);
    return S_OK;
}

void CUIPanel::Update(float deltaTime, float worldTime)
{
}

void CUIPanel::LateUpdate()
{
}

void CUIPanel::BackRender(HDC _hdc)
{
    if (useBackRender) m_spriteRenderer->RenderUI(_hdc);
}

void CUIPanel::Render(HDC _hdc)
{
    if (useRender) m_spriteRenderer->RenderUI(_hdc);
}

void CUIPanel::FrontRender(HDC _hdc)
{
    if (useFrontRender) m_spriteRenderer->RenderUI(_hdc);
}

void CUIPanel::UseFrontRender()
{
    useFrontRender = true;
    useRender = false;
    useBackRender = false;
}

void CUIPanel::UseRender()
{
    useFrontRender = false;
    useRender = true;
    useBackRender = false;
}

void CUIPanel::UseBackRender()
{
    useFrontRender = false;
    useRender = false;
    useBackRender = true;
}
