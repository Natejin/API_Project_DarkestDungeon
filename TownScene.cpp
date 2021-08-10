#include "framework.h"
#include "TownScene.h"
#include "CBuilding.h"
#include"CButton.h"
#include"CDragButtion.h"
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
#include "CDragButtion.h"
#include"CHero.h"
TownScene::TownScene(){}
TownScene::~TownScene(){}
HRESULT TownScene::Init()
{
	CBG_Town* m_town = new CBG_Town();
	m_town->Init();
	
	MG_GMOBJ->RegisterObj("Town", m_town);

	m_hero = new CHero();

	SetIMG_Est(); //건물 버튼.
	SetUI(); //UI버튼
	SetHerolist();

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

	m_estui = new CEst_UI;


	return S_OK;
}

HRESULT TownScene::Init(bool managerInit)
{
	 abbey_b=false;
	 blacksmith_b = false;
	 campingTrainer_b = false;
	 graveyard_b = false;
	 guild_b = false;
	 nomad_wagon_b = false;
	 stage_coach_b = false;
	 town_statue_b = false;
	 sanitarium_b = false;
	 tavern_b = false;
	 //===========================
	  abbey_ui=false;
	  blacksmith_ui = false;
	  campingTrainer_ui = false;
	  graveyard_ui = false;
	  guild_ui = false;
	  nomad_wagon_ui = false;
	  stage_coach_ui = false;
	  town_statue_ui = false;
	  sanitarium_ui = false;
	  tavern_ui = false;
	return S_OK;
}

void TownScene::Release()
{
}

void TownScene::Update()
{
	if (abbey_b==true){	abbey_ui = true;}
	if (blacksmith_b == true){blacksmith_ui = true;}
	if (campingTrainer_b ==true){campingTrainer_ui = true;}
	if (graveyard_b ==true){graveyard_ui = true;}
	if (guild_b == true){guild_ui = true;}
	if (sanitarium_b == true){sanitarium_ui = true;}
	if (tavern_b ==true){tavern_ui = true;}
	if (town_statue_b ==true){town_statue_ui = true;}
	if (nomad_wagon_b==true){nomad_wagon_ui = true;}
	if (stage_coach_b==true){stage_coach_ui = true;}
	
	if (abbey_ui == true)
	{
		m_abbey->isUI = true;
		abbey_ui = false;
		abbey_b  = false;
	}
	if (blacksmith_ui == true)
	{
		m_blacksmith->isUI = true;
		blacksmith_b = false;
		blacksmith_ui = false;
	}
	if (campingTrainer_ui == true)
	{
		m_campingTrainer->isUI = true;
		campingTrainer_b = false;
		campingTrainer_ui = false;

	}
	if (graveyard_ui == true)
	{
		m_graveyard->isUI = true;
		graveyard_b = false;
		graveyard_ui = false;
	}
	if (guild_ui == true)
	{
		m_guild->isUI = true;
		guild_ui = false;
		guild_b = false;
	}
	if (sanitarium_ui == true)
	{
		m_sanitarium->isUI = true;
		sanitarium_b = false;
		sanitarium_ui = false;
	}
	if (stage_coach_ui == true)
	{
		m_stage_coach->isUI = true;
		stage_coach_b = false;
		stage_coach_ui = false;

	}
	if (town_statue_ui == true)
	{
		m_statue->isUI = true;
		town_statue_b = false;
		town_statue_ui = false;

	}
	if (nomad_wagon_ui == true)
	{
		m_nomad_wagon->isUI = true;
		nomad_wagon_b = false;
		nomad_wagon_ui = false;

	}
	if (tavern_ui == true)
	{
		m_tavern->isUI = true;
		tavern_b = false;
		tavern_ui = false;
	}
}

void TownScene::Render()
{
	
}

