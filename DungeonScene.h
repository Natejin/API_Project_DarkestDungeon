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

	bool isDoorClick;
	int m_movedDistance;
	int m_roadNum;
	int imageCount;
	int torchLight;

	//������ �̵��Ҷ� �ִ� ����
	int m_WF_btwHeroes = 150;
	//�ڷ� �̵��Ҷ� �ִ� ����
	int m_WB_btwHeroes = 100;

	//int getDistance()const { return m_movedDistance; } //�̵��Ÿ�
	//int getRoadCount()const { return m_roadNum; } //��ǥ�ε���
	//void setDistance(CHero* player);
	//void setRoadNum(CHero* player);

	//void setRoadKind();
	//void setRoadKind(int firstArea, int secondArea, int thirdArea);

	void FormationMove();
	void CheckDoor();

	void ShowDungeonInfo(HDC _hdc);

//==================================
//��Ʋ�ý���
public:
	int curBattleTurnCount;
	BATTLETURN curBattleTurn;
	vector<class CEnemy*> enemyGroup;


	//UI
public:
	void TestButton();
	void TestButton1();
	//class CButton* m_testButton;
	int m_buttonTest;
	int m_buttonTest1;
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
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);




	void DungeonScene::bindFunction(function<void()>& dest)
	{
		dest = bind(&DungeonScene::TestButton, this);
	}
};