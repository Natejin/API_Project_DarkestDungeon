#include "framework.h"
#include "CRoadObject.h"

CRoadObject::CRoadObject() {}
CRoadObject::~CRoadObject() {}

HRESULT CRoadObject::Init()
{
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
}

void CRoadObject::FrontRender(HDC _hdc)
{
}

void CRoadObject::Release()
{
}


//==================================


void CRoadObject::setRoadObjIMG()
{
    Image* temp;
    temp = MG_IMAGE->findImage("");
    img_object.push_back(temp);

    CTransform ts_temp;
    ts_temp.m_pos = Vector2(600, 500);

}

void CRoadObject::getMapInfo(int a1, int a2, int a3)
{
}

void CRoadObject::setRoadObj()
{
}

void CRoadObject::Interaction_tressure(CHero* member)
{
}

void CRoadObject::Interaction_trap(CHero* member)
{
}

void CRoadObject::Interaction_battle(CParty* party)
{
}
