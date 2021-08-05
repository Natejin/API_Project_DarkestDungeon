#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	
public:
	TestScene();
	virtual~TestScene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};