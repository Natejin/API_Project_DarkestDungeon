#include "framework.h"
#include "DB_UnitInfo.h"

DB_UnitInfo::DB_UnitInfo()
{
}

DB_UnitInfo::~DB_UnitInfo()
{
}

void DB_UnitInfo::Init()
{
	SetHero();
	SetEnemy();
}

Info_Hero* DB_UnitInfo::CallHero(JOB job)
{
	return heroDB[job];
}

Info_Enemy* DB_UnitInfo::CallEnemy(ENEMYTYPE enemyType)
{
	return enemyDB[enemyType];
}

void DB_UnitInfo::SetHero()
{
	Info_Hero* info = new Info_Hero();
	info->unitType = UNITTYPE::Hero;
	info->m_HP = 33;
	info->m_SPD = 1;

	info->job = JOB::Crusader;
	info->m_DMG = 1;
	info->m_ACRY = 9;
	info->m_CRI = 0;
	info->m_DEF = 3;
	info->m_DODGE = 0;
	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;

	info->imageIdle = IMAGE::Crusader_Idle;
	info->imageCombat = IMAGE::Crusader_Combat;
	info->imageWalk = IMAGE::Crusader_Walk;
	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Crusader_Combat_Smite);
	info->ownSkill.push_back(SKILL::Crusader_Combat_ZealousAccusation);
	info->ownSkill.push_back(SKILL::Crusader_Combat_StunningBlow);
	info->ownSkill.push_back(SKILL::Crusader_Heal_BattleHeal);

	info->portrait = IMAGE::Crusader_portrait;
	info->weapon.push_back( IMAGE::Crusader_Weapon_0);
	info->armor.push_back( IMAGE::Crusader_Armor_0);
	heroDB.insert(make_pair(info->job, info));


	info = new Info_Hero();
	info->unitType = UNITTYPE::Hero;
	info->m_HP = 22;
	info->m_SPD = 4;


	info->job = JOB::Vestal;
	info->m_DMG = 3;
	info->m_ACRY = 4;
	info->m_CRI = 2;
	info->m_DEF = 5;
	info->m_DODGE = 2;
	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;

	info->imageIdle = IMAGE::Vestal_Idle;
	info->imageCombat = IMAGE::Vestal_Idle;
	info->imageWalk = IMAGE::Vestal_Idle;
	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Vestal_Combat_MaceBash);
	info->ownSkill.push_back(SKILL::Vestal_Combat_Judgement);
	info->ownSkill.push_back(SKILL::Vestal_Combat_DazzlingLight);
	info->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);

	info->portrait = IMAGE::Vestal_portrait;
	info->weapon.push_back(IMAGE::Vestal_Weapon_0);
	info->armor.push_back(IMAGE::Vestal_Armor_0);
	heroDB.insert(make_pair(info->job, info));
}

void DB_UnitInfo::SetEnemy()
{
}



void DB_UnitInfo::Save()
{
}

void DB_UnitInfo::Load()
{
}
