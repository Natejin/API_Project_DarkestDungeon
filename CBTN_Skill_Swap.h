#pragma once
#include "CBTN_Skill.h"

class CBTN_Skill_Swap :public CBTN_Skill
{
protected:

public:
	CBTN_Skill_Swap();
	~CBTN_Skill_Swap();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);

};