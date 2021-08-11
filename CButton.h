#pragma once
#include "GameObject.h"

class CButton : public GameObject
{
protected:


	function<void()> m_triggerWhenUp;
	function<void()> m_triggerWhenDown;
	int countNum;
	Rect m_rect;

	bool canTriggerUp;
	bool canTriggerDown;

public:
	static bool clickable;
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
	void SetTriggerWhenUp(T* pObj, void(T::* func)())
	{
		canTriggerUp = true;
		m_triggerWhenUp = bind(func, pObj);
	}
	template <typename T>
	void SetTriggerWhenDown(T* pObj, void(T::* func)())
	{
		canTriggerDown = true;
		m_triggerWhenDown = bind(func, pObj);
	}
};