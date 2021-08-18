#pragma once
#include "GameObject.h"

class CEst_UI :public GameObject
{
protected:

	class CButton* m_quit;

	class CSpriteRenderer* m_windowPanelBG;
	class CSpriteRenderer* m_windowPanel;

	class CSpriteRenderer* m_windowPanelChar;
	class CSpriteRenderer* m_HeroImg;

	class CSpriteRenderer* Quirk_Img;
	class CSpriteRenderer* OriginStatus_Img;
	class CSpriteRenderer* Equip_Img;
	class CSpriteRenderer* CombatSkill_Img;
	class CSpriteRenderer* CampingSkill_Img;
	class CSpriteRenderer* Resistance_Img;
	class CSpriteRenderer* Disease_Img;

	class CSpriteRenderer* m_stunicon;
	class CSpriteRenderer* m_bleedicon;
	class CSpriteRenderer* m_moveicon;
	class CSpriteRenderer* m_blighicon;
	class CSpriteRenderer* m_debufficon;

	class CSpriteRenderer* m_borderLine;

public:
	class TownScene* townScene;

	CEst_UI();
	~CEst_UI();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void FinishUI();
	virtual void Enable();
	virtual void Disable();
};