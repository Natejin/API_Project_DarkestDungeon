#include "framework.h"
#include "DungeonScene.h"

DungeonScene::DungeonScene()
{
}

DungeonScene::~DungeonScene()
{
}

void DungeonScene::CreateDungeon()
{

}

HRESULT DungeonScene::Init()
{
	dungeonState = DUNGEONSTATE::ROOM;
	return S_OK;
}

HRESULT DungeonScene::Init(bool managerInit)
{

	return S_OK;
}

void DungeonScene::Release()
{
}

void DungeonScene::Update()
{
}

void DungeonScene::Render(HDC _hdc)
{
}
