#pragma once
#include "CEst_UI.h"

class CUIPanel_Abbey :public CEst_UI
{
private:
	class CHeroList_button* m_HeroList_button;

	class CBuilding_PanelButton* m_empty1;
	class CBuilding_PanelButton* m_empty2;
	class CBuilding_PanelButton* m_empty3;
	class CBuilding_PanelButton* m_empty4;
	class CBuilding_PanelButton* m_empty5;
	class CBuilding_PanelButton* m_empty6;
	class CBuilding_PanelButton* m_empty7;
	class CBuilding_PanelButton* m_empty8;
	class CBuilding_PanelButton* m_empty9;

public:

	class CButton* m_smallx1;
	class CBuilding_PanelButton* panelbutton;

	CUIPanel_Abbey();
	~CUIPanel_Abbey();
	
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	void CreateRooms();
	void CreatsmallX();
	
};
