#include "framework.h"
#include "TownScene.h"

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
	m_town->m_transform->m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	m_town->SetImageSize(WINSIZEX, WINSIZEY);
	m_town->m_image = MG_IMAGE->findImage("district");

	MG_GMOBJ->RegisterObj("Town", m_town);

	SetIMG_Est();

	Set_EST_UI();
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

void TownScene::SetIMG_Est()
{
	CButton* m_abbey = new CButton();
	m_abbey->m_transform->m_pos = Vector2(WINSIZEX / 2 - 350, WINSIZEY / 2 - 450);
	m_abbey->SetButtonSize(200, 200);
	m_abbey->m_image = MG_IMAGE->findImage("town_abbey");
	m_abbey->SetTriggerWhenClick(this, &TownScene::Show_abbey);
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);

	CButton* m_graveyard = new CButton();
	m_graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 - 150);
	m_graveyard->SetButtonSize(200, 200);
	m_graveyard->m_image = MG_IMAGE->findImage("town_graveyard");
	m_graveyard->SetTriggerWhenClick(this, &TownScene::Show_graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);

	CButton* m_guild = new CButton();
	m_guild->m_transform->m_pos = Vector2(WINSIZEX / 2 - 180, WINSIZEY / 2 - 250);
	m_guild->SetButtonSize(200, 200);
	m_guild->m_image = MG_IMAGE->findImage("town_guild");
	m_guild->SetTriggerWhenClick(this, &TownScene::Show_guild);
	MG_GMOBJ->RegisterObj("Guild", m_guild);

	CButton* m_blacksmith = new CButton();
	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2 - 100);
	m_blacksmith->SetButtonSize(500, 500);
	m_blacksmith->m_image = MG_IMAGE->findImage("town_blacksmith");
	m_blacksmith->SetTriggerWhenClick(this, &TownScene::Show_blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);

	CButton* m_sanitarium = new CButton();
	m_sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 550, WINSIZEY / 2 - 280);
	m_sanitarium->SetButtonSize(200, 200);
	m_sanitarium->m_image = MG_IMAGE->findImage("town_sanitarium");
	m_sanitarium->SetTriggerWhenClick(this, &TownScene::Show_sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	CButton* m_tavern = new CButton();
	m_tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 700, WINSIZEY / 2 - 150);
	m_tavern->SetButtonSize(200, 200);
	m_tavern->m_image = MG_IMAGE->findImage("town_tavern");
	m_tavern->SetTriggerWhenClick(this, &TownScene::Show_tavern);
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);

	CButton* m_statue = new CButton();
	m_statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 350, WINSIZEY / 2 - 80);
	m_statue->SetButtonSize(200, 200);
	m_statue->m_image = MG_IMAGE->findImage("town_statue");
	m_statue->SetTriggerWhenClick(this, &TownScene::Show_town_statue);
	MG_GMOBJ->RegisterObj("Statue", m_statue);

	CButton* m_nomad_wagon = new CButton();
	m_nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 + 30);
	m_nomad_wagon->SetButtonSize(200, 200);
	m_nomad_wagon->m_image = MG_IMAGE->findImage("town_nomad_wagon");
	m_nomad_wagon->SetTriggerWhenClick(this, &TownScene::Show_nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);

	CButton* m_stage_coach = new CButton();
	m_stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 850, WINSIZEY / 2 - 50);
	m_stage_coach->SetButtonSize(200, 200);
	m_stage_coach->m_image = MG_IMAGE->findImage("town_stage_coach");
	m_stage_coach->SetTriggerWhenClick(this, &TownScene::Show_stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);

	CButton* m_campingTrainer = new CButton();
	m_campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 900, WINSIZEY / 2 - 330);
	m_campingTrainer->SetButtonSize(200, 200);
	m_campingTrainer->m_image = MG_IMAGE->findImage("town_camping_trainer");
	m_campingTrainer->SetTriggerWhenClick(this, &TownScene::Show_campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);
}

void TownScene::Show_abbey( )
{
	
}

void TownScene::Show_blacksmith( )
{
	
}

void TownScene::Show_campingTrainer( )
{
	
}

void TownScene::Show_graveyard( )
{
	
}

void TownScene::Show_guild( )
{
	
}

void TownScene::Show_nomad_wagon( )
{
	
}

void TownScene::Show_stage_coach( )
{
	
}

void TownScene::Show_town_statue()
{
	
}

void TownScene::Show_sanitarium()
{
	
}

void TownScene::Show_tavern()
{
	
}

void TownScene::Set_EST_UI()
{
	

	if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
	{
		Isinput = !Isinput;
	}
	
	if (abbey_rc.CheckCollisionWithPoint(m_ptMouse)&& Isinput)
	{
		Show_abbey();
	}
	if (blacksmith_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_blacksmith();
	}
	if (campingTrainer_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_campingTrainer();
	}
	if (graveyard_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_graveyard();
	}
	if (guild_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_guild();
	}
	if (nomad_wagon_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_nomad_wagon();
	}
	if (sanitarium_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_sanitarium();
	}

	if (stage_coach_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_stage_coach();
	}

	if (town_statue_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_town_statue();
	}

	if (tavern_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_tavern();
	}
}

