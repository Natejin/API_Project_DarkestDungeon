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
	auto _info = heroDB[job];
	auto info = new Info_Hero();
	info->unitType = _info->unitType;
	info->m_HP = _info->m_HP;
	info->m_SPD = _info->m_SPD;
	for (size_t i = 0; i < 5; i++)
	{
		info->resist[i] = _info->resist[i];
	}
	for (size_t i = 0; i < 8; i++)
	{
		info->attribute[i] = false;
	}

	//hero
	info->job = _info->job;
	info->m_DMG = _info->m_DMG;
	info->m_ACRY = _info->m_ACRY;
	info->m_CRI = _info->m_CRI;
	info->m_DEF = _info->m_DEF;
	info->m_DODGE = _info->m_DODGE;
	//info->ownSkill = _info->ownSkill;

	info->imageIdle = _info->imageIdle;
	info->imageWalk = _info->imageWalk;
	info->imageCombat = _info->imageCombat;



	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;
	info->portrait = _info->portrait;
	info->weapon = _info->weapon;
	info->armor = _info->armor;
	for (size_t i = 0; i < _info->ownSkill.size(); i++)
	{
		info->ownSkill.push_back(_info->ownSkill[i]);
	}
	MG_INFO->RegisterInfo(info);
	return info;
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
	MG_INFO->RegisterInfo(info);

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
	//info->ownSkill.push_back(SKILL::Vestal_Combat_DazzlingLight);
	info->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);

	info->portrait = IMAGE::Vestal_portrait;
	info->weapon.push_back(IMAGE::Vestal_Weapon_0);
	info->armor.push_back(IMAGE::Vestal_Armor_0);
	heroDB.insert(make_pair(info->job, info));
	MG_INFO->RegisterInfo(info);
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
