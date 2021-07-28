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

    MG_SOUND->addSound("카드", "sound/체리.mp3", true, true);
    return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
    if (MG_INPUT->isOnceKeyDown('Q'))
    {
        MG_SOUND->play("카드",1.0f);
    }
    if (MG_INPUT->isOnceKeyDown('S'))
    {
        MG_SOUND->stop("카드");
    }
    if (MG_INPUT->isOnceKeyDown('T'))
    {
        MG_SOUND->resume("카드");
    }
    if (MG_INPUT->isOnceKeyDown('P'))
    {
        MG_SOUND->pause("카드");
    }
}