void TownScene::Render(HDC _hdc)
{
	

	if (abbey_b)
	{
		TextOut(_hdc, 50, 100, "수도원", lstrlen("수도원"));
		

	}
	if (blacksmith_b)
	{
		TextOut(_hdc, 50, 150, "대장간", lstrlen("대장간"));
	}
	if (campingTrainer_b)
	{
		TextOut(_hdc, 50, 200, "캠프", lstrlen("캠프"));
	}
	if (graveyard_b)
	{
		TextOut(_hdc, 50, 250, "무덤", lstrlen("무덤"));
	}
	if (guild_b)
	{
		TextOut(_hdc, 50, 300, "길드", lstrlen("길드"));
	}
	if (sanitarium_b)
	{
		TextOut(_hdc, 50, 350, "요양원", lstrlen("요양원"));
	}
	if (stage_coach_b)
	{
		TextOut(_hdc, 50, 550, "역마차", lstrlen("역마차"));
	}
	if (town_statue_b)
	{
		TextOut(_hdc, 50, 450, "선조의 회고록", lstrlen("선조의 회고록"));
	}
	if (nomad_wagon_b)
	{
		TextOut(_hdc, 50, 500, "유목민마차", lstrlen("유목민마차"));
	}
	if (tavern_b)
	{
		TextOut(_hdc, 50, 400, "여관", lstrlen("여관"));
	}
}

