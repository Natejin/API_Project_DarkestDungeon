#pragma once
#include"singleton.h"

class CObjectManager : public Singleton<CObjectManager>
{
private:
	//map<int,class GameObject*> objectMap;
	vector<class GameObject*> objectVec;
	map<LAYER, vector<class GameObject*>> objectUpdate;

	vector<class GameObject*> objsToRegister;
	vector<int> objsToErase;

	vector<LAYER> renderOrder;
	map<LAYER, vector<class GameObject*>> objectRender;

	int _instance_id;

public:
	CObjectManager();
	~CObjectManager();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void RegisterObj(string name, GameObject* gameObj);
	void RegisterObj( GameObject* gameObj);
	void RemoveObj(int id);
	void RemoveObj(GameObject* gameObj);

	template<typename T>
	T getObj(string name);
};

template<typename T>
inline T CObjectManager::getObj(string name)
{
	for (size_t i = 0; i < objectVec.size(); i++)
	{
		if (objectVec[i]->GetName == name)
		{
			int toFindID = objectVec[i]->GetId();
		}

		for (size_t j = 0; j < objectVec.size(); ++j)
		{
			if (objectVec[j]->GetId() == toFindID)
			{
				return *objectVec[j];
			}
		}
	}
}
