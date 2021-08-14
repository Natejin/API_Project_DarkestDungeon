#include "framework.h"
#include "DB_Item.h"
#include "CItemEffect.h"
#include "DB_itemEffect.h"

CDB_Item::CDB_Item() {}
CDB_Item::~CDB_Item() {}

void CDB_Item::Init()
{
	id = 0;

	CInfo_Item* temp = new CInfo_Item();
	temp->m_name = "torch";
	temp->m_description = "+20 brightness";
	temp->m_item = ITEM::Torch;
	temp->maxCount = 8;
	temp->isStockable = true;
	temp->isUsable = true;
	temp->m_price = 700;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::torch;
	temp->m_itemEffect = new TorchEffect();
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Torch, temp));

	temp = new CInfo_Item();
	temp->m_name = "food";
	temp->m_description = "+20 brightness";
	temp->m_item = ITEM::Food;
	temp->maxCount = 12;
	temp->isStockable = true;
	temp->isUsable = true;
	temp->m_price = 500;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::food1;
	temp->m_itemEffect = new FoodEffect();
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Food, temp));

	temp = new CInfo_Item();
	temp->m_name = "bandage";
	temp->m_description = "heals bleeding.";
	temp->m_item = ITEM::Bandage;
	temp->maxCount = 8;
	temp->isStockable = true;
	temp->isUsable = true;
	temp->m_price = 600;
	temp->m_count = 0;
	temp->m_imgData = IMAGE::bandage;
	temp->m_itemEffect = new BandageEffect();
	temp->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Bandage, temp));

}

CInfo_Item* CDB_Item::CallItem(ITEM item)
{
	CInfo_Item* itemInfo = new CInfo_Item();
	itemInfo->m_name = itemDB[item]->m_name;
	itemInfo->m_description = itemDB[item]->m_description;
	itemInfo->m_item = itemDB[item]->m_item;
	itemInfo->maxCount = itemDB[item]->maxCount;
	itemInfo->isStockable = itemDB[item]->isStockable;
	itemInfo->isUsable = itemDB[item]->isUsable;
	itemInfo->m_price = itemDB[item]->m_price;
	itemInfo->m_count = itemDB[item]->m_count;
	itemInfo->m_imgData = itemDB[item]->m_imgData;
	itemInfo->m_ID = itemDB[item]->m_ID;
	itemInfo->m_itemEffect = itemDB[item]->m_itemEffect;
	
	return itemInfo;
}

void CDB_Item::Save()
{
}

void CDB_Item::Load()
{
}
