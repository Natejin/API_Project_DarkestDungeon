#pragma once
#include "singleton.h"
#include "Info_Item.h"

class CDB_Item : public Singleton<CDB_Item>
{
private:
	map< ITEM, CInfo_Item*> itemDB;
	int id;

public:
	CDB_Item();
	~CDB_Item();

	void Init();

	CInfo_Item* CallItem(ITEM item);

	void Save();
	void Load();
};