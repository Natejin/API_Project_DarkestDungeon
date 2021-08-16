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
	m_transform->m_pivot = Vector2(0.5, 0.5);
	AddSpriteRenderer();
	return S_OK;
}

void DummySlot::Update(float deltaTime, float worldTime)
{
	m_transform->m_pos = g_ptMouse + MG_CAMERA->getCameraPos();
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
	m_spriteRenderer->RenderUI(_hdc);
}

void DummySlot::Release()
{
}

void DummySlot::SetDummySlot(Vector2Int slotID, CInfo_Item* item)
{
	itemInfo = item;
	originSlotID = slotID;
	m_spriteRenderer->SetImage(itemInfo->m_imgData);
	hasItem = true;
	isActive = true;
}

void DummySlot::Disable()
{
	itemInfo = nullptr;
	originSlotID = Vector2Int(-1, -1);
	hasItem = false;
	isActive = false;
}