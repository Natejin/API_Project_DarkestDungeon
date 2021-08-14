#include "framework.h"
#include "Unit.h"

Unit::Unit() {
    unitType = UNITTYPE::NONE;
}
Unit::~Unit() {}

HRESULT Unit::Init()
{
    return S_OK;
}

void Unit::Update(float deltaTime, float worldTime)
{
    if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
    {
        if (MG_INPUT->IsDownLMB())
        {
            if (canTriggerDown)
            {
                m_triggerWhenDown(m_partyIndex);
            }
        }
    }
}

void Unit::LateUpdate()
{
}

void Unit::BackRender(HDC _hdc)
{
}

void Unit::Render(HDC _hdc)
{
}

void Unit::FrontRender(HDC _hdc)
{
    if (m_collider)
    {
        if (MG_INPUT->isToggleKey(VK_TAB))
        {
            RectangleMake(_hdc, m_collider->rect, m_transform->m_pos - MG_CAMERA->GetPos());
        }
    }

}

void Unit::Release()
{
    GameObject::Release();
}