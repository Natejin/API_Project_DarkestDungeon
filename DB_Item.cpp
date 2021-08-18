#include "framework.h"
#include "DB_Item.h"
#include "CItemEffect.h"
#include "ItemEffect_Colletion.h"

CDB_Item::CDB_Item() {}
CDB_Item::~CDB_Item() {}

void CDB_Item::Init()
{
	id = 0;

	CInfo_Item* info = new CInfo_Item();
	info->m_name = "torch";
	info->m_description = "+20 brightness";
	info->m_item = ITEM::Torch;
	info->maxCount = 8;
	info->isStockable = true;
	info->isUsable = true;
	info->m_price = 700;
	info->m_count = 0;
	info->m_imgData = IMAGE::torch;
	info->m_itemEffect = new TorchEffect();
	info->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Torch, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Item();
	info->m_name = "food";
	info->m_description = "+1~3 Hp";
	info->m_item = ITEM::Food;
	info->maxCount = 12;
	info->isStockable = true;
	info->isUsable = true;
	info->m_price = 500;
	info->m_count = 0;
	info->m_imgData = IMAGE::food1;
	info->m_itemEffect = new FoodEffect();
	info->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Food, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Item();
	info->m_name = "bandage";
	info->m_description = "heals bleeding.";
	info->m_item = ITEM::Bandage;
	info->maxCount = 8;
	info->isStockable = true;
	info->isUsable = true;
	info->m_price = 600;
	info->m_count = 0;
	info->m_imgData = IMAGE::bandage;
	info->m_itemEffect = new BandageEffect();
	info->m_ID = id++;
	itemDB.insert(make_pair(ITEM::Bandage, info));
	MG_INFO->RegisterInfo(info);

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
	MG_INFO->RegisterInfo(itemInfo);
	return itemInfo;
}

void CDB_Item::Save()
{
}

void CDB_Item::Load()
{
}
