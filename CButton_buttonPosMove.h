#pragma once
#include "CButton.h"


class CButton_buttonPosMove : public CButton
{
private:
	////function<void()> m_triggerWhenClick;
	//int countNum;
	GameObject* go;

public:
	Rect m_rect;
	int sizeX, sizeY;

	CButton_buttonPosMove();
	~CButton_buttonPosMove();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//===================================

	//void SetButtonSize(float width, float height);

	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		m_triggerWhenUp = bind(func, pObj);
	}

	//void setRect();
	void setBtTarget(GameObject* _go);

};