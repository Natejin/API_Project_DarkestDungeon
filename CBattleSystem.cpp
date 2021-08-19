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
CBattleSystem::~CBattleSystem() {}

HRESULT CBattleSystem::Init()
{
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
	m_enemyInfoUI->m_battleSys = this;
	m_enemyInfoUI->Init();
	m_enemyInfoUI->Disable();
	MG_GMOBJ->RegisterObj(m_enemyInfoUI);

	SetZoomImage();
	return S_OK;
}

void CBattleSystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown(VK_F3))
	{
		BattleSystemEnd();
	}
	if (MG_INPUT->isOnceKeyDown(VK_F4))
	{
		StartTurn();
	}

	//if (MG_INPUT->isOnceKeyDown('R'))
	//{
	//	for (size_t i = 0; i < enemyParty.size(); i++)
	//	{
	//		enemyParty[i]->ShowWordCount(MG_RND->getInt(100), (NumCorType)MG_RND->getInt(3));
	//	}
	//	for (size_t i = 0; i < heroParty.size(); i++)
	//	{
	//		heroParty[i]->ShowWordCount(MG_RND->getInt(100), (NumCorType)MG_RND->getInt(3));
	//	}
	//}

	if (startNextTurn && worldTime > startTriggerTime)
	{
		if (delayForSwapSetPosition)
		{
			startTriggerTime += 3;
			SetPosition();
			delayForSwapSetPosition = false;
		}
		else 
		{
			startNextTurn = false;
			StartTurn();
		}
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
			sprintf_s(str, "[Hero's Turn] POS : % d, SPEED : % d, HP : %d / %d", 
				speedVec[i].second->GetPartyIndex(), 
				speedVec[i].first,
				speedVec[i].second->getHP(),
				speedVec[i].second->getMaxHP());
			TextOut(_hdc, 200, 100 + 20 * i, str, strlen(str));
		}
		else 
		{
			sprintf_s(str, "[Enemy's Turn] POS : %d, SPEED : %d HP : %d / %d", 
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

//==================================

void CBattleSystem::BattleSystemInitiate()
{
	worldSize = MG_CAMERA->GetWorldSize();
	cameraSize = MG_CAMERA->GetCenterPos();
	m_enemyInfoUI->Enable();
	originPosOfBattle = MG_GAME->GetHeroFromParty(0)->m_transform->m_pos;
	CreateHeroesParty();
	CreateEnemyParty();
	Compare_P_E_Speed_ReArray();
	monsterIndicator->Enable();
	scene->m_dungeonMode = DUNGEONMODE::BATTLE;
	curTurn = 1;
	monsterIndicator->m_transform->m_pos.x = enemyParty[0]->m_transform->m_pos.x;
	StartTurn();
	scene->DeactivateSound();
	MG_SOUND->play(SOUND::Combat, 0.1f);
	isBattle = true;

	Enable();
}

void CBattleSystem::BattleSystemEnd()
{
	m_enemyInfoUI->Disable();
	monsterIndicator->Disable();
	scene->m_dungeonMode = DUNGEONMODE::WALK;
	

	MG_GAME->m_partyOrigin.clear();

	MG_GAME->m_partyOrigin.push_back(nullptr);
	MG_GAME->m_partyOrigin.push_back(nullptr);
	MG_GAME->m_partyOrigin.push_back(nullptr);
	MG_GAME->m_partyOrigin.push_back(nullptr);
	for (size_t i = 0; i < posHero.size(); i++)
	{
		MG_GAME->RegisterHeroToParty(heroParty[posHero[i]]);
		MG_GAME->m_partyOrigin[i]->SetPartyIndex(i);
		MG_GAME->m_partyOrigin[i]->SetPartyPos(i);
	}
	scene->m_party->SetPartyMember(MG_GAME->m_partyOrigin);


	for (size_t i = 0; i < heroParty.size(); i++)
	{
		heroParty[i]->movePosMode = false;
	}
	heroParty.clear();

	for (size_t i = 0; i < enemyParty.size(); i++)
	{
		MG_GMOBJ->RemoveObj(enemyParty[i]);
	}
	enemyParty.clear();


	posEnemy.clear();
	posHero.clear();
	speedVec.clear();
	scene->m_dungeonUIinfo->setButton();
	MG_SOUND->stop(SOUND::Combat);
	scene->ActivateSound();
	isBattle = false;
	if (isBoss)
	{
		isBoss = false;
		MG_SOUND->play(SOUND::raid_success, 0.5f);
	}

	auto party = MG_GAME->m_partyOrigin;

	Disable();
}

void CBattleSystem::StartTurn()
{
	DeselectAll();

	if (speedVec.size() == 0)
	{
		Compare_P_E_Speed_ReArray();
		curTurn++;
		if (isBattle)
		{
			StartTurn();
		}
	}
	else 
	{
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
			SKILL skill = curHero->GetOwnSkill()[currentSkill];
			CInfo_Skill* tempSkill = DB_SKILL->CallSkill(skill);

			switch (tempSkill->target)
			{
			case SKILLTARGET::Enemy:
				SelectEnemyTarget(curHero->GetOwnSkill()[_index]);
				break;
			case SKILLTARGET::Enemies:
				SelectEnemyTarget(curHero->GetOwnSkill()[_index]);
				break;
			case SKILLTARGET::Self:
				//SelectEnemyTarget(curHero->GetOwnSkill()[_index]); 
				//���� ����.....
				break;
			case SKILLTARGET::Ally:
				SelectHeroTarget(curHero->GetOwnSkill()[_index]);
				break;
			case SKILLTARGET::Allies:
				SelectHeroTarget(curHero->GetOwnSkill()[_index]);
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


	if (isBoss)
	{

			CEnemy* enemy = new CEnemy();
			enemy->Init(DB_UNIT->CallEnemy(ENEMYTYPE::Necromancer)); //TODO ���� �� ���� �����ϱ�
			enemy->m_transform->m_pivot = Vector2(0.5, 1);
			enemy->SetPartyPos(0);
			enemy->SetPartyIndex(0);
			enemy->SetTriggerWhenClick(this, &CBattleSystem::SelectEnemy);
			enemy->SetTriggerWhenStay(this, &CBattleSystem::SetEnemyIndicator);
			enemy->movePosMode = true;
			posEnemy.push_back(0);
			monsterIndicator->enemyPosIndex = 0;
			enemy->m_transform->m_pos = Vector2(worldSize.x * 0.5 + 350, originPosOfBattle.y);
			targetEnemyPosVec[0].x = enemy->m_transform->m_pos.x;
			SetIndicatorPos(enemy);
			enemy->targetPos = enemy->m_transform->m_pos;
			enemy->movePosMode = true;
			MG_GMOBJ->RegisterObj("boss", enemy);
			enemyParty.push_back(enemy);
	}else{
		for (size_t i = 0; i < 4; i++)
		{
			CEnemy* enemy = new CEnemy();
			enemy->Init(DB_UNIT->CallEnemy((ENEMYTYPE)MG_RND->getInt(3))); //TODO ���� �� ���� �����ϱ�
			enemy->m_transform->m_pivot = Vector2(0.5, 1);
			enemy->SetPartyPos(i);
			enemy->SetPartyIndex(i);
			enemy->SetTriggerWhenClick(this, &CBattleSystem::SelectEnemy);
			enemy->SetTriggerWhenStay(this, &CBattleSystem::SetEnemyIndicator);
			enemy->movePosMode = true;
			posEnemy.push_back(i);

			if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
			{
				enemy->m_transform->m_pos = Vector2(worldSize.x * 0.5 + 100 + 150 * i, originPosOfBattle.y);
				targetEnemyPosVec[i].x = enemy->m_transform->m_pos.x;
			}
			else
			{
				enemy->m_transform->m_pos = Vector2(cameraSize.x + 100 + 150 * i, originPosOfBattle.y);
				targetEnemyPosVec[i].x = enemy->m_transform->m_pos.x;
			}
			SetIndicatorPos(enemy);
			enemy->targetPos = enemy->m_transform->m_pos;
			enemy->movePosMode = true;
			MG_GMOBJ->RegisterObj("enemy_" + i, enemy);
			enemyParty.push_back(enemy);
		}
	
	}

}
void CBattleSystem::SetIndicatorPos(CEnemy* enemy)
{
	Vector2 indicatorPos = enemy->m_transform->m_pos;
	indicatorPos.y += 50;
	monsterIndicator->PushEnemyPos(indicatorPos);
}
//
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

//==================================

void CBattleSystem::DelayUntillNextTurn(int second)
{
	startTriggerTime = MG_TIME->getWorldTime() + second;
	startNextTurn = true;
	DeselectAll();
}

bool CBattleSystem::CheckAndDamageEnemy(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(enemyParty[index]->GetPartyPos()))
	{
		MG_SOUND->play(tempSkill->sound, soundEffectVolume);

		enemyParty[index]->GetInfo()->attribute[(int)tempSkill->effect] = true;
		if (enemyParty[index]->GetAlive())
		{

			int damage = tempSkill->GetDamage(MG_GAME->m_CurSelHero->GetInfo(), enemyParty[index]->GetInfo());
			//ȸ����
			if (damage <= -1)
			{
				//TODO missAttack
			}
			else 
			{
				SetZoomImage(heroZoomImage, tempSkill->m_skillMotion, 200, 3);
				SetZoomImage(enemyZoomImage, enemyParty[index]->GetInfo()->imageDefend, 100, 2);
				SetEffectImage(Vector2(-400, 0), Vector2(0, 0), 10);


				if (enemyParty[index]->reduceHP(damage))
				{
					enemyParty[index]->ShowWordCount(damage, NumCorType::Red);
					CheckEnemyAllDead();
				}
				else {
					enemyParty[index]->ShowWordCount(99, NumCorType::Black);
				}
			}
		}
		else if(enemyParty[index]->GetCorpse())
		{
			enemyParty[index]->SetCorpse(false);
			enemyParty[index]->Disable();
			delayForSwapSetPosition = true;
			for (size_t i = 0; i < posEnemy.size(); i++)
			{
				if (posEnemy[i] == index)
				{

					posEnemy.erase(posEnemy.begin() + i);
					break;
				}
			}
		}
		DelayUntillNextTurn(delayTriggerEffect);
		return true;
	}
	return false;
}

void CBattleSystem::CheckEnemyAllDead()
{
	bool isAllDead = true;
	for (size_t i = 0; i < enemyParty.size(); i++)
	{

		if (enemyParty[i]->GetAlive())
		{

			isAllDead = false;
			break;
		}

	}
	if (isAllDead)
	{
		EnemyTeamAreDead();
	}
}
//
void CBattleSystem::CheckAndHealAlly(CInfo_Skill* tempSkill, int index)
{
	if (tempSkill->CheckTarget(heroParty[index]->GetPartyPos()))
	{
		MG_SOUND->play(tempSkill->sound, soundEffectVolume);
		SetZoomImage(heroZoomImage, tempSkill->m_skillMotion, 200, 10);
		int hp = tempSkill->GetHeal();
		heroParty[index]->increaseHP(hp);
		heroParty[index]->ShowWordCount(hp, NumCorType::Green);

		DelayUntillNextTurn(delayTriggerEffect);
		SetEffectImage(Vector2(-200, 0), Vector2(0, 0), 2);
	}
}

void CBattleSystem::CheckAndSwapHeroPos(int index)
{
	if (curHero->GetPartyPos() != heroParty[index]->GetPartyPos())
	{
		int oldPos1 = curHero->GetPartyPos();
		int oldPos2 = heroParty[index]->GetPartyPos();
		int oldIndex1 = curHero->GetPartyIndex();
		int oldIndex2 = heroParty[index]->GetPartyIndex();

		heroParty[oldIndex1]->SetPartyPos(oldPos2);
		heroParty[oldIndex2]->SetPartyPos(oldPos1);
		posHero[oldIndex1] = oldPos2;
		posHero[oldIndex2] = oldPos1;

		delayForSwapSetPosition = true;

		DelayUntillNextTurn(1);
	}
}

//==================================

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
			SKILL skill = curHero->GetOwnSkill()[currentSkill];
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

void CBattleSystem::SelectHeroTarget(SKILL skill)
{
	if (turn == TURN::Player && !startNextTurn)
	{
		auto tempSkill = DB_SKILL->CallSkill(skill);
		for (int i = 0; i < heroParty.size(); i++)
		{
			heroParty[i]->isTargetHeal = tempSkill->CheckTarget(heroParty[i]->GetPartyPos()) ? true : false;
		}
	}
}

void CBattleSystem::SelectEnemyTarget(SKILL skill)
{
	if (turn == TURN::Player && !startNextTurn)
	{
		auto tempSkill = DB_SKILL->CallSkill(skill);
		for (int i = 0; i < enemyParty.size(); i++)
		{
			enemyParty[i]->isTargetSkill = tempSkill->CheckTarget(enemyParty[i]->GetPartyPos()) ? true : false;
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

//==================================

void CBattleSystem::SetZoomImage()
{
	enemyZoomImage = new ImageObject();
	enemyZoomImage->originPos = Vector2(1100, 800);
	enemyZoomImage->speed = 10;
	enemyZoomImage->Init();
	MG_GMOBJ->RegisterObj(enemyZoomImage);

	heroZoomImage = new ImageObject();
	heroZoomImage->originPos = Vector2(600, 800);
	heroZoomImage->speed = 10;
	heroZoomImage->Init();
	MG_GMOBJ->RegisterObj(heroZoomImage);
}

void CBattleSystem::SetZoomImage(ImageObject* zoomImage, IMAGE skillMotion, float distance, float speed)
{
	zoomImage->m_spriteRenderer->SetImage(skillMotion);
	zoomImage->targetPos = zoomImage->originPos;
	zoomImage->targetPos.x += distance;
	zoomImage->speed = speed;
	zoomImage->Enable();
}

void CBattleSystem::SetEffectImage(Vector2 startPos, Vector2 targetPos, float speed)
{
	effectBGImage->m_transform->m_pos = startPos;
	effectBGImage->targetPos = targetPos;
	effectBGImage->speed = speed;
	effectBGImage->Enable();
}

void CBattleSystem::SetEnemyIndicator(int index)
{
	if (enemyParty.size()>0)
	{
		monsterIndicator->SetPosIndex(enemyParty[index]->GetPartyPos());
		monsterIndicator->MonsterIsTargetSkill(enemyParty[index]->isTargetSkill ? true : false);
	}

}

void CBattleSystem::SetPosition() 
{


	for (size_t i = 0; i < heroParty.size(); i++)
	{
		if (heroParty[i] == nullptr) continue;
		if (heroParty[i]->GetAlive())
		{
			if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
			{
				heroParty[i]->targetPos = Vector2(worldSize.x * 0.5 - 100 - 150 * heroParty[i]->GetPartyPos(), originPosOfBattle.y);
			}
			else 
			{
				heroParty[i]->targetPos = Vector2(cameraSize.x - 100 - 150 * heroParty[i]->GetPartyPos(), originPosOfBattle.y);
			}
		}
		else 
		{
			heroParty[i]->Disable();
		}
	}
	
	for (size_t i = 0; i < posEnemy.size(); i++)
	{
		int index = posEnemy[i];
		if (enemyParty[index]->GetAlive() || enemyParty[index]->GetCorpse())
		{
			enemyParty[index]->SetPartyPos(i);
			if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
			{
				enemyParty[index]->targetPos = Vector2(worldSize.x * 0.5 + 100 + 150 * enemyParty[index]->GetPartyPos(), originPosOfBattle.y);
			}
			else {
				enemyParty[index]->targetPos = Vector2(cameraSize.x + 100 + 150 * enemyParty[index]->GetPartyPos(), originPosOfBattle.y);
			}
		}
	}
}

//==================================

//void CBattleSystem::CreateEnemyParty()
//{
//	if (enemyParty.size() > 0)
//	{
//		monsterIndicator->SetPosIndex(enemyParty[index]->GetPartyPos());
//		monsterIndicator->MonsterIsTargetSkill(enemyParty[index]->isTargetSkill ? true : false);
//	}
//
//}

void CBattleSystem::CreateHeroesParty()
{
	int playerPartySize = MG_GAME->GetHeroPartySize();

	//Vector2 heroPos = MG_GAME->GetHeroFromParty(0)->m_transform->m_pos;
	int k = 0;
	for (int i = 0; i < playerPartySize; i++, k++)
	{
		CHero* hero = MG_GAME->GetHeroFromParty(i);
		if (hero != nullptr)
		{
			heroParty.push_back(hero);


			heroParty[k]->SetPartyIndex(k);
			heroParty[k]->SetPartyPos(k);
			posHero.push_back(k);

			if (scene->m_dungeonState == DUNGEONSTATE::ROOM)
			{
				heroParty[k]->m_transform->m_pos = Vector2(worldSize.x * 0.5 - 100 - 150 * k, originPosOfBattle.y);

			}
			else 
			{
				heroParty[k]->m_transform->m_pos = Vector2(cameraSize.x - 100 - 150 * k, originPosOfBattle.y);
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
		if (!heroParty[i]->GetAlive()) continue;
		isAllDead = false;
		speedVec.push_back(make_pair(heroParty[i]->GetSpeed() + MG_RND->getInt(randomDice6) , heroParty[i]));
	}
	if (isAllDead)
	{
		HeroTeamAreDead();
		return;
	}
	isAllDead = true;

	//������ speed turn�� �߰�
	for (int i = 0; i < enemyParty.size(); i++)
	{
		if (!enemyParty[i]->GetAlive()) continue;
		isAllDead = false;
		speedVec.push_back(make_pair(enemyParty[i]->GetSpeed() + MG_RND->getInt(randomDice6), enemyParty[i]));
	}

	if (isAllDead)
	{
		EnemyTeamAreDead();
		return;
	}

	//�˰������� �̿��� ����
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
		SKILL skill = curHero->GetOwnSkill()[currentSkill];
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

//==================================

CHero* CBattleSystem::GetHero(int index)
{
	return index < heroParty.size() ? heroParty[index] : nullptr;
}

void CBattleSystem::StartHeroTrun(int index)
{
	//MG_GAME->SetCurSelHero(index);
	//for (int i = 0; i < heroParty.size(); i++)
	//{
	//	heroParty[i]->isSelected = false;
	//}
	//m_party->GetHero(index)->isSelected = true;

	scene->m_dungeonUIinfo->SetPortrait(curHero->GetInfo()->portrait);
	scene->m_dungeonUIinfo->SetWeapon(curHero->GetInfo()->weapon[0]);
	scene->m_dungeonUIinfo->SetArmor(curHero->GetInfo()->armor[0]);

	vector<SKILL> temp = curHero->GetInfo()->ownSkill;

	for (int j = 0; j < scene->m_dungeonUI->skillBTNs.size(); j++)
	{
		if (temp.size() > j)
		{
			CInfo_Skill* skillInfo = DB_SKILL->CallSkill(temp[j]);
			scene->m_dungeonUI->skillBTNs[j]->Enable();
			scene->m_dungeonUI->skillBTNs[j]->SetSkill(temp[j]);
			scene->m_dungeonUI->skillBTNs[j]->ActiveSkill(skillInfo->CheckUseable(curHero->GetPartyPos()));
		}
		else {
			scene->m_dungeonUI->skillBTNs[j]->Disable();
		}
	}
}

void CBattleSystem::StartEnemyTrun(int index)
{
	bool isFoundTarget = false;
	vector<SKILL> ownSkill = enemyParty[index]->GetInfo()->ownSkill;

	while (!isFoundTarget)
	{
		if (ownSkill.size() < 1)
		{
			return;
		}
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
					MG_SOUND->play(enemySkill->sound, soundEffectVolume);
					heroParty[orderIndex]->GetInfo()->attribute[(int)enemySkill->effect] = true;

					SetZoomImage(enemyZoomImage, enemySkill->m_skillMotion, -100, 2);
					SetZoomImage(heroZoomImage, heroParty[orderIndex]->GetInfo()->imageDefend, -200, 5);
					SetEffectImage(Vector2(-400,0), Vector2(0, 0), 10);
					int damage = enemySkill->GetDamage(curEnemy->GetInfo(), heroParty[orderIndex]->GetInfo());
					if (heroParty[orderIndex]->reduceHP(damage))
					{
						heroParty[orderIndex]->ShowWordCount(damage, NumCorType::Red);
					}
					else {
						heroParty[orderIndex]->ShowWordCount(99, NumCorType::Black);
					}
					DelayUntillNextTurn(5);
					return;
				}
			}
		}
	}
}

void CBattleSystem::HeroTeamAreDead()
{
	BattleSystemEnd();
}

void CBattleSystem::EnemyTeamAreDead()
{
	BattleSystemEnd();
}