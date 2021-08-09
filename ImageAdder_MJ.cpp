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
	MG_IMAGE->addImage("crusader_skill1", "images/icons_heroes/crusader.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill2", "images/icons_heroes/crusader.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill3", "images/icons_heroes/crusader.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill4", "images/icons_heroes/crusader.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill5", "images/icons_heroes/crusader.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill6", "images/icons_heroes/crusader.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill7", "images/icons_heroes/crusader.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("highwayman_skill1", "images/icons_heroes/highwayman.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill2", "images/icons_heroes/highwayman.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill3", "images/icons_heroes/highwayman.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill4", "images/icons_heroes/highwayman.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill5", "images/icons_heroes/highwayman.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill6", "images/icons_heroes/highwayman.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill7", "images/icons_heroes/highwayman.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("plagueDoctor_skill1", "images/icons_heroes/plague_doctor.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill2", "images/icons_heroes/plague_doctor.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill3", "images/icons_heroes/plague_doctor.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill4", "images/icons_heroes/plague_doctor.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill5", "images/icons_heroes/plague_doctor.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill6", "images/icons_heroes/plague_doctor.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill7", "images/icons_heroes/plague_doctor.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("vestal_portrait", "images/icons_heroes/vestal_portrait_roster.bmp", 85, 85, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill1", "images/icons_heroes/vestal.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill2", "images/icons_heroes/vestal.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill3", "images/icons_heroes/vestal.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill4", "images/icons_heroes/vestal.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill5", "images/icons_heroes/vestal.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill6", "images/icons_heroes/vestal.ability.six.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill7", "images/icons_heroes/vestal.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("ability_move", "images/icons_heroes/ability_move.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("vestal_armor", "images/icons_equip_Vestal/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_weapon", "images/icons_equip_Vestal/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));


	return S_OK;
}