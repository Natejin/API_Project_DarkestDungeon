#pragma once
#include"CHero.h"
#include"Info_Hero.h"

class CHeroOnStage_coach : public CHero
{
	
public:
	CHeroOnStage_coach();
	~CHeroOnStage_coach();

	HRESULT Init(Info_Hero* coach_info);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void SetHero();
	class CHero* CreateHero(string name, JOB job);

};

