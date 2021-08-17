#pragma once
#include "Info_Unit.h"


class Info_Hero: public Info_Unit
{
public:
	JOB job;


	int m_LVL; //stress에서 기인?
	int m_EXP;
	int m_STRS;


	IMAGE lTrinket;
	IMAGE rTrinket;


	vector<IMAGE> weapon;
	int weaponLvl;
	vector<IMAGE> armor;
	int armorLvl;
	vector<IMAGE>Camping_Skill;

public:
	Info_Hero();
	~Info_Hero();

	virtual IMAGE GetArmor(int i);
	virtual IMAGE GetWeapon(int i);

	virtual class Image* GetTrinketL();
	virtual class Image* GetTrinketR();

	virtual void Release();
};

