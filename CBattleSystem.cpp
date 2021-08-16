#include "framework.h"
#include "CBattleSystem.h"
#include "DungeonScene.h"
#include "CParty.h"
#include "CHero.h"
#include "CEnemy.h"
#include "CBoneDefender.h"
#include "dungeonUI.h";
#include "dungeonUI_HeroInfo.h"
#include "CBTN_Skill.h"
#include "Info_Skill.h"
#include "Info_Enemy.h"
#include "ImageObject.h"
#include "MonsterIndicator.h"


CBattleSystem::CBattleSystem()
{

}

CBattleSystem::~CBattleSystem()
{

}

HRESULT CBattleSystem::Init()
{
	
	////mouseOnEnemy.m_img = MG_IMAGE->findImage(IMAGE::panel_monster_Red);

	targetEnemyPosVec.push_back(Vector2(1160, 700));
	targetEnemyPosVec.push_back(Vector2(1360, 700));
	targetEnemyPosVec.push_back(Vector2(1560, 700));
	targetEnemyPosVec.push_back(Vector2(1760, 700));

	monsterIndicator = new MonsterIndicator();
	monsterIndicator->Init();
	monsterIndicator->Disable();
	MG_GMOBJ->RegisterObj(monsterIndicator);
	SetZoomImage();
	return S_OK;
}

void CBattleSystem::SetZoomImage()
{


	enemyZoomImage = new ImageObject();
	enemyZoomImage->originPos = Vector2(1100, 800);
	enemyZoomImage->speed =10;
	enemyZoomImage->Init();
	MG_GMOBJ->RegisterObj(enemyZoomImage);

	heroZoomImage = new ImageObject();
	heroZoomImage->originPos = Vector2(600, 800);
	heroZoomImage->speed = 10;
	heroZoomImage->Init();
	MG_GMOBJ->RegisterObj(heroZoomImage);
}

void CBattleSystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown('P'))
	{
		BattleSystemEnd();
	}

	if (MG_INPUT->isOnceKeyDown('N'))
	{
		StartTurn();
	}

	

	if (startNextTurn && worldTime > startTriggerTime)
	{
		startNextTurn = false;
		StartTurn();
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
	/*mouseOnEnemy.RenderWithPivot(_hdc);*/
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
	CreateEnemyParty();
	CreateHeroesParty();
	Compare_P_E_Speed_ReArray();
	monsterIndicator->Enable();
	scene->m_dungeonMode = DUNGEONMODE::BATTLE;
	curTurn = 1;
	isActive = true;
	monsterIndicator->m_transform->m_pos.x = enemyParty[0]->m_transform->m_pos.x;
	StartTurn();
}

void CBattleSystem::BattleSystemEnd()
{
	monsterIndicator->Disable();
	scene->m_dungeonMode = DUNGEONMODE::WALK;
	heroParty.clear();
	for (size_t i = 0; i < enemyParty.size(); i++)
	{
		enemyParty[i]->Disable();
		MG_GMOBJ->RemoveObj(enemyParty[i]);
	}
	enemyParty.clear();
	speedVec.clear();
	Disable();
}



void CBattleSystem::StartTurn()
{
	DeselectAll();
	if (speedVec.size() == 0)
	{
		Compare_P_E_Speed_ReArray();
		curTurn++;
	}

	if (speedVec.size() > 0)
	{
		Unit* unit = speedVec[speedVec.size() - 1].second;
		if (unit->getHP() > 0)
		{
			if (unit->GetUnitType() == UNITTYPE::Hero)
			{
				curHero = (CHero*)unit;
				curHero->isSelected = true;
				turn = TURN::Player;
				speedVec.pop_back();
			}
			else if (unit->GetUnitType() == UNITTYPE::Enemy)
			{
				curEnemy = (CEnemy*)unit;
				curEnemy->isSelected = true;
				turn = TURN::Enemy;
				speedVec.pop_back();
			}
			else {
				assert(true);
			}
		}
		else {
			StartTurn();
		}
		
	}

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
	StartHeroTrun(curHero->GetPartyIndex());
}

void CBattleSystem::EnemyTurn()
{
	StartEnemyTrun(curEnemy->GetPartyIndex());

}

void CBattleSystem::EndTurn()
{
	curHero = nullptr;
	curEnemy = nullptr;
}

