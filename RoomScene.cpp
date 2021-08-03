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
	////�̺κ�
	//CBackground* bg = new CBackground();
	//bg->Init();
	//bg->m_image = MG_IMAGE->findImage("bg");
	//MG_GMOBJ->RegisterObj("Background", bg);

	//Create_Player_Party();
	//Create_Enermy_Party();

	////�ʱ� ���ǵ尪�� �ش�.
	////3 2 1 0
	////[0]:�����, [1]: ��󰭵� [2]: �����ǻ� [3]: ���� 
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
	�ӵ��� ���濡�� �ϸ��� + �������� �߰��ǰ�
	�� ���� ���� �Ǹ� �ٽ� �ʱ�ȭ�� �����־���Ѵ�. �ƴѰ�..?
	���� �̹����� ������ �ֻ������� ��ҷ� ��� �����־ �Ǵ°ǰ�?

	�ϼ��� �������� �ƴѵ�
	bool������ ���� �����ϸ� for���� ����� ������ �ϴ°��� ->�˼�����
	�ƴϸ� while���� �����µ� ���� ���� �װų� �������� ���� �׾�������� ������ �ֵ��� hp�� �־��ְ� ���ݵ� �־��־�� �ϴ°ǰ�.

	*/

	//�ӵ��� �� �Ϲٲ��.
	////3 2 1 0 [0]:�����, [1]: ��󰭵� [2]: �����ǻ� [3]: ���� 
	//m_player->m_heroParty[0]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[1]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[2]->SPD + MG_RND->getInt(3);
	//m_player->m_heroParty[3]->SPD + MG_RND->getInt(3);
	//// 0 1 2  3
	//Enermy_arr[0]->SPD + MG_RND->getInt(4);
	//Enermy_arr[1]->SPD + MG_RND->getInt(4);
	//Enermy_arr[2]->SPD + MG_RND->getInt(4);
	//Enermy_arr[3]->SPD + MG_RND->getInt(4);

	//�ӵ��� ���� �ٲ�ڿ� 
	//���� �����ϸ� �ӵ��� ���ؼ� ������ ��Ŵ.
	Battle();
	CheckButton(); //�ϼ��� �ö󰡴��� Ȯ�ο�.
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
	//int���� �ƴ� class�� �迭�� �־ ������.?
	���� ������-> �迭�ȿ� �־����� int�� �迭�� ��� ��ü�� ���������� �ν��� �ϰ� �ǰ�
	int������ �ν��� ��ä�� ��迭�� ��Ű�� ���� ���� �������� ������ ���ڸ����� �������� �Ǳ⶧���� �̰� ������ �ӵ�����
	�˼��� ���Եȴ�.
	�׷��Ƿ� ��迭�� ������ �̰��� ������ �ӵ����� �˰Բ� �ڵ带 �ٽ� ¥����.
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
	//�ӵ��� ���� ������
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
	Compare_P_E_Speed_ReArray(); //�ӵ� ��迭.
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