#pragma once


class Scene
{

public:
	Scene();
	virtual~Scene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);

	virtual void Release();

	virtual void Update();

	virtual void Render(HDC _hdc);
};

