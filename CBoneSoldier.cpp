#include "framework.h"
#include "CBoneSoldier.h"

CBoneSoldier::CBoneSoldier()
{
	CBoneSoldier* boneSD = new CBoneSoldier;
	int resist[5] = { 25, 10, 200, 15, 20 };

	//DEF 15%
	/*boneSD->Init("mon2", resist, 10, 2, 3, 15, 0);*/
}
CBoneSoldier::~CBoneSoldier() {}

void CBoneSoldier::useSkill(int SkillNum, int enemyPos, int heroPos)
{
	switch (SkillNum)
	{
	case 1:
		skill_GraveyardSlash(heroPos);
		break;

	case 2:
		skill_GraveyardStumble(heroPos);
		break;
	}
}

void CBoneSoldier::skill_GraveyardSlash(int heroPos)
{
	//공격대상 ○●●●
	//위치 ●●●○
}

void CBoneSoldier::skill_GraveyardStumble(int heroPos)
{
	//공격대상 ○○●●
	//위치 ○○○●
}