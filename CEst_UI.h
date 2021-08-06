#pragma once
#include "GameObject.h"
class CEst_UI :public GameObject
{
private:
	function<void()> m_triggerWhenClick;

public:
	Rect m_rect;

	CEst_UI();
	~CEst_UI();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
public:
	
	//===================================
	template <typename T>
	void SetUI(T* pObj, void(T::* func)())
	{
		m_triggerWhenClick = bind(func, pObj);
	}
	

};

