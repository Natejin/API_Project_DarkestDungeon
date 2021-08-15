#pragma once
#include "Info_Unit.h"


class Info_Hero: public Info_Unit
{
public:
	JOB job;
	
	int m_DMG; //skill에서 값 넣어주기
	int m_ACRY; //명중률
	int m_CRI;
	int m_DEF;
	int m_DODGE; //회피율

	int m_LVL; //stress에서 기인?
	int m_EXP;
	int m_STRS;

	vector<SKILL> ownSkill;
	IMAGE lTrinket;
	IMAGE rTrinket;

	vector<int> skillLvl;
	IMAGE portrait;
	vector<IMAGE> weapon;
	int weaponLvl;
	vector<IMAGE> armor;
	int armorLvl;


public:
	Info_Hero();
	~Info_Hero();

	virtual IMAGE GetArmor(int i);
	virtual IMAGE GetWeapon(int i);

	virtual class Image* GetTrinketL();
	virtual class Image* GetTrinketR();

	virtual void Release();
};

