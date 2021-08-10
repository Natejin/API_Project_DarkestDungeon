#pragma once
#include "CButton.h"
class CDragButtion : public CButton
{
public:
	
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
	void Mouse_Move(float width, float height);

};