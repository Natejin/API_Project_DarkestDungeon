#pragma once
#include "CEnemy.h"

class CBoneCourtier : public CEnemy
{
private:

public:
	CBoneCourtier();
	~CBoneCourtier();

	void useSkill(int SkillNum, int enemyPos, int heroPos);
	void skill_TemptingGoblet(int heroPos);
	void skill_KnifeInTheDark(int heroPos);
};