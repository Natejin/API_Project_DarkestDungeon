#include "framework.h"
#include "DummySlot.h"

DummySlot::DummySlot()
{
	hasItem = false;
	m_layer = LAYER::DummySlot;
}

DummySlot::~DummySlot()
{
}


HRESULT DummySlot::Init()
{
	m_transform->m_pivot = Vector2(0, 0);
	AddSpriteRenderer();
	return S_OK;
}

void DummySlot::Update(float deltaTime, float worldTime)
{

	m_transform->m_pos = m_ptMouse;
}

void DummySlot::LateUpdate()
{
}

void DummySlot::BackRender(HDC _hdc)
{
}

void DummySlot::Render(HDC _hdc)
{
}

void DummySlot::FrontRender(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);
}

void DummySlot::Release()
{
}

void DummySlot::SetDummySlot(Vector2Int slotID, CItemInfo* item)
{
	originSlotID = slotID;
	hasItem = true;
	itemInfo = item;
	m_spriteRenderer->SetImage(itemInfo->m_imgData);
	isActive = true;

}

void DummySlot::Unable()
{
	itemInfo = nullptr;
	originSlotID = Vector2Int(-1, -1);
	hasItem = false;
	isActive = false;
}

