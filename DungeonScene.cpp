#include "framework.h"
#include "DungeonScene.h"
#include "CButton.h"
#include "CHero.h"
#include "CParty.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CObjOnRoad.h"
#include "dungeonUI.h"
#include "dungeonUI_HeroInfo.h"
#include "CMapSystem.h"
#include "CBattleSystem.h"
#include "CInventorySystem.h"
#include "TreasureEventPanel.h"


DungeonScene::DungeonScene()
{
	isDoorClick = false;

	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;

}
DungeonScene::~DungeonScene() {}

HRESULT DungeonScene::Init()
{
	MG_SOUND->stop(SOUND::Town);
	ActivateSound();

	m_dungeonState = DUNGEONSTATE::ROAD;
	m_dungeonMode = DUNGEONMODE::WALK;

	CreateInvenSystem();
	CreateDungeonMap();
	CreateDungeonUI();
	CreateBattleSystem();

	CreateParty();

	CreateRoom();
	CreateRoad();
	CreateDoor();

	ActivateRoom();

	return S_OK;
}

HRESULT DungeonScene::Init(bool managerInit)
{
	return S_OK;
}

void DungeonScene::Release()
{

	MG_GMOBJ->RemoveObj(m_roomBG);
	MG_GMOBJ->RemoveObj(m_roadBG);
	MG_GMOBJ->RemoveObj(treasurePanel);

	for (size_t i = 0; i < m_roadObjs.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_roadObjs[i]);
	}


	MG_GMOBJ->RemoveObj(m_pBattleSystem);
	MG_GMOBJ->RemoveObj(m_pInvenSystem);
	MG_GMOBJ->RemoveObj(m_treasurePanel);
	MG_GMOBJ->RemoveObj(m_dungeonUI);
	MG_GMOBJ->RemoveObj(m_dungeonUIinfo);


	MG_GMOBJ->RemoveObj(m_party);

}

void DungeonScene::Update()
{
	if (MG_INPUT->isOnceKeyDown(VK_F5))
	{
		MG_SCENE->changeScene(SCENETYPE::Town);
	}


	if (m_dungeonMode == DUNGEONMODE::WALK)
	{
		if (!isOpenedPanel)
		{
			m_party->FormationMove();
		}
	
		m_party->getStress_movement();
		m_party->decreaseBright_movement();

		CheckDoor(); //TODO
		setRoadNum();

		if (MG_INPUT->isOnceKeyDown(VK_F2))
		{
			m_pBattleSystem->BattleSystemInitiate();
		}

		if (MG_INPUT->isOnceKeyDown(VK_F6))
		{
			m_pBattleSystem->isBoss = true;
			m_pBattleSystem->BattleSystemInitiate();
		}
	}
	else if (m_dungeonMode == DUNGEONMODE::BATTLE)
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
		//m_roadObj->Render(_hdc);
	}
	else 
	{

	}
}

//==================================

#pragma region InitDungeon

void DungeonScene::CreateDungeonMap()
{
	m_pMapSystem = new CMapSystem();

	m_pMapSystem->Init();
	m_pMapSystem->dungeonScene = this;
	MG_GMOBJ->RegisterObj("mapSystem", m_pMapSystem);
}

void DungeonScene::CreateParty()
{
	m_party = MG_GAME->GetParty();
	for (int i = 0; i < MG_GAME->GetHeroPartySize(); i++)
	{
		if (MG_GAME->GetHeroFromParty(i) != nullptr)
		{
			MG_GAME->GetHeroFromParty(i)->m_transform->m_pos = Vector2(500 - 120 * i, 640);
			MG_GAME->GetHeroFromParty(i)->SetPartyIndex(i);
			MG_GAME->GetHeroFromParty(i)->SetPartyPos(i);
			MG_GAME->GetHeroFromParty(i)->Enable();

			m_party->SetHero(MG_GAME->GetHeroFromParty(i));
		}
	}

	MG_GAME->SetCurSelHero(0);
	m_party->Enable();
	MG_CAMERA->SetTarget(m_party->GetHero(0));
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

	m_roomObj = new CObjOnRoad();
	m_roomObj->Init();
	m_roomObj->Disable();
	m_roomObj->m_dungeonScene = this;
	MG_GMOBJ->RegisterObj("roomObj_", m_roomObj);

	//이걸 그냥 createUI에 넣어버릴까
	m_treasurePanel = new TreasureEventPanel();
	m_treasurePanel->m_dungeonScene = this;
	m_treasurePanel->Init();
	m_treasurePanel->Disable();
	MG_GMOBJ->RegisterObj("treasureEventPanel", m_treasurePanel);
}

