#pragma once
#include "CBackground.h"

class CBG_Road : public CBackground
{
public:
	CBG_Road();
	~CBG_Road();

	HRESULT Init();

	virtual void SetIMG();
};