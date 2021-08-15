#include "framework.h"
#include "TreasureEventPanel.h"
#include "CSpriteRenderer.h"
#include "CButton.h"
#include "TownScene.h"
#include "CInventorySystem.h"
#include "dungeonUI.h"

TreasureEventPanel::TreasureEventPanel()
{
    m_layer = LAYER::UI;
    m_quick = nullptr;
}
TreasureEventPanel::~TreasureEventPanel() {}

HRESULT TreasureEventPanel::Init(int torch, int food, int bandage)
{
	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(400, 100);
	m_quick->AddSpriteRenderer("quick");
	m_quick->AddColliderBox();
	m_quick->isActive = false;

	m_quick->SetTriggerWhenDown(this, &TreasureEventPanel::Unable);
	MG_GMOBJ->RegisterObj("quick", m_quick);

	setTreasureSlot();
	setTreasureItem(torch, food, bandage);

	//m_invenSys = &MG_GMOBJ->getObj("inventory");

	return S_OK;
}

HRESULT TreasureEventPanel::Init()
{
	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(400, 100);
	m_quick->AddSpriteRenderer("quick");
	m_quick->AddColliderBox();
	m_quick->isActive = false;

	m_quick->SetTriggerWhenDown(this, &TreasureEventPanel::Unable);
	MG_GMOBJ->RegisterObj("quick", m_quick);

	//m_invenSys = &MG_GMOBJ->getObj("inventory");

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
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
}

void TreasureEventPanel::FrontRender(HDC _hdc)
{
}

void TreasureEventPanel::Release()
{
	GameObject::Release();
	m_quick = nullptr;
	SAFE_DELETE(m_windowPanelBG);
	SAFE_DELETE(m_windowPanelChar);
}

void TreasureEventPanel::setTreasureItem(int torch, int food, int bandage)
{
	auto _torch = DB_ITEM->CallItem(ITEM::Torch);
	_torch->m_count = torch;
	m_treasureSlots[0]->AddItem(_torch);

	auto _food = DB_ITEM->CallItem(ITEM::Food);
	_food->m_count = food;
	m_treasureSlots[1]->AddItem(_food);

	auto _bandage = DB_ITEM->CallItem(ITEM::Bandage);
	_bandage->m_count = bandage;
	m_treasureSlots[2]->AddItem(_bandage);
}

void TreasureEventPanel::setTreasureSlot()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			CSlotItemButton* temp = new CSlotItemButton();
			m_treasureSlots.push_back(temp);
			temp->Init();
			temp->m_transform->m_pos = (i * 8 + j, Vector2(300 + 100 * i, 200));
			temp->slotID = Vector2Int(i, j);
			//temp->m_invenSys = 
				//getInven 필요할 것 같음
			MG_GMOBJ->RegisterObj("TreasureSlot", temp);
		}
	}
}

void TreasureEventPanel::FinishUI()
{
}

void TreasureEventPanel::Enable()
{
}

void TreasureEventPanel::Unable()
{
	m_quick->isActive = false;
	isActive = false;
}