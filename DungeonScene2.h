

#pragma once
#include "Scene.h"
//#define MAPX 100;


class DungeonScene2 : public Scene
{
	vector<IMAGE> roomRandom;
	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	DungeonData curDunheonMap;

public:






	class CParty* m_party;

	Vector2Int curPos;
	int roadCount;
	int remainRoom;

	//==================================
	//Room
public:
	class CBackground* m_roomBG;


	//==================================
	//Road
public:
	class CBackground* m_roadBG;
	Rect door1;
	Rect door2;

	DUNGEONMAPSTATE m_kindOfRoad;
	bool isDoorClick;
	int m_movedDistance;
	int m_roadNum;
	int imageCount;
	int torchLight;

	class CRoadObject* m_roadObj;

	//앞으로 이동할때 최대 간격
	int m_WF_btwHeroes = 150;
	//뒤로 이동할때 최대 간격
	int m_WB_btwHeroes = 100;

	int getRoadCount()const { return m_roadNum; } //좌표인덱스
	void setRoadNum();
	void setRoadKind();
	void setRoadObject();

	void setTorchUI();
	void TorchLightBarDecrease();

	void CheckDoor();
	void ShowDungeonInfo(HDC _hdc);

	//==================================
	//배틀시스템
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;
	class CBattleSystem* m_pBattleSystem;

	//==================================
	//UI
public:
	vector<ImageData> vUI;
	Rect rc_map;
	Rect rc_inven;
	bool showMap;
	int m_sceneSize;

	void SetUIIMG();
	void ShowMapOrInven(HDC _hdc);
	void SetSceneSize();

	void TestButton();
	int m_buttonTest;

	//==================================
public:
	DungeonScene2();
	virtual~DungeonScene2();

public:
	void CreateDungeon();
	void CreateMapPart(int i, int j, int count, Vector2Int lastDir);
	Vector2Int GetDirFromInt(int dir);

	void CreateParty();

	void CreateRoom();
	void CreateRoad();
	void CreateDoor();

	void CreateBattleSystem();

public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

	void DungeonScene2::bindFunction(function<void()>& dest)
	{
		dest = bind(&DungeonScene2::TestButton, this);
	}

	void ActivateRoom();
	void ActivateRoad();
};