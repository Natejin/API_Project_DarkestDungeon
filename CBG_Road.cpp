#include "framework.h"
#include "CBG_Road.h"

CBG_Road::CBG_Road()
{
}

CBG_Road::~CBG_Road()
{
}

HRESULT CBG_Road::Init()
{
	m_layer = LAYER::BackGround;
	bgCount = 10;
	roadCount = 6;
	SetIMG();
    return S_OK;
}

//void CBG_Road::Update(float deltaTime, float worldTime)
//{
//}
//
//void CBG_Road::LateUpdate()
//{
//}


void CBG_Road::SetIMG()
{
	for (int i = 0; i < bgCount; i++)
	{
		ImageData temp1;
		mostBG.push_back(temp1);
		mostBG[i].m_img = MG_IMAGE->findImage("ruins_bg");
		mostBG[i].m_trans.m_pivot = 0;
		mostBG[i].m_trans.m_scale = Vector2(720, 720);
		mostBG[i].m_trans.m_pos = Vector2(720 * i, 0);

		ImageData temp2;
		mostFG_Bottom.push_back(temp2);
		mostFG_Bottom[i].m_img = MG_IMAGE->findImage("ruins_bottom");
		mostFG_Bottom[i].m_trans.m_pivot = 0;
		mostFG_Bottom[i].m_trans.m_scale = Vector2(720, 720);
		mostFG_Bottom[i].m_trans.m_pos = Vector2(720 * (i - 2), WINSIZEY - 101);

		ImageData temp3;
		mostFG_Top.push_back(temp3);
		mostFG_Top[i].m_img = MG_IMAGE->findImage("ruins_top");
		mostFG_Top[i].m_trans.m_pivot = 0;
		mostFG_Top[i].m_trans.m_scale = Vector2(720, 720);
		mostFG_Top[i].m_trans.m_pos = Vector2(720 * (i - 2), -100);
	}


	for (int i = 0; i < roadCount; i++)
	{
		ImageData temp1;
		road.push_back(temp1);
		road[i].m_trans.m_pivot = 0;
		road[i].m_trans.m_scale = Vector2(720, 720);
		road[i].m_trans.m_pos = Vector2(720 * i, 0);
	}

	road[0].m_img = MG_IMAGE->findImage("ruins_wall0");
	road[1].m_img = MG_IMAGE->findImage("ruins_wall1");
	road[2].m_img = MG_IMAGE->findImage("ruins_wall2");
	road[3].m_img = MG_IMAGE->findImage("ruins_wall3");
	road[4].m_img = MG_IMAGE->findImage("ruins_wall4");
	road[5].m_img = MG_IMAGE->findImage("ruins_wall0");
	//road[6].m_img = MG_IMAGE->findImage("ruins_wall5");
	//road[7].m_img = MG_IMAGE->findImage("ruins_wall6");
	//road[8].m_img = MG_IMAGE->findImage("ruins_wall7");
}