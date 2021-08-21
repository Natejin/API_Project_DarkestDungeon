#pragma once
#include"CBackground.h"

class StartBG :public CBackground
{
public:
	Rect m_rect;
	void SetImageSize(float width, float height);

	StartBG();
	~StartBG();

	HRESULT Init();

	virtual void SetIMG();
};