#include "framework.h"
#include "sceneManager.h"
#include "gameNode.h"
#include "Astar.h"
#include "TestScene.h"
#include "DungeonScene.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

//현재씬을  널값으로  초기화하자
Scene* SceneManager::_currentScene = nullptr;

HRESULT SceneManager::init()
{
	//_astar = new Astar;
	//_astar->init();

	m_testScene = new TestScene;
	m_testScene->Init();

	DungeonScene* dungeon = new DungeonScene;
	dungeon->Init();
	addScene(SCENETYPE::Dungeon, dungeon);

	_currentScene = m_testScene;
	return S_OK;
}

void SceneManager::release()
{
	//isceneList iter = m_sceneList.begin();
	//for (iter; iter!= m_sceneList.end();)
	//{
	//	//삭제
	//	if (iter->second != NULL)
	//	{
	//		if (iter->second == _currentScene)iter->second->release();
	//		SAFE_DELETE(iter->second);
	//		iter = m_sceneList.erase(iter);
	//	}
	//	else
	//	{
	//		iter++;
	//	}
	//}
	//m_sceneList.clear();



	//m_testScene->Release();
	//delete m_testScene;
	//m_testScene = nullptr;
	//_currentScene = nullptr;
}

void SceneManager::update()
{
	if (_currentScene)
	{
		_currentScene->Update();
	}
}

void SceneManager::Render(HDC _hdc)
{
	if (_currentScene)_currentScene->Render(_hdc);
}

Scene* SceneManager::addScene(string sceneName, Scene* scene)
{
	if (!scene)return nullptr;

	m_sceneList.insert(make_pair(sceneName, scene));

	return nullptr;
}

HRESULT SceneManager::changeScene(string sceneName)
{
	isceneList find = m_sceneList.find(sceneName);

	//못찾으면E_FAIL
	if(find==m_sceneList.end())return E_FAIL;
	//바꾸려는 씬이현재씬이랑같아도  E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//여기까지 왔다면 문제가 없다 즉 씬을 초기화 하고  변경하자.
	if (SUCCEEDED(find->second->Init()))
	{
		//혹시 기존에 씬이 있다면 릴리즈
		if (_currentScene)_currentScene->Release();

		_currentScene = find->second;
		return  S_OK;
	}

	return E_FAIL;
}

Scene* SceneManager::addScene(SCENETYPE sceneName, Scene* scene)
{
	if (!scene)return nullptr;

	m_sceneMap.insert(make_pair(sceneName, scene));

	return nullptr;
}

HRESULT SceneManager::changeScene(SCENETYPE sceneName)
{
	SceneMapiter find = m_sceneMap.find(sceneName);

	//못찾으면E_FAIL
	if (find == m_sceneMap.end())return E_FAIL;
	//바꾸려는 씬이현재씬이랑같아도  E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//여기까지 왔다면 문제가 없다 즉 씬을 초기화 하고  변경하자.
	if (SUCCEEDED(find->second->Init()))
	{
		//혹시 기존에 씬이 있다면 릴리즈
		if (_currentScene)_currentScene->Release();

		_currentScene = find->second;
		return  S_OK;
	}

	return E_FAIL;
}
