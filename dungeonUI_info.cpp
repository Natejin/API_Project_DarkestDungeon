#include "framework.h"
#include "dungeonUI_info.h"
#include "CHero.h"
#include "CParty.h"

dungeonUI_info::dungeonUI_info() {}
dungeonUI_info::~dungeonUI_info() {}

HRESULT dungeonUI_info::Init()
{
    CHero* defalt = new CHero;
    defalt = pos1Hero;
    showWhichHero(defalt);

    return S_OK;
}

void dungeonUI_info::Update(float deltaTime, float worldTime)
{
}

void dungeonUI_info::LateUpdate()
{
}

void dungeonUI_info::BackRender(HDC _hdc)
{
}

void dungeonUI_info::Render(HDC _hdc)
{
}

void dungeonUI_info::FrontRender(HDC _hdc)
{
}

void dungeonUI_info::Release()
{
}


//==================================



void dungeonUI_info::setHeroJob()
{

}

void dungeonUI_info::setInfoImage()
{
}

void dungeonUI_info::setSkillIcon()
{
}

void dungeonUI_info::showWhichHero(CHero* _hero)
{
}
