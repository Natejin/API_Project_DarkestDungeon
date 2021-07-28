#include "framework.h"
#include "soundTest.h"

soundTest::soundTest()
{
}

soundTest::~soundTest()
{
}

HRESULT soundTest::init()
{

    MG_SOUND->addSound("ī��", "sound/ü��.mp3", true, true);
    return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
    if (MG_INPUT->isOnceKeyDown('Q'))
    {
        MG_SOUND->play("ī��",1.0f);
    }
    if (MG_INPUT->isOnceKeyDown('S'))
    {
        MG_SOUND->stop("ī��");
    }
    if (MG_INPUT->isOnceKeyDown('T'))
    {
        MG_SOUND->resume("ī��");
    }
    if (MG_INPUT->isOnceKeyDown('P'))
    {
        MG_SOUND->pause("ī��");
    }
}
