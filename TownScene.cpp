#include "framework.h"
#include "TownScene.h"
//===========================
#include"CButton.h"
#include"CDragButtion.h"
#include"CHeroList_button.h"
#include"CBuilding.h"
#include"Hero_Roster.h"
#include"CUI_Panel_Hero.h"
//===========================
#include"CHero.h"
//===========================
#include"CBG_Town.h"
#include"CUIPanel_Abbey.h"
#include"CUIPanel_BlackSmith.h"
#include"CUIPanel_CampingTrainer.h"
#include"CUIPanel_GraveYard.h"
#include"CUIPanel_Guild.h"
#include"CUIPanel_Sanitarium.h"
#include"CUIPanel_Statue.h"
#include"CUIPanel_StageCoach.h"
#include"CUIPanel_NomadWagon.h"
#include"CUIPanel_Tavern.h"
//===========================
#include"CHeroList_ui.h"

TownScene::TownScene(){}
TownScene::~TownScene(){}
HRESULT TownScene::Init()
{
	CBG_Town* m_town = new CBG_Town();
	m_town->Init();
	MG_GMOBJ->RegisterObj("Town", m_town);
	SetEst_Img();
	SetEst_ui();  

	SetHerolist(); 
	SetRoster();
	SetHeroPanel();

	return S_OK;
}
HRESULT TownScene::Init(bool managerInit)
{
	return S_OK;
}
void TownScene::Release()
{
}
void TownScene::Update()
{	
}
void TownScene::Render()
{
}
void TownScene::Render(HDC _hdc)
{
}
//Building.
void TownScene::SetEst_Img()
{	
	CBuilding* abeey = new CBuilding();
	abeey->Init();
	abeey->m_transform->m_pos = Vector2(WINSIZEX / 2 , WINSIZEY / 2 -200);
	abeey->AddSpriteRenderer("town_abbey");
	abeey->AddColliderBox(200, 200);
	abeey->SetTriggerWhenDown(this, &TownScene::Show_abeey);
	buildingVec.push_back(abeey);
	MG_GMOBJ->RegisterObj("Abbey", abeey);

	CBuilding* guild = new CBuilding();
	guild->Init();
	guild->m_transform->m_pos = Vector2(WINSIZEX / 2 + 250, WINSIZEY / 2 +0);
	guild->AddColliderBox(200, 200);
	guild->AddSpriteRenderer("town_guild");
	guild->SetTriggerWhenDown(this, &TownScene::Show_guild);
	buildingVec.push_back(guild);
	MG_GMOBJ->RegisterObj("Guild", guild);

	CBuilding* blacksmith = new CBuilding();
	blacksmith->Init();
	blacksmith->m_transform->m_pos = Vector2(WINSIZEX - 500, WINSIZEY / 2 + 50);
	blacksmith->AddColliderBox(200, 200);
	blacksmith->AddSpriteRenderer("town_blacksmith");
	blacksmith->SetTriggerWhenDown(this, &TownScene::Show_blacksmith);
	buildingVec.push_back(blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", blacksmith);

	CBuilding* campingTrainer = new CBuilding();
	campingTrainer->Init();
	campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 750, WINSIZEY / 2 - 250);
	campingTrainer->AddColliderBox(150, 150);
	campingTrainer->AddSpriteRenderer("town_camping_trainer");
	campingTrainer->SetTriggerWhenDown(this, &TownScene::Show_campingTrainer);
	buildingVec.push_back(campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", campingTrainer);

	CBuilding* graveyard = new CBuilding();
	graveyard->Init();
	graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2+0);
	graveyard->AddColliderBox(150, 150);
	graveyard->AddSpriteRenderer("town_graveyard");
	graveyard->SetTriggerWhenDown(this, &TownScene::Show_graveyard);
	buildingVec.push_back(graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", graveyard);

	CBuilding* sanitarium = new CBuilding();
	sanitarium->Init();
	sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 220, WINSIZEY / 2 -100);
	sanitarium->AddColliderBox(200, 200);
	sanitarium->AddSpriteRenderer("town_sanitarium");
	sanitarium->SetTriggerWhenDown(this, &TownScene::Show_sanitarium);
	buildingVec.push_back(sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", sanitarium);

	CBuilding* statue = new CBuilding();
	statue->Init();
	statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2 + 100);
	statue->AddColliderBox(100, 100);
	statue->AddSpriteRenderer("town_statue");
	statue->SetTriggerWhenDown(this, &TownScene::Show_town_statue);
	buildingVec.push_back(statue);
	MG_GMOBJ->RegisterObj("Statue", statue);

	CBuilding* nomad_wagon = new CBuilding();
	nomad_wagon->Init();
	nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2 +200);
	nomad_wagon->AddColliderBox(100, 100);
	nomad_wagon->AddSpriteRenderer("town_nomad_wagon");
	nomad_wagon->SetTriggerWhenDown(this, &TownScene::Show_nomad_wagon);
	buildingVec.push_back(nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", nomad_wagon);

	CBuilding* tavern = new CBuilding();
	tavern->Init();
	tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 + 50);
	tavern->AddColliderBox(200, 200);
	tavern->AddSpriteRenderer("town_tavern");
	tavern->SetTriggerWhenDown(this, &TownScene::Show_tavern);
	buildingVec.push_back(tavern);
	MG_GMOBJ->RegisterObj("Tavern", tavern);

	CBuilding* stage_coach = new CBuilding();
	stage_coach->Init();
	stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 650, WINSIZEY / 2 +150);
	stage_coach->AddColliderBox(150, 150);
	stage_coach->AddSpriteRenderer("town_stage_coach");
	stage_coach->SetTriggerWhenDown(this, &TownScene::Show_stage_coach);
	buildingVec.push_back(stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", stage_coach);

}
void TownScene::SetRoster()
{
	m_Roster_ButtonVec = new Hero_Roster();
	m_Roster_ButtonVec->Init();
	m_Roster_ButtonVec->scene = this;
	m_Roster_ButtonVec->Disable();
	MG_GMOBJ->RegisterObj(m_Roster_ButtonVec);
}
void TownScene::SetHeroPanel()
{
	m_hero_panel = new CUI_Panel_Hero();
	m_hero_panel->townScene = this;
	m_hero_panel->Init();
	MG_GMOBJ->RegisterObj(m_hero_panel);
}
//
void TownScene::SetEst_ui()
{	
	CButton* m_activity_log = new CButton();
	m_activity_log->m_transform->m_pos = Vector2(WINSIZEX / 2+100, WINSIZEY / 2 +450);
	m_activity_log->AddColliderBox(100, 100);
	m_activity_log->AddSpriteRenderer(IMAGE::estate_activity_log);
	MG_GMOBJ->RegisterObj("log", m_activity_log);

	m_abbey = new CUIPanel_Abbey();
	m_abbey->townScene = this;
	m_abbey->Init();
	MG_GMOBJ->RegisterObj("AbbeyUI", m_abbey);

	m_blacksmith = new CUIPanel_BlackSmith();
	m_blacksmith->townScene = this;
	m_blacksmith->Init();
	MG_GMOBJ->RegisterObj("BlackSmithUI", m_blacksmith);

	m_campingTrainer = new CUIPanel_CampingTrainer();
	m_campingTrainer->townScene = this;
	m_campingTrainer->Init();
	MG_GMOBJ->RegisterObj("CampingTrainerUI", m_campingTrainer);

	m_graveyard = new CUIPanel_GraveYard();
	m_graveyard->townScene = this;
	m_graveyard->Init();
	MG_GMOBJ->RegisterObj("GraveYardUI", m_graveyard);

	m_guild = new CUIPanel_Guild();
	m_guild->townScene = this;
	m_guild->Init();
	MG_GMOBJ->RegisterObj("GuildUI", m_guild);

	m_sanitarium = new CUIPanel_Sanitarium();
	m_sanitarium->townScene = this;
	m_sanitarium->Init();
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	m_stage_coach = new CUIPanel_StageCoach();
	m_stage_coach->townScene = this;
	m_stage_coach->Init();
	MG_GMOBJ->RegisterObj("StageCoachUI", m_stage_coach);

	m_statue = new CUIPanel_Statue();
	m_statue->townScene = this;
	m_statue->Init();
	MG_GMOBJ->RegisterObj("StatueUI", m_statue);

	m_nomad_wagon = new CUIPanel_NomadWagon();
	m_nomad_wagon->townScene = this;
	m_nomad_wagon->Init();
	MG_GMOBJ->RegisterObj("NomadWagonUI", m_nomad_wagon);

	m_tavern = new CUIPanel_Tavern();
	m_tavern->townScene = this;
	m_tavern->Init();
	MG_GMOBJ->RegisterObj("TavernUI", m_tavern);
}
void TownScene::DeactivateBuildings()
{
	for (size_t i = 0; i < buildingVec.size(); i++)
	{
		buildingVec[i]->isActive = false;
	}
}

