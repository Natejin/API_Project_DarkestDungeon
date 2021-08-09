
#include "framework.h"
#include "DungeonScene2.h"
#include "CHero.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CParty.h"
#include "CButton.h"
#include "CRoadObject.h"
#include "CBattleSystem.h"

DungeonScene2::DungeonScene2()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 2;
	m_buttonTest = 0;
	isDoorClick = false;

	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;
	m_roadObj = nullptr;
	m_pBattleSystem = nullptr;
	showMap = true;
}
DungeonScene2::~DungeonScene2() {}



HRESULT DungeonScene2::Init()
{
	SetUIIMG();
	CreateBattleSystem();

	roomRandom.push_back(IMAGE::Ruins_room1);
	roomRandom.push_back(IMAGE::Ruins_room2);
	roomRandom.push_back(IMAGE::Ruins_room3);
	roomRandom.push_back(IMAGE::Ruins_room4);
	roomRandom.push_back(IMAGE::Ruins_room5);
	roomRandom.push_back(IMAGE::Ruins_room6);
	roomRandom.push_back(IMAGE::Ruins_room7);
	roomRandom.push_back(IMAGE::Ruins_room8);
	roomRandom.push_back(IMAGE::Ruins_room9);
	
	m_dungeonState = DUNGEONSTATE::ROAD;
	dungeonMode = DUNGEONMODE::WALK;
	CreateDungeon();
	CreateRoom();
	CreateRoad();
	CreateParty();
	CreateDoor();

	ActivateRoad();
	MG_CAMERA->SetTarget(m_party->GetHero(0));
	

	//CButton* m_testButton1 = new CButton();
	//m_testButton1->m_transform->m_pos = Vector2(300, 300);
	//m_testButton1->SetButtonSize(300, 100);
	//m_testButton1->m_image = MG_IMAGE->findImage("scouting");
	//m_testButton1->SetTriggerWhenClick(this, &DungeonScene2::TestButton);
	//MG_GMOBJ->RegisterObj("TestUiButton1", m_testButton1);

	return S_OK;
}

HRESULT DungeonScene2::Init(bool managerInit)
{
	return S_OK;
}

void DungeonScene2::Release()
{
	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;

	for (size_t i = 0; i < enemyGroup.size(); i++)
	{
		enemyGroup[i] = nullptr;
	}
	enemyGroup.clear();
}

void DungeonScene2::Update()
{
	if (dungeonMode == DUNGEONMODE::WALK)
	{
		m_party->FormationMove();
		m_party->getStress_movement();
		m_party->decreaseBright_movement();

		CheckDoor();
		setRoadNum();
		TorchLightBarDecrease();
		SetSceneSize();
	}

	else if (dungeonMode == DUNGEONMODE::BATTLE)
	{

	}

	else
	{

	}
}

void DungeonScene2::Render(HDC _hdc)
{
	ShowMapOrInven(_hdc);
	if (m_dungeonState == DUNGEONSTATE::ROOM)
	{

	}

	else if (m_dungeonState == DUNGEONSTATE::ROAD)
	{
		ShowDungeonInfo(_hdc);
	

		//m_roadObj->Render(_hdc);
	}

	else
	{

	}
}

void DungeonScene2::ActivateRoom()
{
	m_roadBG->isActive = false;
	m_roomBG->isActive = true;
	m_dungeonState = DUNGEONSTATE::ROOM;
	MG_CAMERA->SetWorldSize(Vector2(WINSIZEX, WINSIZEY));

	dungeonMode = DUNGEONMODE::BATTLE; //TODO 나중에는 방에 들어갈때 상태체크에서 몬스터일경우 변경
	m_pBattleSystem->BattleSystemInitiate();

}

void DungeonScene2::ActivateRoad()
{
	m_roomBG->isActive = false;
	 m_roadBG->isActive = true;
	 m_dungeonState = DUNGEONSTATE::ROAD;
	MG_CAMERA->SetWorldSize(Vector2(WORLDSIZEX, WORLDSIZEY));
}


#pragma region InitDungeon
void DungeonScene2::CreateDungeon()
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

	CreateMapPart(curPos.x, curPos.y, 0, Vector2Int(0, 0));
	curDunheonMap = dungeonMap[curPos.x][curPos.y];
}

