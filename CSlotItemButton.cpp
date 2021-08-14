#include "framework.h"
#include "CSlotItemButton.h"
#include "CSpriteRenderer.h"
#include "Info_Item.h"
#include "CInventorySystem.h"

CSlotItemButton::CSlotItemButton() {}
CSlotItemButton::~CSlotItemButton() {}

HRESULT CSlotItemButton::Init()
{
	LAYER::UIButton;
	m_transform->m_pivot = Vector2(0, 0);
	AddSpriteRenderer();
	AddColliderBox(70, 125);

	m_itemInfo = nullptr;
	return S_OK;
}

void CSlotItemButton::Update(float deltaTime, float worldTime)
{
	checkCount();


	//use item
	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->IsDownRMB())
		{
			useSlotItem();
		}
	}

	//burida
	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->isStayKeyDown(VK_SHIFT))
		{
			if (MG_INPUT->IsDownLMB())
			{
				dumpSlotItem();
			}
		}
	}

	//drag
	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
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

	if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
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

void CSlotItemButton::LateUpdate()
{
}

void CSlotItemButton::BackRender(HDC _hdc)
{
}

void CSlotItemButton::Render(HDC _hdc)
{
}

void CSlotItemButton::FrontRender(HDC _hdc)
{
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
	if (m_itemInfo != nullptr)
	{
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
		}
	}
}


//==================================


void CSlotItemButton::AddItem(CInfo_Item* _iteminfo)
{
	m_itemInfo = _iteminfo;
	m_spriteRenderer->SetImage(_iteminfo->m_imgData);
}

void CSlotItemButton::SwapItem(CSlotItemButton* _slot)
{
	if (_slot->m_itemInfo == nullptr)
	{
		_slot->m_itemInfo = m_itemInfo;
		m_itemInfo = nullptr;
		_slot->m_spriteRenderer->SetImage(_slot->m_itemInfo->m_imgData);
		m_spriteRenderer->SetImage();
	}
	else if (m_itemInfo->m_item == _slot->m_itemInfo->m_item)
	{
		if (m_itemInfo->m_count + _slot->m_itemInfo->m_count < m_itemInfo->maxCount)
		{
			_slot->m_itemInfo->m_count += m_itemInfo->m_count;
			m_itemInfo = nullptr;
			_slot->m_spriteRenderer->SetImage(_slot->m_itemInfo->m_imgData);
		}
	}
	else 
	{
		auto itemInfo = m_itemInfo;
		m_itemInfo = _slot->m_itemInfo;
		_slot->m_itemInfo = itemInfo;

		_slot->m_spriteRenderer->SetImage(_slot->m_itemInfo->m_imgData);
		m_spriteRenderer->SetImage(m_itemInfo->m_imgData);
	}
}

void CSlotItemButton::RemoveItem()
{
	m_itemInfo = nullptr;
}

void CSlotItemButton::useSlotItem()
{
	if (m_itemInfo == nullptr) return;
	else
	{
		if (m_itemInfo->useItem())
		{
			m_itemInfo->m_count--;
		}
	}
}

void CSlotItemButton::dumpSlotItem()
{
	if (m_itemInfo == nullptr) return;
	else
	{
		m_itemInfo->DumpItem(m_itemInfo->m_count);
		RemoveItem();
	}
}

void CSlotItemButton::checkCount()
{
	if (m_itemInfo == nullptr) return;
	if (m_itemInfo->m_count == 0)
	{
		RemoveItem();
	}
}