void TownScene::ActivateBuildings() {
	for (size_t i = 0; i < buildingVec.size(); i++)
	{
		buildingVec[i]->isActive = true;
	}
}

void TownScene::Show_abeey()
{	
	m_abbey->Enable();
}
void TownScene::Show_blacksmith( )
{
	m_blacksmith->Enable();
}
void TownScene::Show_campingTrainer( )
{
	m_campingTrainer->Enable();
}
void TownScene::Show_graveyard()
{
	m_graveyard->Enable();
}
void TownScene::Show_guild()
{
	m_guild->Enable();
}
void TownScene::Show_nomad_wagon( )
{
	m_nomad_wagon->Enable();
}
void TownScene::Show_stage_coach( )
{	
	m_stage_coach->Enable();

}
void TownScene::Show_town_statue()
{
	m_statue->Enable();
}
void TownScene::Show_sanitarium()
{
	m_sanitarium->Enable();
}
void TownScene::Show_tavern()
{
	m_tavern->Enable();
}
void TownScene::Show_Activity_log()
{
}
void TownScene::SetHerolist()
{	
	for (size_t i = 0; i < m_heroListButtonVec.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_heroListButtonVec[i]->GetId());
	}
	m_heroListButtonVec.clear();

		for (size_t i = 0; i < MG_GAME->m_ownHeroes.size(); i++)
		{
			CHeroList_button* dragButton = new CHeroList_button();
			dragButton->Init();
			dragButton->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880 + i * 100);
			dragButton->AddColliderBox(50, 50);
			dragButton->SetTriggerWhenDown(this, &TownScene::ShowDummyHeroList);
			dragButton->SetTriggerWhenDownRightButton(this, &TownScene::ShowHeroPanel);
			dragButton->m_index = i;
			dragButton->townScene = this;
			MG_GAME->GetHero(i)->SetOwnIndex(i);
			dragButton->m_hero = MG_GAME->GetHero(i);

			switch (dragButton->m_hero->GetJob())
			{
			case JOB::Crusader:
				dragButton->AddSpriteRenderer(IMAGE::crusader_roster);
				break;
			case JOB::Vestal:
				dragButton->AddSpriteRenderer(IMAGE::vestal_roster);
				break;
			case JOB::PlagueDoctor:
				dragButton->AddSpriteRenderer(IMAGE::plague_doctor_roster);
				break;
			case JOB::Highwayman:
				dragButton->AddSpriteRenderer(IMAGE::highwayman_roster);
				break;
			default:
				break;
			}
			m_heroListButtonVec.push_back(dragButton);
			MG_GMOBJ->RegisterObj("Hero_roster", dragButton);
		}
}

void TownScene::ShowDummyHeroList()
{
	m_Roster_ButtonVec->m_spriteRenderer->SetImage(m_heroListButtonVec[curDragHeroIndex]->m_spriteRenderer->GetImage());
	m_Roster_ButtonVec->Enable();
}

void TownScene::ShowHeroPanel()
{
	m_hero_panel->Enable();
}

CUI_Panel_Hero* TownScene::GetHeroPanel()
{
	return m_hero_panel;
}


