#include "framework.h"
#include "CBoneCourtier.h"

CBoneCourtier::CBoneCourtier()
{
	CBoneCourtier* boneCT = new CBoneCourtier;
	int resist[5] = {10, 10, 200, 15, 10};

	//DODGE 12.5%
	//boneCT->Init("mon3", resist, 10, 8, 2, 0, 12);
}
CBoneCourtier::~CBoneCourtier() {}

void CBoneCourtier::useSkill(int SkillNum, int enemyPos, int heroPos)
{
	switch (SkillNum)
	{
	case 1:
		skill_TemptingGoblet(heroPos);
		break;

	case 2:
		skill_KnifeInTheDark(heroPos);
		break;
	}
}

void CBoneCourtier::skill_TemptingGoblet(int heroPos)
{
	//공격 대상 ●●●●
	//위치 ○●●●
}

void CBoneCourtier::skill_KnifeInTheDark(int heroPos)
{
	//공격 대상 ○○●●
	//위치 ●●○○
}
