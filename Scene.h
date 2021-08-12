#pragma once

class Scene
{
	Vector2 sceneWorldSize;

public:
	Scene();
	virtual~Scene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

	void SetSceneWorldSize(Vector2 size) { sceneWorldSize = size; };
	Vector2 GetSceneWorldSize() { return sceneWorldSize; };
};