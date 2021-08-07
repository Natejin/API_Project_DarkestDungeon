#pragma once
#include "GameObject.h"

class Unit :public GameObject
{
public:
	int m_HP;
	int m_SPD;
	int m_POS; //(파티에서의 위치)
	int Skill[4]; //1, 2, 3, 4

	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
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
	
};