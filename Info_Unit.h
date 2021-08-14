#pragma once
class Info_Unit
{
public:
	int m_HP;
	int m_SPD;


	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
	bool attribute[8] = { false }; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;
	IMAGE imageIdle;
	IMAGE imageWalk;
	IMAGE imageCombat;
};

