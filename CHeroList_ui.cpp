#include "framework.h"
#include "CHeroList_ui.h"

CHeroList_ui::CHeroList_ui()
{
    m_layer = LAYER::UI;
}

CHeroList_ui::~CHeroList_ui()
{
}

HRESULT CHeroList_ui::Init()
{
	ImageData m_rostertop;
	m_rostertop.m_img = MG_IMAGE->findImage(IMAGE::roster_topframe);
	m_rostertop.m_trans.m_pos = Vector2(WINSIZEX / 2 + 500, WINSIZEY / 2 - 440);
	v_roster.push_back(m_rostertop);

	ImageData m_rosterdown;
	m_rosterdown.m_img = MG_IMAGE->findImage(IMAGE::roster_downframe);
	m_rosterdown.m_trans.m_pos = Vector2(WINSIZEX / 2 + 500, WINSIZEY + 0);
	v_roster.push_back(m_rosterdown);

	ImageData m_rosterbg;
	m_rosterbg.m_img = MG_IMAGE->findImage(IMAGE::roster_bggrad);
	m_rosterbg.m_trans.m_pos = Vector2(WINSIZEX / 2 + 520, WINSIZEY - 950);
	//m_rosterbg.m_trans.m_pos = Vector2(WINSIZEX / 2 + 520, WINSIZEY - 550);
	v_roster.push_back(m_rosterbg);

	ImageData m_nameplate;
	m_nameplate.m_img = MG_IMAGE->findImage(IMAGE::estate_nameplate);
	m_nameplate.m_trans.m_pos = Vector2(WINSIZEX / 2 - 900, 0);
	v_roster.push_back(m_nameplate);

	ImageData m_unequip_trinkets;
	m_unequip_trinkets.m_img = MG_IMAGE->findImage(IMAGE::unequip_trinkets);
	m_unequip_trinkets.m_trans.m_pos = Vector2(WINSIZEX / 2 + 670, WINSIZEY - 970);
	v_roster.push_back(m_unequip_trinkets);

	ImageData m_sort_rarity;
	m_sort_rarity.m_img = MG_IMAGE->findImage(IMAGE::sort_rarity);
	m_sort_rarity.m_trans.m_pos = Vector2(WINSIZEX / 2 + 700, WINSIZEY - 970);
	v_roster.push_back(m_sort_rarity);

	ImageData m_sort_stress;
	m_sort_stress.m_img = MG_IMAGE->findImage(IMAGE::sort_rarity);
	m_sort_stress.m_trans.m_pos = Vector2(WINSIZEX / 2 + 730, WINSIZEY - 970);
	v_roster.push_back(m_sort_stress);
    return S_OK;
}

void CHeroList_ui::Update(float deltaTime, float worldTime)
{
	

}

void CHeroList_ui::LateUpdate()
{
}

void CHeroList_ui::BackRender(HDC _hdc)
{
}

void CHeroList_ui::Render(HDC _hdc)
{
}

void CHeroList_ui::FrontRender(HDC _hdc)
{
	for(size_t i = 0; i < v_roster.size(); i++)
	{
		v_roster[i].Render(_hdc);
	}
}

void CHeroList_ui::Release()
{
}
