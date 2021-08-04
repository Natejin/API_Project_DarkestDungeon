#include "framework.h"
#include "CBoneArbalest.h"

CBoneArbalest::CBoneArbalest()
{
	CBoneArbalest* boneAB = new CBoneArbalest;
	int resist[5] = { 10, 10, 200, 15, 25 };

	//DEF 5%
	boneAB->Init("mon4", resist, 16, 5, 4, 0, 5);
}
CBoneArbalest::~CBoneArbalest() {}

void CBoneArbalest::useSkill(int SkillNum, int enemyPos, int heroPos)
{
	switch (SkillNum)
	{
	case 1:
		skill_Qurrel(heroPos);
		break;
		
	case 2:
		skill_BayonetJab(heroPos);
		break;
	}
}

void CBoneArbalest::skill_Qurrel(int heroPos)
{
	//공격 대상 ●●●○
	//위치 ○○●●
}

void CBoneArbalest::skill_BayonetJab(int heroPos)
{	
	//공격 대상 ○○●●
	//위치 ●●○○
}
