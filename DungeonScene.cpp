#include "framework.h"
#include "DungeonScene.h"
#include "CHero.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CParty.h"
#include "CButton.h"
#include "CRoadObject.h"
#include "dungeonUI.h"
#include "dungeonUI_HeroInfo.h"
#include "CBattleSystem.h"
#include "CMapSystem.h"
#include "CInventorySystem.h"

DungeonScene::DungeonScene()
{
	isDoorClick = false;

	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;
	m_roadObj = nullptr;
}
DungeonScene::~DungeonScene() {}

HRESULT DungeonScene::Init()
{
	m_dungeonState = DUNGEONSTATE::ROAD;
	dungeonMode = DUNGEONMODE::WALK;

	//SetUIIMG();
	CreateBattleSystem();
	CreateParty();
	CreateDungeonMap();
	CreateDungeonUI();

	CreateRoom();
	CreateRoad();
	CreateDoor();

	ActivateRoom();
	return S_OK;
}

void DungeonScene::CreateDungeonUI()
{
	m_dungeonUI = new dungeonUI;
	m_dungeonUI->m_pMapSystem = m_pMapSystem;
	m_dungeonUI->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUI", m_dungeonUI);

	m_dungeonUIinfo = new dungeonUI_HeroInfo;
	m_dungeonUIinfo->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUIinfo", m_dungeonUIinfo);
}

HRESULT DungeonScene::Init(bool managerInit)
{
	return S_OK;
}

void DungeonScene::Release()
{
	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;

	for (size_t i = 0; i < enemyGroup.size(); i++)
	{
		enemyGroup[i] = nullptr;
	}
	enemyGroup.clear();
}

void DungeonScene::Update()
{
	if (dungeonMode == DUNGEONMODE::WALK)
	{
		m_party->FormationMove();
		m_party->getStress_movement();
		m_party->decreaseBright_movement();

		CheckDoor();
		setRoadNum();
	}
	else if (dungeonMode == DUNGEONMODE::BATTLE)
	{




	}
	else 
	{
	
	}
}

void DungeonScene::Render(HDC _hdc)
{
	ShowDungeonInfo(_hdc);
	if (m_dungeonState == DUNGEONSTATE::ROOM)
	{

	}
	else if (m_dungeonState == DUNGEONSTATE::ROAD)
	{
	
		m_roadObj->Render(_hdc);
	}
	else 
	{

	}
}


#pragma region InitDungeon


void DungeonScene::CreateDungeonMap()
{
	m_pMapSystem = new CMapSystem();

	m_pMapSystem->Init();

}

void DungeonScene::CreateParty()
{
	MG_GAME->setParty();
	m_party = MG_GAME->GetParty();

	auto party = MG_GAME->GetHeroes();
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(500 - 120 * i, 640);
	}
	m_party->SetParty(party);

	MG_GMOBJ->RegisterObj("Party", m_party);
	MG_CAMERA->SetTarget(m_party->GetHero(0));
	MG_GAME->GetHero(0)->isSelected = true;
}

void DungeonScene::CreateRoom()
{
	auto room = new CBG_Room();
	room->Init();
	room->isActive = false;
	room->AddSpriteRenderer(IMAGE::Ruins_room1);
	MG_GMOBJ->RegisterObj("RoomBG", room);
	m_roomBG = room;

	roomRandom.push_back(IMAGE::Ruins_room1);
	roomRandom.push_back(IMAGE::Ruins_room2);
	roomRandom.push_back(IMAGE::Ruins_room3);
	roomRandom.push_back(IMAGE::Ruins_room4);
	roomRandom.push_back(IMAGE::Ruins_room5);
	roomRandom.push_back(IMAGE::Ruins_room6);
	roomRandom.push_back(IMAGE::Ruins_room7);
	roomRandom.push_back(IMAGE::Ruins_room8);
	roomRandom.push_back(IMAGE::Ruins_room9);
}

void DungeonScene::CreateDoor()
{

}

