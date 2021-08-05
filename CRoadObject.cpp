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
    
}

void CRoadObject::getMapInfo(int a1, int a2, int a3)
{
}

void CRoadObject::setRoadObj()
{
}

void CRoadObject::Interaction_treassure(CHero* member)
{
}

void CRoadObject::Interaction_trap(CHero* member)
{
}

void CRoadObject::Interaction_battle(CParty* party)
{
}
