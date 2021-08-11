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
	CBuilding* m_abbey = new CBuilding();
	m_abbey->Init();
	m_abbey->m_transform->m_pos = Vector2(WINSIZEX / 2 , WINSIZEY / 2 -200);
	m_abbey->AddSpriteRenderer("town_abbey");
	m_abbey->AddColliderBox(200, 200);
	m_abbey->SetTriggerWhenDown(this, &TownScene::Show_abeey);
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);

	CBuilding* m_guild = new CBuilding();
	m_guild->Init();
	m_guild->m_transform->m_pos = Vector2(WINSIZEX / 2 + 250, WINSIZEY / 2 +0);
	m_guild->AddColliderBox(200, 200);
	m_guild->AddSpriteRenderer("town_guild");
	m_guild->SetTriggerWhenDown(this, &TownScene::Show_guild);
	MG_GMOBJ->RegisterObj("Guild", m_guild);

	CBuilding* m_blacksmith = new CBuilding();
	m_blacksmith->Init();
	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX - 500, WINSIZEY / 2 + 50);
	m_blacksmith->AddColliderBox(200, 200);
	m_blacksmith->AddSpriteRenderer("town_blacksmith");
	m_blacksmith->SetTriggerWhenDown(this, &TownScene::Show_blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);

	CBuilding* m_campingTrainer = new CBuilding();
	m_campingTrainer->Init();
	m_campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 750, WINSIZEY / 2 - 250);
	m_campingTrainer->AddColliderBox(150, 150);
	m_campingTrainer->AddSpriteRenderer("town_camping_trainer");
	m_campingTrainer->SetTriggerWhenDown(this, &TownScene::Show_campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);

	CBuilding* m_graveyard = new CBuilding();
	m_graveyard->Init();
	m_graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2+0);
	m_graveyard->AddColliderBox(150, 150);
	m_graveyard->AddSpriteRenderer("town_graveyard");
	m_graveyard->SetTriggerWhenDown(this, &TownScene::Show_graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);

	CBuilding* m_sanitarium = new CBuilding();
	m_sanitarium->Init();
	m_sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 220, WINSIZEY / 2 -100);
	m_sanitarium->AddColliderBox(200, 200);
	m_sanitarium->AddSpriteRenderer("town_sanitarium");
	m_sanitarium->SetTriggerWhenDown(this, &TownScene::Show_sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	CBuilding* m_statue = new CBuilding();
	m_statue->Init();
	m_statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2 + 100);
	m_statue->AddColliderBox(100, 100);
	m_statue->AddSpriteRenderer("town_statue");
	m_statue->SetTriggerWhenDown(this, &TownScene::Show_town_statue);
	MG_GMOBJ->RegisterObj("Statue", m_statue);

	CBuilding* m_nomad_wagon = new CBuilding();
	m_nomad_wagon->Init();
	m_nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2 +200);
	m_nomad_wagon->AddColliderBox(100, 100);
	m_nomad_wagon->AddSpriteRenderer("town_nomad_wagon");
	m_nomad_wagon->SetTriggerWhenDown(this, &TownScene::Show_nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);

	CBuilding* m_tavern = new CBuilding();
	m_tavern->Init();
	m_tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 + 50);
	m_tavern->AddColliderBox(200, 200);
	m_tavern->AddSpriteRenderer("town_tavern");
	m_tavern->SetTriggerWhenDown(this, &TownScene::Show_tavern);
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);

	CBuilding* m_stage_coach = new CBuilding();
	m_stage_coach->Init();
	m_stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 650, WINSIZEY / 2 +150);
	m_stage_coach->AddColliderBox(150, 150);
	m_stage_coach->AddSpriteRenderer("town_stage_coach");
	m_stage_coach->SetTriggerWhenDown(this, &TownScene::Show_stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);

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
	MG_GMOBJ->RegisterObj("AbbeyUI", m_abbey);

	m_blacksmith = new BlackSmith();
	m_blacksmith->Init();
	MG_GMOBJ->RegisterObj("BlackSmithUI", m_blacksmith);

	m_campingTrainer = new CampingTrainer();
	m_campingTrainer->Init();
	MG_GMOBJ->RegisterObj("CampingTrainerUI", m_campingTrainer);

	m_graveyard = new GraveYard();
	m_graveyard->Init();
	MG_GMOBJ->RegisterObj("GraveYardUI", m_graveyard);

	m_guild = new Guild();
	m_guild->Init();
	MG_GMOBJ->RegisterObj("GuildUI", m_guild);

	m_sanitarium = new Sanitarium();
	m_sanitarium->Init();
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	m_stage_coach = new StageCoach();
	m_stage_coach->Init();
	MG_GMOBJ->RegisterObj("StageCoachUI", m_stage_coach);

	m_statue = new Statue();
	m_statue->Init();
	MG_GMOBJ->RegisterObj("StatueUI", m_statue);

	m_nomad_wagon = new NomadWagon();
	m_nomad_wagon->Init();
	MG_GMOBJ->RegisterObj("NomadWagonUI", m_nomad_wagon);

	m_tavern = new Tavern();
	m_tavern->Init();
	MG_GMOBJ->RegisterObj("TavernUI", m_tavern);
}
void TownScene::Show_abeey()
{	
	m_abbey->isActive = true;
}
void TownScene::Show_blacksmith( )
{
	m_blacksmith->isActive = true;
}
void TownScene::Show_campingTrainer( )
{
	m_campingTrainer->isActive = true;
}
void TownScene::Show_graveyard()
{
	m_graveyard->isActive = true;
}
void TownScene::Show_guild()
{
	m_guild->isActive = true;
}
void TownScene::Show_nomad_wagon( )
{
	m_nomad_wagon->isActive = true;
}
void TownScene::Show_stage_coach( )
{
	m_stage_coach->isActive = true;
}
void TownScene::Show_town_statue()
{
	m_statue->isActive = true;
}
void TownScene::Show_sanitarium()
{
	m_sanitarium->isActive = true;
}
void TownScene::Show_tavern()
{
	m_tavern->isActive = true;
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
