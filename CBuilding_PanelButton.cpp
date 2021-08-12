#include "framework.h"
#include "CBuilding_PanelButton.h"
#include "TownScene.h"
#include "CHeroList_button.h"
#include "CHero.h"	
#include"CUIPanel_Abbey.h"

CBuilding_PanelButton::CBuilding_PanelButton()
{
	m_layer = LAYER::UIButton;	
}

CBuilding_PanelButton::~CBuilding_PanelButton()
{
}

HRESULT CBuilding_PanelButton::Init()
{
	return S_OK;
}

void CBuilding_PanelButton::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->IsUpLMB())
		{
			if (hero == nullptr && CHeroList_button::selDragButton != nullptr)
			{
				hero = ((CHeroList_button*)CHeroList_button::selDragButton)->m_hero;
				CHeroList_button::selDragButton = nullptr;
				MG_GAME->RemoveHero(hero->ownIndex);
				townScene->SetHerolist();
				
				switch (hero->job)
				{
				case JOB::Crusader:
					m_spriteRenderer->SetImage(IMAGE::crusader_roster);
					break;
				case JOB::Vestal:
					m_spriteRenderer->SetImage(IMAGE::vestal_roster);
					break;
				case JOB::PlagueDoctor:
					m_spriteRenderer->SetImage(IMAGE::plague_doctor_roster);
					break;
				case JOB::Highwayman:
					m_spriteRenderer->SetImage(IMAGE::highwayman_roster);
					break;
				default:
					break;
				}
				
			}
		
		}

	}
	
}

void CBuilding_PanelButton::LateUpdate()
{
}

void CBuilding_PanelButton::BackRender(HDC _hdc)
{
}

void CBuilding_PanelButton::Render(HDC _hdc)
{

}

void CBuilding_PanelButton::FrontRender(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);

#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}
