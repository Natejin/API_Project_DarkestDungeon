#pragma once
#include "GameObject.h"
#include "CDragButtion.h"

class CItemInfo;
class CButton_SlotItem : public CDragButton
{
public:
	CItemInfo* itemInfo;
	//ImageData slotItemImg;
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

	void setButton();

	void AddItem(CItemInfo* _iteminfo);
	void RemoveItem();
};