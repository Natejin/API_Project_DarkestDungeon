#pragma once
#include "Info_Unit.h"

class Info_Hero: public Info_Unit
{
public:


	JOB job;
	int ownIndex;

	int m_DMG; //skill���� �� �־��ֱ�
	int m_ACRY; //���߷�
	int m_CRI;
	int m_DEF;
	int m_DODGE; //ȸ����

	int m_LVL; //stress���� ����?
	int m_EXP;
	int m_STRS;
	int m_STRSLVL; //��Ʈ������ ����

	int m_DIST; //�̵��� �Ÿ�
	int m_DIST_retreat; //������ �Ÿ�

	vector<SKILL> ownSkill;
};

