#pragma once
#include "CDragButtion.h"

class CBTN_CampSkill :public CDragButton
{
protected:
	class CInfo_Skill* skillInfo;
	class CSpriteRenderer* m_spriteSelected;
	class CHero* hero;

public:
	bool selected;
	int index = -1;

	class TownScene* scene;
	CBTN_CampSkill();
	~CBTN_CampSkill();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void SetSkill(SKILL skill);
	virtual void Release();
};