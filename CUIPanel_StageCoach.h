#pragma once
#include "CEst_UI.h"
class CUIPanel_StageCoach : public CEst_UI
{
	
private:
	class CHeroList_button* m_HeroList_button;
public:
	CUIPanel_StageCoach();
	~CUIPanel_StageCoach();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};

