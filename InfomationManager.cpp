#include "framework.h"
#include "InfomationManager.h"
#include "Info.h"
CInfomationManager::CInfomationManager()
{
	_instance_id = 0;
}

CInfomationManager::~CInfomationManager()
{
}

void CInfomationManager::RegisterInfo(Info* info)
{
	info->instanceId = _instance_id;
	objectVec.insert(make_pair(_instance_id++, info));
}

void CInfomationManager::Release()
{
	map<int, Info*>::iterator it;

	for (it = objectVec.begin(); it != objectVec.end(); it++)
	{
		SAFE_DELETE(it->second);
	}
	objectVec.clear();
}

void CInfomationManager::RemoveInfo(Info* info)
{
	int id = info->instanceId;
	auto a = objectVec[id];
	SAFE_DELETE(a);
	a = nullptr;
	objectVec.erase(id);
}