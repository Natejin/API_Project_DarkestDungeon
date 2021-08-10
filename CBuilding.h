#pragma once
#include "CButton.h"

class CBuilding :public CButton
{
public:
	CBuilding();
	~CBuilding();

	HRESULT Init();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

};

