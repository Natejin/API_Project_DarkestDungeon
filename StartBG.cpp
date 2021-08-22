#include "framework.h"
#include "StartBG.h"

void StartBG::SetImageSize(float width, float height) {}

StartBG::StartBG() {}
StartBG::~StartBG() {}

HRESULT StartBG::Init()
{
	m_layer = LAYER::BackGround;
	SetIMG();
    return S_OK;
}

void StartBG::SetIMG()
{
	ImageData temp0;
	mostStartBG.push_back(temp0);
	mostStartBG[0].m_img = MG_IMAGE->findImage(IMAGE::title_bg);
	mostStartBG[0].m_trans.m_pivot = 0;
	mostStartBG[0].m_trans.m_scale = Vector2(720, 720);
	mostStartBG[0].m_trans.m_pos = Vector2(0,-1200);

	ImageData temp1;
	mostStartBG.push_back(temp1);
	mostStartBG[1].m_img = MG_IMAGE->findImage(IMAGE::title_house);
	mostStartBG[1].m_trans.m_pivot = 0;
	mostStartBG[1].m_trans.m_scale = Vector2(720, 720);
	mostStartBG[1].m_trans.m_pos = Vector2(0, 500);

	ImageData temp2;
	mostStartBG.push_back(temp2);
	mostStartBG[2].m_img = MG_IMAGE->findImage("logo");
	mostStartBG[2].m_trans.m_pivot = 0;
	mostStartBG[2].m_trans.m_scale = Vector2(640*2, 242*2);
	mostStartBG[2].m_trans.m_pos = Vector2(WINSIZEX /2 - 280 , 100);
}