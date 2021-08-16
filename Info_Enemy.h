#pragma once
#include "Info_Unit.h"
class Info_Enemy :public Info_Unit
{
public:
	ENEMYTYPE enemyType;


public:
	Info_Enemy();
	~Info_Enemy();

	virtual void Release();
};

