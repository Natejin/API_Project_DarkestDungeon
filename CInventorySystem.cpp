#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"
#include "CHero.h"
#include "CCollider.h"
#include "slot.h"
#include "CTransform.h"
#include "iteminfo.h"
#include "slot.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;

	setInvenSlot();

	nowMouseOnSlot = 0;
	filledSlot = 0;


	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	
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
			CButton_SlotItem* temp = new CButton_SlotItem();
			m_invenSlots.push_back(temp);
			temp->Init();
			temp->m_transform->m_pos = (i * 8 + j, Vector2(982 + 70 * j, 725 + 120 * i));
			temp->slotID = Vector2Int(j,i);
			MG_GMOBJ->RegisterObj("Slot", temp);
		}
	}

	setConsumableSlot();
}

void CInventorySystem::setConsumableSlot()
{
	CItemInfo* temp = new CItemInfo();
	temp->m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp->m_name = "torch";
	temp->m_description = "+20 brightness";
	temp->m_count = MG_GAME->GetParty()->getTorch();
	temp->m_imgData = IMAGE::torch;
	m_invenSlots[0]->AddItem(temp);

	CItemInfo* temp1 = new CItemInfo();
	temp1->m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp1->m_name = "food";
	temp1->m_description = "+ (1~3) HP";
	temp1->m_count = MG_GAME->GetParty()->getFood();
	temp1->m_imgData = IMAGE::food1;
	m_invenSlots[1]->AddItem(temp);

	CItemInfo* temp2 = new CItemInfo();
	temp2->m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp2->m_name = "bandage";
	temp2->m_description = "heals bleeding.";
	temp2->m_count = MG_GAME->GetParty()->getBandage();
	temp2->m_imgData = IMAGE::bandage;
	m_invenSlots[2]->AddItem(temp);
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
			if (m_invenSlots[i]->itemInfo !=nullptr)
			{
				sprintf_s(str, "SlotKind : %d", m_invenSlots[i]->itemInfo->m_itemKind);
				TextOut(_hdc, 0, 320, str, strlen(str));
			}

		}
	}
}