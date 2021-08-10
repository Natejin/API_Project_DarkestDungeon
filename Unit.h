#pragma once
#include "GameObject.h"

class Unit :public GameObject
{
public:
	int m_HP;
	int m_SPD;
	int m_POS; //(��Ƽ������ ��ġ)

	//����
	int resist[5]; //stun, blight, bleed, debuff, move
	//����
	bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;
	int m_partyIndex = -1;

public:
	Unit();
	~Unit();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	UNITTYPE GetUnitType() { return unitType; }
	int GetSpeed() { return m_SPD; }

	void SetPartyIndex(int index) { m_partyIndex = index; }
	int GetPartyIndex() { return m_partyIndex; }

	void SetPosition(int pos) { m_POS = pos; }
	int GetPosition() { return m_POS; }
	
	//==============================
	//int m_HP;
	//int m_SPD;
	//int m_POS; //(��Ƽ������ ��ġ)

	////����
	//int resist[5]; //stun, blight, bleed, debuff, move
	////����
	//bool attribute[8];

	int getHP() { return m_HP; }
	int getSPD() { return m_SPD; }
	int getPartyPos() { return m_POS; }
	//�迭�� ��ȯ�ϴ� �ٸ� ����� Ȯ���� �� ��
	int getResist() 
	{ 
		return resist[0], resist[1], resist[2], resist[3], resist[4];
	}
	bool getAttribute()
	{
		return attribute[0];
	}

	void setHP(int hp) { m_HP = hp; }
	void setSPD(int spd) { m_SPD = spd; }
	void setPartyPos(int pos) { m_POS = pos; }
	void setResist(int _resist[])
	{
		for (int i; i < 5; i++)
		{
			resist[i] = _resist[i];
		}
	}
	void setAttribute(int _attribute[])
	{
		for (int i = 0; i < 8; i++)
		{
			attribute[i] = _attribute[i];
		}
	}

};