void DungeonScene::CreateRoad()
{
	auto road = new CBG_Road();
	road->Init();
	road->isActive = false;

	MG_GMOBJ->RegisterObj("RoadBG", road);
	m_roadBG = road;
	
	for (size_t i = 0; i < 3; i++)
	{
		CObjOnRoad* obj = new CObjOnRoad();
		obj->Init();
		obj->Disable();
		obj->m_dungeonScene = this;
		m_roadObjs.push_back(obj);
		MG_GMOBJ->RegisterObj("roadObj_", obj);
	}
}

void DungeonScene::CreateDoor()
{
	//Road, Room�� ���� door��ġ ������ Ȯ��
}

void DungeonScene::CreateInvenSystem()
{
	m_pInvenSystem = new CInventorySystem();
	m_pInvenSystem->Init();
	MG_GMOBJ->RegisterObj("inventory", m_pInvenSystem);
}

void DungeonScene::CreateBattleSystem()
{
	m_pBattleSystem = new CBattleSystem();
	m_pBattleSystem->scene = this;
	m_pBattleSystem->Init();
	m_pBattleSystem->dungeonUI = m_dungeonUI;
	m_pBattleSystem->dungeonUIHeroinfo = m_dungeonUIinfo;
	m_pBattleSystem->Disable();
	m_dungeonUI->m_pBattleSystem = m_pBattleSystem;
	m_dungeonUI->SetSkillButton();
	MG_GMOBJ->RegisterObj("battleSystem", m_pBattleSystem);
}

void DungeonScene::CreateDungeonUI()
{
	m_dungeonUI = new dungeonUI;
	m_dungeonUI->m_pMapSystem = m_pMapSystem;
	m_dungeonUI->m_invenSystem = m_pInvenSystem;
	m_dungeonUI->scene = this;
	m_dungeonUI->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUI", m_dungeonUI);

	m_dungeonUIinfo = new CDungeonUI_HeroInfo;
	m_dungeonUIinfo->scene = this;
	m_dungeonUIinfo->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUIinfo", m_dungeonUIinfo);
}

#pragma endregion


#pragma region Road
void DungeonScene::setRoadNum()
{
	if (m_dungeonState == DUNGEONSTATE::ROAD)
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (i * ROOMSIZE < m_party->GetHero(0)->m_transform->m_pos.x)
			{
				m_roadNum = i + 1;
			}
		}

		if (m_previousRoadMap != m_roadNum)
		{
			if (m_previousRoadMap == 2 && m_roadNum == 3)
			{
				m_pMapSystem->UseKeyBoardToMoveCurPoint();
			}

			if (m_previousRoadMap == 3 && m_roadNum == 2)
			{
				m_pMapSystem->UseKeyBoardToReverseMoveCurPoint();
			}

			if (m_previousRoadMap == 4 && m_roadNum == 5)
			{
				m_pMapSystem->UseKeyBoardToMoveCurPoint();
			}

			if (m_previousRoadMap == 5 && m_roadNum == 4)
			{
				m_pMapSystem->UseKeyBoardToReverseMoveCurPoint();
			}

			m_previousRoadMap = m_roadNum;
		}
	}
}

void DungeonScene::CheckDoor()
{
	if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos) ||
		door2.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos))
	{
		isDoorClick = true;
		if (m_dungeonState == DUNGEONSTATE::ROAD)
		{
			m_pMapSystem->canMoveAnotherRoom = false;
			if (MG_INPUT->isOnceKeyDown(VK_UP))
			{
				if (m_dungeonState == DUNGEONSTATE::ROAD)
				{
					m_pMapSystem->canMoveAnotherRoom = false;
				}
				else {
					m_pMapSystem->canMoveAnotherRoom = true;
				}
				ActivateRoom();
			}
		}
		else 
		{
			m_pMapSystem->canMoveAnotherRoom = true;
		}
	}

	else
	{
		m_pMapSystem->canMoveAnotherRoom = false;
		isDoorClick = false;
	}
}

