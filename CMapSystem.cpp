#include "framework.h"
#include "CMapSystem.h"

CMapSystem::CMapSystem()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 2;
	m_layer = LAYER::UI;
}

CMapSystem::~CMapSystem()
{

}

HRESULT CMapSystem::Init()
{
	CreateDungeon();
	return S_OK;
}

void CMapSystem::Update(float deltaTime, float worldTime)
{
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

	CreateMapPart(curPos.x, curPos.y, 0, Vector2Int(0, 0));
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
	dungeonMap[i][j].pos = Vector2Int(i, j);
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
		dungeonMap[i][j].isRoom = true;
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

void CMapSystem::SetMapWitchCreated()
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{


			if (dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE)
			{
			
				switch (dungeonMap[i][j].dungeonMapState)
				{
				case DUNGEONMAPSTATE::Road_Empty:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::hall_clear);
					break;
				case DUNGEONMAPSTATE::Road_Enemy:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::marker_battle);
					break;
				case DUNGEONMAPSTATE::Road_Trasure:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::marker_curio);
					break;
				case DUNGEONMAPSTATE::Road_Trap:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::marker_trap);
					break;
				case DUNGEONMAPSTATE::Room_Empty:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::room_empty);
					break;
				case DUNGEONMAPSTATE::Room_Enemy:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::room_battle);
					break;
				case DUNGEONMAPSTATE::Room_Trasure:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::room_curio);
					break;
				case DUNGEONMAPSTATE::Room_Boss:
					dungeonMap[i][j].m_imageData.m_img = MG_IMAGE->findImage(IMAGE::room_boss);
					break;
				default:
					break;
				}
				dungeonMapCreate.push_back(dungeonMap[i][j]);
			}
		}
	}
}
