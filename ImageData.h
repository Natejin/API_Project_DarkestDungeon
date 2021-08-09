#pragma once
#include "CTransform.h"

struct ImageData
{
	Image* m_img;
	CTransform m_trans;



	void Render(HDC hdc) 
	{
		m_img->render(hdc, &m_trans);
	}

	bool Collision(float x)
	{
		if (m_trans.m_pos.x < x && x < m_trans.m_pos.x + m_img->getFrameWidth())
		{
			return true;
		}
		else return false;
	}
};