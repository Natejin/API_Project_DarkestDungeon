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

	//히어로 아이콘
	MG_IMAGE->addImage("crusader_skill1", "images/Heroes_skill_icon/crusader.ability.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill2", "images/Heroes_skill_icon/crusader.ability.two.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill3", "images/Heroes_skill_icon/crusader.ability.three.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill4", "images/Heroes_skill_icon/crusader.ability.four.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill5", "images/Heroes_skill_icon/crusader.ability.five.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill6", "images/Heroes_skill_icon/crusader.ability.six.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill7", "images/Heroes_skill_icon/crusader.ability.seven.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("highwayman_skill1", "images/Heroes_skill_icon/highwayman.ability.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill2", "images/Heroes_skill_icon/highwayman.ability.two.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill3", "images/Heroes_skill_icon/highwayman.ability.three.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill4", "images/Heroes_skill_icon/highwayman.ability.four.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill5", "images/Heroes_skill_icon/highwayman.ability.five.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill6", "images/Heroes_skill_icon/highwayman.ability.six.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill7", "images/Heroes_skill_icon/highwayman.ability.seven.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("plagueDoctor_skill1", "images/Heroes_skill_icon/plague_doctor.ability.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill2", "images/Heroes_skill_icon/plague_doctor.ability.two.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill3", "images/Heroes_skill_icon/plague_doctor.ability.three.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill4", "images/Heroes_skill_icon/plague_doctor.ability.four.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill5", "images/Heroes_skill_icon/plague_doctor.ability.five.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill6", "images/Heroes_skill_icon/plague_doctor.ability.six.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill7", "images/Heroes_skill_icon/plague_doctor.ability.seven.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("vestal_skill1", "images/Heroes_skill_icon/vestal.ability.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill2", "images/Heroes_skill_icon/vestal.ability.two.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill3", "images/Heroes_skill_icon/vestal.ability.three.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill4", "images/Heroes_skill_icon/vestal.ability.four.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill5", "images/Heroes_skill_icon/vestal.ability.five.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill6", "images/Heroes_skill_icon/vestal.ability.six.five.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill7", "images/Heroes_skill_icon/vestal.ability.seven.bmp", 100, 100, false, RGB(255, 0, 255));

	return S_OK;
}