#pragma once
#include"CDragButtion.h"
class Hero_Roster : public CDragButton
{
	int index;

public:
	
	class TownScene* scene;

	Hero_Roster();
	~Hero_Roster();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);
};

