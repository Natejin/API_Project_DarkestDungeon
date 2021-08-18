#pragma once
#include"Scene.h"

class mainScene :public Scene
{
public:
	mainScene();
	~mainScene();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void Render(HDC _hdc);

};