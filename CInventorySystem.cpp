#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"
#include "CHero.h"
#include "CCollider.h"
#include "CSlotItemButton.h"
#include "CTransform.h"
#include "Info_Item.h"
#include "DummySlot.h"


CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;

	setInvenSlot();

	nowMouseOnSlot = 0;
	filledSlot = 0;
	dummySlot = new DummySlot();
	dummySlot->Init();
	dummySlot->Unable();
	MG_GMOBJ->RegisterObj("dummySlot", dummySlot);
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown('Z'))
	{
		int count = 1;
		AddItem(ITEM::Torch, count);
		MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('X'))
	{
		int count = 1;
		AddItem(ITEM::Food, count);
		MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('C'))
	{
		int count = 1;
		AddItem(ITEM::Bandage, count);
		MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + 1);
	}

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
		{
			if (MG_INPUT->isOnceKeyDown(VK_RBUTTON))
			{
				int count = 1;
				useItem(m_invenSlots[i], count);
				//MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() - 1);
			}
		}
	}

	if (MG_INPUT->IsStayLMB())
	{
		if (dummySlot->isActive)
		{
			dummySlot->m_transform->m_pos = MG_INPUT->GetptMouse();
		}
	}

}

void CInventorySystem::LateUpdate()
{
}

void CInventorySystem::BackRender(HDC _hdc)
{
}

void CInventorySystem::Render(HDC _hdc)
{
}

void CInventorySystem::FrontRender(HDC _hdc)
{
	//showInvenItem(_hdc);
	//showSlotItemCount(_hdc);
	showSlotMouseOn(_hdc);
}

void CInventorySystem::Release()
{
}



void CInventorySystem::Enable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Enable();
	}
	GameObject::Enable();
}

void CInventorySystem::Unable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Unable();
	}
	GameObject::Unable();
}


//==================================


void CInventorySystem::setInvenSlot()
{
	//fill emptySlot expert already filled
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CSlotItemButton* temp = new CSlotItemButton();
			m_invenSlots.push_back(temp);
			temp->Init();
			temp->m_transform->m_pos = (i * 8 + j, Vector2(982 + 70 * j, 725 + 140 * i));
			temp->slotID = Vector2Int(j, i);
			temp->m_invenSys = this;
			MG_GMOBJ->RegisterObj("Slot", temp);
		}
	}
	setConsumableSlot();
}

void CInventorySystem::setConsumableSlot()
{
	auto torch = DB_ITEM->CallItem(ITEM::Torch);
	torch->m_count = 2;
	m_invenSlots[0]->AddItem(torch);

	auto food = DB_ITEM->CallItem(ITEM::Food);
	food->m_count = 2;
	m_invenSlots[1]->AddItem(food);

	auto bandage = DB_ITEM->CallItem(ITEM::Bandage);
	bandage->m_count = 2;
	m_invenSlots[2]->AddItem(bandage);
}

void CInventorySystem::changeSlot()
{
}

void CInventorySystem::showSlotMouseOn(HDC _hdc)
{
	int k = 0;
	char str[256];
	string strFrame;
	SetBkMode(_hdc, RGB(0, 0, 0));
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
		{
			sprintf_s(str, "nowMouseOnSlot : %d", i);
			TextOut(_hdc, 0, 300, str, strlen(str));
			if (m_invenSlots[i]->m_itemInfo !=nullptr)
			{
				sprintf_s(str, "SlotKind : %d", m_invenSlots[i]->m_itemInfo->m_item);
				TextOut(_hdc, 0, 320, str, strlen(str));
			}
		}
	}
}

bool CInventorySystem::AddItem(ITEM itemInfo, int& count)
{
	int curCount = count;

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_itemInfo == nullptr)
		{
			continue;
		}
		else 
		{
			if (m_invenSlots[i]->m_itemInfo->m_item == itemInfo
				&& m_invenSlots[i]->m_itemInfo->isStockable
				&& !m_invenSlots[i]->m_itemInfo->IsFull())
			{
				if (m_invenSlots[i]->m_itemInfo->maxCount > curCount + m_invenSlots[i]->m_itemInfo->m_count)
				{
					m_invenSlots[i]->m_itemInfo->m_count += curCount;
					return true;
				}
				else 
				{
					curCount -= m_invenSlots[i]->m_itemInfo->maxCount - m_invenSlots[i]->m_itemInfo->m_count;
					m_invenSlots[i]->m_itemInfo->m_count = m_invenSlots[i]->m_itemInfo->maxCount;
				}
			}
		}
	}

	if (curCount == 0)
	{
		return true;
	}

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_itemInfo == nullptr)
		{
			auto item = DB_ITEM->CallItem(itemInfo);
			item->m_count = curCount;
			m_invenSlots[i]->AddItem(item);
			return true;
		}
	}
	return false;
}

void CInventorySystem::RemoveItem(Vector2Int pos)
{
	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->slotID == pos)
		{
			m_invenSlots[i]->RemoveItem();
		}
	}
}

void CInventorySystem::StartDragItem(CSlotItemButton* slot)
{
	originPos = slot->slotID;
	dragSlot = slot;
	dummySlot->Enable();
	dummySlot->SetDummySlot(originPos, slot->m_itemInfo);
	isDragging = true;
}

void CInventorySystem::EndDragItem(CSlotItemButton* _slot)
{
	if (dragSlot != _slot)
	{
		dragSlot->SwapItem(_slot);
	}

	isDragging = false;
	dragSlot = nullptr;
	dummySlot->Unable();
}

bool CInventorySystem::useItem(CSlotItemButton* slot, int& count)
{
	int curCount = count;
	ITEM _item = slot->m_itemInfo->m_item;

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		//if there is no item
		if (m_invenSlots[i]->m_itemInfo == nullptr)
		{
			continue;
		}
		
		//there are items
		else
		{
			//usable condition and count 
			if (m_invenSlots[i]->m_itemInfo->isUsable
				&& m_invenSlots[i]->m_itemInfo->m_count > 0)
			{
				//slot item is enough to use
				if (m_invenSlots[i]->m_itemInfo->m_count - curCount > 0)
				{
					m_invenSlots[i]->m_itemInfo->m_count -= curCount;
					return true;
				} 
				//快急 老何父 昏力
				else
				{
					curCount -= m_invenSlots[i]->m_itemInfo->m_count;
					m_invenSlots[i]->RemoveItem(); //deleteSlotItem
				}
			}
		}
	}

	if (curCount == 0)
	{
		return true;
	}

	//have to delete more
	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_itemInfo->m_item == _item)
		{
			//there is slot that same itemKind
			if (m_invenSlots[i]->m_itemInfo->m_count - curCount > 0)
			{
				m_invenSlots[i]->m_itemInfo->m_count -= curCount;
			}
			else continue;
		}
	}
	return false;
}

void CInventorySystem::throwItem(CSlotItemButton* slot)
{
}
