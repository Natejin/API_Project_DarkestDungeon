#pragma once
#include"singleton.h"

class CObjectManager : public Singleton<CObjectManager>
{
private:
	 //map<int,class GameObject*> objectMap;
	vector<class GameObject*> objectMap;
	vector<class GameObject*> objsToRegister;
	vector<int> objsToErase;

	int _instance_id;

public:
	CObjectManager();
	~CObjectManager();

	HRESULT init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void RegisterObj(string name, GameObject* gameObj);
	void RemoveObj(int id);
};