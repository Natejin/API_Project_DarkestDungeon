#pragma once
#include "CTransform.h"

struct ImageData
{
	image* m_img;
	Transform m_trans;

	void Render(HDC hdc) {
		m_img->render(hdc, &m_trans);
	}
};