#include "framework.h"
#include "CBattleSystem.h"
#include "DungeonScene.h"
#include "CParty.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CBoneDefender.h"
#include "dungeonUI.h";
#include "dungeonUI_HeroInfo.h"




CBattleSystem::CBattleSystem()
{
	m_layer = LAYER::UI;
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
	if (MG_INPUT->isOnceKeyDown('P'))
	{
		BattleSystemEnd();
	}

	if (MG_INPUT->isOnceKeyDown('N'))
	{
		EndTurn();
	}
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
	SetTextColor(_hdc, RGB(0, 255, 255));

	for (size_t i = 0; i < speedVec.size(); i++)
	{
		if (speedVec[i].second->GetUnitType() == UNITTYPE::Hero)
		{
			sprintf_s(str, "영웅 : 위치 % d, 속도 : % d", speedVec[i].second->GetPartyIndex(), speedVec[i].first);
			TextOut(_hdc, 200, 100 + 20 * i, str, strlen(str));
		}
		else {
			sprintf_s(str, "적 : 위치 % d, 속도 : % d", speedVec[i].second->GetPartyIndex(), speedVec[i].first);
			TextOut(_hdc, 500, 100 + 20 * i, str, strlen(str));
		}

	}
}

void CBattleSystem::Release()
{

}









void CBattleSystem::BattleSystemInitiate()
{
	CreateHeroesParty();
	CreateEnemyParty();
	Compare_P_E_Speed_ReArray();
	scene->m_dungeonMode = DUNGEONMODE::BATTLE;
	curTurn = 1;
	isActive = true;
	StartTurn();
}
void CBattleSystem::BattleSystemEnd()
{
	scene->m_dungeonMode = DUNGEONMODE::WALK;
	heroParty.clear();
	for (size_t i = 0; i < enemyParty.size(); i++)
	{
		enemyParty[i]->Unable();
		MG_GMOBJ->RemoveObj(enemyParty[i]);
	}
	enemyParty.clear();
	speedVec.clear();
	Unable();
}



void CBattleSystem::StartTurn()
{
	
	if (speedVec.size() > 0)
	{
		Unit* unit = speedVec[speedVec.size() - 1].second;
		if (unit->GetUnitType()== UNITTYPE::Hero)
		{
			curHero = (CHero*)unit;
			turn = TURN::Player;
		}
		else if (unit->GetUnitType() == UNITTYPE::Enemy)
		{
			curEnemy = (CEnemy*)unit;
			turn = TURN::Enemy;
		}
		else {
			assert(true);
		}
	}
	speedVec.pop_back();
	if (turn == TURN::Player)
	{
		HeroTurn();
	}
	else {
		EnemyTurn();
	}
}

void CBattleSystem::HeroTurn()
{
	SelectHero(curHero->GetPartyIndex());


}

void CBattleSystem::EnemyTurn()
{
	SelectEnemy(curEnemy->GetPartyIndex());



}

void CBattleSystem::EndTurn()
{
	curHero = nullptr;
	curEnemy = nullptr;
}

void CBattleSystem::UseSkill1()
{
	//for (size_t i = 0; i < dungeonUIHeroinfo->->GetPartySize(); i++)
	//{
	//	m_party->GetHero(i)->isSelected = false;
	//}
	//m_party->GetHero(i)->isSelected = true;
}
void CBattleSystem::UseSkill2()
{

}
void CBattleSystem::UseSkill3()
{

}
void CBattleSystem::UseSkill4()
{

}

//enemy->m_transform->m_pos = Vector2(WINSIZEX / 2 + i * 100, WINSIZEY);
void CBattleSystem::CreateEnemyParty()
{
	int random = MG_RND->getInt(2) + 2;
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	for (size_t i = 0; i < random; i++)
	{
		CBoneDefender* enemy = new CBoneDefender();
		enemy->Init(); //TODO 추후 적 세팅 변경하기
		enemy->m_transform->m_pivot = Vector2(0.5, 1);
		enemy->SetPosition(i);
		enemy->SetPartyIndex(i);
		enemy->SetTriggerWhenClick(this, &CBattleSystem::SelectEnemy);
		enemy->m_transform->m_pos = Vector2(worldSize.x * 0.5 + 200 + 200 * i, 560);
		MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
		enemyParty.push_back(enemy);
	}


}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = MG_GAME->GetHeroPartySize();
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	for (int i = 0; i < playerPartySize; i++)
	{
		heroParty.push_back(MG_GAME->GetHero(i));
		heroParty[i]->SetPartyIndex(i);
		heroParty[i]->SetPartyIndex(i);
		heroParty[i]->m_transform->m_pos = Vector2(worldSize.x * 0.5 - 200 - 200 * i, 560);
		heroParty[i]->m_animator->SetIndex(2);
	}
}

void CBattleSystem::Compare_P_E_Speed_ReArray()
{	
	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < heroParty.size(); i++)
	{
		speedVec.push_back(make_pair(heroParty[i]->GetSpeed() + MG_RND->getInt(randomDice6) , heroParty[i]));
	}

	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < enemyParty.size(); i++)
	{
		speedVec.push_back(make_pair(enemyParty[i]->GetSpeed() + MG_RND->getInt(randomDice6), enemyParty[i]));
	}

	//알고리즘을 이용한 정렬
	sort(speedVec.begin(), speedVec.end());

}





CEnemy* CBattleSystem::GetEnemy(int index)
{
	return index < enemyParty.size() ? enemyParty[index] : nullptr;
}


void CBattleSystem::SelectEnemy(int index)
{
	for (int i = 0; i < enemyParty.size(); i++)
	{
		if (i == index) GetEnemy(i)->isSelected = true;
		else GetEnemy(i)->isSelected = false;
	}
}

CHero* CBattleSystem::GetHero(int index)
{
	return index < heroParty.size() ? heroParty[index] : nullptr;
}

void CBattleSystem::SelectHero(int index)
{
	MG_GAME->SetCurSelHero(index);
}

void CBattleSystem::ShowTargetBySkill(int index)
{
}
