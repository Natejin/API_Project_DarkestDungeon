#include "framework.h"
#include "CEst_UI.h"
#include "CSpriteRenderer.h"
#include "CButton.h"
#include "TownScene.h"
#include"CUIPanel_Abbey.h"

CEst_UI::CEst_UI()
{
    m_layer = LAYER::UI;
	m_quick = nullptr;
}

CEst_UI::~CEst_UI()
{
}

HRESULT CEst_UI::Init()
{	
	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
	m_quick->AddSpriteRenderer("quick");
	m_quick->AddColliderBox();
	m_quick->isActive = false;

	m_quick->SetTriggerWhenDown(this, &CEst_UI::Unable);
	MG_GMOBJ->RegisterObj("quick", m_quick);

    return S_OK;
}

void CEst_UI::Update(float deltaTime, float worldTime)
{
}

void CEst_UI::LateUpdate()
{
}

void CEst_UI::BackRender(HDC _hdc)
{
}

void CEst_UI::Render(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
}

void CEst_UI::FrontRender(HDC _hdc)
{
	//assert(m_image != nullptr);
	//m_image->renderUI(_hdc, m_transform);
}

void CEst_UI::Release()
{
	GameObject::Release();
	m_quick = nullptr;
	SAFE_DELETE(m_windowPanelBG);
	SAFE_DELETE(m_windowPanelChar);
}

void CEst_UI::FinishUI()
{
}

void CEst_UI::Enable()
{
}

void CEst_UI::Unable()
{
	m_quick->isActive = false;
	isActive = false;
	townScene->ActivateBuildings();
}