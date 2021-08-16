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

	TimerCount = 0;
	isNothing = false;

	m_pass = new CButton();
	m_pass->m_transform->m_pos = Vector2(1320, 535);
	m_pass->AddSpriteRenderer(IMAGE::eve_pass);
	m_pass->AddColliderBox();
	m_pass->Disable();
	m_pass->SetTriggerWhenDown(this, &TreasureEventPanel::Disable);
	MG_GMOBJ->RegisterObj("TreasureEve_pass", m_pass);

	m_getAll = new CButton();
	m_getAll->m_transform->m_pos = Vector2(1470, 535);
	m_getAll->AddSpriteRenderer(IMAGE::eve_byHand);
	m_getAll->AddColliderBox();
	m_getAll->Disable();
	m_getAll->SetTriggerWhenDown(this, &TreasureEventPanel::getAll);
	MG_GMOBJ->RegisterObj("TreasureEve_getAll", m_getAll);

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
	if (!isNothing)
	{
		m_TreasurePanel->RenderUI(_hdc);
		AddSpriteRenderer(IMAGE::eve_byHand);
		AddSpriteRenderer(IMAGE::eve_pass);
	}
}

void TreasureEventPanel::FrontRender(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(197, 180, 110));

	if (!isNothing)
	{
		sprintf_s(str, "Treasure!");
		TextOut(_hdc, 1363, 260, str, strlen(str));
		sprintf_s(str, "yours for the taking...");
		TextOut(_hdc, 1328, 320, str, strlen(str));
	}
	else
	{
		if (TimerCount < 100)
		{
			SetBkMode(_hdc, RGB(255, 255, 255));
			sprintf_s(str, "empty box!");
			TextOut(_hdc, 1400, 300, str, strlen(str));
			TimerCount++;
		}
	}
}

void TreasureEventPanel::Release()
{
	GameObject::Release();
	m_pass = nullptr;
	m_getAll = nullptr;
	SAFE_DELETE(m_TreasurePanel);
}

void TreasureEventPanel::setTreasureItem()
{
	isNothing = false;
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
		temp->m_transform->m_pos = Vector2(1283 + 80 * i, 350);
		temp->slotID = Vector2Int(i, 0);
		temp->m_invenSys = m_dungeonScene->m_pInvenSystem;
		temp->Disable();
		MG_GMOBJ->RegisterObj("TreasureSlot", temp);
	}
}

void TreasureEventPanel::setPanelImg()
{
	m_transform->m_pos = Vector2(1400, 400);
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_transform->m_scale = Vector2(0.8, 0.8);
	m_TreasurePanel = new CSpriteRenderer(IMAGE::eve_scroll_loot, m_transform);
}

void TreasureEventPanel::getAll()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_treasureSlots[i]->m_itemInfo != nullptr)
		{
			m_dungeonScene->m_pInvenSystem->AddItem(m_treasureSlots[i]->m_itemInfo->m_item, m_treasureSlots[i]->m_itemInfo->m_count);
			m_treasureSlots[i]->RemoveItem();
		}
	}
}

void TreasureEventPanel::Enable()
{
	m_dungeonScene->m_pMapSystem->SetIsOpened();
	if (MG_RND->getInt(10) > 2)
	{
		setTreasureItem();
		for (size_t i = 0; i < m_treasureSlots.size(); i++)
		{
			m_treasureSlots[i]->Enable();
		}
		m_dungeonScene->isOpenedPanel = true;
		m_pass->Enable();
		m_getAll->Enable();
		isActive = true;
	}
	else
	{
		isNothing = true;
		isActive = true;
	}
}

void TreasureEventPanel::Disable()
{
	m_dungeonScene->isOpenedPanel = false;
	isActive = false;
	m_pass->Disable();
	m_getAll->Disable();
	for (size_t i = 0; i < m_treasureSlots.size(); i++)
	{
		m_treasureSlots[i]->Disable();
	}
}