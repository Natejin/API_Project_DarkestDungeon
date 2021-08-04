#include "framework.h"
#include "CBattleSystem.h"
#include "DungeonScene.h"
#include "CParty.h"
#include "CHero.h"
#include "CEnemy.h"

void CBattleSystem::BattleSystemInitiate()
{
	CreateHeroesParty();
	CreateEnemyParty();
	Compare_P_E_Speed_ReArray();
}
//enemy->m_transform->m_pos = Vector2(WINSIZEX / 2 + i * 100, WINSIZEY);
void CBattleSystem::CreateEnemyParty()
{
	int random = MG_RND->getInt(2) + 2;
	for (size_t i = 0; i < random; i++)
	{
		CEnemy* enemy = new CEnemy();
		enemy->Init(); //TODO 추후 적 세팅 변경하기

		MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
		enemyParty.push_back(enemy);
		enemyParty[i]->SetPosition(i);
		enemyParty[i]->SetPartyIndex(i);
	}
}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = scene->m_party->GetPartySize();

	for (int i = 0; i < playerPartySize; i++)
	{
		heroParty.push_back(scene->m_party->GetHero(i));
		heroParty[i]->SetPosition(i);
		heroParty[i]->SetPartyIndex(i);
	}
}

void CBattleSystem::Compare_P_E_Speed_ReArray()
{	
	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < heroParty.size(); i++)
	{
		speedVec.push_back(make_pair(heroParty[i]->GetSpeed() + MG_RND->getInt(randomDice6), heroParty[i]));
	}

	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < enemyParty.size(); i++)
	{
		speedVec.push_back(make_pair(enemyParty[i]->GetSpeed() + MG_RND->getInt(randomDice6), enemyParty[i]));
	}

	//알고리즘을 이용한 정렬
	sort(speedVec.begin(), speedVec.end());



	//int turn_number[8] = { this->m_player->Hero_array[0]->SPD,this->m_player->Hero_array[1]->SPD,this->m_player->Hero_array[2]->SPD,this->m_player->Hero_array[3]->SPD,
	//this->Enermy_arr[0]->SPD,this->Enermy_arr[1]->SPD,this->Enermy_arr[2]->SPD,this->Enermy_arr[3]->SPD };

	//this->m_player->Hero_array[0]->SPD = m_player->Hero_array[0]->SPD;
	//this->m_player->Hero_array[1]->SPD = m_player->Hero_array[1]->SPD;
	//this->m_player->Hero_array[2]->SPD = m_player->Hero_array[2]->SPD;
	//this->m_player->Hero_array[3]->SPD = m_player->Hero_array[3]->SPD;

	//this->Enermy_arr[0]->SPD = Enermy_arr[0]->SPD;
	//this->Enermy_arr[1]->SPD = Enermy_arr[1]->SPD;
	//this->Enermy_arr[2]->SPD = Enermy_arr[2]->SPD;
	//this->Enermy_arr[3]->SPD = Enermy_arr[3]->SPD;
	////속도에 따른 재정렬
	//for (int i = 0; i < 8; i++) {
	//	int maxindex = i;
	//	int maxNum = turn_number[i];
	//	for (int j = i + 1; j < 8; j++) {
	//		if (maxNum < turn_number[j]) {
	//			maxindex = j;
	//			maxNum = turn_number[j];
	//		}
	//	}
	//	int temp = turn_number[i];
	//	turn_number[i] = turn_number[maxindex];
	//	turn_number[maxindex] = temp;
	//}

}

CBattleSystem::CBattleSystem()
{
}

CBattleSystem::~CBattleSystem()
{
}

HRESULT CBattleSystem::Init()
{
	return S_OK;
}

void CBattleSystem::Update(float deltaTime, float worldTime)
{
}

void CBattleSystem::LateUpdate()
{

}

void CBattleSystem::BackRender(HDC _hdc)
{

}

void CBattleSystem::Render(HDC _hdc)
{

}

void CBattleSystem::FrontRender(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (size_t i = 0; i < speedVec.size(); i++)
	{
		//string temp = speedVec[i].second->GetName();
		//temp += " : " + to_string(speedVec[i].first) + "," + to_string(speedVec[i].second->GetPartyIndex());
		sprintf_s(str,   " : %d, %d", speedVec[i].first, speedVec[i].second->GetPartyIndex());
		TextOut(_hdc, 0, 100, str, strlen(str));
	}
}

void CBattleSystem::Release()
{

}
