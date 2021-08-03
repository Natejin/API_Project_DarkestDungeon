#include "framework.h"
#include "CVestal.h"

Vestal::Vestal()
{
	//이부분 내용은 createvestal로 옮김

}
Vestal::~Vestal(){}

void Vestal::useSkill(int SkillNum, int enemyPos, int memberPos)
{
	switch (SkillNum)
	{
	case 1:
		skill_MaceBash(enemyPos);
		break;

	case 2:
		skill_Judgement(enemyPos);
		break;

	case 3:
		skill_DivineGrace(memberPos);
		break;

	case 4:
		skill_DivineComfort(memberPos);
		break;
	}
}

void Vestal::skill_MaceBash(int enemyPos)
{

}

void Vestal::skill_Judgement(int enemyPos)
{

}

void Vestal::skill_DivineGrace(int memberPos)
{

}

void Vestal::skill_DivineComfort(int memberPos)
{

}
