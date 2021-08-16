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

CBattleSystem::CBattleSystem()
{
	m_layer = LAYER::UI;
	enemyPosIndex = 0;
}

CBattleSystem::~CBattleSystem()
{

}

HRESULT CBattleSystem::Init()
{
	mouseOnEnemy.m_img = MG_IMAGE->findImage(IMAGE::panel_monster_Black);
	//mouseOnEnemy.m_img = MG_IMAGE->findImage(IMAGE::panel_monster_Red);

	targetEnemyPosVec.push_back(Vector2(1160, 640));
	targetEnemyPosVec.push_back(Vector2(1360, 640));
	targetEnemyPosVec.push_back(Vector2(1560, 640));
	targetEnemyPosVec.push_back(Vector2(1760, 640));


	SetZoomImage();

	mouseOnEnemy.m_trans.m_pivot = Vector2(0.5, 0.5);
	mouseOnEnemy.m_trans.m_pos = targetEnemyPosVec[0];
	return S_OK;
}

void CBattleSystem::SetZoomImage()
{
	heroZoomImage = new ImageObject();
	heroZoomImage->originPos = Vector2(700, 800);
	heroZoomImage->speed = 10;
	heroZoomImage->Init();
	MG_GMOBJ->RegisterObj(heroZoomImage);

	enemyZoomImage = new ImageObject();
	enemyZoomImage->originPos = Vector2(1100, 800);
	enemyZoomImage->speed =10;
	enemyZoomImage->Init();
	MG_GMOBJ->RegisterObj(enemyZoomImage);
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
	float x = abs(mouseOnEnemy.m_trans.m_pos.x - targetEnemyPosVec[enemyPosIndex].x);
	if (x > 60)
	{
		mouseOnEnemy.m_trans.m_pos += (targetEnemyPosVec[enemyPosIndex] - mouseOnEnemy.m_trans.m_pos).Normalize() * 20;
	}
	else if (x > 20) {
		mouseOnEnemy.m_trans.m_pos += (targetEnemyPosVec[enemyPosIndex] - mouseOnEnemy.m_trans.m_pos).Normalize() * 3;
	}
	else if (x > 1) {
		mouseOnEnemy.m_trans.m_pos += (targetEnemyPosVec[enemyPosIndex] - mouseOnEnemy.m_trans.m_pos).Normalize() * 1;
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

}

void CBattleSystem::FrontRender(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(0, 255, 255));
	mouseOnEnemy.RenderWithPivot(_hdc);

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
	scene->m_dungeonMode = DUNGEONMODE::BATTLE;
	curTurn = 1;
	isActive = true;
	mouseOnEnemy.m_trans.m_pos.x = enemyParty[0]->m_transform->m_pos.x;
	StartTurn();
}

void CBattleSystem::BattleSystemEnd()
{
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
	if (turn == TURN::Player)
	{
		DeselectAll();
		curHero->isSelected = true;
		for (int i = 0; i < dungeonUI->skillBTNs.size() - 1; i++)
		{
			dungeonUI->skillBTNs[i]->selected = false;
		}
		dungeonUI->skillBTNs[_index]->selected = true;
		currentSkill = _index;

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
		enemy->SetPosition(i);
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
		heroParty.push_back(MG_GAME->GetHeroFromParty(i));
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

		if (tempSkill->target == SKILLTARGET::Enemies || tempSkill->target == SKILLTARGET::Enemy)
		{
			if (tempSkill->CheckTarget(index))
			{
				heroZoomImage->m_spriteRenderer->SetImage(tempSkill->m_skillMotion);
				heroZoomImage->targetPos = heroZoomImage->originPos;
				heroZoomImage->targetPos.x += 400;
				heroZoomImage->speed = 10;
				heroZoomImage->Enable();



				enemyZoomImage->m_spriteRenderer->SetImage(enemyParty[index]->GetInfo()->imageDefend);
				enemyZoomImage->targetPos = enemyZoomImage->originPos;
				enemyZoomImage->targetPos.x +=  100;
				enemyZoomImage->speed = 2;
				enemyZoomImage->Enable();

				startTriggerTime = MG_TIME->getWorldTime() + 5;
				startNextTurn = true;

				DeselectAll();

			}
		}
	}
}

void CBattleSystem::SelectHero(int index)
{
	if (!startNextTurn && scene->m_dungeonMode == DUNGEONMODE::BATTLE && turn == TURN::Player)
	{
		SKILL skill = MG_GAME->GetCurSelHero()->GetOwnSkill()[currentSkill];
		CInfo_Skill* tempSkill = DB_SKILL->CallSkill(skill);

		if (tempSkill->target == SKILLTARGET::Allies || tempSkill->target == SKILLTARGET::Ally)
		{
			if (tempSkill->CheckTarget(index))
			{
				heroZoomImage->m_spriteRenderer->SetImage(tempSkill->m_skillMotion);
				heroZoomImage->targetPos = heroZoomImage->originPos;
				heroZoomImage->targetPos.x += 200;
				heroZoomImage->speed = 10;
				heroZoomImage->Enable();



				/*enemyZoomImage->m_spriteRenderer->SetImage(enemyParty[index]->GetInfo()->imageDefend);
				enemyZoomImage->speed = Vector2(0, 0);
				enemyZoomImage->Enable();*/

				startTriggerTime = MG_TIME->getWorldTime() + 5;
				startNextTurn = true;

				DeselectAll();

			}
		}
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
	enemyPosIndex = index;
	if (enemyParty[index]->isTargetSkill)
	{
		mouseOnEnemy.m_img = MG_IMAGE->findImage(IMAGE::panel_monster_Red);
	}
	else {
		mouseOnEnemy.m_img = MG_IMAGE->findImage(IMAGE::panel_monster_Black);
	}
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
}

void CBattleSystem::ShowTargetBySkill(int index)
{

}






