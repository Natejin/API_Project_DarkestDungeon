#include "framework.h"
#include "effectTest.h"

effectTest::effectTest()
{
}

effectTest::~effectTest()
{
}

HRESULT effectTest::init()
{

	MG_IMAGE->addImage("���", "images/�糪.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	////��������Ʈ �̹���
	//IMAGE->addImage("����", "images/explosion.bmp", 832, 62, true, RGB(255, 0, 255));
	//IMAGE->addImage("����1", "images/explosion1.bmp", 4355,135, true, RGB(255, 0, 255));


	//_effect = new effect;
	//_effect->init(IMAGE->findImage("����"), 32, 62, 1, 0.5f);


	//_effect1 = new effect;
	//_effect1->init(IMAGE->findImage("����1"), 335, 135, 1, 0.4f);

	count = 0;
	MG_EFFECT->addEffect("����", "images/explosion.bmp", 832, 62, 32, 62, 1, 0.5f, 100);
	MG_EFFECT->addEffect("����1", "images/explosion1.bmp", 4355, 135, 335, 135, 1, 0.3f, 100);
	return S_OK;
}

void effectTest::release()
{/*
	SAFE_DELETE(_effect);
	SAFE_DELETE(_effect1);*/
}

void effectTest::update()
{
	if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
	{
		//_effect->startEffect(m_ptMouse.x, m_ptMouse.y);
		MG_EFFECT->play("����", g_ptMouse.x, g_ptMouse.y);
	}
	if (MG_INPUT->isOnceKeyDown(VK_RBUTTON))
	{
		//_effect1->startEffect(m_ptMouse.x, m_ptMouse.y);
		MG_EFFECT->play("����1", g_ptMouse.x, g_ptMouse.y);
	}


	count++;

	if (count % 10 == 0)
	{
		MG_EFFECT->play("����", MG_RND->getFromIntTo(100, 300), MG_RND->getFromIntTo(100, 300));
	}


	/*_effect->update();
	_effect1->update();*/
}

void effectTest::render()
{
	//IMAGE->render("���", getMemDC());
	//_effect->render();
	//_effect1->render();
}
