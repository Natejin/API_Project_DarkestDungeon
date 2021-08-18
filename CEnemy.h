#pragma once
#include "Unit.h"
#include "Info_Enemy.h"
class CEnemy : public Unit
{
private:

	//스킬
	//스킬 Info에 accuracy, critical, DMG, changeAttribute 가 포함됨
	Info_Enemy* info;


	ImageData targetSkillMem; //appear when some member using healSkill



	function<void(int i)> m_triggerWhenStay;
	bool canTriggerStay;
public:
	template <typename T>
	void SetTriggerWhenStay(T* pObj, void(T::* func)(int i))
	{
		canTriggerStay = true;
		//int index = i;
		m_triggerWhenStay = bind(func, pObj, std::placeholders::_1);
	}
public:
	
	bool isTargetSkill;

	CEnemy();
	~CEnemy();

	//HRESULT Init();
	HRESULT Init(Info_Enemy* _info);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void SetMemberOverlay();
	virtual UNITTYPE GetUnitType();

	virtual Info_Enemy* GetInfo();
	virtual int getHP();
	virtual bool reduceHP(int hp);
	virtual void increaseHP(int hp);
	virtual void setHP(int hp);
	virtual int getMaxHP();

	virtual int getSPD();
	virtual void setSPD(int spd);

	virtual bool GetAlive();
	virtual bool GetCorpse();
	virtual bool SetCorpse(bool _corpse);

	virtual int GetAcry()const;
	virtual int GetCri()const;
	virtual int GetDmg()const;
	virtual int GetDodge()const;
	virtual int GetDef()const;

	virtual void GetProt()const;

};