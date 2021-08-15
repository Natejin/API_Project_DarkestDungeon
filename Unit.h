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

	virtual void SetPartyIndex(int index) { m_partyIndex = index; }
	virtual int GetPartyIndex() { return m_partyIndex; }

	void showSelMember(HDC _hdc);
	void showHpBar(HDC _hdc);


//GetStatus;
	virtual UNITTYPE GetUnitType();
	virtual int GetSpeed();
	virtual void SetPosition(int pos);
	virtual int getHP();
	virtual int getSPD();
	virtual int GetPosition();
	virtual int getPartyPos();
	virtual int getResist(int index);
	virtual bool getAttribute(int index);
	virtual void setHP(int hp);
	virtual void setSPD(int spd);
	virtual void setPartyPos(int pos);
	virtual void setResist(int index, bool val);
	virtual void setAttribute(int index, bool val);
	virtual void SetMemberOverlay();

};