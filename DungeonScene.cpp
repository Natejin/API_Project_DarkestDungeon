#include "framework.h"
#include "DungeonScene.h"
#include "CHero.h"
#include "CBG_Road.h"
#include "CBG_Room.h"
#include "CParty.h"
#include "CButton.h"

DungeonScene::DungeonScene()
{
	curPos = Vector2Int(0, 0);
	roadCount = 3;
	remainRoom = 2;
	m_buttonTest = 0;
	isDoorClick = false;

	m_party = nullptr;
	m_roomBG = nullptr;
	m_roadBG = nullptr;

	showMap = true;
}
DungeonScene::~DungeonScene() {}

void print_num()
{
    std::cout << 3 << '\n';
}

HRESULT DungeonScene::Init()
{
	SetUIIMG();

	m_dungeonState = DUNGEONSTATE::ROAD;
	dungeonMode = DUNGEONMODE::WALK;
	CreateDungeon();
	CreateRoom();
	CreateRoad();
	CreateParty();
	CreateDoor();
	m_roadBG->isActive = true;

	CButton* m_testButton1 = new CButton();
	m_testButton1->m_transform->m_pos = Vector2(300, 300);
	m_testButton1->SetButtonSize(300, 100);
	m_testButton1->m_image = MG_IMAGE->findImage("scouting");
	m_testButton1->SetTriggerWhenClick(this, &DungeonScene::TestButton);
	MG_GMOBJ->RegisterObj("TestUiButton1", m_testButton1);

	return S_OK;
}

HRESULT DungeonScene::Init(bool managerInit)
{
	return S_OK;
}

void DungeonScene::Release()
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

void DungeonScene::Update()
{
	if (dungeonMode == DUNGEONMODE::WALK)
	{
		m_party->FormationMove();
		m_party->getStress_movement();
		m_party->decreaseBright_movement();
		CheckDoor();
		setRoadNum();
		TorchLightBarDecrease();

	}

	else if (dungeonMode == DUNGEONMODE::BATTLE)
	{

	}

	else 
	{
	
	}
}

void DungeonScene::Render(HDC _hdc)
{
	if (m_dungeonState == DUNGEONSTATE::ROOM)
	{

	}

	else if (m_dungeonState == DUNGEONSTATE::ROAD)
	{
		ShowDungeonInfo(_hdc);
		ShowMapOrInven(_hdc);

		Rectangle(_hdc, 600, 500, 700, 600);
	}

	else 
	{

	}
}


#pragma region InitDungeon
void DungeonScene::CreateDungeon()
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

