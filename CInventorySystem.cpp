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
	filledSlot = 0;

	setSlotCollider();

	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	updateItem();
	interactWithItem();
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


void CInventorySystem::setInvenSlot()
{
	setConsumableSlot();

	slot temp;

	//fill emptySlot expert already filled
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i * 8 + j < 16);
			{
				if (i * 8 + j < m_inven.size()) continue;
				m_inven.push_back(temp);
				setEmptySlot(i * 8 + j, Vector2(982 + 70 * j, 725 + 120 * i));
			}
		}
	}
}

void CInventorySystem::setEquipSlot()
{

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


void CInventorySystem::updateItem()
{
	setNowMouseOnSlot();
	setFilledSlot();

	fillAnotherSpace();
	
	/*
	int count_torch = 0;
	int count_food = 0;
	int count_bandage = 0;

	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_name == "torch")
		{
			count_torch += m_inven[i].slotItem.m_count;
		}
	}
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_name == "food")
		{
			count_food += m_inven[i].slotItem.m_count;
		}
	}
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_name == "bandage")
		{
			count_bandage += m_inven[i].slotItem.m_count;
		}
	}*/

	//remake to EmptySlot when count is 0
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind != ITEMKIND::ITEM_EMPTY && m_inven[i].slotItem.m_count == 0)
		{
			setEmptySlot(i, m_inven[i].slotItemImg.m_trans.m_pos);
		}
	}
}

void CInventorySystem::setNowMouseOnSlot()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].m_collider->CheckColliderBoxWithPoint(m_ptMouse))
		{
			nowMouseOnSlot = i;
		}
	}
}

void CInventorySystem::setEmptySlot(int slotIndex, Vector2 slotItemImgPos)
{
	m_inven[slotIndex].slotItemImg.m_img = MG_IMAGE->findImage("torch");
	m_inven[slotIndex].slotItemImg.m_trans.m_pos = slotItemImgPos;
	m_inven[slotIndex].slotItem.m_itemKind = ITEMKIND::ITEM_EMPTY;
	m_inven[slotIndex].slotItem.m_name = "nothing";
	m_inven[slotIndex].slotItem.m_description = "it's emptySlot";
	m_inven[slotIndex].slotItem.m_count = 0;
}

void CInventorySystem::interactWithItem()
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind != ITEMKIND::ITEM_EMPTY)
		{
			switch (m_inven[i].slotItem.m_itemKind)
			{
			case ITEMKIND::ITEM_CONSUMABLE:
				useConsumableItem(i);
				break;

			case ITEMKIND::ITEM_MONEY:

				break;

			case ITEMKIND::ITEM_NOINTERACTION:

				break;

			default:

				break;
			}
		}
	}
}

void CInventorySystem::useConsumableItem(int itemInfoIndex)
{
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].m_collider->CheckColliderBoxWithPoint(m_ptMouse))
		{
			if (MG_INPUT->isOnceKeyClick(VK_RBUTTON))
			{
				if (m_inven[i].slotItem.m_name == "torch")
				{
					MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() - 1);
				}
				
				if (m_inven[i].slotItem.m_name == "food") 
				{
					MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() - 1);
				}
				
				if (m_inven[i].slotItem.m_name == "bandage")
				{
					MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() - 1);
				}

				m_inven[i].slotItem.m_count--;
			}
		}
	}
}

void CInventorySystem::fillAnotherSpace()
{
	int quotient; //몫
	int remainder; //나머지

	int count; //아이템이 차지한 슬롯의 개수

	quotient = MG_GAME->GetParty()->getTorch() / torchLimit + 1;
	remainder = MG_GAME->GetParty()->getTorch() % torchLimit;
	count = 0;

	//when party's total torch more than 8
	if (MG_GAME->GetParty()->getTorch() >= torchLimit)
	{
		//check the slot divided appropriately
		for (int j = 0; j < m_inven.size(); j++)
		{
			if (m_inven[j].slotItem.m_name == "torch")
			{
				count += 1;
			}
		}
		if (count == quotient) return; //correct
	}

	//if incorrect:

	//didnt divided
	//find place to add remainder
	CTransform temp;
	for (int i = 0; i < m_inven.size(); i++)
	{
		//if there is torch slot and do not exceed the limit
		if (m_inven[i].slotItem.m_name == "torch")
		{
			if (m_inven[i].slotItem.m_count < torchLimit)
			{
				m_inven[i].slotItem.m_count = MG_GAME->GetParty()->getTorch() >= torchLimit;
				break;
			}
		}

		//there is no another torchSlot but emptyslot
		else
		{
			for (int j = 0; j < m_inven.size(); j++)
			{
				if (m_inven[j].slotItem.m_itemKind == ITEMKIND::ITEM_EMPTY)
				{
					temp = m_inven[j].slotItemImg.m_trans;
				}
				m_inven[j] = m_inven[i];
				m_inven[j].slotItemImg.m_trans = temp;
				m_inven[j].slotItem.m_count = remainder;
				m_inven[i].slotItem.m_count = torchLimit - 1;
				break;
			}
		}

		//no slot to fill
		break;
	}
}

void CInventorySystem::changeSlot()
{
}


void CInventorySystem::showInvenItem(HDC _hdc)
{
	//btween 72
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind != ITEMKIND::ITEM_EMPTY)
		{
			m_inven[i].slotItemImg.m_img->render(_hdc, &m_inven[i].slotItemImg.m_trans);
		}
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

	int quotient;
	quotient = MG_GAME->GetParty()->getTorch() / torchLimit + 1;
	sprintf_s(str, "quotient : %d", quotient);
	TextOut(_hdc, 0, 400, str, strlen(str));

	int remainder;
	remainder = MG_GAME->GetParty()->getTorch() % torchLimit;	
	sprintf_s(str, "remainder : %d", remainder);
	TextOut(_hdc, 0, 420, str, strlen(str));

	sprintf_s(str, "filledSlot : %d", filledSlot);
	TextOut(_hdc, 0, 440, str, strlen(str));

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
			sprintf_s(str, "nowMouseOnSlot : %d", i);
			TextOut(_hdc, 0, 300, str, strlen(str));
			sprintf_s(str, "SlotKind : %d", m_inven[i].slotItem.m_itemKind);
			TextOut(_hdc, 0, 320, str, strlen(str));
		}
	}
}

void CInventorySystem::setFilledSlot()
{
	filledSlot = 0; 
	for (int i = 0; i < m_inven.size(); i++)
	{
		if (m_inven[i].slotItem.m_itemKind != ITEMKIND::ITEM_EMPTY)
		{
			filledSlot += 1;
		}
	}
}

bool CInventorySystem::isDividedCorrectly()
{
	return false;
}
