#include "framework.h"
#include "TownScene.h"
#include "CButton.h"
TownScene::TownScene()
{

}

TownScene::~TownScene()
{
}

HRESULT TownScene::Init()
{
	Image* Town_Img;
	Town_Img = MG_IMAGE->findImage("district");
	vtown.push_back(Town_Img);
	Town_Img = MG_IMAGE->findImage("district_midground");
	vtown.push_back(Town_Img);
	Town_Img = MG_IMAGE->findImage("ruins");
	vtown.push_back(Town_Img);
	Town_Img = MG_IMAGE->findImage("town_ground");
	vtown.push_back(Town_Img);

	CTransform ts;
	ts.m_pos = Vector2(300, 690);
	ts_vtown.push_back(ts);
	ts.m_pos = Vector2(330, 810);
	ts_vtown.push_back(ts);
	ts.m_pos = Vector2(965, 690);
	ts_vtown.push_back(ts);
	ts_vtown.push_back(ts);

	return S_OK;
}

HRESULT TownScene::Init(bool managerInit)
{
	return S_OK;
}

void TownScene::Release()
{
}

void TownScene::Update()
{


}

void TownScene::Update(HDC _hdc)
{
	if (abbey_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_abbey(_hdc);
	}
	if (blacksmith_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_blacksmith(_hdc);
	}
	if (campingTrainer_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_campingTrainer(_hdc);
	}
	if (graveyard_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_graveyard(_hdc);
	}
	if (guild_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_guild(_hdc);
	}
	if (nomad_wagon_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_nomad_wagon(_hdc);
	}
	if (sanitarium_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_sanitarium(_hdc);
	}

	if (stage_coach_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_stage_coach(_hdc);
	}

	if (town_statue_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_town_statue(_hdc);
	}

	if (tavern_rc.CheckCollisionWithPoint(m_ptMouse))
	{
		Show_tavern(_hdc);
	}
}

void TownScene::Render(HDC _hdc)
{
	Show_AllTownScene(_hdc);

}
void TownScene::Show_AllTownScene(HDC _hdc)
{
	/*
	뒤에 나타나는 배경들 먼저 그리고
	나머지 estate를 마지막에 그리자.
	townbg->sky->ruins->ground->town_backdrop->tree
	->각종시설.
	*/


	for (int i = 0; i < vtown.size(); i++)
	{
		vtown[i]->render(_hdc, &ts_vtown[i]);
	}

}

void TownScene::Show_Estate(HDC _hdc)
{	/*
	MG_IMAGE->addImage("town_abbey", "images/Town/estate/town_abbey_1.bmp", 800, 986, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_blacksmith", "images/Town/estate/town_blacksmith_1.bmp", 719, 795, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_camping_trainer", "images/Town/estate/town_camping_trainer_1.bmp", 281, 424, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_graveyard", "images/Town/estate/town_graveyard_1.bmp", 578, 293, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_guild", "images/Town/estate/town_guild_1.bmp", 707, 697, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_nomad_wagon", "images/Town/estate/town_nomad_wagon_1.bmp", 514, 392, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_sanitarium", "images/Town/estate/town_sanitarium_1.bmp", 764, 963, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_stage_coach", "images/Town/estate/town_stage_coach_1.bmp", 509, 362, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_statue", "images/Town/estate/town_statue_1.bmp", 449, 498, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_tavern", "images/Town/estate/town_tavern_1.bmp", 824, 814, true, RGB(255, 0, 255));
	*/


}

void TownScene::Show_abbey(HDC _hdc)
{
	/*
	MG_IMAGE->addImage("abbey.character", "images/Town/abbey/abbey.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("abbey.character.bg", "images/Town/abbey/abbey.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/


}

void TownScene::Show_blacksmith(HDC _hdc)
{	/*
	MG_IMAGE->addImage("blacksmith.character", "images/Town/blacksmith/blacksmith.character.bmp", 865, 760, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("blacksmith.character.bg", "images/Town/blacksmith/blacksmith.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("blacksmith.frame", "images/Town/blacksmith/blacksmith.frame.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_campingTrainer(HDC _hdc)
{	/*
	MG_IMAGE->addImage("camping_trainer.character", "images/Town/camping_trainer/camping_trainer.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("camping_trainer.character.bg", "images/Town/camping_trainer/camping_trainer.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_graveyard(HDC _hdc)
{
	/*
	MG_IMAGE->addImage("graveyard.character", "images/Town/graveyard/graveyard.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("graveyard.character", "images/Town/graveyard/graveyard.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_guild(HDC _hdc)
{	/*
	MG_IMAGE->addImage("guild.character", "images/Town/guild/guild.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("guild.character.bg", "images/Town/guild/guild.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_nomad_wagon(HDC _hdc)
{	/*
	MG_IMAGE->addImage("nomad_wagon.character", "images/Town/nomad_wagon/nomad_wagon.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("nomad_wagon.character.bg", "images/Town/nomad_wagon/nomad_wagon.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("inventory_grid_bg", "images/Town/nomad_wagon/inventory_grid_backgroud.bmp", 684, 360, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_stage_coach(HDC _hdc)
{	/*
	MG_IMAGE->addImage("sanitarium.character", "images/Town/sanitarium/sanitarium.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("sanitarium.character.bg", "images/Town/sanitarium/sanitarium.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_town_statue(HDC _hdc)
{	/*
	MG_IMAGE->addImage("stage_coach.character", "images/Town/stage_coach/stage_coach.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stage_coach.character.bg", "images/Town/stage_coach/stage_coach.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_sanitarium(HDC _hdc)
{	/*
	MG_IMAGE->addImage("statue.character", "images/Town/statue/statue.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("statue.character.bg", "images/Town/statue/statue.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}

void TownScene::Show_tavern(HDC _hdc)
{	/*
	MG_IMAGE->addImage("tavern.character", "images/Town/tavern/tavern.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("tavern.character.bg", "images/Town/tavern/tavern.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	*/

}