#pragma once
#include "CBTN_Skill.h"

class CBTN_Skill_Endturn :public CBTN_Skill
{
protected:

public:
	CBTN_Skill_Endturn();
	~CBTN_Skill_Endturn();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);

};