#include "framework.h"
#include "DungeonScene.h"
#include "CHero.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CParty.h"
#include "CButton.h"
#include "CRoadObject.h"
#include "dungeonUI.h"
#include "dungeonUI_info.h"

DungeonScene::DungeonScene()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 2;
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
	CreateDungeon();
	CreateRoom();
	CreateRoad();
	CreateParty();
	CreateDoor();

	m_dungeonUI = new dungeonUI;
	m_dungeonUI->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUI", m_dungeonUI);
	
	m_dungeonUIinfo = new dungeonUI_info;
	m_dungeonUIinfo->Init();
	MG_GMOBJ->RegisterObj("scene1_dungeonUIinfo", m_dungeonUIinfo);

	m_roadBG->isActive = true;

	return S_OK;
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
	if (m_dungeonState == DUNGEONSTATE::ROOM)
	{

	}

	else if (m_dungeonState == DUNGEONSTATE::ROAD)
	{
		ShowDungeonInfo(_hdc);
		m_roadObj->Render(_hdc);
	}

	else 
	{

	}
}


#pragma region InitDungeon
void DungeonScene::CreateDungeon()
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			DungeonData dungeonData;
			dungeonMap[i][j] = dungeonData;
		}
	}

	curPos = Vector2Int(MAPSIZE / 2, MAPSIZE / 2);
	dungeonMap[curPos.x][curPos.y].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;

	CreateMapPart(curPos.x, curPos.y, 0, Vector2Int(0, 0));
	curDunheonMap = dungeonMap[curPos.x][curPos.y];
}

void DungeonScene::CreateMapPart(int i, int j, int count, Vector2Int _lastDir)
{
	if (_lastDir != Vector2Int(0, 0))
	{
		if (remainRoom < 0) 
		{
			return;
		}
		if (i < 0 ||
			i > MAPSIZE || 
			j < 0 ||
			j > MAPSIZE || 
			dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE) // �ش���� ������
			return;
	}

#ifdef _DEBUG
	//system("CLS");
	//for (size_t m = 0; m < MAPSIZE; m++)
	//{
	//	for (size_t n = 0; n < MAPSIZE; n++)
	//	{
	//		_cprintf("%d ", (int)dungeonMap[m][n].dungeonMapState);
	//	}
	//	_cprintf("\n");
	//}

#endif // _DEBUG

	if (count > 0)
	{
		count--;
		if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Enemy;
		}
		else if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Trasure;
		}
		else if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Trap;
		}
		else {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Empty;
		}
		
		CreateMapPart(i + _lastDir.x, j + _lastDir.y, count, _lastDir);
	}
	else {
		if (_lastDir == Vector2Int(0, 0))
		{
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;
		}
		else 
		{
			if (!(bool)MG_RND->getInt(4)) {
				dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Enemy;
			}
			else if (!(bool)MG_RND->getInt(4)) {
				dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Trasure;
			}

			else {
				dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;
			}
		}

		remainRoom--;

		Vector2Int lastDir;
		bool noneDir = true;
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(1, 0);
			dungeonMap[i][j].dirMap[(int)DIR::Right] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(-1, 0);
			dungeonMap[i][j].dirMap[(int)DIR::Left] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, 1);
			dungeonMap[i][j].dirMap[(int)DIR::Down] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}

		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, -1);
			dungeonMap[i][j].dirMap[(int)DIR::Up] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}

		if (noneDir)
		{
			vector<int> dirVec;
			for (int k = 0; k < 4; k++)
			{
				Vector2Int newDic = GetDirFromInt(k);
				if (_lastDir != newDic)
				{
					dungeonMap[i][j].dirMap[k] = true;
					CreateMapPart(i + newDic.x, j + newDic.y, 3, newDic);
					return;
				}
			}
		}
	}
}

Vector2Int DungeonScene::GetDirFromInt(int dir) {
	switch (dir)
	{
	case (int)DIR::Left:
		return Vector2Int(-1, 0);
		break;
	case (int)DIR::Up:
		return Vector2Int(-0, -1);
		break;
	case (int)DIR::Right:
		return Vector2Int(1, 0);
		break;
	case (int)DIR::Down:
		return Vector2Int(0, 1);
		break;
	}
}

void DungeonScene::CreateParty()
{
	//이부분을 게임 매니저로 옮겨도 된다면 GetParty도 만들 수 있을듯함
	//m_party = new CParty;
	//m_party->Init(1,1,1);
	//
	//auto party = MG_GAME->GetHeroes();
	//for (int i = 0; i < party.size(); i++)
	//{
	//	party[i]->m_transform->m_pos = Vector2(210 + 20 * i, 360);
	//}
	//m_party->SetParty(party);

	MG_GAME->setParty();
	m_party = MG_GAME->GetParty();

	auto party = MG_GAME->GetHeroes();
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(210 + 20 * i, 500);
	}
	m_party->SetParty(party);

	MG_GMOBJ->RegisterObj("Party", m_party);
	MG_CAMERA->SetTarget(m_party->GetHero(0));
}

void DungeonScene::CreateRoom()
{
	auto room = new CBG_Room();
	room->Init();
	room->isActive = false;
	MG_GMOBJ->RegisterObj("RoomBG", room);
	m_roomBG = room;
}

void DungeonScene::CreateDoor()
{
	door1.SetRect(145, 0, 365, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 675, 0, WORLDSIZEX - 355, WINSIZEY);
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
	//switch (curDunheonMap.dungeonMapState)
	//{
	//case DUNGEONMAPSTATE::Road_Empty:
	//	break;

	//case DUNGEONMAPSTATE::Road_Enemy:
	//	break;

	//case DUNGEONMAPSTATE::Road_Trap:
	//	break;

	//case DUNGEONMAPSTATE::Road_Trasure:
	//	
	// break;
	//}
}

void DungeonScene::CheckDoor()
{
	if (true)
	{
		if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos) ||
			door2.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos))
		{
			isDoorClick = true;
			if (MG_INPUT->isOnceKeyDown(VK_UP))
			{
				isDoorClick = false;
				m_roadBG->isActive = false;
				m_roomBG->isActive = true;
			}
		}
		else
		{
			isDoorClick = false;
		}
	}
	
}
#pragma endregion


#pragma region DebugLog
void DungeonScene::ShowDungeonInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

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
}
#pragma endregion