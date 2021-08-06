#include "framework.h"
#include "CRoadObject.h"
#include "CParty.h"
#include "CHero.h"
#include "CAnimator.h"
#include "CCollider.h"

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
    for (int i = 0; i < m_roadObj.size(); i++)
    {
        m_roadObj[i].m_img->render(_hdc, &m_roadObj[i].m_trans);
    }
}

void CRoadObject::FrontRender(HDC _hdc)
{
}

void CRoadObject::Release()
{
    for (int i = 0; i < m_roadObj.size(); i++)
    {
        m_roadObj[i].m_img = nullptr;
    }
}


//==================================


void CRoadObject::setRoadObjIMG()
{
    ImageData temp;
    temp.m_img = MG_IMAGE->findImage("crusader");

    temp.m_img->setHeight(100);
    temp.m_img->setWidth(100);
    temp.m_trans.m_pos.y = 600;

    m_roadObj.push_back(temp);
    m_roadObj.push_back(temp);

    setRoadObj();

}

void CRoadObject::getMapInfo(int a1, int a2, int a3)
{

}

void CRoadObject::setRoadObj()
{
    CTransform temp;

    temp.m_pos.x = ROADSIZEX / 6;
    m_SettingArea.push_back(temp);

    temp.m_pos.x += ROADSIZEX / 6;
    m_SettingArea.push_back(temp);

    temp.m_pos.x += ROADSIZEX / 6;
    m_SettingArea.push_back(temp);

    isTreasureOpen = false;

    for (int i = 0; i < m_roadObj.size(); i++)
    {
        m_roadObj[i].m_trans.m_pos.x = MG_RND->getFromIntTo(m_SettingArea[i].m_pos.x, m_SettingArea[i + 1].m_pos.x);
    }
}

void CRoadObject::reach_InteractionArea(CParty* _party)
{
    party = _party;
    CCollider* _collider = new CCollider;
    _collider->SetTrans(&m_roadObj[0].m_trans);

    //해당 반경에 진입하여 클릭시 상호작용
    if (_collider->CheckColliderBoxWithPoint(party->GetHero(0)->m_animator->GetCurImage()->getX() + party->GetHero(0)->m_animator->GetCurImage()->getFrameWidth() + 40))
    {
        if (MG_INPUT->isOnceKeyDown(VK_LBUTTON) && isTreasureOpen == false)
        {
            isTreasureOpen = true;
            Interaction_treassure();
        }
    }

    _collider->SetTrans(&m_roadObj[1].m_trans);
    
    //캐릭터와 충돌해야만 상호작용 발생
    if (_collider->CheckColliderBoxWithPoint(party->GetHero(0)->m_animator->GetCurImage()->getX() + party->GetHero(0)->m_animator->GetCurImage()->getFrameWidth() + 40))
    {
        //둘중 어떤 상황이 발생할지는 추후 맵과 연결하면서 상세하게 세팅
        //Interaction_battle();
        Interaction_trap();
    }
}

void CRoadObject::Interaction_treassure()
{
    //보물상자를 열었다는 약식적인 구현만 완성
    m_roadObj[0].m_img = MG_IMAGE->findImage("mon1");
    m_roadObj[0].m_img->setWidth(100);
    m_roadObj[0].m_img->setHeight(100);

    int torch = MG_RND->getInt(2);
    int food = MG_RND->getInt(2);
    int band = MG_RND->getInt(2);

    if (MG_RND->getInt(9) > 0)
    {
        party->setBandage(party->getBandage() + band);
        party->setFood(party->getFood() + food);
        party->setTorch(party->getTorch() + torch);
    }
    else
    {
        //상자가 비었다는 이미지가 잠시 발생
    }
}

void CRoadObject::Interaction_trap()
{ 
    CCollider* _collider = new CCollider;
    _collider->SetTrans(&m_roadObj[1].m_trans);

    //해체를 시도한 경우
    if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
    {
        m_roadObj[1].m_img = MG_IMAGE->findImage("배경화면");
        m_roadObj[1].m_img->setWidth(100);
        m_roadObj[1].m_img->setHeight(100);
    }

    //해체하지않고 반경내로 충돌한 경우
    //출혈, 독, 스트레스와 체력감소
    else if (_collider->CheckColliderBoxWithPoint(party->GetHero(0)->m_animator->GetCurImage()->getX() + party->GetHero(0)->m_animator->GetCurImage()->getFrameWidth() + 40))
    {
        if (MG_RND->getInt(5) > 0)
        {
            //병합 후 Hero 상태에 바로 접근할 수 있는 함수를 만들 것 
            //party->GetHero(0)->;
            m_roadObj[1].m_img = MG_IMAGE->findImage("ruins_room1");
            m_roadObj[1].m_img->setWidth(100);
            m_roadObj[1].m_img->setHeight(100);
            party->GetHero(0)->setStress(party->GetHero(0)->getStress() + 10);
        }
    }
}

void CRoadObject::Interaction_battle()
{
    //배틀시스템 구현 후 추가
    m_roadObj[1].m_img = MG_IMAGE->findImage("록맨");
    m_roadObj[1].m_img->setWidth(100);
    m_roadObj[1].m_img->setHeight(100);
}


void CRoadObject::showDividedArea(HDC _hdc)
{

}