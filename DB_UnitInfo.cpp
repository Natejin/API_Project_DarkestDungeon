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
	info->name = _info->name;
	info->unitType = _info->unitType;
	info->m_maxHP = _info->m_maxHP;
	info->m_HP = _info->m_maxHP;
	info->m_SPD = _info->m_SPD;
	info->isAlive = _info->isAlive;
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
	info->imageInvestigate = _info->imageInvestigate;
	info->imageDefend = _info->imageDefend;
	info->imageAttack = _info->imageAttack;
	info->imageCharge = _info->imageCharge;
	info->imageBuff = _info->imageBuff;
	info->imageDebuff = _info->imageDebuff;
	info->imageCorpse = _info->imageCorpse;


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
	for (size_t i = 0; i < _info->ownCamp_Skill.size(); i++)
	{
		info->ownCamp_Skill.push_back(_info->ownCamp_Skill[i]);
	}
	MG_INFO->RegisterInfo(info);
	return info;
}

Info_Enemy* DB_UnitInfo::CallEnemy(ENEMYTYPE enemyType)
{
	auto _info = enemyDB[enemyType];
	auto info = new Info_Enemy();
	info->name = _info->name;
	info->unitType = _info->unitType;
	info->m_maxHP = _info->m_maxHP;
	info->m_HP = _info->m_maxHP;
	info->m_SPD = _info->m_SPD;
	info->isAlive = _info->isAlive;
	info->isCorpse = _info->isCorpse;
	MG_INFO->RegisterInfo(info);







	for (size_t i = 0; i < 5; i++)
	{
		info->resist[i] = _info->resist[i];
	}
	for (size_t i = 0; i < 8; i++)
	{
		info->attribute[i] = false;
	}

	//hero
	info->enemyType = _info->enemyType;
	info->m_DMG = _info->m_DMG;
	info->m_ACRY = _info->m_ACRY;
	info->m_CRI = _info->m_CRI;
	info->m_DEF = _info->m_DEF;
	info->m_DODGE = _info->m_DODGE;
	//info->ownSkill = _info->ownSkill;

	info->imageIdle = _info->imageIdle;
	info->imageWalk = _info->imageWalk;
	info->imageCombat = _info->imageCombat;
	info->imageInvestigate = _info->imageInvestigate;
	info->imageDefend = _info->imageDefend;
	info->imageAttack = _info->imageAttack;
	info->imageCharge = _info->imageCharge;
	info->imageBuff = _info->imageBuff;
	info->imageDebuff = _info->imageDebuff;
	info->imageCorpse = _info->imageCorpse;



	info->portrait = _info->portrait;
	for (size_t i = 0; i < _info->ownSkill.size(); i++)
	{
		info->ownSkill.push_back(_info->ownSkill[i]);
	}
	MG_INFO->RegisterInfo(info);
	return info;
}

