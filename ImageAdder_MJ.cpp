#include "framework.h"
#include "ImageAdder_MJ.h"

HRESULT ImageAdder_MJ::Init()
{
	MG_IMAGE->addImage("panel_bg", "images/panel/panel_bg.bmp", 1920, 1080, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("panel_bg2", "images/panel/panel_bg2.bmp", 344, 319, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("torchFrontBar", "images/dungeonUI/torch_.bmp", 900, 200, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar", "images/dungeonUI/torch_lightBar.bmp", 890, 30, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar2", "images/dungeonUI/torch_lightBar2.bmp", 422, 30, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar3", "images/dungeonUI/torch_lightBar2.bmp", 422, 30, true, RGB(255, 0, 255));
	
	MG_IMAGE->addImage("button", "images/dungeonUI/button_.bmp", 422, 30, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("treasure", "images/임시/treasure.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("trap", "images/임시/trap.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("enemy", "images/임시/enemyPoint.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("nothing", "images/임시/nothing.bmp", 100, 100, false, RGB(255, 0, 255));

	//히어로 아이콘 추가할 것

	return S_OK;
}