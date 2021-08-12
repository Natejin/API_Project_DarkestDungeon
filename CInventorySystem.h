#pragma once
#include "GameObject.h"

//dungeonInven, memberEquip
//Hero안에 ItemVector를 하나 더 만들 것 

//dungeonInven 기준으로만 만들어 보기
class CSlotItemButton;
class CInventorySystem : public GameObject
{
public:
	vector<CSlotItemButton*> m_invenSlots;


	int foodLimit = 13;
	int torchLimit = 9;

	int nowMouseOnSlot;

	//drag to change pos
	CSlotItemButton* swap_slotB;
	CSlotItemButton* swap_slotA;

	//fakeImageSlot?
	class DummySlot* dummySlot;

	int filledSlot;

	CSlotItemButton* dragSlot;
	Vector2Int originPos;
	bool isDragging;

public:
	CInventorySystem();
	~CInventorySystem();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual  void Enable();
	virtual void Unable();
	//==================================

	void setInvenSlot(); //set dungeonInventory according to party info
	void setConsumableSlot(); 
	void changeSlot(); 
	void showSlotMouseOn(HDC _hdc);

	bool AddItem(ITEM itemInfo, int& count);
	void RemoveItem(Vector2Int pos);
	//void SwapItem(Vector2Int originPos, Vector2Int swapPos);

	void StartDragItem(class CSlotItemButton* slot);
	void EndDragItem(class CSlotItemButton* slot);


};