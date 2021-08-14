#pragma once
#include "Info_Enemy.h"
#include "Info_Hero.h"

class DB_UnitInfo : public Singleton<DB_UnitInfo>
{
private:
	map<JOB, Info_Hero*> heroDB;
	map<JOB, Info_Enemy*> enemyDB;
	int heroID;
	int enemyID;

public:
	DB_UnitInfo();
	~DB_UnitInfo();

	void Init();

	CInfo_Item* CallItem(ITEM item);

	void Save();
	void Load();
};