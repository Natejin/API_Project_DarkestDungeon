#pragma once
#include "GameObject.h"
#include "Info_Unit.h"

class Unit :public GameObject
{
public:
	int m_partyPos = - 1;
	int m_partyIndex = -1;
	bool isSelected;

	ImageData HPbar_front;
	ImageData HPbar_back;
	
	ImageData selectedMem;


	Vector2 targetPos;
	bool movePosMode;
	float movePosSpeed;

protected:
	function<void(int i)> m_triggerWhenDown;
	bool canTriggerDown;
	UNITTYPE m_unitType;
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

	//virtual void SetPartyIndex(int index) { m_partyIndex = index; }
	//inline int Unit::GetPartyPos()
	//{
	//	return m_partyPos;
	//}
	//inline void Unit::SetPartyPos(int pos)
	//{
	//	m_partyPos = pos;
	//}
	//virtual int GetPartyIndex() { return m_partyIndex; }

	void showSelMember(HDC _hdc);
	void showHpBar(HDC _hdc);


//GetStatus;
	virtual UNITTYPE GetUnitType();

	virtual int getHP();
	virtual bool reduceHP(int hp);
	virtual void increaseHP(int hp);
	virtual void setHP(int hp);
	virtual int getMaxHP();

	virtual bool GetAffliction();
	virtual bool GetAlive();

	virtual int GetSpeed();

	virtual int getSPD();



	virtual int GetPartyIndex();
	virtual void SetPartyIndex(int pos);

	virtual int GetPartyPos();
	virtual void SetPartyPos(int pos);



	virtual int getResist(int index);
	virtual bool getAttribute(int index);
	virtual void setSPD(int spd);
	virtual void setResist(int index, bool val);
	virtual void setAttribute(int index, bool val);
	virtual void SetMemberOverlay();

};