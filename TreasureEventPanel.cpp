#include "framework.h"
#include "TreasureEventPanel.h"
#include "CSpriteRenderer.h"
#include "CButton.h"
#include "TownScene.h"
#include "CInventorySystem.h"
#include "dungeonUI.h"
#include "DungeonScene.h"
#include "CMapSystem.h"
TreasureEventPanel::TreasureEventPanel()
{
    m_layer = LAYER::UI;
    m_quit = nullptr;
}
TreasureEventPanel::~TreasureEventPanel() {}



HRESULT TreasureEventPanel::Init()
{
	setTreasureSlot();
	setPanelImg();
	m_quit = new CButton();
	m_quit->m_transform->m_pos = Vector2(500, 200);
	m_quit->AddSpriteRenderer("quick");
	m_quit->AddColliderBox();
	m_quit->Unable();
	m_quit->SetTriggerWhenDown(this, &TreasureEventPanel::Unable);
	MG_GMOBJ->RegisterObj("quick", m_quit);
    return S_OK;
}

void TreasureEventPanel::Update(float deltaTime, float worldTime)
{
}

void TreasureEventPanel::LateUpdate()
{
}

void TreasureEventPanel::BackRender(HDC _hdc)
{
}

void TreasureEventPanel::Render(HDC _hdc)
{
	m_TreasurePanel->RenderUI(_hdc);
}

void TreasureEventPanel::FrontRender(HDC _hdc)
{
}

void TreasureEventPanel::Release()
{
	GameObject::Release();
	m_quit = nullptr;
	SAFE_DELETE(m_TreasurePanel);
}

void TreasureEventPanel::setTreasureItem()
{
	auto _torch = DB_ITEM->CallItem(ITEM::Torch);
	_torch->m_count = MG_RND->getFromIntTo(1, 3);
	m_treasureSlots[0]->AddItem(_torch);

	auto _food = DB_ITEM->CallItem(ITEM::Food);
	_food->m_count = MG_RND->getFromIntTo(1, 3);
	m_treasureSlots[1]->AddItem(_food);

	auto _bandage = DB_ITEM->CallItem(ITEM::Bandage);
	_bandage->m_count = MG_RND->getFromIntTo(1, 3);
	m_treasureSlots[2]->AddItem(_bandage);
}

void TreasureEventPanel::setTreasureSlot()
{
	for (int i = 0; i < 3; i++)
	{
		CSlotItemButton* temp = new CSlotItemButton();
		m_treasureSlots.push_back(temp);
		temp->Init();
		temp->m_transform->m_pos = Vector2(1400 + 100 * i, 400);
		temp->slotID = Vector2Int(i, 0);
		temp->m_invenSys = m_dungeonScene->m_pInvenSystem;
		temp->Unable();
		MG_GMOBJ->RegisterObj("TreasureSlot", temp);
	}
}

void TreasureEventPanel::setPanelImg()
{
	m_transform->m_pos = Vector2(500, 500);
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_transform->m_scale = Vector2(1, 1);
	m_TreasurePanel = new CSpriteRenderer(IMAGE::eve_scroll_loot, m_transform);

	AddSpriteRenderer(IMAGE::eve_byHand);
	AddSpriteRenderer(IMAGE::eve_pass);
}


void TreasureEventPanel::Enable()
{
	if (!isOpend)
	{
		m_dungeonScene->m_pMapSystem->SetIsOpened();
		isOpend = true;
		if (MG_RND->getInt(10) > 0)
		{
			setTreasureItem();
		}
	}


	for (size_t i = 0; i < m_treasureSlots.size(); i++)
	{
		m_treasureSlots[i]->Enable();
	}
	m_dungeonScene->isOpenedPanel = true;
	m_quit->Enable();
	isActive = true;
	//enable(); dungoenScene ¿¡¼­
}

void TreasureEventPanel::Unable()
{
	m_dungeonScene->isOpenedPanel = false;
	isActive = false;
	m_quit->Unable();
	for (size_t i = 0; i < m_treasureSlots.size(); i++)
	{
		m_treasureSlots[i]->Unable();
	}

}