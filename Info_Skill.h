#pragma once
#define MAXSKILLLVL 5
class CInfo_Skill : public Info
{
	
public:
	string m_name;
	string m_description;

	int m_ID;
	int skillLevel;
	//비트연산쓰기!!
	//1의자리 = 맨앞
	//2의자리 = 두번째
	//4의 자리 = 3번쨰
	//8의 자리 = 4번째
	//예 9 = 1001 : 맨앞과 뒤가 타겟가능
	int targetPos;
	int allowUseSkillPos;

	IMAGE m_skillIcon;
	IMAGE m_skillMotion;
	SKILL m_skill;
	SKILLIMAGETYPE m_skillImageType;
	SKILLTARGET target;
	JOB job;
	ENEMYTYPE enemyType;
	EFFECTTYPE effect = EFFECTTYPE::NONE;
public:
	float damage[5] = {0};
	int accuracy[5] = { 0 };
	int healMin[5] = { 0 };
	int healMax[5] = { 0 };
	float critMod[5] = { 0 };
	int effectVal[5] = { 0 };

public:
	CInfo_Skill() {};
	~CInfo_Skill() {};

	bool CheckUseable(int pos);
	bool CheckTarget(int pos);

	virtual void Release();
};