void CBattleSystem::UseSkill(int _index)
{
	for (int i = 0; i < dungeonUI->skillBTNs.size() - 1; i++)
	{
		dungeonUI->skillBTNs[i]->selected = false;
	}
	dungeonUI->skillBTNs[_index]->selected = true;
	currentSkill = _index;
	if (scene->m_dungeonMode == DUNGEONMODE::BATTLE)
	{
		if (turn == TURN::Player)
		{
			DeselectAll();
			curHero->isSelected = true;
	

			if (scene->m_dungeonMode == DUNGEONMODE::BATTLE)
			{
				SKILL skill = MG_GAME->GetCurSelHero()->GetOwnSkill()[currentSkill];
				CInfo_Skill* tempSkill = DB_SKILL->CallSkill(skill);

				switch (tempSkill->target)
				{
				case SKILLTARGET::Enemy:
					SelectEnemyTarget(MG_GAME->GetCurSelHero()->GetOwnSkill()[_index]);
					break;
				case SKILLTARGET::Enemies:
					SelectEnemyTarget(MG_GAME->GetCurSelHero()->GetOwnSkill()[_index]);
					break;
				case SKILLTARGET::Self:
					//SelectEnemyTarget(MG_GAME->GetCurSelHero()->GetOwnSkill()[_index]); 
					//졸려 ㅅㅂ.....
					break;
				case SKILLTARGET::Ally:
					SelectHeroTarget(MG_GAME->GetCurSelHero()->GetOwnSkill()[_index]);
					break;
				case SKILLTARGET::Allies:
					SelectHeroTarget(MG_GAME->GetCurSelHero()->GetOwnSkill()[_index]);
					break;
				default:
					break;
				}


			}
		}
	}
	
	
}



void CBattleSystem::CreateEnemyParty()
{
	int random = MG_RND->getInt(2) + 2;
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	Vector2 cameraPos = MG_CAMERA->GetCenterPos();
	Vector2 heroPos = MG_GAME->GetHero(0)->m_transform->m_pos;
	for (size_t i = 0; i < random; i++)
	{
		CEnemy* enemy = new CEnemy();
		enemy->Init(DB_UNIT->CallEnemy(ENEMYTYPE::BoneDefender)); //TODO 추후 적 세팅 변경하기
		enemy->m_transform->m_pivot = Vector2(0.5, 1);
		enemy->SetPartyPos(i);
		enemy->SetPartyIndex(i);
		enemy->SetTriggerWhenClick(this, &CBattleSystem::SelectEnemy);
		enemy->SetTriggerWhenStay(this, &CBattleSystem::SetEnemyIndicator);

		if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
		{
			enemy->m_transform->m_pos = Vector2(worldSize.x * 0.5 + 200 + 200 * i, heroPos.y);
			targetEnemyPosVec[i].x = enemy->m_transform->m_pos.x;
		}
		else {
			enemy->m_transform->m_pos = Vector2(cameraPos.x + 200 + 200 * i, heroPos.y);
			targetEnemyPosVec[i].x = enemy->m_transform->m_pos.x;
		}
		MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
		enemyParty.push_back(enemy);
	}
}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = MG_GAME->GetHeroPartySize();
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	Vector2 cameraPos = MG_CAMERA->GetCenterPos();
	Vector2 heroPos = MG_GAME->GetHero(0)->m_transform->m_pos;
	for (int i = 0; i < playerPartySize; i++)
	{
		heroParty.push_back(MG_GAME->GetHero(i));
		heroParty[i]->SetPartyIndex(i);
		if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
		{
			heroParty[i]->m_transform->m_pos = Vector2(worldSize.x * 0.5 - 200 - 200 * i, heroPos.y);
		}
		else {
			heroParty[i]->m_transform->m_pos = Vector2(cameraPos.x - 200 - 200 * i, heroPos.y);
		}
		
		heroParty[i]->m_animator->SetIndex(2);
		heroParty[i]->SetTriggerWhenClick(this, &CBattleSystem::SelectHero);
	}
}

void CBattleSystem::Compare_P_E_Speed_ReArray()
{	
	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < heroParty.size(); i++)
	{
		if (heroParty[i]->getHP() < 1) continue;
		speedVec.push_back(make_pair(heroParty[i]->GetSpeed() + MG_RND->getInt(randomDice6) , heroParty[i]));
	}

	//플레이어 영웅들을 speed turn에 추가
	for (int i = 0; i < enemyParty.size(); i++)
	{
		if (enemyParty[i]->getHP() < 1) continue;
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
	if (!startNextTurn && scene->m_dungeonMode == DUNGEONMODE::BATTLE && turn == TURN::Player)
	{
		SKILL skill = MG_GAME->GetCurSelHero()->GetOwnSkill()[currentSkill];
		CInfo_Skill* tempSkill = DB_SKILL->CallSkill(skill);

		switch (tempSkill->target)
		{
		case SKILLTARGET::Enemy:
			CheckAndDamageEnemy(tempSkill, index);
			break;
		case SKILLTARGET::Enemies:
			for (int i = 0; i < enemyParty.size(); i++)
			{
				CheckAndDamageEnemy(tempSkill, i);
			}
			break;
		default:
			break;
		}
	}
}

