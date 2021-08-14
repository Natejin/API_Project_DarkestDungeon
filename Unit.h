#pragma once
#include "GameObject.h"

class Unit :public GameObject
{
public:
	int m_HP;
	int m_SPD;
	int m_POS; //(파티에서의 위치)

	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
	bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;
	int m_partyIndex = -1;
	bool isSelected;

	ImageData HPbar_front;
	ImageData HPbar_back;
	ImageData selectedMem;

protected:
	function<void(int i)> m_triggerWhenDown;
	bool canTriggerDown;

public:
	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)(int i))
	{
		canTriggerDown = true;
		//int index = i;
		m_triggerWhenDown = bind(func, pObj, std::placeholders::_1);
	}
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

	int getHP() { return m_HP; }
	int getSPD() { return m_SPD; }
	int getPartyPos() { return m_POS; }

	int getResist(int index) 
	{ 
		return resist[index];
	}
	bool getAttribute(int index)
	{
		return attribute[index];
	}

	void setHP(int hp) { m_HP = hp; }
	void setSPD(int spd) { m_SPD = spd; }
	void setPartyPos(int pos) { m_POS = pos; }

	void setResist(int index, bool val)
	{
		resist[index] = val;
	}
	void setAttribute(int index, bool val)
	{
		attribute[index] = val;
	}

};