void DungeonScene::ActivateRoad()
{
	m_previousRoadMap = 1;
	m_roomBG->isActive = false;
	m_roadBG->isActive = true;

	for (size_t i = 0; i < 3; i++)
	{
		SetRoadObject(i);
		m_roadObjs[i]->Enable();
	}

	m_roomObj->Disable();
	
	m_dungeonState = DUNGEONSTATE::ROAD;
	MG_CAMERA->SetWorldSize(Vector2(WORLDSIZEX, WORLDSIZEY));

	door1.SetRect(220, 0, 500, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 500, 0, WORLDSIZEX - 220, WINSIZEY);
	vector<CHero*> party = m_party->GetParty();

	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(500 - 120 * i, 640);
	}
}

void DungeonScene::ActivateSound()
{
	MG_SOUND->play(SOUND::Ruins_base);
	MG_SOUND->play(SOUND::Ruins_dark);
}

void DungeonScene::DeactivateSound()
{
	MG_SOUND->stop(SOUND::Ruins_base);
	MG_SOUND->stop(SOUND::Ruins_dark);
}

void DungeonScene::SetRoadObject(int i)
{
	DungeonData dungeonData = m_pMapSystem->GetCurDungeonData(i);
	m_roadObjs[i]->Init(dungeonData.m_roadObjType, i, dungeonData.isPassed, dungeonData.isOpenedTreasure);
	m_pMapSystem->SetIsPassed(i);
}

#pragma endregion


#pragma region Room
void DungeonScene::ActivateRoom()
{
	m_pMapSystem->SetIsPassed();
	m_roadBG->isActive = false;
	m_roomBG->isActive = true;

	for (size_t i = 0; i < 3; i++)
	{
		m_roadObjs[i]->Disable();
	}

	m_dungeonState = DUNGEONSTATE::ROOM;
	m_roomBG->m_spriteRenderer->SetImage(roomRandom[MG_RND->getInt(roomRandom.size())]);
	MG_CAMERA->SetWorldSize(Vector2(WINSIZEX, WINSIZEY));

	door1.SetRect(0, 0, 350, WINSIZEY);
	door2.SetRect(WINSIZEX - 350, 0, WINSIZEX, WINSIZEY);

	vector<CHero*> party = m_party->GetParty();
	m_pMapSystem->UseKeyBoardToMoveCurPoint();
	switch (m_pMapSystem->GetCurDungeonData().dungeonMapState)
	{
	case DUNGEONMAPSTATE::Room_Empty:
		for (int i = 0; i < party.size(); i++)
		{
			party[i]->m_transform->m_pos = Vector2(500 - 120 * i, 640);
		}
		break;

	case DUNGEONMAPSTATE::Room_Enemy:
		m_pBattleSystem->isBoss = false;
		m_pBattleSystem->BattleSystemInitiate();
		break;

	case DUNGEONMAPSTATE::Room_Trasure:
		for (int i = 0; i < party.size(); i++)
		{
			party[i]->m_transform->m_pos = Vector2(500 - 120 * i, 640);
		}
		break;
	
	case DUNGEONMAPSTATE::Room_Boss:
		m_pBattleSystem->isBoss = true;
		m_pBattleSystem->BattleSystemInitiate();
		break;
	
	default:
		break;
	}

	if (m_pMapSystem->GetCurDungeonData().dungeonMapState == DUNGEONMAPSTATE::Room_Trasure)
	{

		SetRoomObject();
		m_roomObj->Enable();
	}
}

void DungeonScene::SetRoomObject()
{
	DungeonData dungeonData = m_pMapSystem->GetCurDungeonData();
	m_roomObj->Init(dungeonData.m_roadObjType, 3, dungeonData.isPassed, dungeonData.isOpenedTreasure);
	m_pMapSystem->SetIsPassed();
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