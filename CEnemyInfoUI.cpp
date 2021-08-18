#include "framework.h"
#include "CEnemyInfoUI.h"
#include "CSpriteRenderer.h"
#include "CBattleSystem.h"
#include "CEnemy.h"

CEnemyInfoUI::CEnemyInfoUI() {}
CEnemyInfoUI::~CEnemyInfoUI() {}

HRESULT CEnemyInfoUI::Init()
{
	m_layer = LAYER::UIButton;
	m_transform->m_pos = Vector2(1573, 1080 - 58);
	m_transform->m_pivot = Vector2(1, 1);

	setUIIMG();
	return S_OK;
}

void CEnemyInfoUI::Update(float deltaTime, float worldTime)
{
	isMouseOnEnemy();
}

void CEnemyInfoUI::LateUpdate()
{
}

void CEnemyInfoUI::BackRender(HDC _hdc)
{
}

void CEnemyInfoUI::Render(HDC _hdc)
{

	
}

void CEnemyInfoUI::FrontRender(HDC _hdc)
{
	for (int i = 0; i < m_battleSys->enemyParty.size(); i++)
	{
		if (m_battleSys->enemyParty[i]->m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			m_enemyInfoPanel->RenderUI(_hdc);
			drawResistancesImage(_hdc);
			showEnemyInfo(_hdc);
		}
	}
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));

	sprintf_s(str, "enemyIndex : %d", enemyIndex);
	TextOut(_hdc, 0, 200, str, strlen(str));
}

void CEnemyInfoUI::Release()
{
}

//==================================

void CEnemyInfoUI::setUIIMG()
{
	m_enemyInfoPanel = new CSpriteRenderer(IMAGE::monster, m_transform);

	m_stunicon = new CSpriteRenderer(IMAGE::stun, m_transform);
	m_stunicon->useCustomPos = true;
	m_stunicon->pos = Vector2(50, 0);

	m_blighicon = new CSpriteRenderer(IMAGE::poison, m_transform);
	m_blighicon->useCustomPos = true;
	m_blighicon->pos = Vector2(100, 0);

	m_bleedicon = new CSpriteRenderer(IMAGE::bleed, m_transform);
	m_bleedicon->useCustomPos = true;
	m_bleedicon->pos = Vector2(150, 0);

	m_debufficon = new CSpriteRenderer(IMAGE::debuff, m_transform);
	m_debufficon->useCustomPos = true;
	m_debufficon->pos = Vector2(200, 0);

	m_moveicon = new CSpriteRenderer(IMAGE::move, m_transform);
	m_moveicon->useCustomPos = true;
	m_moveicon->pos = Vector2(250, 0);
}

void CEnemyInfoUI::isMouseOnEnemy()
{
	for (int i = 0; i < m_battleSys->enemyParty.size(); i++)
	{
		if (m_battleSys->enemyParty[i]->m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			enemyIndex = i;
		}
	}
}

void CEnemyInfoUI::showEnemyInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(122, 25, 14));
	temp = m_battleSys->enemyParty[enemyIndex];

	sprintf_s(str, "Name");
	TextOut(_hdc, 1010, 755, str, strlen(str));

	SetTextColor(_hdc, RGB(255, 255, 255));
	sprintf_s(str, "Skeleton");
	TextOut(_hdc, 1010, 795, str, strlen(str));

	sprintf_s(str, "PROT : %d", temp-> GetProt());
	TextOut(_hdc, 1150, 795, str, strlen(str));

	sprintf_s(str, "DODGE : %d", temp->GetDodge());
	TextOut(_hdc, 1150, 815, str, strlen(str));

	sprintf_s(str, "SPD : %d", temp->getSPD());
	TextOut(_hdc, 1150, 835, str, strlen(str));

	//stun, blight, bleed, debuff, move

	SetTextColor(_hdc, RGB(212, 187, 120));
	sprintf_s(str, "Stun :  %d", temp->getResist(0));
	TextOut(_hdc, 1020, 900, str, strlen(str));

	SetTextColor(_hdc, RGB(162, 175, 70));
	sprintf_s(str, "Blight :  %d", temp->getResist(1));
	TextOut(_hdc, 1020, 920, str, strlen(str));

	SetTextColor(_hdc, RGB(126, 8, 4));
	sprintf_s(str, "Bleed :  %d", temp->getResist(2));
	TextOut(_hdc, 1020, 940, str, strlen(str));

	SetTextColor(_hdc, RGB(195, 122, 81));
	sprintf_s(str, "Debuff :  %d", temp->getResist(3));
	TextOut(_hdc, 1020, 960, str, strlen(str));

	SetTextColor(_hdc, RGB(118, 164, 198));
	sprintf_s(str, "Move :  %d", temp->getResist(4));
	TextOut(_hdc, 1020, 980, str, strlen(str));


	SetTextColor(_hdc, RGB(118, 21, 9));
	sprintf_s(str, "HP : %d / %d", temp->getHP(), temp->getMaxHP());
	TextOut(_hdc, 1440, 755, str, strlen(str));

	SetTextColor(_hdc, RGB(132, 121, 85));
	sprintf_s(str, "Resistances");
	TextOut(_hdc, 1080, 870, str, strlen(str));

	SetTextColor(_hdc, RGB(132, 121, 85));
	sprintf_s(str, "Skills");
	TextOut(_hdc, 1380, 870, str, strlen(str));
}

void CEnemyInfoUI::drawResistancesImage(HDC _hdc)
{
	m_stunicon->RenderUI(_hdc);
	m_bleedicon->RenderUI(_hdc);
	m_moveicon->RenderUI(_hdc);
	m_blighicon->RenderUI(_hdc);
	m_debufficon->RenderUI(_hdc);
}

void CEnemyInfoUI::Disable()
{
	isActive = false;
}

void CEnemyInfoUI::Enable()
{
	isActive = true;
}