#pragma once
#include "GameObject.h"

class FinishPanelUI : public GameObject
{
public:
	class CButton* buttonEnd;
	class CButton* buttonContinue;

	class DungeonScene* m_dungeonScene;

	FinishPanelUI();
	~FinishPanelUI();


	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);

	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void Enable();
	virtual void Disable();

	void GoBackToHome();
};

