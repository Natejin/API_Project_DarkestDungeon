#pragma once
#include"singleton.h"

class CInfomationManager : public Singleton<CInfomationManager>
{

	map<int, class Info*> objectVec;
	int _instance_id;


public:
	CInfomationManager();
	~CInfomationManager();

	void RegisterInfo(class Info* info);
	void RemoveInfo(Info* info);
	virtual void Release();


};

