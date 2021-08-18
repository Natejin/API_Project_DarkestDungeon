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
			m_enemyInfoPanel->Render(_hdc);
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
	SetTextColor(_hdc, RGB(255, 0, 255));
	temp = m_battleSys->enemyParty[enemyIndex];

	sprintf_s(str, "Skeleton");
	TextOut(_hdc, 1400, 800, str, strlen(str));

	sprintf_s(str, "PROT : %d", temp-> );
	TextOut(_hdc, 1500, 1000, str, strlen(str));

	sprintf_s(str, "enemyIndex : %d", enemyIndex);
	TextOut(_hdc, 1400, 1200, str, strlen(str));

	sprintf_s(str, "enemyIndex : %d", enemyIndex);
	TextOut(_hdc, 1400, 1400, str, strlen(str));
}

void CEnemyInfoUI::Disable()
{
	isActive = false;
}

void CEnemyInfoUI::Enable()
{
	isActive = true;
}