#include "framework.h"
#include "CBuilding_PanelButton.h"
#include "TownScene.h"
#include "CHeroList_button.h"
#include "CHero.h"	
CBuilding_PanelButton::CBuilding_PanelButton()
{
	m_layer = LAYER::UIButton;
}

CBuilding_PanelButton::~CBuilding_PanelButton()
{
}

HRESULT CBuilding_PanelButton::Init()
{
	//listbutton = new CHeroList_button();
	return S_OK;
}

void CBuilding_PanelButton::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
	
		if (MG_INPUT->IsUpLMB())
		{
			if (canTriggerUp)
			{
				townScene->SetHerolist(); //정보를 받아온다.
				for (size_t i = 0; i < MG_GAME->m_partyOrigin.size(); i++)
				{
					switch (MG_GAME->GetHero(i)->job)
					{
					case JOB::Crusader:
						this->AddSpriteRenderer(IMAGE::crusader_roster);
						break;
					case JOB::Vestal:
						this->AddSpriteRenderer(IMAGE::vestal_roster);
						break;
					case JOB::PlagueDoctor:
						this->AddSpriteRenderer(IMAGE::plague_doctor_roster);
						break;
					case JOB::Highwayman:
						this->AddSpriteRenderer(IMAGE::highwayman_roster);
						break;
					default:
						break;
					}
				}
			}
			//TownScene::SetHerolist에 nullptr을 못주는데. 주는법을...
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
