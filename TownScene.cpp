#include "framework.h"
#include "TownScene.h"
#include "CBuilding.h"
#include"CButton.h"
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

TownScene::TownScene()
{

}

TownScene::~TownScene()
{
}

HRESULT TownScene::Init()
{
	CBG_Town* m_town = new CBG_Town();
	m_town->Init();
	
	MG_GMOBJ->RegisterObj("Town", m_town);

	SetIMG_Est(); //건물 버튼.

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
	m_abbey->m_transform->m_pos = Vector2(WINSIZEX / 2 - 150, WINSIZEY / 2 - 250);
	m_abbey->AddSpriteRenderer("town_abbey");
	m_abbey->SetButtonSize(200, 200);
	m_abbey->SetTriggerWhenClick(this, &TownScene::Show_abeey);
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);

	CBuilding* m_guild = new CBuilding();
	m_guild->m_transform->m_pos = Vector2(WINSIZEX / 2 + 80, WINSIZEY / 2 - 50);
	m_guild->SetButtonSize(200, 200);
	m_guild->AddSpriteRenderer("town_guild");
	m_guild->SetTriggerWhenClick(this, &TownScene::Show_guild);
	MG_GMOBJ->RegisterObj("Guild", m_guild);

	CBuilding* m_blacksmith = new CBuilding();
	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX / 2+200 , WINSIZEY / 2);
	m_blacksmith->SetButtonSize(200, 200);
	m_blacksmith->AddSpriteRenderer("town_blacksmith");
	m_blacksmith->SetTriggerWhenClick(this, &TownScene::Show_blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);

	CBuilding* m_campingTrainer = new CBuilding();
	m_campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 820, WINSIZEY / 2 - 300);
	m_campingTrainer->SetButtonSize(200, 200);
	m_campingTrainer->AddSpriteRenderer("town_camping_trainer");
	m_campingTrainer->SetTriggerWhenClick(this, &TownScene::Show_campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);

	CBuilding* m_graveyard = new CBuilding();
	m_graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 250, WINSIZEY / 2 - 100);
	m_graveyard->SetButtonSize(200, 200);
	m_graveyard->AddSpriteRenderer("town_graveyard");
	m_graveyard->SetTriggerWhenClick(this, &TownScene::Show_graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);
	
	CBuilding* m_sanitarium = new CBuilding();
	m_sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 420, WINSIZEY / 2 - 180);
	m_sanitarium->SetButtonSize(200, 200);
	m_sanitarium->AddSpriteRenderer("town_sanitarium");
	m_sanitarium->SetTriggerWhenClick(this, &TownScene::Show_sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	CBuilding* m_statue = new CBuilding();
	m_statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 - 0);
	m_statue->SetButtonSize(200, 200);
	m_statue->AddSpriteRenderer("town_statue");
	m_statue->SetTriggerWhenClick(this, &TownScene::Show_town_statue);
	MG_GMOBJ->RegisterObj("Statue", m_statue);

	CBuilding* m_nomad_wagon = new CBuilding();
	m_nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 + 130);
	m_nomad_wagon->SetButtonSize(200, 200);
	m_nomad_wagon->AddSpriteRenderer("town_nomad_wagon");
	m_nomad_wagon->SetTriggerWhenClick(this, &TownScene::Show_nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);

	CBuilding* m_tavern = new CBuilding();
	m_tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 550, WINSIZEY / 2 - 50);
	m_tavern->SetButtonSize(200, 200);
	m_tavern->AddSpriteRenderer("town_tavern");
	m_tavern->SetTriggerWhenClick(this, &TownScene::Show_tavern);
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);

	CBuilding* m_stage_coach = new CBuilding();
	m_stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 780, WINSIZEY / 2 +50);
	m_stage_coach->SetButtonSize(200, 200);
	m_stage_coach->AddSpriteRenderer("town_stage_coach");
	m_stage_coach->SetTriggerWhenClick(this, &TownScene::Show_stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);

	
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