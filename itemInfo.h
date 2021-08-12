#pragma once

enum class ITEMKIND
{
	ITEM_EMPTY, 
	ITEM_CONSUMABLE,
	ITEM_TREASURE,
	ITEM_NOINTERACTION,
	ITEM_MONEY,
	ITEM_TRINKET_DROP,
	ITEM_TRINKET_EQUIP
};

class itemInfo
{
public:
	ITEMKIND m_itemKind;
	ImageData m_imgData;
	string m_name;
	string m_description;
	int m_abillity;
	int m_ID;
	int m_price;
	int m_count;
	
public:
	
};