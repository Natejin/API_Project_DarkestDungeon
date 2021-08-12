#include "framework.h"
#include "CUIPanel_Abbey.h"
#include "CButton.h"
#include "CHeroList_button.h"
#include "TownScene.h"
#include"CBuilding_PanelButton.h"
CUIPanel_Abbey::CUIPanel_Abbey()
{

}

CUIPanel_Abbey::~CUIPanel_Abbey()
{
}

HRESULT CUIPanel_Abbey::Init()
{
	CEst_UI::Init();
	isActive = false;

	m_windowPanelBG = new CSpriteRenderer(IMAGE::abbey_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095,-0.095);
	CreateRooms();
	return S_OK;
}

void CUIPanel_Abbey::Update(float deltaTime, float worldTime)
{
	if (isActive == true)
	{
		m_empty1->isActive = true;
		m_empty2->isActive = true;
		m_empty3->isActive = true;
		m_empty4->isActive = true;
		m_empty5->isActive = true;
		m_empty6->isActive = true;
		m_empty7->isActive = true;
		m_empty8->isActive = true;
		m_empty9->isActive = true;
	}
	//if(m_collider->CheckColliderBoxWithPoint())
	

}

void CUIPanel_Abbey::LateUpdate()
{
}

void CUIPanel_Abbey::BackRender(HDC _hdc)
{
}

void CUIPanel_Abbey::Render(HDC _hdc)
{

}
void CUIPanel_Abbey::FrontRender(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quick->isActive = true;

	
}

void CUIPanel_Abbey::Release()
{
	
}

void CUIPanel_Abbey::CreateRooms()
{
	m_empty1 = new CBuilding_PanelButton();
	m_empty1->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180, WINSIZEY / 2 - 240);
	m_empty1->AddColliderBox(100, 100);
	m_empty1->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty1->isActive = false;
	m_empty1->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty1);

	m_empty2 = new CBuilding_PanelButton();
	m_empty2->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+135, WINSIZEY / 2 - 240);
	m_empty2->AddColliderBox(100, 100);
	m_empty2->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty2->isActive = false;
	m_empty2->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty2);

	m_empty3 = new CBuilding_PanelButton();
	m_empty3->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+270, WINSIZEY / 2 - 240);
	m_empty3->AddColliderBox(100, 100);
	m_empty3->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty3->isActive = false;
	m_empty3->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty3);

	m_empty4 = new CBuilding_PanelButton();
	m_empty4->m_transform->m_pos = Vector2(WINSIZEX / 2+180, WINSIZEY / 2-15);
	m_empty4->AddColliderBox(100, 100);
	m_empty4->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty4->isActive = false;
	m_empty4->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty4);

	m_empty5 = new CBuilding_PanelButton();
	m_empty5->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+135, WINSIZEY / 2 - 15);
	m_empty5->AddColliderBox(100, 100);
	m_empty5->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty5->isActive = false;
	m_empty5->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty5);

	m_empty6 = new CBuilding_PanelButton();
	m_empty6->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+270, WINSIZEY / 2 - 15);
	m_empty6->AddColliderBox(100, 100);
	m_empty6->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty6->isActive = false;
	m_empty6->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty6);

	m_empty7 = new CBuilding_PanelButton();
	m_empty7->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180, WINSIZEY / 2 +210);
	m_empty7->AddColliderBox(100, 100);
	m_empty7->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty7->isActive = false;
	m_empty7->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty7);

	m_empty8 = new CBuilding_PanelButton();
	m_empty8->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+135, WINSIZEY / 2 + 210);
	m_empty8->AddColliderBox(100, 100);
	m_empty8->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty8->isActive = false;
	m_empty8->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty8);

	m_empty9 = new CBuilding_PanelButton();
	m_empty9->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+270, WINSIZEY / 2 + 210);
	m_empty9->AddColliderBox(100, 100);
	m_empty9->AddSpriteRenderer(IMAGE::hero_slot_bg);
	m_empty9->isActive = false;
	m_empty9->townScene = townScene;
	MG_GMOBJ->RegisterObj("emptyroom", m_empty9);

}


