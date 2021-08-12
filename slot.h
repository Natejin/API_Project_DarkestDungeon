#pragma once
#include "GameObject.h"
#include "CDragButtion.h"

class CItemInfo;
class CButton_SlotItem : public CDragButton
{
public:
	CItemInfo* m_itemInfo;
	//ImageData slotItemImg;
	class CInventorySystem* m_invenSys;

	Vector2Int slotID; 

	CDragButton* bt_slot;

public:
	CButton_SlotItem();
	~CButton_SlotItem();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

	void SetButton(CItemInfo* _iteminfo);

	void AddItem(CItemInfo* _iteminfo);
	void SwapItem(CButton_SlotItem* _iteminfo);
	void RemoveItem();
};