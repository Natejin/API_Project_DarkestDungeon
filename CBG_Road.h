#pragma once
#include "CBackground.h"

class CBG_Road : public CBackground
{
public:
	CBG_Road();
	~CBG_Road();

	HRESULT Init();

	//virtual void Update(float deltaTime, float worldTime);
	//virtual void LateUpdate();

	//virtual void BackRender(HDC _hdc);
	//virtual void Render(HDC _hdc);
	//virtual void FrontRender(HDC _hdc);

	//virtual void Release();

	virtual void SetIMG();
};