#pragma once
#include "CEst_UI.h"
#include <functional>
#include "CButton.h"
class Abbey :public CEst_UI
{

private:
	function<void()> m_triggerWhenClick;

public:
	Rect m_rect;

	Abbey();
	~Abbey();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	bool isUi;
	bool isUI;
	void Setquick();
	void FinishUI();
	//===================================

	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		m_triggerWhenClick = bind(func, pObj);
	}

};