void DungeonScene2::CreateMapPart(int i, int j, int count, Vector2Int _lastDir)
{
	if (_lastDir != Vector2Int(0, 0))
	{
		if (remainRoom < 1)
		{
			return;
		}
		if (i < 0 ||
			i > MAPSIZE ||
			j < 0 ||
			j > MAPSIZE ||
			dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE)
			return;
	}

#ifdef _DEBUG
	system("CLS");
	for (size_t m = 0; m < MAPSIZE; m++)
	{
		for (size_t n = 0; n < MAPSIZE; n++)
		{
			_cprintf("%d ", (int)dungeonMap[m][n].dungeonMapState);
		}
		_cprintf("\n");
	}

#endif // _DEBUG

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
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(-1, 0);
			dungeonMap[i][j].dirMap[(int)DIR::Left] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}
		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, 1);
			dungeonMap[i][j].dirMap[(int)DIR::Down] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
		}

		if (!(bool)MG_RND->getInt(2)) {
			noneDir = false;
			lastDir = Vector2Int(0, -1);
			dungeonMap[i][j].dirMap[(int)DIR::Up] = true;
			CreateMapPart(i + lastDir.x, j + lastDir.y, 3, lastDir);
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
					CreateMapPart(i + newDic.x, j + newDic.y, 3, newDic);
					return;
				}
			}
		}
	}
}

Vector2Int DungeonScene2::GetDirFromInt(int dir) {
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

void DungeonScene2::CreateParty()
{
	m_party = new CParty;
	m_party->Init(1, 1, 1);

	auto party = MG_GAME->GetHeroes();
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(210 + 20 * i, 520);
	}
	m_party->SetParty(party);
	MG_GMOBJ->RegisterObj("Party", m_party);

}

void DungeonScene2::CreateRoom()
{
	auto room = new CBG_Room();
	room->Init();
	room->isActive = false;
	MG_GMOBJ->RegisterObj("RoomBG", room);
	m_roomBG = room;
}

void DungeonScene2::CreateDoor()
{
	door1.SetRect(145, 0, 365, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 675, 0, WORLDSIZEX - 355, WINSIZEY);
}

void DungeonScene2::CreateBattleSystem()
{
	m_pBattleSystem = new CBattleSystem();
	m_pBattleSystem->isActive = false;
	MG_GMOBJ->RegisterObj("battleSystem", m_pBattleSystem);
}

void DungeonScene2::CreateRoad()
{
	//�̺κ�
	auto road = new CBG_Road();
	road->Init();
	road->isActive = false;
	MG_GMOBJ->RegisterObj("RoadBG", road);
	m_roadBG = road;

	auto roadOBJ = new CRoadObject();
	roadOBJ->Init();
	roadOBJ->isActive = false;
	MG_GMOBJ->RegisterObj("RoadOBJ", roadOBJ);
	m_roadObj = roadOBJ;
}
#pragma endregion


#pragma region Road
void DungeonScene2::setRoadNum()
{
	for (size_t i = 0; i < 6; i++)
	{
		if (i * 720 < m_party->GetHero(0)->m_transform->m_pos.x)
		{
			m_roadNum = i + 1;
		}
	}
}

void DungeonScene2::setRoadKind()
{
	//switch (curDunheonMap.dungeonMapState)
	//{
	//case DUNGEONMAPSTATE::Road_Empty:
	//	break;

	//case DUNGEONMAPSTATE::Road_Enemy:
	//	break;

	//case DUNGEONMAPSTATE::Road_Trap:
	//	break;

	//case DUNGEONMAPSTATE::Road_Trasure:
	//	
	// break;
	//}
}

void DungeonScene2::setRoadObject()
{
	//call the CRoadObj memberfunction
}

void DungeonScene2::setTorchUI()
{
	ImageData UIimg;

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar");
	UIimg.m_trans.m_pos = Vector2(524, 100); //decrese according to distance
	vUI.push_back(UIimg); //[6] torchBackBar

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar2");
	UIimg.m_trans.m_pos = Vector2(510, 100);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar3");
	UIimg.m_trans.m_pos = Vector2(988, 100);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("torchFrontBar");
	UIimg.m_trans.m_pos = Vector2(520, 19);
	vUI.push_back(UIimg);
}