void DB_UnitInfo::SetHero()
{
	Info_Hero* info = new Info_Hero();
	info->name = "(감)성전사";
	info->unitType = UNITTYPE::Hero;
	info->m_maxHP = 33;
	info->m_SPD = 1;
	info->isAffliction = false;
	info->isAlive = true;
	info->job = JOB::Crusader;
	info->m_DMG = 20;
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
	info->imageAttack = IMAGE::Crusader_sword;
	info->imageCharge = IMAGE::Crusader_charge;
	info->imageInvestigate = IMAGE::Crusader_investigate;
	info->imageDefend = IMAGE::Crusader_defend;
	info->imageBuff = IMAGE::Crusader_banner;
	info->imageDebuff = IMAGE::Crusader_scroll;

	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Crusader_Combat_Smite);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Crusader_Combat_ZealousAccusation);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Crusader_Combat_StunningBlow);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Crusader_Heal_BattleHeal);
	info->skillLvl.push_back(0);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_bandage);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_encourage);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_pep_talk);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_stand_tall);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_unshakeable_leader);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_zealous_speech);
	info->ownCamp_Skill.push_back(IMAGE::camp_skill_zealous_vigil);

	info->portrait = IMAGE::Crusader_portrait;
	info->weapon.push_back( IMAGE::Crusader_Weapon_0);
	info->armor.push_back( IMAGE::Crusader_Armor_0);
	heroDB.insert(make_pair(info->job, info));
	MG_INFO->RegisterInfo(info);

	info = new Info_Hero();
	info->name = "다키한 성녀";
	info->unitType = UNITTYPE::Hero;
	info->m_maxHP = 22;
	info->m_SPD = 4;
	info->isAffliction = false;
	info->isAlive = true;

	info->job = JOB::Vestal;
	info->m_DMG = 50;
	info->m_ACRY = 4;
	info->m_CRI = 2;
	info->m_DEF = 5;
	info->m_DODGE = 2;
	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;

	info->imageIdle = IMAGE::Vestal_Idle;
	info->imageCombat = IMAGE::Vestal_Combat;
	info->imageWalk = IMAGE::Vestal_Walk;
	info->imageAttack = IMAGE::Vestal_mace;
	info->imageCharge = IMAGE::Vestal_miracle;
	info->imageInvestigate = IMAGE::Vestal_investigate;
	info->imageDefend = IMAGE::Vestal_defend;
	info->imageBuff = IMAGE::Vestal_heal;
	info->imageDebuff = IMAGE::Vestal_lectionary;

	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Vestal_Combat_MaceBash);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Vestal_Combat_Judgement);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Vestal_Combat_DazzlingLight);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);
	info->skillLvl.push_back(0);
	info->Camping_Skill.push_back(IMAGE::camp_skill_bandage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_encourage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_pep_talk);
	info->Camping_Skill.push_back(IMAGE::camp_skill_bless);
	info->Camping_Skill.push_back(IMAGE::camp_skill_chant);
	info->Camping_Skill.push_back(IMAGE::camp_skill_pray);
	info->Camping_Skill.push_back(IMAGE::camp_skill_sanctuary);

//	info->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);

	info->portrait = IMAGE::Vestal_portrait;
	info->weapon.push_back(IMAGE::Vestal_Weapon_0);
	info->armor.push_back(IMAGE::Vestal_Armor_0);
	heroDB.insert(make_pair(info->job, info));
	MG_INFO->RegisterInfo(info);

	//plague_doctor
	info = new Info_Hero();
	info->name = "킹갓 역병 술사";
	info->unitType = UNITTYPE::Hero;
	info->m_maxHP = 23;
	info->m_SPD = 4;
	info->isAffliction = false;
	info->isAlive = true;
	info->job = JOB::PlagueDoctor;
	info->m_DMG = 1;
	info->m_ACRY = 8;
	info->m_CRI = 0;
	info->m_DEF = 4;
	info->m_DODGE = 2;
	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;

	info->imageIdle = IMAGE::Plague_Idle;
	info->imageCombat = IMAGE::Plague_Combat;
	info->imageWalk = IMAGE::Plague_Walk;
	info->imageAttack = IMAGE::Plague_doctor_dagger;
	info->imageCharge = IMAGE::Plague_doctor_grenade;
	info->imageInvestigate = IMAGE::Plague_doctor_investigate;
	info->imageDefend = IMAGE::Plague_doctor_defend;
	info->imageBuff = IMAGE::Plague_doctor_buff;
	info->imageDebuff = IMAGE::Plague_doctor_defend;
	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Plague_doctor_BattleFiled_Medicine);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Plague_doctor_Incision);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Plague_doctor_NoxiousBlast);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Plague_doctor_PlagueGrenade);
	info->skillLvl.push_back(0);
	info->Camping_Skill.push_back(IMAGE::camp_skill_bandage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_encourage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_pep_talk);
	info->Camping_Skill.push_back(IMAGE::camp_skill_experimental_vapours);
	info->Camping_Skill.push_back(IMAGE::camp_skill_leeches);
	info->Camping_Skill.push_back(IMAGE::camp_skill_preventative_medicine);
	info->Camping_Skill.push_back(IMAGE::camp_skill_self_medicate);

	info->portrait = IMAGE::plague_doctor_roster;
	info->weapon.push_back(IMAGE::Plague_Weapon_0);
	info->armor.push_back(IMAGE::Plague_Armor_0);
	heroDB.insert(make_pair(info->job, info));
	MG_INFO->RegisterInfo(info);
	//Highwayman
	info = new Info_Hero();
	info->name = "모래반지 빵야";
	info->unitType = UNITTYPE::Hero;
	info->m_maxHP = 24;
	info->m_SPD = 7;
	info->isAffliction = false;
	info->isAlive = true;
	info->job = JOB::Highwayman;
	info->m_DMG = 8;
	info->m_ACRY = 8;
	info->m_CRI = 2;
	info->m_DEF = 2;
	info->m_DODGE = 4;
	info->m_LVL = 1;
	info->m_EXP = 0;
	info->m_STRS = 0;

	info->imageIdle = IMAGE::Highwayman_Idle;
	info->imageCombat = IMAGE::Highwayman_Combat;
	info->imageWalk = IMAGE::Highwayman_Walk;
	info->imageAttack = IMAGE::Highwayman_slice;
	info->imageCharge = IMAGE::Highwayman_lunge;
	info->imageInvestigate = IMAGE::Highwayman_investigate;
	info->imageDefend = IMAGE::Highwayman_defend;
	info->imageBuff = IMAGE::Highwayman_pistol;
	info->imageDebuff = IMAGE::Highwayman_defend;
	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::Highwayman_Duelists_Advance);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Highwayman_GrapeshotBlast);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Highwayman_OpenVein);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Highwayman_PointBlankShot);
	info->skillLvl.push_back(0);
	info->Camping_Skill.push_back(IMAGE::camp_skill_bandage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_encourage);
	info->Camping_Skill.push_back(IMAGE::camp_skill_pep_talk);
	info->Camping_Skill.push_back(IMAGE::camp_skill_clean_guns);
	info->Camping_Skill.push_back(IMAGE::camp_skill_gallows_humor);
	info->Camping_Skill.push_back(IMAGE::camp_skill_perimeter_alarms);
	info->Camping_Skill.push_back(IMAGE::camp_skill_uncatchable);

	info->portrait = IMAGE::highwayman_roster;
	info->weapon.push_back(IMAGE::Highway_Weapon_0);
	info->armor.push_back(IMAGE::Highway_Armor_0);
	heroDB.insert(make_pair(info->job, info));
	MG_INFO->RegisterInfo(info);

}

