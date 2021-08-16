#pragma once
#include "CTransform.h"

struct ImageData
{
	Image* m_img = nullptr;
	CTransform m_trans;

	void Render(HDC hdc) 
	{
		m_img->render(hdc, &m_trans);
	}

	void RenderWithPivot(HDC hdc)
	{
		m_img->render(hdc, &m_trans, Vector2(m_img->getWidth(), m_img->getHeight()));
	}

	void RenderUI(HDC hdc)
	{
		m_img->renderUI(hdc, &m_trans);
	}
};