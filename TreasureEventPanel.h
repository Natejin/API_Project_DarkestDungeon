#pragma once
#include "GameObject.h"
#include "CSlotItemButton.h"

class CInventorySystem;
class TreasureEventPanel : public GameObject
{
private:
	vector<CSlotItemButton*> m_treasureSlots;
	class CButton* m_quick;

	class CSpriteRenderer* m_windowPanelBG;
	class CSpriteRenderer* m_windowPanelChar;

	int nowMouseOn;

	GameObject* m_invenSys;

public :
	TreasureEventPanel();
	~TreasureEventPanel();

	HRESULT Init(int torch, int food, int bandage);
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void setTreasureItem(int torch, int food, int bandage);

	void setTreasureSlot();

	void FinishUI();
	virtual void Enable();
	virtual void Unable();

};