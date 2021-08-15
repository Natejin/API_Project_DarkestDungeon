#include "framework.h"
#include "Info_Skill.h"

bool CInfo_Skill::CheckUseable(int pos)
{
	return allowUseSkillPos & (2 << pos) ? true : false;
}

//비트연산을 활용하여 위치값을 스킬타겟과 비교하기
bool CInfo_Skill::CheckTarget(int pos)
{
	return targetPos & (2 << pos) ? true : false;
}

void CInfo_Skill::Release()
{
}
