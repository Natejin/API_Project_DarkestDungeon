#pragma once

class CItemInfo
{
public:
	ITEM m_item;
	IMAGE m_imgData;
	string m_name;
	string m_description;
	int m_abillity;
	int m_ID;
	int m_price;
	int m_count;
	
	bool isStockable;
	int maxCount;

public:
	CItemInfo() {};
	~CItemInfo() {};

	bool IsFull();
};