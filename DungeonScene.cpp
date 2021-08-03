#include "framework.h"
#include "DungeonScene.h"
#include "CHero.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CParty.h"

DungeonScene::DungeonScene()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 2;
	isDoorClick = false;
}

DungeonScene::~DungeonScene()
{

}




HRESULT DungeonScene::Init()
{
	m_dungeonState = DUNGEONSTATE::ROAD;
	dungeonMode = DUNGEONMODE::WALK;
	CreateDungeon();
	CreateRoom();
	CreateRoad();
	CreateParty();
	CreateDoor();
	m_roadBG->isActive = true;
	return S_OK;
}

HRESULT DungeonScene::Init(bool managerInit)
{

	return S_OK;
}

void DungeonScene::Release()
{
}

void DungeonScene::Update()
{
	if (dungeonMode == DUNGEONMODE::WALK)
	{
		m_party->FormationMove();
		m_party->decreaseBright_movement();
		m_party->SetFormation();
		CheckDoor();
	}
	else if (dungeonMode == DUNGEONMODE::BATTLE)
	{

	}
	else {
	
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
	}
	else {

	}
}


#pragma region InitDungeon
void DungeonScene::CreateDungeon()
{
	//맵을 생성
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			DungeonData dungeonData;
			dungeonMap[i][j] = dungeonData;
		}
	}

	//현재위치(시작위치)를 맵의 중앙에 위치
	curPos = Vector2Int(MAPSIZE / 2, MAPSIZE / 2);
	dungeonMap[curPos.x][curPos.y].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;

	CreateMapPart(curPos.x, curPos.y, 0, Vector2Int(0, 0));
	curDunheonMap = dungeonMap[curPos.x][curPos.y];
}

void DungeonScene::CreateMapPart(int i, int j, int count, Vector2Int _lastDir)
{

	if (_lastDir != Vector2Int(0, 0))
	{
		if (remainRoom < 0) //생성할 방개수가 0개인경우
		{
			return;
		}
		if (i < 0 || // x축방이 0보다 작음
			i > MAPSIZE || // x축방이 최대치보다 큼
			j < 0 || // y축방이 0보다 작음
			j > MAPSIZE || // y축방이 최대치보다 큼
			dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE) // 해당방이 존재함
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
	//방일때
	else {
		if (_lastDir == Vector2Int(0, 0))
		{
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;
		}
		else {
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
	m_party = new CParty;
	m_party->Init(1,1,1);
	
	auto party = MG_GAME->GetHeroes();
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(210 + 20 * i, 360);
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
	door1.SetRect(180, 0, 220, WINSIZEY);
	door1.SetRect(WORLDSIZEX - 535, 0, WORLDSIZEX - 495, WINSIZEY);
}

void DungeonScene::CreateRoad()
{
	//이부분
	auto road = new CBG_Road();
	road->Init();
	road->isActive = false;
	MG_GMOBJ->RegisterObj("RoadBG", road);
	m_roadBG = road;
}
#pragma endregion




#pragma region Road
void DungeonScene::CheckDoor()
{
	if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->getPos())||
		door2.CheckCollisionWithPoint(m_party->GetHero(0)->getPos()))
	{
		isDoorClick = true;
	}
	else {
		isDoorClick = false;
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
		sprintf_s(str, "문에 플레이어가 닿음");
		TextOut(_hdc, 0, 140, str, strlen(str));
	}
}


#pragma endregion
