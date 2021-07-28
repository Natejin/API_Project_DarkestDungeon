#include "framework.h"
#include "TestScene.h"
#include "CPlayer.h"
#include "CBackground.h"
TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

HRESULT TestScene::Init()
{
	CBackground* bg = new CBackground();
	bg->Init();
	bg->m_image = MG_IMAGE->findImage("배경화면");
	MG_GMOBJ->RegisterObj("Background", bg);

	CPlayer* player = new CPlayer();
	player->Init();
	MG_GMOBJ->RegisterObj("Player1", player);
	MG_CAMERA->SetTarget(player);
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

}

void TestScene::Render(HDC _hdc)
{
	RectangleMakeCenter(_hdc, 500, 500, 100, 100);
}
