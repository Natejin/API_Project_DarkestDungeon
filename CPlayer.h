#pragma once
#include "Unit.h"

class CPlayer : public Unit
{
protected:
	JOB job;
	int stress;
	int Hp;
	int Def;
	int Speed;
	int Damage;
	int Critical;
	int Accuracy; //명중률
	int Evasion;
	int Exp;
	//장비나 장신구는 어떻게?

	enum class Resistance
	{
		Stun,
		Blight,
		Bleed,
		Debuff,
		Move,
		Death_Door
	};
	enum class Combat_Skill
	{

	};
	enum class Camping_Skill
	{	//야습방지
		Night_Attack_Prevention,
		//정찰 강화
		Reconnaissance,
		Stress_Down,
		Cure_disease,
		Cure_Death_Door,
		Cure_Hp

	};

public:
	CPlayer();
	~CPlayer();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};