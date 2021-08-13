#pragma once
#include "CSaveable.h"
#include "Info_Skill.h"

class CDB_Skill : public CSaveable<CDB_Skill>
{
private:
	map< SKILL, CInfo_Skill*> skillDB;
	int id;

public:
	CDB_Skill();
	~CDB_Skill();

	void Init();

	CInfo_Skill* CallSkill(SKILL skill);
};