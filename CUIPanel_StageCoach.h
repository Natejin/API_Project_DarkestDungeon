#pragma once
#include "CEst_UI.h"
class CUIPanel_StageCoach : public CEst_UI
{
private:
	class CHeroList_button* m_HeroList_button;

public:
	vector<class CHeroList_button*> m_OnCoach_heroListButtonVec;
	vector<class CHero*> m_OnCoach_HeroVec;

	//class Hero_Roster* m_Roster_ButtonVec;
	//class CUI_Panel_Hero* m_hero_panel;

	void CreateOnCoach_Hero();
	void CreateCoach_Button();
	int ONHeroIndex;
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
	virtual void Enable();
	virtual void Unable();

	void ShowDummyHeroList();
	void ShowHeroPanel();
};

