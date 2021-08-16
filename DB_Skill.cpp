#include "framework.h"
#include "DB_Skill.h"
#include "image.h"
#include "Info_Skill.h"

CDB_Skill::CDB_Skill()
{
}

CDB_Skill::~CDB_Skill()
{
}

void CDB_Skill::Init()
{
	id = 0;
	SetHeroSkill();
	SetEnemySkill();
}

void CDB_Skill::SetHeroSkill()
{
	CInfo_Skill* info = new CInfo_Skill();
#pragma region Crusader
	info = new CInfo_Skill();
	info->m_name = "Smite";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_Smite;
	info->m_skillIcon = IMAGE::Crusader_Skill_Smite;
	info->m_skillMotion = IMAGE::Crusader_sword;
	info->damage[0] = 0.f;
	info->damage[1] = 0.f;
	info->damage[2] = 0.f;
	info->damage[3] = 0.f;
	info->damage[4] = 0.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_Smite, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Zealous Accusation";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->target = SKILLTARGET::Enemies;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_ZealousAccusation;
	info->m_skillIcon = IMAGE::Crusader_Skill_ZealousAccusation;
	info->m_skillMotion = IMAGE::Crusader_charge;
	info->damage[0] = -40.f;
	info->damage[1] = -40.f;
	info->damage[2] = -40.f;
	info->damage[3] = -40.f;
	info->damage[4] = -40.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = -4.f;
	info->critMod[1] = -3.f;
	info->critMod[2] = -2.f;
	info->critMod[3] = -1.f;
	info->critMod[4] = -0.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_ZealousAccusation, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Stunning Blow";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_StunningBlow;
	info->m_skillIcon = IMAGE::Crusader_Skill_StunningBlow;
	info->m_skillMotion = IMAGE::Crusader_scroll;
	info->effect = EFFECTTYPE::Stun;
	info->damage[0] = -50.f;
	info->damage[1] = -50.f;
	info->damage[2] = -50.f;
	info->damage[3] = -50.f;
	info->damage[4] = -50.f;
	info->accuracy[0] = 90;
	info->accuracy[1] = 95;
	info->accuracy[2] = 100;
	info->accuracy[3] = 105;
	info->accuracy[4] = 110;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_StunningBlow, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "BattleHeal";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 15;
	info->m_skillImageType = SKILLIMAGETYPE::Buff;
	info->target = SKILLTARGET::Ally;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Heal_BattleHeal;
	info->m_skillIcon = IMAGE::Crusader_Skill_BattleHeal;
	info->m_skillMotion = IMAGE::Crusader_banner;
	info->healMin[0] = 2;
	info->healMin[1] = 3;
	info->healMin[2] = 3;
	info->healMin[3] = 4;
	info->healMin[4] = 4;
	info->healMax[0] = 3;
	info->healMax[1] = 3;
	info->healMax[2] = 4;
	info->healMax[3] = 5;
	info->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Crusader_Heal_BattleHeal, info));
	MG_INFO->RegisterInfo(info);
#pragma endregion


#pragma region Vestal
	info = new CInfo_Skill();
	info->m_name = "Smite";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_MaceBash;
	info->m_skillIcon = IMAGE::Vestal_Skill_MaceBash;
	info->m_skillMotion = IMAGE::Vestal_mace;
	info->damage[0] = 0.f;
	info->damage[1] = 0.f;
	info->damage[2] = 0.f;
	info->damage[3] = 0.f;
	info->damage[4] = 0.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_MaceBash, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Judgement";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_Judgement;
	info->m_skillIcon = IMAGE::Vestal_Skill_Judgement;
	info->m_skillMotion = IMAGE::Vestal_miracle;
	info->damage[0] = -25.f;
	info->damage[1] = -25.f;
	info->damage[2] = -25.f;
	info->damage[3] = -25.f;
	info->damage[4] = -25.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 5.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 7.f;
	info->critMod[3] = 8.f;
	info->critMod[4] = 9.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_Judgement, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Dazzling Light";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 7;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Debuff;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_DazzlingLight;
	info->m_skillIcon = IMAGE::Vestal_Skill_DazzlingLight;
	info->m_skillMotion = IMAGE::Vestal_lectionary;
	info->effect = EFFECTTYPE::Stun;
	info->damage[0] = -75.f;
	info->damage[1] = -75.f;
	info->damage[2] = -75.f;
	info->damage[3] = -75.f;
	info->damage[4] = -75.f;
	info->accuracy[0] = 90;
	info->accuracy[1] = 95;
	info->accuracy[2] = 100;
	info->accuracy[3] = 105;
	info->accuracy[4] = 110;
	info->critMod[0] = 5.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 7.f;
	info->critMod[3] = 8.f;
	info->critMod[4] = 9.f;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_DazzlingLight, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Divine Comfort";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Buff;
	info->target = SKILLTARGET::Allies;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Heal_DivineComfort;
	info->m_skillIcon = IMAGE::Vestal_Skill_DivineComfort;
	info->m_skillMotion = IMAGE::Vestal_heal;
	info->healMin[0] = 1;
	info->healMin[1] = 2;
	info->healMin[2] = 3;
	info->healMin[3] = 3;
	info->healMin[4] = 4;
	info->healMax[0] = 3;
	info->healMax[1] = 3;
	info->healMax[2] = 3;
	info->healMax[3] = 4;
	info->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Vestal_Heal_DivineComfort, info));
	MG_INFO->RegisterInfo(info);
#pragma endregion
}

void CDB_Skill::SetEnemySkill()
{

	CInfo_Skill* info = new CInfo_Skill();
	info->m_name = "BoneDefender Skill 1";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->enemyType = ENEMYTYPE::BoneDefender;
	info->m_skill = SKILL::BoneDefender_Combat_1;
	info->m_skillIcon = IMAGE::Enemy_SkeletonDefender_Attack;
	info->m_skillMotion = IMAGE::Enemy_SkeletonDefender_Attack;
	info->damage[0] = 0.f;
	info->damage[1] = 0.f;
	info->damage[2] = 0.f;
	info->damage[3] = 0.f;
	info->damage[4] = 0.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::BoneDefender_Combat_1, info));
	MG_INFO->RegisterInfo(info);
}

CInfo_Skill* CDB_Skill::CallSkill(SKILL skill)
{
	return skillDB[skill];
}

Image* CDB_Skill::CallSkillImage(SKILL skill)
{
	return MG_IMAGE->findImage(skillDB[skill]->m_skillIcon);
}
