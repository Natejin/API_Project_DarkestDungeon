#include "framework.h"
#include "TestScene.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CBackground.h"

TestScene::TestScene() {}
TestScene::~TestScene() {}

HRESULT TestScene::Init()
{
	//ÀÌºÎºÐ
	CBackground* bg = new CBackground();
	bg->Init();
	bg->m_image = MG_IMAGE->findImage("bg");
	MG_GMOBJ->RegisterObj("Background", bg);

	CPlayer* player = new CPlayer();
	player->Init();
	player->m_transform->m_pos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	MG_GMOBJ->RegisterObj("Player1", player);
	MG_CAMERA->SetTarget(player);

	CEnemy* enemy = new CEnemy();
	enemy->Init();
	enemy->m_transform->m_pos = Vector2(WINSIZEX, WINSIZEY);
	MG_GMOBJ->RegisterObj("enemy1", enemy);
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