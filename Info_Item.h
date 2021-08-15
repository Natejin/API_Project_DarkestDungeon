#pragma once
#include "CItemEffect.h"
#include "Info.h"

class CInfo_Item : public Info
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
	bool isUsable;
	int maxCount;

	CItemEffect* m_itemEffect;


public:
	CInfo_Item() {};
	~CInfo_Item() {};

	bool IsFull();
	bool useItem();
	void DumpItem(int dumpCount);
	virtual void Release();
};