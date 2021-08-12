#pragma once
#include <map>
#include "ItemInfo.h"
#include "singleton.h"
class CItemDB : public Singleton<CItemDB>
{
	map< ITEM, CItemInfo*> itemDB;
	int id;
public:
	CItemDB();
	~CItemDB();

public:
	void Init();

	CItemInfo* CallItem(ITEM item);

	void Save();
	void Load();
};

