#pragma once
#include "Scene.h"

class dungeonUI;
class dungeonUI_HeroInfo;
class CInventorySystem;
class DungeonScene : public Scene
{
public:
	vector<IMAGE> roomRandom;
	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];
	DungeonData curDunheonMap;

	class CParty* m_party;



//==================================
//Room
public:
	class CBG_Room* m_roomBG;


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
	int imageCount;
	int torchLight;

	class CRoadObject* m_roadObj;

	//������ �̵��Ҷ� �ִ� ����
	int m_WF_btwHeroes = 150;
	//�ڷ� �̵��Ҷ� �ִ� ����
	int m_WB_btwHeroes = 100;

	int getRoadCount()const { return m_roadNum; } //��ǥ�ε���
	void setRoadNum();
	void setRoadKind();

	void CheckDoor();
	void ShowDungeonInfo(HDC _hdc);

//==================================
//�ʽý���
public:
	class CMapSystem* m_pMapSystem;

//==================================

//��Ʋ�ý���
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;
	class CBattleSystem* m_pBattleSystem;

//==================================
//UI
public:
	dungeonUI* m_dungeonUI;
	dungeonUI_HeroInfo* m_dungeonUIinfo;

//==================================
public:
	DungeonScene();
	virtual~DungeonScene();

public:
	void CreateDungeonMap();

	void CreateParty();

	void CreateRoom();
	void CreateRoad();
	void CreateDoor();

	void CreateBattleSystem();

public:
	virtual HRESULT Init();
	void CreateDungeonUI();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

	void ActivateRoom();
	void ActivateRoad();
};