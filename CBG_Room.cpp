#include "framework.h"
#include "CBG_Room.h"

CBG_Room::CBG_Room() {}
CBG_Room::~CBG_Room() {}

HRESULT CBG_Room::Init()
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

void CBG_Room::SetIMG()
{
	//for (int i = 0; i < bgCount; i++)
	//{
	//	mostBG[i].m_img = MG_IMAGE->findImage("ruins_bg");
	//	mostBG[i].m_trans.m_pivot = 0;
	//	mostBG[i].m_trans.m_scale = Vector2(720, 720);
	//	mostBG[i].m_trans.m_pos = Vector2(720 * i, 0);

	//	mostFG_Bottom[i].m_img = MG_IMAGE->findImage("ruins_bottom");
	//	mostFG_Bottom[i].m_trans.m_pivot = 0;
	//	mostFG_Bottom[i].m_trans.m_scale = Vector2(720, 720);
	//	mostFG_Bottom[i].m_trans.m_pos = Vector2(720 * (i - 2), WINSIZEY - 101);

	//	mostFG_Top[i].m_img = MG_IMAGE->findImage("ruins_top");
	//	mostFG_Top[i].m_trans.m_pivot = 0;
	//	mostFG_Top[i].m_trans.m_scale = Vector2(720, 720);
	//	mostFG_Top[i].m_trans.m_pos = Vector2(720 * (i - 2), -100);
	//}


	/*for (int i = 0; i < roadCount; i++)
	{
		road[i].m_img = MG_IMAGE->findImage("ruins_wall7");
		road[i].m_trans.m_pivot = 0;
		road[i].m_trans.m_scale = Vector2(720, 720);
		road[i].m_trans.m_pos = Vector2(720 * i, 0);
	}*/
}