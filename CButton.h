#pragma once
#include "GameObject.h"

class CButton : public GameObject
{
protected:
	bool canTriggerClick;
	function<void()> m_triggerWhenUp;
	int countNum;
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
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		canTriggerClick = true;
		m_triggerWhenUp = bind(func, pObj);
	}

};