#include "framework.h"
#include "CUIPanel_StageCoach.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
#include"CHero.h"
#include"Hero_Roster.h"
#include"CUI_Panel_Hero.h"

CUIPanel_StageCoach::CUIPanel_StageCoach()
{
	m_layer = LAYER::UI;
}
CUIPanel_StageCoach::~CUIPanel_StageCoach() {}

HRESULT CUIPanel_StageCoach::Init()
{
	CEst_UI::Init();
	isActive = false;

	m_windowPanelBG = new CSpriteRenderer(IMAGE::stage_coach_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::stage_coach_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095, -0.095);

	m_HeroList_button = new CHeroList_button();

	CreateOnCoach_Hero();

	return S_OK;
}

void CUIPanel_StageCoach::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_StageCoach::LateUpdate()
{
}

void CUIPanel_StageCoach::BackRender(HDC _hdc)
{
}

void CUIPanel_StageCoach::Render(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quit->isActive = true;
}

void CUIPanel_StageCoach::FrontRender(HDC _hdc)
{

}

void CUIPanel_StageCoach::Release()
{

}

void CUIPanel_StageCoach::Enable()
{
	CreateCoach_Button();
	CEst_UI::Enable();
}

void CUIPanel_StageCoach::Disable()
{
	m_quit->isActive = false;
	isActive = false;
	townScene->ActivateBuildings();
	for (size_t i = 0; i < m_OnCoach_heroListButtonVec.size(); i++)
	{
		m_OnCoach_heroListButtonVec[i]->isActive = false;
	}
}

void CUIPanel_StageCoach::CreateOnCoach_Hero()
{
	int random = MG_RND->getFromIntTo(3, 5);
	for (size_t i = 0; i < random; i++)
	{
		m_OnCoach_HeroVec.push_back(MG_GAME->CreateHero("Hero", (JOB)(MG_RND->getInt(2))));
	}
}

void CUIPanel_StageCoach::CreateCoach_Button()
{
	for (size_t i = 0; i < m_OnCoach_heroListButtonVec.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_OnCoach_heroListButtonVec[i]->GetId());
	}
	m_OnCoach_heroListButtonVec.clear();

	for (size_t i = 0; i < m_OnCoach_HeroVec.size(); i++)
	{
		CHeroList_button* OnCoach_HeroList_Button = new CHeroList_button();
		OnCoach_HeroList_Button->Init();
		OnCoach_HeroList_Button->m_transform->m_pos = Vector2(900, WINSIZEY - 880 + i * 100);
		OnCoach_HeroList_Button->AddColliderBox(85, 85);
		OnCoach_HeroList_Button->SetTriggerWhenDownForHerolist(townScene, &TownScene::ShowDummyHeroList);
		OnCoach_HeroList_Button->SetTriggerWhenDownForHerolist(townScene, &TownScene::ShowDummyHeroList);
		OnCoach_HeroList_Button->SetTriggerWhenDownRightButton(townScene, &TownScene::ShowCoachHeroPanel);
		OnCoach_HeroList_Button->townScene = townScene;
		OnCoach_HeroList_Button->btType = HeroListBtType::coach;
		OnCoach_HeroList_Button->m_index = i;

		OnCoach_HeroList_Button->m_hero = m_OnCoach_HeroVec[i];

		switch (OnCoach_HeroList_Button->m_hero->GetJob())
		{
		case JOB::Crusader:
			OnCoach_HeroList_Button->AddSpriteRenderer(IMAGE::crusader_roster);
			break;
		case JOB::Vestal:
			OnCoach_HeroList_Button->AddSpriteRenderer(IMAGE::vestal_roster);
			break;
		case JOB::PlagueDoctor:
			OnCoach_HeroList_Button->AddSpriteRenderer(IMAGE::plague_doctor_roster);
			break;
		case JOB::Highwayman:
			OnCoach_HeroList_Button->AddSpriteRenderer(IMAGE::highwayman_roster);
			break;
		}

		m_OnCoach_heroListButtonVec.push_back(OnCoach_HeroList_Button);
		MG_GMOBJ->RegisterObj("OnCoach_Hero_roster", OnCoach_HeroList_Button);
	}
}