#pragma once
#include "CEst_UI.h"
class Sanitarium :public CEst_UI
{
private:
	class CHeroList_button* m_HeroList_button;
public:
	Sanitarium();
	~Sanitarium();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	
};

