#include"framework.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	MG_CAMERA->Init();
	MG_SCENE->init();
	MG_GMOBJ->init();
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
	MG_SCENE->Render(getMemDC());
	MG_GMOBJ->BackRender(getMemDC());
	MG_GMOBJ->Render(getMemDC());
	MG_GMOBJ->FrontRender(getMemDC());
	//==============================================

	MG_TIME->render(getMemDC());

	MG_CAMERA->Render(getMemDC());


	//������� ������ HDC�׸���.(�ǵ帮�� ����.)
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

