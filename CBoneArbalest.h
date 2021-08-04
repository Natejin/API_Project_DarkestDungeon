#pragma once
#include "CEnemy.h"

class CBoneArbalest : public CEnemy
{
private:

public:
	CBoneArbalest();
	~CBoneArbalest();

	void useSkill(int SkillNum, int enemyPos, int heroPos);
	void skill_Qurrel(int heroPos);
	void skill_BayonetJab(int heroPos);

};