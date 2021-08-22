#pragma once
#include"Scene.h"

class mainScene :public Scene
{
public:
	class StartBG* m_startscene;
	class TitleButton* m_titleButton;
	mainScene();
	~mainScene();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void Render(HDC _hdc);

	void ChangeTown();
};