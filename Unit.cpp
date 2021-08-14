#include "framework.h"
#include "Unit.h"

Unit::Unit() {
    unitType = UNITTYPE::NONE;
}
Unit::~Unit() {}

HRESULT Unit::Init()
{
    return S_OK;
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
    if (isSelected == true)
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

}

void Unit::Release()
{
    GameObject::Release();
}

void Unit::SetMemberOverlay()
{


	HPbar_back.m_img = MG_IMAGE->findImage("HP_empty");
	HPbar_front.m_img = MG_IMAGE->findImage("HP_full");

}

void Unit::showSelMember(HDC _hdc)
{
	selectedMem.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - 87,
		m_transform->m_pos.y - 78);

	selectedMem.m_img->render(_hdc, &selectedMem.m_trans);
	//targetedMem.m_img->render(_hdc, &targetedMem.m_trans);
}

void Unit::showHpBar(HDC _hdc)
{
	//Hp, strs bar
	HPbar_back.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - 50,
		m_transform->m_pos.y + 15);
	HPbar_front.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - 50,
		m_transform->m_pos.y + 15);

	HPbar_back.m_img->render(_hdc, &HPbar_back.m_trans);
	HPbar_front.m_img->render(_hdc, &HPbar_front.m_trans);
}