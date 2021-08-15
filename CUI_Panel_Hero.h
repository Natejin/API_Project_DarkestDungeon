#pragma once
#include"CEst_UI.h"
#include"CBTN_Skill.h"
class CUI_Panel_Hero : public CEst_UI
{
	
public:

	class CHeroList_button* hero_List;
	class CHero* hero;
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
	virtual void Unable();
	
	void SetHeroPanel();
	void ShowHeroInfo(HDC _hdc);
	void ShowHeroSkill();
	
};

