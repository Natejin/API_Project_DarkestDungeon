#pragma once
#include"singleton.h"
//#include "Scene.h"

class Scene;
class SceneManager : public Singleton<SceneManager>
{
private:
	typedef map<string, Scene*> sceneList;
	typedef map<string, Scene*>::iterator isceneList;

	typedef map<SCENETYPE, Scene*> sceneMap;
	typedef map<SCENETYPE, Scene*>::iterator SceneMapiter;

	static Scene* _currentScene;
	sceneList m_sceneList;

	sceneMap m_sceneMap;

	class Astar* m_astar;
	class TestScene* m_testScene;
	SCENETYPE curScene;
public:
	class DungeonScene* dungeonScene;
	class TownScene* townScene;
	class mainScene* _mainScene;
	SceneManager();
	~SceneManager();

	HRESULT init();
	void release();
	void update();
	
	void Render(HDC _hdc);

	//Scene* addScene(string sceneName, Scene* scene);
	//HRESULT changeScene(string sceneName);

	Scene* addScene(SCENETYPE sceneName, Scene* scene);
	HRESULT changeScene(SCENETYPE sceneName);
	void ResetScene();
	SCENETYPE CurScene();
};