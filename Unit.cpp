#include "framework.h"
#include "Unit.h"
#include "CAnimator.h"
Unit::Unit() 
{
    m_transform->m_pivot = Vector2(0.5, 1);
}
Unit::~Unit() {}

HRESULT Unit::Init()
{
    targetPos = Vector2(0,0);
    movePosMode = false;;
    movePosSpeed = 10;

    showDamageCount1 = new CAnimator(m_transform);
    showDamageCount1->AddImageFrame(IMAGE::NumberBlack);
    showDamageCount1->AddImageFrame(IMAGE::NumberRed);
    showDamageCount1->AddImageFrame(IMAGE::NumberGreen);
    showDamageCount1->customPos = Vector2(20, -200);
    showDamageCount1->useCustomPos = true;
    showDamageCount1->SetIndex(1);

    showDamageCount10 = new CAnimator(m_transform);
    showDamageCount10->AddImageFrame(IMAGE::NumberBlack);
    showDamageCount10->AddImageFrame(IMAGE::NumberRed);
    showDamageCount10->AddImageFrame(IMAGE::NumberGreen);
    showDamageCount10->customPos = Vector2(-20, -200);
    showDamageCount10->useCustomPos = true;
    showDamageCount10->SetIndex(1);
    showCurWordTime = 0;
    showWordCoolTime = 4;
    wordSpeed = 0.5;

    num1Count = 5;
    num10Count = 3;
    spTest = new CSpriteRenderer(IMAGE::NumberBlack, m_transform);
    return S_OK;
}

void Unit::ShowWordCount(int count, NumCorType color)
{
    num1Count = count % 10;
    num10Count = count / 10;
    showDamageCount1->SetIndex((int)color);
    showDamageCount10->SetIndex((int)color);
    showWord = true;
    showCurWordTime = MG_TIME->getWorldTime() + showWordCoolTime;
    showDamageCount10->customPos = Vector2(-18, -250);
    showDamageCount1->customPos = Vector2(18, -250);
    transparent = 255;
}

void Unit::Update(float deltaTime, float worldTime)
{
    if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
    {
        if (MG_INPUT->IsDownLMB())
        {
            if (canTriggerDown)
            {
                m_triggerWhenDown(m_partyIndex);
            }
        }
    }

    if (movePosMode)
    {
        m_transform->m_pos += (targetPos - m_transform->m_pos).Normalize() * movePosSpeed;
    }

    if (showWord)
    {


        if (showCurWordTime > worldTime)
        {
            showDamageCount10->customPos.x -= sin(worldTime * 10) *wordSpeed ;
            showDamageCount1->customPos.x -= sin(worldTime * 10) * wordSpeed ;
            showDamageCount10->customPos.y -= wordSpeed;
            showDamageCount1->customPos.y -= wordSpeed;
            if (showCurWordTime < worldTime + 2)
            {
                if (transparent > 1)
                {
                    transparent -= 2;
                }
            }
           
        }
        else {
            showWord = false;
        }
    }
    
}

void Unit::LateUpdate()
{
}

void Unit::BackRender(HDC _hdc)
{
}

void Unit::Render(HDC _hdc)
{
}

void Unit::FrontRender(HDC _hdc)
{
    if (isSelected)
    {
        showSelMember(_hdc);
    }
   


    showHpBar(_hdc);

    if (m_collider)
    {
        if (MG_INPUT->isToggleKey(VK_TAB))
        {
            RectangleMake(_hdc, m_collider->rect, m_transform->m_pos - MG_CAMERA->GetPos());
        }
    }

    //spTest->Render(_hdc);
    if (showWord)
    {
        showDamageCount1->AlphaFrameRender(_hdc,transparent, num1Count);
        showDamageCount10->AlphaFrameRender(_hdc, transparent, num10Count);
       
    }
}

void Unit::Release()
{
    GameObject::Release();
}

void Unit::SetMemberOverlay()
{
    selectedMem.m_img = MG_IMAGE->findImage(IMAGE::Target_Selected1);

    ImageData temp;
    for (int i = 0; i < 10; i++)
    {
        temp.m_img = MG_IMAGE->findImage("HP_empty");
        HPbarBack.push_back(temp);
        temp.m_img = MG_IMAGE->findImage("HP_full");
        HPbarFront.push_back(temp);
    }
}

bool Unit::GetCorpse()
{
    return false;
}

void Unit::showSelMember(HDC _hdc)
{
	selectedMem.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - 87,
		m_transform->m_pos.y - 78);

	selectedMem.m_img->render(_hdc, &selectedMem.m_trans);
}

void Unit::showHpBar(HDC _hdc)
{
    ImageData temp;
    for (size_t i = 0; i < HPbarBack.size(); i++)
    {
        HPbarBack[i].m_trans.m_pos = Vector2(
            m_transform->m_pos.x - 50 + 10 * i,
            m_transform->m_pos.y + 15);
        HPbarBack[i].m_img->render(_hdc, &HPbarBack[i].m_trans);
    }

    float a = ((float)getMaxHP() - (float)getHP()) / (float)getMaxHP();
    int percent = 0;
    if (a >= 1.f)
    {
        percent = 0;
    }
    else if (a == 0.f) 
    {
        percent = 10;
    }
    else 
    {
        percent = 11 - a * 10;
    }

    for (size_t i = 0; i < percent; i++)
    {
        HPbarFront[i].m_trans.m_pos = Vector2(
            m_transform->m_pos.x - 50 + 10 * i,
            m_transform->m_pos.y + 15);

        HPbarFront[i].m_img->render(_hdc, &HPbarFront[i].m_trans);
    }
}

UNITTYPE Unit::GetUnitType()
{
    return m_unitType;
}

int Unit::GetSpeed()
{
    return 0;
}

int Unit::getHP()
{
    return 0;
}

bool Unit::reduceHP(int hp)
{
    return false;
}

void Unit::increaseHP(int hp)
{
}

int Unit::getSPD()
{
    return 0;
}

int Unit::GetPartyIndex()
{
    return m_partyIndex;
}

void Unit::SetPartyIndex(int pos)
{
    m_partyIndex = pos;
}

int Unit::GetPartyPos()
{
    return m_partyPos;
}

void Unit::SetPartyPos(int pos)
{
    m_partyPos = pos;
}

int Unit::getResist(int index)
{
    return 0;
}

bool Unit::getAttribute(int index)
{
    return false;
}

void Unit::setHP(int hp)
{
}

int Unit::getMaxHP()
{
    return 0;
}

bool Unit::GetAffliction()
{
    return false;
}

bool Unit::GetAlive()
{
    return false;
}

void Unit::setSPD(int spd)
{
}

void Unit::setResist(int index, bool val)
{
}

void Unit::setAttribute(int index, bool val)
{
}