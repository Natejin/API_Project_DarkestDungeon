#pragma once
#include "GameObject.h"

class Unit :public GameObject
{
public:
	int HP;
	int evasion;

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

