#include "framework.h"
#include "CBTN_Skill.h"
#include "DungeonScene.h"
#include "Info_Skill.h"

CBTN_Skill::CBTN_Skill()
{
}

CBTN_Skill::~CBTN_Skill()
{
}

HRESULT CBTN_Skill::Init()
{
	m_transform->m_pivot = Vector2(0, 0);
	AddSpriteRenderer(IMAGE::Crusader_Skill_BattleHeal);
	AddColliderBox();
    return S_OK;
}

void CBTN_Skill::Update(float deltaTime, float worldTime)
{
	if (scene->m_dungeonMode == DUNGEONMODE::BATTLE)
	{
		if (m_collider->new_CheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->IsDownLMB())
			{
				if (canTriggerDown)
				{
					m_triggerWhenDown();
				}

			}
		}
	}
}

void CBTN_Skill::LateUpdate()
{

}

void CBTN_Skill::BackRender(HDC _hdc)
{

}

void CBTN_Skill::Render(HDC _hdc)
{

}

void CBTN_Skill::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}


