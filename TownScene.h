#pragma once
#include "Scene.h"

class TownScene : public Scene
{
public:
public:
	TownScene();
	virtual~TownScene();



public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};