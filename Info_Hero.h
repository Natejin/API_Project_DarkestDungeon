#pragma once
#include "Info_Unit.h"

class Info_Hero: public Info_Unit
{
public:


	JOB job;
	
	int m_DMG; //skill���� �� �־��ֱ�
	int m_ACRY; //���߷�
	int m_CRI;
	int m_DEF;
	int m_DODGE; //ȸ����

	int m_LVL; //stress���� ����?
	int m_EXP;
	int m_STRS;

	vector<SKILL> ownSkill;
};

