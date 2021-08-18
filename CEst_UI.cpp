#include "framework.h"
#include "CEst_UI.h"
#include "CSpriteRenderer.h"
#include "CButton.h"
#include "TownScene.h"
#include"CUIPanel_Abbey.h"

CEst_UI::CEst_UI()
{
    m_layer = LAYER::UI;
	m_quit = nullptr;
}

CEst_UI::~CEst_UI()
{
}

HRESULT CEst_UI::Init()
{
	isStart = true;
	m_windowPanelBG = new CSpriteRenderer(IMAGE::characterpanel_bg, m_transform);

	m_quit = new CButton();
	m_quit->m_transform->m_pos = Vector2(WINSIZEX - 470, 130);
	m_quit->AddSpriteRenderer("quick");
	m_quit->AddColliderBox();
	m_quit->isActive = false;

	m_quit->SetTriggerWhenDown(this, &CEst_UI::Disable);
	MG_GMOBJ->RegisterObj("quick", m_quit);

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
	m_windowPanelChar->Render(_hdc);
	m_windowPanelBG->Render(_hdc);
}

void CEst_UI::FrontRender(HDC _hdc)
{
}

void CEst_UI::Release()
{
	GameObject::Release();
	m_quit = nullptr;
	SAFE_DELETE(m_windowPanelBG);
	SAFE_DELETE(m_windowPanelChar);
}

void CEst_UI::FinishUI()
{
}

void CEst_UI::Enable()
{
	m_quit->isActive = true;
	isActive = true;
	townScene->DeactivateBuildings();
}

void CEst_UI::Disable()
{
	if (!isStart)
	{
		MG_SOUND->play(SOUND::Town_quick);
		
	}
	isStart = false;
	m_quit->isActive = false;
	isActive = false;
	if (townScene->isTown)
	{
		townScene->ActivateBuildings();
	}
}