#pragma once
#include "CBTN_Skill.h"

class CEquipButton : public CBTN_Skill
{
public:
	CEquipButton();
	~CEquipButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);
	

	void SetEquip(IMAGE image);
};

