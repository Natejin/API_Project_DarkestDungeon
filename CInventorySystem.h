#pragma once
#include "slot.h"

//dungeonInven, memberEquip
//Hero안에 ItemVector를 하나 더 만들 것 

//dungeonInven 기준으로만 만들어 보기
class CInventorySystem : public GameObject
{
public:
	vector<slot> m_inven;
	vector<slot> m_equip;

	int foodLimit = 12;
	int torchLimit = 9;

	int nowMouseOnSlot;

	//drag to change pos
	slot* swap_slotB;
	slot* swap_slotA;

	//fakeImageSlot?
	slot* dummySlot;

	slot empty;
	slot torch;

	int filledSlot;

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

	//==================================

	void setInvenSlot(); //set dungeonInventory according to party info
	void setEquipSlot(); //not sure it's nessaccery
	void setSlotCollider();
	void setConsumableSlot(); //set itemInfo

	void updateItem();

	void setNowMouseOnSlot();
	void setEmptySlot(int slotIndex, Vector2 slotItemImgPos);

	void interactWithItem();
	void useConsumableItem(int itemInfoIndex);

	void fillAnotherSpace();
	void changeSlot(); //drag to change item pos(vector order change either)

	void showInvenItem(HDC _hdc); //render inventory item and itemInfo
	void showSlotItemCount(HDC _hdc);
	void showSlotMouseOn(HDC _hdc);

	
	void setFilledSlot();

	bool isDividedCorrectly();


};