void CBattleSystem::CheckAndDamageEnemy(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(index))
	{
		heroZoomImage->m_spriteRenderer->SetImage(tempSkill->m_skillMotion);
		heroZoomImage->targetPos = heroZoomImage->originPos;
		heroZoomImage->targetPos.x += 200;
		heroZoomImage->speed = 5;
		heroZoomImage->Enable();



		enemyZoomImage->m_spriteRenderer->SetImage(enemyParty[index]->GetInfo()->imageDefend);
		enemyZoomImage->targetPos = enemyZoomImage->originPos;
		enemyZoomImage->targetPos.x += 100;
		enemyZoomImage->speed = 2;
		enemyZoomImage->Enable();

		startTriggerTime = MG_TIME->getWorldTime() + 5;
		startNextTurn = true;

		enemyParty[index]->reduceHP(tempSkill->GetDamage(MG_GAME->m_CurSelHero->GetInfo(), enemyParty[index]->GetInfo()));
		DeselectAll();	
	}
}

void CBattleSystem::SelectHero(int index)
{
	if (!startNextTurn && scene->m_dungeonMode == DUNGEONMODE::BATTLE && turn == TURN::Player)
	{
		SKILL skill = MG_GAME->GetCurSelHero()->GetOwnSkill()[currentSkill];
		CInfo_Skill* tempSkill = DB_SKILL->CallSkill(skill);

		switch (tempSkill->target)
		{
		case SKILLTARGET::Ally:
			CheckAndHealAlly(tempSkill, index);
			break;
		case SKILLTARGET::Allies:
			for (int i = 0; i < enemyParty.size(); i++)
			{
				CheckAndHealAlly(tempSkill, index);
			}
			break;
		default:
			break;
		}
	}
}

void CBattleSystem::CheckAndHealAlly(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(index))
	{
		heroZoomImage->m_spriteRenderer->SetImage(tempSkill->m_skillMotion);
		heroZoomImage->targetPos = heroZoomImage->originPos;
		heroZoomImage->targetPos.x += 200;
		heroZoomImage->speed = 10;
		heroZoomImage->Enable();

		//enemyParty[index]->increaseHP();

		startTriggerTime = MG_TIME->getWorldTime() + 5;
		startNextTurn = true;

		enemyParty[index]->increaseHP(tempSkill->GetHeal());

		DeselectAll();

	}
}

void CBattleSystem::SelectHeroTarget(SKILL skill)
{
	if (turn == TURN::Player && !startNextTurn)
	{
		auto tempSkill = DB_SKILL->CallSkill(skill);
		for (int i = 0; i < heroParty.size(); i++)
		{
			heroParty[i]->isTargetHeal = tempSkill->CheckTarget(i) ? true : false;
		}
	}
}

void CBattleSystem::DeselectAll()
{
	for (size_t i = 0; i < enemyParty.size(); i++)
	{
		enemyParty[i]->isSelected = false;
		enemyParty[i]->isTargetSkill = false;
	}

	for (size_t i = 0; i < heroParty.size(); i++)
	{
		heroParty[i]->isSelected = false;
		heroParty[i]->isTargetHeal = false;
	}
}




void CBattleSystem::SetEnemyIndicator(int index)
{

	monsterIndicator->SetPosIndex(index);
	monsterIndicator->MonsterIsTargetSkill(enemyParty[index]->isTargetSkill ? true : false);
}

void CBattleSystem::SelectEnemyTarget(SKILL skill)
{
	if (turn == TURN::Player && !startNextTurn)
	{
		auto tempSkill = DB_SKILL->CallSkill(skill);
		for (int i = 0; i < enemyParty.size(); i++)
		{
			enemyParty[i]->isTargetSkill = tempSkill->CheckTarget(i) ? true : false;
		}
	}
}

CHero* CBattleSystem::GetHero(int index)
{
	return index < heroParty.size() ? heroParty[index] : nullptr;
}

void CBattleSystem::StartHeroTrun(int index)
{
	MG_GAME->SetCurSelHero(index);
}

void CBattleSystem::StartEnemyTrun(int index)
{
	bool isFoundTarget = false;
	vector<SKILL> ownSkill = enemyParty[index]->GetInfo()->ownSkill;
	CInfo_Skill* enemySkill = DB_SKILL->CallSkill(ownSkill[MG_RND->getInt(ownSkill.size())]);
	
	/*while (!isFoundTarget)
	{
		for (size_t i = 0; i < heroParty.size(); i++)
		{
			if (heroParty[i] != nullptr && heroParty[i]->GetAlive())
			{
				if (enemySkill->CheckTarget(heroParty[i]->GetPosition()))
				{

				}
			}

		}
		
	}*/


}

void CBattleSystem::ShowTargetBySkill(int index)
{

}






