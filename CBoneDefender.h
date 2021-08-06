#pragma once
#include "CEnemy.h"

class CBoneDefender : public CEnemy
{
private:

public:
	CBoneDefender();
	~CBoneDefender();

	HRESULT Init();


	void useSkill(int SkillNum, int enemyPos, int heroPos);
	void skill_DeadWeight(int heroPos);
	void skill_ClumsyAxeblade(int heroPos);

};