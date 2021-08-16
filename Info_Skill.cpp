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

int CInfo_Skill::GetDamage(Info_Hero* info, Info_Enemy* info2)
{
	int acc = (accuracy[skillLevel] * MG_RND->getFromIntTo(1, 3));
	int doudge = info2->m_DODGE * MG_RND->getFromIntTo(1, 3);
	if (acc - doudge < 0)
	{
		return -1;
	}
	else {
		float cri = 1;
		return info->m_DMG * (100 + damage[skillLevel])/ 100.f * cri;
	}
}

int CInfo_Skill::GetDamage(Info_Enemy* info, Info_Hero* info2)
{
	int acc = (accuracy[skillLevel] * MG_RND->getFromIntTo(1, 3));
	int doudge = info2->m_DODGE * MG_RND->getFromIntTo(1, 3);
	if (acc - doudge < 0)
	{
		return -1;
	}
	else {
		float cri = 1;
		return info->m_DMG * (100 + damage[skillLevel]) / 100.f * cri;
	}
}

int CInfo_Skill::GetHeal()
{
	return MG_RND->getFromIntTo(healMin[skillLevel], healMax[skillLevel]);
}




void CInfo_Skill::Release()
{
}
