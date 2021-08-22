#include "framework.h"
#include "COwnHeroListPanel.h"
#include "TownScene.h"
#include "Hero_Roster.h"
#include "CHeroList_button.h"

HRESULT COwnHeroListPanel::Init()
{
    m_layer = LAYER::UI;
    m_transform->m_pos = Vector2(0, 0);
    AddColliderBox(Vector2(0, 0), 1520, 130, 1890, 670);
    return S_OK;
}

void COwnHeroListPanel::Update(float deltaTime, float worldTime)
{
    if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
    {
        if (m_townScene->isDrag && MG_INPUT->IsUpLMB())
        {
            if (m_townScene->m_DummyRosterButton->type == HeroListBtType::coach)
            {
                m_townScene->addOwnHero();
            }
        }
    }
}

void COwnHeroListPanel::LateUpdate()
{
}

void COwnHeroListPanel::BackRender(HDC _hdc)
{
}

void COwnHeroListPanel::Render(HDC _hdc)
{
    if(MG_INPUT->isToggleKey(VK_TAB))
    {
        RectangleMake(_hdc, m_collider->rect, m_collider->m_pos);
    }
}

void COwnHeroListPanel::FrontRender(HDC _hdc)
{

}

void COwnHeroListPanel::Release()
{
    GameObject::Release();
}

void COwnHeroListPanel::Disable()
{
    isActive = false;
}

void COwnHeroListPanel::Enable()
{
    isActive = true;
}
