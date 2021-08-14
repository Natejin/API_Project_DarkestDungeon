#include "framework.h"
#include "CUI_Panel_Hero.h"
#include"CEst_UI.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
#include"CHero.h"
CUI_Panel_Hero::CUI_Panel_Hero()
{
}

CUI_Panel_Hero::~CUI_Panel_Hero()
{
}

HRESULT CUI_Panel_Hero::Init()
{
	CEst_UI::Init();
	m_windowPanelBG = new CSpriteRenderer(IMAGE::characterpanel_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	SetHeroPanel();
	m_transform->m_pivot = Vector2(-0.095, -0.095);
	Unable();
	return S_OK; 
}

void CUI_Panel_Hero::Update(float deltaTime, float worldTime)
{

}

void CUI_Panel_Hero::LateUpdate()
{
}

void CUI_Panel_Hero::BackRender(HDC _hdc)
{
}

void CUI_Panel_Hero::Render(HDC _hdc)
{
}

void CUI_Panel_Hero::FrontRender(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quick->isActive = true;
}

void CUI_Panel_Hero::Release()
{
}

void CUI_Panel_Hero::Enable()
{
	isActive = true;
}

void CUI_Panel_Hero::Unable()
{
	CEst_UI::Unable();
	isActive = false;
}

void CUI_Panel_Hero::SetHeroPanel()
{
	//m_spriteRenderer->SetImage(MG_GAME->GetHero(townScene->curDragHeroIndex)->m_spriteRenderer)

	switch (MG_GAME->GetHero(townScene->curDragHeroIndex)->job)
	{
	case JOB::Crusader:
		m_windowPanelChar->SetImage(IMAGE::crusader_roster);
	//	m_windowPanelChar = new CSpriteRenderer(IMAGE::crusader_roster, m_transform);
		break;
	case JOB::Vestal:
		//m_windowPanelChar = new CSpriteRenderer(IMAGE::vestal_roster, m_transform);
		m_spriteRenderer->SetImage(IMAGE::vestal_roster);
	default:
		break;
	}
}
