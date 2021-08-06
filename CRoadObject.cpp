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
    temp.m_trans.m_pos = Vector2(700, 600);
    roadObj.push_back(temp);

    temp.m_trans.m_pos = Vector2(1000, 600);
    roadObj.push_back(temp);

    setRoadObj();

}

void CRoadObject::getMapInfo(int a1, int a2, int a3)
{

}

void CRoadObject::setRoadObj()
{
    CTransform settingObjArea; 
    settingObjArea.m_pos.x = ( (ROADSIZEX - ROADSIZEX / 2) * 4 / 3);
    DividedArea.push_back(settingObjArea);

    settingObjArea.m_pos.x += (ROADSIZEX / 6 * 4 / 3);
    DividedArea.push_back(settingObjArea);
    
    settingObjArea.m_pos.x += (ROADSIZEX / 6 * 4 / 3);
    DividedArea.push_back(settingObjArea);

    for (int i = 0; i < roadObj.size(); i++)
    {
        roadObj[i].m_trans.m_pos.x = MG_RND->getFromIntTo(0, DividedArea[i].m_pos.x);
    }

}

//TODO all Hero Check, randomGetStress
void CRoadObject::reach_InteractionArea(CParty* _party)
{
    //update�� �־ �ڵ����� ���� �� ���� �κ��� ��
    party = _party;
    float poxX = party->GetHero(0)->m_transform->m_pos.x;
    float width = party->GetHero(0)->m_spriteRenderer->GetImage()->getFrameWidth();
    //�ش� �ݰ濡 �����Ͽ� Ŭ���� ��ȣ�ۿ�
    if (roadObj[0].Collision(poxX + width + 40))
    {
        if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
        {
            Interaction_treassure();
        }
    }

    //ĳ���Ϳ� �浹�ؾ߸� ��ȣ�ۿ� �߻�
    if (roadObj[1].Collision(poxX + width + 40))
    {
        //���� � ��Ȳ�� �߻������� ���� �ʰ� �����ϸ鼭 ���ϰ� ����
        Interaction_trap();
        //Interaction_battle();
    }
}

void CRoadObject::Interaction_treassure()
{
    //�������ڸ� �����ٴ� ������� ������ �ϼ�
    roadObj[0].m_img = MG_IMAGE->findImage("mon1");
    roadObj[0].m_img->setWidth(100);
    roadObj[0].m_img->setHeight(100);

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
        //���ڰ� ����ٴ� �̹����� ��� �߻�
    }

}

void CRoadObject::Interaction_trap()
{
    //��ü�� �õ��� ���
    if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
    {
        roadObj[1].m_img = MG_IMAGE->findImage("���ȭ��");
        roadObj[1].m_img->setWidth(100);
        roadObj[1].m_img->setHeight(100);
    }
    //��ü�����ʰ� �ݰ泻�� �浹�� ���
    //����, ��, ��Ʈ������ ü�°���

    else if (roadObj[1].Collision(party->GetHero(0)->m_transform->m_pos.x + party->GetHero(0)->m_spriteRenderer->GetImage()->getFrameWidth() - 40))
    {
        if (MG_RND->getInt(5) > 0)
        {  
            //���� �� Hero ���¿� �ٷ� ������ �� �ִ� �Լ��� ���� �� 
            //party->GetHero(0)->;
            roadObj[1].m_img = MG_IMAGE->findImage("ruins_room1");
            roadObj[1].m_img->setWidth(100);
            roadObj[1].m_img->setHeight(100);

            party->GetHero(0)->setStress(party->GetHero(0)->getStress() + 10);
        }
    }
}

void CRoadObject::Interaction_battle()
{
    //��Ʋ�ý��� ���� �� �߰�

    roadObj[1].m_img = MG_IMAGE->findImage("�ϸ�");
    roadObj[1].m_img->setWidth(100);
    roadObj[1].m_img->setHeight(100);
}

void CRoadObject::showDividedArea(HDC _hdc)
{

}
