#pragma once
#include "CHero.h"

class Vestal : public CHero
{
private:


public:
	Vestal();
	~Vestal();




	void useSkill(int SkillNum, int enemyPos, int memberPos);
	void skill_MaceBash(int enemyPos); //근거리 공격
	void skill_Judgement(int enemyPos); //원거리 공격
	void skill_DivineGrace(int memberPos); //단일회복
	void skill_DivineComfort(int memberPos); //전체회복

};