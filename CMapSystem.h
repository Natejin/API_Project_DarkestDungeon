#pragma once
#include "GameObject.h"

class Image;
class CMapSystem : public GameObject
{
public:
	//DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	//DungeonData curDunheonMap;


	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	DungeonData curDungeonMap;

	vector< DungeonData> dungeonMapCreate;

	Vector2Int curPos;
	int roadCount;
	int remainRoom;

	CMapSystem();
	~CMapSystem();
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	void CreateDungeon();
	void CreateMapPart(int i, int j, int count, Vector2Int lastDir);
	Vector2Int GetDirFromInt(int dir);

	void SetMapWitchCreated();
};

