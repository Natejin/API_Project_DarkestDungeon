#include"framework.h"
#include "mainGame.h"
#include "ImageAdder_MJ.h"
#include "ImageAdder_WT.h"

mainGame::mainGame() {
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

	ImageAdder_MJ imgAdd_Mj;
	imgAdd_Mj.Init();
	ImageAdder_WT imgAdd_Wt;
	imgAdd_Wt.Init();
	MG_GAME->Init();
	MG_CAMERA->Init();
	MG_SCENE->init();
	MG_GMOBJ->Init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	//SCENE->release();
	//SAFE_DELETE(_astar);
}

void mainGame::update()
{
	gameNode::update();
	MG_TIME->update(60.0f);
	MG_SCENE->update();

	MG_GMOBJ->Update(MG_TIME->getElapsedTime(), MG_TIME->getWorldTime());
	MG_GMOBJ->LateUpdate();

	MG_CAMERA->Update(MG_TIME->getElapsedTime(), MG_TIME->getWorldTime());
	//SCENE->update();
	//ANIMATION->update();
	//EFFECT->update();
	//_astar->update();
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

	//백버퍼의 내용을 HDC그린다.(건드리지 말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}