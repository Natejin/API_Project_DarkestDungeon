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
	checkBTN = new CButton();
	//checkBTN->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + buttonID/3 * 135, WINSIZEY / 2 - 240 + 50 + buttonID % 3 * 225);
	Vector2 pos = m_transform->m_pos;
	pos.y += 50;
	checkBTN->m_transform->m_pos = pos;
	checkBTN->AddSpriteRenderer(IMAGE::check);
	checkBTN->AddColliderBox();
	checkBTN->Disable();
	checkBTN->SetTriggerWhenDown(this, &CBuilding_PanelButton::PressCheckButton);
	MG_GMOBJ->RegisterObj("check", checkBTN);

	AddSpriteRenderer(IMAGE::hero_slot_bg);
	AddColliderBox();
	MG_GMOBJ->RegisterObj("emptyroom", this);
	Disable();
	return S_OK;
}

void CBuilding_PanelButton::Update(float deltaTime, float worldTime)
{
	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->IsUpLMB())
		{
			if (hero == nullptr && scene->isDrag)
			{	//히어로리스트버튼의벡터의 몇번째 인덱스의 히어로를 들었냐
				hero = scene->m_heroListButtonVec[scene->curDragHeroIndex]->m_hero; 
				MG_GAME->RemoveHeroFromOwnList(hero->GetHeroID());
				scene->SetHerolist();
				checkBTN->Enable();
				switch (hero->GetJob())
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

		if (hero != nullptr)
		{
			if (MG_INPUT->IsDownRMB())
			{
				MG_GAME->RegisterHeroToOwnList(hero);
				scene->SetHerolist();
				m_spriteRenderer->SetImage(IMAGE::hero_slot_bg);
				checkBTN->Disable();
				hero = nullptr;

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

void CBuilding_PanelButton::PressCheckButton()
{
	switch (buttonID % 3)
	{
	case 0:
		m_spriteRenderer->SetImage(IMAGE::abbey_flagellation);
		break;
	case 1:
		m_spriteRenderer->SetImage(IMAGE::abbey_pray);
		break;
	case 2:
		m_spriteRenderer->SetImage(IMAGE::abbey_meditation);
		break;
	default:
		break;
	}
	checkBTN->Disable();
}

void CBuilding_PanelButton::Disable()
{
	checkBTN->Disable();
}
