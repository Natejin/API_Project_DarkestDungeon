#include "framework.h"
#include "CMinimapButton.h"
#include "CMapSystem.h"
#include "CUIPanel.h"
#include "DungeonScene.h"

CMapSystem::CMapSystem()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 10;
}
CMapSystem::~CMapSystem() {}

HRESULT CMapSystem::Init()
{
	minimapCenterPos = Vector2(850, 450);
	minimapOriginPos = minimapCenterPos;
	canMoveAnotherRoom = false;
	moveDistance = 12;
	SetRandomCreateValue();
	CreateDungeon();
	return S_OK;
}

void CMapSystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown('W'))
	{
		MoveCurPoint(Vector2Int(0, -1));
	}
	
	if (MG_INPUT->isOnceKeyDown('A'))
	{
		MoveCurPoint(Vector2Int(-1, 0));
	}

	if (MG_INPUT->isOnceKeyDown('D'))
	{
		MoveCurPoint(Vector2Int(1, 0));
	}

	if (MG_INPUT->isOnceKeyDown('S'))
	{
		MoveCurPoint(Vector2Int(0, 1));
	}
}

void CMapSystem::LateUpdate()
{
}

void CMapSystem::BackRender(HDC _hdc)
{
}

void CMapSystem::Render(HDC _hdc)
{
}

void CMapSystem::FrontRender(HDC _hdc)
{
}

void CMapSystem::Release()
{
}

void CMapSystem::SetRandomCreateValue()
{
	randRoomEnemy = 100;
	randRoomCurio = 0;
	randomRoadEnemy = 0;
	randomRoadCurio = 50;
	randomRoadTrap = 50;

	int _rndRoomEnemy = randRoomEnemy;
	int _rndRoomCurio = randRoomEnemy + randRoomCurio;
	rndRoom.push_back(_rndRoomEnemy < 100 ? _rndRoomEnemy : 100);
	rndRoom.push_back(_rndRoomCurio < 100 ? _rndRoomCurio : 100);

	int _rndRoadEnemy = randomRoadEnemy;
	int _rndRoadCurio = randomRoadEnemy + randomRoadCurio;
	int _rndRoadTrap = randomRoadEnemy + randomRoadCurio + randomRoadTrap;
	rndRoad.push_back(_rndRoadEnemy < 100 ? _rndRoadEnemy : 100);
	rndRoad.push_back(_rndRoadCurio < 100 ? _rndRoadCurio : 100);
	rndRoad.push_back(_rndRoadTrap < 100 ? _rndRoadTrap : 100);
}



void CMapSystem::CreateDungeon()
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
	dungeonMap[curPos.x][curPos.y].pos = curPos;

	while (remainRoom > 0)
	{
		CreateMapPart(curPos.x, curPos.y, 0, Vector2Int(0, 0));
	
	}

	curDungeonMap = dungeonMap[curPos.x][curPos.y];
	SetMapWitchCreated();
}

void CMapSystem::CreateMapPart(int i, int j, int count, Vector2Int _lastDir)
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
			dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE)
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
	dungeonMap[i][j].pos = Vector2Int(i, j);
	dungeonMap[i][j].m_roadObjType = RoadObjType::Empty;
	int random = MG_RND->getInt(100);
	if (count > 0)
	{
		count--;
		if (random < rndRoad[0]) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Enemy;
			dungeonMap[i][j].m_roadObjType = RoadObjType::Enemy;
		}
		else if (random < rndRoad[1]) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Trasure;
			dungeonMap[i][j].m_roadObjType = RoadObjType::Treasure;
		}
		else if (random < rndRoad[2]) {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Trap;
			dungeonMap[i][j].m_roadObjType = RoadObjType::Trap;
		}
		else {
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Road_Empty;
		}
		if (_lastDir == Vector2Int(1,0) || _lastDir == Vector2Int(-1, 0))
		{
			dungeonMap[i][j].isHorizontal = true;
		}
		CreateMapPart(i + _lastDir.x, j + _lastDir.y, count, _lastDir);
	}
	else {
		dungeonMap[i][j].isRoom = true;
		if (_lastDir == Vector2Int(0, 0))
		{
			dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Empty;
		}
		else
		{
			if (random < rndRoom[0]) {
				dungeonMap[i][j].dungeonMapState = DUNGEONMAPSTATE::Room_Enemy;
			}
			else if (random < rndRoom[1]) {
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
			CreateMapPart(i + lastDir.x, j + lastDir.y, roadCount, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(-1, 0);
			dungeonMap[i][j].dirMap[(int)DIR::Left] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, roadCount, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, 1);
			dungeonMap[i][j].dirMap[(int)DIR::Down] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, roadCount, lastDir);
		}

		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, -1);
			dungeonMap[i][j].dirMap[(int)DIR::Up] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, roadCount, lastDir);
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
					CreateMapPart(i + newDic.x, j + newDic.y, roadCount, newDic);
					return;
				}
			}
		}
	}
}

