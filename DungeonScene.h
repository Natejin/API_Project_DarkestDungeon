#pragma once
#include "Scene.h"

class DungeonScene : public Scene
{
public:
	vector<class CPlayer*> playerGroup;
	DUNGEONSTATE dungeonState;

	
	DUNGEONMAPSTATE dungeonMap[100][100];

	Vector2Int curPos;

	//통로 이동
public:
	int torchLight;

	//배틀시스템
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;


public:
	DungeonScene();
	virtual~DungeonScene();

	void CreateDungeon();


	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};