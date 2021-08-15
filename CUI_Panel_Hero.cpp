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
	
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform); //임의 이미지
	m_windowPanelChar->useCustomPos = true;
	m_windowPanelChar->pos = Vector2(100, 50);
	
	m_HeroPanel = new CSpriteRenderer(IMAGE::hero, m_transform);
	m_HeroPanel->useCustomPos = true;
	m_HeroPanel->pos = Vector2(150, 600);
	m_transform->m_pivot = Vector2(-0.095, -0.095);

	//m_HeroImg = new CSpriteRenderer(IMAGE::Crusader_sword, m_transform);
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
	m_HeroPanel->Render(_hdc);
	m_HeroImg->Render(_hdc);
    ShowHeroInfo(_hdc);
}

void CUI_Panel_Hero::Release()
{
}

void CUI_Panel_Hero::Enable()
{
	SetHeroPanel();
	CEst_UI::Enable();
}

void CUI_Panel_Hero::Unable()
{
	CEst_UI::Unable();
}

void CUI_Panel_Hero::SetHeroPanel()
{
	switch (MG_GAME->GetHero(townScene->curDragHeroIndex)->GetJob())
	{
	case JOB::Crusader:
		m_windowPanelChar->SetImage(IMAGE::crusader_header);

		//m_HeroImg->SetImage(IMAGE::Crusader_Idle);
		//m_HeroImg->SetImage(IMAGE::enemy);
		//m_HeroImg->SetImage(IMAGE::Crusader_sword);
		break;
	case JOB::Vestal:
		m_windowPanelChar->SetImage(IMAGE::vestal_header);
		//m_HeroImg->SetImage(IMAGE::Vestal_Idle);
		break;
	case JOB::Highwayman:
		m_windowPanelChar->SetImage(IMAGE::highwayman_header);
		break;
	case JOB::PlagueDoctor:
		m_windowPanelChar->SetImage(IMAGE::plague_doctor_header);
		break;

	default:
		break;
	}
}

void CUI_Panel_Hero::ShowHeroInfo(HDC _hdc)
{
    char str[256];
    string strFrame;
    SetBkMode(_hdc, TRANSPARENT);

    SetTextColor(_hdc, RGB(202, 201, 155));
    sprintf_s(str, "%s", "Name");
    TextOut(_hdc, 380, 400, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 0, 0));
    sprintf_s(str, "HP :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getHP());
    TextOut(_hdc, 380, 435, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 255, 255));

    sprintf_s(str, "ACC :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetAcry());
    TextOut(_hdc, 380, 485, str, strlen(str));

    sprintf_s(str, "CRIT :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetCri());
    TextOut(_hdc, 380, 505, str, strlen(str));

    sprintf_s(str, "DMG :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDmg());
    TextOut(_hdc, 380, 525, str, strlen(str));

    sprintf_s(str, "DODGE :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDodge());
    TextOut(_hdc, 380, 545, str, strlen(str));

    sprintf_s(str, "PROT :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDef());
    TextOut(_hdc, 380, 565, str, strlen(str));

    sprintf_s(str, "SPD :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getSPD());
    TextOut(_hdc, 380, 585, str, strlen(str));
}
