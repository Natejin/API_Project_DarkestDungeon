#include "framework.h"
#include "CUI_Panel_Hero.h"
#include"CEst_UI.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
#include"CHero.h"
#include"Info_Skill.h"

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
	m_HeroPanel->pos = Vector2(100, 600);
	
	m_HeroImg = new CSpriteRenderer(IMAGE::Crusader_sword, m_transform);
	m_HeroImg->useCustomPos = true;
	m_HeroImg->pos = Vector2(120, 300);
	m_HeroImg->useCustomScale = true;
	m_HeroImg->scale = Vector2(0.5, 0.5);

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
	m_HeroPanel->Render(_hdc);
	m_HeroImg->Render(_hdc);
    ShowHeroInfo(_hdc);
	ShowHeroSkill();
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
		m_HeroImg->SetImage(IMAGE::Crusader_sword);
		break;
	case JOB::Vestal:
		m_windowPanelChar->SetImage(IMAGE::vestal_header);
		m_HeroImg->SetImage(IMAGE::Vestal_mace);
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

    sprintf_s(str, "Acc :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetAcry());
    TextOut(_hdc, 380, 455, str, strlen(str));

    sprintf_s(str, "Crit :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetCri());
    TextOut(_hdc, 480, 455, str, strlen(str));

    sprintf_s(str, "Dmg :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDmg());
    TextOut(_hdc, 380, 470, str, strlen(str));

    sprintf_s(str, "Dodge :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDodge());
    TextOut(_hdc, 480, 470, str, strlen(str));

    sprintf_s(str, "Prot :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->GetDef());
    TextOut(_hdc, 380, 485, str, strlen(str));

    sprintf_s(str, "Spd :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getSPD());
    TextOut(_hdc, 480, 485, str, strlen(str));

	//stun, blight, bleed, debuff, move
	sprintf_s(str, "Stun :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getResist(0));
	TextOut(_hdc, 1000, 455, str, strlen(str));

	sprintf_s(str, "Blight :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getResist(1));
	TextOut(_hdc, 1100, 455, str, strlen(str));

	sprintf_s(str, "Bleed :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getResist(2));
	TextOut(_hdc, 1000, 470, str, strlen(str));

	sprintf_s(str, "Debuff :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getResist(3));
	TextOut(_hdc, 1100, 470, str, strlen(str));

	sprintf_s(str, "Move :  %d", MG_GAME->GetHero(townScene->curDragHeroIndex)->getResist(4));
	TextOut(_hdc, 1000, 485, str, strlen(str));

}

void CUI_Panel_Hero::ShowHeroSkill()
{
	MG_GAME->GetHero(townScene->curDragHeroIndex)->GetOwnSkill();
	
}
