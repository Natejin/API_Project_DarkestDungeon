#pragma once
#include "Unit.h"

class CEnemy : public Unit
{
protected:
	RACE m_race;

	//스킬
	//스킬 Info에 accuracy, critical, DMG, changeAttribute 가 포함됨

public:
	CEnemy();
	~CEnemy();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};