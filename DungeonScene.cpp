#include "framework.h"
#include "DungeonScene.h"

DungeonScene::DungeonScene()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
}

DungeonScene::~DungeonScene()
{
}

void DungeonScene::CreateDungeon()
{
	//맵을 생성
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			dungeonMap[i][j] = DUNGEONMAPSTATE::NONE;
		}
	}

	//현재위치(시작위치)를 맵의 중앙에 위치
	curPos = Vector2Int(MAPSIZE / 2, MAPSIZE / 2);
	dungeonMap[curPos.x][curPos.y] = DUNGEONMAPSTATE::Room_Empty;
	Vector2Int dir = GetNewDir();
	CreateMapPart(curPos.x + dir.x, curPos.y + dir.y, 3, dir);
}

void DungeonScene::CreateMapPart(int i, int j, int count, Vector2Int lastDir)
{
#ifdef _DEBUG
	system("CLS");
	for (size_t m = 0; m < MAPSIZE; m++)
	{
		for (size_t n = 0; n < MAPSIZE; n++)
		{
			_cprintf("%d ", (int)dungeonMap[m][n]);
		}
		_cprintf("\n");
	}
#endif // _DEBUG
	if (remainRoom < 0 || //생성할 방개수가 0개인경우
		i < 0 || // x축방이 0보다 작음
		i > MAPSIZE || // x축방이 최대치보다 큼
		j < 0 || // y축방이 0보다 작음
		j > MAPSIZE || // y축방이 최대치보다 큼
		dungeonMap[i][j] != DUNGEONMAPSTATE::NONE) // 해당방이 존재함
		return;



	if (count > 0)
	{
		count--;
		if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Road_Enemy;
		}
		else if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Road_Trasure;
		}

		else if (!(bool)MG_RND->getInt(10)) {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Road_Trap;
		}
		else {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Road_Empty;
		}
		CreateMapPart(i + lastDir.x, j + +lastDir.y, count, lastDir);
	}
	//방일때
	else {
		if (!(bool)MG_RND->getInt(4)) {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Room_Enemy;
		}
		else if (!(bool)MG_RND->getInt(4)) {
			dungeonMap[i][j] = DUNGEONMAPSTATE::Room_Trasure;
		}

		else{
			dungeonMap[i][j] = DUNGEONMAPSTATE::Room_Empty;
		}
		remainRoom--;

		
		lastDir = GetNewDir();
		CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
	}
}

Vector2Int DungeonScene::GetNewDir()
{
	Vector2Int temp;
	if (!(bool)MG_RND->getInt(4)) {
		temp = Vector2Int(1, 0);
	}
	else if (!(bool)MG_RND->getInt(4)) {
		temp = Vector2Int(0, 1);
	}
	else if (!(bool)MG_RND->getInt(4)) {
		temp = Vector2Int(-1, 0);
	}
	else {
		temp = Vector2Int(0, -1);
	}
	return temp;
}



HRESULT DungeonScene::Init()
{
	dungeonState = DUNGEONSTATE::ROOM;
	CreateDungeon();
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
}

void DungeonScene::Render(HDC _hdc)
{
}
