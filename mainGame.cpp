#include"framework.h"
#include "mainGame.h"

mainGame::mainGame() 
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //TODO 디버깅 하는곳
	AllocConsole();
	//_CrtSetBreakAlloc(3210); 	//디버그용 메모리 누수 체크

#endif // _DEBUG
}
mainGame::~mainGame() {}

HRESULT mainGame::init()
{
	gameNode::init(true);
	DB_ITEM->Init();
	DB_SKILL->Init();
	DB_UNIT->Init();

	MG_SCENE->init();
	MG_GAME->Init();
	MG_CAMERA->Init();
	MG_GMOBJ->Init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	MG_TIME->update(60.0f);

	float deltaTime = MG_TIME->getElapsedTime();
	float worldTime = MG_TIME->getWorldTime();

	MG_SCENE->update();
	MG_INPUT->Update(deltaTime, worldTime);
	MG_GMOBJ->Update(deltaTime, worldTime);
	MG_GMOBJ->LateUpdate();

	MG_CAMERA->Update(deltaTime, worldTime);

	MG_GAME->Update(deltaTime, worldTime);
}

void mainGame::render(/*HDC hdc*/)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//==============================================

	MG_GMOBJ->BackRender(getMemDC());
	MG_GMOBJ->Render(getMemDC());
	MG_GMOBJ->FrontRender(getMemDC());

	//==============================================
	MG_TIME->render(getMemDC());
	MG_SCENE->Render(getMemDC());
	MG_CAMERA->Render(getMemDC());
	MG_GAME->Render(getMemDC());

	//백버퍼의 내용을 HDC그린다.(건드리지 말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}