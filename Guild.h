#pragma once
#include "CEst_UI.h"
class Guild : public CEst_UI
{

private:
	class CButton* m_quick ;
	class CHeroList_button* m_HeroList_button;
public:
	Rect m_rect;

	Guild();
	~Guild();

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

