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
#include "ImageEffectBG.h"
#include "CEnemyInfoUI.h"

CBattleSystem::CBattleSystem()
{
	m_layer = LAYER::UIMotion;
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

	effectBGImage = new ImageEffectBG();
	effectBGImage->originPos = Vector2(-200, 0);
	effectBGImage->speed = 10;
	effectBGImage->Init();
	effectBGImage->Disable();
	MG_GMOBJ->RegisterObj(effectBGImage);

	m_enemyInfoUI = new CEnemyInfoUI();
	m_enemyInfoUI->Init();
	m_enemyInfoUI->Enable();
	MG_GMOBJ->RegisterObj(m_enemyInfoUI);

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
			sprintf_s(str, "���� : ��ġ % d, �ӵ� : % d, ü�� : %d/ %d", 
				speedVec[i].second->GetPartyIndex(), 
				speedVec[i].first,
				speedVec[i].second->getHP(),
				speedVec[i].second->getMaxHP());
			TextOut(_hdc, 200, 100 + 20 * i, str, strlen(str));
		}
		else {
			sprintf_s(str, "�� : ��ġ %d, �ӵ� : %d ü�� : %d/ %d", 
				speedVec[i].second->GetPartyIndex(), 
				speedVec[i].first, 
				speedVec[i].second->getHP(),
				speedVec[i].second->getMaxHP());
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
	monsterIndicator->Enable();
	scene->m_dungeonMode = DUNGEONMODE::BATTLE;
	curTurn = 1;
	isActive = true;
	monsterIndicator->m_transform->m_pos.x = enemyParty[0]->m_transform->m_pos.x;
	StartTurn();
	Enable();
}

void CBattleSystem::BattleSystemEnd()
{
	monsterIndicator->Disable();
	scene->m_dungeonMode = DUNGEONMODE::WALK;
	
	for (size_t i = 0; i < heroParty.size(); i++)
	{
		heroParty[i]->movePosMode = false;
	}

	heroParty.clear();
	for (size_t i = 0; i < enemyParty.size(); i++)
	{
		enemyParty[i]->Disable();
		MG_GMOBJ->RemoveObj(enemyParty[i]);
	}
	enemyParty.clear();
	speedVec.clear();
	scene->m_dungeonUIinfo->setButton();
	Disable();
}

void CBattleSystem::StartTurn()
{
	DeselectAll();
	if (speedVec.size() == 0)
	{
		Compare_P_E_Speed_ReArray();
		curTurn++;
		StartTurn();
	}
	else {
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
				else 
				{
					assert(true);
				}
			}
			else 
			{
				speedVec.pop_back();
				StartTurn();
			}

			if (turn == TURN::Player)
			{
				HeroTurn();
			}
			else 
			{
				EnemyTurn();
			}
		}
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
	for (int i = 0; i < dungeonUI->skillBTNs.size(); i++)
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
				//���� ����.....
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
	int random = MG_RND->getInt(3) + 2;
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	Vector2 cameraPos = MG_CAMERA->GetCenterPos();
	Vector2 heroPos = heroParty[0]->m_transform->m_pos;
	for (size_t i = 0; i < 4; i++)
	{
		CEnemy* enemy = new CEnemy();
		enemy->Init(DB_UNIT->CallEnemy(ENEMYTYPE::BoneDefender)); //TODO ���� �� ���� �����ϱ�
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
		else 
		{
			enemy->m_transform->m_pos = Vector2(cameraPos.x + 200 + 200 * i, heroPos.y);
			targetEnemyPosVec[i].x = enemy->m_transform->m_pos.x;
		}
		enemy->targetPos = enemy->m_transform->m_pos;
		enemy->movePosMode = true;
		MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
		enemyParty.push_back(enemy);
	}
}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = MG_GAME->GetHeroPartySize();
	Vector2 worldSize = MG_CAMERA->GetWorldSize();
	Vector2 cameraPos = MG_CAMERA->GetCenterPos();
	Vector2 heroPos = MG_GAME->GetHeroFromParty(0)->m_transform->m_pos;
	int k = 0;
	for (int i = 0; i < playerPartySize; i++, k++)
	{
		CHero* hero = MG_GAME->GetHeroFromParty(i);
		if (hero != nullptr)
		{
			heroParty.push_back(hero);
			heroParty[k]->SetPartyIndex(k);
			if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
			{
				heroParty[k]->m_transform->m_pos = Vector2(worldSize.x * 0.5 - 200 - 200 * k, heroPos.y);
			}
			else 
			{
				heroParty[k]->m_transform->m_pos = Vector2(cameraPos.x - 200 - 200 * k, heroPos.y);
			}

			heroParty[k]->m_animator->SetIndex(2);
			heroParty[k]->SetTriggerWhenClick(this, &CBattleSystem::SelectHero);
			heroParty[k]->targetPos = heroParty[k]->m_transform->m_pos;
			heroParty[k]->movePosMode = true;
		}
		else 
		{
			k--;
		}
	}
}

