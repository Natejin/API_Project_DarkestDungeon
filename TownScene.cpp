#include "framework.h"
#include "TownScene.h"
#include"CBG_Town.h"
#include "CButton.h"

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

void TownScene::Update(HDC _hdc)
{
	if (abbey_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_abbey(_hdc);
	}
	if (blacksmith_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_blacksmith(_hdc);
	}
	if (campingTrainer_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_campingTrainer(_hdc);
	}
	if (graveyard_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_graveyard(_hdc);
	}
	if (guild_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_guild(_hdc);
	}
	if (nomad_wagon_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_nomad_wagon(_hdc);
	}
	if (sanitarium_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_sanitarium(_hdc);
	}

	if (stage_coach_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_stage_coach(_hdc);
	}

	if (town_statue_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_town_statue(_hdc);
	}

	if (tavern_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_tavern(_hdc);
	}
}

void TownScene::Render(HDC _hdc)
{

}

void TownScene::Show_abbey(HDC _hdc)
{
	CButton* m_abbey = new CButton();
	m_abbey->m_transform->m_pos = Vector2(0, 0);
	m_abbey->SetButtonSize(200, 200);
	m_abbey->m_image = MG_IMAGE->findImage("abbey.character");
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);
}

void TownScene::Show_blacksmith(HDC _hdc)
{
	CButton* m_blacksmith = new CButton();
	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	m_blacksmith->SetButtonSize(500, 500);
	m_blacksmith->m_image = MG_IMAGE->findImage("blacksmith.character");
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);
}

void TownScene::Show_campingTrainer(HDC _hdc)
{
	CButton* m_campingTrainer = new CButton();
	m_campingTrainer->m_transform->m_pos = Vector2(0, 0);
	m_campingTrainer->SetButtonSize(200, 200);
	m_campingTrainer->m_image = MG_IMAGE->findImage("camping_trainer.character");
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);
}

void TownScene::Show_graveyard(HDC _hdc)
{
	CButton* m_graveyard = new CButton();
	m_graveyard->m_transform->m_pos = Vector2(0, 0);
	m_graveyard->SetButtonSize(200, 200);
	m_graveyard->m_image = MG_IMAGE->findImage("graveyard.character");
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);
}

void TownScene::Show_guild(HDC _hdc)
{
	CButton* m_guild = new CButton();
	m_guild->m_transform->m_pos = Vector2(0, 0);
	m_guild->SetButtonSize(200, 200);
	m_guild->m_image = MG_IMAGE->findImage("guild.character");
	MG_GMOBJ->RegisterObj("Guild", m_guild);
}

void TownScene::Show_nomad_wagon(HDC _hdc)
{
	CButton* m_nomad_wagon = new CButton();
	m_nomad_wagon->m_transform->m_pos = Vector2(0, 0);
	m_nomad_wagon->SetButtonSize(200, 200);
	m_nomad_wagon->m_image = MG_IMAGE->findImage("nomad_wagon.character");
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);
}

void TownScene::Show_stage_coach(HDC _hdc)
{
	CButton* m_stage_coach = new CButton();
	m_stage_coach->m_transform->m_pos = Vector2(0, 0);
	m_stage_coach->SetButtonSize(200, 200);
	m_stage_coach->m_image = MG_IMAGE->findImage("stage_coach.character");
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);
}

void TownScene::Show_town_statue(HDC _hdc)
{
	CButton* m_statue = new CButton();
	m_statue->m_transform->m_pos = Vector2(0, 0);
	m_statue->SetButtonSize(200, 200);
	m_statue->m_image = MG_IMAGE->findImage("statue.character");
	MG_GMOBJ->RegisterObj("Statue", m_statue);
}

void TownScene::Show_sanitarium(HDC _hdc)
{
	CButton* m_sanitarium = new CButton();
	m_sanitarium->m_transform->m_pos = Vector2(0, 0);
	m_sanitarium->SetButtonSize(200, 200);
	m_sanitarium->m_image = MG_IMAGE->findImage("sanitarium.character");
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);
}

void TownScene::Show_tavern(HDC _hdc)
{
	CButton* m_tavern = new CButton();
	m_tavern->m_transform->m_pos = Vector2(0, 0);
	m_tavern->SetButtonSize(200, 200);
	m_tavern->m_image = MG_IMAGE->findImage("tavern.character");
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);
}

void TownScene::Set_EST_UI()
{
	CButton* m_abbey = new CButton();
	m_abbey->m_transform->m_pos = Vector2(0, 0);
	m_abbey->SetButtonSize(200, 200);
	m_abbey->m_image = MG_IMAGE->findImage("abbey.character");
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);
}
