#include "framework.h"
#include "CBTN_Skill.h"
#include "DungeonScene.h"
#include "Info_Skill.h"
#include "CSpriteRenderer.h"
#include "CBattleSystem.h"

CBTN_Skill::CBTN_Skill()
{
	m_spriteSelected = nullptr;
}

CBTN_Skill::~CBTN_Skill()
{
}

HRESULT CBTN_Skill::Init()
{
	selected = false;
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_spriteSelected = new CSpriteRenderer(IMAGE::SelectedSkill, m_transform);
	m_spriteDeactiveIcon = new CSpriteRenderer(IMAGE::Crusader_Skill_BattleHeal, m_transform);
	activateSkill = true;
	AddSpriteRenderer(IMAGE::Crusader_Skill_BattleHeal);
	AddColliderBox();
    return S_OK;
}

void CBTN_Skill::Update(float deltaTime, float worldTime)
{
	if (activateSkill)
	{
		if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->IsDownLMB())
			{
				m_pBattleSystem->UseSkill(index);
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


	if (activateSkill)
	{
		m_spriteRenderer->RenderUI(_hdc);
		if (selected)
		{
			m_spriteSelected->RenderUI(_hdc);
		}
	}
	else {
		m_spriteDeactiveIcon->RenderUI(_hdc);
	}
#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}

void CBTN_Skill::SetSkill(SKILL skill)
{
	skillInfo = DB_SKILL->CallSkill(skill);
	m_spriteRenderer->SetImage(DB_SKILL->CallSkillImage(skill));
	m_spriteDeactiveIcon->SetImage(DB_SKILL->CallDeactiveSkillImage(skill));
}

void CBTN_Skill::ActiveSkill(bool activate)
{
	activateSkill = activate;
}

void CBTN_Skill::Release()
{
	CDragButton::Release();
	SAFE_DELETE(m_spriteSelected);
	
}


