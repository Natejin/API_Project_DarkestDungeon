#pragma once
#include"GameObject.h"

class CDragButtion : public GameObject
{

protected:
	function<void()> m_triggerWhenClick;
	int countNum;

public:
	Rect m_rect;

	CDragButtion();
	~CDragButtion();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

	void SetButtonSize(float width, float height);

	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		m_triggerWhenClick = bind(func, pObj);
	}

};