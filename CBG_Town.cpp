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
	assert(m_image != nullptr);
	m_image->render(_hdc, m_transform);


}*/

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

void CBG_Town::SetIMG_Est()
{
	ImageData temp0;
	most_EST.push_back(temp0);
	most_EST[0].m_img = MG_IMAGE->findImage("town_abbey");
	most_EST[0].m_trans.m_pivot = 0;
	most_EST[0].m_trans.m_scale = Vector2(720, 720);
	most_EST[0].m_trans.m_pos = Vector2(WINSIZEX / 2 - 300, WINSIZEY / 2 - 500);

	ImageData temp1;
	most_EST.push_back(temp1);
	most_EST[1].m_img = MG_IMAGE->findImage("town_guild");
	most_EST[1].m_trans.m_pivot = 0;
	most_EST[1].m_trans.m_scale = Vector2(720, 720);
	most_EST[1].m_trans.m_pos = Vector2(WINSIZEX / 2 - 150, WINSIZEY / 2 - 200);

	ImageData temp2;
	most_EST.push_back(temp2);
	most_EST[2].m_img = MG_IMAGE->findImage("town_blacksmith");
	most_EST[2].m_trans.m_pivot = 0;
	most_EST[2].m_trans.m_scale = Vector2(720, 720);
	most_EST[2].m_trans.m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2 - 100);

	ImageData temp3;
	most_EST.push_back(temp3);
	most_EST[3].m_img = MG_IMAGE->findImage("town_sanitarium");
	most_EST[3].m_trans.m_pivot = 0;
	most_EST[3].m_trans.m_scale = Vector2(720, 720);
	most_EST[3].m_trans.m_pos = Vector2(WINSIZEX / 2 - 500, WINSIZEY / 2 - 380);

	ImageData temp4;
	most_EST.push_back(temp4);
	most_EST[4].m_img = MG_IMAGE->findImage("town_tavern");
	most_EST[4].m_trans.m_pivot = 0;
	most_EST[4].m_trans.m_scale = Vector2(720, 720);
	most_EST[4].m_trans.m_pos = Vector2(WINSIZEX / 2 - 700, WINSIZEY / 2 - 250);

	ImageData temp5;
	most_EST.push_back(temp5);
	most_EST[5].m_img = MG_IMAGE->findImage("town_nomad_wagon");
	most_EST[5].m_trans.m_pivot = 0;
	most_EST[5].m_trans.m_scale = Vector2(720, 720);
	most_EST[5].m_trans.m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 + 50);

	ImageData temp6;
	most_EST.push_back(temp6);
	most_EST[6].m_img = MG_IMAGE->findImage("town_nomad_wagon");
	most_EST[6].m_trans.m_pivot = 0;
	most_EST[6].m_trans.m_scale = Vector2(720, 720);
	most_EST[6].m_trans.m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 + 50);


}

void CBG_Town::SetImageSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}
