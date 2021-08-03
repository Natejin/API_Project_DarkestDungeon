#pragma once
#include "GameObject.h"

class Unit :public GameObject
{
protected:
	int m_HP;
	int m_SPD;
	int m_POS; //(파티에서의 위치)
	int Skill[4]; //1, 2, 3, 4

	//저항
	int resist[5]; //stun, blight, bleed, debuff, move
	//상태
	bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

public:
	Unit();
	~Unit();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};