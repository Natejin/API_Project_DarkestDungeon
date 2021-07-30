#pragma once
#include "Scene.h"
//#define MAPX 100;
#define MAPSIZE 10
class DungeonScene : public Scene
{
public:
	vector<class CPlayer*> playerGroup;
	DUNGEONSTATE dungeonState;

	DUNGEONMAPSTATE dungeonMap[MAPSIZE][MAPSIZE];
	Vector2Int curPos;
	int roadCount;
	int remainRoom;

	//��� �̵�
public:
	int torchLight;

	//��Ʋ�ý���
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;

public:
	DungeonScene();
	virtual~DungeonScene();

	void CreateDungeon();
	void CreateMapPart(int i, int j, int count, Vector2Int lastDir);

	Vector2Int GetNewDir();
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};