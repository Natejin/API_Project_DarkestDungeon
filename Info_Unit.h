#pragma once
class Info_Unit
{
public:
	int m_HP;
	int m_SPD;


	//����
	int resist[5]; //stun, blight, bleed, debuff, move
	//����
	bool attribute[8] = { false }; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;
	IMAGE imageIdle;
	IMAGE imageWalk;
	IMAGE imageCombat;
};

