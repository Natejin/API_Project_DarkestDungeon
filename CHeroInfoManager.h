#pragma once
#include "CParty.h"
#include "CHero.h"

class CHeroInfoManager : public Singleton<CHeroInfoManager>
{
private:
	//������� ������ �׽� ���޹޾� �����ϰ�
	//�ٸ� Ŭ�������� �ʿ��� ��� �װ��� ������
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