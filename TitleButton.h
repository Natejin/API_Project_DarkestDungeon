#pragma once
#include"CButton.h"
class TitleButton :public CButton
{

public:
	TitleButton();
	~TitleButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	
};

