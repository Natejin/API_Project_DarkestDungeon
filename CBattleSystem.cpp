#include "framework.h"
#include "CBattleSystem.h"
#include "DungeonScene.h"
#include "CParty.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CBoneDefender.h"

void CBattleSystem::BattleSystemInitiate()
{
	CreateHeroesParty();
	CreateEnemyParty();
	Compare_P_E_Speed_ReArray();
	isActive = true;
}
//enemy->m_transform->m_pos = Vector2(WINSIZEX / 2 + i * 100, WINSIZEY);
void CBattleSystem::CreateEnemyParty()
{
	int random = MG_RND->getInt(2) + 2;
	for (size_t i = 0; i < random; i++)
	{

		CBoneDefender* enemy = new CBoneDefender();
		enemy->Init(); //TODO 추후 적 세팅 변경하기

		MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
		enemyParty.push_back(enemy);
		enemyParty[i]->SetPosition(i);
		enemyParty[i]->SetPartyIndex(i);
		enemyParty[i]->m_transform->m_pos = Vector2(1100 + 150 * i, 360);
	}
}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = MG_GAME->GetHeroPartySize();

	for (int i = 0; i < playerPartySize; i++)
	{
		heroParty.push_back(MG_GAME->GetHero(i));
		heroParty[i]->SetPosition(i);
		heroParty[i]->SetPartyIndex(i);
		heroParty[i]->m_transform->m_pos = Vector2(700 - 150 * i, 360);
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
