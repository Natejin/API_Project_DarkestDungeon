#include "framework.h"
#include "strsBar.h"

HRESULT strsBar::Init()
{
	m_layer = LAYER::UIButton;
	setImage();
	return S_OK;
}

void strsBar::Render(HDC _hdc)
{
	showSTRSbar(_hdc);
}

void strsBar::setImage()
{
	ImageData temp;
	temp.m_img = MG_IMAGE->findImage("STRS_empty");

	for (int i = 0; i < 10; i++)
	{
		STRSbar.push_back(temp);
	}

	lvl.m_img = MG_IMAGE->findImage("level");
}

void strsBar::showSTRSbar(HDC _hdc)
{
	for (int i = 0; i < 10; i++)
	{
		if (info->m_STRS >= (i + 1) * 10)
		{
			if (info->m_STRS == 0) continue;
			STRSbar[i].m_img = MG_IMAGE->findImage("STRS_full");
		}
		STRSbar[i].m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 50 + 10 * i,
			m_transform->m_pos.y);
		STRSbar[i].m_img->render(_hdc, &STRSbar[i].m_trans);
	}

	lvl.m_trans.m_pos = Vector2(m_transform->m_pos.x -  58, m_transform->m_pos.y + 20);
	lvl.m_img->render(_hdc, &lvl.m_trans);
}								