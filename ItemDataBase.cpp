#include "framework.h"
#include "ItemDataBase.h"

CItemDB::CItemDB()
{
}

CItemDB::~CItemDB()
{
}

void CItemDB::Init()
{
	id = 0;

	CItemInfo* temp = new CItemInfo();
	temp->m_name = "torch";
	temp->m_description = "+20 brightness";
	temp->m_item = ITEM::Torch;
	temp->maxCount = 8;
	temp->isStockable = true;
	temp->m_price = 700;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::torch;
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Torch, temp));

	temp = new CItemInfo();
	temp->m_name = "food";
	temp->m_description = "+20 brightness";
	temp->m_item = ITEM::Food;
	temp->maxCount = 12;
	temp->isStockable = true;
	temp->m_price = 500;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::food1;
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Food, temp));

	temp = new CItemInfo();
	temp->m_name = "bandage";
	temp->m_description = "heals bleeding.";
	temp->m_item = ITEM::Bandage;
	temp->maxCount = 8;
	temp->isStockable = true;
	temp->m_price = 600;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::bandage;
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Bandage, temp));

}

CItemInfo* CItemDB::CallItem(ITEM item)
{
	CItemInfo* itemInfo = new CItemInfo();
	itemInfo->m_name = itemDB[item]->m_name;
	itemInfo->m_description = itemDB[item]->m_description;
	itemInfo->m_item = itemDB[item]->m_item;
	itemInfo->maxCount = itemDB[item]->maxCount;
	itemInfo->isStockable = itemDB[item]->isStockable;
	itemInfo->m_price = itemDB[item]->m_price;
	itemInfo->m_count = itemDB[item]->m_count;
	itemInfo->m_imgData = itemDB[item]->m_imgData;
	itemInfo->m_ID = itemDB[item]->m_ID;
	return itemInfo;
}

void CItemDB::Save()
{
}

void CItemDB::Load()
{
}
