#pragma once
class Info_Unit
{
	int m_HP;
	int m_SPD;
	int m_POS; //(��Ƽ������ ��ġ)

	//����
	int resist[5]; //stun, blight, bleed, debuff, move
	//����
	bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;

};

