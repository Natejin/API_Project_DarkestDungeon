#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"
#include "CHero.h"
#include "CCollider.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;

	setInvenSlot();
	
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_collider = new CCollider(&m_inven[i].slotItemImg.m_trans);
	}
	nowMouseOnSlot = 0;

	setSlotCollider();
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	updateItem();
	setNowMouseOnSlot();
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
	showInvenItem(_hdc);
	showSlotItemCount(_hdc);
	showSlotMouseOn(_hdc);
}

void CInventorySystem::Release()
{
}


//==================================


void CInventorySystem::setConsumableSlot()
{
	slot temp;
	temp.slotItemImg.m_img = MG_IMAGE->findImage("torch");
	temp.slotItemImg.m_trans.m_pos = Vector2(982, 725);
	temp.slotItem.m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp.slotItem.m_name = "torch";
	temp.slotItem.m_description = "+20 brightness";
	temp.slotItem.m_count = MG_GAME->GetParty()->getTorch();
	m_inven.push_back(temp);

	temp.slotItemImg.m_img = MG_IMAGE->findImage("food1");
	temp.slotItemImg.m_trans.m_pos = Vector2(1052, 725);
	temp.slotItem.m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp.slotItem.m_name = "food";
	temp.slotItem.m_description = "+(1~3) HP";
	temp.slotItem.m_count = MG_GAME->GetParty()->getFood();
	m_inven.push_back(temp);

	temp.slotItemImg.m_img = MG_IMAGE->findImage("bandage");
	temp.slotItemImg.m_trans.m_pos = Vector2(1122, 725);
	temp.slotItem.m_itemKind = ITEMKIND::ITEM_CONSUMABLE;
	temp.slotItem.m_name = "bandage";
	temp.slotItem.m_description = "heals bleeding.";
	temp.slotItem.m_count = MG_GAME->GetParty()->getBandage();
	m_inven.push_back(temp);
}

void CInventorySystem::setInvenSlot()
{
	setConsumableSlot();

	//fill emptySlot expert already filled
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j <= m_inven.size()) continue;
			for (int i = m_inven.size(); i < 16; i++)
			{
				setEmptySlot(i * 1 + j, Vector2(982 + 70 * j, 725 + 120 * i));
			}
		}
	}
}

void CInventorySystem::setEquipSlot()
{

}

void CInventorySystem::updateItem()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_name == "torch")
		{
			if (m_inven[i].slotItem.m_count < torchLimit)
			{
				//find emptySlot
			}
			else
			{
				//fill torchSlot
			}
			m_inven[i].slotItem.m_count = MG_GAME->GetParty()->getTorch() % torchLimit;
		}
	}
	m_inven[1].slotItem.m_count = MG_GAME->GetParty()->getFood();
	m_inven[2].slotItem.m_count = MG_GAME->GetParty()->getBandage();

	//changeEmptySlot when count is 0
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind != ITEMKIND::ITEM_EMPTY && m_inven[i].slotItem.m_count == 0)
		{
			setEmptySlot(i, m_inven[i].slotItemImg.m_trans.m_pos);
		}
	}
	fillAnotherSpace();
}

void CInventorySystem::showInvenItem(HDC _hdc)
{
	//btween 72
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].slotItemImg.m_img->render(_hdc, &m_inven[i].slotItemImg.m_trans);
	}
}

void CInventorySystem::showSlotItemCount(HDC _hdc)
{
	int k = 0;
	char str[256];
	string strFrame;
	SetBkMode(_hdc, RGB(0, 0, 0));
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (k < m_inven.size())
			{
				sprintf_s(str, "%d", m_inven[k].slotItem.m_count);
				TextOut(_hdc, 990 + 70 * i, 730 + 140 * j, str, strlen(str));
			}
			k++;
		}
	}
}

void CInventorySystem::showSlotMouseOn(HDC _hdc)
{
	int k = 0;
	char str[256];
	string strFrame;
	SetBkMode(_hdc, RGB(0, 0, 0));
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].m_collider->CheckColliderBoxWithPoint(m_ptMouse))
		{
			sprintf_s(str, "nowMouseOnSlot : %d", nowMouseOnSlot);
			TextOut(_hdc, 300, 300, str, strlen(str));
		}
	}
}

void CInventorySystem::setNowMouseOnSlot()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind == ITEMKIND::ITEM_CONSUMABLE)
		{
			useConsumableItem(i);
		}
	}
}

void CInventorySystem::setSlotCollider()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_collider->SetRect(
			m_inven[i].slotItemImg.m_trans.m_pos.x,
			m_inven[i].slotItemImg.m_trans.m_pos.y,
			m_inven[i].slotItemImg.m_trans.m_pos.x + m_inven[i].slotItemImg.m_img->getWidth(),
			m_inven[i].slotItemImg.m_trans.m_pos.y + m_inven[i].slotItemImg.m_img->getHeight());
	}
}

void CInventorySystem::changeSlot()
{
}

void CInventorySystem::interactWithItem()
{
}

void CInventorySystem::useConsumableItem(int itemInfoIndex)
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].m_collider->CheckColliderBoxWithPoint(m_ptMouse))
		{
			nowMouseOnSlot = i;
			if (MG_INPUT->isOnceKeyClick(VK_RBUTTON))
			{
				m_inven[i].slotItem.m_count--;
			}
		}
	}
}

void CInventorySystem::setEmptySlot(int slotIndex, Vector2 slotItemImgPos)
{
	slot emptySlot;

	m_inven.push_back(emptySlot);
	m_inven.back().slotItemImg.m_img = MG_IMAGE->findImage("button");
	m_inven.back().slotItemImg.m_trans.m_pos = slotItemImgPos;
	m_inven.back().slotItem.m_itemKind = ITEMKIND::ITEM_EMPTY;
	m_inven.back().slotItem.m_name = "nothing";
	m_inven.back().slotItem.m_description = "it's emptySlot";
	m_inven.back().slotItem.m_count = 0;
}

void CInventorySystem::fillAnotherSpace()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_count > torchLimit && m_inven[i].slotItem.m_name == "torch")
		{
			for (int j = 0; j < m_inven.size(); j++)
			{
				if (m_inven[j].slotItem.m_itemKind == ITEMKIND::ITEM_CONSUMABLE && m_inven[j].slotItem.m_name == "torch")
				{
					
				}

				if (m_inven[j].slotItem.m_itemKind == ITEMKIND::ITEM_EMPTY)
				{
					CTransform temp = m_inven[j].slotItemImg.m_trans;
					m_inven[j] = m_inven[i];
					m_inven[j].slotItemImg.m_trans = temp;
					m_inven[j].slotItem.m_count = m_inven[i].slotItem.m_count % torchLimit;
					m_inven[i].slotItem.m_count = torchLimit;
					break;
					//find one of emptyPlace to fill, get out of For
				}
			}
		}
	}
}