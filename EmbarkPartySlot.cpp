#include "framework.h"
#include "EmbarkPartySlot.h"
#include "CHero.h"
#include "CParty.h"
#include "TownScene.h"
#include "CHeroList_button.h"

EmbarkPartySlot::EmbarkPartySlot()
{
    m_layer = LAYER::UI;
    m_hero = nullptr;
}
EmbarkPartySlot::~EmbarkPartySlot() {}

HRESULT EmbarkPartySlot::Init()
{
    CEst_UI::Init();
    m_transform->m_pivot = Vector2(0.5, 0.5);
	AddSpriteRenderer("heroSlot2");
    AddColliderBox(85, 85);

    m_hero = nullptr;

    return S_OK;
}

void EmbarkPartySlot::Update(float deltaTime, float worldTime)
{
	if (m_hero != nullptr)
	{
		if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->IsDownRMB())
			{
				MG_GAME->RegisterHeroToOwnList(m_hero);
				m_townScene->SetHerolist();
				m_hero = nullptr;
				m_spriteRenderer->SetImage("heroSlot2");
			}
		}
	}

	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->IsUpLMB())
		{
			if (m_hero == nullptr && m_townScene->isDrag) 
			{
				m_hero = m_townScene->m_heroListButtonVec[m_townScene->curDragHeroIndex]->m_hero;

				MG_GAME->RegisterHeroToParty(m_hero);
				MG_GAME->RemoveHeroFromOwnList(m_hero->GetHeroID());
				m_townScene->SetHerolist();
				//m_spriteRenderer->SetImage(m_hero->GetInfo()->portrait);

				switch (m_hero->GetJob())
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

void EmbarkPartySlot::LateUpdate()
{
}

void EmbarkPartySlot::BackRender(HDC _hdc)
{
}

void EmbarkPartySlot::Render(HDC _hdc)
{
}

void EmbarkPartySlot::FrontRender(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);
    if (MG_INPUT->isToggleKey(VK_TAB))
    {
        RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
    }
}

void EmbarkPartySlot::Release()
{
	CEst_UI::Release();
	m_hero = nullptr;
}

void EmbarkPartySlot::Enable()
{
	isActive = true;
}

void EmbarkPartySlot::Disable()
{
	isActive = false;
}