#pragma once
#include "CHero.h"

class Vestal : public CHero
{
private:


public:
	Vestal();
	~Vestal();




	void useSkill(int SkillNum, int enemyPos, int memberPos);
	void skill_MaceBash(int enemyPos); //�ٰŸ� ����
	void skill_Judgement(int enemyPos); //���Ÿ� ����
	void skill_DivineGrace(int memberPos); //����ȸ��
	void skill_DivineComfort(int memberPos); //��üȸ��

};