#include "framework.h"
#include "sceneManager.h"
#include "gameNode.h"
#include "Astar.h"
#include "TestScene.h"
#include "DungeonScene.h"
#include "TownScene.h"
#include "mainScene.h"
SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

//�������  �ΰ�����  �ʱ�ȭ����
Scene* SceneManager::_currentScene = nullptr;

HRESULT SceneManager::init()
{
	

	TestScene* test = new TestScene;
	test->Init();
	addScene(SCENETYPE::Test, test);

	_mainScene = new mainScene;
	addScene(SCENETYPE::MainScene, _mainScene);
	changeScene(SCENETYPE::Test);
	return S_OK;
}

void SceneManager::release()
{
	//isceneList iter = m_sceneList.begin();
	//for (iter; iter!= m_sceneList.end();)
	//{
	//	//����
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

//Scene* SceneManager::addScene(string sceneName, Scene* scene)
//{
//	if (!scene)return nullptr;
//
//	m_sceneList.insert(make_pair(sceneName, scene));
//
//	return nullptr;
//}
//
//HRESULT SceneManager::changeScene(string sceneName)
//{
//	isceneList find = m_sceneList.find(sceneName);
//
//	//��ã����E_FAIL
//	if(find==m_sceneList.end())return E_FAIL;
//	//�ٲٷ��� ����������̶����Ƶ�  E_FAIL
//	if (find->second == _currentScene)return E_FAIL;
//
//	//������� �Դٸ� ������ ���� �� ���� �ʱ�ȭ �ϰ�  ��������.
//	if (SUCCEEDED(find->second->Init()))
//	{
//		//Ȥ�� ������ ���� �ִٸ� ������
//		if (_currentScene)_currentScene->Release();
//
//		_currentScene = find->second;
//		_currentScene->Init();
//		return  S_OK;
//	}
//
//	return E_FAIL;
//}

Scene* SceneManager::addScene(SCENETYPE sceneName, Scene* scene)
{
	if (!scene)return nullptr;

	m_sceneMap.insert(make_pair(sceneName, scene));

	return nullptr;
}

HRESULT SceneManager::changeScene(SCENETYPE sceneName)
{
	SceneMapiter find = m_sceneMap.find(sceneName);

	//��ã����E_FAIL
	if (find == m_sceneMap.end())return E_FAIL;
	//�ٲٷ��� ����������̶����Ƶ�  E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//������� �Դٸ� ������ ���� �� ���� �ʱ�ȭ �ϰ�  ��������.
	if (find->second != nullptr)
	{
		//Ȥ�� ������ ���� �ִٸ� ������
		if (_currentScene)_currentScene->Release();

		find->second->Init();

		_currentScene = find->second;
		curScene = sceneName;
		return  S_OK;
	}

	return E_FAIL;
}

void SceneManager::ResetScene()
{
	SAFE_DELETE(m_sceneMap[SCENETYPE::Dungeon]);
	m_sceneMap.erase(SCENETYPE::Dungeon);

	SAFE_DELETE(m_sceneMap[SCENETYPE::Town]);
	m_sceneMap.erase(SCENETYPE::Town);


	dungeonScene = new DungeonScene;
	addScene(SCENETYPE::Dungeon, dungeonScene);

	//DungeonScene2* dungeon2 = new DungeonScene2;

	townScene = new TownScene;
	addScene(SCENETYPE::Town, townScene);

	MG_GAME->m_dungeonScene = dungeonScene;
	MG_GAME->m_townScene = townScene;

}

SCENETYPE SceneManager::CurScene()
{
	return curScene;
}
