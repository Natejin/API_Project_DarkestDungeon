#include "framework.h"
#include "CBG_Town.h"

CBG_Town::CBG_Town()
{
}

CBG_Town::~CBG_Town()
{
}

HRESULT CBG_Town::Init()
{
	m_layer = LAYER::BackGround;
	bgCount = 10;
	roadCount = 6;
	SetIMG();
	return S_OK;
}

void CBG_Town::SetIMG()
{	
	ImageData temp0;
	mostBG.push_back(temp0);
	mostBG[0].m_img = MG_IMAGE->findImage("district");
	mostBG[0].m_trans.m_pivot = 0;
	mostBG[0].m_trans.m_scale = Vector2(720, 720);
	mostBG[0].m_trans.m_pos = Vector2(0, 0);

	ImageData temp1;
	mostBG.push_back(temp1);
	mostBG[1].m_img = MG_IMAGE->findImage("district_midground");
	mostBG[1].m_trans.m_pivot = 0;
	mostBG[1].m_trans.m_scale = Vector2(720, 720);
	mostBG[1].m_trans.m_pos = Vector2(0, 0 + 150);

	ImageData temp2;
	mostBG.push_back(temp2);
	mostBG[2].m_img = MG_IMAGE->findImage("town_ruins");
	mostBG[2].m_trans.m_pivot = 0;
	mostBG[2].m_trans.m_scale = Vector2(720, 720);
	mostBG[2].m_trans.m_pos = Vector2(0, 0);

	ImageData temp3;
	mostBG.push_back(temp3);
	mostBG[3].m_img = MG_IMAGE->findImage("town_ground");
	mostBG[3].m_trans.m_pivot = 0;
	mostBG[3].m_trans.m_scale = Vector2(720, 720);
	mostBG[3].m_trans.m_pos = Vector2(0, 35);

}

void CBG_Town::SetImageSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}