#pragma once
#include "CEst_UI.h"
class CampingTrainer : public CEst_UI
{

private:
	class CButton* m_quick;
	class CHeroList_button* m_HeroList_button;
public:
	Rect m_rect;

	CampingTrainer();
	~CampingTrainer();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	bool isUi;
	bool isUI;
	void Setquick();
	void FinishUI();
	
};

