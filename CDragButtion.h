#pragma once
#include "CButton.h"
class CDragButton : public CButton
{
protected:
	Vector2 buttonSize;
	function<void()> m_triggerWhenDrag;

	bool canTriggerDrag;

public:
	CDragButton();
	~CDragButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

	void SetButtonSize(float width, float height);
	void Mouse_icon_Move();

	template <typename T>
	void SetTriggerWhenDrag(T* pObj, void(T::* func)())
	{
		canTriggerDrag = true;
		m_triggerWhenDrag = bind(func, pObj);
	}
};