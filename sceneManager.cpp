#include "framework.h"
#include "sceneManager.h"
#include "gameNode.h"
#include "Astar.h"
#include "TestScene.h"
#include "DungeonScene.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

//�������  �ΰ�����  �ʱ�ȭ����
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

Scene* SceneManager::addScene(string sceneName, Scene* scene)
{
	if (!scene)return nullptr;

	m_sceneList.insert(make_pair(sceneName, scene));

	return nullptr;
}

HRESULT SceneManager::changeScene(string sceneName)
{
	isceneList find = m_sceneList.find(sceneName);

	//��ã����E_FAIL
	if(find==m_sceneList.end())return E_FAIL;
	//�ٲٷ��� ����������̶����Ƶ�  E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//������� �Դٸ� ������ ���� �� ���� �ʱ�ȭ �ϰ�  ��������.
	if (SUCCEEDED(find->second->Init()))
	{
		//Ȥ�� ������ ���� �ִٸ� ������
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

	//��ã����E_FAIL
	if (find == m_sceneMap.end())return E_FAIL;
	//�ٲٷ��� ����������̶����Ƶ�  E_FAIL
	if (find->second == _currentScene)return E_FAIL;

	//������� �Դٸ� ������ ���� �� ���� �ʱ�ȭ �ϰ�  ��������.
	if (SUCCEEDED(find->second->Init()))
	{
		//Ȥ�� ������ ���� �ִٸ� ������
		if (_currentScene)_currentScene->Release();

		_currentScene = find->second;
		return  S_OK;
	}

	return E_FAIL;
}
