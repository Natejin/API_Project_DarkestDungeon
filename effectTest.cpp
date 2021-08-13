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

	MG_IMAGE->addImage("¹è°æ", "images/»ç³ª.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	////Æø¹ßÀÌÆåÆ® ÀÌ¹ÌÁö
	//IMAGE->addImage("Æø¹ß", "images/explosion.bmp", 832, 62, true, RGB(255, 0, 255));
	//IMAGE->addImage("Æø¹ß1", "images/explosion1.bmp", 4355,135, true, RGB(255, 0, 255));


	//_effect = new effect;
	//_effect->init(IMAGE->findImage("Æø¹ß"), 32, 62, 1, 0.5f);


	//_effect1 = new effect;
	//_effect1->init(IMAGE->findImage("Æø¹ß1"), 335, 135, 1, 0.4f);

	count = 0;
	MG_EFFECT->addEffect("Æø¹ß", "images/explosion.bmp", 832, 62, 32, 62, 1, 0.5f, 100);
	MG_EFFECT->addEffect("Æø¹ß1", "images/explosion1.bmp", 4355, 135, 335, 135, 1, 0.3f, 100);
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
		MG_EFFECT->play("Æø¹ß", g_ptMouse.x, g_ptMouse.y);
	}
	if (MG_INPUT->isOnceKeyDown(VK_RBUTTON))
	{
		//_effect1->startEffect(m_ptMouse.x, m_ptMouse.y);
		MG_EFFECT->play("Æø¹ß1", g_ptMouse.x, g_ptMouse.y);
	}


	count++;

	if (count % 10 == 0)
	{
		MG_EFFECT->play("Æø¹ß", MG_RND->getFromIntTo(100, 300), MG_RND->getFromIntTo(100, 300));
	}


	/*_effect->update();
	_effect1->update();*/
}

void effectTest::render()
{
	//IMAGE->render("¹è°æ", getMemDC());
	//_effect->render();
	//_effect1->render();
}
