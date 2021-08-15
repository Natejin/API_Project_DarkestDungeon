#pragma once
#include "GameObject.h"
#include "CSlotItemButton.h"

class TreasureEventPanel : public GameObject
{
public:
	class DungeonScene* m_dungeonScene;
	class CSpriteRenderer* m_TreasurePanel;
	class CInventorySystem* m_invenSys;
	class CButton* m_quit;

	vector<CSlotItemButton*> m_treasureSlots;

	int nowMouseOn;
	bool isOpend;

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

	//==================================

	void setTreasureItem();
	void setTreasureSlot();
	void setPanelImg();

	virtual void Enable();
	virtual void Unable();

};