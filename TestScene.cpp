#include "framework.h"
#include "TestScene.h"
#include "CParty.h"
#include "CEnemy.h"
#include "CBackground.h"

TestScene::TestScene() {}
TestScene::~TestScene() {}

HRESULT TestScene::Init()
{
	
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
	//MG_SCENE->changeScene(SCENETYPE::Dungeon2);
	MG_SCENE->changeScene(SCENETYPE::Town);
	//MG_SCENE->changeScene(SCENETYPE::MainScene);
	
}

void TestScene::Render(HDC _hdc)
{

}
