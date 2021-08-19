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
	isFirst = false;
	return S_OK;
}

void TestScene::Release()
{

}

void TestScene::Update()
{
	MG_SCENE->ResetScene();

	if (isFirst)
	{
		isFirst = false;
		MG_SCENE->changeScene(SCENETYPE::MainScene);
	}
	else {

		MG_SCENE->changeScene(SCENETYPE::Town);

	}


	
	if (MG_INPUT->isOnceKeyDown('P'))
	{
		//MG_SOUND->play(SOUND::Town,0.2);
	}
}

void TestScene::Render(HDC _hdc)
{

}
