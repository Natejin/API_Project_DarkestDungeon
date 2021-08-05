#include "framework.h"
#include "CRoadObject.h"
#include "CParty.h"
#include "CHero.h"

CRoadObject::CRoadObject() {}
CRoadObject::~CRoadObject() {}

HRESULT CRoadObject::Init()
{
    m_layer = LAYER::BackGround;
    setRoadObjIMG();
    return S_OK;
}

void CRoadObject::Update(float deltaTime, float worldTime)
{

}

void CRoadObject::LateUpdate()
{
}

void CRoadObject::BackRender(HDC _hdc)
{

}

void CRoadObject::Render(HDC _hdc)
{
    for (int i = 0; i < roadObj.size(); i++)
    {
        roadObj[i].m_img->render(_hdc, &roadObj[i].m_trans);
    }
}

void CRoadObject::FrontRender(HDC _hdc)
{
}

void CRoadObject::Release()
{
    for (int i = 0; i < roadObj.size(); i++)
    {
        roadObj[i].m_img = nullptr;
    }
}


//==================================


void CRoadObject::setRoadObjIMG()
{
    ImageData temp;
    temp.m_img = MG_IMAGE->findImage("crusader");
    temp.m_img->setHeight(100);
    temp.m_img->setWidth(100);
    temp.m_trans.m_pos = Vector2(500, 600);
    roadObj.push_back(temp);
    
    Rect rc;
    rc.SetRect(500, 600, 600, 700);
    roadObj_rc.push_back(rc);

    temp.m_trans.m_pos = Vector2(1000, 600);
    roadObj.push_back(temp);

}

void CRoadObject::getMapInfo(int a1, int a2, int a3)
{

}

void CRoadObject::setRoadObj()
{

}

void CRoadObject::setRoadObj(CBackground* bg)
{
    CTransform settingObjArea; 
    settingObjArea.m_pos.x = (bg->getSceneSize() / 6 * 4 / 3);
    DividedArea.push_back(settingObjArea);
    settingObjArea.m_pos.x += (bg->getSceneSize() / 6 * 4 / 3);
    DividedArea.push_back(settingObjArea);
    settingObjArea.m_pos.x += (bg->getSceneSize() / 6 * 4 / 3);
    DividedArea.push_back(settingObjArea);

}

void CRoadObject::reach_InteractionArea(CParty* _party)
{
    //if (roadObj[0].Collision(_party->GetHero(0)->m_collider()))
}

void CRoadObject::Interaction_treassure()
{
}

void CRoadObject::Interaction_trap()
{
}

void CRoadObject::Interaction_battle()
{
}


void CRoadObject::showDividedArea(HDC _hdc)
{

}
