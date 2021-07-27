
#include "framework.h"
#include "CObjectManager.h"
#include "GameObject.h"

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}



HRESULT CObjectManager::init()
{

	return S_OK;
}

void CObjectManager::Update(float deltaTime, float worldTime)
{
	for (auto g : objectMap)
	{
		g->Update(deltaTime, worldTime);
	}
	
}

void CObjectManager::LateUpdate()
{

	for (auto g : objectMap)
	{
		g->LateUpdate();
	}


	for (size_t i = 0; i < objsToErase.size(); i++)
	{
		int eraseID = objsToErase[i];
		for (size_t j = 0; j < objectMap.size(); ++j)
		{
			if (objectMap[j]->GetId() == eraseID) {
				//colliderGroup에서 해당객체를 제거

				objectMap[j]->Release();
				delete 	objectMap[j];
				objectMap.erase(objectMap.begin() + j);
				break;
			}
		}
	}



	for (auto g : objsToRegister)
	{
		objectMap.push_back(g);
	}


}

void CObjectManager::BackRender(HDC _hdc)
{
	for (auto g : objectMap)
	{
		g->BackRender(_hdc);
	}
}

void CObjectManager::Render(HDC _hdc)
{
	for (auto g : objectMap)
	{
		g->Render(_hdc);
	}
}

void CObjectManager::FrontRender(HDC _hdc)
{
	for (auto g : objectMap)
	{
		g->FrontRender(_hdc);
	}
}

void CObjectManager::Release()
{
	for (auto g : objectMap)
	{
		g->Release();
	}

}

void CObjectManager::RegisterObj(string name, GameObject* gameObj)
{
	gameObj->SetId(_instance_id++);
	gameObj->SetName(name);
	objectMap.push_back(gameObj);
}

void CObjectManager::RemoveObj(int id)
{

}
