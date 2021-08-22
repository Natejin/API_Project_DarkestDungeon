#pragma once
#include "Info_Hero.h"

class strsBar : public GameObject
{
public:
	vector<ImageData> STRSbar;
	Info_Hero* info;

public:
	HRESULT Init();
	virtual void Render(HDC _hdc);

	void setImage();
	void showSTRSbar(HDC _hdc);
};