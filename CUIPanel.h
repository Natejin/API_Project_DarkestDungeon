#pragma once

#include "GameObject.h"

class CUIPanel : public GameObject
{
	bool useFrontRender;
	bool useRender;
	bool useBackRender;

public:
	CUIPanel();
	~CUIPanel();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	void UseFrontRender();
	void UseRender();
	void UseBackRender();
};

