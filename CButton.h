#pragma once
#include "GameObject.h"

class CButton : public GameObject
{
protected:
	bool canTriggerClick; //ÀÇµµ
	int countNum;
	function<void()> m_triggerWhenOnceUp;
	function<void()> m_triggerWhenOnceDown;
	Rect m_rect;

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

	void SetButtonSize(float width, float height);
	void SetButtonSize();

	template <typename T>
	void SetTriggerWhenOnceDown(T* pObj, void(T::* func)())
	{
		canTriggerClick = true;
		m_triggerWhenOnceUp = bind(func, pObj);
	}

	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		canTriggerClick = true;
		m_triggerWhenOnceDown = bind(func, pObj);
	}

};