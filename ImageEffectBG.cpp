#include "framework.h"
#include "ImageEffectBG.h"

ImageEffectBG::ImageEffectBG()
{
    m_layer = LAYER::UIIndicator;
}

ImageEffectBG::~ImageEffectBG()
{
}

HRESULT ImageEffectBG::Init()
{
    m_transform->m_pivot = Vector2(0, 0);
    AddSpriteRenderer(IMAGE::NONE);
    rndBGIMG.push_back(IMAGE::BattleBG_darkest_dungeon_1);
    rndBGIMG.push_back(IMAGE::BattleBG_darkest_dungeon_2);
    rndBGIMG.push_back(IMAGE::BattleBG_darkestdungeon_wall1);
    rndBGIMG.push_back(IMAGE::BattleBG_darkestdungeon_wall2);
    rndBGIMG.push_back(IMAGE::BattleBG_town_invasion);
    rndBGIMG.push_back(IMAGE::BattleBG_trinket_retention);
    coolTime = 3;
    return S_OK;
}

void ImageEffectBG::Enable()
{
    m_spriteRenderer->SetImage(rndBGIMG[MG_RND->getInt(rndBGIMG.size())]);
    curTime = MG_TIME->getWorldTime() + coolTime;
    isActive = true;
}

void ImageEffectBG::Disable()
{
    isActive = false;
    targetPos = originPos;

}
