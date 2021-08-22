#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	bool isFirst = true;
public:
	TestScene();
	virtual~TestScene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};