Vector2Int CMapSystem::GetDirFromInt(int dir) {
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

void CMapSystem::MapButtonOnOff(bool active)
{
	for (size_t i = 0; i < dungeonMapCreate.size(); i++)
	{
		dungeonMapCreate[i]->isActive = active;
	}
}

void CMapSystem::SetMapWitchCreated()
{
	int mid = MAPSIZE / 2;

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE)
			{
				CMinimapButton* minimapButton = new CMinimapButton();
				switch (dungeonMap[i][j].dungeonMapState)
				{
				case DUNGEONMAPSTATE::Road_Empty:
					minimapButton->AddSpriteRenderer(IMAGE::hall_clear);
					
					break;
				case DUNGEONMAPSTATE::Road_Enemy:
					minimapButton->AddSpriteRenderer(IMAGE::marker_battle);
					break;
				case DUNGEONMAPSTATE::Road_Trasure:
					minimapButton->AddSpriteRenderer(IMAGE::marker_curio);
					break;
				case DUNGEONMAPSTATE::Road_Trap:
					minimapButton->AddSpriteRenderer(IMAGE::marker_trap);
					break;
				case DUNGEONMAPSTATE::Room_Empty:
					minimapButton->AddSpriteRenderer(IMAGE::room_empty);
					break;
				case DUNGEONMAPSTATE::Room_Enemy:
					minimapButton->AddSpriteRenderer(IMAGE::room_battle);
					break;
				case DUNGEONMAPSTATE::Room_Trasure:
					minimapButton->AddSpriteRenderer(IMAGE::room_curio);
					break;
				case DUNGEONMAPSTATE::Room_Boss:
					minimapButton->AddSpriteRenderer(IMAGE::room_boss);
					break;
				default:
					break;
				}
				
				minimapButton->dungeonData = dungeonMap[i][j];
				minimapButton->dungeonData.pos.x = i;
				minimapButton->dungeonData.pos.y = j;
		
				int x = 0;
				int y = 0;
				if (dungeonMap[i][j].isRoom)
				{
					minimapButton->m_layer = LAYER::UIMinimapRoom;
					x = ((i) / 4) * 64 + ((i) / 4) * 3 * 24 + (i) % 4 * 24 - 2;
					y = ((j) / 4) * 64 + ((j) / 4) * 3 * 24 + (j) % 4 * 24 -4;
				}
				else {
					minimapButton->m_layer = LAYER::UIMinimapRoad;
					if (dungeonMap[i][j].isHorizontal)
					{
						x = ((i) / 4) * 64 + ((i) / 4) * 3 * 24 + (i) % 4 * 24 + 18;
						y = ((j) / 4) * 64 + ((j) / 4) * 3 * 24 + (j) % 4 * 24 - 2;
					}
					else {
						x = ((i) / 4) * 64 + ((i) / 4) * 3 * 24 + (i) % 4 * 24 - 2;
						y = ((j) / 4) * 64 + ((j) / 4) * 3 * 24 + (j) % 4 * 24 + 16;
					}
				}
				minimapButton->dungeonData.posFromCenter = Vector2(x,y);
				dungeonMap[i][j].posFromCenter = Vector2(x, y);
				minimapButton->m_transform->m_pos = minimapCenterPos + minimapButton->dungeonData.posFromCenter ;
				minimapButton->m_transform->m_pivot = Vector2(0.5, 0.5);
				minimapButton->isActive = false;
				minimapButton->SetMapSystem(this);
				dungeonMapCreate.push_back(minimapButton);
				MG_GMOBJ->RegisterObj("dungeonMapButton" + to_string(i), minimapButton);

				if (curPos == Vector2Int(i,j))
				{
					curPosPanel = new CMinimapButton();
					curPosPanel->Init();
					curPosPanel->AddSpriteRenderer(IMAGE::indicator);
					curPosPanel->dungeonData = dungeonMap[i][j];
					curPosPanel->dungeonData.posFromCenter = Vector2(x, y);
					curPosPanel->m_transform->m_pos = minimapButton->m_transform->m_pos;
					curPosPanel->m_transform->m_pivot = Vector2(0.5, 0.5);
					curPosPanel->m_layer = LAYER::UIMinimapTouch;
					//curPosPanel->UseFrontRender();
					MG_GMOBJ->RegisterObj("panel", curPosPanel);
				}
			}
		}
	}
}

void CMapSystem::DragMinimap(Vector2 deltaMove)
{
	for (size_t i = 0; i < dungeonMapCreate.size(); i++)
	{
		dungeonMapCreate[i]->m_transform->m_pos += Vector2(g_ptMouse) - deltaMove;
	}
	curPosPanel->m_transform->m_pos += Vector2(g_ptMouse) - deltaMove;
}



