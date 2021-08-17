#pragma once
#include "ImageObject.h"

class ImageEffectBG : public ImageObject
{
	vector<IMAGE> rndBGIMG;
public:
	ImageEffectBG();
	~ImageEffectBG();

	HRESULT Init();

	virtual void Enable();
	virtual void Disable();
};

