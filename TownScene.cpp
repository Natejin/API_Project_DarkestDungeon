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

	SetIMG_Est(); //건물 버튼.
	Set_quick(); //나가기 버튼
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

	

}

void TownScene::Render()
{

}

void TownScene::Render(HDC _hdc)
{
	if (abbey_b)
	{
		TextOut(_hdc, 50, 100, "수도원", lstrlen("수도원"));
		if (abbey_ui == true)
		{
			MG_IMAGE->findImage("abbey.character.bg")->render(_hdc);
			MG_IMAGE->findImage("abbey.character")->render(_hdc);
			abbey_ui = false;
		}
	}
	if (blacksmith_b)
	{
		TextOut(_hdc, 50, 150, "대장간", lstrlen("대장간")); 
		if (blacksmith_ui == true)
		{
			MG_IMAGE->findImage("blacksmith.character.bg")->render(_hdc);
			MG_IMAGE->findImage("blacksmith.character")->render(_hdc);
			blacksmith_ui = false;
		}
	}
	if (campingTrainer_b)
	{
		TextOut(_hdc, 50, 200, "캠프", lstrlen("캠프"));
		if (campingTrainer_ui == true)
		{
			MG_IMAGE->findImage("camping_trainer.character.bg")->render(_hdc);
			MG_IMAGE->findImage("camping_trainer.character")->render(_hdc);
			campingTrainer_ui = false;
		}
	}
	if (graveyard_b)
	{
		TextOut(_hdc, 50, 250, "무덤", lstrlen("무덤"));
		if (graveyard_ui == true)
		{
			MG_IMAGE->findImage("graveyard.character.bg")->render(_hdc);
			MG_IMAGE->findImage("graveyard.character")->render(_hdc);
			graveyard_ui = false;
		}
	}
	if (guild_b)
	{
		TextOut(_hdc, 50, 300, "길드", lstrlen("길드"));
		if (guild_ui == true)
		{
			MG_IMAGE->findImage("guild.character.bg")->render(_hdc);
			MG_IMAGE->findImage("guild.character")->render(_hdc);
			guild_ui = false;
		}
	}
	if (sanitarium_b)
	{
		TextOut(_hdc, 50, 350, "요양원", lstrlen("요양원"));
		if (sanitarium_ui == true)
		{
			MG_IMAGE->findImage("sanitarium.character.bg")->render(_hdc);
			MG_IMAGE->findImage("sanitarium.character")->render(_hdc);
			sanitarium_ui = false;
		}
	}
	if (tavern_b)
	{
		TextOut(_hdc, 50, 400, "여관", lstrlen("여관")); 
		if (tavern_ui == true)
		{
			MG_IMAGE->findImage("tavern.character.bg")->render(_hdc);
			MG_IMAGE->findImage("tavern.character")->render(_hdc);
			tavern_ui = false;
		}
	}
	if (town_statue_b)
	{
		TextOut(_hdc, 50, 450, "선조의 회고록", lstrlen("선조의 회고록"));
		if (town_statue_ui == true)
		{
			MG_IMAGE->findImage("statue.character.bg")->render(_hdc);
			MG_IMAGE->findImage("statue.character")->render(_hdc);
			town_statue_ui = false;
		}
	}
	if (nomad_wagon_b)
	{
		TextOut(_hdc, 50, 500, "유목민마차", lstrlen("유목민마차"));
		if (nomad_wagon_ui == true)
		{
			MG_IMAGE->findImage("nomad_wagon.character.bg")->render(_hdc);
			MG_IMAGE->findImage("nomad_wagon.character")->render(_hdc);
			nomad_wagon_ui = false;
		}
	}
	if (stage_coach_b)
	{
		TextOut(_hdc, 50, 550, "역마차", lstrlen("역마차"));
		if (stage_coach_ui == true)
		{
			MG_IMAGE->findImage("stage_coach.character.bg")->render(_hdc);
			MG_IMAGE->findImage("stage_coach.character")->render(_hdc);
			stage_coach_ui = false;
		}
	}
}

