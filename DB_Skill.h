#pragma once
#include "CSaveable.h"


class CInfo_Skill;
class CDB_Skill : public CSaveable<CDB_Skill>
{
private:
	map< SKILL, CInfo_Skill*> skillDB;
	int id;

public:
	CDB_Skill();
	~CDB_Skill();

	void Init();

	void SetHeroSkill();
	void SetEnemySkill();

	CInfo_Skill* CallSkill(SKILL skill);
	class Image* CallSkillImage(SKILL skill);
};