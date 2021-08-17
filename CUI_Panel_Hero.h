#pragma once
#include"CEst_UI.h"
#include"CBTN_Skill.h"

class CUI_Panel_Hero : public CEst_UI
{	
public:

	class CHeroList_button* hero_List;
	class CHero* hero;
	class CEquipButton* m_armor;
	class CEquipButton* m_weapon;

	bool isShowCoachHero; 

	vector<class CBTN_Skill*> m_skillbuttonVec;
	vector<class CBTN_CampSkill*> m_campSkillbuttonVec;
	vector<class CEquipButton*> m_armorbuttonVec;
	vector<class CEquipButton*> m_weaponbuttonVec;
	vector<class CPosition_Button*>m_postion_buttonVec;
	CUI_Panel_Hero();
	~CUI_Panel_Hero();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	virtual void Enable();
	virtual void Disable();
	
	void SetHeroPanel();
	void setCoachHeroPanel();

	void ShowHeroInfo(HDC _hdc);
	void ShowCoachHeroInfo(HDC _hdc);

	void CreateHeroSkill();
	void SetHeroSkill();
	void SetCoachHeroSkill();
	void CloseHeroSkill();

	void CreateHeroEquip();
	void SetHeroEquip();
	void SetCoachHeroEquip();
	void CloseHeroEquip();

	void CreateCampSkill();
	void SetCampSkill();
	void SetCoachCampSkill();
	void CloseCampSkill();

	void CreatPostionButton();

	void SetPhrases_Img();
	void DrawPhrases_Img(HDC _hdc);

	void SetResistanceInfo();
	void DrawResistanceInfo(HDC _hdc);
};