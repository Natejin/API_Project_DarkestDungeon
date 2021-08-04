#include "framework.h"
#include "TestScene.h"
#include "CParty.h"
#include "CEnemy.h"
#include "CBackground.h"

TestScene::TestScene() {}
TestScene::~TestScene() {}

HRESULT TestScene::Init()
{
	//CParty* player = new CParty();
	//player->Init();
	//player->m_transform->m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	//MG_GMOBJ->RegisterObj("Player1", player);
	//MG_CAMERA->SetTarget(player);

	//CEnemy* enemy = new CEnemy();
	//enemy->Init();
	//enemy->m_transform->m_pos = Vector2(WINSIZEX, WINSIZEY);
	//MG_GMOBJ->RegisterObj("enemy1", enemy);

	MG_SCENE->changeScene(SCENETYPE::Dungeon);

	MG_SCENE->changeScene(SCENETYPE::Town);

	return S_OK;
}

HRESULT TestScene::Init(bool managerInit)
{
	return S_OK;
}

void TestScene::Release()
{

}

void TestScene::Update()
{
	//MG_SCENE->changeScene(SCENETYPE::Dungeon);
	MG_SCENE->changeScene(SCENETYPE::Town);
}

void TestScene::Render(HDC _hdc)
{
	//RectangleMakeCenter(_hdc, 500, 500, 100, 100); 


}

void TestScene::Show_AllTownScene()
{
	/*
	뒤에 나타나는 배경들 먼저 그리고 
	나머지 estate를 마지막에 그리자.
	townbg->sky->ruins->ground->town_backdrop->tree
	->각종시설.
	*/
	
}
//이미지 클릭하면 각 시설이용하는 ui로 넘어가자.
void TestScene::Show_abbey()
{
}

void TestScene::Show_blacksmith()
{
}

void TestScene::Show_campingTrainer()
{
}

void TestScene::Show_graveyard()
{
}

void TestScene::Show_guild()
{
}

void TestScene::Show_nomad_wagon()
{
}

void TestScene::Show_stage_coach()
{
}

void TestScene::Show_town_statue()
{
}

void TestScene::Show_sanitarium()
{
}

void TestScene::Show_tavern()
{
}
