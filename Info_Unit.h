#pragma once
class Info_Unit
{
	int m_HP;
	int m_SPD;
	int m_POS; //(파티에서의 위치)

	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
	bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;

};

