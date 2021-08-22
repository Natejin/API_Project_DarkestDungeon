#include "framework.h"
#include "TitleButton.h"

TitleButton::TitleButton() {}
TitleButton::~TitleButton() {}

HRESULT TitleButton::Init()
{
    return S_OK;
}

void TitleButton::Update(float deltaTime, float worldTime)
{
    CButton::Update(deltaTime, worldTime);
    if (m_transform->m_pos.y != 860)
    {
        m_transform->m_pos.y -= 4;
        if (m_transform->m_pos.y < 860)
        {
            m_transform->m_pos.y = 860;
        }
    }
}