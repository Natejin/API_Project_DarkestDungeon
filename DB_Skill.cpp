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
	CInfo_Skill* temp = new CInfo_Skill();
#pragma region Crusader
	temp = new CInfo_Skill();
	temp->m_name = "Smite";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 3;
	temp->allowUseSkillPos = 3;
	temp->target = SKILLTARGET::Enemy;
	temp->job = JOB::Crusader;
	temp->m_skill = SKILL::Crusader_Combat_Smite;
	temp->m_imgData = IMAGE::Crusader_Skill_Smite;
	temp->damage[0] = 0.f;
	temp->damage[1] = 0.f;
	temp->damage[2] = 0.f;
	temp->damage[3] = 0.f;
	temp->damage[4] = 0.f;
	temp->accuracy[0] = 85;
	temp->accuracy[1] = 90;
	temp->accuracy[2] = 95;
	temp->accuracy[3] = 100;
	temp->accuracy[4] = 105;
	temp->critMod[0] = 0.f;
	temp->critMod[1] = 1.f;
	temp->critMod[2] = 2.f;
	temp->critMod[3] = 3.f;
	temp->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_Smite, temp));

	temp = new CInfo_Skill();
	temp->m_name = "Zealous Accusation";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 3;
	temp->allowUseSkillPos = 3;
	temp->target = SKILLTARGET::Enemies;
	temp->job = JOB::Crusader;
	temp->m_skill = SKILL::Crusader_Combat_ZealousAccusation;
	temp->m_imgData = IMAGE::Crusader_Skill_ZealousAccusation;
	temp->damage[0] = -40.f;
	temp->damage[1] = -40.f;
	temp->damage[2] = -40.f;
	temp->damage[3] = -40.f;
	temp->damage[4] = -40.f;
	temp->accuracy[0] = 85;
	temp->accuracy[1] = 90;
	temp->accuracy[2] = 95;
	temp->accuracy[3] = 100;
	temp->accuracy[4] = 105;
	temp->critMod[0] = -4.f;
	temp->critMod[1] = -3.f;
	temp->critMod[2] = -2.f;
	temp->critMod[3] = -1.f;
	temp->critMod[4] = -0.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_ZealousAccusation, temp));

	temp = new CInfo_Skill();
	temp->m_name = "Stunning Blow";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 3;
	temp->allowUseSkillPos = 3;
	temp->target = SKILLTARGET::Enemy;
	temp->job = JOB::Crusader;
	temp->m_skill = SKILL::Crusader_Combat_StunningBlow;
	temp->m_imgData = IMAGE::Crusader_Skill_StunningBlow;
	temp->effect = EFFECTTYPE::Stun;
	temp->damage[0] = -50.f;
	temp->damage[1] = -50.f;
	temp->damage[2] = -50.f;
	temp->damage[3] = -50.f;
	temp->damage[4] = -50.f;
	temp->accuracy[0] = 90 ;
	temp->accuracy[1] = 95 ;
	temp->accuracy[2] = 100;
	temp->accuracy[3] = 105;
	temp->accuracy[4] = 110;
	temp->critMod[0] = 0.f;
	temp->critMod[1] = 1.f;
	temp->critMod[2] = 2.f;
	temp->critMod[3] = 3.f;
	temp->critMod[4] = 4.f;
	temp->effectVal[0] = 100.f;
	temp->effectVal[1] = 110.f;
	temp->effectVal[2] = 120.f;
	temp->effectVal[3] = 130.f;
	temp->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_StunningBlow, temp));

	temp = new CInfo_Skill();
	temp->m_name = "BattleHeal";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 15;
	temp->allowUseSkillPos = 15;
	temp->target = SKILLTARGET::Ally;
	temp->job = JOB::Crusader;
	temp->m_skill = SKILL::Crusader_Heal_BattleHeal;
	temp->m_imgData = IMAGE::Crusader_Skill_BattleHeal;
	temp->healMin[0] = 2;
	temp->healMin[1] = 3;
	temp->healMin[2] = 3;
	temp->healMin[3] = 4;
	temp->healMin[4] = 4;
	temp->healMax[0] = 3;
	temp->healMax[1] = 3;
	temp->healMax[2] = 4;
	temp->healMax[3] = 5;
	temp->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Crusader_Heal_BattleHeal, temp));
