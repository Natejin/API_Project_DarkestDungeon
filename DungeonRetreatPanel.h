#pragma once
#include "GameObject.h"

class DungeonRetreatPanel : public GameObject
{
public:
	class CButton* m_retreat;
	class CButton* m_cancle;

	ImageData m_panel;

public:
	DungeonRetreatPanel();
	~DungeonRetreatPanel();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void Enable();
	virtual void Disable();

	//==================================

	void setPanelImage();
	void setButton();

	void backToTown();
	void closePanel();

};