#include "framework.h"
#include "RoomScene.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CBackground.h"
#include "CParty.h"

RoomScene::RoomScene() {}
RoomScene::~RoomScene() {}

HRESULT RoomScene::Init()
{
	////이부분
	//CBackground* bg = new CBackground();
	//bg->Init();
	//bg->m_image = MG_IMAGE->findImage("bg");
	//MG_GMOBJ->RegisterObj("Background", bg);

	//Create_Player_Party();
	//Create_Enermy_Party();

	////초기 스피드값을 준다.
	////3 2 1 0
	////[0]:성기사, [1]: 노상강도 [2]: 역병의사 [3]: 성녀 
	//m_player->m_heroParty[0]->SPD = 3;
	//m_player->m_heroParty[1]->SPD = 4;
	//m_player->m_heroParty[2]->SPD = 5;
	//m_player->m_heroParty[3]->SPD = 6;
	//// 0 1 2  3
	//Enermy_arr[0]->SPD = 1;
	//Enermy_arr[1]->SPD = 2;
	//Enermy_arr[2]->SPD = 3;
	//Enermy_arr[3]->SPD = 4;

	return S_OK;
}

HRESULT RoomScene::Init(bool managerInit)
{
	return S_OK;
}

void RoomScene::Release()
{

}

void RoomScene::Update()
{	/*
	속도의 변경에서 턴마다 + 랜덤값이 추가되고
	그 턴이 종료 되면 다시 초기화를 시켜주어야한다. 아닌가..?
	숫자 이미지는 같은데 주사위적인 요소로 계속 더해주어도 되는건가?

	턴수가 정해진게 아닌데
	bool값으로 턴을 지정하면 for문을 몇번을 돌려야 하는거지 ->알수없음
	아니면 while문을 돌리는데 적이 전부 죽거나 영웅들이 전부 죽었을때라고 돌리면 애들의 hp도 넣어주고 공격도 넣어주어야 하는건가.

	*/

	//속도가 매 턴바뀌도록.
	////3 2 1 0 [0]:성기사, [1]: 노상강도 [2]: 역병의사 [3]: 성녀 
	//m_player->m_heroParty[0]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[1]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[2]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[3]->SPD + MG_RND->getInt(3);
	//// 0 1 2  3
	//Enermy_arr[0]->SPD + MG_RND->getInt(4);
	//Enermy_arr[1]->SPD + MG_RND->getInt(4);
	//Enermy_arr[2]->SPD + MG_RND->getInt(4);
	//Enermy_arr[3]->SPD + MG_RND->getInt(4);

	//속도가 전부 바뀐뒤에 
	//전투 시작하면 속도를 비교해서 재정렬 시킴.
	Battle();
	CheckButton(); //턴수가 올라가는지 확인용.
}

void RoomScene::Render(HDC _hdc)
{
	//RectangleMakeCenter(_hdc, 500, 500, 100, 100);

	char str[256];

	SetBkMode(_hdc, TRANSPARENT);

	SetTextColor(_hdc, RGB(0, 0, 255));
	sprintf_s(str, " Total_turn :%d", _Turn);
	TextOut(_hdc, WINSIZEX / 2, WINSIZEY / 2 - 200, str, strlen(str));

}

void RoomScene::Create_Player_Party()
{
	m_player = new CParty();
	for (size_t i = 0; i < 4; i++)
	{
		CHero* m_hero = new CHero();

		//m_hero->Init();
		m_hero->m_transform->m_pos = Vector2(WINSIZEX / 2 - i * 100, WINSIZEY / 2);

		MG_GMOBJ->RegisterObj("Player1", m_hero);
		MG_CAMERA->SetTarget(m_hero);
		//m_player->m_heroParty.push_back(m_hero);

	}
}

void RoomScene::Create_Enermy_Party()
{
	for (size_t i = 0; i < 4; i++)
	{
		CEnemy* enemy = new CEnemy();

		enemy->Init();
		enemy->m_transform->m_pos = Vector2(WINSIZEX / 2 + i * 100, WINSIZEY);
		MG_GMOBJ->RegisterObj("enemy1", enemy);

		Enermy_arr.push_back(enemy);
	}
}

void RoomScene::Compare_P_E_Speed_ReArray()
{	
	/*
	//int형이 아닌 class를 배열로 넣어서 만들어라.?
	현재 문제점-> 배열안에 넣었을때 int형 배열인 경우 객체를 정수형으로 인식을 하게 되고
	int형으로 인식을 한채로 재배열을 시키고 나면 값의 재정렬은 되지만 숫자만으로 재정렬이 되기때문에 이게 누구의 속도인지
	알수가 없게된다.
	그러므로 재배열을 했을때 이것이 누구의 속도인지 알게끔 코드를 다시 짜야함.
	*/
	//turn_number[8] = { 
	//	this->m_player->m_heroParty[0]->SPD,
	//	this->m_player->m_heroParty[1]->SPD,
	//	this->m_player->m_heroParty[2]->SPD,
	//	this->m_player->m_heroParty[3]->SPD,
	//	this->Enermy_arr[0]->SPD,
	//	this->Enermy_arr[1]->SPD,
	//	this->Enermy_arr[2]->SPD,
	//	this->Enermy_arr[3]->SPD };

	//this->m_player->m_heroParty[0]->SPD = m_player->m_heroParty[0]->SPD;
	//this->m_player->m_heroParty[1]->SPD = m_player->m_heroParty[1]->SPD;
	//this->m_player->m_heroParty[2]->SPD = m_player->m_heroParty[2]->SPD;
	//this->m_player->m_heroParty[3]->SPD = m_player->m_heroParty[3]->SPD;

	//this->Enermy_arr[0]->SPD = Enermy_arr[0]->SPD;
	//this->Enermy_arr[1]->SPD = Enermy_arr[1]->SPD;
	//this->Enermy_arr[2]->SPD = Enermy_arr[2]->SPD;
	//this->Enermy_arr[3]->SPD = Enermy_arr[3]->SPD;
	//속도에 따른 재정렬
	for (int i = 0; i < 8; i++) {
		int maxindex = i;
		int maxNum = turn_number[i];
		for (int j = i + 1; j < 8; j++) {
			if (maxNum < turn_number[j]) {
				maxindex = j;
				maxNum = turn_number[j];
			}
		}
		int temp = turn_number[i];
		turn_number[i] = turn_number[maxindex];
		turn_number[maxindex] = temp;
	}

}

void RoomScene::Battle()
{
	Battle_Start();
	Battle_Finish();
}

void RoomScene::Battle_Start()
{
	Compare_P_E_Speed_ReArray(); //속도 재배열.
}

void RoomScene::Battle_Finish()
{

}

void RoomScene::CheckButton()
{
	if (MG_INPUT->isOnceKeyDown(VK_SPACE))
	{
		_Turn += 1;
	}
}