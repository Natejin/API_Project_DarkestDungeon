#pragma once
#include"CEst_UI.h"

class CPosition_Button : public CEst_UI
{
	class CSpriteRenderer* m_potionButton;
	bool enable;

public:
	CPosition_Button();
	~CPosition_Button();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);
	virtual void Enable();
	virtual void Disable();

	void Click(bool _enable);
};