void TownScene::SetIMG_Est() //건물 버튼.
{	
	CBuilding* m_abbey = new CBuilding();

	m_abbey->m_transform->m_pos = Vector2(WINSIZEX / 2 +30, WINSIZEY / 2 - 200);

	m_abbey->AddSpriteRenderer("town_abbey");
	m_abbey->SetButtonSize(200, 200);
	m_abbey->SetTriggerWhenClick(this, &TownScene::Show_abeey);
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);

	CBuilding* m_guild = new CBuilding();

	m_guild->m_transform->m_pos = Vector2(WINSIZEX / 2 + 300, WINSIZEY / 2 +50);

	m_guild->SetButtonSize(200, 200);
	m_guild->AddSpriteRenderer("town_guild");
	m_guild->SetTriggerWhenClick(this, &TownScene::Show_guild);
	MG_GMOBJ->RegisterObj("Guild", m_guild);

	CBuilding* m_blacksmith = new CBuilding();

	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX -500 , WINSIZEY / 2+100);

	m_blacksmith->SetButtonSize(200, 200);
	m_blacksmith->AddSpriteRenderer("town_blacksmith");
	m_blacksmith->SetTriggerWhenClick(this, &TownScene::Show_blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);

	CBuilding* m_campingTrainer = new CBuilding();

	m_campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 750, WINSIZEY / 2 - 250);

	m_campingTrainer->SetButtonSize(200, 200);
	m_campingTrainer->AddSpriteRenderer("town_camping_trainer");
	m_campingTrainer->SetTriggerWhenClick(this, &TownScene::Show_campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);

	CBuilding* m_graveyard = new CBuilding();

	m_graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2 - 0);

	m_graveyard->SetButtonSize(200, 200);
	m_graveyard->AddSpriteRenderer("town_graveyard");
	m_graveyard->SetTriggerWhenClick(this, &TownScene::Show_graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);
	
	CBuilding* m_sanitarium = new CBuilding();

	m_sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 220, WINSIZEY / 2 - 80);

	m_sanitarium->SetButtonSize(200, 200);
	m_sanitarium->AddSpriteRenderer("town_sanitarium");
	m_sanitarium->SetTriggerWhenClick(this, &TownScene::Show_sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	CBuilding* m_statue = new CBuilding();

	m_statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 0, WINSIZEY / 2 +150);

	m_statue->SetButtonSize(200, 200);
	m_statue->AddSpriteRenderer("town_statue");
	m_statue->SetTriggerWhenClick(this, &TownScene::Show_town_statue);
	MG_GMOBJ->RegisterObj("Statue", m_statue);

	CBuilding* m_nomad_wagon = new CBuilding();
	m_nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 +150, WINSIZEY / 2 + 250);
	m_nomad_wagon->SetButtonSize(100, 100);
	m_nomad_wagon->AddSpriteRenderer("town_nomad_wagon");
	m_nomad_wagon->SetTriggerWhenClick(this, &TownScene::Show_nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);

	CBuilding* m_tavern = new CBuilding();

	m_tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 +100);
	m_tavern->SetButtonSize(200, 200);
	m_tavern->AddSpriteRenderer("town_tavern");
	m_tavern->SetTriggerWhenClick(this, &TownScene::Show_tavern);
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);

	CBuilding* m_stage_coach = new CBuilding();

	m_stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 650, WINSIZEY / 2 +150);

	m_stage_coach->SetButtonSize(200, 200);
	m_stage_coach->AddSpriteRenderer("town_stage_coach");
	m_stage_coach->SetTriggerWhenClick(this, &TownScene::Show_stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);

}
void TownScene::SetUI()
{	
	CButton* m_activity_log = new CButton();
	m_activity_log->m_transform->m_pos = Vector2(WINSIZEX / 2+100, WINSIZEY / 2 +400);
	m_activity_log->SetButtonSize(100, 100);
	m_activity_log->AddSpriteRenderer(IMAGE::estate_activity_log);
	MG_GMOBJ->RegisterObj("log", m_activity_log);

	CButton* m_rostertop = new CButton();
	m_rostertop->m_transform->m_pos = Vector2(WINSIZEX / 2+700, WINSIZEY / 2-400);
	m_rostertop->SetButtonSize(0, 0);
	m_rostertop->AddSpriteRenderer(IMAGE::roster_topframe);
	MG_GMOBJ->RegisterObj("rostertop", m_rostertop);
	
	CButton* m_rosterbg = new CButton();
	m_rosterbg->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY-650);
	m_rosterbg->SetButtonSize(0, 0);
	m_rosterbg->AddSpriteRenderer(IMAGE::roster_bggrad);
	MG_GMOBJ->RegisterObj("rosterPanel", m_rosterbg);
	

	CButton* m_rosterdown = new CButton();
	m_rosterdown->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 350);
	m_rosterdown->SetButtonSize(50, 50);
	m_rosterdown->AddSpriteRenderer(IMAGE::roster_downframe);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterdown);
	
	CButton* m_nameplate = new CButton();
	m_nameplate->m_transform->m_pos = Vector2(WINSIZEX / 2-500 , 130);
	m_nameplate->SetButtonSize(0, 0);
	m_nameplate->AddSpriteRenderer(IMAGE::estate_nameplate);
	MG_GMOBJ->RegisterObj("rosterdown", m_nameplate);

	CButton* m_rosterelement = new CButton();
	m_rosterelement->m_transform->m_pos = Vector2(WINSIZEX / 2 +700, WINSIZEY - 880);
	m_rosterelement->SetButtonSize(0, 0);
	m_rosterelement->AddSpriteRenderer(IMAGE::rosterelement_res);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterelement);

	CButton* m_rosterelement2 = new CButton();
	m_rosterelement2->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 780);
	m_rosterelement2->SetButtonSize(0, 0);
	m_rosterelement2->AddSpriteRenderer(IMAGE::rosterelement_res);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterelement2);

	CButton* m_rosterelement3 = new CButton();
	m_rosterelement3->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 680);
	m_rosterelement3->SetButtonSize(0, 0);
	m_rosterelement3->AddSpriteRenderer(IMAGE::rosterelement_res);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterelement3);

	CButton* m_rosterelement4 = new CButton();
	m_rosterelement4->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 580);
	m_rosterelement4->SetButtonSize(0, 0);
	m_rosterelement4->AddSpriteRenderer(IMAGE::rosterelement_res);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterelement4);

	CButton* m_rosterelement5 = new CButton();
	m_rosterelement5->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 480);
	m_rosterelement5->SetButtonSize(0, 0);
	m_rosterelement5->AddSpriteRenderer(IMAGE::rosterelement_res);
	MG_GMOBJ->RegisterObj("rosterdown", m_rosterelement5);
	
	CButton* m_unequip_trinkets = new CButton();
	m_unequip_trinkets->m_transform->m_pos = Vector2(WINSIZEX / 2 + 670, WINSIZEY - 950);
	m_unequip_trinkets->SetButtonSize(20, 20);
	m_unequip_trinkets->AddSpriteRenderer(IMAGE::unequip_trinkets);
	MG_GMOBJ->RegisterObj("rosterdown", m_unequip_trinkets);

	CButton* m_sort_rarity = new CButton();
	m_sort_rarity->m_transform->m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 950);
	m_sort_rarity->SetButtonSize(20, 20);
	m_sort_rarity->AddSpriteRenderer(IMAGE::sort_rarity);
	MG_GMOBJ->RegisterObj("rosterdown", m_sort_rarity);

	CButton* m_sort_stress = new CButton();
	m_sort_stress->m_transform->m_pos = Vector2(WINSIZEX / 2 + 730, WINSIZEY - 950);
	m_sort_stress->SetButtonSize(20, 20);
	m_sort_stress->AddSpriteRenderer(IMAGE::sort_stress);
	MG_GMOBJ->RegisterObj("rosterdown", m_sort_stress);

	/*CDragButton* m_hero_slot_bg = new CDragButton();
	m_hero_slot_bg->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880);
	m_hero_slot_bg->SetButtonSize(50, 50);
	m_hero_slot_bg->AddSpriteRenderer(IMAGE::hero_slot_bg);
	MG_GMOBJ->RegisterObj("rosterdown", m_hero_slot_bg);

	*/

	
}
void TownScene::Show_abeey()
{
	abbey_b = true;
	
}
void TownScene::Show_blacksmith( )
{
	blacksmith_b = true;

}
void TownScene::Show_campingTrainer( )
{
	campingTrainer_b = true;

}
void TownScene::Show_graveyard()
{
	graveyard_b = true;
}
void TownScene::Show_guild()
{
	guild_b = true;
}
void TownScene::Show_nomad_wagon( )
{
	nomad_wagon_b = true;

}
void TownScene::Show_stage_coach( )
{
	stage_coach_b = true;

}
void TownScene::Show_town_statue()
{
	town_statue_b = true;

}
void TownScene::Show_sanitarium()
{
	sanitarium_b = true;

}
void TownScene::Show_tavern()
{
	tavern_b = true;

}