void CBattleSystem::Compare_P_E_Speed_ReArray()
{	
	//�÷��̾� �������� speed turn�� 
	bool isAllDead = true;
	for (int i = 0; i < heroParty.size(); i++)
	{
		if (heroParty[i]->getHP() < 1) continue;
		isAllDead = false;
		speedVec.push_back(make_pair(heroParty[i]->GetSpeed() + MG_RND->getInt(randomDice6) , heroParty[i]));
	}
	if (isAllDead)
	{
		HeroTeamAreDead();
	}
	isAllDead = true;

	//������ speed turn�� �߰�
	for (int i = 0; i < enemyParty.size(); i++)
	{
		if (enemyParty[i]->getHP() < 1) continue;
		isAllDead = false;
		speedVec.push_back(make_pair(enemyParty[i]->GetSpeed() + MG_RND->getInt(randomDice6), enemyParty[i]));
	}

	if (isAllDead)
	{
		EnemyTeamAreDead();
	}

	//�˰����� �̿��� ����
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

bool CBattleSystem::CheckAndDamageEnemy(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(index))
	{
		SetZoomImage(heroZoomImage, tempSkill->m_skillMotion, 200, 5);
		SetZoomImage(enemyZoomImage, enemyParty[index]->GetInfo()->imageDefend, 100, 2);
		SetEffectImage(0, -400, 10);

		enemyParty[index]->reduceHP(tempSkill->GetDamage(MG_GAME->m_CurSelHero->GetInfo(), enemyParty[index]->GetInfo()));
		DelayUntillNextTurn(5);
		return true;
	}
	return false;
}

void CBattleSystem::DelayUntillNextTurn(int second)
{
	startTriggerTime = MG_TIME->getWorldTime() + second;
	startNextTurn = true;
	DeselectAll();
}

bool CBattleSystem::CheckAndDamageHero(CInfo_Skill* tempSkill, int index)
{
	return false;
}

void CBattleSystem::SelectHero(int index)
{
	if (!startNextTurn && scene->m_dungeonMode == DUNGEONMODE::BATTLE && turn == TURN::Player)
	{
		if (isSwapModeOn)
		{
			if (heroParty[index]->isTargetHeal)
			{
				CheckAndSwapHeroPos(index);
			}
		}
		else 
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
}

void CBattleSystem::CheckAndHealAlly(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(index))
	{
		SetZoomImage(heroZoomImage, tempSkill->m_skillMotion, 200, 10);
		enemyParty[index]->increaseHP(tempSkill->GetHeal());
		DelayUntillNextTurn(3);
	}
}

void CBattleSystem::SetZoomImage(ImageObject* zoomImage, IMAGE skillMotion, float distance, float speed)
{
	zoomImage->m_spriteRenderer->SetImage(skillMotion);
	zoomImage->targetPos = heroZoomImage->originPos;
	zoomImage->targetPos.x += distance;
	zoomImage->speed = speed;
	zoomImage->Enable();
}

void CBattleSystem::SetEffectImage(float startPos, float targetPos, float speed)
{
	effectBGImage->m_transform->m_pos = Vector2(startPos, 0);
	effectBGImage->targetPos = effectBGImage->m_transform->m_pos;
	effectBGImage->targetPos.x += targetPos;
	effectBGImage->speed = speed;
	effectBGImage->Enable();
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
	isSwapModeOn = false;
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

void CBattleSystem::CheckAndSwapHeroPos(int index)
{
	if (curHero->GetPartyPos() != heroParty[index]->GetPartyPos())
	{
		int tempPos = curHero->GetPartyPos();
		curHero->SetPartyPos(heroParty[index]->GetPartyPos());
		heroParty[index]->SetPartyPos(tempPos);

		Vector2 tempTargetPos = curHero->targetPos;
		curHero->targetPos = heroParty[index]->targetPos;
		heroParty[index]->targetPos = tempTargetPos;
		DelayUntillNextTurn(3);
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

	//�������� �������ִ½�ų�� �ϳ��� �����ͼ�
	//Ÿ����(�÷��̾�� ����)�� ã����
	//Ÿ���� ������� �ٸ���ų�� �ݺ�����
	while (!isFoundTarget)
	{
		int curSkillIndex = MG_RND->getInt(ownSkill.size());
		CInfo_Skill* enemySkill = DB_SKILL->CallSkill(ownSkill[curSkillIndex]);
		ownSkill.erase(ownSkill.begin() + curSkillIndex);

		vector<int> order;
		for (size_t i = 0; i < heroParty.size(); i++)
		{
			order.push_back(i);
		}

		while (order.size() > 0)
		{
			int orderIndex = MG_RND->getInt(order.size());
			order.erase(order.begin() + orderIndex);
			if (heroParty[orderIndex] != nullptr && heroParty[orderIndex]->GetAlive())
			{
				if (enemySkill->CheckTarget(heroParty[orderIndex]->GetPartyPos()))
				{
					isFoundTarget = true;

					SetZoomImage(enemyZoomImage, enemySkill->m_skillMotion, -100, 2);
					SetZoomImage(heroZoomImage, heroParty[orderIndex]->GetInfo()->imageDefend, -200, 5);
					SetEffectImage(-400, 400, 10);

					heroParty[orderIndex]->reduceHP(enemySkill->GetDamage(curEnemy->GetInfo(), heroParty[orderIndex]->GetInfo()));
					DelayUntillNextTurn(5);
					return;
				}
			}
		}
	}
}

void CBattleSystem::ShowTargetBySkill(int index)
{

}

void CBattleSystem::HeroTeamAreDead()
{
	BattleSystemEnd();
}

void CBattleSystem::EnemyTeamAreDead()
{
	BattleSystemEnd();
}

void CBattleSystem::SwapPosSkill()
{
	if (scene->m_dungeonMode == DUNGEONMODE::BATTLE)
	{
		DeselectAll();
		curHero->isSelected = true;
		int curIndex = curHero->GetPartyPos();
		isSwapModeOn = true;
		switch (curIndex)
		{
		case 0:
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 1)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			break;

		case 1:
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 0)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 2)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			break;

		case 2:
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 1)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 3)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			break;

		case 3:
			for (size_t i = 0; i < heroParty.size(); i++)
			{
				if (heroParty[i]->GetPartyPos() == 2)
				{
					heroParty[i]->isTargetHeal = true;
					break;
				}
			}
			break;
		}
	}
}