void DungeonScene::CreateRoad()
{
	auto road = new CBG_Road();
	road->Init();
	road->isActive = false;
	MG_GMOBJ->RegisterObj("RoadBG", road);
	m_roadBG = road;

	auto roadOBJ = new CRoadObject();
	roadOBJ->Init();
	roadOBJ->isActive = false;
	MG_GMOBJ->RegisterObj("RoadOBJ", roadOBJ);
	m_roadObj = roadOBJ;
}

void DungeonScene::CreateBattleSystem()
{
	m_pBattleSystem = new CBattleSystem();
	m_pBattleSystem->isActive = false;
	MG_GMOBJ->RegisterObj("battleSystem", m_pBattleSystem);
}
#pragma endregion


#pragma region Road
void DungeonScene::setRoadNum()
{
	for (size_t i = 0; i < 6; i++)
	{
		if (i * 720 < m_party->GetHero(0)->m_transform->m_pos.x)
		{
			m_roadNum = i + 1;
		}
	}
}

void DungeonScene::setRoadKind()
{
	
}



void DungeonScene::ActivateRoad()
{
	m_roomBG->isActive = false;
	m_roadBG->isActive = true;
	m_roadObj->isActive = true;
	m_dungeonState = DUNGEONSTATE::ROAD;
	MG_CAMERA->SetWorldSize(Vector2(WORLDSIZEX, WORLDSIZEY));

	door1.SetRect(145, 0, 365, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 675, 0, WORLDSIZEX - 355, WINSIZEY);
}

void DungeonScene::CheckDoor()
{
	if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos) ||
		door2.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos))
	{
		isDoorClick = true;
		if (MG_INPUT->isOnceKeyDown(VK_UP))
		{
			isDoorClick = false;
			ActivateRoom();
		}
	}
	else
	{
		isDoorClick = false;
	}
}
#pragma endregion


#pragma region Room
void DungeonScene::ActivateRoom()
{
	m_roadBG->isActive = false;
	m_roomBG->isActive = true;
	m_roadObj->isActive = false;
	m_dungeonState = DUNGEONSTATE::ROOM;
	m_roomBG->m_spriteRenderer->SetImage(roomRandom[MG_RND->getInt(roomRandom.size())]);
	MG_CAMERA->SetWorldSize(Vector2(WINSIZEX, WINSIZEY));

	door1.SetRect(145, 0, 365, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 200, 0, WORLDSIZEX - 100, WINSIZEY);

	switch (m_pMapSystem->GetCurDungeonData().dungeonMapState)
	{
	case DUNGEONMAPSTATE::Room_Empty:

		break;
	case DUNGEONMAPSTATE::Room_Enemy:
		dungeonMode = DUNGEONMODE::BATTLE; //TODO 나중에는 방에 들어갈때 상태체크에서 몬스터일경우 변경
		m_pBattleSystem->BattleSystemInitiate();
		break;
	case DUNGEONMAPSTATE::Room_Trasure:

		break;
	case DUNGEONMAPSTATE::Room_Boss:

		break;
	default:
		break;
	}


}

#pragma endregion



#pragma region DebugLog
void DungeonScene::ShowDungeonInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));

	sprintf_s(str, "<dungeonInfo>");
	TextOut(_hdc, 0, 80, str, strlen(str));

	sprintf_s(str, "roadNum : %d", m_roadNum);
	TextOut(_hdc, 0, 100, str, strlen(str));

	sprintf_s(str, "nowScene : %d", (int)m_dungeonState);
	TextOut(_hdc, 0, 140, str, strlen(str));

	sprintf_s(str, "mousePos : %d, %d", (int)m_ptMouse.x, (int)m_ptMouse.y);
	TextOut(_hdc, 0, 180, str, strlen(str));

	switch (curDunheonMap.dungeonMapState)
	{
	case DUNGEONMAPSTATE::Road_Empty:
		sprintf_s(str, "roadState : empty");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	case DUNGEONMAPSTATE::Road_Enemy:
		sprintf_s(str, "roadState : enemy");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	case DUNGEONMAPSTATE::Road_Trasure:
		sprintf_s(str, "roadState : treasure");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	default:
		sprintf_s(str, "roadState : door");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	}

	if (isDoorClick)
	{
		sprintf_s(str, "near Door");
		TextOut(_hdc, 0, 160, str, strlen(str));
	}
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
	
	}
}
#pragma endregion

