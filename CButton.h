#pragma once
#include "GameObject.h"

class CButton : public GameObject
{
protected:
	//bool canTriggerClick; //ÀÇµµ
	//int countNum;
	//function<void()> m_triggerWhenOnceUp;
	//function<void()> m_triggerWhenOnceDown;
	//Rect m_rect;

	bool canTriggerUp;
	bool canTriggerDown;
	function<void()> m_triggerWhenUp;
	function<void()> m_triggerWhenDown;
	int countNum;
public:
	CButton();
	~CButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

	template <typename T>
	void SetTriggerWhenDown(T* pObj, void(T::* func)())
	{
		canTriggerDown = true;
		m_triggerWhenDown = bind(func, pObj);
	}

	template <typename T>
	void SetTriggerWhenUp(T* pObj, void(T::* func)())
	{

		canTriggerUp = true;
		m_triggerWhenUp = bind(func, pObj);
	}

};