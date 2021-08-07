#pragma once

#pragma once
#include "CComponent.h"

class CSpriteRenderer : public CComponent
{
	class CTransform* m_trans;
	class Image* m_image;

	Vector2 m_imageSize;

	int imageWidth;
	int imageHeight;
public:
	CSpriteRenderer();
	~CSpriteRenderer();
	void SetTrans(class CTransform* _trans) { m_trans = _trans; }

	void SetImage(string imageName);
	void SetImage(IMAGE imageName);

	class Image* GetImage();

	void Render(HDC _hdc);
	void RenderUI(HDC _hdc);
};

