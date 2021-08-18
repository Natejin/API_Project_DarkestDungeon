#include "framework.h"
#include "CEnemyInfoUI.h"
#include "CSpriteRenderer.h"

CEnemyInfoUI::CEnemyInfoUI() {}
CEnemyInfoUI::~CEnemyInfoUI() {}

HRESULT CEnemyInfoUI::Init()
{
	m_layer = LAYER::UI;
	m_transform->m_pos = Vector2(1573, 1080 - 58);
	m_transform->m_pivot = Vector2(1, 1);

	setUIIMG();
	return S_OK;
}

void CEnemyInfoUI::Update(float deltaTime, float worldTime)
{
}

void CEnemyInfoUI::LateUpdate()
{
}

void CEnemyInfoUI::BackRender(HDC _hdc)
{
}

void CEnemyInfoUI::Render(HDC _hdc)
{
	m_enemyInfoPanel->Render(_hdc);
}

void CEnemyInfoUI::FrontRender(HDC _hdc)
{
}

void CEnemyInfoUI::Release()
{
}

//==================================

void CEnemyInfoUI::setUIIMG()
{
	m_enemyInfoPanel = new CSpriteRenderer(IMAGE::monster, m_transform);
}

int CEnemyInfoUI::isMouseOnEnemy()
{
	return 0;
}

void CEnemyInfoUI::showEnemyInfo()
{
}
