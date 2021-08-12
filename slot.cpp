#include "framework.h"
#include "slot.h"

slot::slot() {}
slot::~slot() {}

HRESULT slot::Init()
{
	LAYER::UIButton;

	//setButton();

	return S_OK;
}

void slot::Update(float deltaTime, float worldTime)
{
}

void slot::LateUpdate()
{
}

void slot::BackRender(HDC _hdc)
{
}

void slot::Render(HDC _hdc)
{
}

void slot::FrontRender(HDC _hdc)
{
}

void slot::setButton()
{
	//CHeroList_button* dragButton = new CHeroList_button();
	//dragButton->Init();
	//dragButton->m_transform->m_pos = Vector2(WINSIZEX / 2 + 570, WINSIZEY - 880 + i * 100);
	//dragButton->SetButtonSize(50, 50);
	//switch (MG_GAME->GetHero(i)->job)
	//case JOB::Highwayman:
	//	//dragButton->AddSpriteRenderer(IMAGE::highwayman_roster);
	//	break;
	//default:
	//	break;
	//}
	//m_dragButton.push_back(dragButton);
	//MG_GMOBJ->RegisterObj("m_hero_slot_bg", dragButton);

	//bt_slot = new CDragButton();
	//bt_slot->Init();
	//bt_slot->m_transform->m_pos = Vector2(m_collider->rect.l, m_collider->rect.t);
	//bt_slot->SetButtonSize(70, 125);
	//bt_slot->AddSpriteRenderer("torch");
	//MG_GMOBJ->RegisterObj("bt_inven_dragButton", bt_slot);


}
