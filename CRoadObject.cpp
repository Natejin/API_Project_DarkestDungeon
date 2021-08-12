#include "framework.h"
#include "CRoadObject.h"
#include "CParty.h"
#include "CHero.h"
#include "ImageData.h"
#include "CButton.h"

CRoadObject::CRoadObject() {}
CRoadObject::~CRoadObject() {}

HRESULT CRoadObject::Init()
{
    m_layer = LAYER::BackGround;
    
    isCollision = false;

    setRoadObjIMG();
    setButton();

    return S_OK;
}

void CRoadObject::Update(float deltaTime, float worldTime)
{
    Interaction_collision();
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

    char str[256];
    string strFrame;
    SetBkMode(_hdc, TRANSPARENT);
    SetTextColor(_hdc, RGB(255, 255, 255));

    sprintf_s(str, "isCollision: %d", isCollision);
    TextOut(_hdc, 0, 200, str, strlen(str));
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


void CRoadObject::setButton()
{
    bt_treasure = new CButton_move();
    bt_treasure->m_transform->m_pos = m_roadObj[0].m_trans.m_pos;
    bt_treasure->SetButtonSize(100, 100);
    bt_treasure->AddSpriteRenderer ("button");
    bt_treasure->SetTriggerWhenClick(this, &CRoadObject::Interaction_treassure);
    MG_GMOBJ->RegisterObj("RoadObj_treasure", bt_treasure);

    bt_trap = new CButton_move();
    bt_trap->m_transform->m_pos = m_roadObj[1].m_trans.m_pos;
    bt_trap->SetButtonSize(100, 100);
    bt_trap->AddSpriteRenderer ("button");
    bt_trap->SetTriggerWhenClick(this, &CRoadObject::Interaction_trap);
    MG_GMOBJ->RegisterObj("RoadObj_trap", bt_trap);
}

void CRoadObject::setRoadObjIMG()
{
    ImageData temp;
    temp.m_img = MG_IMAGE->findImage("treasure");
    temp.m_trans.m_pos.y = 600;
    m_roadObj.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("trap");
    temp.m_trans.m_pos.y = 600;
    m_roadObj.push_back(temp);

    temp.m_img = MG_IMAGE->findImage("enemy");
    temp.m_trans.m_pos.y = 600;
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

    temp.m_pos.x += ROADSIZEX / 6;
    m_SettingArea.push_back(temp);

    isTreasureOpen = false;
    isTrapClear = false;

    for (int i = 0; i < m_roadObj.size(); i++)
    {
        m_roadObj[i].m_trans.m_pos.x = MG_RND->getFromIntTo(m_SettingArea[i].m_pos.x, m_SettingArea[i + 1].m_pos.x);
        //if (i != 0 && m_roadObj[i - 1].m_trans.m_pos.x > m_roadObj[i].m_trans.m_pos.x - 150)
        //{
        //    m_roadObj[i].m_trans.m_pos.x -= 100;
        //}
    }
}

void CRoadObject::Interaction_collision()
{
    ////for test
    //testCollider = new CCollider;
    //testCollider->SetRect(m_roadObj[0].m_trans.m_pos.x - 100, m_roadObj[0].m_trans.m_pos.y, m_roadObj[0].m_trans.m_pos.x + 200, m_roadObj[0].m_trans.m_pos.y - 100);
    //if (testCollider->CheckXCollision(MG_GAME->GetHero(0)->m_transform->m_pos.x + 100))
    //{
    //    isCollision = true;
    //}
    //else isCollision = false;

    //CCollider* _collider = new CCollider;

    ////collision with trap

    ////얘부터 차례대로 디버깅하려면
    //(*_collider).SetRect(m_roadObj[1].m_trans.m_pos.x, m_roadObj[1].m_trans.m_pos.y, m_roadObj[1].m_trans.m_pos.x + 100, m_roadObj[1].m_trans.m_pos.y - 100);
    //if (isTrapClear == false)
    //{
    //    if (_collider->CheckXCollision(MG_GAME->GetHero(0)->m_transform->m_pos.x))
    //    {
    //        Interaction_trap_fail();
    //        isTrapClear == true;
    //    }
    //}

    ////collision with enemyPoint
    //(*_collider).SetRect(m_roadObj[2].m_trans.m_pos.x, m_roadObj[2].m_trans.m_pos.y, m_roadObj[2].m_trans.m_pos.x + 100, m_roadObj[2].m_trans.m_pos.y - 100);
    //if (_collider->CheckXCollision(MG_GAME->GetHero(0)->m_transform->m_pos.x + 100))
    //{
    //    Interaction_battle();
    //}
}

void CRoadObject::Interaction_treassure()
{
    //CCollider* _collider = new CCollider;
    //(*_collider).SetRect(m_roadObj[0].m_trans.m_pos.x - 100, m_roadObj[0].m_trans.m_pos.y, m_roadObj[0].m_trans.m_pos.x + 200, m_roadObj[0].m_trans.m_pos.y - 100);

    ////treasure
    ////touchable when it's collision with Hero(0)
    //if (_collider->CheckXCollision(MG_GAME->GetHero(0)->m_transform->m_pos.x + 100))
    //{
    //    if (isTreasureOpen == false)
    //    {
    //        if (MG_RND->getInt(10) > 0)
    //        {
    //            m_roadObj[0].m_img = MG_IMAGE->findImage("mon1");
    //            m_roadObj[0].m_img->setWidth(100);
    //            m_roadObj[0].m_img->setHeight(100);

    //            int torch = MG_RND->getInt(2);
    //            int food = MG_RND->getInt(2);
    //            int band = MG_RND->getInt(2);

    //            MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + band);
    //            MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + food);
    //            MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + torch);
    //            isTreasureOpen = true;
    //        }
    //        else
    //        {
    //            m_roadObj[0].m_img = MG_IMAGE->findImage("nothing");
    //            isTreasureOpen = true;
    //        }
    //    }
    //}
}

void CRoadObject::Interaction_trap()
{
    //CCollider* _collider = new CCollider;
    //(*_collider).SetRect(m_roadObj[1].m_trans.m_pos.x - 100, m_roadObj[1].m_trans.m_pos.y, m_roadObj[1].m_trans.m_pos.x + 200, m_roadObj[1].m_trans.m_pos.y - 100);

    //if (isTrapClear == false)
    //{
    //    if (_collider->CheckXCollision(MG_GAME->GetHero(0)->m_transform->m_pos.x + 200))
    //    {
    //        if (MG_RND->getInt(4) > 0)
    //        {
    //            Interaction_trap_success();
    //        }
    //        else
    //        {
    //            //tryed but fail
    //            Interaction_trap_fail();
    //        }
    //    }
    //}
}

void CRoadObject::Interaction_trap_fail()
{
	m_roadObj[1].m_img = MG_IMAGE->findImage("mon1");
	m_roadObj[1].m_img->setWidth(100);
	m_roadObj[1].m_img->setHeight(100);
    MG_GAME->GetParty()->GetHero(0)->setStress(MG_GAME->GetParty()->GetHero(0)->getStress() + 10);
    isTrapClear = true;
    
}

void CRoadObject::Interaction_trap_success()
{
    //try to clearTrap and succeed
    m_roadObj[1].m_img = MG_IMAGE->findImage("nothing");
    isTrapClear = true;
}

void CRoadObject::Interaction_battle()
{
	//m_roadObj[2].m_img = MG_IMAGE->findImage("�ϸ�");
	//m_roadObj[2].m_img->setWidth(100);
	//m_roadObj[2].m_img->setHeight(100);
}