#pragma once
#include "CEst_UI.h"
class CUIPanel_Sanitarium :public CEst_UI
{
private:
	class CHeroList_button* m_HeroList_button;

	class CBuilding_PanelButton* m_room1;
	class CBuilding_PanelButton* m_room2;
	class CBuilding_PanelButton* m_room3;
	class CBuilding_PanelButton* m_room4;
	class CBuilding_PanelButton* m_room5;
	class CBuilding_PanelButton* m_room6;

	class CButton* m_roomcheck;

public:
	vector<class CBuilding_PanelButton*> panelVec;
	vector<class CButton*>checkVec;
	vector<class CButton*>closedVec;
	class CHero* hero;
	CUIPanel_Sanitarium();
	~CUIPanel_Sanitarium();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	void CreateRooms();
	void Creatchecks();

	virtual void Enable();
	virtual void Disable();

	void CheckStress(HDC _hdc);
	void ReduceStress();
	void closeRoom();
};

