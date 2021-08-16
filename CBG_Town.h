#pragma once
#include "CBackground.h"

class CBG_Town : public CBackground
{
public:
	Rect m_rect;
	void SetImageSize(float width, float height);

	CBG_Town();
	~CBG_Town();

	HRESULT Init();

	virtual void SetIMG();
	void SetIMG_UI();
};