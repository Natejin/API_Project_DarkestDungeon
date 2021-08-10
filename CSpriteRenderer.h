#pragma once
#include "CComponent.h"
#include "GameObject.h"

class CTransform;
class CSpriteRenderer : public CComponent
{
	friend GameObject;
	 CTransform* m_trans;
	class Image* m_image;

	Vector2 m_imageSize;
	int imageWidth;
	int imageHeight;

protected:
	CSpriteRenderer();

public:
	CSpriteRenderer(IMAGE imageName, CTransform* _trans);
	~CSpriteRenderer();
	void SetTrans(class CTransform* _trans) { m_trans = _trans; }



	void SetImage(string imageName);
	void SetImage(IMAGE imageName);

	class Image* GetImage();

	void Render(HDC _hdc);
	void RenderUI(HDC _hdc);

	Vector2 GetImageSize();
};

