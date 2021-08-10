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
{	/*
	�ڿ� ��Ÿ���� ���� ���� �׸���
	������ estate�� �������� �׸���.
	townbg->sky->ruins->ground->town_backdrop->tree
	->�����ü�.
	*/

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

	/*ImageData temp4;
	mostBG.push_back(temp4);
	mostBG[4].m_img = MG_IMAGE->findImage("roster_topframe");
	mostBG[4].m_trans.m_pivot = 0;
	mostBG[4].m_trans.m_scale = Vector2(720, 720);
	mostBG[4].m_trans.m_pos = Vector2(720 * 0, 0);*/


}

void CBG_Town::SetIMG_Est()
{	
	ImageData temp0;
	most_EST.push_back(temp0);
	most_EST[0].m_img = MG_IMAGE->findImage("town_abbey");
	most_EST[0].m_trans.m_pivot = 0;
	most_EST[0].m_trans.m_scale = Vector2(720, 720);
	most_EST[0].m_trans.m_pos = Vector2(WINSIZEX / 2 - 350, WINSIZEY / 2 - 450);

	ImageData temp1;
	most_EST.push_back(temp1);
	most_EST[1].m_img = MG_IMAGE->findImage("town_graveyard");
	most_EST[1].m_trans.m_pivot = 0;
	most_EST[1].m_trans.m_scale = Vector2(720, 720);
	most_EST[1].m_trans.m_pos = Vector2(WINSIZEX / 2 - 400, WINSIZEY / 2 - 150);

	ImageData temp2;
	most_EST.push_back(temp2);
	most_EST[2].m_img = MG_IMAGE->findImage("town_guild");
	most_EST[2].m_trans.m_pivot = 0;
	most_EST[2].m_trans.m_scale = Vector2(720, 720);
	most_EST[2].m_trans.m_pos = Vector2(WINSIZEX / 2 - 180, WINSIZEY / 2 - 250);

	ImageData temp3;
	most_EST.push_back(temp3);
	most_EST[3].m_img = MG_IMAGE->findImage("town_blacksmith");
	most_EST[3].m_trans.m_pivot = 0;
	most_EST[3].m_trans.m_scale = Vector2(720, 720);
	most_EST[3].m_trans.m_pos = Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2 - 100);

	ImageData temp4;
	most_EST.push_back(temp4);
	most_EST[4].m_img = MG_IMAGE->findImage("town_sanitarium");
	most_EST[4].m_trans.m_pivot = 0;
	most_EST[4].m_trans.m_scale = Vector2(720, 720);
	most_EST[4].m_trans.m_pos = Vector2(WINSIZEX / 2 - 550, WINSIZEY / 2 - 280);

	ImageData temp5;
	most_EST.push_back(temp5);
	most_EST[5].m_img = MG_IMAGE->findImage("town_tavern");
	most_EST[5].m_trans.m_pivot = 0;
	most_EST[5].m_trans.m_scale = Vector2(720, 720);
	most_EST[5].m_trans.m_pos = Vector2(WINSIZEX / 2 - 700, WINSIZEY / 2 - 150);

	ImageData temp6;
	most_EST.push_back(temp6);
	most_EST[6].m_img = MG_IMAGE->findImage("town_statue");
	most_EST[6].m_trans.m_pivot = 0;
	most_EST[6].m_trans.m_scale = Vector2(720, 720);
	most_EST[6].m_trans.m_pos = Vector2(WINSIZEX / 2 - 350, WINSIZEY / 2 - 80);

	ImageData temp7;
	most_EST.push_back(temp7);
	most_EST[7].m_img = MG_IMAGE->findImage("town_nomad_wagon");
	most_EST[7].m_trans.m_pivot = 0;
	most_EST[7].m_trans.m_scale = Vector2(720, 720);
	most_EST[7].m_trans.m_pos = Vector2(WINSIZEX / 2 - 200, WINSIZEY / 2 + 30);

	ImageData temp8;
	most_EST.push_back(temp8);
	most_EST[8].m_img = MG_IMAGE->findImage("town_stage_coach");
	most_EST[8].m_trans.m_pivot = 0;
	most_EST[8].m_trans.m_scale = Vector2(720, 720);
	most_EST[8].m_trans.m_pos = Vector2(WINSIZEX / 2 - 850, WINSIZEY / 2 - 50);

	ImageData temp9;
	most_EST.push_back(temp9);
	most_EST[9].m_img = MG_IMAGE->findImage("town_camping_trainer");
	most_EST[9].m_trans.m_pivot = 0;
	most_EST[9].m_trans.m_scale = Vector2(720, 720);
	most_EST[9].m_trans.m_pos = Vector2(WINSIZEX / 2 - 900, WINSIZEY / 2 - 330);

	
}

void CBG_Town::SetIMG_UI()
{
	/*ImageData temp0;
	most_EST_UI.push_back(temp0);
	most_EST_UI[0].m_img = MG_IMAGE->findImage("town_abbey_frame");
	most_EST_UI[0].m_trans.m_pivot = 0;
	most_EST_UI[0].m_trans.m_scale = Vector2(720, 720);
	most_EST_UI[0].m_trans.m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);*/
}

void CBG_Town::SetImageSize(float width, float height)
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + width;
	m_rect.b = m_transform->m_pos.y + height;
}
