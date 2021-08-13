#include "framework.h"
#include "CUIPanel_Sanitarium.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
#include"CBuilding_PanelButton.h"
CUIPanel_Sanitarium::CUIPanel_Sanitarium()
{
}
CUIPanel_Sanitarium::~CUIPanel_Sanitarium()
{
}
HRESULT CUIPanel_Sanitarium::Init()
{
    CEst_UI::Init();
    
    m_windowPanelBG = new CSpriteRenderer(IMAGE::sanitarium_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::sanitarium_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();

	CreateRooms();
	Creatchecks();
	Unable();
    return S_OK;
}

void CUIPanel_Sanitarium::Update(float deltaTime, float worldTime)
{

}

void CUIPanel_Sanitarium::LateUpdate()
{
}

void CUIPanel_Sanitarium::BackRender(HDC _hdc)
{
}

void CUIPanel_Sanitarium::Render(HDC _hdc)
{
}

void CUIPanel_Sanitarium::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
	   m_quick->isActive = true;
}

void CUIPanel_Sanitarium::Release()
{
    
}

void CUIPanel_Sanitarium::CreateRooms() //panel버튼
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			CBuilding_PanelButton* m_room = new CBuilding_PanelButton();
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i * 135, WINSIZEY / 2 - 280 + j * 225);
			m_room->AddSpriteRenderer(IMAGE::hero_slot_bg);
			m_room->AddColliderBox();
			m_room->isActive = false;
			m_room->townScene = townScene;
			panelVec.push_back(m_room);
			MG_GMOBJ->RegisterObj("emptyroom", m_room);
		}
	}

}

void CUIPanel_Sanitarium::Creatchecks()
{
	m_check = new CButton();
	m_check->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180, WINSIZEY / 2 - 240 + 50);
	m_check->AddColliderBox(100, 25);
	m_check->AddSpriteRenderer(IMAGE::check);
	m_check->isActive = false;
	MG_GMOBJ->RegisterObj("smallx", m_check);

}

void CUIPanel_Sanitarium::Enable()
{
	CEst_UI::Enable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	isActive = true;
	m_check->isActive = true;	//얘도 활성화 조건 바꿔야 한다.
}

void CUIPanel_Sanitarium::Unable()
{
	CEst_UI::Unable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}
	isActive = false;
	m_check->isActive = false;
}
