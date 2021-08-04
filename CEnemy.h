#pragma once
#include "Unit.h"

class CEnemy : public Unit
{
protected:
	RACE m_race;

protected:
	int m_DEF;
	int m_DODGE;
	//��ų
	//��ų Info�� accuracy, critical, DMG, changeAttribute �� ���Ե�

public:
	CEnemy();
	~CEnemy();

	HRESULT Init();

	HRESULT Init(string img, int resist[],
		int HP, int SPD, int POS,
		int DEF, int DODGE);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};