void DB_UnitInfo::SetEnemy()
{
	Info_Enemy* info = new Info_Enemy();
	info->unitType = UNITTYPE::Enemy;
	info->m_maxHP = 20;
	info->m_SPD = 3;
	info->isAffliction = false;
	info->isAlive = true;

	info->enemyType = ENEMYTYPE::BoneDefender;
	info->m_DMG = 3;
	info->m_ACRY = 9;
	info->m_CRI = 0;
	info->m_DEF = 3;
	info->m_DODGE = 0;

	info->imageIdle = IMAGE::Enemy_SkeletonDefender_Idle;
	info->imageCombat = IMAGE::Enemy_SkeletonDefender_Idle;
	info->imageWalk = IMAGE::Enemy_SkeletonDefender_Idle;
	info->imageAttack = IMAGE::Enemy_SkeletonDefender_Attack;
	info->imageCharge = IMAGE::Enemy_SkeletonDefender_Attack;
	info->imageDefend = IMAGE::Enemy_SkeletonDefender_Defender;
	info->imageBuff = IMAGE::Enemy_SkeletonDefender_Shield;
	info->imageDebuff = IMAGE::Enemy_SkeletonDefender_Shield;
	info->imageCorpse = IMAGE::skeleton_defender_dead;

	info->resist[0] = 40;
	info->resist[1] = 30;
	info->resist[2] = 30;
	info->resist[3] = 30;
	info->resist[4] = 40;
	info->ownSkill.push_back(SKILL::BoneDefender_Combat_1);
	info->skillLvl.push_back(0);
	info->portrait = IMAGE::Crusader_portrait;
	enemyDB.insert(make_pair(info->enemyType, info));
	MG_INFO->RegisterInfo(info);

	//common
	info = new Info_Enemy();
	info->unitType = UNITTYPE::Enemy;
	info->m_maxHP = 10;
	info->m_SPD = 2;
	info->isAffliction = false;
	info->isAlive = true;

	info->enemyType = ENEMYTYPE::BoneCommon;
	info->m_DMG = 3;
	info->m_ACRY = 9;
	info->m_CRI = 0;
	info->m_DEF = 3;
	info->m_DODGE = 0;

	info->imageIdle = IMAGE::skeleton_common_combat;
	info->imageCombat = IMAGE::skeleton_common_combat;
	info->imageWalk = IMAGE::skeleton_common_combat;
	info->imageAttack = IMAGE::skeleton_common_attack;
	info->imageCharge = IMAGE::skeleton_common_attack;
	info->imageDefend = IMAGE::skeleton_common_defend;
	info->imageBuff = IMAGE::skeleton_common_defend;
	info->imageDebuff = IMAGE::skeleton_common_defend;
	info->imageCorpse = IMAGE::skeleton_common_dead;
	//stun, blight, bleed, debuff, move
	info->resist[0] = 25;
	info->resist[1] = 10;
	info->resist[2] = 200;
	info->resist[3] = 15;
	info->resist[4] = 20;
	info->ownSkill.push_back(SKILL::BoneCommon_Combat_1);
	info->skillLvl.push_back(0);
	info->portrait = IMAGE::Crusader_portrait;
	enemyDB.insert(make_pair(info->enemyType, info));
	MG_INFO->RegisterInfo(info);

	//Courtier
	info = new Info_Enemy();
	info->unitType = UNITTYPE::Enemy;
	info->m_maxHP = 10;
	info->m_SPD = 8;
	info->isAffliction = false;
	info->isAlive = true;

	info->enemyType = ENEMYTYPE::BoneCourtier;
	info->m_DMG = 1;
	info->m_ACRY = 9;
	info->m_CRI = 0;
	info->m_DEF = 2;
	info->m_DODGE = 0;

	info->imageIdle = IMAGE::skeleton_courtier_combat;
	info->imageCombat = IMAGE::skeleton_courtier_combat;
	info->imageWalk = IMAGE::skeleton_courtier_combat;
	info->imageAttack = IMAGE::skeleton_courtier_attack;
	info->imageCharge = IMAGE::skeleton_courtier_attack_goblet;
	info->imageDefend = IMAGE::skeleton_courtier_defend;
	info->imageBuff = IMAGE::skeleton_courtier_defend;
	info->imageDebuff = IMAGE::skeleton_courtier_defend;
	info->imageCorpse = IMAGE::skeleton_courtier_dead;
	//stun, blight, bleed, debuff, move
	info->resist[0] = 10;
	info->resist[1] = 10;
	info->resist[2] = 200;
	info->resist[3] = 15;
	info->resist[4] = 10;
	info->ownSkill.push_back(SKILL::BoneCourtier_Combat_1);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::BoneCourtier_Combat_2_goblet);
	info->skillLvl.push_back(0);
	info->portrait = IMAGE::Crusader_portrait;
	enemyDB.insert(make_pair(info->enemyType, info));
	MG_INFO->RegisterInfo(info);

	//Necromancer
	info = new Info_Enemy();
	info->unitType = UNITTYPE::Enemy;
	info->m_maxHP = 105;
	info->m_SPD = 8;
	info->isAffliction = false;
	info->isAlive = true;

	info->enemyType = ENEMYTYPE::Necromancer;
	info->m_DMG = 5;
	info->m_ACRY = 9;
	info->m_CRI = 0;
	info->m_DEF = 2;
	info->m_DODGE = 0;

	info->imageIdle = IMAGE::necromancer_combat;
	info->imageCombat = IMAGE::necromancer_combat;
	info->imageWalk = IMAGE::necromancer_combat;
	info->imageAttack = IMAGE::necromancer_attack;
	info->imageCharge = IMAGE::necromancer_retreat;
	info->imageDefend = IMAGE::necromancer_defend;
	info->imageBuff = IMAGE::necromancer_defend;
	info->imageDebuff = IMAGE::necromancer_defend;
	info->imageCorpse = IMAGE::NONE;
	//stun, blight, bleed, debuff, move
	info->resist[0] = 75;
	info->resist[1] = 20;
	info->resist[2] = 20;
	info->resist[3] = 40;
	info->resist[4] = 25;
	info->ownSkill.push_back(SKILL::Necromancer_Combat_1);
	info->skillLvl.push_back(0);
	info->ownSkill.push_back(SKILL::Necromancer_Combat_2_back);
	info->skillLvl.push_back(0);
	info->portrait = IMAGE::Crusader_portrait;
	enemyDB.insert(make_pair(info->enemyType, info));
	MG_INFO->RegisterInfo(info);

}



void DB_UnitInfo::Save()
{

}

void DB_UnitInfo::Load()
{

}
