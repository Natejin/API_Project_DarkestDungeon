#pragma once
#include "CEnemy.h"

class CBoneSoldier : public CEnemy
{
private:

public:
	CBoneSoldier();
	~CBoneSoldier();

	void useSkill(int SkillNum, int enemyPos, int heroPos);
	void skill_GraveyardSlash(int heroPos);
	void skill_GraveyardStumble(int heroPos);

};