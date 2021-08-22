#pragma once
#include "GameObject.h"
#include "CDragButtion.h"

class CInfo_Item;
class CSlotItemButton : public CDragButton
{
public:
	class CInventorySystem* m_invenSys;
	CInfo_Item* m_itemInfo;
	Vector2Int slotID; 
	CDragButton* bt_slot;

public:
	CSlotItemButton();
	~CSlotItemButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

	void AddItem(CInfo_Item* _iteminfo);
	void SwapItem(CSlotItemButton* _iteminfo);
	void RemoveItem();

	void useSlotItem();
	void dumpSlotItem();
	void checkCount();
};