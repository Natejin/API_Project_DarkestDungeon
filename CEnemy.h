#pragma once
#include "Unit.h"
#include "Info_Enemy.h"
class CEnemy : public Unit
{
private:

	//��ų
	//��ų Info�� accuracy, critical, DMG, changeAttribute �� ���Ե�
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

	HRESULT Init();

	HRESULT Init(string img, int resist[],
		int HP, int SPD, int POS,
		int DEF, int DODGE);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void SetMemberOverlay();


};