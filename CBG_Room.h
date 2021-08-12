#pragma once
#include "CBackground.h"

class CBG_Room : public CBackground
{
public:
	CBG_Room();
	~CBG_Room();

	HRESULT Init();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void SetIMG();
	
};