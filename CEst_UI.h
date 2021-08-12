#pragma once
#include "GameObject.h"

class CEst_UI :public GameObject
{
protected:
	 class CSpriteRenderer* m_windowPanelBG;

	 class CSpriteRenderer* m_windowPanelChar;

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
};
