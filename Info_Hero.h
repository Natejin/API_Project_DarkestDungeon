#pragma once
#include "Info_Unit.h"

class Info_Hero: public Info_Unit
{
public:


	JOB job;
	int ownIndex;

	int m_DMG; //skill에서 값 넣어주기
	int m_ACRY; //명중률
	int m_CRI;
	int m_DEF;
	int m_DODGE; //회피율

	int m_LVL; //stress에서 기인?
	int m_EXP;
	int m_STRS;
	int m_STRSLVL; //스트레스의 정도

	int m_DIST; //이동한 거리
	int m_DIST_retreat; //후퇴한 거리

	vector<SKILL> ownSkill;
};