void DungeonScene2::TorchLightBarDecrease()
{
	vUI[7].m_img->setWidth(20);
	vUI[8].m_img->setWidth2(20);
	vUI[8].m_trans.m_pos.x = 1400;

	vUI[7].m_img->setWidth(20 + (422 / 100) * (100 - m_party->getBrightness()));
	vUI[8].m_img->setWidth2(20 + (422 / 100) * (100 - m_party->getBrightness()));
	vUI[8].m_trans.m_pos.x = 1400 - ((422 / 100) * (100 - m_party->getBrightness()));

}



void DungeonScene2::CheckDoor()
{
	if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos) ||
		door2.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos))
	{
		isDoorClick = true;
		if (MG_INPUT->isOnceKeyDown(VK_UP))
		{
			isDoorClick = false;
			ActivateRoom();

		}
	}
	else
	{
		isDoorClick = false;
	}
}
#pragma endregion


#pragma region DebugLog
void DungeonScene2::ShowDungeonInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	sprintf_s(str, "<dungeonInfo>");
	TextOut(_hdc, 0, 80, str, strlen(str));

	sprintf_s(str, "roadNum : %d", m_roadNum);
	TextOut(_hdc, 0, 100, str, strlen(str));

	//sprintf_s(str, "sceneSize : %d", m_sceneSize);
	//TextOut(_hdc, 0, 140, str, strlen(str));

	sprintf_s(str, "nowScene : %d", (int)m_dungeonState);
	TextOut(_hdc, 0, 140, str, strlen(str));

	sprintf_s(str, "ButtonTest1 : %d", m_buttonTest);
	TextOut(_hdc, 0, 180, str, strlen(str));

	switch (curDunheonMap.dungeonMapState)
	{
	case DUNGEONMAPSTATE::Road_Empty:
		sprintf_s(str, "roadState : empty");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	case DUNGEONMAPSTATE::Road_Enemy:
		sprintf_s(str, "roadState : enemy");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	case DUNGEONMAPSTATE::Road_Trasure:
		sprintf_s(str, "roadState : treasure");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	default:
		sprintf_s(str, "roadState : door");
		TextOut(_hdc, 0, 120, str, strlen(str));
		break;
	}

	if (isDoorClick)
	{
		sprintf_s(str, "near Door");
		TextOut(_hdc, 0, 160, str, strlen(str));
	}
}
#pragma endregion


#pragma region UI
void DungeonScene2::SetUIIMG()
{
	ImageData UIimg;

	UIimg.m_img = MG_IMAGE->findImage("panel_bg2");
	UIimg.m_trans.m_pos = Vector2(0, 700);
	vUI.push_back(UIimg);

	UIimg.m_trans.m_pos = Vector2(1580, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("banner");
	UIimg.m_trans.m_pos = Vector2(300, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("hero");
	UIimg.m_trans.m_pos = Vector2(330, 820);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("inventory");
	UIimg.m_trans.m_pos = Vector2(965, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("map");
	UIimg.m_trans.m_pos = Vector2(965, 700);
	vUI.push_back(UIimg);

	setTorchUI();

	rc_inven.SetRect(1550, 1080 - 236, 1600, 1080 - 165);
	rc_map.SetRect(1550, 1080 - 160, 1600, 1080 - 95);
}

void DungeonScene2::TestButton()
{
	m_buttonTest++;
}

void DungeonScene2::ShowMapOrInven(HDC _hdc)
{
	if (showMap == false)
	{
		for (int i = 0; i < vUI.size(); i++)
		{
			vUI[i].m_img->renderUI(_hdc, &vUI[i].m_trans);
		}
	}
	else
	{
		for (int i = 0; i < vUI.size(); i++)
		{
			vUI[i].m_img->renderUI(_hdc, &vUI[i].m_trans);
		}
		vUI[4].m_img->renderUI(_hdc, &vUI[4].m_trans);
	}

	if (rc_inven.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			showMap = false;
		}
	}
	if (rc_map.CheckCollisionWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			showMap = true;
		}
	}
}

void DungeonScene2::SetSceneSize()
{
	m_sceneSize = m_roadBG->getSceneSize();
}

#pragma endregion