void CMapSystem::SetMinimapPos(Vector2 deltaMove)
{
	minimapCenterPos += deltaMove;
	for (size_t i = 0; i < dungeonMapCreate.size(); i++)
	{
		dungeonMapCreate[i]->m_transform->m_pos = minimapCenterPos + dungeonMapCreate[i]->dungeonData.posFromCenter;
	}

	curPosPanel->m_transform->m_pos = minimapCenterPos + curPosPanel->dungeonData.posFromCenter;
}

void CMapSystem::SetMinimapPosOrigin()
{
	SetMinimapPos(minimapCenterPos - minimapOriginPos);
	//minimapCenterPos = minimapOriginPos;
	minimapOriginPos = minimapCenterPos;
}



void CMapSystem::UseClickToMoveCurPoint(DungeonData _dungeonData)
{
	if (curPosPanel->dungeonData.isRoom && _dungeonData.isRoom && canMoveAnotherRoom)
	{
		Vector2Int index = _dungeonData.pos - curPos;
		
		if ((index.x == 4 | index.y == 4) || (index.x == -4 | index.y == -4))
		{
			bool ableToGo = false;
			if (index.x == 4 && 
				dungeonMap[curPos.x + 1][curPos.y].dungeonMapState != DUNGEONMAPSTATE::NONE)
			{
				ableToGo = true;
			}
			else if (index.y == 4 &&
				dungeonMap[curPos.x][curPos.y + 1].dungeonMapState != DUNGEONMAPSTATE::NONE)
			{
				ableToGo = true;
			}
			else if(index.x == -4 &&
				dungeonMap[curPos.x - 1][curPos.y].dungeonMapState != DUNGEONMAPSTATE::NONE) 
			{
				ableToGo = true;
			}
			else if (index.y == -4 &&
				dungeonMap[curPos.x][curPos.y - 1].dungeonMapState != DUNGEONMAPSTATE::NONE) 
			{
				ableToGo = true;
			}

			if (ableToGo)
			{
				if (index.x == 4)
				{
					curPos.x++;
					curDir = Vector2Int(1, 0);
					minimapCenterPos.x -= moveDistance;
				}
				else if (index.y == 4) {
					curPos.y++;
					curDir = Vector2Int(0, 1);
					minimapCenterPos.y -= moveDistance;
				}
				else if (index.x == -4) {
					curPos.x--;
					curDir = Vector2Int(-1, 0);
					minimapCenterPos.x += moveDistance;
				}
				else if (index.y == -4) {
					curPos.y--;
					curDir = Vector2Int(0, -1);
					minimapCenterPos.y += moveDistance;
				}
				curPosPanel->dungeonData = dungeonMap[curPos.x][curPos.y];
				SetMinimapPosOrigin();
				dungeonScene->ActivateRoad();
			}
		}
	}
}

void CMapSystem::MoveCurPoint(Vector2Int dir)
{
	Vector2Int nextRoom = dir + curPos;
	float roomDistance = 0;
	if (!(!dungeonMap[curPos.x][curPos.y].isRoom & !dungeonMap[nextRoom.x ][nextRoom.y].isRoom))
	{
		roomDistance = 10;
	}

	if (dir.x > 0)
	{
		curPos.x++;
		minimapCenterPos.x -= moveDistance + roomDistance;
	}
	else if (dir.y > 0) {
		curPos.y++;
		minimapCenterPos.y -= moveDistance + roomDistance;
	}
	else if (dir.x < 0) {
		curPos.x--;
		minimapCenterPos.x += moveDistance + roomDistance;
	}
	else if (dir.y < 0) {
		curPos.y--;
		minimapCenterPos.y += moveDistance + roomDistance;
	}
	curPosPanel->dungeonData = dungeonMap[curPos.x][curPos.y];
	SetMinimapPosOrigin();
}

DungeonData CMapSystem::GetCurDungeonData(int i)
{

	return dungeonMap[curPos.x + curDir.x * i][curPos.y + curDir.y * i];
}

DungeonData CMapSystem::GetCurDungeonData()
{
	return dungeonMap[curPos.x][curPos.y];
}

void CMapSystem::SetIsPassed()
{
	dungeonMap[curPos.x][curPos.y].isPassed = true;
}

void CMapSystem::SetIsOpened()
{
	dungeonMap[curPos.x][curPos.y].isOpenedTreasure = true;
}

void CMapSystem::SetIsPassed(int i)
{
	dungeonMap[curPos.x + curDir.x * i][curPos.y + curDir.y * i].isPassed = true;
}

void CMapSystem::UseKeyBoardToMoveCurPoint()
{
	MoveCurPoint(curDir);
}

void CMapSystem::UseKeyBoardToReverseMoveCurPoint()
{
	MoveCurPoint( curDir * -1);
}

