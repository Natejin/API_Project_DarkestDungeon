#include "framework.h"
#include "DungeonRetreatPanel.h"
#include "CButton.h"

DungeonRetreatPanel::DungeonRetreatPanel()
{
	m_layer = LAYER::UI;
}
DungeonRetreatPanel::~DungeonRetreatPanel() {}

HRESULT DungeonRetreatPanel::Init()
{
	setPanelImage();
	setButton();
	return S_OK;
}

void DungeonRetreatPanel::Update(float deltaTime, float worldTime)
{
}

void DungeonRetreatPanel::LateUpdate()
{
}

void DungeonRetreatPanel::BackRender(HDC _hdc)
{
}

void DungeonRetreatPanel::Render(HDC _hdc)
{
	m_panel.m_img->renderUI(_hdc, &m_panel.m_trans);
}

void DungeonRetreatPanel::FrontRender(HDC _hdc)
{
}

void DungeonRetreatPanel::Release()
{
}

void DungeonRetreatPanel::Enable()
{
	m_cancle->isActive = true;
	m_retreat->isActive = true;
	isActive = true;
}

void DungeonRetreatPanel::Disable()
{
	m_cancle->isActive = false;
	m_retreat->isActive = false;
	isActive = false;
}

void DungeonRetreatPanel::setPanelImage()
{
	m_panel.m_img = MG_IMAGE->findImage("retreatPanel");
	m_panel.m_trans.m_pivot = Vector2(0.5, 0.5);
	m_panel.m_trans.m_pos = Vector2(WINSIZEX/2, 400);
}

void DungeonRetreatPanel::setButton()
{
	m_retreat = new CButton();
	m_retreat->m_transform->m_pos = Vector2(960, 460);
	m_retreat->AddSpriteRenderer("button");
	m_retreat->AddColliderBox(300, 35);
	m_retreat->Disable();
	m_retreat->SetTriggerWhenDown(this, &DungeonRetreatPanel::backToTown);
	MG_GMOBJ->RegisterObj("backToTown", m_retreat);

	m_cancle = new CButton();
	m_cancle->m_transform->m_pos = Vector2(960, 500);
	m_cancle->AddSpriteRenderer("button");
	m_cancle->AddColliderBox(300, 35);
	m_cancle->Disable();
	m_cancle->SetTriggerWhenDown(this, &DungeonRetreatPanel::closePanel);
	MG_GMOBJ->RegisterObj("closePanel", m_cancle);

}

void DungeonRetreatPanel::backToTown()
{
	MG_SCENE->changeScene(SCENETYPE::Test);
}

void DungeonRetreatPanel::closePanel()
{
	Disable();
}