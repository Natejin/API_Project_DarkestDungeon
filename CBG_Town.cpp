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
	SetIMG_Est();
	SetIMG_UI();
	return S_OK;
}

//void CBG_Town::BackRender(HDC _hdc)
//{
//}
//
//void CBG_Town::Render(HDC _hdc)
//{
//	
//	
//}
//
//void CBG_Town::FrontRender(HDC _hdc)
//{
//
//}

//void CBG_Road::Update(float deltaTime, float worldTime)
//{
//}
//
//void CBG_Road::LateUpdate()
//{
//}

void CBG_Town::SetIMG()
{	

	ImageData temp0;
	mostBG.push_back(temp0);
	mostBG[0].m_img = MG_IMAGE->findImage("district");
	mostBG[0].m_trans.m_pivot = 0;
	mostBG[0].m_trans.m_scale = Vector2(720, 720);
	mostBG[0].m_trans.m_pos = Vector2(720 * 0, 0);

	ImageData temp1;
	mostBG.push_back(temp1);
	mostBG[1].m_img = MG_IMAGE->findImage("district_midground");
	mostBG[1].m_trans.m_pivot = 0;
	mostBG[1].m_trans.m_scale = Vector2(720, 720);
	mostBG[1].m_trans.m_pos = Vector2(720 * 0, 0 + 150);

	ImageData temp2;
	mostBG.push_back(temp2);
	mostBG[2].m_img = MG_IMAGE->findImage("town_ruins");
	mostBG[2].m_trans.m_pivot = 0;
	mostBG[2].m_trans.m_scale = Vector2(720, 720);
	mostBG[2].m_trans.m_pos = Vector2(720 * 0, 0);

	ImageData temp3;
	mostBG.push_back(temp3);
	mostBG[3].m_img = MG_IMAGE->findImage("town_ground");
	mostBG[3].m_trans.m_pivot = 0;
	mostBG[3].m_trans.m_scale = Vector2(720, 720);
	mostBG[3].m_trans.m_pos = Vector2(720 * 0, 0);

}

void CBG_Town::SetIMG_Est()
{	
	
}

void CBG_Town::SetIMG_UI()
{
	/*ImageData temp0;
	most_HeroList_UI.push_back(temp0);
	most_HeroList_UI[0].m_img = MG_IMAGE->findImage("town_abbey_frame");
	most_HeroList_UI[0].m_trans.m_pivot = 0;
	most_HeroList_UI[0].m_trans.m_scale = Vector2(720, 720);
	most_HeroList_UI[0].m_trans.m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);*/

	ImageData m_rostertop;
	m_rostertop.m_img = MG_IMAGE->findImage(IMAGE::roster_topframe);
	m_rostertop.m_trans.m_pos = Vector2(WINSIZEX / 2 + 500, WINSIZEY / 2 - 440);
	most_HeroList_UI.push_back(m_rostertop);
	/*most_HeroList_UI[0].m_trans.m_pivot = 0;
	most_HeroList_UI[0].m_trans.m_scale = Vector2(720, 720);
	most_HeroList_UI[0].m_trans.m_pos = Vector2(WINSIZEX / 2 + 500, WINSIZEY / 2 - 440);*/

	ImageData m_rosterdown;
	m_rosterdown.m_img = MG_IMAGE->findImage(IMAGE::roster_downframe);
	m_rosterdown.m_trans.m_pos = Vector2(WINSIZEX / 2 + 500, WINSIZEY + 200);
	most_HeroList_UI.push_back(m_rosterdown);

	ImageData m_rosterbg;
	m_rosterbg.m_img = MG_IMAGE->findImage(IMAGE::roster_bggrad);
	m_rosterbg.m_trans.m_pos = Vector2(WINSIZEX / 2 + 520, WINSIZEY - 950);
	most_HeroList_UI.push_back(m_rosterbg);

	ImageData m_nameplate;
	m_nameplate.m_img = MG_IMAGE->findImage(IMAGE::estate_nameplate);
	m_nameplate.m_trans.m_pos = Vector2(WINSIZEX / 2 - 900, 0);
	most_HeroList_UI.push_back(m_nameplate);

	ImageData m_unequip_trinkets;
	m_unequip_trinkets.m_img = MG_IMAGE->findImage(IMAGE::unequip_trinkets);
	m_unequip_trinkets.m_trans.m_pos = Vector2(WINSIZEX / 2 + 670, WINSIZEY - 970);
	most_HeroList_UI.push_back(m_unequip_trinkets);

	ImageData m_sort_rarity;
	m_sort_rarity.m_img = MG_IMAGE->findImage(IMAGE::sort_rarity);
	m_sort_rarity.m_trans.m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 970);
	most_HeroList_UI.push_back(m_sort_rarity);

	ImageData m_sort_stress;
	m_sort_stress.m_img = MG_IMAGE->findImage(IMAGE::sort_rarity);
	m_sort_stress.m_trans.m_pos = Vector2(WINSIZEX / 2 + 730, WINSIZEY - 970);
	most_HeroList_UI.push_back(m_sort_stress);
}

void CBG_Town::SetImageSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}
