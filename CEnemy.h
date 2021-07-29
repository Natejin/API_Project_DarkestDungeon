#pragma once
#include "Unit.h"


class CEnemy : public Unit
{
protected:
	RACE m_race;

	

	//스킬
	//스킬 Info에 accuracy, critical, DMG, changeAttribute 가 포함됨
	
	
//=======
//	int m_Hp;
//	int m_Dodge;
//	int m_DMG; //스킬에서 값을 변경하여 사용
//	int m_DEF;
//	int m_SPD;
//
//	int resist[5]; //Stun, Blight, Move, Bleed, Debuff
//	int attribute[6]; //Stun, Blight, Move, Bleed, Debuff, Buff, marked
//
//>>>>>>> Stashed changes

public:
	CEnemy();
	~CEnemy();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};