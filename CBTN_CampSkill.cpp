#include "framework.h"
#include "CBTN_CampSkill.h"
#include "DungeonScene.h"
#include "Info_Skill.h"
#include "CSpriteRenderer.h"
#include "CBattleSystem.h"

CBTN_CampSkill::CBTN_CampSkill()
{
	m_spriteSelected = nullptr;
}
CBTN_CampSkill::~CBTN_CampSkill() {}


HRESULT CBTN_CampSkill::Init()
{
	selected = false;
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_spriteSelected = new CSpriteRenderer(IMAGE::SelectedSkill, m_transform);

	AddSpriteRenderer(IMAGE::Crusader_Skill_BattleHeal);
	AddColliderBox();
	return S_OK;
}

void CBTN_CampSkill::Update(float deltaTime, float worldTime)
{
}

void CBTN_CampSkill::LateUpdate()
{
}

void CBTN_CampSkill::BackRender(HDC _hdc)
{
}

void CBTN_CampSkill::Render(HDC _hdc)
{
}

void CBTN_CampSkill::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
	if (selected)
	{
		m_spriteSelected->RenderUI(_hdc);
	}

#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}

//void CBTN_CampSkill::SetSkill(SKILL skill)
//{
//	skillInfo = DB_SKILL->CallSkill(skill);
//	m_spriteRenderer->SetImage(DB_SKILL->CallSkillImage(skill));
//}

void CBTN_CampSkill::SetCampSkill(IMAGE skill)
{
	m_spriteRenderer->SetImage(skill);
}

void CBTN_CampSkill::Release()
{
	CDragButton::Release();
	SAFE_DELETE(m_spriteSelected);
}