#pragma endregion
	
	
#pragma region Vestal
	temp = new CInfo_Skill();
	temp->m_name = "Smite";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 3;
	temp->allowUseSkillPos = 3;
	temp->target = SKILLTARGET::Enemy;
	temp->job = JOB::Vestal;
	temp->m_skill = SKILL::Vestal_Combat_MaceBash;
	temp->m_imgData = IMAGE::Vestal_Skill_MaceBash;
	temp->damage[0] = 0.f;
	temp->damage[1] = 0.f;
	temp->damage[2] = 0.f;
	temp->damage[3] = 0.f;
	temp->damage[4] = 0.f;
	temp->accuracy[0] = 85;
	temp->accuracy[1] = 90;
	temp->accuracy[2] = 95;
	temp->accuracy[3] = 100;
	temp->accuracy[4] = 105;
	temp->critMod[0] = 0.f;
	temp->critMod[1] = 1.f;
	temp->critMod[2] = 2.f;
	temp->critMod[3] = 3.f;
	temp->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_MaceBash, temp));

	temp = new CInfo_Skill();
	temp->m_name = "Judgement";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 15;
	temp->allowUseSkillPos = 3;
	temp->target = SKILLTARGET::Enemy;
	temp->job = JOB::Vestal;
	temp->m_skill = SKILL::Vestal_Combat_Judgement;
	temp->m_imgData = IMAGE::Vestal_Skill_Judgement;
	temp->damage[0] = -25.f;
	temp->damage[1] = -25.f;
	temp->damage[2] = -25.f;
	temp->damage[3] = -25.f;
	temp->damage[4] = -25.f;
	temp->accuracy[0] = 85;
	temp->accuracy[1] = 90;
	temp->accuracy[2] = 95;
	temp->accuracy[3] = 100;
	temp->accuracy[4] = 105;
	temp->critMod[0] = 5.f;
	temp->critMod[1] = 6.f;
	temp->critMod[2] = 7.f;
	temp->critMod[3] = 8.f;
	temp->critMod[4] = 9.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_Judgement, temp));

	temp = new CInfo_Skill();
	temp->m_name = "Dazzling Light";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 7;
	temp->allowUseSkillPos = 14;
	temp->target = SKILLTARGET::Enemy;
	temp->job = JOB::Vestal;
	temp->m_skill = SKILL::Vestal_Combat_DazzlingLight;
	temp->m_imgData = IMAGE::Vestal_Skill_DazzlingLight;
	temp->effect = EFFECTTYPE::Stun;
	temp->damage[0] = -75.f;
	temp->damage[1] = -75.f;
	temp->damage[2] = -75.f;
	temp->damage[3] = -75.f;
	temp->damage[4] = -75.f;
	temp->accuracy[0] = 90;
	temp->accuracy[1] = 95;
	temp->accuracy[2] = 100;
	temp->accuracy[3] = 105;
	temp->accuracy[4] = 110;
	temp->critMod[0] = 5.f;
	temp->critMod[1] = 6.f;
	temp->critMod[2] = 7.f;
	temp->critMod[3] = 8.f;
	temp->critMod[4] = 9.f;
	temp->effectVal[0] = 100.f;
	temp->effectVal[1] = 110.f;
	temp->effectVal[2] = 120.f;
	temp->effectVal[3] = 130.f;
	temp->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_DazzlingLight, temp));

	temp = new CInfo_Skill();
	temp->m_name = "Divine Comfort";
	temp->m_description = "";
	temp->m_ID = id++;
	temp->skillLevel = 0;
	temp->targetPos = 15;
	temp->allowUseSkillPos = 14;
	temp->target = SKILLTARGET::Allies;
	temp->job = JOB::Vestal;
	temp->m_skill = SKILL::Vestal_Heal_DivineComfort;
	temp->m_imgData = IMAGE::Vestal_Skill_DivineComfort;
	temp->healMin[0] = 1;
	temp->healMin[1] = 2;
	temp->healMin[2] = 3;
	temp->healMin[3] = 3;
	temp->healMin[4] = 4;
	temp->healMax[0] = 3;
	temp->healMax[1] = 3;
	temp->healMax[2] = 3;
	temp->healMax[3] = 4;
	temp->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Vestal_Heal_DivineComfort, temp));
#pragma endregion
}

CInfo_Skill* CDB_Skill::CallSkill(SKILL skill)
{
	return skillDB[skill];
}

Image* CDB_Skill::CallSkillImage(SKILL skill)
{
	return MG_IMAGE->findImage(skillDB[skill]->m_imgData);
}
