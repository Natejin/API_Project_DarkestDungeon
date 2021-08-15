#include "framework.h"
#include "CEquipButton.h"

CEquipButton::CEquipButton()
{
}

CEquipButton::~CEquipButton()
{
}

HRESULT CEquipButton::Init()
{   
	CBTN_Skill::Init();
    return S_OK;
}

void CEquipButton::Update(float deltaTime, float worldTime)
{

}

void CEquipButton::LateUpdate()
{
}

void CEquipButton::BackRender(HDC _hdc)
{
}

void CEquipButton::Render(HDC _hdc)
{
  
}

void CEquipButton::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}

void CEquipButton::SetEquip(IMAGE image)
{

		//skillInfo = DB_SKILL->CallSkill(skill);
		m_spriteRenderer->SetImage(image);
	
}
