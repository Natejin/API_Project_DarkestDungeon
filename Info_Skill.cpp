#include "framework.h"
#include "Info_Skill.h"

bool CInfo_Skill::CheckUseable(int pos)
{
	return allowUseSkillPos & (2 << pos) ? true : false;
}

//��Ʈ������ Ȱ���Ͽ� ��ġ���� ��ųŸ�ٰ� ���ϱ�
bool CInfo_Skill::CheckTarget(int pos)
{
	return targetPos & (2 << pos) ? true : false;
}

void CInfo_Skill::Release()
{
}
