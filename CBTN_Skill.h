#pragma once
#include "CDragButtion.h"

class CBTN_Skill :public CDragButton
{
protected:
	class CInfo_Skill* skillInfo;
	class CHero* hero;
	//class 

public:
	class DungeonScene* scene;

	CBTN_Skill();
	~CBTN_Skill();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void SetSkill(SKILL skill);
};