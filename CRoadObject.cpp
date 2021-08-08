#include "framework.h"
#include "CRoadObject.h"
#include "CParty.h"
#include "CHero.h"
#include "CAnimator.h"
#include "CCollider.h"
#include "ImageData.h"

#include "CButton.h"

CRoadObject::CRoadObject() {}
CRoadObject::~CRoadObject() {}

HRESULT CRoadObject::Init()
{
    m_layer = LAYER::BackGround;

    colliderCheck = false;

    setRoadObjIMG();
    setButton();

    return S_OK;
}

void CRoadObject::Update(float deltaTime, float worldTime)
{
    //Vector2 PointToVector;
    //PointToVector.x = m_ptMouse.x - MG_CAMERA->getTargerPivot().x + MG_CAMERA->getCameraPos().x;
    //PointToVector.y = m_ptMouse.y - MG_CAMERA->getTargerPivot().y + MG_CAMERA->getCameraPos().y;

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


void CRoadObject::setButton()
{
    bt_treasure = new CButton_move();
    bt_treasure->m_transform->m_pos = m_roadObj[0].m_trans.m_pos;
    bt_treasure->SetButtonSize(100, 100);
    bt_treasure->m_image = MG_IMAGE->findImage("button");
    bt_treasure->SetTriggerWhenClick(this, &CRoadObject::Interaction_treassure);
    MG_GMOBJ->RegisterObj("RoadObj_treasure", bt_treasure);

    bt_trap = new CButton_move();
    bt_trap->m_transform->m_pos = m_roadObj[1].m_trans.m_pos;
    bt_trap->SetButtonSize(100, 100);
    bt_trap->m_image = MG_IMAGE->findImage("button");
    bt_trap->SetTriggerWhenClick(this, &CRoadObject::Interaction_trap_success);
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
    //랜덤맵으로 생성된 정보를 받아와야 함
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

    for (int i = 0; i < m_roadObj.size(); i++)
    {
        m_roadObj[i].m_trans.m_pos.x = MG_RND->getFromIntTo(m_SettingArea[i].m_pos.x, m_SettingArea[i + 1].m_pos.x);
        //너무 가까운 경우를 방지하기 위함
        //if (i != 0 && m_roadObj[i - 1].m_trans.m_pos.x > m_roadObj[i].m_trans.m_pos.x - 150)
        //{
        //    m_roadObj[i].m_trans.m_pos.x -= 100;
        //}
    }
}

void CRoadObject::Interaction_treassure()
{
    //어떤 이유에서인지 가끔 버튼 적용이 되지 않음
    //if (bt_treasure->m_rect.CheckCollisionWithPoint(party->GetHero(0)->m_transform->m_pos.x + 300))
    //{
        colliderCheck = true;
		if (isTreasureOpen == false)
		{
			if (MG_RND->getInt(10) > 0)
			{
				//보물상자를 열었다는 약식적인 구현만 완성
				m_roadObj[0].m_img = MG_IMAGE->findImage("mon1");
				m_roadObj[0].m_img->setWidth(100);
				m_roadObj[0].m_img->setHeight(100);

				int torch = MG_RND->getInt(2);
				int food = MG_RND->getInt(2);
				int band = MG_RND->getInt(2);

				party->setBandage(party->getBandage() + band);
				party->setFood(party->getFood() + food);
				party->setTorch(party->getTorch() + torch);
				isTreasureOpen = true;
			}
			else
			{
				m_roadObj[0].m_img = MG_IMAGE->findImage("nothing");
				isTreasureOpen = true;
			}
		}
    //}
}

void CRoadObject::Interaction_trap_success()
{
    //해체성공
    m_roadObj[1].m_img = MG_IMAGE->findImage("nothing");
}

void CRoadObject::Interaction_trap_fail()
{
    //해체하지않고 반경내로 충돌한 경우
    //출혈, 독, 스트레스와 체력감소

    CCollider* _collider = new CCollider;
    (*_collider).SetRectAndTrans(&m_roadObj[1].m_trans, 100, 100);

    if (_collider->CheckXCollision(party->GetHero(0)->m_transform->m_pos.x + 300))
    {
       m_roadObj[1].m_img = MG_IMAGE->findImage("ruins_room1");
       m_roadObj[1].m_img->setWidth(100);
       m_roadObj[1].m_img->setHeight(100);
       party->GetHero(0)->setStress(party->GetHero(0)->getStress() + 10);
    }
}

void CRoadObject::Interaction_battle()
{
    //배틀시스템 구현 후 추가
    m_roadObj[2].m_img = MG_IMAGE->findImage("록맨");
    m_roadObj[2].m_img->setWidth(100);
    m_roadObj[2].m_img->setHeight(100);

    //바로 배틀씬 진입
}


void CRoadObject::showDividedArea(HDC _hdc)
{

}