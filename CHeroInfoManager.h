#pragma once
#include "CParty.h"
#include "CHero.h"

class CHeroInfoManager : public Singleton<CHeroInfoManager>
{
private:
	//히어로의 정보를 항시 전달받아 저장하고
	//다른 클래스에서 필요할 경우 그것을 전달함
	CParty* partyTemp;

public:
	CHeroInfoManager();
	~CHeroInfoManager();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	JOB getJob(int HeroIndex);
	int getResist(int HeroIndex);


};