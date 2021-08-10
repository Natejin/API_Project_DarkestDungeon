#pragma once

//dungeonInven, memberEquip
//Hero안에 ItemVector를 하나 더 만들 것 

//dungeonInven 기준으로만 만들어 보기
enum class ITEM
{
	ITEM_CONSUMABLE,
	ITEM_NONE,
	ITEM_TRINKET_SHOPPURCHASE,
	ITEM_TRINKET_DUNGEONDROP
};

struct itemInfo
{
	ITEM itemKind;
	ImageData m_imgData;
	string name;
	string description;
	int ability;
	int count;
	int price;
};

class CInventorySystem : public GameObject
{
public:
	vector<itemInfo> m_inven;
	vector<itemInfo> m_equip;

	CCollider _itemCollider;

	int foodLimit = 12;
	int torchLimit = 8;
	int itemIndex;

	itemInfo none;
	
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

	void setConsumableItem(); //set itemInfo
	void setInven(); //set dungeonInventory according to party info
	void setEquip(); //not sure it's nessaccery
	void setButton(); //set button to interact with inventory item

	void updateItem();

	void showInvenItem(HDC _hdc); //render inventory item and itemInfo

	void changePos(); //drag to change item pos(vector order change either)

	void interactWithItem();

	void useConsumableItem(int itemInfoIndex);

	void setEmptyItem();
};