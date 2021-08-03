#pragma once
#include "Scene.h"
//#define MAPX 100;
#define MAPSIZE 25

class DungeonScene : public Scene
{
public:

	struct DungeonData {
		DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
		bool dirMap[4] = { false };
		int posX = 0;
		int posY = 0;
	};

	
	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	DungeonData curDunheonMap;

	class CParty* m_party;

	Vector2Int curPos;
	int roadCount;
	int remainRoom;

	
	//Room
public:
	class CBackground* m_roomBG;



	//Road
public:
	class CBackground* m_roadBG;
	Rect door1;
	Rect door2;


	bool isDoorClick;
	int m_movedDistance;
	int m_roadNum;
	int imageCount;
	int torchLight;

	//앞으로 이동할때 최대 간격
	int m_WF_btwHeroes = 150;
	//뒤로 이동할때 최대 간격
	int m_WB_btwHeroes = 100;

	//배틀시스템
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;

public:
	DungeonScene();
	virtual~DungeonScene();

public:
	void CreateDungeon();
	void CreateMapPart(int i, int j, int count, Vector2Int lastDir);
	Vector2Int GetDirFromInt(int dir);

	void CreateParty();

	void CreateRoom();
	void CreateRoad();
	void CreateDoor();

public:
	//int getDistance()const { return m_movedDistance; } //이동거리
	//int getRoadCount()const { return m_roadNum; } //좌표인덱스
	//void setDistance(CHero* player);
	//void setRoadNum(CHero* player);


	//void setRoadKind();
	//void setRoadKind(int firstArea, int secondArea, int thirdArea);

	void FormationMove();
	void CheckDoor();


	void ShowDungeonInfo(HDC _hdc);
public:



	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};