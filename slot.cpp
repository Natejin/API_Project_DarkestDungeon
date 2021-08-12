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

	m_itemInfo = nullptr;
	return S_OK;
}

void CButton_SlotItem::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->IsDownLMB())
		{
			if (m_itemInfo != nullptr && !m_invenSys->isDragging)
			{
				//m_invenSys->dummySlot->m_spriteRenderer->SetImage(m_spriteRenderer->GetImage());
				m_invenSys->StartDragItem(this);
			}
		}
	}

	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->IsUpLMB())
		{
			if (m_invenSys->isDragging)
			{
				//m_invenSys->dummySlot->m_spriteRenderer->SetImage(m_spriteRenderer->GetImage());
				m_invenSys->EndDragItem(this);
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

		sprintf_s(str, "%d", m_itemInfo->m_count);
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



void CButton_SlotItem::AddItem(CItemInfo* _iteminfo)
{
	m_itemInfo = _iteminfo;
	m_spriteRenderer->SetImage(_iteminfo->m_imgData);
}

void CButton_SlotItem::SwapItem(CButton_SlotItem* _slot)
{
	if (_slot->m_itemInfo == nullptr)
	{
		_slot->m_itemInfo = m_itemInfo;
		m_itemInfo = nullptr;
		_slot->m_spriteRenderer->SetImage(_slot->m_itemInfo->m_imgData);
		m_spriteRenderer->SetImage();
	}
	else {
		auto itemInfo = m_itemInfo;
		m_itemInfo = _slot->m_itemInfo;
		_slot->m_itemInfo = itemInfo;


		_slot->m_spriteRenderer->SetImage(_slot->m_itemInfo->m_imgData);
		m_spriteRenderer->SetImage(m_itemInfo->m_imgData);
	}
}

void CButton_SlotItem::RemoveItem()
{
	m_itemInfo = nullptr;
}
