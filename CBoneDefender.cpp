#include "framework.h"
#include "CBoneDefender.h"


CBoneDefender::CBoneDefender()
{
	//CBoneDefender* boneDF = new CBoneDefender;
	//int resist[5] = {25, 10, 200, 15, 50};
	
	//DEF 25%
	//boneDF->Init("mon1", resist, 15, 0, 1, 25, 0);
}

CBoneDefender::~CBoneDefender()
{
}

HRESULT CBoneDefender::Init()
{
	CEnemy::Init();
	//m_image = MG_IMAGE->findImage(IMAGE::Skeleton_Defender);


	m_animator->AddImageFrame(IMAGE::Skeleton_Defender);
	AddColliderBox();
	return S_OK;
}

void CBoneDefender::useSkill(int SkillNum, int enemyPos, int heroPos)
{
	switch (SkillNum)
	{
	case 1:
		skill_DeadWeight(heroPos);
		break;

	case 2:
		skill_ClumsyAxeblade(heroPos);
		break;
	}
}

void CBoneDefender::skill_DeadWeight(int heroPos)
{
	//공격대상 ○○●●
	//위치 ●●○○
}

void CBoneDefender::skill_ClumsyAxeblade(int heroPos)
{
	//공격대상 ○○●●
	//위치 ○○●●
}
