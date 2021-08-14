#include "framework.h"
#include "TreasureEventPanel.h"
#include "CSpriteRenderer.h"
#include "CButton.h"
#include "TownScene.h"

TreasureEventPanel::TreasureEventPanel()
{
    m_layer = LAYER::UI;
    m_quick = nullptr;
}
TreasureEventPanel::~TreasureEventPanel() {}

HRESULT TreasureEventPanel::Init()
{
	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(400, 100);
	m_quick->AddSpriteRenderer("quick");
	m_quick->AddColliderBox();
	m_quick->isActive = false;

	m_quick->SetTriggerWhenDown(this, &TreasureEventPanel::Unable);
	MG_GMOBJ->RegisterObj("quick", m_quick);

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
