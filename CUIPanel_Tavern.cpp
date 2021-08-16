#include "framework.h"
#include "CUIPanel_Tavern.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include "TownScene.h"
#include"CBuilding_PanelButton.h"
CUIPanel_Tavern::CUIPanel_Tavern()
{
}

CUIPanel_Tavern::~CUIPanel_Tavern()
{
}

HRESULT CUIPanel_Tavern::Init()
{
    CEst_UI::Init();
    isActive = false;

    m_windowPanelBG = new CSpriteRenderer(IMAGE::tavern_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::tavern_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);

    m_HeroList_button = new CHeroList_button();

    CreateRooms();
    Creatchecks();
    Disable();
    return S_OK;
}

void CUIPanel_Tavern::Update(float deltaTime, float worldTime)
{
}

void CUIPanel_Tavern::LateUpdate()
{
}

void CUIPanel_Tavern::BackRender(HDC _hdc)
{
}

void CUIPanel_Tavern::Render(HDC _hdc)
{
}

void CUIPanel_Tavern::FrontRender(HDC _hdc)
{
       m_windowPanelBG->Render(_hdc);
       m_windowPanelChar->Render(_hdc);
       m_quit->isActive = true; 
}

void CUIPanel_Tavern::Release()
{
   
}

void CUIPanel_Tavern::CreateRooms() //panel버튼
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			CBuilding_PanelButton* m_room = new CBuilding_PanelButton();
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i * 135, WINSIZEY / 2 - 280 + j * 225);
			m_room->AddSpriteRenderer(IMAGE::hero_slot_bg);
			m_room->AddColliderBox();
			m_room->isActive = false;
			m_room->scene = townScene;
			panelVec.push_back(m_room);
			MG_GMOBJ->RegisterObj("emptyroom", m_room);
		}
	}
}

void CUIPanel_Tavern::Creatchecks()
{
	m_check = new CButton();
	m_check->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180, WINSIZEY / 2 - 240 + 50);

	m_check->AddSpriteRenderer(IMAGE::check);
	m_check->AddColliderBox();
	m_check->isActive = false;
	MG_GMOBJ->RegisterObj("smallx", m_check);

}

void CUIPanel_Tavern::Enable()
{
	CEst_UI::Enable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	isActive = true;
	m_check->isActive = true;	//얘도 활성화 조건 바꿔야 한다.
}

void CUIPanel_Tavern::Disable()
{
	CEst_UI::Disable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}
	isActive = false;
	m_check->isActive = false;
}
