#include "framework.h"
#include "CBG_Town.h"
#include"CBackground.h"
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

/*void CBG_Town::BackRender(HDC _hdc)
{
}

void CBG_Town::Render(HDC _hdc)
{
}

void CBG_Town::FrontRender(HDC _hdc)
{
	


}*/

//void CBG_Road::Update(float deltaTime, float worldTime)
//{
//}
//
//void CBG_Road::LateUpdate()
//{
//}

void CBG_Town::SetIMG()
{	/*
	뒤에 나타나는 배경들 먼저 그리고
	나머지 estate를 마지막에 그리자.
	townbg->sky->ruins->ground->town_backdrop->tree
	->각종시설.
	*/

	ImageData temp0;
	mostBG.push_back(temp0);
	mostBG[0].m_img = MG_IMAGE->findImage("district");
	mostBG[0].m_trans.m_pivot = 0;
	mostBG[0].m_trans.m_scale = Vector2(720, 720);
	mostBG[0].m_trans.m_pos = Vector2(720 * 0, 0);

	ImageData temp1;
	mostBG.push_back(temp1);
	mostBG[1].m_img = MG_IMAGE->findImage("town_ruins");
	mostBG[1].m_trans.m_pivot = 0;
	mostBG[1].m_trans.m_scale = Vector2(720, 720);
	mostBG[1].m_trans.m_pos = Vector2(720 * 0, 0);

	ImageData temp2;
	mostBG.push_back(temp2);
	mostBG[2].m_img = MG_IMAGE->findImage("district_midground");
	mostBG[2].m_trans.m_pivot = 0;
	mostBG[2].m_trans.m_scale = Vector2(720, 720);
	mostBG[2].m_trans.m_pos = Vector2(720 * 0, 0 + 150);

	ImageData temp3;
	mostBG.push_back(temp3);
	mostBG[3].m_img = MG_IMAGE->findImage("town_ground");
	mostBG[3].m_trans.m_pivot = 0;
	mostBG[3].m_trans.m_scale = Vector2(720, 720);
	mostBG[3].m_trans.m_pos = Vector2(720 * 0, 0);

}

void CBG_Town::SetImageSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}
