#pragma once
#include "GameObject.h"

//dungeonInven, memberEquip
//Hero안에 ItemVector를 하나 더 만들 것 

//dungeonInven 기준으로만 만들어 보기
class CButton_SlotItem;
class CInventorySystem : public GameObject
{
public:
	vector<CButton_SlotItem*> m_invenSlots;


	int foodLimit = 13;
	int torchLimit = 9;

	int nowMouseOnSlot;

	//drag to change pos
	CButton_SlotItem* swap_slotB;
	CButton_SlotItem* swap_slotA;

	//fakeImageSlot?
	CButton_SlotItem* dummySlot;

	//CButton_SlotItem empty;
	//CButton_SlotItem torch;

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

	virtual  void Enable();
	virtual void Unable();
	//==================================

	void setInvenSlot(); //set dungeonInventory according to party info
	void setConsumableSlot(); 
	void changeSlot(); 
	void showSlotMouseOn(HDC _hdc);




};