void TownScene::SetIMG_Est() //건물 버튼.
{
	CButton* m_abbey = new CButton();
	m_abbey->m_transform->m_pos = Vector2(WINSIZEX / 2 - 350, WINSIZEY / 2 - 500);
	m_abbey->SetButtonSize(200, 200);
	m_abbey->m_image = MG_IMAGE->findImage("town_abbey");
	m_abbey->SetTriggerWhenClick(this, &TownScene::Show_abeey);
	MG_GMOBJ->RegisterObj("Abbey", m_abbey);

	CButton* m_graveyard = new CButton();
	m_graveyard->m_transform->m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 - 150);
	m_graveyard->SetButtonSize(200, 200);
	m_graveyard->m_image = MG_IMAGE->findImage("town_graveyard");
	m_graveyard->SetTriggerWhenClick(this, &TownScene::Show_graveyard);
	MG_GMOBJ->RegisterObj("Graveyard", m_graveyard);

	CButton* m_guild = new CButton();
	m_guild->m_transform->m_pos = Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2 - 250);
	m_guild->SetButtonSize(200, 200);
	m_guild->m_image = MG_IMAGE->findImage("town_guild");
	m_guild->SetTriggerWhenClick(this, &TownScene::Show_guild);
	MG_GMOBJ->RegisterObj("Guild", m_guild);

	CButton* m_blacksmith = new CButton();
	m_blacksmith->m_transform->m_pos = Vector2(WINSIZEX / 2 + 80, WINSIZEY / 2 - 150);
	m_blacksmith->SetButtonSize(200, 200);
	m_blacksmith->m_image = MG_IMAGE->findImage("town_blacksmith");
	m_blacksmith->SetTriggerWhenClick(this, &TownScene::Show_blacksmith);
	MG_GMOBJ->RegisterObj("Blacksmith", m_blacksmith);

	CButton* m_sanitarium = new CButton();
	m_sanitarium->m_transform->m_pos = Vector2(WINSIZEX / 2 - 580, WINSIZEY / 2 - 380);
	m_sanitarium->SetButtonSize(200, 200);
	m_sanitarium->m_image = MG_IMAGE->findImage("town_sanitarium");
	m_sanitarium->SetTriggerWhenClick(this, &TownScene::Show_sanitarium);
	MG_GMOBJ->RegisterObj("Sanitarium", m_sanitarium);

	CButton* m_tavern = new CButton();
	m_tavern->m_transform->m_pos = Vector2(WINSIZEX / 2 - 750, WINSIZEY / 2 - 250);
	m_tavern->SetButtonSize(200, 200);
	m_tavern->m_image = MG_IMAGE->findImage("town_tavern");
	m_tavern->SetTriggerWhenClick(this, &TownScene::Show_tavern);
	MG_GMOBJ->RegisterObj("Tavern", m_tavern);

	CButton* m_statue = new CButton();
	m_statue->m_transform->m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 - 80);
	m_statue->SetButtonSize(200, 200);
	m_statue->m_image = MG_IMAGE->findImage("town_statue");
	m_statue->SetTriggerWhenClick(this, &TownScene::Show_town_statue);
	MG_GMOBJ->RegisterObj("Statue", m_statue);

	CButton* m_nomad_wagon = new CButton();
	m_nomad_wagon->m_transform->m_pos = Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2 + 80);
	m_nomad_wagon->SetButtonSize(200, 200);
	m_nomad_wagon->m_image = MG_IMAGE->findImage("town_nomad_wagon");
	m_nomad_wagon->SetTriggerWhenClick(this, &TownScene::Show_nomad_wagon);
	MG_GMOBJ->RegisterObj("Nomad_wagon", m_nomad_wagon);

	CButton* m_stage_coach = new CButton();
	m_stage_coach->m_transform->m_pos = Vector2(WINSIZEX / 2 - 880, WINSIZEY / 2 - 50);
	m_stage_coach->SetButtonSize(200, 200);
	m_stage_coach->m_image = MG_IMAGE->findImage("town_stage_coach");
	m_stage_coach->SetTriggerWhenClick(this, &TownScene::Show_stage_coach);
	MG_GMOBJ->RegisterObj("Stage_coach", m_stage_coach);

	CButton* m_campingTrainer = new CButton();
	m_campingTrainer->m_transform->m_pos = Vector2(WINSIZEX / 2 - 920, WINSIZEY / 2 - 400);
	m_campingTrainer->SetButtonSize(200, 200);
	m_campingTrainer->m_image = MG_IMAGE->findImage("town_camping_trainer");
	m_campingTrainer->SetTriggerWhenClick(this, &TownScene::Show_campingTrainer);
	MG_GMOBJ->RegisterObj("CampingTrainer", m_campingTrainer);
}
void TownScene::Show_abeey()
{
	abbey_b = !abbey_b;
	
}
void TownScene::Show_blacksmith( )
{
	blacksmith_b = !blacksmith_b;
}
void TownScene::Show_campingTrainer( )
{
	campingTrainer_b = !campingTrainer_b;
}
void TownScene::Show_graveyard( )
{
	graveyard_b = !graveyard_b;
}
void TownScene::Show_guild( )
{
	guild_b = !guild_b;
}
void TownScene::Show_nomad_wagon( )
{
	nomad_wagon_b = !nomad_wagon_b;
}
void TownScene::Show_stage_coach( )
{
	stage_coach_b = !stage_coach_b;
}
void TownScene::Show_town_statue()
{
	town_statue_b = !town_statue_b;
}
void TownScene::Show_sanitarium()
{
	sanitarium_b = !sanitarium_b;
}
void TownScene::Show_tavern()
{
	tavern_b = !tavern_b;
}

void TownScene::Set_quick()
{
	//나가기버튼
	CButton* m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(WINSIZEX-800 , 100);
	m_quick->SetButtonSize(200, 200);
	m_quick->m_image = MG_IMAGE->findImage("quick");
	MG_GMOBJ->RegisterObj("Abbey", m_quick);
}
