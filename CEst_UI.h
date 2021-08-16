#pragma once
#include "GameObject.h"

class CEst_UI :public GameObject
{
protected:

	class CButton* m_quit;

	class CSpriteRenderer* m_windowPanelBG;
	class CSpriteRenderer* m_windowPanelChar;
	class CSpriteRenderer* m_HeroPanel;
	class CSpriteRenderer* m_HeroImg;
	class CSpriteRenderer* m_treatmentImg;
	class CSpriteRenderer* m_diseaseImg;

	class CSpriteRenderer* m_stunicon;
	class CSpriteRenderer* m_bleedicon;
	class CSpriteRenderer* m_moveicon;
	class CSpriteRenderer* m_blighicon;
	class CSpriteRenderer* m_debufficon;

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