#pragma once
#include"CEst_UI.h"

class Activity_log : public CEst_UI 
{
public:
	Activity_log();
	~Activity_log();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};

