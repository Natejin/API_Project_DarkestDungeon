#include "framework.h"
#include "slot.h"
#include "CSpriteRenderer.h"
#include "itemInfo.h"
#include "CInventorySystem.h"

CButton_SlotItem::CButton_SlotItem() {}
CButton_SlotItem::~CButton_SlotItem() {}

HRESULT CButton_SlotItem::Init()
{
	LAYER::UIButton;
	m_transform->m_pivot = Vector2(0, 0);
	AddSpriteRenderer();
	AddColliderBox(70,125);

	itemInfo = nullptr;
	return S_OK;
}

void CButton_SlotItem::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->IsDownLMB())
		{
			if (itemInfo != nullptr && m_invenSys->dummySlot->m_spriteRenderer->GetImage() == nullptr)
			{
				m_invenSys->dummySlot->m_spriteRenderer->SetImage(m_spriteRenderer->GetImage());
				m_invenSys->dummySlot->Enable();
			}
		}
	}


}

void CButton_SlotItem::LateUpdate()
{
}

void CButton_SlotItem::BackRender(HDC _hdc)
{

}

void CButton_SlotItem::Render(HDC _hdc)
{

}

void CButton_SlotItem::FrontRender(HDC _hdc)
{

	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
	if (m_spriteRenderer->HasImage())
	{
		m_spriteRenderer->RenderUI(_hdc);


		int k = 0;
		char str[256];
		string strFrame;
		SetBkMode(_hdc, RGB(0, 0, 0));
		SetTextColor(_hdc, RGB(255, 255, 255));

		sprintf_s(str, "%d", itemInfo->m_count);
		TextOut(_hdc, 990 + 70 * slotID.x, 730 + 140 * slotID.y, str, strlen(str));

		/*int quotient;
		quotient = MG_GAME->GetParty()->getTorch() / torchLimit + 1;
		sprintf_s(str, "quotient : %d", quotient);
		TextOut(_hdc, 0, 400, str, strlen(str));

		int remainder;
		remainder = MG_GAME->GetParty()->getTorch() % torchLimit;
		sprintf_s(str, "remainder : %d", remainder);
		TextOut(_hdc, 0, 420, str, strlen(str));

		sprintf_s(str, "filledSlot : %d", filledSlot);
		TextOut(_hdc, 0, 440, str, strlen(str));*/

	}
}

void CButton_SlotItem::setButton()
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

void CButton_SlotItem::AddItem(CItemInfo* _iteminfo)
{
	itemInfo = _iteminfo;
	m_spriteRenderer->SetImage(_iteminfo->m_imgData);
}

void CButton_SlotItem::RemoveItem()
{
	itemInfo = nullptr;
}
