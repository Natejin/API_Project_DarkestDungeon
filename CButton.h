#pragma once
#include "GameObject.h"


class CButton : public GameObject
{
	function<void()> m_triggerWhenClick;
	int countNum;
	//function<void()> m_triggerWhenClick1;
public:
	Rect m_rect;

	CButton();
	~CButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void SetButtonSize(float width, float height);



	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		m_triggerWhenClick = bind(func, pObj);
	}

	//template <typename T>
	//void SetTriggerWhenClick1(T* pObj, void(T::* func)())
	//{
	//	m_triggerWhenClick1 = bind(func, pObj);
	//}
};