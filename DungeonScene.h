#pragma once
#include "Scene.h"

class dungeonUI;
class CDungeonUI_HeroInfo;
class CInventorySystem;
class DungeonScene : public Scene
{
public:
	vector<IMAGE> roomRandom;
	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE m_dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	DungeonData curDunheonMap;

	class CParty* m_party;

	class TreasureEventPanel* treasurePanel;

//==================================
//Room
public:
	class CBG_Room* m_roomBG;
	//class CObjOnRoom* m_roomObj;

	class CObjOnRoad* m_roomObj;
	void SetRoomObject();

//==================================
//Road
public:
	class CBG_Road* m_roadBG;
	Rect door1;
	Rect door2;

	DUNGEONMAPSTATE m_kindOfRoad;
	bool isDoorClick;
	int m_movedDistance;
	int m_roadNum;
	int m_previousRoadMap;
	int imageCount;
	int torchLight;

	vector<class CObjOnRoad*> m_roadObjs;

	//앞으로 이동할때 최대 간격
	int m_WF_btwHeroes = 150;
	//뒤로 이동할때 최대 간격
	int m_WB_btwHeroes = 100;

	int getRoadCount()const { return m_roadNum; } //좌표인덱스
	void setRoadNum();

	void CheckDoor();
	void ShowDungeonInfo(HDC _hdc);
	void SetRoadObject(int i);

//==================================
//맵시스템
public:
	class CMapSystem* m_pMapSystem;

//==================================

//배틀시스템
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	//vector<class CEnemy*> enemyGroup;
	class CBattleSystem* m_pBattleSystem;

//==================================
//inventory SYstem
public:
	class CInventorySystem* m_pInvenSystem;
	class TreasureEventPanel* m_treasurePanel;
	bool isOpenedPanel;
//==================================
//UI
public:
	dungeonUI* m_dungeonUI;
	CDungeonUI_HeroInfo* m_dungeonUIinfo;
	
//==================================
public:
	DungeonScene();
	virtual ~DungeonScene();

	void CreateDungeonMap();

	void CreateParty();

	void CreateRoom();
	void CreateRoad();
	void CreateDoor();

	void CreateInvenSystem();
	void CreateBattleSystem();
	void CreateDungeonUI();

public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);

	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);


	//room and road changeScene
	void ActivateRoom();
	void ActivateRoad();

	void ActivateSound();
	void DeactivateSound();
};