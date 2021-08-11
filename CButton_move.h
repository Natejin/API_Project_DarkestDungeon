#pragma once
#include "GameObject.h"
#include <functional>

class CButton_move : public GameObject
{
private:
	function<void()> m_triggerWhenClick;
	int countNum;

public:
	Rect m_rect;

	CButton_move();
	~CButton_move();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//===================================

	void SetButtonSize(float width, float height);

	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		m_triggerWhenClick = bind(func, pObj);
	}

};