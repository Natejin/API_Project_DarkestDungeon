#include "framework.h"
#include "dungeonUI_info.h"
#include "CHero.h"
#include "CParty.h"

dungeonUI_info::dungeonUI_info() {}
dungeonUI_info::~dungeonUI_info() {}

HRESULT dungeonUI_info::Init()
{
    m_layer = LAYER::UI;

    CHero* defalt = new CHero;
    defalt = MG_GAME->GetHero(0);
    showWhichHero(defalt);

    setInfoImage();

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
    for (int i = 0; i < m_heroInfoImage.size(); i++)
    {
        m_heroInfoImage[i].m_img->renderUI(_hdc, &m_heroInfoImage[i].m_trans);
    }
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
    //0~5
    ImageData temp;
    temp.m_img = MG_IMAGE->findImage("vestal_portrait");
    temp.m_trans.m_pos = Vector2(357, 725);
    m_heroInfoImage.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("vestal_skill1");
    temp.m_trans.m_pos = Vector2(585, 732);
    m_heroInfoImage.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("vestal_skill2");
    temp.m_trans.m_pos = Vector2(655, 732);
    m_heroInfoImage.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("vestal_skill3");
    temp.m_trans.m_pos = Vector2(725, 732);
    m_heroInfoImage.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("vestal_skill4");
    temp.m_trans.m_pos = Vector2(795, 732);
    m_heroInfoImage.push_back(temp);

    //moveSkill
    temp.m_img = MG_IMAGE->findImage("ability_move");
    temp.m_trans.m_pos = Vector2(865, 732);
    m_heroInfoImage.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("vestal_armor");
    temp.m_trans.m_pos = Vector2(575, 868);
    m_heroInfoImage.push_back(temp);


}

void dungeonUI_info::setSkillIcon()
{

}

void dungeonUI_info::showWhichHero(CHero* _hero)
{

}
