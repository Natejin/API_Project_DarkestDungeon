#pragma once
#include "GameObject.h"

class TreasureEventPanel : public GameObject
{
private:
	class CButton* m_quick;

	class CSpriteRenderer* m_windowPanelBG;
	class CSpriteRenderer* m_windowPanelChar;

public :
	TreasureEventPanel();
	~TreasureEventPanel();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void FinishUI();
	virtual void Enable();
	virtual void Unable();

};