#pragma once
#include "Info.h"

class Info_Unit : public Info
{
public:
	int m_HP;
	int m_maxHP;
	int m_SPD;
	bool isAlive;
	bool isCorpse;
	bool isAffliction;

	int m_DMG; //skill에서 값 넣어주기


	int m_ACRY; //명중률
	int m_CRI;
	int m_DEF;
	int m_DODGE; //회피율
	

	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
	bool attribute[9] = { false }; 
	//int attributeDP[9] = { 0 };
	//none, stun, blight, bleed, debuff, buff, marked, death, Poison

	UNITTYPE unitType;

	IMAGE imageIdle;
	IMAGE imageCombat;
	IMAGE imageWalk;
	IMAGE imageInvestigate;
	IMAGE imageDefend;
	IMAGE imageAttack;
	IMAGE imageCharge;
	IMAGE imageBuff;
	IMAGE imageDebuff;
	IMAGE imageCorpse;

	IMAGE portrait;

	vector<int> skillLvl;
	vector<SKILL> ownSkill;
	vector<CAMP_SKILL> ownCamp_Skill;
	
	virtual void Release();
};