void DungeonScene::CreateMapPart(int i, int j, int count, Vector2Int _lastDir)
{
	if (_lastDir != Vector2Int(0, 0))
	{
		if (remainRoom < 0) //������ �氳���� 0���ΰ��
		{
			return;
		}
		if (i < 0 || // x����� 0���� ����
			i > MAPSIZE || // x����� �ִ�ġ���� ŭ
			j < 0 || // y����� 0���� ����
			j > MAPSIZE || // y����� �ִ�ġ���� ŭ
			dungeonMap[i][j].dungeonMapState != DUNGEONMAPSTATE::NONE) // �ش���� ������
			return;
	}

#ifdef _DEBUG
	//system("CLS");
	//for (size_t m = 0; m < MAPSIZE; m++)
	//{
	//	for (size_t n = 0; n < MAPSIZE; n++)
	//	{
	//		_cprintf("%d ", (int)dungeonMap[m][n].dungeonMapState);
	//	}
	//	_cprintf("\n");
	//}

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

Vector2Int DungeonScene::GetDirFromInt(int dir) {
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

void DungeonScene::CreateParty()
{
	m_party = new CParty;
	m_party->Init(1,1,1);
	
	auto party = MG_GAME->GetHeroes();
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->m_transform->m_pos = Vector2(210 + 20 * i, 360);
	}
	m_party->SetParty(party);
	MG_GMOBJ->RegisterObj("Party", m_party);
	MG_CAMERA->SetTarget(m_party->GetHero(0));
}

void DungeonScene::CreateRoom()
{
	auto room = new CBG_Room();
	room->Init();
	room->isActive = false;
	MG_GMOBJ->RegisterObj("RoomBG", room);
	m_roomBG = room;
}

void DungeonScene::CreateDoor()
{
	door1.SetRect(145, 0, 365, WINSIZEY);
	door2.SetRect(WORLDSIZEX - 675, 0, WORLDSIZEX - 355, WINSIZEY);
}

void DungeonScene::CreateRoad()
{
	//�̺κ�
	auto road = new CBG_Road();
	road->Init();
	road->isActive = false;
	MG_GMOBJ->RegisterObj("RoadBG", road);
	m_roadBG = road;
}
#pragma endregion


#pragma region Road
void DungeonScene::setRoadNum()
{
	for (size_t i = 0; i < 6; i++)
	{
		if (i * 720 < m_party->GetHero(0)->m_transform->m_pos.x)
		{
			m_roadNum = i + 1;
		}
	}
}

void DungeonScene::setRoadKind()
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

void DungeonScene::setRoadObject()
{

}

void DungeonScene::setTorchUI()
{
	Image* Torch;
	Torch = MG_IMAGE->findImage("torchBackBar"); //decrese according to distance
	panel.push_back(Torch); //[6] torchBackBar
	Torch = MG_IMAGE->findImage("torchBackBar2");
	panel.push_back(Torch);
	Torch = MG_IMAGE->findImage("torchBackBar3");
	panel.push_back(Torch);
	Torch = MG_IMAGE->findImage("torchFrontBar");
	panel.push_back(Torch);

	CTransform ts;
	ts.m_pos = Vector2(524, 100);
	ts_panel.push_back(ts); //6
	ts.m_pos = Vector2(510, 100);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(988, 100);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(520, 19);
	ts_panel.push_back(ts);
}

void DungeonScene::TorchLightBarDecrease()
{
	panel[7]->setWidth(20);
	panel[8]->setWidth2(20);
	ts_panel[8].m_pos.x = 1400;

	panel[7]->setWidth(20 + (422 / 100) * (100 - m_party->getBrightness()) );
	panel[8]->setWidth2(20 + (422 / 100) * (100 - m_party->getBrightness()) );
	ts_panel[8].m_pos.x = 1400 -((422 / 100) * (100 - m_party->getBrightness()));
	
}

void DungeonScene::CheckDoor()
{
	if (true)
	{
		if (door1.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos) ||
			door2.CheckCollisionWithPoint(m_party->GetHero(0)->m_transform->m_pos))
		{
			isDoorClick = true;
			if (MG_INPUT->isOnceKeyDown(VK_UP))
			{
				isDoorClick = false;
				m_roadBG->isActive = false;
				m_roomBG->isActive = true;

			}
		}
		else
		{
			isDoorClick = false;
		}
	}
	
}
#pragma endregion


#pragma region DebugLog
void DungeonScene::ShowDungeonInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	sprintf_s(str, "<dungeonInfo>");
	TextOut(_hdc, 0, 80, str, strlen(str));

	sprintf_s(str, "roadNum : %d", m_roadNum);
	TextOut(_hdc, 0, 100, str, strlen(str));

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
		TextOut(_hdc, 0, 140, str, strlen(str));
	}
}
#pragma endregion


#pragma region UI
void DungeonScene::SetUIIMG()
{
	Image* panelImg;
	panelImg = MG_IMAGE->findImage("panel_bg2");
	panel.push_back(panelImg);
	panel.push_back(panelImg);
	panelImg = MG_IMAGE->findImage("banner");
	panel.push_back(panelImg);
	panelImg = MG_IMAGE->findImage("hero");
	panel.push_back(panelImg);
	panelImg = MG_IMAGE->findImage("inventory");
	panel.push_back(panelImg);
	panelImg = MG_IMAGE->findImage("map");
	panel.push_back(panelImg);


	CTransform ts;
	ts.m_pos = Vector2(0, 690);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(1580, 690);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(300, 690);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(330, 810);
	ts_panel.push_back(ts);
	ts.m_pos = Vector2(965, 690);
	ts_panel.push_back(ts);
	ts_panel.push_back(ts);

	setTorchUI();

	rc_inven.SetRect(1550, WINSIZEY - 236, 1600, WINSIZEY - 165);
	rc_map.SetRect(1550, WINSIZEY - 160, 1600, WINSIZEY - 95);
}

void DungeonScene::TestButton() 
{
	m_buttonTest++;
}

void DungeonScene::ShowMapOrInven(HDC _hdc)
{
	if (showMap == false)
	{
		for (int i = 0; i < panel.size(); i++)
		{
			panel[i]->renderUI(_hdc, &ts_panel[i]);
		}
	}
	else
	{
		for (int i = 0; i < panel.size(); i++)
		{
			panel[i]->renderUI(_hdc, &ts_panel[i]);
		}
		panel[4]->renderUI(_hdc, &ts_panel[4]);
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
#pragma endregion