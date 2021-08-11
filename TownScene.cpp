#include "framework.h"
#include "TownScene.h"
//===========================
#include"CButton.h"
#include"CDragButtion.h"
#include"CHeroList_button.h"
#include"CBuilding.h"
//===========================
#include"CHero.h"
//===========================
#include"CBG_Town.h"
#include"Abbey.h"
#include"BlackSmith.h"
#include"CampingTrainer.h"
#include"GraveYard.h"
#include"Guild.h"
#include"Sanitarium.h"
#include"Statue.h"
#include"StageCoach.h"
#include"NomadWagon.h"
#include"Tavern.h"
//===========================
#include"CHeroList_ui.h"

TownScene::TownScene(){}
TownScene::~TownScene(){}
HRESULT TownScene::Init()
{
	CBG_Town* m_town = new CBG_Town();
	m_town->Init();
	MG_GMOBJ->RegisterObj("Town", m_town);

	SetEst_ui();  
	SetEst_Img(); 
	SetHerolist(); 

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
//
void TownScene::SetEst_ui()
{	
	/*CButton* m_activity_log = new CButton();
	m_activity_log->m_transform->m_pos = Vector2(WINSIZEX / 2+100, WINSIZEY / 2 +450);
	m_activity_log->AddColliderBox(100, 100);
	m_activity_log->AddSpriteRenderer(IMAGE::estate_activity_log);
	MG_GMOBJ->RegisterObj("log", m_activity_log);*/

	m_abbey = new Abbey();
	m_abbey->Init();
	m_abbey->townScene = this;
	MG_GMOBJ->RegisterObj("AbbeyUI", m_abbey);

	m_blacksmith = new BlackSmith();
	m_blacksmith->Init();
	m_blacksmith->townScene = this;

	MG_GMOBJ->RegisterObj("BlackSmithUI", m_blacksmith);

	m_campingTrainer = new CampingTrainer();
	m_campingTrainer->Init();
	m_campingTrainer->townScene = this;

	MG_GMOBJ->RegisterObj("CampingTrainerUI", m_campingTrainer);

	m_graveyard = new GraveYard();
	m_graveyard->Init();
	m_graveyard->townScene = this;
	MG_GMOBJ->RegisterObj("GraveYardUI", m_graveyard);

	m_guild = new Guild();
	m_guild->Init();
	m_guild->townScene = this;
	MG_GMOBJ->RegisterObj("GuildUI", m_guild);

	m_sanitarium = new Sanitarium();
	m_sanitarium->Init();
	m_sanitarium->townScene = this;
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	m_stage_coach = new StageCoach();
	m_stage_coach->Init();
	m_stage_coach->townScene = this;
	MG_GMOBJ->RegisterObj("StageCoachUI", m_stage_coach);

	m_statue = new Statue();
	m_statue->Init();
	m_statue->townScene = this;
	MG_GMOBJ->RegisterObj("StatueUI", m_statue);

	m_nomad_wagon = new NomadWagon();
	m_nomad_wagon->Init();
	m_nomad_wagon->townScene = this;
	MG_GMOBJ->RegisterObj("NomadWagonUI", m_nomad_wagon);

	m_tavern = new Tavern();
	m_tavern->Init();
	m_tavern->townScene = this;
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
	m_abbey->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_blacksmith( )
{
	m_blacksmith->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_campingTrainer( )
{
	m_campingTrainer->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_graveyard()
{
	m_graveyard->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_guild()
{
	m_guild->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_nomad_wagon( )
{
	m_nomad_wagon->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_stage_coach( )
{
	m_stage_coach->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_town_statue()
{
	m_statue->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_sanitarium()
{
	m_sanitarium->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_tavern()
{
	m_tavern->isActive = true;
	DeactivateBuildings();
}
void TownScene::Show_Activity_log()
{
}
void TownScene::SetHerolist()
{	
		for (size_t i = 0; i < MG_GAME->m_partyOrigin.size(); i++)
		{
		   /*
		   ImageData m_roster;
			m_roster.m_img = MG_IMAGE->findImage(IMAGE::rosterelement_res);
			m_roster.m_trans.m_pos = Vector2(WINSIZEX / 2+510 , WINSIZEY - 930 + i*100);
			v_roster.push_back(m_roster);
			*/
			dragButton = new CHeroList_button();
			dragButton->Init();
			dragButton->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880 + i * 100);
			dragButton->AddColliderBox(50, 50);
			switch (MG_GAME->GetHero(i)->job)
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
			m_dragButton.push_back(dragButton);
			MG_GMOBJ->RegisterObj("m_hero_slot_bg", dragButton);
		}
}

void TownScene::Mouse()
{

}
