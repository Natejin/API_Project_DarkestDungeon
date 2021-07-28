#pragma once
#include "Unit.h"

class CPlayer : public Unit
{
protected:
	JOB job;
	int stress;

public:
	CPlayer();
	~CPlayer();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};