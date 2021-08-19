#pragma once
#include "Info_Enemy.h"
#include "Info_Hero.h"

class DB_UnitInfo : public Singleton<DB_UnitInfo>
{
private:
	map<JOB, Info_Hero*> heroDB;
	map<ENEMYTYPE, Info_Enemy*> enemyDB;
	int heroID;
	int enemyID;

	void SetHero();
	void SetEnemy();

public:
	DB_UnitInfo();
	~DB_UnitInfo();

	void Init();

	Info_Hero* CallHero(JOB item);
	Info_Enemy* CallEnemy(ENEMYTYPE item);

	void Save();
	void Load();
};