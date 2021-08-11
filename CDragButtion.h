#pragma once
#include "CButton.h"
class CDragButton : public CButton
{
protected:
	Vector2 buttonSize;
	function<void()> m_triggerWhenDrag;

	bool canTriggerDrag;
	

public:
	static CDragButton* selDragButton;
	static int selKeyIndex;

	CDragButton();
	~CDragButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================


	void Mouse_Move();


	template <typename T>
	void SetTriggerWhenDrag(T* pObj, void(T::* func)())
	{
		canTriggerDrag = true;
		m_triggerWhenDrag = bind(func, pObj);
	}

	bool CanTriggerDrag() {	return canTriggerDrag;}
	void TriggerWhenDrag() { m_triggerWhenDrag(); }
};

