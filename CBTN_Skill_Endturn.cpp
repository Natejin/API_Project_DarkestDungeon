#include "framework.h"
#include "CBTN_Skill_Endturn.h"
#include "CBattleSystem.h"

CBTN_Skill_Endturn::CBTN_Skill_Endturn()
{
}

CBTN_Skill_Endturn::~CBTN_Skill_Endturn()
{
}

HRESULT CBTN_Skill_Endturn::Init()
{
    selected = false;
    m_transform->m_pivot = Vector2(0.5, 0.5);
    m_spriteSelected = new CSpriteRenderer(IMAGE::SelectedSkill, m_transform);

    AddSpriteRenderer(IMAGE::Ability_Pass);
    AddColliderBox();
    return S_OK;
}

void CBTN_Skill_Endturn::Update(float deltaTime, float worldTime)
{
    if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
    {
        if (MG_INPUT->IsDownLMB())
        {
            m_pBattleSystem->StartTurn();

        }
    }
}
