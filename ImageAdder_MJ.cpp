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

	return S_OK;
}