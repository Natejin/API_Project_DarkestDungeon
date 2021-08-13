#pragma once
#define MAXSKILLLVL 5
class CInfo_Skill
{
	
public:
	string m_name;
	string m_description;

	int m_ID;
	int skillLevel;
	//��Ʈ���꾲��!!
	//1���ڸ� = �Ǿ�
	//2���ڸ� = �ι�°
	//4�� �ڸ� = 3����
	//8�� �ڸ� = 4��°
	//�� 9 = 1001 : �Ǿհ� �ڰ� Ÿ�ٰ���
	int targetPos;
	int allowUseSkillPos;

	IMAGE m_imgData;
	SKILL m_skill;
	SKILLTARGET target;
	JOB job;
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
};

