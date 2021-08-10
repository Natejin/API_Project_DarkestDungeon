#pragma once
#include "CEst_UI.h"
class Sanitarium :public CEst_UI
{
private:
	class CButton* m_quick;

public:
	Rect m_rect;

	Sanitarium();
	~Sanitarium();

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
	
};