void TownScene::Show_Activity_log()
{

}
	
void TownScene::SetHerolist()
{	//ownHeros를 가져오자.



	//영웅 리스트.
	//내가 가지고있는 용병이 ~~이라면 그용병의 이미지를 띄워라.
	if (true)
	{
	
		for (size_t i = 0; i < MG_GAME->m_partyOrigin.size(); i++)
		{
			/*ImageData 
			ImageData UIimg;

			UIimg.m_img = MG_IMAGE->findImage("panel_bg2");
			UIimg.m_trans.m_pos = Vector2(0, 700);
			vUI.push_back(UIimg);
			UIimg.m_trans.m_pos = Vector2(1580, 700);
			vUI.push_back(UIimg);*/
			

			CDragButton* dragButton = new CDragButton();
			dragButton->Init();
			dragButton->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880 + i * 100);
			dragButton->SetButtonSize(50, 50);
			switch (MG_GAME->GetHero(i)->job)
			{
			case JOB::Crusader:
				dragButton->AddSpriteRenderer(IMAGE::crusader_roster);
				break;
			case JOB::Vestal:
				dragButton->AddSpriteRenderer(IMAGE::vestal_roster);
				break;
			case JOB::PlagueDoctor:
				break;
			case JOB::Highwayman:
				break;
			default:
				break;
			}
	
			m_dragButton.push_back(dragButton);
			MG_GMOBJ->RegisterObj("m_hero_slot_bg", dragButton);

		}

		//CDragButton* crusader_roster = new CDragButton();
		//crusader_roster->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880);
		//crusader_roster->SetButtonSize(50, 50);
		//crusader_roster->AddSpriteRenderer(IMAGE::crusader_roster);
		//MG_GMOBJ->RegisterObj("m_hero_slot_bg", crusader_roster);

		//CDragButton* highwayman_roster = new CDragButton();
		//highwayman_roster->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 780);
		//highwayman_roster->SetButtonSize(50, 50);
		//highwayman_roster->AddSpriteRenderer(IMAGE::highwayman_roster);
		//MG_GMOBJ->RegisterObj("m_hero_slot_bg", highwayman_roster);

		//CDragButton* vestal_roster = new CDragButton();
		//vestal_roster->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 680);
		//vestal_roster->SetButtonSize(50, 50);
		//vestal_roster->AddSpriteRenderer(IMAGE::vestal_roster);
		//MG_GMOBJ->RegisterObj("m_hero_slot_bg", vestal_roster);

		//CDragButton* plague_doctor_roster = new CDragButton();
		//plague_doctor_roster->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 580);
		//plague_doctor_roster->SetButtonSize(50, 50);
		//plague_doctor_roster->AddSpriteRenderer(IMAGE::plague_doctor_roster);
		//MG_GMOBJ->RegisterObj("m_hero_slot_bg", plague_doctor_roster);

	}
	

	//버튼도 구현을 해야 한다,
	//버튼은 드래그도 되야 하고 
	//누르고 있는동안은 잡혀있다가 손을 떼면 그위치에 두는걸로,
	
	//그럼 버튼을 먼저 만들어 보자.
	
}
