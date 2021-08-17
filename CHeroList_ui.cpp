#include "framework.h"
#include "CHeroList_ui.h"

CHeroList_ui::CHeroList_ui()
{
    m_layer = LAYER::UI;
}
CHeroList_ui::~CHeroList_ui() {}

HRESULT CHeroList_ui::Init()
{	
	ImageData m_rosterbg;
	m_rosterbg.m_img = MG_IMAGE->findImage(IMAGE::roster_bggrad);
	m_rosterbg.m_trans.m_pos = Vector2(WINSIZEX / 2 + 520, WINSIZEY - 950);
	most_HeroList_UI.push_back(m_rosterbg);

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

	ImageData m_nameplate;
	m_nameplate.m_img = MG_IMAGE->findImage(IMAGE::estate_nameplate);
	m_nameplate.m_trans.m_pos = Vector2(WINSIZEX / 2 - 900, 0);
	most_HeroList_UI.push_back(m_nameplate);

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
	for(size_t i = 0; i < most_HeroList_UI.size(); i++)
	{
		most_HeroList_UI[i].Render(_hdc);
	}
}

void CHeroList_ui::FrontRender(HDC _hdc)
{

}

void CHeroList_ui::Release()
{
	GameObject::Release();
}